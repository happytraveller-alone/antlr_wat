
// Generated from WatLexer.g4 by ANTLR 4.13.1

#pragma once


#include "antlr4-runtime.h"




class  WatLexer : public antlr4::Lexer {
public:
  enum {
    LPAR = 1, RPAR = 2, NAT = 3, INT = 4, FLOAT = 5, STRING_ = 6, NUM_TYPE = 7, 
    PACK_TYPE = 8, VEC_TYPE = 9, VEC_SHAPE = 10, CONST = 11, VEC_CONST = 12, 
    ANY = 13, ANYREF = 14, NONE = 15, NULLREF = 16, EQ = 17, EQREF = 18, 
    I31 = 19, I31REF = 20, STRUCTREF = 21, ARRAYREF = 22, NOFUNC = 23, FUNCREF = 24, 
    MUT = 25, NULLFUNCREF = 26, EXTERN = 27, NOEXTERN = 28, EXTERNREF = 29, 
    NULLEXTERNREF = 30, REF = 31, NULL_ = 32, ARRAY = 33, STRUCT = 34, FIELD = 35, 
    SUB = 36, FINAL = 37, REC = 38, REF_NULL = 39, REF_FUNC = 40, REF_STRUCT = 41, 
    REF_ARRAY = 42, REF_HOST = 43, REF_EXTERN = 44, REF_IS_NULL = 45, REF_AS_NON_NULL = 46, 
    REF_TEST = 47, REF_CAST = 48, REF_EQ = 49, REF_I31 = 50, I31_GET = 51, 
    STRUCT_NEW = 52, STRUCT_GET = 53, STRUCT_SET = 54, ARRAY_NEW = 55, ARRAY_NEW_FIXED = 56, 
    ARRAY_NEW_ELEM = 57, ARRAY_NEW_DATA = 58, ARRAY_GET = 59, ARRAY_SET = 60, 
    ARRAY_LEN = 61, ARRAY_COPY = 62, ARRAY_FILL = 63, ARRAY_INIT_DATA = 64, 
    ARRAY_INIT_ELEM = 65, EXTERN_CONVERT = 66, NOP = 67, UNREACHABLE = 68, 
    DROP = 69, BLOCK = 70, LOOP = 71, END = 72, BR = 73, BR_IF = 74, BR_TABLE = 75, 
    RETURN = 76, IF = 77, THEN = 78, ELSE = 79, SELECT = 80, CALL = 81, 
    CALL_INDIRECT = 82, CALL_REF = 83, RETURN_CALL = 84, RETURN_CALL_REF = 85, 
    RETURN_CALL_INDIRECT = 86, BR_ON_NULL = 87, BR_ON_CAST = 88, LOCAL_GET = 89, 
    LOCAL_SET = 90, LOCAL_TEE = 91, GLOBAL_GET = 92, GLOBAL_SET = 93, TABLE_GET = 94, 
    TABLE_SET = 95, TABLE_SIZE = 96, TABLE_GROW = 97, TABLE_FILL = 98, TABLE_COPY = 99, 
    TABLE_INIT = 100, DATA_DROP = 101, ELEM_DROP = 102, LOAD = 103, STORE = 104, 
    OFFSET_EQ_NAT = 105, ALIGN_EQ_NAT = 106, UNARY = 107, BINARY = 108, 
    TEST = 109, COMPARE = 110, CONVERT = 111, VEC_LOAD = 112, VEC_STORE = 113, 
    VEC_LOAD_LANE = 114, VEC_STORE_LANE = 115, VEC_UNARY = 116, VEC_BINARY = 117, 
    VEC_TERNARY = 118, VEC_TEST = 119, VEC_BITMASK = 120, VEC_SHIFT = 121, 
    VEC_SHUFFLE = 122, VEC_SPLAT = 123, VEC_EXTRACT = 124, VEC_REPLACE = 125, 
    MEMORY_SIZE = 126, MEMORY_GROW = 127, MEMORY_FILL = 128, MEMORY_COPY = 129, 
    MEMORY_INIT = 130, TYPE = 131, FUNC = 132, START_ = 133, PARAM = 134, 
    RESULT = 135, LOCAL = 136, GLOBAL = 137, TABLE = 138, MEMORY = 139, 
    ELEM = 140, DATA = 141, OFFSET = 142, IMPORT = 143, EXPORT = 144, DECLARE = 145, 
    ITEM = 146, MODULE = 147, BIN = 148, QUOTE = 149, SCRIPT = 150, REGISTER = 151, 
    INVOKE = 152, GET = 153, ASSERT_MALFORMED = 154, ASSERT_INVALID = 155, 
    ASSERT_UNLINKABLE = 156, ASSERT_RETURN = 157, ASSERT_TRAP = 158, ASSERT_EXHAUSTION = 159, 
    INPUT = 160, OUTPUT = 161, NAN_ = 162, VAR = 163, SPACE = 164, COMMENT = 165
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

