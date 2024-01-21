
// Generated from StrParser.g4 by ANTLR 4.13.1

#pragma once


#include "antlr4-runtime.h"
#include "StrParserListener.h"


/**
 * This class provides an empty implementation of StrParserListener,
 * which can be extended to create a listener which only needs to handle a subset
 * of the available methods.
 */
class  StrParserBaseListener : public StrParserListener {
public:

  virtual void enterLeft(StrParser::LeftContext * /*ctx*/) override { }
  virtual void exitLeft(StrParser::LeftContext * /*ctx*/) override { }

  virtual void enterMiddle(StrParser::MiddleContext * /*ctx*/) override { }
  virtual void exitMiddle(StrParser::MiddleContext * /*ctx*/) override { }

  virtual void enterRight(StrParser::RightContext * /*ctx*/) override { }
  virtual void exitRight(StrParser::RightContext * /*ctx*/) override { }

  virtual void enterModule(StrParser::ModuleContext * /*ctx*/) override { }
  virtual void exitModule(StrParser::ModuleContext * /*ctx*/) override { }


  virtual void enterEveryRule(antlr4::ParserRuleContext * /*ctx*/) override { }
  virtual void exitEveryRule(antlr4::ParserRuleContext * /*ctx*/) override { }
  virtual void visitTerminal(antlr4::tree::TerminalNode * /*node*/) override { }
  virtual void visitErrorNode(antlr4::tree::ErrorNode * /*node*/) override { }

};

