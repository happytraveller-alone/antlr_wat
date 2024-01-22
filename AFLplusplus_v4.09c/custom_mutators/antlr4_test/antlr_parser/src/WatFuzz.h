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

#endif // _WATFUZZ_H_
