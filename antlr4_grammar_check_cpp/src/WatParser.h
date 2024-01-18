
// Generated from WatParser.g4 by ANTLR 4.13.1

#pragma once


#include "antlr4-runtime.h"




class  WatParser : public antlr4::Parser {
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

  enum {
    RuleValue = 0, RuleName = 1, RuleNull_opt = 2, RuleHeap_type = 3, RuleRef_type = 4, 
    RuleVal_type = 5, RuleGlobal_type = 6, RuleStorage_type = 7, RuleField_type = 8, 
    RuleStruct_type = 9, RuleArray_type = 10, RuleFunc_type = 11, RuleStr_type = 12, 
    RuleSub_type = 13, RuleTable_type = 14, RuleMemory_type = 15, RuleType_use = 16, 
    RuleNat32 = 17, RuleNum = 18, RuleVar_ = 19, RuleBind_var = 20, RuleInstr_list = 21, 
    RuleInstr = 22, RulePlain_instr = 23, RuleSelect_instr_instr_list = 24, 
    RuleCall_instr_instr_list = 25, RuleCall_instr_type_instr_list = 26, 
    RuleBlock_instr = 27, RuleBlock = 28, RuleBlock_param_body = 29, RuleHandler_block = 30, 
    RuleHandler_block_param_body = 31, RuleHandler_block_body = 32, RuleExpr = 33, 
    RuleExpr1 = 34, RuleSelect_expr_results = 35, RuleCall_expr_type = 36, 
    RuleCall_expr_params = 37, RuleCall_expr_results = 38, RuleIf_block = 39, 
    RuleIf_block_result_body = 40, RuleTry_block = 41, RuleTry_block_param_body = 42, 
    RuleTry_block_handler_body = 43, RuleConst_expr = 44, RuleFunc_ = 45, 
    RuleFunc_fields = 46, RuleFunc_fields_import = 47, RuleFunc_fields_import_result = 48, 
    RuleFunc_fields_body = 49, RuleFunc_result_body = 50, RuleFunc_body = 51, 
    RuleTable_use = 52, RuleMemory_use = 53, RuleOffset = 54, RuleElem_kind = 55, 
    RuleElem_expr = 56, RuleElem_list = 57, RuleElem = 58, RuleTable = 59, 
    RuleTable_fields = 60, RuleData = 61, RuleMemory = 62, RuleMemory_fields = 63, 
    RuleTag = 64, RuleTag_fields = 65, RuleTag_fields_import = 66, RuleTag_fields_import_result = 67, 
    RuleSglobal = 68, RuleGlobal_fields = 69, RuleImport_desc = 70, RuleSimport = 71, 
    RuleInline_import = 72, RuleExport_desc = 73, RuleExport_ = 74, RuleInline_export = 75, 
    RuleType_def = 76, RuleRec_type = 77, RuleType_ = 78, RuleStart_ = 79, 
    RuleModule_field = 80, RuleModule_ = 81, RuleInline_module = 82, RuleScript_module = 83, 
    RuleAction_ = 84, RuleAssertion = 85, RuleCmd = 86, RuleShared_cmd_list = 87, 
    RuleMeta = 88, RuleLiteral_num = 89, RuleLiteral_vec = 90, RuleLiteral_ref = 91, 
    RuleLiteral = 92, RuleLiteral_list = 93, RuleNumpat = 94, RuleResult = 95, 
    RuleScript = 96, RuleModule = 97
  };

  explicit WatParser(antlr4::TokenStream *input);

  WatParser(antlr4::TokenStream *input, const antlr4::atn::ParserATNSimulatorOptions &options);

  ~WatParser() override;

  std::string getGrammarFileName() const override;

  const antlr4::atn::ATN& getATN() const override;

  const std::vector<std::string>& getRuleNames() const override;

  const antlr4::dfa::Vocabulary& getVocabulary() const override;

  antlr4::atn::SerializedATNView getSerializedATN() const override;


  class ValueContext;
  class NameContext;
  class Null_optContext;
  class Heap_typeContext;
  class Ref_typeContext;
  class Val_typeContext;
  class Global_typeContext;
  class Storage_typeContext;
  class Field_typeContext;
  class Struct_typeContext;
  class Array_typeContext;
  class Func_typeContext;
  class Str_typeContext;
  class Sub_typeContext;
  class Table_typeContext;
  class Memory_typeContext;
  class Type_useContext;
  class Nat32Context;
  class NumContext;
  class Var_Context;
  class Bind_varContext;
  class Instr_listContext;
  class InstrContext;
  class Plain_instrContext;
  class Select_instr_instr_listContext;
  class Call_instr_instr_listContext;
  class Call_instr_type_instr_listContext;
  class Block_instrContext;
  class BlockContext;
  class Block_param_bodyContext;
  class Handler_blockContext;
  class Handler_block_param_bodyContext;
  class Handler_block_bodyContext;
  class ExprContext;
  class Expr1Context;
  class Select_expr_resultsContext;
  class Call_expr_typeContext;
  class Call_expr_paramsContext;
  class Call_expr_resultsContext;
  class If_blockContext;
  class If_block_result_bodyContext;
  class Try_blockContext;
  class Try_block_param_bodyContext;
  class Try_block_handler_bodyContext;
  class Const_exprContext;
  class Func_Context;
  class Func_fieldsContext;
  class Func_fields_importContext;
  class Func_fields_import_resultContext;
  class Func_fields_bodyContext;
  class Func_result_bodyContext;
  class Func_bodyContext;
  class Table_useContext;
  class Memory_useContext;
  class OffsetContext;
  class Elem_kindContext;
  class Elem_exprContext;
  class Elem_listContext;
  class ElemContext;
  class TableContext;
  class Table_fieldsContext;
  class DataContext;
  class MemoryContext;
  class Memory_fieldsContext;
  class TagContext;
  class Tag_fieldsContext;
  class Tag_fields_importContext;
  class Tag_fields_import_resultContext;
  class SglobalContext;
  class Global_fieldsContext;
  class Import_descContext;
  class SimportContext;
  class Inline_importContext;
  class Export_descContext;
  class Export_Context;
  class Inline_exportContext;
  class Type_defContext;
  class Rec_typeContext;
  class Type_Context;
  class Start_Context;
  class Module_fieldContext;
  class Module_Context;
  class Inline_moduleContext;
  class Script_moduleContext;
  class Action_Context;
  class AssertionContext;
  class CmdContext;
  class Shared_cmd_listContext;
  class MetaContext;
  class Literal_numContext;
  class Literal_vecContext;
  class Literal_refContext;
  class LiteralContext;
  class Literal_listContext;
  class NumpatContext;
  class ResultContext;
  class ScriptContext;
  class ModuleContext; 

  class  ValueContext : public antlr4::ParserRuleContext {
  public:
    ValueContext(antlr4::ParserRuleContext *parent, size_t invokingState);
    virtual size_t getRuleIndex() const override;
    antlr4::tree::TerminalNode *INT();
    antlr4::tree::TerminalNode *FLOAT();

    virtual void enterRule(antlr4::tree::ParseTreeListener *listener) override;
    virtual void exitRule(antlr4::tree::ParseTreeListener *listener) override;

    virtual std::any accept(antlr4::tree::ParseTreeVisitor *visitor) override;
   
  };

  ValueContext* value();

  class  NameContext : public antlr4::ParserRuleContext {
  public:
    NameContext(antlr4::ParserRuleContext *parent, size_t invokingState);
    virtual size_t getRuleIndex() const override;
    antlr4::tree::TerminalNode *STRING_();

    virtual void enterRule(antlr4::tree::ParseTreeListener *listener) override;
    virtual void exitRule(antlr4::tree::ParseTreeListener *listener) override;

    virtual std::any accept(antlr4::tree::ParseTreeVisitor *visitor) override;
   
  };

  NameContext* name();

  class  Null_optContext : public antlr4::ParserRuleContext {
  public:
    Null_optContext(antlr4::ParserRuleContext *parent, size_t invokingState);
    virtual size_t getRuleIndex() const override;
    antlr4::tree::TerminalNode *NULL_();

    virtual void enterRule(antlr4::tree::ParseTreeListener *listener) override;
    virtual void exitRule(antlr4::tree::ParseTreeListener *listener) override;

    virtual std::any accept(antlr4::tree::ParseTreeVisitor *visitor) override;
   
  };

  Null_optContext* null_opt();

  class  Heap_typeContext : public antlr4::ParserRuleContext {
  public:
    Heap_typeContext(antlr4::ParserRuleContext *parent, size_t invokingState);
    virtual size_t getRuleIndex() const override;
    antlr4::tree::TerminalNode *ANY();
    antlr4::tree::TerminalNode *NONE();
    antlr4::tree::TerminalNode *EQ();
    antlr4::tree::TerminalNode *I31();
    antlr4::tree::TerminalNode *STRUCT();
    antlr4::tree::TerminalNode *ARRAY();
    antlr4::tree::TerminalNode *FUNC();
    antlr4::tree::TerminalNode *NOFUNC();
    antlr4::tree::TerminalNode *EXTERN();
    antlr4::tree::TerminalNode *NOEXTERN();
    antlr4::tree::TerminalNode *EXN();
    Var_Context *var_();

    virtual void enterRule(antlr4::tree::ParseTreeListener *listener) override;
    virtual void exitRule(antlr4::tree::ParseTreeListener *listener) override;

    virtual std::any accept(antlr4::tree::ParseTreeVisitor *visitor) override;
   
  };

  Heap_typeContext* heap_type();

  class  Ref_typeContext : public antlr4::ParserRuleContext {
  public:
    Ref_typeContext(antlr4::ParserRuleContext *parent, size_t invokingState);
    virtual size_t getRuleIndex() const override;
    antlr4::tree::TerminalNode *FUNCREF();
    antlr4::tree::TerminalNode *EXTERNREF();
    antlr4::tree::TerminalNode *LPAR();
    antlr4::tree::TerminalNode *REF();
    Null_optContext *null_opt();
    Heap_typeContext *heap_type();
    antlr4::tree::TerminalNode *RPAR();
    antlr4::tree::TerminalNode *ANYREF();
    antlr4::tree::TerminalNode *NULLREF();
    antlr4::tree::TerminalNode *EQREF();
    antlr4::tree::TerminalNode *I31REF();
    antlr4::tree::TerminalNode *STRUCTREF();
    antlr4::tree::TerminalNode *ARRAYREF();
    antlr4::tree::TerminalNode *NULLFUNCREF();
    antlr4::tree::TerminalNode *NULLEXTERNREF();
    antlr4::tree::TerminalNode *EXNREF();

    virtual void enterRule(antlr4::tree::ParseTreeListener *listener) override;
    virtual void exitRule(antlr4::tree::ParseTreeListener *listener) override;

    virtual std::any accept(antlr4::tree::ParseTreeVisitor *visitor) override;
   
  };

  Ref_typeContext* ref_type();

  class  Val_typeContext : public antlr4::ParserRuleContext {
  public:
    Val_typeContext(antlr4::ParserRuleContext *parent, size_t invokingState);
    virtual size_t getRuleIndex() const override;
    antlr4::tree::TerminalNode *NUM_TYPE();
    antlr4::tree::TerminalNode *VEC_TYPE();
    Ref_typeContext *ref_type();

    virtual void enterRule(antlr4::tree::ParseTreeListener *listener) override;
    virtual void exitRule(antlr4::tree::ParseTreeListener *listener) override;

    virtual std::any accept(antlr4::tree::ParseTreeVisitor *visitor) override;
   
  };

  Val_typeContext* val_type();

  class  Global_typeContext : public antlr4::ParserRuleContext {
  public:
    Global_typeContext(antlr4::ParserRuleContext *parent, size_t invokingState);
    virtual size_t getRuleIndex() const override;
    Val_typeContext *val_type();
    antlr4::tree::TerminalNode *LPAR();
    antlr4::tree::TerminalNode *MUT();
    antlr4::tree::TerminalNode *RPAR();

    virtual void enterRule(antlr4::tree::ParseTreeListener *listener) override;
    virtual void exitRule(antlr4::tree::ParseTreeListener *listener) override;

    virtual std::any accept(antlr4::tree::ParseTreeVisitor *visitor) override;
   
  };

  Global_typeContext* global_type();

