#include "client_mysql.h"

#include <unistd.h>

#include <cstring>
#include <deque>
#include <fstream>
#include <iostream>
#include <optional>
#include <string>
#include <string_view>
#include <vector>

std::fstream mysql_logfile("/tmp/mysql.log", std::ios::out | std::ios::app);

#include "mysql.h"
#include "mysqld_error.h"

using namespace std;
namespace {
bool is_crash_response(int response) {
  return response == CR_SERVER_LOST || response == CR_SERVER_GONE_ERROR;
}
};  // namespace

namespace client {

void MySQLClient::initialize(YAML::Node config) {
  host_ = config["host"].as<std::string>();
  user_name_ = config["user_name"].as<std::string>();
  passwd_ = config["passwd"].as<std::string>();
  sock_path_ = config["sock_path"].as<std::string>();
  db_prefix_ = config["db_prefix"].as<std::string>();
}

void MySQLClient::prepare_env() {
  ++database_id_;
  std::string database_name = db_prefix_ + std::to_string(database_id_);
  if (!create_database(database_name)) {
    mysql_logfile << "Failed to create database." << std::endl;
  }
}

ExecutionStatus MySQLClient::execute(
    const char *query, size_t size,
    std::vector<std::vector<std::string>> &result) {
  mysql_logfile << "[MySQL] Executing queries..." << std::endl;

  // 쿼리 분리
  std::vector<std::string> queries = split_query(query, size);

  // 데이터베이스 접속 정보 설정
  std::string database_name = db_prefix_ + std::to_string(database_id_);

  // 연결 생성
  std::optional<MYSQL> connection = create_connection(database_name);
  if (!connection.has_value()) {
    mysql_logfile << "Cannot create connection at execute" << std::endl;
    mysql_close(&(*connection));

    return kConnectFailed;
  }

  // 각 쿼리 실행
  for (const auto &q : queries) {
    mysql_logfile << "[MySQL] Execute query: " << q << std::endl;

    // 쿼리 실행
    int server_response = mysql_real_query(&(*connection), q.c_str(), q.size());
    if (server_response != 0) {
      mysql_logfile << "MySQL query error: " << mysql_error(&(*connection))
                    << std::endl;
      clean_up_connection(*connection);
      mysql_close(&(*connection));
      return kExecuteError;
    }

    // 결과 저장
    MYSQL_RES *query_result = mysql_store_result(&(*connection));
    if (!query_result && mysql_errno(&(*connection)) != 0) {
      mysql_logfile << "MySQL store result error: "
                    << mysql_error(&(*connection)) << std::endl;
      clean_up_connection(*connection);
      mysql_close(&(*connection));
      return kExecuteError;
    }

    // 결과 처리
    if (query_result) {
      int num_fields = mysql_num_fields(query_result);
      MYSQL_ROW row;
      while ((row = mysql_fetch_row(query_result))) {
        std::vector<std::string> row_result;
        for (int i = 0; i < num_fields; ++i) {
          row_result.push_back(row[i] ? row[i] : "NULL");
        }
        result.push_back(row_result);
      }
      mysql_free_result(query_result);
    }

    // 다중 쿼리 처리
    int next_result_response = mysql_next_result(&(*connection));
    if (next_result_response > 0) {
      mysql_logfile << "MySQL error while executing next query: "
                    << mysql_error(&(*connection)) << std::endl;
      clean_up_connection(*connection);
      mysql_close(&(*connection));
      return kSyntaxError;
    }
  }

  // 스키마 정보 조회
  mysql_logfile << "[MySQL] Retrieving schema information..." << std::endl;
  std::string schema_query =
      "SELECT table_name, table_type FROM information_schema.tables WHERE "
      "table_schema = '" +
      database_name + "';";
  int schema_response = mysql_real_query(&(*connection), schema_query.c_str(),
                                         schema_query.size());

  if (schema_response != 0) {
    mysql_logfile << "MySQL schema query error: " << mysql_error(&(*connection))
                  << std::endl;
    clean_up_connection(*connection);
    mysql_close(&(*connection));
    return kSyntaxError;
  }

  // 스키마 결과 처리
  // MYSQL_RES *schema_result = mysql_store_result(&(*connection));
  // if (schema_result) {
  //   MYSQL_ROW row;
  //   while ((row = mysql_fetch_row(schema_result))) {
  //     std::string table_name = row[0] ? row[0] : "NULL";
  //     std::string table_type = row[1] ? row[1] : "NULL";
  //     mysql_logfile << "Table: " << table_name << ", Type: " << table_type
  //                   << std::endl;

  //     // 각 테이블의 CREATE TABLE 구문 조회
  //     std::string create_table_query = "SHOW CREATE TABLE " + table_name +
  //     ";"; int create_table_response =
  //         mysql_real_query(&(*connection), create_table_query.c_str(),
  //                          create_table_query.size());
  //     if (create_table_response == 0) {
  //       MYSQL_RES *create_table_result = mysql_store_result(&(*connection));
  //       if (create_table_result) {
  //         MYSQL_ROW create_row;
  //         if ((create_row = mysql_fetch_row(create_table_result))) {
  //           mysql_logfile << "Create table query for " << table_name << ": "
  //                         << create_row[1] << std::endl;
  //         }
  //         mysql_free_result(create_table_result);
  //       }
  //     } else {
  //       mysql_logfile << "Failed to retrieve CREATE TABLE statement for "
  //                     << table_name << ": " << mysql_error(&(*connection))
  //                     << std::endl;
  //       return kExecuteError;
  //     }
  //   }
  //   mysql_free_result(schema_result);
  // } else {
  //   mysql_logfile << "Failed to fetch schema result: "
  //                 << mysql_error(&(*connection)) << std::endl;
  //   return kExecuteError;
  // }

  // 연결 정리 및 종료
  ExecutionStatus server_status = clean_up_connection(*connection);
  mysql_close(&(*connection));
  return server_status;
}

void MySQLClient::clean_up_env() {
  std::string database_name = db_prefix_ + std::to_string(database_id_);
  string reset_query = "DROP DATABASE IF EXISTS " + database_name + ";";
  std::optional<MYSQL> connection = create_connection("");
  if (!connection.has_value()) {
    return;
  }

  mysql_real_query(&(*connection), reset_query.c_str(), reset_query.size());
  clean_up_connection((*connection));
  mysql_close(&(*connection));
}

std::optional<MYSQL> MySQLClient::create_connection(std::string_view db_name) {
  MYSQL result;
  if (mysql_init(&result) == NULL) return std::nullopt;

  if (mysql_real_connect(&result, host_.c_str(), user_name_.c_str(),
                         passwd_.c_str(), db_name.data(), 0, sock_path_.c_str(),
                         CLIENT_MULTI_STATEMENTS) == NULL) {
    mysql_logfile << "Create connection failed: " << mysql_errno(&result)
                  << mysql_error(&result) << std::endl;
    mysql_close(&result);
    return std::nullopt;
  }

  return result;
}

bool MySQLClient::check_alive() {
  std::optional<MYSQL> connection = create_connection("");
  if (!connection.has_value()) {
    return false;
  }
  mysql_close(&(*connection));
  return true;
}

bool MySQLClient::create_database(const std::string &database) {
  MYSQL tmp_m;

  if (mysql_init(&tmp_m) == NULL) {
    mysql_close(&tmp_m);
    return false;
  }

  if (mysql_real_connect(&tmp_m, host_.c_str(), user_name_.c_str(),
                         passwd_.c_str(), nullptr, 0, sock_path_.c_str(),
                         CLIENT_MULTI_STATEMENTS) == NULL) {
    fprintf(stderr, "Connection error3 %d, %s\n", mysql_errno(&tmp_m),
            mysql_error(&tmp_m));
    mysql_close(&tmp_m);
    return false;
  }

  string cmd = "CREATE DATABASE IF NOT EXISTS " + database + ";";
  mysql_real_query(&tmp_m, cmd.c_str(), cmd.size());
  clean_up_connection(tmp_m);
  mysql_close(&tmp_m);
  return true;
}

ExecutionStatus MySQLClient::clean_up_connection(MYSQL &mm) {
  int res = -1;
  mysql_logfile << "[MySQL] Cleaning up connection..." << std::endl;

  do {
    auto q_result = mysql_store_result(&mm);
    if (q_result) {
      mysql_free_result(q_result);
    } else if (mysql_errno(&mm)) {
      mysql_logfile << "[MySQL] Error while fetching result: "
                    << mysql_errno(&mm) << " - " << mysql_error(&mm)
                    << std::endl;
      // 에러를 기록하고 계속 진행
    }
  } while ((res = mysql_next_result(&mm)) == 0);

  if (res != -1) {
    res = mysql_errno(&mm);
    if (is_crash_response(res)) {
      return kServerCrash;
    }
    if (res == ER_PARSE_ERROR) {
      return kSyntaxError;
    } else {
      mysql_logfile << "[MySQL] Error code: " << res << " - "
                    << mysql_error(&mm) << std::endl;
      return kSemanticError;
    }
  }

  return kNormal;
}

};  // namespace client
