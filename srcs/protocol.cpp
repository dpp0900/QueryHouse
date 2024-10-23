#include "protocol.h"

#include <cstring>
#include <fstream>  // for ofstream
#include <sstream>
#include <vector>

#include "client.h"

extern std::ofstream outfile;
extern std::ofstream errfile;
std::ofstream logfile("/tmp/report.Fuzzlog", std::ios::out | std::ios::app);
/***************************************
 * Target
 ***************************************/

TargetsMask to_flag(std::vector<Target> targets) {
  TargetsMask mask = 0;
  for (const auto &target : targets) {
    mask |= TARGET(static_cast<uint8_t>(target));
  }
  return mask;
}

std::vector<Target> to_targets(TargetsMask targets) {
  std::vector<Target> res;
  for (uint8_t i = 0; i <= TargetEnd; i++)
    if (targets & TARGET(i)) res.push_back(static_cast<Target>(i));
  return res;
}

/***************************************
 * Oracle Planner
 ***************************************/

OraclePlan *oracle_planner(const std::string src_query,
                           QueryQueue *query_queue) {
  // Step 1: Initialize a new OraclePlan
  OraclePlan *plan = new OraclePlan(src_query);

  // Step 2: Iterate over each target in the query queue and populate OraclePlan
  // without splitting
  for (const auto &entry : *query_queue) {
    Target target = entry.first;
    const std::string &transpiled_query = entry.second;

    // Add the full query (without splitting) to QueryInfo for this target
    QueryInfo qinfo;
    qinfo.queries.push_back(
        transpiled_query);  // No splitting, just add the entire query

    // Add the QueryInfo to the plan's query_infos for the target
    plan->query_infos[target] = qinfo;
  }

  // Step 3: Since there is no query splitting, add a single OracleType for
  // comparison In this case, we use ORACLE_ROW_NO_OPT as an example.
  plan->oracle_plan.push_back(ORACLE_ROWNUM);

  // Step 4: Validate the generated OraclePlan
  if (!plan->is_valid()) {
    std::cerr << "Error: Generated OraclePlan is invalid.\n";
    delete plan;
    return nullptr;
  }

  // Return the plan as a string for printing
  return plan;
}

// QueryInfo::total_size()
//      Length of queries in bytes, when concatenated, with each string
//      deliminated by NULL
size_t QueryInfo::total_size() {
  size_t s = 0;
  for (auto &q : queries) s += q.length();
  return s;
}

// QueryInfo::write_at()
//      Write concatenation of queires with each string deliminated by NULL at
//      `buf` Returns address of next null byte
char *QueryInfo::write_at(char *buf) {
  for (auto &q : queries) {
    strcpy(buf, q.c_str());
    // while (buf) buf++;
    while (*buf) buf++;
    buf++;
  }
  return buf;
}

// OraclePlan::is_valid()
//      Validate if OraclePlan has everything ready to be encoded into Round
bool OraclePlan::is_valid() {
  long unsigned int size = oracle_plan.size();

  if (size <= 0 || size > MAX_ORACLE)  // size check
    return false;

  if (query_infos.empty()) return false;  // query empty check

  for (auto &qinfo : query_infos)  // Is the number of oracle plans equal to the
                                   // number of query pieces?
    if (qinfo.second.queries.size() != size) return false;  // query nums check

  return true;
}

std::string target_to_string(Target target) {
  switch (target) {
    case Target::SQLite:
      return "SQLite";
    case Target::MySQL:
      return "MySQL";
    case Target::PostgreSQL:
      return "PostgreSQL";
    case Target::Oracle:
      return "Oracle";
    default:
      return "Unknown Target";
  }
}

// OraclePlan::to_string()
//      Returns a string for printing all contents of OraclePlan
std::string OraclePlan::to_string() {
  std::stringstream ss;

  // Print the source query
  ss << "----------------------------------------------------------------------"
        "----------------------------------------------------------------------"
        "--------";
  ss /*<< BLUE */ << "\nSource Query: " /*<< RESET*/ << src_query << "\n";

  // Print the oracle plan
  ss /*<< MAGENTA*/ << "Oracle Plan: \n" /*<< RESET*/;
  for (size_t i = 0; i < oracle_plan.size(); i++) {
    ss << "\tStep " << i + 1
       << ": Oracle Type = " << static_cast<int>(oracle_plan[i]) << "\n";
  }
  ss << "\n";

  // Print the query info for each target
  ss /*<< YELLOW */ << "Query Infos:\n" /*<< RESET*/;
  for (const auto &entry : query_infos) {
    Target target = entry.first;
    const QueryInfo &qinfo = entry.second;

    ss /*<< CYAN */ << "\tTarget: " /*<< RESET*/ << target_to_string(target)
                    << "\n";
    ss /*<< GREEN */ << "\tQueries:\n" /*<< RESET*/;
    for (const std::string &query : qinfo.queries) {
      ss << "\t\t" << query << "\n";
    }
    ss /*<< RED */ << "\tType-2 Scenario Mask: " /*<< RESET*/
                   << qinfo.type2_scenario << "\n\n";
  }
  return ss.str();
}

/***************************************
 * Round
 ***************************************/

/*****   Encoder   *****/
// void print_buf_queries(const char* buf, size_t length) {
//     for (size_t i = 0; i < length; i++) {
//         if (buf[i] == '\0') {
//             std::cout << "\\0";  // NULL 문자 대신 표시할 문자
//         } else {
//             std::cout << buf[i];
//         }
//     }
//     std::cout << std::endl;
// }
/*
 * encode():
 *
 * Encode the given OraclePlan into Round
 */
