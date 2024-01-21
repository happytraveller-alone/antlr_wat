#pragma once

#include "StrParserVisitor.h"
#include "antlr4-runtime.h"
#include <iostream>
#include <vector>

using namespace std;

class StrOverrideVisitor : public StrParserVisitor {
public:
private:
  /**
   * Visit parse trees produced by StrParser.
   */
  virtual antlrcpp::Any visitLeft(StrParser::LeftContext *ctx) override {
    fprintf(stdout, "\nvisitLeft:%s \n", ctx->getText().c_str());
    // if the left is a string, we can mutate it
    for (auto child : ctx->children) {
      fprintf(stdout, "child:%s\n", child->getText().c_str());
    }
    std::vector token_vector = ctx->getTokens(StrParser::DIGIT);
    for (auto token : token_vector) {
      fprintf(stdout, "DIGIT token:%s\n", token->getText().c_str());
    }
    return visitChildren(ctx);
  }

  virtual antlrcpp::Any visitMiddle(StrParser::MiddleContext *ctx) override {
    return visitChildren(ctx);
  }

  virtual antlrcpp::Any visitRight(StrParser::RightContext *ctx) override {
    fprintf(stdout, "\nvisitRight:%s \n", ctx->getText().c_str());
    return visitChildren(ctx);
  }

  virtual antlrcpp::Any visitModule(StrParser::ModuleContext *ctx) override {
    return visitChildren(ctx);
  }
};