  class  Storage_typeContext : public antlr4::ParserRuleContext {
  public:
    Storage_typeContext(antlr4::ParserRuleContext *parent, size_t invokingState);
    virtual size_t getRuleIndex() const override;
    Val_typeContext *val_type();
    antlr4::tree::TerminalNode *PACK_TYPE();

    virtual void enterRule(antlr4::tree::ParseTreeListener *listener) override;
    virtual void exitRule(antlr4::tree::ParseTreeListener *listener) override;

    virtual std::any accept(antlr4::tree::ParseTreeVisitor *visitor) override;
   
  };

  Storage_typeContext* storage_type();

  class  Field_typeContext : public antlr4::ParserRuleContext {
  public:
    Field_typeContext(antlr4::ParserRuleContext *parent, size_t invokingState);
    virtual size_t getRuleIndex() const override;
    Storage_typeContext *storage_type();
    antlr4::tree::TerminalNode *LPAR();
    antlr4::tree::TerminalNode *MUT();
    antlr4::tree::TerminalNode *RPAR();

    virtual void enterRule(antlr4::tree::ParseTreeListener *listener) override;
    virtual void exitRule(antlr4::tree::ParseTreeListener *listener) override;

    virtual std::any accept(antlr4::tree::ParseTreeVisitor *visitor) override;
   
  };

  Field_typeContext* field_type();

  class  Struct_typeContext : public antlr4::ParserRuleContext {
  public:
    Struct_typeContext(antlr4::ParserRuleContext *parent, size_t invokingState);
    virtual size_t getRuleIndex() const override;
    std::vector<antlr4::tree::TerminalNode *> LPAR();
    antlr4::tree::TerminalNode* LPAR(size_t i);
    std::vector<antlr4::tree::TerminalNode *> FIELD();
    antlr4::tree::TerminalNode* FIELD(size_t i);
    std::vector<antlr4::tree::TerminalNode *> RPAR();
    antlr4::tree::TerminalNode* RPAR(size_t i);
    std::vector<Bind_varContext *> bind_var();
    Bind_varContext* bind_var(size_t i);
    std::vector<Field_typeContext *> field_type();
    Field_typeContext* field_type(size_t i);

    virtual void enterRule(antlr4::tree::ParseTreeListener *listener) override;
    virtual void exitRule(antlr4::tree::ParseTreeListener *listener) override;

    virtual std::any accept(antlr4::tree::ParseTreeVisitor *visitor) override;
   
  };

  Struct_typeContext* struct_type();

  class  Array_typeContext : public antlr4::ParserRuleContext {
  public:
    Array_typeContext(antlr4::ParserRuleContext *parent, size_t invokingState);
    virtual size_t getRuleIndex() const override;
    Field_typeContext *field_type();

    virtual void enterRule(antlr4::tree::ParseTreeListener *listener) override;
    virtual void exitRule(antlr4::tree::ParseTreeListener *listener) override;

    virtual std::any accept(antlr4::tree::ParseTreeVisitor *visitor) override;
   
  };

  Array_typeContext* array_type();

  class  Func_typeContext : public antlr4::ParserRuleContext {
  public:
    Func_typeContext(antlr4::ParserRuleContext *parent, size_t invokingState);
    virtual size_t getRuleIndex() const override;
    std::vector<antlr4::tree::TerminalNode *> LPAR();
    antlr4::tree::TerminalNode* LPAR(size_t i);
    std::vector<antlr4::tree::TerminalNode *> RPAR();
    antlr4::tree::TerminalNode* RPAR(size_t i);
    std::vector<antlr4::tree::TerminalNode *> RESULT();
    antlr4::tree::TerminalNode* RESULT(size_t i);
    std::vector<antlr4::tree::TerminalNode *> PARAM();
    antlr4::tree::TerminalNode* PARAM(size_t i);
    std::vector<Bind_varContext *> bind_var();
    Bind_varContext* bind_var(size_t i);
    std::vector<Val_typeContext *> val_type();
    Val_typeContext* val_type(size_t i);

    virtual void enterRule(antlr4::tree::ParseTreeListener *listener) override;
    virtual void exitRule(antlr4::tree::ParseTreeListener *listener) override;

    virtual std::any accept(antlr4::tree::ParseTreeVisitor *visitor) override;
   
  };

  Func_typeContext* func_type();

  class  Str_typeContext : public antlr4::ParserRuleContext {
  public:
    Str_typeContext(antlr4::ParserRuleContext *parent, size_t invokingState);
    virtual size_t getRuleIndex() const override;
    antlr4::tree::TerminalNode *LPAR();
    antlr4::tree::TerminalNode *RPAR();
    antlr4::tree::TerminalNode *STRUCT();
    Struct_typeContext *struct_type();
    antlr4::tree::TerminalNode *ARRAY();
    Array_typeContext *array_type();
    antlr4::tree::TerminalNode *FUNC();
    Func_typeContext *func_type();

    virtual void enterRule(antlr4::tree::ParseTreeListener *listener) override;
    virtual void exitRule(antlr4::tree::ParseTreeListener *listener) override;

    virtual std::any accept(antlr4::tree::ParseTreeVisitor *visitor) override;
   
  };

  Str_typeContext* str_type();

  class  Sub_typeContext : public antlr4::ParserRuleContext {
  public:
    Sub_typeContext(antlr4::ParserRuleContext *parent, size_t invokingState);
    virtual size_t getRuleIndex() const override;
    Str_typeContext *str_type();
    antlr4::tree::TerminalNode *LPAR();
    antlr4::tree::TerminalNode *SUB();
    antlr4::tree::TerminalNode *RPAR();
    antlr4::tree::TerminalNode *FINAL();
    std::vector<Var_Context *> var_();
    Var_Context* var_(size_t i);

    virtual void enterRule(antlr4::tree::ParseTreeListener *listener) override;
    virtual void exitRule(antlr4::tree::ParseTreeListener *listener) override;

    virtual std::any accept(antlr4::tree::ParseTreeVisitor *visitor) override;
   
  };

  Sub_typeContext* sub_type();

  class  Table_typeContext : public antlr4::ParserRuleContext {
  public:
    Table_typeContext(antlr4::ParserRuleContext *parent, size_t invokingState);
    virtual size_t getRuleIndex() const override;
    std::vector<antlr4::tree::TerminalNode *> NAT();
    antlr4::tree::TerminalNode* NAT(size_t i);
    Ref_typeContext *ref_type();

    virtual void enterRule(antlr4::tree::ParseTreeListener *listener) override;
    virtual void exitRule(antlr4::tree::ParseTreeListener *listener) override;

    virtual std::any accept(antlr4::tree::ParseTreeVisitor *visitor) override;
   
  };

  Table_typeContext* table_type();

  class  Memory_typeContext : public antlr4::ParserRuleContext {
  public:
    Memory_typeContext(antlr4::ParserRuleContext *parent, size_t invokingState);
    virtual size_t getRuleIndex() const override;
    std::vector<antlr4::tree::TerminalNode *> NAT();
    antlr4::tree::TerminalNode* NAT(size_t i);
    antlr4::tree::TerminalNode *SHARED();

    virtual void enterRule(antlr4::tree::ParseTreeListener *listener) override;
    virtual void exitRule(antlr4::tree::ParseTreeListener *listener) override;

    virtual std::any accept(antlr4::tree::ParseTreeVisitor *visitor) override;
   
  };

  Memory_typeContext* memory_type();

  class  Type_useContext : public antlr4::ParserRuleContext {
  public:
    Type_useContext(antlr4::ParserRuleContext *parent, size_t invokingState);
    virtual size_t getRuleIndex() const override;
    antlr4::tree::TerminalNode *LPAR();
    antlr4::tree::TerminalNode *TYPE();
    Var_Context *var_();
    antlr4::tree::TerminalNode *RPAR();

    virtual void enterRule(antlr4::tree::ParseTreeListener *listener) override;
    virtual void exitRule(antlr4::tree::ParseTreeListener *listener) override;

    virtual std::any accept(antlr4::tree::ParseTreeVisitor *visitor) override;
   
  };

  Type_useContext* type_use();

  class  Nat32Context : public antlr4::ParserRuleContext {
  public:
    Nat32Context(antlr4::ParserRuleContext *parent, size_t invokingState);
    virtual size_t getRuleIndex() const override;
    antlr4::tree::TerminalNode *NAT();

    virtual void enterRule(antlr4::tree::ParseTreeListener *listener) override;
    virtual void exitRule(antlr4::tree::ParseTreeListener *listener) override;

    virtual std::any accept(antlr4::tree::ParseTreeVisitor *visitor) override;
   
  };

  Nat32Context* nat32();

  class  NumContext : public antlr4::ParserRuleContext {
  public:
    NumContext(antlr4::ParserRuleContext *parent, size_t invokingState);
    virtual size_t getRuleIndex() const override;
    antlr4::tree::TerminalNode *NAT();
    antlr4::tree::TerminalNode *INT();
    antlr4::tree::TerminalNode *FLOAT();

    virtual void enterRule(antlr4::tree::ParseTreeListener *listener) override;
    virtual void exitRule(antlr4::tree::ParseTreeListener *listener) override;

    virtual std::any accept(antlr4::tree::ParseTreeVisitor *visitor) override;
   
  };

  NumContext* num();

  class  Var_Context : public antlr4::ParserRuleContext {
  public:
    Var_Context(antlr4::ParserRuleContext *parent, size_t invokingState);
    virtual size_t getRuleIndex() const override;
    antlr4::tree::TerminalNode *NAT();
    antlr4::tree::TerminalNode *VAR();

    virtual void enterRule(antlr4::tree::ParseTreeListener *listener) override;
    virtual void exitRule(antlr4::tree::ParseTreeListener *listener) override;

    virtual std::any accept(antlr4::tree::ParseTreeVisitor *visitor) override;
   
  };

  Var_Context* var_();

  class  Bind_varContext : public antlr4::ParserRuleContext {
  public:
    Bind_varContext(antlr4::ParserRuleContext *parent, size_t invokingState);
    virtual size_t getRuleIndex() const override;
    antlr4::tree::TerminalNode *VAR();

    virtual void enterRule(antlr4::tree::ParseTreeListener *listener) override;
    virtual void exitRule(antlr4::tree::ParseTreeListener *listener) override;

    virtual std::any accept(antlr4::tree::ParseTreeVisitor *visitor) override;
   
  };

  Bind_varContext* bind_var();

  class  Instr_listContext : public antlr4::ParserRuleContext {
  public:
    Instr_listContext(antlr4::ParserRuleContext *parent, size_t invokingState);
    virtual size_t getRuleIndex() const override;
    std::vector<InstrContext *> instr();
    InstrContext* instr(size_t i);
    Call_instr_instr_listContext *call_instr_instr_list();
    Select_instr_instr_listContext *select_instr_instr_list();

    virtual void enterRule(antlr4::tree::ParseTreeListener *listener) override;
    virtual void exitRule(antlr4::tree::ParseTreeListener *listener) override;

    virtual std::any accept(antlr4::tree::ParseTreeVisitor *visitor) override;
   
  };

  Instr_listContext* instr_list();

  class  InstrContext : public antlr4::ParserRuleContext {
  public:
    InstrContext(antlr4::ParserRuleContext *parent, size_t invokingState);
    virtual size_t getRuleIndex() const override;
    Plain_instrContext *plain_instr();
    Block_instrContext *block_instr();
    ExprContext *expr();

    virtual void enterRule(antlr4::tree::ParseTreeListener *listener) override;
    virtual void exitRule(antlr4::tree::ParseTreeListener *listener) override;

    virtual std::any accept(antlr4::tree::ParseTreeVisitor *visitor) override;
   
  };

  InstrContext* instr();