Round *encode(OraclePlan *plan) {
  if (!plan->is_valid()) return nullptr;
  // TODO: improve here?
  Round *r = (Round *)malloc(MAX_ROUND_SIZE);
  if (!r) return nullptr;

  // Initialize targets
  r->targets = 0;
  // Copy num_oracle and oracle_plans
  r->num_oracle = (uint8_t)plan->oracle_plan.size();
  for (int i = 0; i < MAX_ORACLE; i++)
    r->oracle_plans[i] = i < r->num_oracle ? plan->oracle_plan[i] : ORACLE_SKIP;
  // Copy original query
  char *cur = r->buf_queries;
  strcpy(cur, plan->src_query.c_str());
  cur += plan->src_query.length() + 1;  // src_query || NULL || each of db query
  // Iterate for each target
  for (uint8_t db = TargetStart; db <= TargetEnd; db++) {
    auto it = plan->query_infos.find((Target)db);
    if (it != plan->query_infos.end()) {
      // If the target is in the plan
      QueryInfo &qinfo = it->second;

      // Set the target
      set_target(r, (Target)db);

      // Copy type-2 diff test scenario
      r->type2_scenario[db] = qinfo.type2_scenario;

      // Copy its query and set the offset
      r->query_offset[db] = cur - r->buf_queries;
      cur = qinfo.write_at(cur);
    } else {
      // If the target does not exist in the plan
      // No scenario, No offset
      r->type2_scenario[db] = DIFF2_NONE;
      r->query_offset[db] = -1;
    }
  }
  // size_t round_size = (size_t) cur - r;
  return r;
}

/*****   Decoder   *****/

/*
 * get_querylist()
 *
 * Get the vector of query pieces of the given target `db` from the given Round
 * `r` If target is not set in that Round, returns empty vector.
 *
 * The query pieces are null-terminated `const char *` which can be directly
 * used to execute.
 */
OraclePlan *decode(Round *r) {
  outfile << YELLOW << "[Decode Round->OraclePlan]" << RESET << std::endl;
  // Ensure that the round object is valid
  if (r == NULL) {
    printf("\n[ERROR] Null pointer received for Round.\n");
    return NULL;
  }
  // Initialize OraclePlan with the original query from buf_queries
  std::string src_query = std::string(r->buf_queries);
  outfile << "src_query: " << src_query << std::endl;
  OraclePlan *plan = new OraclePlan(src_query);
  outfile << YELLOW << "[Create OraclePlan]" << RESET << std::endl;
  outfile << "num_oracle: " << r->num_oracle << std::endl;

  // Set the oracle_plan from Round
  for (int i = 0; i < r->num_oracle; i++) {
    plan->oracle_plan.push_back(r->oracle_plans[i]);
  }

  // Loop over all possible DBMS targets (SQLite, MySQL, PostgreSQL, Oracle)
  for (uint8_t db = TargetStart; db <= TargetEnd; db++) {
    // If this target was included in the round, decode it
    if (is_target_set(r, static_cast<Target>(db))) {
      QueryInfo qinfo;
      qinfo.type2_scenario = r->type2_scenario[db];

      // Copy queries
      for (char *q : get_querylist(r, static_cast<Target>(db))) {
        outfile << "Query: " << q << std::endl;
        qinfo.queries.push_back(std::string(q));
      }

      // Add the QueryInfo object for the DBMS to the plan
      plan->query_infos[static_cast<Target>(db)] = qinfo;
    }
  }

  // Return the decoded OraclePlan object
  outfile << CYAN << plan->to_string() << RESET << std::endl;
  return plan;
}

std::vector<char *> get_querylist(Round *r, Target db) {
  std::vector<char *> res = {};
  // If the target is set in the Round
  if (is_target_set(r, db)) {
    // Collect const char *'s for r->num_oracle number of times
    char *cur = query_start(r, db);
    for (int i = 0; i < r->num_oracle; i++) {
      res.push_back((char *)cur);
      do {
        cur++;
      } while (*cur);
      cur++;
    }
  }
  return res;
}

/***** Auxiliary *****/

/*
 * set_target()
 *
 * Mask the target set in the Round
 */
inline void set_target(Round *r, Target db) { r->targets |= TARGET(db); }

/*
 * is_target_set()
 *
 * Returns true if the given target is masked in the given round, false
 * otherwise
 */
inline bool is_target_set(Round *r, Target db) {
  return (r->targets & TARGET(db)) != 0;
}

/***************************************
 * Oracle Executor (Result Analyzer)
 ***************************************/
// Helper function to determine if a string can be interpreted as a float
bool isFloat(const std::string &myString) {
  std::istringstream iss(myString);
  float f;
  iss >> std::noskipws >> f;  // noskipws considers leading whitespace invalid
  return iss.eof() && !iss.fail();
}

// Helper function to trim quotation marks from strings
std::string trimQuotes(const std::string &str) {
  if ((str.front() == '"' && str.back() == '"') ||
      (str.front() == '\'' && str.back() == '\'')) {
    return str.substr(
        1, str.size() - 2);  // Remove the first and last character (quotes)
  }
  return str;
}

// Function to format a float string into a fixed-length string with leading
// zeros
std::string formatFloat(const std::string &floatStr) {
  size_t int_length = floatStr.find('.');
  size_t float_length = floatStr.length() - 1 - int_length;

  std::string res;
  for (size_t i = 0; i < PREPENDING_ZEROS - int_length; i++) res += "0";
  res += floatStr;
  for (size_t i = 0; i < TRAILING_ZEROS - float_length; i++) res += "0";

  return res;
}

