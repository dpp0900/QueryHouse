#include "sqlite.h"

#include <string>
#include <vector>

#include "ast.h"
#include "define.h"
#include "mutator.h"
#include "transpile.h"
#include "utils.h"

std::ofstream mutateOutfile("/tmp/mutator.log");
SQLiteDB *create_sqlite() { return new SQLiteDB; }
SQLiteDB::SQLiteDB() { mutator_ = std::make_unique<Mutator>(); }

bool SQLiteDB::initialize(YAML::Node config) {
  const std::string init_lib_path = config["init_lib"].as<std::string>();
  std::cerr << "Init path" << init_lib_path << std::endl;
  const std::string pragma_path = config["pragma"].as<std::string>();
  std::cerr << "pragma path" << pragma_path << std::endl;
  std::vector<std::string> file_list =
      get_all_files_in_dir(init_lib_path.c_str());
  for (auto &f : file_list) {
    std::cerr << "init lib: " << f << std::endl;
    mutator_->init(f, "", pragma_path);
  }
  return true;
}

bool SQLiteDB::save_interesting_query(const std::string &query) {
  if (Program *program = parser(query)) {
    std::vector<IR *> ir_set;
    IR *ir = program->translate(ir_set);
    ir_set.clear();
    string strip_sql = mutator_->extract_struct(ir);
    // string strip_sql = ir->to_string();
    auto p_strip_sql = parser(strip_sql);
    if (p_strip_sql) {
      auto root_ir = p_strip_sql->translate(ir_set);
      p_strip_sql->deep_delete();
      // mutator_->add_ir_to_library(root_ir);
      mutator_->add_to_library(root_ir);
      deep_delete(root_ir);
    }
    return true;
  } else {
    std::cerr << "Error: SQL parser returned null for query: " << query
              << "?????" << std::endl;
    return false;
  }
}

std::vector<std::string> SQLiteDB::validate_all(
    const std::vector<IR *> &ir_set) {
  std::vector<std::string> validated_queries;

  for (IR *ir : ir_set) {
    std::string validated_ir = mutator_->validate(ir);
    if (validated_ir.empty()) {
      continue;
    }
    validated_queries.push_back(
        std::move(validated_ir));  // 벡터에 validated query 저장
  }

  return validated_queries;  // validated queries 반환
}

bool SQLiteDB::has_mutated_test_cases() {
  return !validated_test_cases_.empty();
}
size_t SQLiteDB::mutate(Round &r) {
  std::vector<IR *> ir_set, mutated_tree;
  Program *program_root = parser(r.buf_queries);
  if (program_root == nullptr) {
    return 0;
  }
  mutateOutfile << YELLOW << "[Parsing src_query]" << RESET << std::endl;
  // TODO: Remove this uncessary try.
  // Or we will have exception from the parser?
  try {
    program_root->translate(ir_set);
    mutateOutfile << YELLOW << "[Translate AST -> IR]" << RESET << std::endl;
  } catch (...) {
    for (auto ir : ir_set) {
      delete ir;
    }
    program_root->deep_delete();
  }
  program_root->deep_delete();

  mutated_tree = mutator_->mutate_all(ir_set);
  mutateOutfile << YELLOW << "[Mutate IR]" << RESET << std::endl;
  deep_delete(ir_set[ir_set.size() - 1]);

  std::vector<std::string> validated_queries = validate_all(mutated_tree);
  mutateOutfile << YELLOW << "[Validate mutated IR]" << RESET << std::endl;
  QueryQueue q;
  OraclePlan *plan;
  // 각 타겟에 맞는 쿼리로 변환하여 QueryQueue에 추가
  int i = 1;
  for (const auto &validated_query : validated_queries) {
    mutateOutfile << "\n\n"
                  << YELLOW << "[" << i++ << "th test case start!!!!!]" << RESET
                  << std::endl;
    q = transpile(validated_query, TARGET_ALL);  // 각 DBMS에 맞게 쿼리 변환
    // std::cerr << "q size: " << q.size() << std::endl;
    mutateOutfile << YELLOW << "[Query transpile to suit each DBMS]" << RESET
                  << std::endl;
    // std::cout << "  single_query: " << single_query << std::endl;

    mutateOutfile << MAGENTA << "src_query: " << validated_query << std::endl;
    mutateOutfile << "Contents of QueryQueue (q):\n";
    for (const auto &entry : q) {
      Target target = entry.first;
      const std::string &query = entry.second;
      mutateOutfile << "Target: " << target_to_string(target) << "\n";
      mutateOutfile << "\tQuery: " << query << "\n";
    }
    // OraclePlan 생성 및 테스트 케이스에 추가
    plan = oracle_planner(validated_query, &q);
    mutateOutfile << YELLOW << "[Create OraclePlan]" << RESET << std::endl;
    mutateOutfile << BRIGHT_BLUE << plan->to_string() << RESET << std::endl;

    postprocess(plan, decode(&r));
    // mutateOutfile << YELLOW << "[Postprocess]" << RESET << std::endl;
    // mutateOutfile << CYAN << plan->to_string() << RESET << std::endl;

    // mutateOutfile << YELLOW
    //               << "[Push only if the Plan is valid after validation]"
    //               << RESET << std::endl;

    if (plan && plan->is_valid()) {
      validated_test_cases_.push(encode(plan));  // Plan이 유효한 경우에만
      //   push mutateOutfile << GREEN
      //                 << "[ Original query before mutation:  " <<
      //                 r.buf_queries
      //                 << "]" << RESET << std::endl;
      mutateOutfile << GREEN << "[ mutated query:                   "
                    << validated_test_cases_.top()->buf_queries << "]" << RESET
                    << std::endl;
    }
  }

  if (validated_test_cases_.empty()) {
    mutateOutfile << RED << "[No validated test cases available.]" << RESET
                  << std::endl;
  }

  size_t validated_ir_size = validated_test_cases_.size();
  for (auto ir : mutated_tree) {
    deep_delete(ir);
  }

  // std::cerr << "validated ir size: " << validated_ir_size << std::endl;
  mutateOutfile << "[mutated queries num: " << validated_test_cases_.size()
                << "]" << std::endl;
  return validated_ir_size;
}

Round *SQLiteDB::get_next_mutated_query() {
  auto result = validated_test_cases_.top();
  validated_test_cases_.pop();
  return result;
}