  class  Plain_instrContext : public antlr4::ParserRuleContext {
  public:
    Plain_instrContext(antlr4::ParserRuleContext *parent, size_t invokingState);
    virtual size_t getRuleIndex() const override;
    antlr4::tree::TerminalNode *UNREACHABLE();
    antlr4::tree::TerminalNode *NOP();
    antlr4::tree::TerminalNode *DROP();
    antlr4::tree::TerminalNode *SELECT();
    antlr4::tree::TerminalNode *BR();
    std::vector<Var_Context *> var_();
    Var_Context* var_(size_t i);
    antlr4::tree::TerminalNode *BR_IF();
    antlr4::tree::TerminalNode *BR_TABLE();
    antlr4::tree::TerminalNode *BR_ON_NULL();
    antlr4::tree::TerminalNode *BR_ON_CAST();
    std::vector<Ref_typeContext *> ref_type();
    Ref_typeContext* ref_type(size_t i);
    antlr4::tree::TerminalNode *RETURN();
    antlr4::tree::TerminalNode *CALL();
    antlr4::tree::TerminalNode *CALL_REF();
    antlr4::tree::TerminalNode *RETURN_CALL();
    antlr4::tree::TerminalNode *RETURN_CALL_REF();
    antlr4::tree::TerminalNode *LOCAL_GET();
    antlr4::tree::TerminalNode *LOCAL_SET();
    antlr4::tree::TerminalNode *LOCAL_TEE();
    antlr4::tree::TerminalNode *GLOBAL_GET();
    antlr4::tree::TerminalNode *GLOBAL_SET();
    antlr4::tree::TerminalNode *TABLE_GET();
    antlr4::tree::TerminalNode *TABLE_SET();
    antlr4::tree::TerminalNode *TABLE_SIZE();
    antlr4::tree::TerminalNode *TABLE_GROW();
    antlr4::tree::TerminalNode *TABLE_FILL();
    antlr4::tree::TerminalNode *TABLE_COPY();
    antlr4::tree::TerminalNode *TABLE_INIT();
    antlr4::tree::TerminalNode *ELEM_DROP();
    antlr4::tree::TerminalNode *LOAD();
    antlr4::tree::TerminalNode *OFFSET_EQ_NAT();
    antlr4::tree::TerminalNode *ALIGN_EQ_NAT();
    antlr4::tree::TerminalNode *STORE();
    antlr4::tree::TerminalNode *VEC_LOAD();
    antlr4::tree::TerminalNode *VEC_STORE();
    antlr4::tree::TerminalNode *VEC_LOAD_LANE();
    antlr4::tree::TerminalNode *NAT();
    antlr4::tree::TerminalNode *VEC_STORE_LANE();
    antlr4::tree::TerminalNode *MEMORY_SIZE();
    antlr4::tree::TerminalNode *MEMORY_GROW();
    antlr4::tree::TerminalNode *CONST();
    std::vector<NumContext *> num();
    NumContext* num(size_t i);
    antlr4::tree::TerminalNode *MEMORY_FILL();
    antlr4::tree::TerminalNode *MEMORY_COPY();
    antlr4::tree::TerminalNode *MEMORY_INIT();
    antlr4::tree::TerminalNode *DATA_DROP();
    antlr4::tree::TerminalNode *REF_NULL();
    Heap_typeContext *heap_type();
    antlr4::tree::TerminalNode *REF_IS_NULL();
    antlr4::tree::TerminalNode *REF_FUNC();
    antlr4::tree::TerminalNode *REF_AS_NON_NULL();
    antlr4::tree::TerminalNode *REF_TEST();
    antlr4::tree::TerminalNode *REF_CAST();
    antlr4::tree::TerminalNode *REF_EQ();
    antlr4::tree::TerminalNode *REF_I31();
    antlr4::tree::TerminalNode *I31_GET();
    antlr4::tree::TerminalNode *STRUCT_NEW();
    antlr4::tree::TerminalNode *STRUCT_GET();
    antlr4::tree::TerminalNode *STRUCT_SET();
    antlr4::tree::TerminalNode *ARRAY_NEW();
    antlr4::tree::TerminalNode *ARRAY_NEW_FIXED();
    Nat32Context *nat32();
    antlr4::tree::TerminalNode *ARRAY_NEW_ELEM();
    antlr4::tree::TerminalNode *ARRAY_NEW_DATA();
    antlr4::tree::TerminalNode *ARRAY_GET();
    antlr4::tree::TerminalNode *ARRAY_SET();
    antlr4::tree::TerminalNode *ARRAY_LEN();
    antlr4::tree::TerminalNode *ARRAY_COPY();
    antlr4::tree::TerminalNode *ARRAY_FILL();
    antlr4::tree::TerminalNode *ARRAY_INIT_DATA();
    antlr4::tree::TerminalNode *ARRAY_INIT_ELEM();
    antlr4::tree::TerminalNode *EXTERN_CONVERT();
    antlr4::tree::TerminalNode *TEST();
    antlr4::tree::TerminalNode *COMPARE();
    antlr4::tree::TerminalNode *UNARY();
    antlr4::tree::TerminalNode *BINARY();
    antlr4::tree::TerminalNode *CONVERT();
    antlr4::tree::TerminalNode *VEC_CONST();
    antlr4::tree::TerminalNode *VEC_SHAPE();
    antlr4::tree::TerminalNode *VEC_UNARY();
    antlr4::tree::TerminalNode *VEC_BINARY();
    antlr4::tree::TerminalNode *VEC_TERNARY();
    antlr4::tree::TerminalNode *VEC_TEST();
    antlr4::tree::TerminalNode *VEC_SHIFT();
    antlr4::tree::TerminalNode *VEC_BITMASK();
    antlr4::tree::TerminalNode *VEC_SHUFFLE();
    antlr4::tree::TerminalNode *VEC_SPLAT();
    antlr4::tree::TerminalNode *VEC_EXTRACT();
    antlr4::tree::TerminalNode *VEC_REPLACE();
    antlr4::tree::TerminalNode *MEMORY_ATOMIC_WAIT();
    antlr4::tree::TerminalNode *MEMORY_ATOMIC_NOTIFY();
    antlr4::tree::TerminalNode *ATOMIC_FENCE();
    antlr4::tree::TerminalNode *ATOMIC_LOAD();
    antlr4::tree::TerminalNode *ATOMIC_STORE();
    antlr4::tree::TerminalNode *ATOMIC_RMW();
    antlr4::tree::TerminalNode *ATOMIC_RMW_CMPXCHG();
    antlr4::tree::TerminalNode *THROW();
    antlr4::tree::TerminalNode *THROW_REF();

    virtual void enterRule(antlr4::tree::ParseTreeListener *listener) override;
    virtual void exitRule(antlr4::tree::ParseTreeListener *listener) override;

    virtual std::any accept(antlr4::tree::ParseTreeVisitor *visitor) override;
   
  };

  Plain_instrContext* plain_instr();

  class  Select_instr_instr_listContext : public antlr4::ParserRuleContext {
  public:
    Select_instr_instr_listContext(antlr4::ParserRuleContext *parent, size_t invokingState);
    virtual size_t getRuleIndex() const override;
    antlr4::tree::TerminalNode *SELECT();
    Instr_listContext *instr_list();
    std::vector<antlr4::tree::TerminalNode *> LPAR();
    antlr4::tree::TerminalNode* LPAR(size_t i);
    std::vector<antlr4::tree::TerminalNode *> RESULT();
    antlr4::tree::TerminalNode* RESULT(size_t i);
    std::vector<antlr4::tree::TerminalNode *> RPAR();
    antlr4::tree::TerminalNode* RPAR(size_t i);
    std::vector<Val_typeContext *> val_type();
    Val_typeContext* val_type(size_t i);

    virtual void enterRule(antlr4::tree::ParseTreeListener *listener) override;
    virtual void exitRule(antlr4::tree::ParseTreeListener *listener) override;

    virtual std::any accept(antlr4::tree::ParseTreeVisitor *visitor) override;
   
  };

  Select_instr_instr_listContext* select_instr_instr_list();

  class  Call_instr_instr_listContext : public antlr4::ParserRuleContext {
  public:
    Call_instr_instr_listContext(antlr4::ParserRuleContext *parent, size_t invokingState);
    virtual size_t getRuleIndex() const override;
    antlr4::tree::TerminalNode *CALL_INDIRECT();
    Call_instr_type_instr_listContext *call_instr_type_instr_list();
    Var_Context *var_();
    antlr4::tree::TerminalNode *RETURN_CALL_INDIRECT();

    virtual void enterRule(antlr4::tree::ParseTreeListener *listener) override;
    virtual void exitRule(antlr4::tree::ParseTreeListener *listener) override;

    virtual std::any accept(antlr4::tree::ParseTreeVisitor *visitor) override;
   
  };

  Call_instr_instr_listContext* call_instr_instr_list();

  class  Call_instr_type_instr_listContext : public antlr4::ParserRuleContext {
  public:
    Call_instr_type_instr_listContext(antlr4::ParserRuleContext *parent, size_t invokingState);
    virtual size_t getRuleIndex() const override;
    Instr_listContext *instr_list();
    Type_useContext *type_use();
    std::vector<antlr4::tree::TerminalNode *> LPAR();
    antlr4::tree::TerminalNode* LPAR(size_t i);
    std::vector<antlr4::tree::TerminalNode *> PARAM();
    antlr4::tree::TerminalNode* PARAM(size_t i);
    std::vector<antlr4::tree::TerminalNode *> RPAR();
    antlr4::tree::TerminalNode* RPAR(size_t i);
    std::vector<antlr4::tree::TerminalNode *> RESULT();
    antlr4::tree::TerminalNode* RESULT(size_t i);
    std::vector<Val_typeContext *> val_type();
    Val_typeContext* val_type(size_t i);

    virtual void enterRule(antlr4::tree::ParseTreeListener *listener) override;
    virtual void exitRule(antlr4::tree::ParseTreeListener *listener) override;

    virtual std::any accept(antlr4::tree::ParseTreeVisitor *visitor) override;
   
  };

  Call_instr_type_instr_listContext* call_instr_type_instr_list();

  class  Block_instrContext : public antlr4::ParserRuleContext {
  public:
    Block_instrContext(antlr4::ParserRuleContext *parent, size_t invokingState);
    virtual size_t getRuleIndex() const override;
    BlockContext *block();
    antlr4::tree::TerminalNode *END();
    antlr4::tree::TerminalNode *BLOCK();
    antlr4::tree::TerminalNode *LOOP();
    std::vector<Bind_varContext *> bind_var();
    Bind_varContext* bind_var(size_t i);
    antlr4::tree::TerminalNode *IF();
    antlr4::tree::TerminalNode *ELSE();
    Instr_listContext *instr_list();
    antlr4::tree::TerminalNode *TRY_TABLE();
    Handler_blockContext *handler_block();

    virtual void enterRule(antlr4::tree::ParseTreeListener *listener) override;
    virtual void exitRule(antlr4::tree::ParseTreeListener *listener) override;

    virtual std::any accept(antlr4::tree::ParseTreeVisitor *visitor) override;
   
  };

  Block_instrContext* block_instr();

  class  BlockContext : public antlr4::ParserRuleContext {
  public:
    BlockContext(antlr4::ParserRuleContext *parent, size_t invokingState);
    virtual size_t getRuleIndex() const override;
    Block_param_bodyContext *block_param_body();
    Type_useContext *type_use();

    virtual void enterRule(antlr4::tree::ParseTreeListener *listener) override;
    virtual void exitRule(antlr4::tree::ParseTreeListener *listener) override;

    virtual std::any accept(antlr4::tree::ParseTreeVisitor *visitor) override;
   
  };

  BlockContext* block();

  class  Block_param_bodyContext : public antlr4::ParserRuleContext {
  public:
    Block_param_bodyContext(antlr4::ParserRuleContext *parent, size_t invokingState);
    virtual size_t getRuleIndex() const override;
    Instr_listContext *instr_list();
    std::vector<antlr4::tree::TerminalNode *> LPAR();
    antlr4::tree::TerminalNode* LPAR(size_t i);
    std::vector<antlr4::tree::TerminalNode *> PARAM();
    antlr4::tree::TerminalNode* PARAM(size_t i);
    std::vector<antlr4::tree::TerminalNode *> RPAR();
    antlr4::tree::TerminalNode* RPAR(size_t i);
    std::vector<antlr4::tree::TerminalNode *> RESULT();
    antlr4::tree::TerminalNode* RESULT(size_t i);
    std::vector<Val_typeContext *> val_type();
    Val_typeContext* val_type(size_t i);

    virtual void enterRule(antlr4::tree::ParseTreeListener *listener) override;
    virtual void exitRule(antlr4::tree::ParseTreeListener *listener) override;

    virtual std::any accept(antlr4::tree::ParseTreeVisitor *visitor) override;
   
  };

  Block_param_bodyContext* block_param_body();

  class  Handler_blockContext : public antlr4::ParserRuleContext {
  public:
    Handler_blockContext(antlr4::ParserRuleContext *parent, size_t invokingState);
    virtual size_t getRuleIndex() const override;
    Handler_block_param_bodyContext *handler_block_param_body();
    Type_useContext *type_use();

