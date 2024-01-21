#ifndef _WATFUZZ_H_
#define _WATFUZZ_H_

#include <algorithm>
#include <array>
#include <chrono>
#include <cstdio>
#include <cstdlib>
#include <cstring>
#include <exception>
#include <filesystem>
#include <fstream>
#include <functional>
#include <iostream>
#include <map>
#include <random>
#include <sstream>
#include <thread>
#include <unordered_map>
#include <utility>

#include "StrLexer.h"
#include "StrParser.h"
#include "StrParserBaseVisitor.h"
#include "StrParserVisitor.h"
#include "TokenStreamRewriter.h"
#include "afl-fuzz.h"
#include "antlr4-runtime.h"

using namespace antlr4;
using namespace std;

#define DATA_SIZE (100)

class CustomStrVisitor : public StrParserVisitor {
private:
  /* data */
  std::string_view file_path;
  std::ifstream input_file;
  ANTLRInputStream stream;
  StrLexer lexer;
  CommonTokenStream tokens;
  StrParser parser;
  TokenStreamRewriter rewriter;
  // tree::ParseTree *tree;
  StrParser::ModuleContext *module;

public:
  CustomStrVisitor(std::string_view file_path)
      : file_path(file_path), input_file(file_path.data()), stream(input_file),
        lexer(&stream), tokens(&lexer), parser(&tokens), rewriter(&tokens) {
    input_file.open(file_path.data());
    if (!input_file.is_open()) {
      throw std::runtime_error("failed to open file");
    }
    // tree = parser.module();
    module = parser.module();
  }

  // tree::ParseTree *get_tree() { return tree; }
  StrParser::ModuleContext *get_module() { return module; }
  StrParser *get_parser() { return &parser; }
  TokenStreamRewriter *get_rewriter() { return &rewriter; }
  /**
   * Visit parse trees produced by StrParser.
   */
  virtual antlrcpp::Any visitLeft(StrParser::LeftContext *ctx) {
    int random_num = rand() % 90000 + 10000;
    std::string new_str = "(" + std::to_string(random_num) + ")";
    rewriter.replace(ctx->start, ctx->stop, new_str);
    return visitChildren(ctx);
  }

  virtual antlrcpp::Any visitMiddle(StrParser::MiddleContext *ctx) {
    return visitChildren(ctx);
  }

  virtual antlrcpp::Any visitRight(StrParser::RightContext *ctx) {
    std::string new_str = "";
    new_str += "{";
    for (int i = 0; i < 5; i++) {
      new_str += 'a' + rand() % 26;
    }
    new_str += "}";
    rewriter.replace(ctx->start, ctx->stop, new_str);
    return visitChildren(ctx);
  }

  virtual antlrcpp::Any visitModule(StrParser::ModuleContext *ctx) {
    return visitChildren(ctx);
  }
};

typedef struct my_mutator {

  afl_state_t *afl;

  // any additional data here!
  //   size_t trim_size_current;
  //   int trimmming_steps;
  //   int cur_step;

  u8 *mutated_out;
  u8 *post_process_buf;
  // u8 *trim_buf;

} my_mutator_t;

/**
 * Initialize this custom mutator
 *
 * @param[in] afl a pointer to the internal state object. Can be ignored for
 * now.
 * @param[in] seed A seed for this mutator - the same seed should always mutate
 * in the same way.
 * @return Pointer to the data object this custom mutator instance should use.
 *         There may be multiple instances of this mutator in one afl-fuzz run!
 *         Return NULL on error.
 */
my_mutator_t *afl_custom_init(afl_state_t *afl, unsigned int seed) {

  srand(seed); // needed also by surgical_havoc_mutate()

  my_mutator_t *data =
      static_cast<my_mutator_t *>(calloc(1, sizeof(my_mutator_t)));
  if (!data) {
    perror("afl_custom_init alloc");
    return NULL;
  }

  if ((data->mutated_out = (u8 *)malloc(MAX_FILE)) == NULL) {
    perror("afl_custom_init malloc");
    return NULL;
  }

  if ((data->post_process_buf = (u8 *)malloc(MAX_FILE)) == NULL) {
    perror("afl_custom_init malloc");
    return NULL;
  }

  data->afl = afl;

  return data;
}

/**
 * Perform custom mutations on a given input
 *
 * (Optional for now. Required in the future)
 *
 * @param[in] data pointer returned in afl_custom_init for this fuzz case
 * @param[in] buf Pointer to input data to be mutated
 * @param[in] buf_size Size of input data
 * @param[out] out_buf the buffer we will work on. we can reuse *buf. NULL on
 * error.
 * @param[in] add_buf Buffer containing the additional test case
 * @param[in] add_buf_size Size of the additional test case
 * @param[in] max_size Maximum size of the mutated output. The mutation must not
 *     produce data larger than max_size.
 * @return Size of the mutated output.
 */
size_t afl_custom_fuzz(my_mutator_t *data, uint8_t *buf, size_t buf_size,
                       u8 **out_buf, uint8_t *add_buf,
                       size_t add_buf_size, // add_buf can be NULL
                       size_t max_size) {

  // Make sure that the packet size does not exceed the maximum size expected by
  // the fuzzer
  size_t mutated_size = DATA_SIZE <= max_size ? DATA_SIZE : max_size;

  memcpy(data->mutated_out, buf, buf_size);

  // Perform the mutation
  ANTLRInputStream stream((char *)data->mutated_out);
  StrLexer lexer(&stream);
  CommonTokenStream tokens(&lexer);
  StrParser parser(&tokens);
  StrParser::ModuleContext *tree;
  // tree = parser.module();

  if (mutated_size > max_size) {
    mutated_size = max_size;
  }

  *out_buf = data->mutated_out;
  return mutated_size;
}

/**
 * A post-processing function to use right before AFL writes the test case to
 * disk in order to execute the target.
 *
 * (Optional) If this functionality is not needed, simply don't define this
 * function.
 *
 * @param[in] data pointer returned in afl_custom_init for this fuzz case
 * @param[in] buf Buffer containing the test case to be executed
 * @param[in] buf_size Size of the test case
 * @param[out] out_buf Pointer to the buffer containing the test case after
 *     processing. External library should allocate memory for out_buf.
 *     The buf pointer may be reused (up to the given buf_size);
 * @return Size of the output buffer after processing or the needed amount.
 *     A return of 0 indicates an error.
 */
size_t afl_custom_post_process(my_mutator_t *data, uint8_t *buf,
                               size_t buf_size, uint8_t **out_buf) {

  if (buf_size + 5 > MAX_FILE) {
    buf_size = MAX_FILE - 5;
  }

  memcpy(data->post_process_buf + 5, buf, buf_size);
  data->post_process_buf[0] = 'A';
  data->post_process_buf[1] = 'F';
  data->post_process_buf[2] = 'L';
  data->post_process_buf[3] = '+';
  data->post_process_buf[4] = '+';

  *out_buf = data->post_process_buf;

  return buf_size + 5;
}
#endif // _WATFUZZ_H_