// Function to normalize values before sorting by trimming quotes and formatting
// floats
std::vector<std::vector<std::string>> normalizeValues(
    const std::vector<std::vector<std::string>> &result) {
  auto normalized_result = result;
  for (auto &row : normalized_result) {
    for (auto &cell : row) {
      if (isFloat(cell)) {
        cell = formatFloat(cell);  // Format floats to a standard representation
      } else {
        cell = trimQuotes(cell);  // Remove quotes before comparison
      }
    }
  }
  return normalized_result;
}

/*
 * compare_row_num()
 *
 * Compares the number of rows between query results from multiple DBMS and
 * prints an explanation if they differ. Returns true if the row counts are the
 * same across all DBMS, false otherwise.
 */

bool compare_row_num(std::vector<Result> &results) {
  if (results.empty()) {
    outfile << "No results to compare." << std::endl;
    return true;
  }

  // Filter results with status == client::kNormal
  std::vector<Result> normal_results;
  for (const auto &result : results) {
    if (result.status == client::kNormal) {
      normal_results.push_back(result);
    } else {
      outfile << "Error: " << target_to_string(result.target)
              << " returned with status: " << result.status << std::endl;
    }
  }

  if (normal_results.empty()) {
    outfile << "No results with status kNormal to compare." << std::endl;
    return true;
  }

  // Get the row count of the first DBMS as the reference
  auto reference_target = normal_results.begin();
  size_t reference_row_count = reference_target->result.size();

  bool match = true;

  // Compare the row count of each DBMS with the reference
  for (const auto &result : normal_results) {
    if (result.result.size() != reference_row_count) {
      outfile << "Row count mismatch detected for target "
              << target_to_string(result.target) << ":\n";
      outfile << "  Target " << target_to_string(result.target) << " has "
              << result.result.size() << " rows.\n";
      match = false;
      results = normal_results;
    }
  }

  if (match) {
    outfile << "Row count is the same across all DBMS: " << reference_row_count
            << " rows." << std::endl;
  } else {
    outfile << "Mismatch found in row counts across different DBMS."
            << std::endl;
  }

  return match;
}

/*
 * compare_row()
 *
 * Compares the rows between query results from multiple DBMS after normalizing
 * and sorting the values. If they differ, prints an explanation and returns
 * false. Returns true if the rows are the same across all DBMS, false
 * otherwise.
 */
bool compare_row(std::vector<Result> &results) {
  if (results.empty()) {
    outfile << "No results to compare." << std::endl;
    return true;
  }

  // Filter results with status == client::kNormal
  std::vector<Result> normal_results;
  for (const auto &result : results) {
    if (result.status == client::kNormal) {
      normal_results.push_back(result);
    } else {
      outfile << "Error: " << target_to_string(result.target)
              << " returned with status: " << result.status << std::endl;
    }
  }

  if (normal_results.size() < 2) {
    outfile << "No results with status kNormal to compare." << std::endl;
    return true;
  }

  // Prepare to store normalized and sorted results for all DBMS
  std::map<Target, std::vector<std::vector<std::string>>> sorted_results;

  // Normalize and sort all DBMS results
  for (const auto &result : normal_results) {
    sorted_results[result.target] = normalizeValues(result.result);
    std::sort(sorted_results[result.target].begin(),
              sorted_results[result.target].end());
  }

  // Use the first DBMS's sorted result as the baseline for comparison
  auto reference_target = sorted_results.begin();
  const auto &sorted_reference = reference_target->second;

  bool match = true;

  // Compare all other DBMS results to the reference
  for (const auto &result : normal_results) {
    const auto &sorted_result = sorted_results[result.target];
    if (result.target == reference_target->first)
      continue;  // Skip comparison with the reference

    if (sorted_reference != sorted_result) {
      outfile << "Row mismatch detected for target "
              << target_to_string(result.target) << ":" << std::endl;

      // Print the mismatched row from each DBMS
      for (const auto &dbms_result : normal_results) {
        std::string target_name = target_to_string(dbms_result.target);
        outfile << "  " << target_name << ": [ ";
        for (const auto &row : dbms_result.result) {
          outfile << "[ ";
          for (const auto &col : row) {
            outfile << col << " ";
          }
          outfile << "] ";
        }
        outfile << "]" << std::endl;
      }

      match = false;
      results = normal_results;
    }
  }

  if (match) {
    outfile
        << "Rows are identical across all DBMS after normalization and sorting."
        << std::endl;
  } else {
    outfile << "Mismatch found in rows across different DBMS." << std::endl;
  }

  return match;
}

// Function to skip comparison
bool compare_skip(size_t step) {
  std::cout << "Skipping comparison for step " << step + 1 << " (ORACLE_SKIP)"
            << std::endl;
  return true;  // Skip means no error
}

// Function to compare schema (currently not supported)
bool compare_schema(size_t step) {
  std::cerr << "Schema comparison is not supported yet for step " << step + 1
            << std::endl;
  return false;  // Not supported, so return false
}

/*
 * execute_plan()
 *
 * Executes queries for each DBMS according to the plan and compares the results
 * row by row. Returns true if no error occurs, false otherwise.
 */
