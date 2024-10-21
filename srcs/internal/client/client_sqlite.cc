#include "client_sqlite.h"

#include <fstream>
#include <iostream>
#include <string>
#include <vector>

std::fstream sqlite_logfile("/tmp/sqlite3.log", std::ios::out | std::ios::app);

namespace client {

void SQLiteClient::initialize(YAML::Node config) {
  db_prefix_ = config["db_prefix"].as<std::string>();
  db_path_ = config["db_path"].as<std::string>();
}

void SQLiteClient::prepare_env() {
  ++database_id_;
  std::string db_name = db_prefix_ + std::to_string(database_id_) + ".db";
  db_path_ = db_name;
  std::cout << "[SQLite] Prepared environment with DB: " << db_path_
            << std::endl;
}

ExecutionStatus SQLiteClient::execute(
    const char *query, size_t size,
    std::vector<std::vector<std::string>> &result) {
  std::cout << "[SQLite] Executing queries..." << std::endl;
  // sqlite_logfile << "[SQLite] Executing queries..." << std::endl;
  // sqlite_logfile << query << std::endl;

  // sqlite_logfile << "[SQLite] Result before execute: " << std::endl;
  std::vector<std::string> queries = split_query(query, size);
  sqlite3 *db = nullptr;

  // 데이터베이스 연결 생성
  if (auto conn = create_connection(); conn) {
    db = *conn;
    std::cout << "[SQLite] Connected to SQLite database" << std::endl;
  } else {
    std::cout << "Failed to connect to SQLite database" << std::endl;
    return kServerCrash;
  }

  // 각 쿼리를 처리
  for (const auto &q : queries) {
    std::cout << "[SQLite] Execute query: " << q << std::endl;

    sqlite3_stmt *stmt = nullptr;
    int result_code = sqlite3_prepare_v2(db, q.c_str(), -1, &stmt, nullptr);

    if (result_code != SQLITE_OK) {
      std::cout << "SQLite error preparing statement: " << sqlite3_errmsg(db)
                << std::endl;
      close_connection(db);
      return kSyntaxError;
    }

    // 쿼리 실행 및 결과 처리
    while (true) {
      result_code = sqlite3_step(stmt);

      if (result_code == SQLITE_ROW) {
        std::vector<std::string> row;
        for (int i = 0; i < sqlite3_column_count(stmt); i++) {
          const char *col =
              reinterpret_cast<const char *>(sqlite3_column_text(stmt, i));
          row.push_back(col ? col : "NULL");
        }
        result.push_back(row);
      } else if (result_code == SQLITE_DONE) {
        break;  // 쿼리 완료
      } else {
        std::cout << "SQLite error executing step: " << sqlite3_errmsg(db)
                  << std::endl;
        sqlite3_finalize(stmt);
        close_connection(db);
        return kExecuteError;
      }
    }

    sqlite3_finalize(stmt);  // 쿼리 완료 후 메모리 해제
  }
  if (result.empty()) {
    sqlite_logfile << "[SQLite] No result" << std::endl;
  } else {
    sqlite_logfile << "[SQLite] Execute Query: ";
    sqlite_logfile << query << std::endl;
    sqlite_logfile << "[SQLite] Result: " << std::endl;
    for (const auto &row : result) {
      for (const auto &col : row) {
        sqlite_logfile << col << " ";
      }
      sqlite_logfile << std::endl;
    }
  }
  // 스키마 정보 가져오기
  std::cout << "[SQLite] Retrieving schema information..." << std::endl;
  const char *schema_query =
      "SELECT type, name, tbl_name, sql FROM sqlite_master WHERE "
      "type='table';";
  sqlite3_stmt *schema_stmt = nullptr;
  int schema_result =
      sqlite3_prepare_v2(db, schema_query, -1, &schema_stmt, nullptr);

  if (schema_result != SQLITE_OK) {
    std::cout << "SQLite error retrieving schema: " << sqlite3_errmsg(db)
              << std::endl;
    close_connection(db);
    return kSyntaxError;
  }

  // 스키마 정보를 출력
  while (sqlite3_step(schema_stmt) == SQLITE_ROW) {
    const char *type =
        reinterpret_cast<const char *>(sqlite3_column_text(schema_stmt, 0));
    const char *name =
        reinterpret_cast<const char *>(sqlite3_column_text(schema_stmt, 1));
    const char *tbl_name =
        reinterpret_cast<const char *>(sqlite3_column_text(schema_stmt, 2));
    const char *sql =
        reinterpret_cast<const char *>(sqlite3_column_text(schema_stmt, 3));

    std::cout << "Type: " << (type ? type : "NULL")
              << ", Name: " << (name ? name : "NULL")
              << ", Table: " << (tbl_name ? tbl_name : "NULL")
              << ", SQL: " << (sql ? sql : "NULL") << std::endl;
  }

  // 스키마 명령문 해제
  sqlite3_finalize(schema_stmt);

  // 데이터베이스 연결 종료
  close_connection(db);
  return kNormal;
}

void SQLiteClient::clean_up_env() {
  std::string db_name = db_prefix_ + std::to_string(database_id_) + ".db";
  if (remove(db_name.c_str()) != 0) {
    std::cout << "Error deleting database file: " << db_name << std::endl;
  } else {
    std::cout << "[SQLite] Deleted database: " << db_name << std::endl;
  }
}

bool SQLiteClient::check_alive() {
  if (auto conn = create_connection(); conn) {
    close_connection(*conn);
    return true;
  }
  return false;
}

std::optional<sqlite3 *> SQLiteClient::create_connection() {
  sqlite3 *db = nullptr;
  std::cout << "[SQLite] Connecting to SQLite database: " << db_path_
            << std::endl;
  if (sqlite3_open(db_path_.c_str(), &db) != SQLITE_OK) {
    std::cout << "Failed to open SQLite database: " << sqlite3_errmsg(db)
              << std::endl;
    return std::nullopt;
  }
  return db;
}

void SQLiteClient::close_connection(sqlite3 *db) { sqlite3_close(db); }

}  // namespace client
