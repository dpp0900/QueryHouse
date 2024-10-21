#include "protocol.h"

#include <cstring>
#include <fstream>  // for ofstream
#include <sstream>
#include <vector>

#include "client.h"

extern std::ofstream outfile;
extern std::ofstream errfile;
std::ofstream logfile("/tmp/reportLog", std::ios::out | std::ios::app);

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
    return false;
  }

  // Get the row count of the first DBMS as the reference
  auto reference_target = results.begin();
  size_t reference_row_count = reference_target->result.size();
  // auto reference_target = results.begin();
  // size_t reference_row_count = reference_target->second.size();

  bool match = true;

  // Compare the row count of each DBMS with the reference
  for (const auto &result : results) {
    // check status of each result
    if (result.status != client::kNormal) {
      outfile << "Error: " << target_to_string(result.target)
              << " returned with status: " << result.status << std::endl;
      return true;  // Skip comparison
    }
    if (result.result.size() != reference_row_count) {
      outfile << "Row count mismatch detected for target "
              << target_to_string(result.target) << ":\n";
      outfile << "  Target " << target_to_string(result.target) << " has "
              << result.result.size() << " rows.\n";
      match = false;
    }
  }

  // for (const auto &[target, result] : results) {
  //   if (result.size() != reference_row_count) {
  //     outfile << "Row count mismatch detected for target "
  //             << static_cast<int>(target) << ":\n";
  //     outfile << "  Target " << static_cast<int>(target) << " has "
  //             << result.size() << " rows.\n";
  //     match = false;
  //   }
  // }

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
bool compare_row(
    const std::map<Target, std::vector<std::vector<std::string>>> &results) {
  if (results.empty()) {
    std::cerr << "Error: No results to compare." << std::endl;
    return false;
  }

  // Prepare to store normalized and sorted results for all DBMS
  std::map<Target, std::vector<std::vector<std::string>>> sorted_results;

  // Normalize and sort all DBMS results
  for (const auto &[target, result] : results) {
    sorted_results[target] = normalizeValues(result);
    std::sort(sorted_results[target].begin(), sorted_results[target].end());
  }

  // Use the first DBMS's sorted result as the baseline for comparison
  auto reference_target = sorted_results.begin();
  const auto &sorted_reference = reference_target->second;

  // Compare all other DBMS results to the reference
  for (const auto &[target, sorted_result] : sorted_results) {
    if (target == reference_target->first)
      continue;  // Skip comparison with the reference

    if (sorted_reference != sorted_result) {
      std::cout << "Row 0 mismatch detected across DBMS:" << std::endl;

      // Print the mismatched row from each DBMS
      for (const auto &[dbms_target, dbms_result] : results) {
        std::string target_name = target_to_string(dbms_target);
        std::cout << "  " << target_name << ": [ ";
        for (const auto &val : dbms_result[0]) {
          std::cout << val << " ";
        }
        std::cout << "]" << std::endl;
      }

      return false;
    }
  }

  std::cout
      << "Rows are identical across all DBMS after normalization and sorting."
      << std::endl;
  return true;
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
        report(plan, TARGET_ALL, i, results);
        // report(plan, TARGET(Target::SQLite) | TARGET(Target::PostgreSQL), i,
        //        results);
        return false;  // Mark failure
      }

      // } else if (oracle_type == ORACLE_ROW) {
      //   // Log row content comparison
      //   outfile << YELLOW << "[Comparing row contents]" << RESET <<
      //   std::endl;

      //   if (!compare_row(results)) {
      //     outfile << "Row content mismatch at step " << i + 1 << std::endl;
      //     report(plan, TARGET_ALL, i);
      //     return false;  // Mark failure
      //   }

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
      report(plan, TARGET_ALL, i, results);
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

void report(OraclePlan &plan, TargetsMask buggy_targets, uint8_t position,
            std::vector<Result> &results) {
  outfile << YELLOW << "[Reporting Bug]" << RESET << std::endl;
  // 로그 파일 열기

  if (!logfile.is_open()) {
    outfile << RED << "Error: Could not open the log file." << RESET
            << std::endl;
    return;
  }

  logfile << "Bug Report:\n";

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
void postprocess(OraclePlan *plan, OraclePlan *old_plan) {
  // Perform operations on the plan, perhaps modifying it based on old_plan or
  // other logic
  if (old_plan) {
    // Example: If old_plan exists, copy some data from old_plan to plan
    // plan->oracle_plan = old_plan->oracle_plan;  // Just an example action
  }

  // Additional post-processing steps can be added here based on your needs
}