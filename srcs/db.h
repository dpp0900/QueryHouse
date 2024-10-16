#ifndef __DB_H__
#define __DB_H__
#include "protocol.h"
#include "yaml-cpp/yaml.h"

class DataBase {
 public:
  // Set up the database.
  virtual bool initialize(YAML::Node config) = 0;
  // Mutate the query and return the number of new queries.
  virtual size_t mutate(Round &r) = 0;
  // Return an new query to test. The `buffer` should be unmanaged,
  virtual Round *get_next_mutated_query() = 0;
  virtual bool has_mutated_test_cases() = 0;
  // Save the interesting query to the dictionary.
  virtual bool save_interesting_query(const std::string &) = 0;
  // Clean up the enviroment, e.g., drop all the databases.
  virtual bool clean_up() { return true; }
  virtual ~DataBase() {};
};

DataBase *create_database(YAML::Node config);
#endif  // __DB_H__
