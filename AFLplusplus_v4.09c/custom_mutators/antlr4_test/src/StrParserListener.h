
// Generated from StrParser.g4 by ANTLR 4.13.1

#pragma once


#include "antlr4-runtime.h"
#include "StrParser.h"


/**
 * This interface defines an abstract listener for a parse tree produced by StrParser.
 */
class  StrParserListener : public antlr4::tree::ParseTreeListener {
public:

  virtual void enterLeft(StrParser::LeftContext *ctx) = 0;
  virtual void exitLeft(StrParser::LeftContext *ctx) = 0;

  virtual void enterMiddle(StrParser::MiddleContext *ctx) = 0;
  virtual void exitMiddle(StrParser::MiddleContext *ctx) = 0;

  virtual void enterRight(StrParser::RightContext *ctx) = 0;
  virtual void exitRight(StrParser::RightContext *ctx) = 0;

  virtual void enterModule(StrParser::ModuleContext *ctx) = 0;
  virtual void exitModule(StrParser::ModuleContext *ctx) = 0;


};

