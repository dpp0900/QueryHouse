cmake_minimum_required(VERSION 3.14)
project(Squirrel)

set(BUILD_SHARED_LIBS ON)

set(CMAKE_CXX_STANDARD 17)

set(CMAKE_CXX_FLAGS_DEBUG "${CMAKE_CXX_FLAGS} -g -O2 -fsanitize=address")
set(CMAKE_CXX_FLAGS_RELEASE "${CMAKE_CXX_FLAGS} -O3")
set(LINK_FLAGS "${LINK_FLAGS} -fsanitize=address")
find_package(PkgConfig)

option(ALL "Build all types of database" ON)
option(SQLITE "Build sqlite" OFF)
option(MYSQL "Build mysql" OFF)
option(POSTGRESQL "Build postgresql" OFF)


set(SQLITE ON)
set(MYSQL ON)
set(POSTGRESQL ON)
set(ORACLE ON)

include(FetchContent)
FetchContent_Declare(
    pybind11
    GIT_REPOSITORY https://github.com/pybind/pybind11.git
    GIT_TAG        v2.10.1  # 설치할 pybind11 버전 명시
)
FetchContent_MakeAvailable(pybind11)

if(MYSQL)
  pkg_check_modules(MySQL REQUIRED mysqlclient>=5.7)
  add_library(mysql_client OBJECT srcs/internal/client/client_mysql.cc)
  target_include_directories(mysql_client PUBLIC ${MySQL_INCLUDE_DIRS}
                                                 srcs/internal/client)
  target_link_libraries(mysql_client PUBLIC ${MySQL_LIBRARIES}
                                            ${YAML_CPP_LIBRARIES})
  target_compile_options(mysql_client PRIVATE -fPIC)
  list(APPEND LINK_CLIENT mysql_client)
  list(APPEND CLIENT_DEFINITION __SQUIRREL_MYSQL__)
endif()

if(POSTGRESQL)
  find_package(PostgreSQL REQUIRED)
  add_library(postgresql_client OBJECT
              srcs/internal/client/client_postgresql.cc)
  target_include_directories(postgresql_client PUBLIC ${PostgreSQL_INCLUDE_DIRS}
                                                      srcs/internal/client)
  target_link_libraries(
    postgresql_client PUBLIC ${PostgreSQL_LIBRARIES} ${YAML_CPP_LIBRARIES}
                             absl::strings absl::str_format)
  target_compile_options(postgresql_client PRIVATE -fPIC)
  list(APPEND LINK_CLIENT postgresql_client)
  list(APPEND CLIENT_DEFINITION __SQUIRREL_POSTGRESQL__)
endif()

if(SQLITE)
  list(APPEND DBMS sqlite)
  find_package(SQLite3 REQUIRED)
  add_library(sqlite_client OBJECT srcs/internal/client/client_sqlite.cc)
  target_include_directories(sqlite_client PUBLIC ${SQLite3_INCLUDE_DIRS} srcs/internal/client)
  target_link_libraries(sqlite_client PUBLIC ${SQLite3_LIBRARIES} ${YAML_CPP_LIBRARIES} absl::strings absl::str_format)
  target_compile_options(sqlite_client PRIVATE -fPIC)
  list(APPEND LINK_CLIENT sqlite_client)
  list(APPEND CLIENT_DEFINITION __SQUIRREL_SQLITE__)
endif()

# Add Oracle code
if(ORACLE)
  set(Oracle_INCLUDE_DIRS "/opt/oracle/product/23ai/dbhomeFree/lib/SDK/instantclient_23_5/sdk/include")
  set(Oracle_LIBRARY_DIRS "/opt/oracle/product/23ai/dbhomeFree/lib/OCI/instantclient_23_5")
  # 라이브러리 파일 추가 (libclntsh.so 파일을 찾을 수 있도록)
  find_library(Oracle_LIBRARIES NAMES clntsh PATHS ${Oracle_LIBRARY_DIRS} NO_DEFAULT_PATH)

  if(Oracle_LIBRARIES)
    message(STATUS "Found Oracle Client Library: ${Oracle_LIBRARIES}")
  else()
    message(FATAL_ERROR "Oracle Client Library (libclntsh.so) not found")
  endif()

  # Oracle Client 관련 설정
  add_library(oracle_client OBJECT srcs/internal/client/client_oracle.cc)
  target_include_directories(oracle_client PUBLIC ${Oracle_INCLUDE_DIRS} srcs/internal/client)
  target_link_directories(oracle_client PUBLIC ${Oracle_LIBRARY_DIRS}) # 라이브러리 경로 추가
  target_link_libraries(oracle_client PUBLIC ${Oracle_LIBRARIES} ${YAML_CPP_LIBRARIES})
  target_compile_options(oracle_client PRIVATE -fPIC)

  # Oracle 클라이언트를 링크 클라이언트 및 정의 목록에 추가
  list(APPEND LINK_CLIENT oracle_client)
  list(APPEND CLIENT_DEFINITION __SQUIRREL_ORACLE__)