bool execute_plan(
    OraclePlan &plan,
    const std::vector<std::unique_ptr<client::DBClient>> &db_clients,
    std::vector<Result> &results) {
  outfile << YELLOW << "[Executing OraclePlan]" << RESET << std::endl;
  outfile << YELLOW << "[Plan Size: " << plan.oracle_plan.size() << "]" << RESET
          << std::endl;
  // Iterate through each step in the oracle plan
  for (size_t i = 0; i < plan.oracle_plan.size(); ++i) {
    OracleType oracle_type = plan.oracle_plan[i];
    oracle_type = ORACLE_ROW;  // for testing
    outfile << YELLOW << "[Oracle Type: " << static_cast<int>(oracle_type)
            << "]" << RESET << std::endl;

    // Log the start of the round execution
    std::cout << YELLOW << "[Executing Round " << i + 1
              << ": Processing OraclePlan]" << RESET << std::endl;

    // Store results for each DBMS dynamically
    std::vector<std::vector<std::string>> results_buffer;

    // Log the execution of each query for the DBMS
    std::cout << YELLOW << "[Fetching results for each DBMS]" << RESET
              << std::endl;

    // Execute and fetch results for each available DBMS target
    outfile << YELLOW << "[plan.query_infos.size(): " << plan.query_infos.size()
            << "]" << RESET << std::endl;
    for (const auto &entry : plan.query_infos) {
      Target target = entry.first;
      const char *query = entry.second.queries[i].c_str();
      size_t query_len = entry.second.queries[i].size();
      outfile << YELLOW << "[Executing query on " << target_to_string(target)
              << "]" << RESET << std::endl;
      outfile << "TargetNum: " << static_cast<int>(target) << std::endl;
      outfile << "Query: " << query << std::endl;
      client::ExecutionStatus status_buffer =
          db_clients[static_cast<int>(target)]->execute(query, query_len,
                                                        results_buffer);
      outfile << YELLOW << "[Execution Status: " << status_buffer << "]"
              << RESET << std::endl;
      results.push_back({target, results_buffer, status_buffer});
      // print result
      outfile << RED << "[Result]" << std::endl;
      outfile << "Target: " << target_to_string(target) << std::endl;
      outfile << "Status: " << results.back().status << std::endl;
      for (const auto &row : results.back().result) {
        for (const auto &col : row) {
          outfile << col << " ";
        }
        outfile << std::endl;
      }
      results_buffer.clear();
    }

    // If oracle_type is ORACLE_SKIP, skip the comparison but execute the query
    if (oracle_type == ORACLE_SKIP) {
      outfile << YELLOW << "[Skipping comparison for this round]" << RESET
              << std::endl;
      compare_skip(i);  // Log skipping, but still execute the query
      continue;
    }

    // Process according to oracle type
    if (oracle_type == ORACLE_ROWNUM) {
      // Log row count comparison
      outfile << YELLOW << "[Comparing row counts]" << RESET << std::endl;

      // Compare row counts only
      if (!compare_row_num(results)) {
        outfile << "Row count mismatch at step " << i + 1 << std::endl;
        // report to only two target
        report(plan, i, results);
        // report(plan, TARGET(Target::SQLite) | TARGET(Target::PostgreSQL), i,
        //        results);
        return false;  // Mark failure
      }

    } else if (oracle_type == ORACLE_ROW) {
      // Log row content comparison
      outfile << YELLOW << "[Comparing row contents]" << RESET << std::endl;

      if (!compare_row(results)) {
        outfile << "Row content mismatch at step " << i + 1 << std::endl;
        report(plan, i, results);
        return false;  // Mark failure
      }

      // } else if (oracle_type == ORACLE_SCHEMA) {
      //   // Log schema comparison
      //   outfile << YELLOW << "[Comparing schema]" << RESET << std::endl;

      //   // Schema comparison (not implemented yet)
      //   if (!compare_schema(i)) {
      //     std::cerr << "Schema mismatch at step " << i + 1 << std::endl;
      //     report(plan, TARGET_ALL, i);
      //     return false;  // Mark failure
      //   }

    } else {
      std::cerr << "Unknown OracleType at step " << i + 1 << std::endl;
      report(plan, i, results);
      return false;  // Mark failure
    }

    // Log the completion of the round
    outfile << YELLOW << "[Completed Round " << i + 1 << "]" << RESET
            << std::endl;
  }

  return true;
}
/* memo:
 *
 * void foo(const vector<unique_ptr<client::DBClient>>& db_clients) {
 *     for (const auto& client_ptr : db_clients) {
 *         if (client_ptr) { // Check if the unique_ptr is not null
 *             client_ptr->someMethod(); // Call a method on the DBClient
 *         }
 *     }
 * }
 */

/*
 * report()
 *
 * Reports a bug on wrong results.
 *  - Log on file
 *  - Prints OraclePlan, which DBMS is buggy on which piece of queries
 */
// 모든 쿼리와 position 위치의 쿼리 및 oracle_plan을 출력하는 함수
void log_queries_for_target(std::ofstream &logfile, const OraclePlan &plan,
                            Target target, const std::string &target_name,
                            uint8_t position, std::vector<Result> &results) {
  // 모든 쿼리 출력
  outfile << "[tmp] log_queries_for_target : " << target_name << std::endl;
  // check loggile open
  if (!logfile.is_open()) {
    outfile << RED << "Error: Could not open the log file." << RESET
            << std::endl;
    return;
  }
  logfile << " " << target_name << ": ";
  for (const auto &query : plan.query_infos.at(target).queries) {
    logfile << query << " ";
  }

  // position 위치 쿼리 piece 출력
  logfile << "\nposition query piece: ";
  if (position < plan.query_infos.at(target)
                     .queries.size()) {  // query 개수보다 position이 큰지 검사
    logfile << plan.query_infos.at(target).queries[position] << "\n";
  } else {
    logfile << "No query at position " << static_cast<int>(position) << "\n";
  }

  logfile << "Result for this piece: \n";
  for (const auto &result : results) {
    if (result.target == target) {
      for (const auto &row : result.result) {
        for (const auto &col : row) {
          logfile << col << " ";
        }
        logfile << "\n";
      }
    }
  }
  // position에 해당하는 oracle_plan 출력
  if (position <
      plan.oracle_plan.size()) {  // oracle_plan 개수보다 position이 큰지 검사
    logfile << "oracle_plan for this piece: "
            << static_cast<int>(plan.oracle_plan[position]) << "\n";
  } else {
    logfile << "No oracle_plan at this position.\n";
  }

  logfile << "\n";
}

