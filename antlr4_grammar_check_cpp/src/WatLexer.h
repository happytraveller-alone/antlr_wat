
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
    EXTERNREF = 30, NULLEXTERNREF = 31, REF = 32, NULL_ = 33, EXN = 34, 
    EXNREF = 35, ARRAY = 36, STRUCT = 37, FIELD = 38, SUB = 39, FINAL = 40, 
    REC = 41, REF_NULL = 42, REF_FUNC = 43, REF_STRUCT = 44, REF_ARRAY = 45, 
    REF_HOST = 46, REF_EXTERN = 47, REF_IS_NULL = 48, REF_AS_NON_NULL = 49, 
    REF_TEST = 50, REF_CAST = 51, REF_EQ = 52, REF_I31 = 53, REF_EXN = 54, 
    TRY_TABLE = 55, CATCH = 56, CATCH_REF = 57, CATCH_ALL = 58, CATCH_ALL_REF = 59, 
    THROW = 60, THROW_REF = 61, I31_GET = 62, STRUCT_NEW = 63, STRUCT_GET = 64, 
    STRUCT_SET = 65, ARRAY_NEW = 66, ARRAY_NEW_FIXED = 67, ARRAY_NEW_ELEM = 68, 
    ARRAY_NEW_DATA = 69, ARRAY_GET = 70, ARRAY_SET = 71, ARRAY_LEN = 72, 
    ARRAY_COPY = 73, ARRAY_FILL = 74, ARRAY_INIT_DATA = 75, ARRAY_INIT_ELEM = 76, 
    EXTERN_CONVERT = 77, MEMORY_ATOMIC_NOTIFY = 78, MEMORY_ATOMIC_WAIT = 79, 
    ATOMIC_FENCE = 80, ATOMIC_LOAD = 81, ATOMIC_STORE = 82, ATOMIC_RMW = 83, 
    ATOMIC_RMW_CMPXCHG = 84, NOP = 85, UNREACHABLE = 86, DROP = 87, BLOCK = 88, 
    LOOP = 89, END = 90, BR = 91, BR_IF = 92, BR_TABLE = 93, RETURN = 94, 
    IF = 95, THEN = 96, ELSE = 97, SELECT = 98, CALL = 99, CALL_INDIRECT = 100, 
    CALL_REF = 101, RETURN_CALL = 102, RETURN_CALL_REF = 103, RETURN_CALL_INDIRECT = 104, 
    BR_ON_NULL = 105, BR_ON_CAST = 106, LOCAL_GET = 107, LOCAL_SET = 108, 
    LOCAL_TEE = 109, GLOBAL_GET = 110, GLOBAL_SET = 111, TABLE_GET = 112, 
    TABLE_SET = 113, TABLE_SIZE = 114, TABLE_GROW = 115, TABLE_FILL = 116, 
    TABLE_COPY = 117, TABLE_INIT = 118, DATA_DROP = 119, ELEM_DROP = 120, 
    LOAD = 121, STORE = 122, OFFSET_EQ_NAT = 123, ALIGN_EQ_NAT = 124, UNARY = 125, 
    BINARY = 126, TEST = 127, COMPARE = 128, CONVERT = 129, VEC_LOAD = 130, 
    VEC_STORE = 131, VEC_LOAD_LANE = 132, VEC_STORE_LANE = 133, VEC_UNARY = 134, 
    VEC_BINARY = 135, VEC_TERNARY = 136, VEC_TEST = 137, VEC_BITMASK = 138, 
    VEC_SHIFT = 139, VEC_SHUFFLE = 140, VEC_SPLAT = 141, VEC_EXTRACT = 142, 
    VEC_REPLACE = 143, MEMORY_SIZE = 144, MEMORY_GROW = 145, MEMORY_FILL = 146, 
    MEMORY_COPY = 147, MEMORY_INIT = 148, TYPE = 149, FUNC = 150, START_ = 151, 
    PARAM = 152, RESULT = 153, LOCAL = 154, GLOBAL = 155, TABLE = 156, MEMORY = 157, 
    ELEM = 158, DATA = 159, OFFSET = 160, IMPORT = 161, EXPORT = 162, DECLARE = 163, 
    ITEM = 164, TAG = 165, MODULE = 166, BIN = 167, QUOTE = 168, EITHER = 169, 
    THREAD = 170, WAIT = 171, SCRIPT = 172, REGISTER = 173, INVOKE = 174, 
    GET = 175, ASSERT_MALFORMED = 176, ASSERT_INVALID = 177, ASSERT_UNLINKABLE = 178, 
    ASSERT_RETURN = 179, ASSERT_EXCEPTION = 180, ASSERT_TRAP = 181, ASSERT_EXHAUSTION = 182, 
    INPUT = 183, OUTPUT = 184, NAN_ = 185, VAR = 186, SPACE = 187, COMMENT = 188
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

