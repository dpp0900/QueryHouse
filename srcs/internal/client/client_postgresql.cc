#include "client_postgresql.h"

#include <unistd.h>

#include <cstring>
#include <deque>
#include <iostream>
#include <optional>
#include <string>
#include <string_view>
#include <vector>

#include "absl/strings/str_format.h"
#include "client.h"
#include "libpq-fe.h"

using namespace std;
namespace {
PGconn *create_connection(std::string_view db_name) {
  std::string conninfo =
      absl::StrFormat("hostaddr=%s port=%d dbname=%s connect_timeout=4",
                      "127.0.0.1", 5432, db_name);
  std::cout << "[PostgreSQL] Create connection: " << conninfo << std::endl;
  PGconn *result = PQconnectdb(conninfo.c_str());
  if (PQstatus(result) == CONNECTION_BAD) {
    fprintf(stderr, "Error1: %s\n", PQerrorMessage(result));
  }
  return result;
}

void reset_database(PGconn *conn) {
  auto res = PQexec(conn, "DROP SCHEMA public CASCADE; CREATE SCHEMA public;");
  PQclear(res);
}
};  // namespace

namespace client {

void PostgreSQLClient::initialize(YAML::Node config) {
  host_ = config["host"].as<std::string>();
  port_ = config["port"].as<std::string>();
  user_name_ = config["user_name"].as<std::string>();
  passwd_ = config["passwd"].as<std::string>();
  db_name_ = config["db_name"].as<std::string>();
}

void PostgreSQLClient::prepare_env() {
  PGconn *conn = create_connection(db_name_);
  reset_database(conn);
  PQfinish(conn);
}

ExecutionStatus PostgreSQLClient::execute(
    const char *query, size_t size,
    std::vector<std::vector<std::string>> &result) {
  FILE *fp = fopen("/tmp/postgresql_log.txt", "a");
  if (fp == NULL) {
    perror("fopen");
    return kServerCrash;
  }
  fprintf(fp, "log to tmp\n");
  fclose(fp);
  std::vector<std::string> queries = split_query(query, size);
  auto conn = create_connection(db_name_);

  if (PQstatus(conn) != CONNECTION_OK) {
    fprintf(stderr, "Error2: %s\n", PQerrorMessage(conn));
    PQfinish(conn);
    return kServerCrash;
  }

  for (const auto &q : queries) {
    std::cout << "[PostgreSQL] Execute query: " << q << std::endl;
    auto res = PQexec(conn, q.c_str());
    if (PQresultStatus(res) != PGRES_COMMAND_OK &&
        PQresultStatus(res) != PGRES_TUPLES_OK) {
      fprintf(stderr, "Error3: %s\n", PQerrorMessage(conn));
      PQclear(res);
      PQfinish(conn);
      return kExecuteError;
    }

    // Handle result set if any
    if (PQresultStatus(res) == PGRES_TUPLES_OK) {
      int num_fields = PQnfields(res);
      for (int i = 0; i < PQntuples(res); i++) {
        std::vector<std::string> row_result;
        for (int j = 0; j < num_fields; j++) {
          row_result.push_back(PQgetvalue(res, i, j));
        }
        result.push_back(row_result);
      }
    }
    PQclear(res);
  }

  // Retrieve schema information for all tables
  std::cout << "[PostgreSQL] Retrieving schema information for all tables..."
            << std::endl;

  std::string tables_query =
      "SELECT table_name FROM information_schema.tables WHERE table_schema = "
      "'public';";
  auto tables_res = PQexec(conn, tables_query.c_str());
  if (PQresultStatus(tables_res) != PGRES_TUPLES_OK) {
    std::cerr << "Error retrieving table list: " << PQerrorMessage(conn)
              << std::endl;
    PQclear(tables_res);
    PQfinish(conn);
    return kSyntaxError;
  }

  // Iterate over all tables and fetch their column information
  for (int i = 0; i < PQntuples(tables_res); i++) {
    std::string table_name = PQgetvalue(tables_res, i, 0);
    std::cout << "Table: " << table_name << std::endl;

    // Fetch column information for the current table
    std::string schema_query = absl::StrFormat(
        "SELECT column_name, data_type, is_nullable, column_default "
        "FROM information_schema.columns WHERE table_name = '%s';",
        table_name);

    auto schema_res = PQexec(conn, schema_query.c_str());
    if (PQresultStatus(schema_res) != PGRES_TUPLES_OK) {
      std::cerr << "Error retrieving schema for table " << table_name << ": "
                << PQerrorMessage(conn) << std::endl;
      PQclear(schema_res);
      continue;
    }

    for (int j = 0; j < PQntuples(schema_res); j++) {
      std::string column_name = PQgetvalue(schema_res, j, 0);
      std::string data_type = PQgetvalue(schema_res, j, 1);
      std::string is_nullable = PQgetvalue(schema_res, j, 2);
      std::string column_default = PQgetvalue(schema_res, j, 3);

      std::cout << "  Column: " << column_name << ", Type: " << data_type
                << ", Nullable: " << is_nullable
                << ", Default: " << column_default << std::endl;
    }

    PQclear(schema_res);
  }

  PQclear(tables_res);
  PQfinish(conn);
  return kNormal;
}

void PostgreSQLClient::clean_up_env() {}

bool PostgreSQLClient::check_alive() {
  std::string conninfo = absl::StrFormat(
      "hostaddr=%s port=%d connect_timeout=4", "127.0.0.1", 5432);
  std::cout << "[PostgreSQL] Check alive: " << conninfo << std::endl;
  PGPing res = PQping(conninfo.c_str());
  return res == PQPING_OK;
}
}  // namespace client