void report(OraclePlan &plan, uint8_t position, std::vector<Result> &results) {
  outfile << YELLOW << "[Reporting Bug]" << RESET << std::endl;
  // 로그 파일 열기

  if (!logfile.is_open()) {
    outfile << RED << "Error: Could not open the log file." << RESET
            << std::endl;
    return;
  }

  logfile << std::unitbuf;
  logfile << "Bug Report:\n";
  TargetsMask buggy_targets;
  for (const auto &result : results) {
    buggy_targets |= TARGET(static_cast<uint8_t>(result.target));
  }
  // MySQL 체크
  if (TARGET(Target::MySQL) & buggy_targets) {
    log_queries_for_target(logfile, plan, Target::MySQL, "MySQL", position,
                           results);
  }

  // PostgreSQL 체크
  if (TARGET(Target::PostgreSQL) & buggy_targets) {
    log_queries_for_target(logfile, plan, Target::PostgreSQL, "PostgreSQL",
                           position, results);
  }

  // SQLite 체크
  if (TARGET(Target::SQLite) & buggy_targets) {
    log_queries_for_target(logfile, plan, Target::SQLite, "SQLite", position,
                           results);
  }

  // Oracle 체크
  if (TARGET(Target::Oracle) & buggy_targets) {
    log_queries_for_target(logfile, plan, Target::Oracle, "Oracle", position,
                           results);
  }

  logfile << "    Position in query: " << static_cast<int>(position) << "\n\n";
}

/*
 * postprocess()
 *
 * Post-processing on the given `plan` after oracle_planner(), including:
 *   - Add type-2 diff test scneario
 *
 * It can refer to the plan of the original seed `old_plan` as hints.
 */

