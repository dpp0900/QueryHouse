#ifndef __SQLITE_H_H_H__
#define __SQLITE_H_H_H__
#include <memory>
#include <stack>
#include <string>

#include "db.h"
#include "protocol.h"

class Mutator;
class IR;
class SQLiteDB : public DataBase {
 public:
  // Set up the database.
  SQLiteDB();
  virtual bool initialize(YAML::Node config);
  virtual size_t mutate(Round &r);
  virtual bool save_interesting_query(const std::string &);
  // Return an new query to test. The `buffer` should be unmanaged,
  virtual Round *get_next_mutated_query();
  virtual bool has_mutated_test_cases();
  // Clean up the enviroment, e.g., drop all the databases.
  virtual bool clean_up() { return true; }

 private:
  std::vector<std::string> validate_all(const std::vector<IR *> &ir_set);
  std::unique_ptr<Mutator> mutator_;
  std::stack<Round *> validated_test_cases_;
};

SQLiteDB *create_sqlite();
#endif
