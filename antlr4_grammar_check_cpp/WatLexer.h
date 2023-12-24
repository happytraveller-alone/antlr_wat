
// Generated from WatLexer.g4 by ANTLR 4.13.1

#pragma once


#include "antlr4-runtime.h"




class  WatLexer : public antlr4::Lexer {
public:
  enum {
    LPAR = 1, RPAR = 2, NAT = 3, INT = 4, FLOAT = 5, STRING_ = 6, VALUE_TYPE = 7, 
    CONST = 8, FUNCREF = 9, MUT = 10, NOP = 11, UNREACHABLE = 12, DROP = 13, 
    BLOCK = 14, LOOP = 15, END = 16, BR = 17, BR_IF = 18, BR_TABLE = 19, 
    RETURN = 20, IF = 21, THEN = 22, ELSE = 23, SELECT = 24, CALL = 25, 
    CALL_INDIRECT = 26, LOCAL_GET = 27, LOCAL_SET = 28, LOCAL_TEE = 29, 
    GLOBAL_GET = 30, GLOBAL_SET = 31, LOAD = 32, STORE = 33, OFFSET_EQ_NAT = 34, 
    ALIGN_EQ_NAT = 35, UNARY = 36, BINARY = 37, TEST = 38, COMPARE = 39, 
    CONVERT = 40, MEMORY_SIZE = 41, MEMORY_GROW = 42, TYPE = 43, FUNC = 44, 
    START_ = 45, PARAM = 46, RESULT = 47, LOCAL = 48, GLOBAL = 49, TABLE = 50, 
    MEMORY = 51, ELEM = 52, DATA = 53, OFFSET = 54, IMPORT = 55, EXPORT = 56, 
    MODULE = 57, BIN = 58, QUOTE = 59, SCRIPT = 60, REGISTER = 61, INVOKE = 62, 
    GET = 63, ASSERT_MALFORMED = 64, ASSERT_INVALID = 65, ASSERT_UNLINKABLE = 66, 
    ASSERT_RETURN = 67, ASSERT_RETURN_CANONICAL_NAN = 68, ASSERT_RETURN_ARITHMETIC_NAN = 69, 
    ASSERT_TRAP = 70, ASSERT_EXHAUSTION = 71, INPUT = 72, OUTPUT = 73, VAR = 74, 
    SPACE = 75, COMMENT = 76
  };

  explicit WatLexer(antlr4::CharStream *input);

  ~WatLexer() override;


  std::string getGrammarFileName() const override;

  const std::vector<std::string>& getRuleNames() const override;

  const std::vector<std::string>& getChannelNames() const override;

  const std::vector<std::string>& getModeNames() const override;

  const antlr4::dfa::Vocabulary& getVocabulary() const override;

  antlr4::atn::SerializedATNView getSerializedATN() const override;

  const antlr4::atn::ATN& getATN() const override;

  // By default the static state used to implement the lexer is lazily initialized during the first
  // call to the constructor. You can call this function if you wish to initialize the static state
  // ahead of time.
  static void initialize();

private:

  // Individual action functions triggered by action() above.

  // Individual semantic predicate functions triggered by sempred() above.

};