void addPragmaCommands(QueryInfo& query_info, std::string& new_query) {
    if (rand() % 100 < 15) {
    
        if (rand() % 100 < 15) {
            int auto_vacuum_modes[] = {0, 1, 2};  // Auto vacuum modes: NONE (0), FULL (1), INCREMENTAL (2)
            int selected_vacuum_mode = auto_vacuum_modes[rand() % 3];  // Randomly choose between 0, 1, or 2
            std::string vacuum_mode = (selected_vacuum_mode == 0) ? "NONE" : (selected_vacuum_mode == 1) ? "FULL" : "INCREMENTAL";
            new_query += "PRAGMA auto_vacuum = " + vacuum_mode + "; ";

            if (!(query_info.type2_scenario & DIFF2_SQLITE_PRAGMA)){
                query_info.type2_scenario |= DIFF2_SQLITE_PRAGMA;
            }
        }

        if (rand() % 100 < 15) {
            bool enable_automatic_index = rand() % 2 == 0;  // Randomly enable or disable
            new_query += "PRAGMA automatic_index = " + std::string(enable_automatic_index ? "true" : "false") + "; ";
            s
            if (!(query_info.type2_scenario & DIFF2_SQLITE_PRAGMA)){
                query_info.type2_scenario |= DIFF2_SQLITE_PRAGMA;
            }
        }

        if (rand() % 100 < 15) {
            int busy_timeout = rand() % 5000 + 1000;  // Random timeout between 1000 and 5000 milliseconds
            new_query += "PRAGMA busy_timeout = " + std::to_string(busy_timeout) + "; ";
            
            if (!(query_info.type2_scenario & DIFF2_SQLITE_PRAGMA)){
                query_info.type2_scenario |= DIFF2_SQLITE_PRAGMA;
            }
        }

        if (rand() % 100 < 15) {
            int cache_size = (rand() % 1000) - 500;  // Random cache size between -500 and 500 (negative for kibibytes)
            new_query += "PRAGMA cache_size = " + std::to_string(cache_size) + "; ";

            if (!(query_info.type2_scenario & DIFF2_SQLITE_PRAGMA)){
                query_info.type2_scenario |= DIFF2_SQLITE_PRAGMA;
            }
        }

        if (rand() % 100 < 15) {
            if (rand() % 2 == 0) {
                bool cache_spill_enabled = rand() % 2 == 0;  // Randomly enable or disable cache spill
                new_query += "PRAGMA cache_spill = " + std::string(cache_spill_enabled ? "true" : "false") + "; ";
            } else {
                int spill_size = rand() % 1000 + 100;  // Random cache spill size between 100 and 1000 pages
                new_query += "PRAGMA cache_spill = " + std::to_string(spill_size) + "; ";
            }

            if (!(query_info.type2_scenario & DIFF2_SQLITE_PRAGMA)){
                query_info.type2_scenario |= DIFF2_SQLITE_PRAGMA;
            }
        }

        if (rand() % 100 < 15) {
            bool cell_size_check = rand() % 2 == 0;
            new_query += "PRAGMA cell_size_check = " + std::string(cell_size_check ? "true" : "false") + "; ";

            if (!(query_info.type2_scenario & DIFF2_SQLITE_PRAGMA)){
                query_info.type2_scenario |= DIFF2_SQLITE_PRAGMA;
            }
        }

        if (rand() % 100 < 15) {
            bool count_changes = rand() % 2 == 0;
            new_query += "PRAGMA count_changes = " + std::string(count_changes ? "true" : "false") + "; ";

            if (!(query_info.type2_scenario & DIFF2_SQLITE_PRAGMA)){
                query_info.type2_scenario |= DIFF2_SQLITE_PRAGMA;
            }
        }

        if (rand() % 100 < 15) {
            int default_cache_size = rand() % 1000 + 1;  // Random default cache size between 1 and 1000 pages
            new_query += "PRAGMA default_cache_size = " + std::to_string(default_cache_size) + "; ";

            if (!(query_info.type2_scenario & DIFF2_SQLITE_PRAGMA)){
                query_info.type2_scenario |= DIFF2_SQLITE_PRAGMA;
            }
        }

        if (rand() % 100 < 15) {
            int encoding_choice = rand() % 4; 
            std::string encoding = (encoding_choice == 0) ? "'UTF-8'" : (encoding_choice == 1) ? "'UTF-16'" : (encoding_choice == 2) ? "'UTF-16le'" : "'UTF-16be'";
            new_query += "PRAGMA encoding = " + encoding + "; ";

            if (!(query_info.type2_scenario & DIFF2_SQLITE_PRAGMA)){
                query_info.type2_scenario |= DIFF2_SQLITE_PRAGMA;
            }
        }

        if (rand() % 100 < 15) {
            std::string journal_modes[] = { "DELETE", "TRUNCATE", "PERSIST", "MEMORY", "WAL", "OFF" };
            std::string selected_journal_mode = journal_modes[rand() % 6];  // Randomly choose one mode
            new_query += "PRAGMA journal_mode = " + selected_journal_mode + "; ";

            if (!(query_info.type2_scenario & DIFF2_SQLITE_PRAGMA)){
                query_info.type2_scenario |= DIFF2_SQLITE_PRAGMA;
            }
        }

        if (rand() % 100 < 15) {
            int journal_size_limit = rand() % 10000 + 1000;  // Random journal size limit between 1000 and 10000 bytes
            new_query += "PRAGMA journal_size_limit = " + std::to_string(journal_size_limit) + "; ";

            if (!(query_info.type2_scenario & DIFF2_SQLITE_PRAGMA)){
                query_info.type2_scenario |= DIFF2_SQLITE_PRAGMA;
            }
        }

        if (rand() % 100 < 15) {
            std::string locking_modes[] = { "NORMAL", "EXCLUSIVE" };
            std::string selected_locking_mode = locking_modes[rand() % 2];  // Randomly choose one mode
            new_query += "PRAGMA locking_mode = " + selected_locking_mode + "; ";

            if (!(query_info.type2_scenario & DIFF2_SQLITE_PRAGMA)){
                query_info.type2_scenario |= DIFF2_SQLITE_PRAGMA;
            }
        }

        if (rand() % 100 < 15) {
            int max_page_count = rand() % 10000 + 1000;  // Random max page count between 1000 and 10000 pages
            new_query += "PRAGMA max_page_count = " + std::to_string(max_page_count) + "; ";

            if (!(query_info.type2_scenario & DIFF2_SQLITE_PRAGMA)){
                query_info.type2_scenario |= DIFF2_SQLITE_PRAGMA;
            }
        }

        if (rand() % 100 < 15) { 
            int mmap_size = rand() % 100000 + 1000;  // Random mmap size between 1000 and 100000 bytes
            new_query += "PRAGMA mmap_size = " + std::to_string(mmap_size) + "; ";

            if (!(query_info.type2_scenario & DIFF2_SQLITE_PRAGMA)){
                query_info.type2_scenario |= DIFF2_SQLITE_PRAGMA;
            }
        }

        if (rand() % 100 < 15) {
            int page_size = (1 << (rand() % 7 + 9));  // Random page size between 512 (2^9) and 65536 (2^16) bytes
            new_query += "PRAGMA page_size = " + std::to_string(page_size) + "; ";

            if (!(query_info.type2_scenario & DIFF2_SQLITE_PRAGMA)){
                query_info.type2_scenario |= DIFF2_SQLITE_PRAGMA;
            }
        }

        if (rand() % 100 < 15) {
            bool read_uncommitted = rand() % 2 == 0;
            new_query += "PRAGMA read_uncommitted = " + std::string(read_uncommitted ? "true" : "false") + "; ";

            if (!(query_info.type2_scenario & DIFF2_SQLITE_PRAGMA)){
                query_info.type2_scenario |= DIFF2_SQLITE_PRAGMA;
            }
        }

        if (rand() % 100 < 15) {
            int schema_version = rand() % 10000;  // Random schema version between 0 and 9999
            new_query += "PRAGMA schema_version = " + std::to_string(schema_version) + "; ";

            if (!(query_info.type2_scenario & DIFF2_SQLITE_PRAGMA)){
                query_info.type2_scenario |= DIFF2_SQLITE_PRAGMA;
            }
        }

        if (rand() % 100 < 15) {
            std::string secure_delete_modes[] = { "false", "true", "FAST" };
            std::string selected_secure_delete = secure_delete_modes[rand() % 3];  // Randomly choose between OFF, ON, FAST
            new_query += "PRAGMA secure_delete = " + selected_secure_delete + "; ";

            if (!(query_info.type2_scenario & DIFF2_SQLITE_PRAGMA)){
                query_info.type2_scenario |= DIFF2_SQLITE_PRAGMA;
            }
        }

        if (rand() % 100 < 15) {
            int soft_heap_limit = rand() % 100000 + 10000;  // Random soft heap limit between 10000 and 100000 bytes
            new_query += "PRAGMA soft_heap_limit = " + std::to_string(soft_heap_limit) + "; ";

            if (!(query_info.type2_scenario & DIFF2_SQLITE_PRAGMA)){
                query_info.type2_scenario |= DIFF2_SQLITE_PRAGMA;
            }
        }

        if (rand() % 100 < 15) {  
            int synchronous_modes[] = { 0, 1, 2, 3 };
            int selected_synchronous_mode = synchronous_modes[rand() % 4];  // Randomly choose one mode
            std::string mode_string = (selected_synchronous_mode == 0) ? "OFF" : std::to_string(selected_synchronous_mode);
            new_query += "PRAGMA synchronous = " + mode_string + "; ";

            if (!(query_info.type2_scenario & DIFF2_SQLITE_PRAGMA)){
                query_info.type2_scenario |= DIFF2_SQLITE_PRAGMA;
            }
        }

        if (rand() % 100 < 15) { 
            int temp_store_modes[] = { 0, 1, 2 };
            int selected_temp_store_mode = temp_store_modes[rand() % 3];  // Randomly choose one mode
            std::string mode_string = (selected_temp_store_mode == 0) ? "DEFAULT" : (selected_temp_store_mode == 1) ? "FILE" : "MEMORY";
            new_query += "PRAGMA temp_store = " + mode_string + "; ";

            if (!(query_info.type2_scenario & DIFF2_SQLITE_PRAGMA)){
                query_info.type2_scenario |= DIFF2_SQLITE_PRAGMA;
            }
        }

        if (rand() % 100 < 15) { 
            int max_threads = rand() % 16 + 1;  // Random number of threads between 1 and 16
            new_query += "PRAGMA threads = " + std::to_string(max_threads) + "; ";

            if (!(query_info.type2_scenario & DIFF2_SQLITE_PRAGMA)){
                query_info.type2_scenario |= DIFF2_SQLITE_PRAGMA;
            }
        }

        if (rand() % 100 < 15) { 
            int wal_autocheckpoint = rand() % 1000 + 1;  // Random WAL autocheckpoint value between 1 and 1000 pages
            new_query += "PRAGMA wal_autocheckpoint = " + std::to_string(wal_autocheckpoint) + "; ";

            if (!(query_info.type2_scenario & DIFF2_SQLITE_PRAGMA)){
                query_info.type2_scenario |= DIFF2_SQLITE_PRAGMA;
            }
        }

        if (rand() % 100 < 15) { 
            new_query += "PRAGMA optimize; ";

            if (!(query_info.type2_scenario & DIFF2_SQLITE_PRAGMA)){
                query_info.type2_scenario |= DIFF2_SQLITE_PRAGMA;
            }
        }
    }
}