endif()


include(FetchContent)
find_package(yaml-cpp REQUIRED)
# FetchContent_Declare( ${YAML_CPP_LIBRARIES} URL
# https://github.com/jbeder/${YAML_CPP_LIBRARIES}/archive/refs/tags/${YAML_CPP_LIBRARIES}-0.7.0.zip)
# FetchContent_MakeAvailable(${YAML_CPP_LIBRARIES})
include_directories(${YAML_INCLUDE_DIRS})

# set_target_properties(${YAML_CPP_LIBRARIES} PROPERTIES COMPILE_FLAGS "-w")

set(ABSL_PROPAGATE_CXX_STD ON)
set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -w")
add_subdirectory(third_party/abseil-cpp)
string(REPLACE " -w" "" CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS}")

set(AFLPP_DIR ${CMAKE_CURRENT_SOURCE_DIR}/AFLplusplus/include)

include_directories(${AFLPP_DIR})

foreach(dbms IN LISTS DBMS)
  add_library(
    ${dbms}_impl OBJECT
    srcs/internal/${dbms}/${dbms}.cc
    srcs/internal/${dbms}/${dbms}.h
    srcs/internal/${dbms}/srcs/ast.cpp
    srcs/internal/${dbms}/srcs/mutator.cpp
    srcs/internal/${dbms}/srcs/utils.cpp
    srcs/internal/${dbms}/parser/bison_parser.cpp
    srcs/internal/${dbms}/parser/flex_lexer.cpp
    srcs/protocol.cpp
    srcs/protocol.h
    srcs/transpile.cpp
    srcs/transpile.h)
  target_include_directories(${dbms}_impl PRIVATE srcs/internal/${dbms}/include
                                                  srcs)
  target_compile_options(${dbms}_impl PRIVATE -fPIC)
  target_link_libraries(${dbms}_impl ${YAML_CPP_LIBRARIES} absl::strings
                        absl::str_format pybind11::embed)

  string(TOUPPER ${dbms} UPPER_CASE_DBMS)
  add_library(${dbms}_mutator SHARED srcs/custom_mutator.cc srcs/db_factory.cc)
  target_link_libraries(${dbms}_mutator ${dbms}_impl config_validator)
  target_include_directories(${dbms}_mutator PRIVATE srcs/internal/${dbms} srcs)
  # target_compile_options(${dbms}_mutator PRIVATE -fPIC)
  target_compile_definitions(${dbms}_mutator
                             PRIVATE __SQUIRREL_${UPPER_CASE_DBMS}__)
endforeach()
if(MYSQL OR POSTGRESQL OR SQLITE)
  include_directories(srcs)
  include_directories(srcs/internal/client)
  add_library(libs OBJECT srcs/protocol.cpp
                          srcs/internal/sqlite/srcs/ast.cpp
                          srcs/internal/sqlite/srcs/mutator.cpp
                          srcs/internal/sqlite/srcs/utils.cpp
                          srcs/internal/sqlite/parser/bison_parser.cpp
                          srcs/internal/sqlite/parser/flex_lexer.cpp)
  target_include_directories(libs PUBLIC srcs/internal/client
                                             srcs/internal/sqlite/include)
  add_executable(db_driver srcs/db_driver.cc)
  target_include_directories(db_driver PRIVATE srcs/internal/sqlite/include)
  target_include_directories(db_driver PRIVATE srcs/internal/sqlite/srcs)
  target_link_libraries(db_driver ${YAML_CPP_LIBRARIES} all_client
                        absl::strings absl::str_format pybind11::embed libs)

  add_executable(test_client srcs/internal/client/test_client.cc)
  target_link_libraries(test_client all_client ${YAML_CPP_LIBRARIES})
  target_include_directories(test_client PUBLIC srcs/internal/client)

  add_library(all_client SHARED srcs/internal/client/client.cc)
  target_include_directories(all_client PUBLIC srcs/internal/client)
  target_link_libraries(all_client PUBLIC ${LINK_CLIENT})
  target_compile_definitions(all_client PRIVATE ${CLIENT_DEFINITION})
endif()

add_library(config_validator OBJECT srcs/utils/config_validate.cc)
target_link_libraries(config_validator PRIVATE ${YAML_CPP_LIBRARIES}
                                               absl::strings absl::str_format)
target_include_directories(config_validator PUBLIC srcs/utils)
target_compile_options(config_validator PRIVATE -fPIC)

include(lint.cmake)
add_subdirectory(tests)
