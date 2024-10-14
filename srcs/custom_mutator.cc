#include <cassert>
#include <fstream>
#include <iostream>
#include <memory>
#include <stack>
#include <string>

#include "afl-fuzz.h"
#include "config_validate.h"
#include "db.h"
#include "protocol.h"
#include "yaml-cpp/yaml.h"

struct SquirrelMutator {
  SquirrelMutator(DataBase *db) : database(db) {}
  ~SquirrelMutator() { delete database; }
  DataBase *database;
  Round *current_input;
};
std::ofstream outfile;
std::ofstream errfile;

extern "C" {
void *afl_custom_init(afl_state_t *afl, unsigned int seed) {
  std::string basedir = getenv("HOME");
  basedir += "/QueryHouse";
  std::string config_file_path = basedir + "/data/config/config_sqlite.yml";
  std::string config_file(config_file_path);
  std::cerr << "Config file: " << config_file << std::endl;
  YAML::Node config = YAML::LoadFile(config_file);
  if (!utils::validate_db_config(config)) {
    std::cerr << "Invalid config!" << std::endl;
  }
  auto *mutator = create_database(config);
  return new SquirrelMutator(mutator);
}

void afl_custom_deinit(SquirrelMutator *data) { delete data; }

u8 afl_custom_queue_new_entry(SquirrelMutator *mutator,
                              const unsigned char *filename_new_queue,
                              const unsigned char *filename_orig_queue) {
  // Open the file in binary mode
  std::ifstream ifs((const char *)filename_new_queue, std::ios::binary);
  if (!ifs) {
    std::cerr << "Error: Could not open file " << filename_new_queue
              << std::endl;
    return false;  // Failed to open file
  }

  // Read the file contents into a string (binary safe)
  std::string content((std::istreambuf_iterator<char>(ifs)),
                      std::istreambuf_iterator<char>());

  // Check that the file size matches the size of the Round structure
  if (content.size() < sizeof(Round)) {
    errfile << "Error: File content size does not match Round structure size."
            << std::endl;
    return false;  // File size mismatch
  }

  // Allocate memory for a Round structure and copy the binary data from the
  // string
  Round *r = (Round *)malloc(MAX_ROUND_SIZE);
  memcpy(r, content.data(),
         MAX_ROUND_SIZE);  // Copy the binary data into the Round structure

  // Extract the buffer queries from the Round structure
  std::string buf_queries = r->buf_queries;
  FILE *fp = fopen("/tmp/afl_custom_queue_new_entry_log", "a");
  if (fp == NULL) {
    perror("fopen");
    return 1;
  }
  fprintf(fp, "%s\n", buf_queries.c_str());
  fclose(fp);
  // Pass the queries to the mutator's database for saving
  mutator->database->save_interesting_query(buf_queries);

  // Clean up (free the dynamically allocated Round)
  delete r;

  return false;  // You can adjust this return value as per your needs
}

unsigned int afl_custom_fuzz_count(SquirrelMutator *mutator,
                                   const unsigned char *buf, size_t buf_size) {
  FILE *fp = fopen("/tmp/afl_custom_fuzz_log", "a");
  if (fp == NULL) {
    perror("fopen");
    return 1;
  }
  fprintf(fp, "log to tmp\n");
  Round *r = (Round *)buf;
  fprintf(fp, "num_oracle: %d\n", r->num_oracle);
  fclose(fp);
  return mutator->database->mutate(*r);
}

size_t afl_custom_fuzz(SquirrelMutator *mutator, uint8_t *buf, size_t buf_size,
                       u8 **out_buf, uint8_t *add_buf,
                       size_t add_buf_size,  // add_buf can be NULL
                       size_t max_size) {
  DataBase *db = mutator->database;
  assert(db->has_mutated_test_cases());
  FILE *fp = fopen("/tmp/afl_custom_fuzz_log", "a");
  if (fp == NULL) {
    perror("fopen");
    return 1;
  }
  fprintf(fp, "log afl_custom_fuzz\n");
  fclose(fp);
  mutator->current_input = db->get_next_mutated_query();
  *out_buf = (u8 *)mutator->current_input;
  return MAX_ROUND_SIZE;
}
}