    virtual void enterRule(antlr4::tree::ParseTreeListener *listener) override;
    virtual void exitRule(antlr4::tree::ParseTreeListener *listener) override;

    virtual std::any accept(antlr4::tree::ParseTreeVisitor *visitor) override;
   
  };

  Handler_blockContext* handler_block();

  class  Handler_block_param_bodyContext : public antlr4::ParserRuleContext {
  public:
    Handler_block_param_bodyContext(antlr4::ParserRuleContext *parent, size_t invokingState);
    virtual size_t getRuleIndex() const override;
    Handler_block_bodyContext *handler_block_body();
    std::vector<antlr4::tree::TerminalNode *> LPAR();
    antlr4::tree::TerminalNode* LPAR(size_t i);
    std::vector<antlr4::tree::TerminalNode *> PARAM();
    antlr4::tree::TerminalNode* PARAM(size_t i);
    std::vector<antlr4::tree::TerminalNode *> RPAR();
    antlr4::tree::TerminalNode* RPAR(size_t i);
    std::vector<antlr4::tree::TerminalNode *> RESULT();
    antlr4::tree::TerminalNode* RESULT(size_t i);
    std::vector<Val_typeContext *> val_type();
    Val_typeContext* val_type(size_t i);

    virtual void enterRule(antlr4::tree::ParseTreeListener *listener) override;
    virtual void exitRule(antlr4::tree::ParseTreeListener *listener) override;

    virtual std::any accept(antlr4::tree::ParseTreeVisitor *visitor) override;
   
  };

  Handler_block_param_bodyContext* handler_block_param_body();

  class  Handler_block_bodyContext : public antlr4::ParserRuleContext {
  public:
    Handler_block_bodyContext(antlr4::ParserRuleContext *parent, size_t invokingState);
    virtual size_t getRuleIndex() const override;
    Instr_listContext *instr_list();
    std::vector<antlr4::tree::TerminalNode *> LPAR();
    antlr4::tree::TerminalNode* LPAR(size_t i);
    std::vector<Var_Context *> var_();
    Var_Context* var_(size_t i);
    std::vector<antlr4::tree::TerminalNode *> RPAR();
    antlr4::tree::TerminalNode* RPAR(size_t i);
    std::vector<antlr4::tree::TerminalNode *> CATCH();
    antlr4::tree::TerminalNode* CATCH(size_t i);
    std::vector<antlr4::tree::TerminalNode *> CATCH_REF();
    antlr4::tree::TerminalNode* CATCH_REF(size_t i);
    std::vector<antlr4::tree::TerminalNode *> CATCH_ALL();
    antlr4::tree::TerminalNode* CATCH_ALL(size_t i);
    std::vector<antlr4::tree::TerminalNode *> CATCH_ALL_REF();
    antlr4::tree::TerminalNode* CATCH_ALL_REF(size_t i);

    virtual void enterRule(antlr4::tree::ParseTreeListener *listener) override;
    virtual void exitRule(antlr4::tree::ParseTreeListener *listener) override;

    virtual std::any accept(antlr4::tree::ParseTreeVisitor *visitor) override;
   
  };

  Handler_block_bodyContext* handler_block_body();

  class  ExprContext : public antlr4::ParserRuleContext {
  public:
    ExprContext(antlr4::ParserRuleContext *parent, size_t invokingState);
    virtual size_t getRuleIndex() const override;
    antlr4::tree::TerminalNode *LPAR();
    Expr1Context *expr1();
    antlr4::tree::TerminalNode *RPAR();

    virtual void enterRule(antlr4::tree::ParseTreeListener *listener) override;
    virtual void exitRule(antlr4::tree::ParseTreeListener *listener) override;

    virtual std::any accept(antlr4::tree::ParseTreeVisitor *visitor) override;
   
  };

  ExprContext* expr();

  class  Expr1Context : public antlr4::ParserRuleContext {
  public:
    Expr1Context(antlr4::ParserRuleContext *parent, size_t invokingState);
    virtual size_t getRuleIndex() const override;
    Plain_instrContext *plain_instr();
    std::vector<ExprContext *> expr();
    ExprContext* expr(size_t i);
    antlr4::tree::TerminalNode *SELECT();
    Select_expr_resultsContext *select_expr_results();
    antlr4::tree::TerminalNode *CALL_INDIRECT();
    Call_expr_typeContext *call_expr_type();
    Var_Context *var_();
    antlr4::tree::TerminalNode *RETURN_CALL_INDIRECT();
    antlr4::tree::TerminalNode *BLOCK();
    BlockContext *block();
    Bind_varContext *bind_var();
    antlr4::tree::TerminalNode *LOOP();
    antlr4::tree::TerminalNode *IF();
    If_blockContext *if_block();
    antlr4::tree::TerminalNode *TRY_TABLE();
    Try_blockContext *try_block();

    virtual void enterRule(antlr4::tree::ParseTreeListener *listener) override;
    virtual void exitRule(antlr4::tree::ParseTreeListener *listener) override;

    virtual std::any accept(antlr4::tree::ParseTreeVisitor *visitor) override;
   
  };

  Expr1Context* expr1();

  class  Select_expr_resultsContext : public antlr4::ParserRuleContext {
  public:
    Select_expr_resultsContext(antlr4::ParserRuleContext *parent, size_t invokingState);
    virtual size_t getRuleIndex() const override;
    std::vector<antlr4::tree::TerminalNode *> LPAR();
    antlr4::tree::TerminalNode* LPAR(size_t i);
    std::vector<antlr4::tree::TerminalNode *> RESULT();
    antlr4::tree::TerminalNode* RESULT(size_t i);
    std::vector<antlr4::tree::TerminalNode *> RPAR();
    antlr4::tree::TerminalNode* RPAR(size_t i);
    std::vector<ExprContext *> expr();
    ExprContext* expr(size_t i);
    std::vector<Val_typeContext *> val_type();
    Val_typeContext* val_type(size_t i);

    virtual void enterRule(antlr4::tree::ParseTreeListener *listener) override;
    virtual void exitRule(antlr4::tree::ParseTreeListener *listener) override;

    virtual std::any accept(antlr4::tree::ParseTreeVisitor *visitor) override;
   
  };

  Select_expr_resultsContext* select_expr_results();

  class  Call_expr_typeContext : public antlr4::ParserRuleContext {
  public:
    Call_expr_typeContext(antlr4::ParserRuleContext *parent, size_t invokingState);
    virtual size_t getRuleIndex() const override;
    Call_expr_paramsContext *call_expr_params();
    Type_useContext *type_use();

    virtual void enterRule(antlr4::tree::ParseTreeListener *listener) override;
    virtual void exitRule(antlr4::tree::ParseTreeListener *listener) override;

    virtual std::any accept(antlr4::tree::ParseTreeVisitor *visitor) override;
   
  };

  Call_expr_typeContext* call_expr_type();

  class  Call_expr_paramsContext : public antlr4::ParserRuleContext {
  public:
    Call_expr_paramsContext(antlr4::ParserRuleContext *parent, size_t invokingState);
    virtual size_t getRuleIndex() const override;
    Call_expr_resultsContext *call_expr_results();
    std::vector<antlr4::tree::TerminalNode *> LPAR();
    antlr4::tree::TerminalNode* LPAR(size_t i);
    std::vector<antlr4::tree::TerminalNode *> PARAM();
    antlr4::tree::TerminalNode* PARAM(size_t i);
    std::vector<antlr4::tree::TerminalNode *> RPAR();
    antlr4::tree::TerminalNode* RPAR(size_t i);
    std::vector<Val_typeContext *> val_type();
    Val_typeContext* val_type(size_t i);

    virtual void enterRule(antlr4::tree::ParseTreeListener *listener) override;
    virtual void exitRule(antlr4::tree::ParseTreeListener *listener) override;

    virtual std::any accept(antlr4::tree::ParseTreeVisitor *visitor) override;
   
  };

  Call_expr_paramsContext* call_expr_params();

  class  Call_expr_resultsContext : public antlr4::ParserRuleContext {
  public:
    Call_expr_resultsContext(antlr4::ParserRuleContext *parent, size_t invokingState);
    virtual size_t getRuleIndex() const override;
    std::vector<antlr4::tree::TerminalNode *> LPAR();
    antlr4::tree::TerminalNode* LPAR(size_t i);
    std::vector<antlr4::tree::TerminalNode *> RESULT();
    antlr4::tree::TerminalNode* RESULT(size_t i);
    std::vector<antlr4::tree::TerminalNode *> RPAR();
    antlr4::tree::TerminalNode* RPAR(size_t i);
    std::vector<ExprContext *> expr();
    ExprContext* expr(size_t i);
    std::vector<Val_typeContext *> val_type();
    Val_typeContext* val_type(size_t i);

    virtual void enterRule(antlr4::tree::ParseTreeListener *listener) override;
    virtual void exitRule(antlr4::tree::ParseTreeListener *listener) override;

    virtual std::any accept(antlr4::tree::ParseTreeVisitor *visitor) override;
   
  };

  Call_expr_resultsContext* call_expr_results();

  class  If_blockContext : public antlr4::ParserRuleContext {
  public:
    If_blockContext(antlr4::ParserRuleContext *parent, size_t invokingState);
    virtual size_t getRuleIndex() const override;
    If_block_result_bodyContext *if_block_result_body();
    Type_useContext *type_use();
    std::vector<antlr4::tree::TerminalNode *> LPAR();
    antlr4::tree::TerminalNode* LPAR(size_t i);
    std::vector<antlr4::tree::TerminalNode *> PARAM();
    antlr4::tree::TerminalNode* PARAM(size_t i);
    std::vector<antlr4::tree::TerminalNode *> RPAR();
    antlr4::tree::TerminalNode* RPAR(size_t i);
    std::vector<Val_typeContext *> val_type();
    Val_typeContext* val_type(size_t i);

    virtual void enterRule(antlr4::tree::ParseTreeListener *listener) override;
    virtual void exitRule(antlr4::tree::ParseTreeListener *listener) override;

    virtual std::any accept(antlr4::tree::ParseTreeVisitor *visitor) override;
   
  };

  If_blockContext* if_block();

  class  If_block_result_bodyContext : public antlr4::ParserRuleContext {
  public:
    If_block_result_bodyContext(antlr4::ParserRuleContext *parent, size_t invokingState);
    virtual size_t getRuleIndex() const override;
    std::vector<antlr4::tree::TerminalNode *> LPAR();
    antlr4::tree::TerminalNode* LPAR(size_t i);
    antlr4::tree::TerminalNode *THEN();
    std::vector<Instr_listContext *> instr_list();
    Instr_listContext* instr_list(size_t i);
    std::vector<antlr4::tree::TerminalNode *> RPAR();
    antlr4::tree::TerminalNode* RPAR(size_t i);
    std::vector<antlr4::tree::TerminalNode *> RESULT();
    antlr4::tree::TerminalNode* RESULT(size_t i);
    std::vector<ExprContext *> expr();
    ExprContext* expr(size_t i);
    antlr4::tree::TerminalNode *ELSE();
    std::vector<Val_typeContext *> val_type();
    Val_typeContext* val_type(size_t i);

    virtual void enterRule(antlr4::tree::ParseTreeListener *listener) override;
    virtual void exitRule(antlr4::tree::ParseTreeListener *listener) override;

    virtual std::any accept(antlr4::tree::ParseTreeVisitor *visitor) override;
   
  };

  If_block_result_bodyContext* if_block_result_body();

  class  Try_blockContext : public antlr4::ParserRuleContext {
  public:
    Try_blockContext(antlr4::ParserRuleContext *parent, size_t invokingState);
    virtual size_t getRuleIndex() const override;
    Try_block_param_bodyContext *try_block_param_body();
    Type_useContext *type_use();

    virtual void enterRule(antlr4::tree::ParseTreeListener *listener) override;
    virtual void exitRule(antlr4::tree::ParseTreeListener *listener) override;

    virtual std::any accept(antlr4::tree::ParseTreeVisitor *visitor) override;
   
  };

  Try_blockContext* try_block();

