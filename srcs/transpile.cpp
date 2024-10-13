#include "transpile.h"

#include <pybind11/embed.h>

#include <cstring>
#include <vector>

/***************************************
 * QueryQueue
 ***************************************/

// To use Python module in C++
namespace py = pybind11;

/***************************************
 * Transpiler
 ***************************************/
/*
 * transpile()
 *
 * Transpiles a given `query` for DBMSs specified by the bitmask `targets`
 *
 * Returns the QueryQueue containing the transpilation result
 *
 * This is a wrapper for transpile_for()
 */
QueryQueue transpile(const std::string &query, TargetsMask targets) {
  QueryQueue q;

  // 먼저 전체 쿼리를 ;로 구분된 쿼리 조각으로 나눔
  std::vector<std::string> split_queries =
      split_query(query.c_str(), query.size());

  // 각 쿼리 조각에 대해 DBMS별 변환을 수행
  for (const auto &single_query : split_queries) {
    for (Target &t : to_targets(targets)) {
      // 각각의 쿼리를 sqlglot을 통해 변환
      std::string transpiled_query = transpile_for(single_query, t);

      // 변환된 쿼리를 QueryQueue에 추가
      q[t] += transpiled_query + "; ";  // 변환 결과 추가 후 ;로 구분
    }
  }

  return q;
}

// 공백을 제거하는 함수
std::string trim(const std::string &str) {
  size_t start = str.find_first_not_of(" \t\n\r");
  if (start == std::string::npos) return "";  // 모두 공백인 경우 빈 문자열 반환
  size_t end = str.find_last_not_of(" \t\n\r");
  return str.substr(start, end - start + 1);
}

// 쿼리를 ; 기준으로 나누고, 공백이나 빈 쿼리는 무시하는 함수
std::vector<std::string> split_query(const char *buf, size_t len) {
  std::vector<std::string> queries;
  std::string query;
  for (size_t i = 0; i < len; i++) {
    if (buf[i] == ';') {
      query.push_back(buf[i]);
      query = trim(query);   // 앞뒤 공백 제거
      if (!query.empty()) {  // 공백이 아닌 경우만 추가
        queries.push_back(query);
      }
      query.clear();
    } else {
      query.push_back(buf[i]);
    }
  }

  // 마지막에 남아 있는 쿼리도 처리
  query = trim(query);
  if (!query.empty()) {
    queries.push_back(query);
  }
  return queries;
}

/*
 * transpile_for()
 *
 * Transpiles a given `query` for the specified DBMS `target`
 *
 * This is a actual worker of transpiler.
 */
std::string transpile_for(const std::string &query, Target target) {
  // Import the SQLglot module
  py::object sqlglot = py::module::import("sqlglot");

  // Set the appropriate dialect for the target
  std::string dialect;
  switch (target) {
    case Target::SQLite:
      dialect = "sqlite";
      break;
    case Target::MySQL:
      dialect = "mysql";
      break;
    case Target::PostgreSQL:
      dialect = "postgres";
      break;
    case Target::Oracle:
      dialect = "oracle";
      break;
    default:
      throw std::invalid_argument("Unsupported target");
  }

  try {
    // Call the transpile function from SQLglot to convert the query
    py::object transpile_func = sqlglot.attr("transpile");

    // Pass the query and target dialect to SQLglot for transpiling
    py::object transpiled_query_obj = transpile_func(query, dialect);

    // Convert the Python object (likely a list) to a Python list
    py::list transpiled_query_list = transpiled_query_obj.cast<py::list>();

    // Extract the first query from the list if it's not empty
    std::string transpiled_query = "";
    if (!transpiled_query_list.empty()) {
      // Get the first element from the list and cast it to std::string
      transpiled_query = transpiled_query_list[0].cast<std::string>();
    } else {
      throw std::runtime_error("Transpiling returned an empty list");
    }

    return transpiled_query;
  } catch (py::error_already_set &e) {
    std::cerr << "Python error: " << e.what() << std::endl;
    return "";
  } catch (const std::exception &e) {
    std::cerr << "C++ error: " << e.what() << std::endl;
    return "";
  }
}
