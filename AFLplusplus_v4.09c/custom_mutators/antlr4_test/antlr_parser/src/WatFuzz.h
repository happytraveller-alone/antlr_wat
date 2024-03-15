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
#include "alloc-inl.h"
#include "antlr4-runtime.h"

using namespace antlr4;
using namespace std;

#define DATA_SIZE (10000)

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
  CustomStrVisitor(u8* buf, size_t buf_size)
      : stream(reinterpret_cast<const char*>(buf), buf_size), lexer(&stream), tokens(&lexer), parser(&tokens), rewriter(&tokens) {
    // fprintf(stdout, "buf: %s\n", buf);
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
    std::string random_str = "(";
    std::random_device rd;
    std::mt19937 gen(rd());
    std::uniform_int_distribution<> random_num(0, 10);
    int random_length = random_num(gen);
    for(int i = 0; i < random_length; i++) {
      random_str += std::to_string(random_num(gen));
    }
    random_str += ")";
    // std::cout << "visiting left:" <<random_str << std::endl;
   
    rewriter.replace(ctx->start, ctx->stop, random_str);
    return visitChildren(ctx);
    // for(int i = ctx->start->getTokenIndex(); i <= ctx->stop->getTokenIndex(); i++) {
    //   // rewriter.replace(i, new_str);
    //   if(tokens.get(i)->getType() == StrLexer::DIGIT) {
    //     rewriter.replace(i, to_string(rand() % 10));
    //   }
    // }
  }

  virtual antlrcpp::Any visitMiddle(StrParser::MiddleContext *ctx) {
    return visitChildren(ctx);
  }

  virtual antlrcpp::Any visitRight(StrParser::RightContext *ctx) {
    std::random_device rd;
    std::mt19937 gen(rd());
    std::uniform_int_distribution<> dis(0, 25);
    std::string alphabet = "abcdefghijklmnopqrstuvwxyz";
    // random generate number within 0-9
    std::uniform_int_distribution<> random_dis(0, 10);
    int random_num = random_dis(gen);
    std::string random_str = "{";
    for(int i = 0; i < random_num; i++) {
      random_str += alphabet[dis(gen)];
    }
    
    random_str += "}";
    // std::cout << "visiting right:" << random_str << std::endl;
    rewriter.replace(ctx->start, ctx->stop, random_str);
    
    return visitChildren(ctx);
    // for(int i = ctx->start->getTokenIndex(); i <= ctx->stop->getTokenIndex(); i++) {
    //   if(tokens.get(i)->getType() == StrLexer::LETTER) {
    //     rewriter.replace(i,std::string(1,alphabet[dis(gen)]));
    //   }
    // }
  }

  virtual antlrcpp::Any visitModule(StrParser::ModuleContext *ctx) {
    return visitChildren(ctx);
  }
};

#endif // _WATFUZZ_H_