  class  Try_block_param_bodyContext : public antlr4::ParserRuleContext {
  public:
    Try_block_param_bodyContext(antlr4::ParserRuleContext *parent, size_t invokingState);
    virtual size_t getRuleIndex() const override;
    Try_block_handler_bodyContext *try_block_handler_body();
    std::vector<antlr4::tree::TerminalNode *> LPAR();
    antlr4::tree::TerminalNode* LPAR(size_t i);
    std::vector<antlr4::tree::TerminalNode *> PARAM();
    antlr4::tree::TerminalNode* PARAM(size_t i);
    std::vector<antlr4::tree::TerminalNode *> RPAR();
    antlr4::tree::TerminalNode* RPAR(size_t i);
    std::vector<antlr4::tree::TerminalNode *> RESULT();
    antlr4::tree::TerminalNode* RESULT(size_t i);
    std::vector<Val_typeContext *> val_type();
    Val_typeContext* val_type(size_t i);

    virtual void enterRule(antlr4::tree::ParseTreeListener *listener) override;
    virtual void exitRule(antlr4::tree::ParseTreeListener *listener) override;

    virtual std::any accept(antlr4::tree::ParseTreeVisitor *visitor) override;
   
  };

  Try_block_param_bodyContext* try_block_param_body();

  class  Try_block_handler_bodyContext : public antlr4::ParserRuleContext {
  public:
    Try_block_handler_bodyContext(antlr4::ParserRuleContext *parent, size_t invokingState);
    virtual size_t getRuleIndex() const override;
    Instr_listContext *instr_list();
    std::vector<antlr4::tree::TerminalNode *> LPAR();
    antlr4::tree::TerminalNode* LPAR(size_t i);
    std::vector<Var_Context *> var_();
    Var_Context* var_(size_t i);
    std::vector<antlr4::tree::TerminalNode *> RPAR();
    antlr4::tree::TerminalNode* RPAR(size_t i);
    std::vector<antlr4::tree::TerminalNode *> CATCH();
    antlr4::tree::TerminalNode* CATCH(size_t i);
    std::vector<antlr4::tree::TerminalNode *> CATCH_REF();
    antlr4::tree::TerminalNode* CATCH_REF(size_t i);
    std::vector<antlr4::tree::TerminalNode *> CATCH_ALL();
    antlr4::tree::TerminalNode* CATCH_ALL(size_t i);
    std::vector<antlr4::tree::TerminalNode *> CATCH_ALL_REF();
    antlr4::tree::TerminalNode* CATCH_ALL_REF(size_t i);

    virtual void enterRule(antlr4::tree::ParseTreeListener *listener) override;
    virtual void exitRule(antlr4::tree::ParseTreeListener *listener) override;

    virtual std::any accept(antlr4::tree::ParseTreeVisitor *visitor) override;
   
  };

  Try_block_handler_bodyContext* try_block_handler_body();

  class  Const_exprContext : public antlr4::ParserRuleContext {
  public:
    Const_exprContext(antlr4::ParserRuleContext *parent, size_t invokingState);
    virtual size_t getRuleIndex() const override;
    Instr_listContext *instr_list();

    virtual void enterRule(antlr4::tree::ParseTreeListener *listener) override;
    virtual void exitRule(antlr4::tree::ParseTreeListener *listener) override;

    virtual std::any accept(antlr4::tree::ParseTreeVisitor *visitor) override;
   
  };

  Const_exprContext* const_expr();

  class  Func_Context : public antlr4::ParserRuleContext {
  public:
    Func_Context(antlr4::ParserRuleContext *parent, size_t invokingState);
    virtual size_t getRuleIndex() const override;
    antlr4::tree::TerminalNode *LPAR();
    antlr4::tree::TerminalNode *FUNC();
    Func_fieldsContext *func_fields();
    antlr4::tree::TerminalNode *RPAR();
    Bind_varContext *bind_var();

    virtual void enterRule(antlr4::tree::ParseTreeListener *listener) override;
    virtual void exitRule(antlr4::tree::ParseTreeListener *listener) override;

    virtual std::any accept(antlr4::tree::ParseTreeVisitor *visitor) override;
   
  };

  Func_Context* func_();

  class  Func_fieldsContext : public antlr4::ParserRuleContext {
  public:
    Func_fieldsContext(antlr4::ParserRuleContext *parent, size_t invokingState);
    virtual size_t getRuleIndex() const override;
    Func_fields_bodyContext *func_fields_body();
    Type_useContext *type_use();
    Inline_importContext *inline_import();
    Func_fields_importContext *func_fields_import();
    Inline_exportContext *inline_export();
    Func_fieldsContext *func_fields();

    virtual void enterRule(antlr4::tree::ParseTreeListener *listener) override;
    virtual void exitRule(antlr4::tree::ParseTreeListener *listener) override;

    virtual std::any accept(antlr4::tree::ParseTreeVisitor *visitor) override;
   
  };

  Func_fieldsContext* func_fields();

  class  Func_fields_importContext : public antlr4::ParserRuleContext {
  public:
    Func_fields_importContext(antlr4::ParserRuleContext *parent, size_t invokingState);
    virtual size_t getRuleIndex() const override;
    Func_fields_import_resultContext *func_fields_import_result();
    std::vector<antlr4::tree::TerminalNode *> LPAR();
    antlr4::tree::TerminalNode* LPAR(size_t i);
    std::vector<antlr4::tree::TerminalNode *> PARAM();
    antlr4::tree::TerminalNode* PARAM(size_t i);
    std::vector<antlr4::tree::TerminalNode *> RPAR();
    antlr4::tree::TerminalNode* RPAR(size_t i);
    std::vector<Bind_varContext *> bind_var();
    Bind_varContext* bind_var(size_t i);
    std::vector<Val_typeContext *> val_type();
    Val_typeContext* val_type(size_t i);

    virtual void enterRule(antlr4::tree::ParseTreeListener *listener) override;
    virtual void exitRule(antlr4::tree::ParseTreeListener *listener) override;

    virtual std::any accept(antlr4::tree::ParseTreeVisitor *visitor) override;
   
  };

  Func_fields_importContext* func_fields_import();

  class  Func_fields_import_resultContext : public antlr4::ParserRuleContext {
  public:
    Func_fields_import_resultContext(antlr4::ParserRuleContext *parent, size_t invokingState);
    virtual size_t getRuleIndex() const override;
    std::vector<antlr4::tree::TerminalNode *> LPAR();
    antlr4::tree::TerminalNode* LPAR(size_t i);
    std::vector<antlr4::tree::TerminalNode *> RESULT();
    antlr4::tree::TerminalNode* RESULT(size_t i);
    std::vector<antlr4::tree::TerminalNode *> RPAR();
    antlr4::tree::TerminalNode* RPAR(size_t i);
    std::vector<Val_typeContext *> val_type();
    Val_typeContext* val_type(size_t i);

    virtual void enterRule(antlr4::tree::ParseTreeListener *listener) override;
    virtual void exitRule(antlr4::tree::ParseTreeListener *listener) override;

    virtual std::any accept(antlr4::tree::ParseTreeVisitor *visitor) override;
   
  };

  Func_fields_import_resultContext* func_fields_import_result();

  class  Func_fields_bodyContext : public antlr4::ParserRuleContext {
  public:
    Func_fields_bodyContext(antlr4::ParserRuleContext *parent, size_t invokingState);
    virtual size_t getRuleIndex() const override;
    Func_result_bodyContext *func_result_body();
    std::vector<antlr4::tree::TerminalNode *> LPAR();
    antlr4::tree::TerminalNode* LPAR(size_t i);
    std::vector<antlr4::tree::TerminalNode *> PARAM();
    antlr4::tree::TerminalNode* PARAM(size_t i);
    std::vector<antlr4::tree::TerminalNode *> RPAR();
    antlr4::tree::TerminalNode* RPAR(size_t i);
    std::vector<Bind_varContext *> bind_var();
    Bind_varContext* bind_var(size_t i);
    std::vector<Val_typeContext *> val_type();
    Val_typeContext* val_type(size_t i);

    virtual void enterRule(antlr4::tree::ParseTreeListener *listener) override;
    virtual void exitRule(antlr4::tree::ParseTreeListener *listener) override;

    virtual std::any accept(antlr4::tree::ParseTreeVisitor *visitor) override;
   
  };

  Func_fields_bodyContext* func_fields_body();

  class  Func_result_bodyContext : public antlr4::ParserRuleContext {
  public:
    Func_result_bodyContext(antlr4::ParserRuleContext *parent, size_t invokingState);
    virtual size_t getRuleIndex() const override;
    Func_bodyContext *func_body();
    std::vector<antlr4::tree::TerminalNode *> LPAR();
    antlr4::tree::TerminalNode* LPAR(size_t i);
    std::vector<antlr4::tree::TerminalNode *> RESULT();
    antlr4::tree::TerminalNode* RESULT(size_t i);
    std::vector<antlr4::tree::TerminalNode *> RPAR();
    antlr4::tree::TerminalNode* RPAR(size_t i);
    std::vector<Val_typeContext *> val_type();
    Val_typeContext* val_type(size_t i);

    virtual void enterRule(antlr4::tree::ParseTreeListener *listener) override;
    virtual void exitRule(antlr4::tree::ParseTreeListener *listener) override;

    virtual std::any accept(antlr4::tree::ParseTreeVisitor *visitor) override;
   
  };

  Func_result_bodyContext* func_result_body();

  class  Func_bodyContext : public antlr4::ParserRuleContext {
  public:
    Func_bodyContext(antlr4::ParserRuleContext *parent, size_t invokingState);
    virtual size_t getRuleIndex() const override;
    Instr_listContext *instr_list();
    std::vector<antlr4::tree::TerminalNode *> LPAR();
    antlr4::tree::TerminalNode* LPAR(size_t i);
    std::vector<antlr4::tree::TerminalNode *> LOCAL();
    antlr4::tree::TerminalNode* LOCAL(size_t i);
    std::vector<antlr4::tree::TerminalNode *> RPAR();
    antlr4::tree::TerminalNode* RPAR(size_t i);
    std::vector<Bind_varContext *> bind_var();
    Bind_varContext* bind_var(size_t i);
    std::vector<Val_typeContext *> val_type();
    Val_typeContext* val_type(size_t i);

    virtual void enterRule(antlr4::tree::ParseTreeListener *listener) override;
    virtual void exitRule(antlr4::tree::ParseTreeListener *listener) override;

    virtual std::any accept(antlr4::tree::ParseTreeVisitor *visitor) override;
   
  };

  Func_bodyContext* func_body();

  class  Table_useContext : public antlr4::ParserRuleContext {
  public:
    Table_useContext(antlr4::ParserRuleContext *parent, size_t invokingState);
    virtual size_t getRuleIndex() const override;
    antlr4::tree::TerminalNode *LPAR();
    antlr4::tree::TerminalNode *TABLE();
    Var_Context *var_();
    antlr4::tree::TerminalNode *RPAR();

    virtual void enterRule(antlr4::tree::ParseTreeListener *listener) override;
    virtual void exitRule(antlr4::tree::ParseTreeListener *listener) override;

    virtual std::any accept(antlr4::tree::ParseTreeVisitor *visitor) override;
   
  };

  Table_useContext* table_use();

  class  Memory_useContext : public antlr4::ParserRuleContext {
  public:
    Memory_useContext(antlr4::ParserRuleContext *parent, size_t invokingState);
    virtual size_t getRuleIndex() const override;
    antlr4::tree::TerminalNode *LPAR();
    antlr4::tree::TerminalNode *MEMORY();
    Var_Context *var_();
    antlr4::tree::TerminalNode *RPAR();

    virtual void enterRule(antlr4::tree::ParseTreeListener *listener) override;
    virtual void exitRule(antlr4::tree::ParseTreeListener *listener) override;

    virtual std::any accept(antlr4::tree::ParseTreeVisitor *visitor) override;
   
  };

  Memory_useContext* memory_use();

  class  OffsetContext : public antlr4::ParserRuleContext {
  public:
    OffsetContext(antlr4::ParserRuleContext *parent, size_t invokingState);
    virtual size_t getRuleIndex() const override;
    antlr4::tree::TerminalNode *LPAR();
    antlr4::tree::TerminalNode *OFFSET();
    Const_exprContext *const_expr();
    antlr4::tree::TerminalNode *RPAR();
    ExprContext *expr();

    virtual void enterRule(antlr4::tree::ParseTreeListener *listener) override;
    virtual void exitRule(antlr4::tree::ParseTreeListener *listener) override;

    virtual std::any accept(antlr4::tree::ParseTreeVisitor *visitor) override;
   
  };

