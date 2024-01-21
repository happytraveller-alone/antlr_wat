
// Generated from StrParser.g4 by ANTLR 4.13.1

#pragma once


#include "antlr4-runtime.h"
#include "StrParserVisitor.h"


/**
 * This class provides an empty implementation of StrParserVisitor, which can be
 * extended to create a visitor which only needs to handle a subset of the available methods.
 */
class  StrParserBaseVisitor : public StrParserVisitor {
public:

  virtual std::any visitLeft(StrParser::LeftContext *ctx) override {
    return visitChildren(ctx);
  }

  virtual std::any visitMiddle(StrParser::MiddleContext *ctx) override {
    return visitChildren(ctx);
  }

  virtual std::any visitRight(StrParser::RightContext *ctx) override {
    return visitChildren(ctx);
  }

  virtual std::any visitModule(StrParser::ModuleContext *ctx) override {
    return visitChildren(ctx);
  }


};

