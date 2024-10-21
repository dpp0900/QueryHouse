#ifndef __PROTOCOL_H__
#define __PROTOCOL_H__

#include <algorithm>
#include <cstdint>
#include <fstream>
#include <iostream>
#include <map>
#include <memory>  // for smart pointers
#include <string>
#include <vector>

#include "client.h"

extern std::ofstream outfile;
extern std::ofstream errfile;

// Define ANSI color codes
#define BLACK "\033[30m"
#define BRIGHT_RED "\033[91m"
#define BRIGHT_GREEN "\033[92m"
#define BRIGHT_YELLOW "\033[93m"
#define BRIGHT_BLUE "\033[94m"
#define BRIGHT_MAGENTA "\033[95m"
#define BRIGHT_CYAN "\033[96m"
#define BRIGHT_WHITE "\033[97m"

#define BOLD_BLACK "\033[1m\033[30m"
#define BOLD_RED "\033[1m\033[31m"
#define BOLD_GREEN "\033[1m\033[32m"
#define BOLD_YELLOW "\033[1m\033[33m"
#define BOLD_BLUE "\033[1m\033[34m"
#define BOLD_MAGENTA "\033[1m\033[35m"
#define BOLD_CYAN "\033[1m\033[36m"
#define BOLD_WHITE "\033[1m\033[37m"

#define RESET "\033[0m"
#define RED "\033[31m"
#define GREEN "\033[32m"
#define YELLOW "\033[33m"
#define BLUE "\033[34m"
#define MAGENTA "\033[35m"
#define CYAN "\033[36m"
#define WHITE "\033[37m"

using std::uint32_t;
using std::uint8_t;

/***************************************
 * Target DBMS
 ***************************************/

/*
 *  Target DBMS
 */
#define MAX_TARGET 8

// Targets are always ordered
enum class Target : uint8_t {
  SQLite = 0,
  MySQL = 1,
  PostgreSQL = 2,
  Oracle = 3
};

std::string target_to_string(Target target);

// For iterating over targets
//  E.g., for (uint8_t t = TargetStart; t <= TargetEnd; t++) ...;
constexpr uint8_t TargetStart = static_cast<uint8_t>(Target::SQLite);
constexpr uint8_t TargetEnd = static_cast<uint8_t>(Target::Oracle);  // 3

// TargetsMask bitmasks targets
using TargetsMask = uint8_t;

// Bitmask for each target
#define TARGET(db) (1 << static_cast<uint8_t>(db))
#define TARGET_NONE 0
#define TARGET_ALL                                  \
  (TARGET(Target::SQLite) | TARGET(Target::MySQL) | \
   TARGET(Target::PostgreSQL) | TARGET(Target::Oracle))

// Conversion between a vector of targets and bitmask for it
TargetsMask to_flag(std::vector<Target> targets);  // TODO
std::vector<Target> to_targets(TargetsMask targets);

/***************************************
 * QueryQueue
 ***************************************/

/*
 * QueryQueue:
 *
 * Buffer for queries after transpile, before oracle plan, type-2 post-process
 */
using QueryQueue = std::map<enum Target, std::string>;
// E.g.,:
//      QueryQueue q;
//      q[SQLite] = "sqlite query...";

/***************************************
 * Oracle Planner
 ***************************************/

/*
 *  Oracles
 */
// MAX_ORACLE: max number of comparison
#define MAX_ORACLE 8
// MAX_ORACLE_TYPE: max number of comparison type
#define MAX_ORACLE_TYPE 8

// Oracle types: what to compare
using OracleType = uint8_t;

#define ORACLE_SKIP 0
#define ORACLE_ROWNUM 1
#define ORACLE_ROW_NO_OPT 2  // not for standalone use
#define ORACLE_ROW ORACLE_ROWNUM | ORACLE_ROW_NO_OPT
#define ORACLE_SCHEMA 4  // not supported yet

/*
 *  Type-2 diff test scenario
 */
using DiffTestMask = uint32_t;

#define DIFF2_NONE 0
#define DIFF2_SQLite_WITHOUT_ROWID 1
// ...

/*
 * QueryInfo:
 *
 * Buffer for quries after oracle plan, type-2 post-process, before encoding
 * Dedicated for each DBMS
 *
 *  queries: list of queries for the specific DBMS
 *  type2_scenario: bitmask for type2 scenario information for the specific DBMS
 */
class QueryInfo {
 public:
  QueryInfo() {
    queries = {};
    type2_scenario = 0;
  }

  std::vector<std::string> queries;
  DiffTestMask type2_scenario;

  // Length of queries in bytes, when concatenated, with each string deliminated
  // by NULL
  size_t total_size();
  // Write concatenation of queires with each string deliminated by NULL at
  // `buf`
  char *write_at(char *buf);
};
// E.g.:
//      QueryInfo *qinfo = new QueryInfo();
//      qinfo->queries = { "1st stmt; 2nd stmt;", "3rd stmt;" };
//      qinfo->type2_scenario = DIFF2_SQLite_WITHOUT_ROWID | ... ;

/*
 * OraclePlan:
 *
 * Plan of execution and oracle of an input -- what and when to compare
 *
 *  src_query: General soruce query before transpilation
 *  oracle_plan:
 *      what to compare (oracle type) at each oracle step
 *      max size = MAX_ORACLE
 *  query_infos:
 *      mapping from DBMS to its QueryInfo
 */
