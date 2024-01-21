
// Generated from StrParser.g4 by ANTLR 4.13.1

#pragma once


#include "antlr4-runtime.h"
#include "StrParser.h"



/**
 * This class defines an abstract visitor for a parse tree
 * produced by StrParser.
 */
class  StrParserVisitor : public antlr4::tree::AbstractParseTreeVisitor {
public:

  /**
   * Visit parse trees produced by StrParser.
   */
    virtual std::any visitLeft(StrParser::LeftContext *context) = 0;

    virtual std::any visitMiddle(StrParser::MiddleContext *context) = 0;

    virtual std::any visitRight(StrParser::RightContext *context) = 0;

    virtual std::any visitModule(StrParser::ModuleContext *context) = 0;


};