  OffsetContext* offset();

  class  Elem_kindContext : public antlr4::ParserRuleContext {
  public:
    Elem_kindContext(antlr4::ParserRuleContext *parent, size_t invokingState);
    virtual size_t getRuleIndex() const override;
    antlr4::tree::TerminalNode *FUNC();

    virtual void enterRule(antlr4::tree::ParseTreeListener *listener) override;
    virtual void exitRule(antlr4::tree::ParseTreeListener *listener) override;

    virtual std::any accept(antlr4::tree::ParseTreeVisitor *visitor) override;
   
  };

  Elem_kindContext* elem_kind();

  class  Elem_exprContext : public antlr4::ParserRuleContext {
  public:
    Elem_exprContext(antlr4::ParserRuleContext *parent, size_t invokingState);
    virtual size_t getRuleIndex() const override;
    antlr4::tree::TerminalNode *LPAR();
    antlr4::tree::TerminalNode *ITEM();
    Const_exprContext *const_expr();
    antlr4::tree::TerminalNode *RPAR();
    ExprContext *expr();

    virtual void enterRule(antlr4::tree::ParseTreeListener *listener) override;
    virtual void exitRule(antlr4::tree::ParseTreeListener *listener) override;

    virtual std::any accept(antlr4::tree::ParseTreeVisitor *visitor) override;
   
  };

  Elem_exprContext* elem_expr();

  class  Elem_listContext : public antlr4::ParserRuleContext {
  public:
    Elem_listContext(antlr4::ParserRuleContext *parent, size_t invokingState);
    virtual size_t getRuleIndex() const override;
    Elem_kindContext *elem_kind();
    std::vector<Var_Context *> var_();
    Var_Context* var_(size_t i);
    Ref_typeContext *ref_type();
    std::vector<Elem_exprContext *> elem_expr();
    Elem_exprContext* elem_expr(size_t i);

    virtual void enterRule(antlr4::tree::ParseTreeListener *listener) override;
    virtual void exitRule(antlr4::tree::ParseTreeListener *listener) override;

    virtual std::any accept(antlr4::tree::ParseTreeVisitor *visitor) override;
   
  };

  Elem_listContext* elem_list();

  class  ElemContext : public antlr4::ParserRuleContext {
  public:
    ElemContext(antlr4::ParserRuleContext *parent, size_t invokingState);
    virtual size_t getRuleIndex() const override;
    antlr4::tree::TerminalNode *LPAR();
    antlr4::tree::TerminalNode *ELEM();
    Elem_listContext *elem_list();
    antlr4::tree::TerminalNode *RPAR();
    Table_useContext *table_use();
    OffsetContext *offset();
    antlr4::tree::TerminalNode *DECLARE();
    Bind_varContext *bind_var();
    std::vector<Var_Context *> var_();
    Var_Context* var_(size_t i);

    virtual void enterRule(antlr4::tree::ParseTreeListener *listener) override;
    virtual void exitRule(antlr4::tree::ParseTreeListener *listener) override;

    virtual std::any accept(antlr4::tree::ParseTreeVisitor *visitor) override;
   
  };

  ElemContext* elem();

  class  TableContext : public antlr4::ParserRuleContext {
  public:
    TableContext(antlr4::ParserRuleContext *parent, size_t invokingState);
    virtual size_t getRuleIndex() const override;
    antlr4::tree::TerminalNode *LPAR();
    antlr4::tree::TerminalNode *TABLE();
    Table_fieldsContext *table_fields();
    antlr4::tree::TerminalNode *RPAR();
    Bind_varContext *bind_var();

    virtual void enterRule(antlr4::tree::ParseTreeListener *listener) override;
    virtual void exitRule(antlr4::tree::ParseTreeListener *listener) override;

    virtual std::any accept(antlr4::tree::ParseTreeVisitor *visitor) override;
   
  };

  TableContext* table();

  class  Table_fieldsContext : public antlr4::ParserRuleContext {
  public:
    Table_fieldsContext(antlr4::ParserRuleContext *parent, size_t invokingState);
    virtual size_t getRuleIndex() const override;
    Table_typeContext *table_type();
    InstrContext *instr();
    Instr_listContext *instr_list();
    Inline_importContext *inline_import();
    Inline_exportContext *inline_export();
    Table_fieldsContext *table_fields();
    Ref_typeContext *ref_type();
    antlr4::tree::TerminalNode *LPAR();
    antlr4::tree::TerminalNode *ELEM();
    antlr4::tree::TerminalNode *RPAR();
    std::vector<Var_Context *> var_();
    Var_Context* var_(size_t i);
    std::vector<Elem_exprContext *> elem_expr();
    Elem_exprContext* elem_expr(size_t i);

    virtual void enterRule(antlr4::tree::ParseTreeListener *listener) override;
    virtual void exitRule(antlr4::tree::ParseTreeListener *listener) override;

    virtual std::any accept(antlr4::tree::ParseTreeVisitor *visitor) override;
   
  };

  Table_fieldsContext* table_fields();

  class  DataContext : public antlr4::ParserRuleContext {
  public:
    DataContext(antlr4::ParserRuleContext *parent, size_t invokingState);
    virtual size_t getRuleIndex() const override;
    antlr4::tree::TerminalNode *LPAR();
    antlr4::tree::TerminalNode *DATA();
    Memory_useContext *memory_use();
    OffsetContext *offset();
    antlr4::tree::TerminalNode *RPAR();
    Bind_varContext *bind_var();
    std::vector<antlr4::tree::TerminalNode *> STRING_();
    antlr4::tree::TerminalNode* STRING_(size_t i);

    virtual void enterRule(antlr4::tree::ParseTreeListener *listener) override;
    virtual void exitRule(antlr4::tree::ParseTreeListener *listener) override;

    virtual std::any accept(antlr4::tree::ParseTreeVisitor *visitor) override;
   
  };

  DataContext* data();

  class  MemoryContext : public antlr4::ParserRuleContext {
  public:
    MemoryContext(antlr4::ParserRuleContext *parent, size_t invokingState);
    virtual size_t getRuleIndex() const override;
    antlr4::tree::TerminalNode *LPAR();
    antlr4::tree::TerminalNode *MEMORY();
    Memory_fieldsContext *memory_fields();
    antlr4::tree::TerminalNode *RPAR();
    Bind_varContext *bind_var();

    virtual void enterRule(antlr4::tree::ParseTreeListener *listener) override;
    virtual void exitRule(antlr4::tree::ParseTreeListener *listener) override;

    virtual std::any accept(antlr4::tree::ParseTreeVisitor *visitor) override;
   
  };

  MemoryContext* memory();

  class  Memory_fieldsContext : public antlr4::ParserRuleContext {
  public:
    Memory_fieldsContext(antlr4::ParserRuleContext *parent, size_t invokingState);
    virtual size_t getRuleIndex() const override;
    Memory_typeContext *memory_type();
    Inline_importContext *inline_import();
    Inline_exportContext *inline_export();
    Memory_fieldsContext *memory_fields();
    antlr4::tree::TerminalNode *LPAR();
    antlr4::tree::TerminalNode *DATA();
    antlr4::tree::TerminalNode *RPAR();
    std::vector<antlr4::tree::TerminalNode *> STRING_();
    antlr4::tree::TerminalNode* STRING_(size_t i);

    virtual void enterRule(antlr4::tree::ParseTreeListener *listener) override;
    virtual void exitRule(antlr4::tree::ParseTreeListener *listener) override;

    virtual std::any accept(antlr4::tree::ParseTreeVisitor *visitor) override;
   
  };

  Memory_fieldsContext* memory_fields();

  class  TagContext : public antlr4::ParserRuleContext {
  public:
    TagContext(antlr4::ParserRuleContext *parent, size_t invokingState);
    virtual size_t getRuleIndex() const override;
    antlr4::tree::TerminalNode *LPAR();
    antlr4::tree::TerminalNode *TAG();
    Tag_fieldsContext *tag_fields();
    antlr4::tree::TerminalNode *RPAR();
    Bind_varContext *bind_var();

    virtual void enterRule(antlr4::tree::ParseTreeListener *listener) override;
    virtual void exitRule(antlr4::tree::ParseTreeListener *listener) override;

    virtual std::any accept(antlr4::tree::ParseTreeVisitor *visitor) override;
   
  };

  TagContext* tag();

  class  Tag_fieldsContext : public antlr4::ParserRuleContext {
  public:
    Tag_fieldsContext(antlr4::ParserRuleContext *parent, size_t invokingState);
    virtual size_t getRuleIndex() const override;
    Func_typeContext *func_type();
    std::vector<Inline_exportContext *> inline_export();
    Inline_exportContext* inline_export(size_t i);
    Type_useContext *type_use();
    Inline_importContext *inline_import();
    Tag_fields_importContext *tag_fields_import();

    virtual void enterRule(antlr4::tree::ParseTreeListener *listener) override;
    virtual void exitRule(antlr4::tree::ParseTreeListener *listener) override;

    virtual std::any accept(antlr4::tree::ParseTreeVisitor *visitor) override;
   
  };

  Tag_fieldsContext* tag_fields();

  class  Tag_fields_importContext : public antlr4::ParserRuleContext {
  public:
    Tag_fields_importContext(antlr4::ParserRuleContext *parent, size_t invokingState);
    virtual size_t getRuleIndex() const override;
    Tag_fields_import_resultContext *tag_fields_import_result();
    std::vector<antlr4::tree::TerminalNode *> LPAR();
    antlr4::tree::TerminalNode* LPAR(size_t i);
    std::vector<antlr4::tree::TerminalNode *> PARAM();
    antlr4::tree::TerminalNode* PARAM(size_t i);
    std::vector<antlr4::tree::TerminalNode *> RPAR();
    antlr4::tree::TerminalNode* RPAR(size_t i);
    std::vector<Bind_varContext *> bind_var();
    Bind_varContext* bind_var(size_t i);
    std::vector<Val_typeContext *> val_type();
    Val_typeContext* val_type(size_t i);

    virtual void enterRule(antlr4::tree::ParseTreeListener *listener) override;
    virtual void exitRule(antlr4::tree::ParseTreeListener *listener) override;

    virtual std::any accept(antlr4::tree::ParseTreeVisitor *visitor) override;
   
  };

  Tag_fields_importContext* tag_fields_import();

  class  Tag_fields_import_resultContext : public antlr4::ParserRuleContext {
  public:
    Tag_fields_import_resultContext(antlr4::ParserRuleContext *parent, size_t invokingState);
    virtual size_t getRuleIndex() const override;
    std::vector<antlr4::tree::TerminalNode *> LPAR();
    antlr4::tree::TerminalNode* LPAR(size_t i);
    std::vector<antlr4::tree::TerminalNode *> RESULT();
    antlr4::tree::TerminalNode* RESULT(size_t i);
    std::vector<antlr4::tree::TerminalNode *> RPAR();
    antlr4::tree::TerminalNode* RPAR(size_t i);
    std::vector<Val_typeContext *> val_type();
    Val_typeContext* val_type(size_t i);

    virtual void enterRule(antlr4::tree::ParseTreeListener *listener) override;
    virtual void exitRule(antlr4::tree::ParseTreeListener *listener) override;

    virtual std::any accept(antlr4::tree::ParseTreeVisitor *visitor) override;
   
  };

  Tag_fields_import_resultContext* tag_fields_import_result();

  class  SglobalContext : public antlr4::ParserRuleContext {
  public:
    SglobalContext(antlr4::ParserRuleContext *parent, size_t invokingState);
    virtual size_t getRuleIndex() const override;
    antlr4::tree::TerminalNode *LPAR();
    antlr4::tree::TerminalNode *GLOBAL();
    Global_fieldsContext *global_fields();
    antlr4::tree::TerminalNode *RPAR();
    Bind_varContext *bind_var();

    virtual void enterRule(antlr4::tree::ParseTreeListener *listener) override;
    virtual void exitRule(antlr4::tree::ParseTreeListener *listener) override;

    virtual std::any accept(antlr4::tree::ParseTreeVisitor *visitor) override;
   
  };

  SglobalContext* sglobal();

  class  Global_fieldsContext : public antlr4::ParserRuleContext {
  public:
    Global_fieldsContext(antlr4::ParserRuleContext *parent, size_t invokingState);
    virtual size_t getRuleIndex() const override;
    Global_typeContext *global_type();
    Const_exprContext *const_expr();
    Inline_importContext *inline_import();
    Inline_exportContext *inline_export();
    Global_fieldsContext *global_fields();