class OraclePlan {
 public:
  OraclePlan(std::string _src_query) { src_query = _src_query; }

  std::string src_query;
  std::vector<OracleType> oracle_plan;
  std::map<enum Target, QueryInfo> query_infos;

  // Validate if OraclePlan has everything ready to be encoded into Round
  bool is_valid();
  // Returns a string for printing all contents of OraclePlan
  std::string to_string();
};
// E.g.,:
//      OraclePlan *p = new OraclePlan("source_query....");
//      p->query_infos[Target::SQlite] = *qinfo;

/*
 * oracle_planner()
 *
 * Creates an OraclePlan for the given `query_queue`.
 *   - Set original query -> OraclePlan::src_query
 *   - Splits the queries for each DBMS into the same number of pieces. ->
 * QueryInfo::queries
 *   - Specify what to compare (oracle type) after execution of each piece ->
 * OraclePlan::oracle_plan note: QueryInfo::type2_scenario is managed by
 * postprocess(), not by oracle_planner().
 *
 */
OraclePlan *oracle_planner(const std::string src_query,
                           QueryQueue *query_queue);  // TODO

/*
 * postprocess()
 *
 * Post-processing on the given `plan` after oracle_planner(), including:
 *   - Add type-2 diff test scneario
 *   - ... (not supported yet) ...
 *
 * It can refer to the plan of the original seed `old_plan` as hints.
 */
void postprocess(OraclePlan *plan, OraclePlan *old_plan);  // TODO

/***************************************
 * Round
 ***************************************/

/*
 * Round:
 *
 * A Round of an execution
 * This must be in raw data types since it will be directly stored in a file as
 * a seed.
 */
typedef struct Round {
  // Targeets bitmask
  TargetsMask targets;  // uint8_t 1..sqlite 2...~ 4..~ 8..

  // Number of comparisons = Number of query pieces = Number of oracles
  uint8_t num_oracle;
  // List of what to compare = OracleType, length must be same with num_oracle
  OracleType oracle_plans[MAX_ORACLE];

  // Bitmasks for per-DBMS type-2 diff test scenario
  DiffTestMask type2_scenario[MAX_TARGET];

  // Offsets: per-DBMS query offset from buf_queries, -1 for empty
  int query_offset[MAX_TARGET];

  // Original query || NULL || Per-DBMS query, with each oracle checkpoint
  // deliminated by NULL
  char buf_queries[];
} Round;

#define MAX_ROUND_SIZE 0x100000

/*****   Encoder   *****/
Round *encode(OraclePlan *plan);

/*****   Decoder   *****/
OraclePlan *decode(Round *r);
#define original_query(r) (r->buf_queries)
#define query_start(r, db) \
  (r->buf_queries + r->query_offset[static_cast<uint8_t>(db)])

// Get the vector of query pieces of the given target `db` from the given Round
// `r`
std::vector<char *> get_querylist(Round *r, Target db);

/***** Auxiliary *****/
// Mask the target set in the Round
inline void set_target(Round *r, Target db);
// Returns true if the given target is masked in the given round, false
// otherwise
inline bool is_target_set(Round *r, Target db);

/***************************************
 * Oracle Executor (Result Analyzer)
 ***************************************/

// Constants for formatting
const int TOTAL_LENGTH =
    8;  // Total length of the number including leading zeros
const int TRAILING_ZEROS = 4;  // Number of decimal places
constexpr int PREPENDING_ZEROS = TOTAL_LENGTH - TRAILING_ZEROS;

// Helper function to determine if a string can be interpreted as a float
bool isFloat(const std::string &myString);

// Helper function to trim quotation marks from strings
std::string trimQuotes(const std::string &str);

// Function to format a float string into a fixed-length string with leading
// zeros
std::string formatFloat(const std::string &floatStr);

// Function to normalize values before sorting by trimming quotes and formatting
// floats
std::vector<std::vector<std::string>> normalizeValues(
    const std::vector<std::vector<std::string>> &result);
// result struct
typedef struct Result {
  Target target;
  std::vector<std::vector<std::string>> result;
  client::ExecutionStatus status;
} Result;

bool execute_plan(
    OraclePlan &plan,
    const std::vector<std::unique_ptr<client::DBClient>> &db_clients,
    std::vector<Result> &results);

/*
 * compare_row_num()
 *
 * Compares the number of rows between two query results and prints an
 * explanation if they differ.
 */
bool compare_row_num(const std::vector<Result> &results);

/*
 * compare_row()
 *
 * Compares the content of each row between two query results and prints an
 * explanation if they differ.
 */
bool compare_row(const std::vector<Result> &results);

// Function to skip comparison
bool compare_skip(size_t step);

// Function to compare schema (currently not supported)
bool compare_schema(size_t step);

/*
 * report()
 *
 * Reports a bug on wrong results.
 *  - Log on file
 *  - Prints OraclePlan, which DBMS is buggy on which piece of queries
 */
void report(OraclePlan &plan, uint8_t position,
            std::vector<Result> &results);  // TODO
void log_queries_for_target(std::ofstream &outfile, const OraclePlan &plan,
                            Target target, const std::string &target_name,
                            uint8_t position, std::vector<Result> &results);
// void print_buf_queries(const char* buf, size_t length);

#endif  // __PROTOCOL_H__