// Function to handle SQLite-specific processing with random probability
void processSQLite(QueryInfo& query_info) {
    srand(time(NULL));  // Initialize the random seed

    for (auto& query : query_info.queries) {
        std::stringstream ss(query);
        std::string statement;
        std::string new_query;

        addPragmaCommands(query_info, new_query);

        // Process each SQL statement (e.g., CREATE TABLE, INSERT, SELECT)
        bool modified = false;
        while (std::getline(ss, statement, ';')) {
            // Trim leading/trailing spaces
            statement.erase(0, statement.find_first_not_of(" \t\n\r"));
            statement.erase(statement.find_last_not_of(" \t\n\r") + 1);

            // Process CREATE TABLE statements
            size_t create_pos = statement.find("CREATE TABLE");
            if (create_pos != std::string::npos) {
                size_t pk_pos = statement.find("PRIMARY KEY", create_pos);

                if (pk_pos != std::string::npos) {
                    // Check if "WITHOUT ROWID" is already present
                    if (statement.find("WITHOUT ROWID") == std::string::npos) {
                        // Randomly decide whether to apply WITHOUT ROWID (e.g., 50% chance)
                        if (rand() % 100 < 30) {  // 30% chance to add WITHOUT ROWID
                            statement += " WITHOUT ROWID";
                            modified = true;
                            // Set the appropriate flag in type2_scenario
                            query_info.type2_scenario |= DIFF2_SQLite_WITHOUT_ROWID;
                        }
                    }
                }
            }

            // Rebuild the query with modified statements
            if (!statement.empty()) {
                new_query += statement + "; ";
            }
        }

        // If modified, update the original query with the modified query
        if (modified) {
            query = new_query;
        } else {
            query = new_query;  // Apply new query regardless of modification
        }
    }
}

