#include "client.h"

#include <cassert>
#include <iostream>
#include <string>

#ifdef __SQUIRREL_MYSQL__
#include "client_mysql.h"
#endif

#ifdef __SQUIRREL_POSTGRESQL__
#include "client_postgresql.h"
#endif

#ifdef __SQUIRREL_SQLITE__
#include "client_sqlite.h"
#endif

#ifdef __SQUIRREL_ORACLE__
#include "client_oracle.h"  // Oracle 클라이언트 헤더 파일 추가
#endif

namespace client {

DBClient *create_client(const std::string &db_name, const YAML::Node &config) {
  DBClient *result = nullptr;
  std::cerr << "Create client: " << db_name << std::endl;

  if (db_name == "mysql") {
#ifdef __SQUIRREL_MYSQL__
    result = new MySQLClient;
#endif
  } else if (db_name == "postgresql") {
#ifdef __SQUIRREL_POSTGRESQL__
    result = new PostgreSQLClient;
#endif
  } else if (db_name == "sqlite") {
#ifdef __SQUIRREL_SQLITE__
    std::cerr << "Create SQLite client" << std::endl;
    result = new SQLiteClient;
#endif
  } else if (db_name == "oracle") {  // Oracle 클라이언트 추가
#ifdef __SQUIRREL_ORACLE__
    std::cerr << "Create Oracle client" << std::endl;
    result = new OracleClient;
#endif
  }

  assert(result &&
         "It is not supported!");  // 지원되지 않는 클라이언트에 대한 오류 처리
  result->initialize(config);  // 초기화
  return result;
}

};  // namespace client
