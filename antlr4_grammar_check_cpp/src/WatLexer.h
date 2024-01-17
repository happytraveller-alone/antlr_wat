
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
    MUT = 25, SHARED = 26, NULLFUNCREF = 27, EXTERN = 28, NOEXTERN = 29, 
    EXTERNREF = 30, NULLEXTERNREF = 31, REF = 32, NULL_ = 33, ARRAY = 34, 
    STRUCT = 35, FIELD = 36, SUB = 37, FINAL = 38, REC = 39, REF_NULL = 40, 
    REF_FUNC = 41, REF_STRUCT = 42, REF_ARRAY = 43, REF_HOST = 44, REF_EXTERN = 45, 
    REF_IS_NULL = 46, REF_AS_NON_NULL = 47, REF_TEST = 48, REF_CAST = 49, 
    REF_EQ = 50, REF_I31 = 51, I31_GET = 52, STRUCT_NEW = 53, STRUCT_GET = 54, 
    STRUCT_SET = 55, ARRAY_NEW = 56, ARRAY_NEW_FIXED = 57, ARRAY_NEW_ELEM = 58, 
    ARRAY_NEW_DATA = 59, ARRAY_GET = 60, ARRAY_SET = 61, ARRAY_LEN = 62, 
    ARRAY_COPY = 63, ARRAY_FILL = 64, ARRAY_INIT_DATA = 65, ARRAY_INIT_ELEM = 66, 
    EXTERN_CONVERT = 67, MEMORY_ATOMIC_NOTIFY = 68, MEMORY_ATOMIC_WAIT = 69, 
    ATOMIC_FENCE = 70, ATOMIC_LOAD = 71, ATOMIC_STORE = 72, ATOMIC_RMW = 73, 
    ATOMIC_RMW_CMPXCHG = 74, NOP = 75, UNREACHABLE = 76, DROP = 77, BLOCK = 78, 
    LOOP = 79, END = 80, BR = 81, BR_IF = 82, BR_TABLE = 83, RETURN = 84, 
    IF = 85, THEN = 86, ELSE = 87, SELECT = 88, CALL = 89, CALL_INDIRECT = 90, 
    CALL_REF = 91, RETURN_CALL = 92, RETURN_CALL_REF = 93, RETURN_CALL_INDIRECT = 94, 
    BR_ON_NULL = 95, BR_ON_CAST = 96, LOCAL_GET = 97, LOCAL_SET = 98, LOCAL_TEE = 99, 
    GLOBAL_GET = 100, GLOBAL_SET = 101, TABLE_GET = 102, TABLE_SET = 103, 
    TABLE_SIZE = 104, TABLE_GROW = 105, TABLE_FILL = 106, TABLE_COPY = 107, 
    TABLE_INIT = 108, DATA_DROP = 109, ELEM_DROP = 110, LOAD = 111, STORE = 112, 
    OFFSET_EQ_NAT = 113, ALIGN_EQ_NAT = 114, UNARY = 115, BINARY = 116, 
    TEST = 117, COMPARE = 118, CONVERT = 119, VEC_LOAD = 120, VEC_STORE = 121, 
    VEC_LOAD_LANE = 122, VEC_STORE_LANE = 123, VEC_UNARY = 124, VEC_BINARY = 125, 
    VEC_TERNARY = 126, VEC_TEST = 127, VEC_BITMASK = 128, VEC_SHIFT = 129, 
    VEC_SHUFFLE = 130, VEC_SPLAT = 131, VEC_EXTRACT = 132, VEC_REPLACE = 133, 
    MEMORY_SIZE = 134, MEMORY_GROW = 135, MEMORY_FILL = 136, MEMORY_COPY = 137, 
    MEMORY_INIT = 138, TYPE = 139, FUNC = 140, START_ = 141, PARAM = 142, 
    RESULT = 143, LOCAL = 144, GLOBAL = 145, TABLE = 146, MEMORY = 147, 
    ELEM = 148, DATA = 149, OFFSET = 150, IMPORT = 151, EXPORT = 152, DECLARE = 153, 
    ITEM = 154, MODULE = 155, BIN = 156, QUOTE = 157, EITHER = 158, THREAD = 159, 
    WAIT = 160, SCRIPT = 161, REGISTER = 162, INVOKE = 163, GET = 164, ASSERT_MALFORMED = 165, 
    ASSERT_INVALID = 166, ASSERT_UNLINKABLE = 167, ASSERT_RETURN = 168, 
    ASSERT_TRAP = 169, ASSERT_EXHAUSTION = 170, INPUT = 171, OUTPUT = 172, 
    NAN_ = 173, VAR = 174, SPACE = 175, COMMENT = 176
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