// Function to handle MySQL-specific processing with random application and UNIQUE check
void processMySQL(QueryInfo& query_info) {
    srand(time(NULL));  // Initialize the random seed

    for (auto& query : query_info.queries) {
        std::stringstream ss(query);
        std::string statement;
        std::string new_query;
        bool modified = false;

        // Process each SQL statement (e.g., CREATE INDEX, ALTER INDEX, INSERT, SELECT)
        while (std::getline(ss, statement, ';')) {
            // Trim leading/trailing spaces
            statement.erase(0, statement.find_first_not_of(" \t\n\r"));
            statement.erase(statement.find_last_not_of(" \t\n\r") + 1);

            // Handle CREATE INDEX for MySQL with a 50% chance, but skip if UNIQUE
            size_t create_index_pos = statement.find("CREATE INDEX");
            if (create_index_pos != std::string::npos) {
                // Check if the index is UNIQUE
                size_t unique_pos = statement.find("UNIQUE", create_index_pos);
                if (unique_pos == std::string::npos) {  // Only proceed if the index is NOT UNIQUE
                    // Randomly decide whether to apply INVISIBLE (50% chance)
                    if (rand() % 100 < 50) {
                        // Check if "INVISIBLE" is already present
                        if (statement.find("INVISIBLE") == std::string::npos) {
                            // Add INVISIBLE at the end of the CREATE INDEX statement
                            statement += " INVISIBLE";
                            modified = true;
                            query_info.type2_scenario |= DIFF2_MYSQL_CREATE_INVISIBLE_INDEX;
                        }
                    }
                }
            }

            // Handle ALTER INDEX for MySQL with a 30% chance
            size_t alter_index_pos = statement.find("ALTER INDEX");
            if (alter_index_pos != std::string::npos) {
                // Randomly decide whether to apply INVISIBLE (30% chance)
                if (rand() % 100 < 30) {
                    // Check if "INVISIBLE" is already present
                    if (statement.find("INVISIBLE") == std::string::npos) {
                        // Add INVISIBLE at the end of the ALTER INDEX statement
                        statement += " INVISIBLE";
                        modified = true;
                        query_info.type2_scenario |= DIFF2_MYSQL_ALTER_INVISIBLE_INDEX;
                    }
                }
            }

            // Rebuild the query with modified statements
            if (!statement.empty()) {
                new_query += statement + "; ";
            }
        }

        // Update the original query with the modified query if modified
        if (modified) {
            query = new_query;
        }
    }
}

// Function to handle PostgreSQL-specific processing
void processPostgreSQL(QueryInfo& query_info) {
    // Add PostgreSQL specific logic here
}

// Function to handle Oracle-specific processing with random application and UNIQUE check
void processOracle(QueryInfo& query_info) {
    srand(time(NULL));  // Initialize the random seed

    for (auto& query : query_info.queries) {
        std::stringstream ss(query);
        std::string statement;
        std::string new_query;
        bool modified = false;

        // Process each SQL statement (e.g., CREATE INDEX, ALTER INDEX, INSERT, SELECT)
        while (std::getline(ss, statement, ';')) {
            // Trim leading/trailing spaces
            statement.erase(0, statement.find_first_not_of(" \t\n\r"));
            statement.erase(statement.find_last_not_of(" \t\n\r") + 1);

            // Handle CREATE INDEX for Oracle with a 50% chance, but skip if UNIQUE
            size_t create_index_pos = statement.find("CREATE INDEX");
            if (create_index_pos != std::string::npos) {
                // Check if the index is UNIQUE
                size_t unique_pos = statement.find("UNIQUE", create_index_pos);
                if (unique_pos == std::string::npos) {  // Only proceed if the index is NOT UNIQUE
                    // Randomly decide whether to apply INVISIBLE (50% chance)
                    if (rand() % 100 < 50) {
                        // Check if "INVISIBLE" is already present
                        if (statement.find("INVISIBLE") == std::string::npos) {
                            // Add INVISIBLE at the end of the CREATE INDEX statement
                            statement += " INVISIBLE";
                            modified = true;
                            query_info.type2_scenario |= DIFF2_ORACLE_CREATE_INVISIBLE_INDEX;
                        }
                    }
                }
            }

            // Handle ALTER INDEX for Oracle with a 30% chance
            size_t alter_index_pos = statement.find("ALTER INDEX");
            if (alter_index_pos != std::string::npos) {
                // Randomly decide whether to apply INVISIBLE (30% chance)
                if (rand() % 100 < 30) {
                    // Check if "INVISIBLE" is already present
                    if (statement.find("INVISIBLE") == std::string::npos) {
                        // Add INVISIBLE at the end of the ALTER INDEX statement
                        statement += " INVISIBLE";
                        modified = true;
                        query_info.type2_scenario |= DIFF2_ORACLE_ALTER_INVISIBLE_INDEX;
                    }
                }
            }

            // Rebuild the query with modified statements
            if (!statement.empty()) {
                new_query += statement + "; ";
            }
        }

        // Update the original query with the modified query if modified
        if (modified) {
            query = new_query;
        }
    }
}

// mutation 전 : old_plan
// 현재 실행 중(mutation 후 transpiled plan) : plan
// Main postprocess function that routes to DBMS-specific handlers
void postprocess(OraclePlan *plan) {
    for (auto& query_info_pair : plan->query_infos) {
        Target dbms_target = query_info_pair.first;
        QueryInfo& query_info = query_info_pair.second;

        switch (dbms_target) {
            case Target::SQLite:
                processSQLite(query_info);
                break;
            case Target::MySQL:
                processMySQL(query_info);
                break;
            case Target::PostgreSQL:
                processPostgreSQL(query_info);
                break;
            case Target::Oracle:
                processOracle(query_info);
                break;
            default:
                std::cerr << "Unsupported DBMS target encountered: " << target_to_string(dbms_target) << ".\n";
                break;
        }
    }
}

/*
void postprocess(OraclePlan *plan, OraclePlan *old_plan) {
  // Perform operations on the plan, perhaps modifying it based on old_plan or
  // other logic
  if (old_plan) {
    // Example: If old_plan exists, copy some data from old_plan to plan
    // plan->oracle_plan = old_plan->oracle_plan;  // Just an example action
  }

  // Additional post-processing steps can be added here based on your needs
}
*/