    virtual void enterRule(antlr4::tree::ParseTreeListener *listener) override;
    virtual void exitRule(antlr4::tree::ParseTreeListener *listener) override;

    virtual std::any accept(antlr4::tree::ParseTreeVisitor *visitor) override;
   
  };

  Global_fieldsContext* global_fields();

  class  Import_descContext : public antlr4::ParserRuleContext {
  public:
    Import_descContext(antlr4::ParserRuleContext *parent, size_t invokingState);
    virtual size_t getRuleIndex() const override;
    antlr4::tree::TerminalNode *LPAR();
    antlr4::tree::TerminalNode *FUNC();
    antlr4::tree::TerminalNode *RPAR();
    Type_useContext *type_use();
    Func_typeContext *func_type();
    Bind_varContext *bind_var();
    antlr4::tree::TerminalNode *TABLE();
    Table_typeContext *table_type();
    antlr4::tree::TerminalNode *MEMORY();
    Memory_typeContext *memory_type();
    antlr4::tree::TerminalNode *GLOBAL();
    Global_typeContext *global_type();
    antlr4::tree::TerminalNode *TAG();

    virtual void enterRule(antlr4::tree::ParseTreeListener *listener) override;
    virtual void exitRule(antlr4::tree::ParseTreeListener *listener) override;

    virtual std::any accept(antlr4::tree::ParseTreeVisitor *visitor) override;
   
  };

  Import_descContext* import_desc();

  class  SimportContext : public antlr4::ParserRuleContext {
  public:
    SimportContext(antlr4::ParserRuleContext *parent, size_t invokingState);
    virtual size_t getRuleIndex() const override;
    antlr4::tree::TerminalNode *LPAR();
    antlr4::tree::TerminalNode *IMPORT();
    std::vector<NameContext *> name();
    NameContext* name(size_t i);
    Import_descContext *import_desc();
    antlr4::tree::TerminalNode *RPAR();

    virtual void enterRule(antlr4::tree::ParseTreeListener *listener) override;
    virtual void exitRule(antlr4::tree::ParseTreeListener *listener) override;

    virtual std::any accept(antlr4::tree::ParseTreeVisitor *visitor) override;
   
  };

  SimportContext* simport();

  class  Inline_importContext : public antlr4::ParserRuleContext {
  public:
    Inline_importContext(antlr4::ParserRuleContext *parent, size_t invokingState);
    virtual size_t getRuleIndex() const override;
    antlr4::tree::TerminalNode *LPAR();
    antlr4::tree::TerminalNode *IMPORT();
    std::vector<NameContext *> name();
    NameContext* name(size_t i);
    antlr4::tree::TerminalNode *RPAR();

    virtual void enterRule(antlr4::tree::ParseTreeListener *listener) override;
    virtual void exitRule(antlr4::tree::ParseTreeListener *listener) override;

    virtual std::any accept(antlr4::tree::ParseTreeVisitor *visitor) override;
   
  };

  Inline_importContext* inline_import();

  class  Export_descContext : public antlr4::ParserRuleContext {
  public:
    Export_descContext(antlr4::ParserRuleContext *parent, size_t invokingState);
    virtual size_t getRuleIndex() const override;
    antlr4::tree::TerminalNode *LPAR();
    Var_Context *var_();
    antlr4::tree::TerminalNode *RPAR();
    antlr4::tree::TerminalNode *FUNC();
    antlr4::tree::TerminalNode *TABLE();
    antlr4::tree::TerminalNode *MEMORY();
    antlr4::tree::TerminalNode *GLOBAL();
    antlr4::tree::TerminalNode *TAG();

    virtual void enterRule(antlr4::tree::ParseTreeListener *listener) override;
    virtual void exitRule(antlr4::tree::ParseTreeListener *listener) override;

    virtual std::any accept(antlr4::tree::ParseTreeVisitor *visitor) override;
   
  };

  Export_descContext* export_desc();

  class  Export_Context : public antlr4::ParserRuleContext {
  public:
    Export_Context(antlr4::ParserRuleContext *parent, size_t invokingState);
    virtual size_t getRuleIndex() const override;
    antlr4::tree::TerminalNode *LPAR();
    antlr4::tree::TerminalNode *EXPORT();
    NameContext *name();
    Export_descContext *export_desc();
    antlr4::tree::TerminalNode *RPAR();

    virtual void enterRule(antlr4::tree::ParseTreeListener *listener) override;
    virtual void exitRule(antlr4::tree::ParseTreeListener *listener) override;

    virtual std::any accept(antlr4::tree::ParseTreeVisitor *visitor) override;
   
  };

  Export_Context* export_();

  class  Inline_exportContext : public antlr4::ParserRuleContext {
  public:
    Inline_exportContext(antlr4::ParserRuleContext *parent, size_t invokingState);
    virtual size_t getRuleIndex() const override;
    antlr4::tree::TerminalNode *LPAR();
    antlr4::tree::TerminalNode *EXPORT();
    NameContext *name();
    antlr4::tree::TerminalNode *RPAR();

    virtual void enterRule(antlr4::tree::ParseTreeListener *listener) override;
    virtual void exitRule(antlr4::tree::ParseTreeListener *listener) override;

    virtual std::any accept(antlr4::tree::ParseTreeVisitor *visitor) override;
   
  };

  Inline_exportContext* inline_export();

  class  Type_defContext : public antlr4::ParserRuleContext {
  public:
    Type_defContext(antlr4::ParserRuleContext *parent, size_t invokingState);
    virtual size_t getRuleIndex() const override;
    antlr4::tree::TerminalNode *LPAR();
    antlr4::tree::TerminalNode *TYPE();
    Sub_typeContext *sub_type();
    antlr4::tree::TerminalNode *RPAR();
    Bind_varContext *bind_var();

    virtual void enterRule(antlr4::tree::ParseTreeListener *listener) override;
    virtual void exitRule(antlr4::tree::ParseTreeListener *listener) override;

    virtual std::any accept(antlr4::tree::ParseTreeVisitor *visitor) override;
   
  };

  Type_defContext* type_def();

  class  Rec_typeContext : public antlr4::ParserRuleContext {
  public:
    Rec_typeContext(antlr4::ParserRuleContext *parent, size_t invokingState);
    virtual size_t getRuleIndex() const override;
    std::vector<Type_defContext *> type_def();
    Type_defContext* type_def(size_t i);
    antlr4::tree::TerminalNode *LPAR();
    antlr4::tree::TerminalNode *REC();
    antlr4::tree::TerminalNode *RPAR();

    virtual void enterRule(antlr4::tree::ParseTreeListener *listener) override;
    virtual void exitRule(antlr4::tree::ParseTreeListener *listener) override;

    virtual std::any accept(antlr4::tree::ParseTreeVisitor *visitor) override;
   
  };

  Rec_typeContext* rec_type();

  class  Type_Context : public antlr4::ParserRuleContext {
  public:
    Type_Context(antlr4::ParserRuleContext *parent, size_t invokingState);
    virtual size_t getRuleIndex() const override;
    Rec_typeContext *rec_type();

    virtual void enterRule(antlr4::tree::ParseTreeListener *listener) override;
    virtual void exitRule(antlr4::tree::ParseTreeListener *listener) override;

    virtual std::any accept(antlr4::tree::ParseTreeVisitor *visitor) override;
   
  };

  Type_Context* type_();

  class  Start_Context : public antlr4::ParserRuleContext {
  public:
    Start_Context(antlr4::ParserRuleContext *parent, size_t invokingState);
    virtual size_t getRuleIndex() const override;
    antlr4::tree::TerminalNode *LPAR();
    antlr4::tree::TerminalNode *START_();
    Var_Context *var_();
    antlr4::tree::TerminalNode *RPAR();

    virtual void enterRule(antlr4::tree::ParseTreeListener *listener) override;
    virtual void exitRule(antlr4::tree::ParseTreeListener *listener) override;

    virtual std::any accept(antlr4::tree::ParseTreeVisitor *visitor) override;
   
  };

  Start_Context* start_();

  class  Module_fieldContext : public antlr4::ParserRuleContext {
  public:
    Module_fieldContext(antlr4::ParserRuleContext *parent, size_t invokingState);
    virtual size_t getRuleIndex() const override;
    std::vector<Type_Context *> type_();
    Type_Context* type_(size_t i);
    std::vector<SglobalContext *> sglobal();
    SglobalContext* sglobal(size_t i);
    std::vector<TableContext *> table();
    TableContext* table(size_t i);
    std::vector<MemoryContext *> memory();
    MemoryContext* memory(size_t i);
    std::vector<Func_Context *> func_();
    Func_Context* func_(size_t i);
    std::vector<ElemContext *> elem();
    ElemContext* elem(size_t i);
    std::vector<DataContext *> data();
    DataContext* data(size_t i);
    std::vector<Start_Context *> start_();
    Start_Context* start_(size_t i);
    std::vector<SimportContext *> simport();
    SimportContext* simport(size_t i);
    std::vector<Export_Context *> export_();
    Export_Context* export_(size_t i);
    std::vector<TagContext *> tag();
    TagContext* tag(size_t i);

    virtual void enterRule(antlr4::tree::ParseTreeListener *listener) override;
    virtual void exitRule(antlr4::tree::ParseTreeListener *listener) override;

    virtual std::any accept(antlr4::tree::ParseTreeVisitor *visitor) override;
   
  };

  Module_fieldContext* module_field();

  class  Module_Context : public antlr4::ParserRuleContext {
  public:
    Module_Context(antlr4::ParserRuleContext *parent, size_t invokingState);
    virtual size_t getRuleIndex() const override;
    antlr4::tree::TerminalNode *LPAR();
    antlr4::tree::TerminalNode *MODULE();
    antlr4::tree::TerminalNode *RPAR();
    antlr4::tree::TerminalNode *VAR();
    std::vector<Module_fieldContext *> module_field();
    Module_fieldContext* module_field(size_t i);

    virtual void enterRule(antlr4::tree::ParseTreeListener *listener) override;
    virtual void exitRule(antlr4::tree::ParseTreeListener *listener) override;

    virtual std::any accept(antlr4::tree::ParseTreeVisitor *visitor) override;
   
  };

  Module_Context* module_();

  class  Inline_moduleContext : public antlr4::ParserRuleContext {
  public:
    Inline_moduleContext(antlr4::ParserRuleContext *parent, size_t invokingState);
    virtual size_t getRuleIndex() const override;
    Module_fieldContext *module_field();

    virtual void enterRule(antlr4::tree::ParseTreeListener *listener) override;
    virtual void exitRule(antlr4::tree::ParseTreeListener *listener) override;

    virtual std::any accept(antlr4::tree::ParseTreeVisitor *visitor) override;
   
  };

  Inline_moduleContext* inline_module();

  class  Script_moduleContext : public antlr4::ParserRuleContext {
  public:
    Script_moduleContext(antlr4::ParserRuleContext *parent, size_t invokingState);
    virtual size_t getRuleIndex() const override;
    Module_Context *module_();
    antlr4::tree::TerminalNode *LPAR();
    antlr4::tree::TerminalNode *MODULE();
    antlr4::tree::TerminalNode *RPAR();
    antlr4::tree::TerminalNode *BIN();
    antlr4::tree::TerminalNode *QUOTE();
    antlr4::tree::TerminalNode *VAR();
    std::vector<antlr4::tree::TerminalNode *> STRING_();
    antlr4::tree::TerminalNode* STRING_(size_t i);

    virtual void enterRule(antlr4::tree::ParseTreeListener *listener) override;
    virtual void exitRule(antlr4::tree::ParseTreeListener *listener) override;

    virtual std::any accept(antlr4::tree::ParseTreeVisitor *visitor) override;
   
  };

  Script_moduleContext* script_module();

  class  Action_Context : public antlr4::ParserRuleContext {
  public:
    Action_Context(antlr4::ParserRuleContext *parent, size_t invokingState);
    virtual size_t getRuleIndex() const override;
    antlr4::tree::TerminalNode *LPAR();
    antlr4::tree::TerminalNode *INVOKE();
    NameContext *name();
    Literal_listContext *literal_list();
    antlr4::tree::TerminalNode *RPAR();
    antlr4::tree::TerminalNode *VAR();
    antlr4::tree::TerminalNode *GET();

    virtual void enterRule(antlr4::tree::ParseTreeListener *listener) override;
    virtual void exitRule(antlr4::tree::ParseTreeListener *listener) override;

    virtual std::any accept(antlr4::tree::ParseTreeVisitor *visitor) override;
   
  };

  Action_Context* action_();

  class  AssertionContext : public antlr4::ParserRuleContext {
  public:
    AssertionContext(antlr4::ParserRuleContext *parent, size_t invokingState);
    virtual size_t getRuleIndex() const override;
    antlr4::tree::TerminalNode *LPAR();
    antlr4::tree::TerminalNode *ASSERT_MALFORMED();
    Script_moduleContext *script_module();
    antlr4::tree::TerminalNode *STRING_();
    antlr4::tree::TerminalNode *RPAR();
    antlr4::tree::TerminalNode *ASSERT_INVALID();
    antlr4::tree::TerminalNode *ASSERT_UNLINKABLE();
    antlr4::tree::TerminalNode *ASSERT_TRAP();
    antlr4::tree::TerminalNode *ASSERT_RETURN();
    Action_Context *action_();
    std::vector<ResultContext *> result();
    ResultContext* result(size_t i);
    antlr4::tree::TerminalNode *ASSERT_EXCEPTION();
    antlr4::tree::TerminalNode *ASSERT_EXHAUSTION();

    virtual void enterRule(antlr4::tree::ParseTreeListener *listener) override;
    virtual void exitRule(antlr4::tree::ParseTreeListener *listener) override;

    virtual std::any accept(antlr4::tree::ParseTreeVisitor *visitor) override;
   
  };

  AssertionContext* assertion();

  class  CmdContext : public antlr4::ParserRuleContext {
  public:
    CmdContext(antlr4::ParserRuleContext *parent, size_t invokingState);
    virtual size_t getRuleIndex() const override;
    Action_Context *action_();
    AssertionContext *assertion();
    Script_moduleContext *script_module();
    antlr4::tree::TerminalNode *LPAR();
    antlr4::tree::TerminalNode *REGISTER();
    NameContext *name();
    antlr4::tree::TerminalNode *RPAR();
    antlr4::tree::TerminalNode *VAR();
    antlr4::tree::TerminalNode *THREAD();
    Shared_cmd_listContext *shared_cmd_list();
    antlr4::tree::TerminalNode *WAIT();
    MetaContext *meta();

    virtual void enterRule(antlr4::tree::ParseTreeListener *listener) override;
    virtual void exitRule(antlr4::tree::ParseTreeListener *listener) override;

    virtual std::any accept(antlr4::tree::ParseTreeVisitor *visitor) override;
   
  };

  CmdContext* cmd();

  class  Shared_cmd_listContext : public antlr4::ParserRuleContext {
  public:
    Shared_cmd_listContext(antlr4::ParserRuleContext *parent, size_t invokingState);
    virtual size_t getRuleIndex() const override;
    std::vector<antlr4::tree::TerminalNode *> LPAR();
    antlr4::tree::TerminalNode* LPAR(size_t i);
    std::vector<antlr4::tree::TerminalNode *> SHARED();
    antlr4::tree::TerminalNode* SHARED(size_t i);
    std::vector<antlr4::tree::TerminalNode *> MODULE();
    antlr4::tree::TerminalNode* MODULE(size_t i);
    std::vector<antlr4::tree::TerminalNode *> VAR();
    antlr4::tree::TerminalNode* VAR(size_t i);
    std::vector<antlr4::tree::TerminalNode *> RPAR();
    antlr4::tree::TerminalNode* RPAR(size_t i);
    std::vector<CmdContext *> cmd();
    CmdContext* cmd(size_t i);

    virtual void enterRule(antlr4::tree::ParseTreeListener *listener) override;
    virtual void exitRule(antlr4::tree::ParseTreeListener *listener) override;

    virtual std::any accept(antlr4::tree::ParseTreeVisitor *visitor) override;
   
  };

  Shared_cmd_listContext* shared_cmd_list();

  class  MetaContext : public antlr4::ParserRuleContext {
  public:
    MetaContext(antlr4::ParserRuleContext *parent, size_t invokingState);
    virtual size_t getRuleIndex() const override;
    antlr4::tree::TerminalNode *LPAR();
    antlr4::tree::TerminalNode *SCRIPT();
    antlr4::tree::TerminalNode *RPAR();
    antlr4::tree::TerminalNode *VAR();
    std::vector<CmdContext *> cmd();
    CmdContext* cmd(size_t i);
    antlr4::tree::TerminalNode *INPUT();
    antlr4::tree::TerminalNode *STRING_();
    antlr4::tree::TerminalNode *OUTPUT();

    virtual void enterRule(antlr4::tree::ParseTreeListener *listener) override;
    virtual void exitRule(antlr4::tree::ParseTreeListener *listener) override;

    virtual std::any accept(antlr4::tree::ParseTreeVisitor *visitor) override;
   
  };

  MetaContext* meta();

  class  Literal_numContext : public antlr4::ParserRuleContext {
  public:
    Literal_numContext(antlr4::ParserRuleContext *parent, size_t invokingState);
    virtual size_t getRuleIndex() const override;
    antlr4::tree::TerminalNode *LPAR();
    antlr4::tree::TerminalNode *CONST();
    NumContext *num();
    antlr4::tree::TerminalNode *RPAR();

    virtual void enterRule(antlr4::tree::ParseTreeListener *listener) override;
    virtual void exitRule(antlr4::tree::ParseTreeListener *listener) override;

    virtual std::any accept(antlr4::tree::ParseTreeVisitor *visitor) override;
   
  };

  Literal_numContext* literal_num();

  class  Literal_vecContext : public antlr4::ParserRuleContext {
  public:
    Literal_vecContext(antlr4::ParserRuleContext *parent, size_t invokingState);
    virtual size_t getRuleIndex() const override;
    antlr4::tree::TerminalNode *LPAR();
    antlr4::tree::TerminalNode *VEC_CONST();
    antlr4::tree::TerminalNode *VEC_SHAPE();
    antlr4::tree::TerminalNode *RPAR();
    std::vector<NumContext *> num();
    NumContext* num(size_t i);

    virtual void enterRule(antlr4::tree::ParseTreeListener *listener) override;
    virtual void exitRule(antlr4::tree::ParseTreeListener *listener) override;

    virtual std::any accept(antlr4::tree::ParseTreeVisitor *visitor) override;
   
  };

  Literal_vecContext* literal_vec();

  class  Literal_refContext : public antlr4::ParserRuleContext {
  public:
    Literal_refContext(antlr4::ParserRuleContext *parent, size_t invokingState);
    virtual size_t getRuleIndex() const override;
    antlr4::tree::TerminalNode *LPAR();
    antlr4::tree::TerminalNode *REF_NULL();
    Heap_typeContext *heap_type();
    antlr4::tree::TerminalNode *RPAR();
    antlr4::tree::TerminalNode *REF_HOST();
    antlr4::tree::TerminalNode *NAT();
    antlr4::tree::TerminalNode *REF_EXTERN();

    virtual void enterRule(antlr4::tree::ParseTreeListener *listener) override;
    virtual void exitRule(antlr4::tree::ParseTreeListener *listener) override;

    virtual std::any accept(antlr4::tree::ParseTreeVisitor *visitor) override;
   
  };

  Literal_refContext* literal_ref();

  class  LiteralContext : public antlr4::ParserRuleContext {
  public:
    LiteralContext(antlr4::ParserRuleContext *parent, size_t invokingState);
    virtual size_t getRuleIndex() const override;
    Literal_numContext *literal_num();
    Literal_vecContext *literal_vec();
    Literal_refContext *literal_ref();

    virtual void enterRule(antlr4::tree::ParseTreeListener *listener) override;
    virtual void exitRule(antlr4::tree::ParseTreeListener *listener) override;

    virtual std::any accept(antlr4::tree::ParseTreeVisitor *visitor) override;
   
  };

  LiteralContext* literal();

  class  Literal_listContext : public antlr4::ParserRuleContext {
  public:
    Literal_listContext(antlr4::ParserRuleContext *parent, size_t invokingState);
    virtual size_t getRuleIndex() const override;
    std::vector<LiteralContext *> literal();
    LiteralContext* literal(size_t i);

    virtual void enterRule(antlr4::tree::ParseTreeListener *listener) override;
    virtual void exitRule(antlr4::tree::ParseTreeListener *listener) override;

    virtual std::any accept(antlr4::tree::ParseTreeVisitor *visitor) override;
   
  };

  Literal_listContext* literal_list();

  class  NumpatContext : public antlr4::ParserRuleContext {
  public:
    NumpatContext(antlr4::ParserRuleContext *parent, size_t invokingState);
    virtual size_t getRuleIndex() const override;
    NumContext *num();
    antlr4::tree::TerminalNode *NAN_();

    virtual void enterRule(antlr4::tree::ParseTreeListener *listener) override;
    virtual void exitRule(antlr4::tree::ParseTreeListener *listener) override;

    virtual std::any accept(antlr4::tree::ParseTreeVisitor *visitor) override;
   
  };

  NumpatContext* numpat();

  class  ResultContext : public antlr4::ParserRuleContext {
  public:
    ResultContext(antlr4::ParserRuleContext *parent, size_t invokingState);
    virtual size_t getRuleIndex() const override;
    Literal_numContext *literal_num();
    Literal_refContext *literal_ref();
    antlr4::tree::TerminalNode *LPAR();
    antlr4::tree::TerminalNode *CONST();
    antlr4::tree::TerminalNode *NAN_();
    antlr4::tree::TerminalNode *RPAR();
    antlr4::tree::TerminalNode *REF_FUNC();
    antlr4::tree::TerminalNode *REF();
    antlr4::tree::TerminalNode *REF_EQ();
    antlr4::tree::TerminalNode *REF_I31();
    antlr4::tree::TerminalNode *REF_STRUCT();
    antlr4::tree::TerminalNode *REF_ARRAY();
    antlr4::tree::TerminalNode *REF_NULL();
    antlr4::tree::TerminalNode *REF_EXTERN();
    antlr4::tree::TerminalNode *VEC_CONST();
    antlr4::tree::TerminalNode *VEC_SHAPE();
    std::vector<NumpatContext *> numpat();
    NumpatContext* numpat(size_t i);
    antlr4::tree::TerminalNode *EITHER();
    std::vector<ResultContext *> result();
    ResultContext* result(size_t i);

    virtual void enterRule(antlr4::tree::ParseTreeListener *listener) override;
    virtual void exitRule(antlr4::tree::ParseTreeListener *listener) override;

    virtual std::any accept(antlr4::tree::ParseTreeVisitor *visitor) override;
   
  };

  ResultContext* result();

  class  ScriptContext : public antlr4::ParserRuleContext {
  public:
    ScriptContext(antlr4::ParserRuleContext *parent, size_t invokingState);
    virtual size_t getRuleIndex() const override;
    antlr4::tree::TerminalNode *EOF();
    std::vector<CmdContext *> cmd();
    CmdContext* cmd(size_t i);
    std::vector<Module_fieldContext *> module_field();
    Module_fieldContext* module_field(size_t i);

    virtual void enterRule(antlr4::tree::ParseTreeListener *listener) override;
    virtual void exitRule(antlr4::tree::ParseTreeListener *listener) override;

    virtual std::any accept(antlr4::tree::ParseTreeVisitor *visitor) override;
   
  };

  ScriptContext* script();

  class  ModuleContext : public antlr4::ParserRuleContext {
  public:
    ModuleContext(antlr4::ParserRuleContext *parent, size_t invokingState);
    virtual size_t getRuleIndex() const override;
    Module_Context *module_();
    antlr4::tree::TerminalNode *EOF();
    std::vector<Module_fieldContext *> module_field();
    Module_fieldContext* module_field(size_t i);

    virtual void enterRule(antlr4::tree::ParseTreeListener *listener) override;
    virtual void exitRule(antlr4::tree::ParseTreeListener *listener) override;

    virtual std::any accept(antlr4::tree::ParseTreeVisitor *visitor) override;
   
  };

  ModuleContext* module();


  // By default the static state used to implement the parser is lazily initialized during the first
  // call to the constructor. You can call this function if you wish to initialize the static state
  // ahead of time.
  static void initialize();

private:
};

