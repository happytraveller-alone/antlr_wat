
// Generated from WatParser.g4 by ANTLR 4.13.1

#pragma once


#include "antlr4-runtime.h"




class  WatParser : public antlr4::Parser {
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

  enum {
    RuleValue = 0, RuleName = 1, RuleValue_type = 2, RuleElem_type = 3, 
    RuleGlobal_type = 4, RuleDef_type = 5, RuleFunc_type = 6, RuleTable_type = 7, 
    RuleMemory_type = 8, RuleType_use = 9, RuleLiteral = 10, RuleVar_ = 11, 
    RuleBind_var = 12, RuleInstr = 13, RulePlain_instr = 14, RuleCall_instr = 15, 
    RuleCall_instr_params = 16, RuleCall_instr_instr = 17, RuleCall_instr_params_instr = 18, 
    RuleCall_instr_results_instr = 19, RuleBlock_instr = 20, RuleBlock_type = 21, 
    RuleBlock = 22, RuleExpr = 23, RuleExpr1 = 24, RuleCall_expr_type = 25, 
    RuleCall_expr_params = 26, RuleCall_expr_results = 27, RuleIf_block = 28, 
    RuleInstr_list = 29, RuleConst_expr = 30, RuleFunc_ = 31, RuleFunc_fields = 32, 
    RuleFunc_fields_import = 33, RuleFunc_fields_import_result = 34, RuleFunc_fields_body = 35, 
    RuleFunc_result_body = 36, RuleFunc_body = 37, RuleOffset = 38, RuleElem = 39, 
    RuleTable = 40, RuleTable_fields = 41, RuleData = 42, RuleMemory = 43, 
    RuleMemory_fields = 44, RuleSglobal = 45, RuleGlobal_fields = 46, RuleImport_desc = 47, 
    RuleSimport = 48, RuleInline_import = 49, RuleExport_desc = 50, RuleExport_ = 51, 
    RuleInline_export = 52, RuleType_ = 53, RuleType_def = 54, RuleStart_ = 55, 
    RuleModule_field = 56, RuleModule_ = 57, RuleScript_module = 58, RuleAction_ = 59, 
    RuleAssertion = 60, RuleCmd = 61, RuleMeta = 62, RuleWconst = 63, RuleConst_list = 64, 
    RuleScript = 65, RuleModule = 66
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
  class Value_typeContext;
  class Elem_typeContext;
  class Global_typeContext;
  class Def_typeContext;
  class Func_typeContext;
  class Table_typeContext;
  class Memory_typeContext;
  class Type_useContext;
  class LiteralContext;
  class Var_Context;
  class Bind_varContext;
  class InstrContext;
  class Plain_instrContext;
  class Call_instrContext;
  class Call_instr_paramsContext;
  class Call_instr_instrContext;
  class Call_instr_params_instrContext;
  class Call_instr_results_instrContext;
  class Block_instrContext;
  class Block_typeContext;
  class BlockContext;
  class ExprContext;
  class Expr1Context;
  class Call_expr_typeContext;
  class Call_expr_paramsContext;
  class Call_expr_resultsContext;
  class If_blockContext;
  class Instr_listContext;
  class Const_exprContext;
  class Func_Context;
  class Func_fieldsContext;
  class Func_fields_importContext;
  class Func_fields_import_resultContext;
  class Func_fields_bodyContext;
  class Func_result_bodyContext;
  class Func_bodyContext;
  class OffsetContext;
  class ElemContext;
  class TableContext;
  class Table_fieldsContext;
  class DataContext;
  class MemoryContext;
  class Memory_fieldsContext;
  class SglobalContext;
  class Global_fieldsContext;
  class Import_descContext;
  class SimportContext;
  class Inline_importContext;
  class Export_descContext;
  class Export_Context;
  class Inline_exportContext;
  class Type_Context;
  class Type_defContext;
  class Start_Context;
  class Module_fieldContext;
  class Module_Context;
  class Script_moduleContext;
  class Action_Context;
  class AssertionContext;
  class CmdContext;
  class MetaContext;
  class WconstContext;
  class Const_listContext;
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

  class  Value_typeContext : public antlr4::ParserRuleContext {
  public:
    Value_typeContext(antlr4::ParserRuleContext *parent, size_t invokingState);
    virtual size_t getRuleIndex() const override;
    antlr4::tree::TerminalNode *VALUE_TYPE();

    virtual void enterRule(antlr4::tree::ParseTreeListener *listener) override;
    virtual void exitRule(antlr4::tree::ParseTreeListener *listener) override;

    virtual std::any accept(antlr4::tree::ParseTreeVisitor *visitor) override;
   
  };

  Value_typeContext* value_type();

  class  Elem_typeContext : public antlr4::ParserRuleContext {
  public:
    Elem_typeContext(antlr4::ParserRuleContext *parent, size_t invokingState);
    virtual size_t getRuleIndex() const override;
    antlr4::tree::TerminalNode *FUNCREF();

    virtual void enterRule(antlr4::tree::ParseTreeListener *listener) override;
    virtual void exitRule(antlr4::tree::ParseTreeListener *listener) override;

    virtual std::any accept(antlr4::tree::ParseTreeVisitor *visitor) override;
   
  };

  Elem_typeContext* elem_type();

  class  Global_typeContext : public antlr4::ParserRuleContext {
  public:
    Global_typeContext(antlr4::ParserRuleContext *parent, size_t invokingState);
    virtual size_t getRuleIndex() const override;
    Value_typeContext *value_type();
    antlr4::tree::TerminalNode *LPAR();
    antlr4::tree::TerminalNode *MUT();
    antlr4::tree::TerminalNode *RPAR();

    virtual void enterRule(antlr4::tree::ParseTreeListener *listener) override;
    virtual void exitRule(antlr4::tree::ParseTreeListener *listener) override;

    virtual std::any accept(antlr4::tree::ParseTreeVisitor *visitor) override;
   
  };

  Global_typeContext* global_type();

  class  Def_typeContext : public antlr4::ParserRuleContext {
  public:
    Def_typeContext(antlr4::ParserRuleContext *parent, size_t invokingState);
    virtual size_t getRuleIndex() const override;
    antlr4::tree::TerminalNode *LPAR();
    antlr4::tree::TerminalNode *FUNC();
    Func_typeContext *func_type();
    antlr4::tree::TerminalNode *RPAR();

    virtual void enterRule(antlr4::tree::ParseTreeListener *listener) override;
    virtual void exitRule(antlr4::tree::ParseTreeListener *listener) override;

    virtual std::any accept(antlr4::tree::ParseTreeVisitor *visitor) override;
   
  };

  Def_typeContext* def_type();

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
    std::vector<Value_typeContext *> value_type();
    Value_typeContext* value_type(size_t i);

    virtual void enterRule(antlr4::tree::ParseTreeListener *listener) override;
    virtual void exitRule(antlr4::tree::ParseTreeListener *listener) override;

    virtual std::any accept(antlr4::tree::ParseTreeVisitor *visitor) override;
   
  };

  Func_typeContext* func_type();

  class  Table_typeContext : public antlr4::ParserRuleContext {
  public:
    Table_typeContext(antlr4::ParserRuleContext *parent, size_t invokingState);
    virtual size_t getRuleIndex() const override;
    std::vector<antlr4::tree::TerminalNode *> NAT();
    antlr4::tree::TerminalNode* NAT(size_t i);
    Elem_typeContext *elem_type();

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

  class  LiteralContext : public antlr4::ParserRuleContext {
  public:
    LiteralContext(antlr4::ParserRuleContext *parent, size_t invokingState);
    virtual size_t getRuleIndex() const override;
    antlr4::tree::TerminalNode *NAT();
    antlr4::tree::TerminalNode *INT();
    antlr4::tree::TerminalNode *FLOAT();

    virtual void enterRule(antlr4::tree::ParseTreeListener *listener) override;
    virtual void exitRule(antlr4::tree::ParseTreeListener *listener) override;

    virtual std::any accept(antlr4::tree::ParseTreeVisitor *visitor) override;
   
  };

  LiteralContext* literal();

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

  class  InstrContext : public antlr4::ParserRuleContext {
  public:
    InstrContext(antlr4::ParserRuleContext *parent, size_t invokingState);
    virtual size_t getRuleIndex() const override;
    Plain_instrContext *plain_instr();
    Call_instr_instrContext *call_instr_instr();
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
    antlr4::tree::TerminalNode *RETURN();
    antlr4::tree::TerminalNode *CALL();
    antlr4::tree::TerminalNode *LOCAL_GET();
    antlr4::tree::TerminalNode *LOCAL_SET();
    antlr4::tree::TerminalNode *LOCAL_TEE();
    antlr4::tree::TerminalNode *GLOBAL_GET();
    antlr4::tree::TerminalNode *GLOBAL_SET();
    antlr4::tree::TerminalNode *LOAD();
    antlr4::tree::TerminalNode *OFFSET_EQ_NAT();
    antlr4::tree::TerminalNode *ALIGN_EQ_NAT();
    antlr4::tree::TerminalNode *STORE();
    antlr4::tree::TerminalNode *MEMORY_SIZE();
    antlr4::tree::TerminalNode *MEMORY_GROW();
    antlr4::tree::TerminalNode *CONST();
    LiteralContext *literal();
    antlr4::tree::TerminalNode *TEST();
    antlr4::tree::TerminalNode *COMPARE();
    antlr4::tree::TerminalNode *UNARY();
    antlr4::tree::TerminalNode *BINARY();
    antlr4::tree::TerminalNode *CONVERT();

    virtual void enterRule(antlr4::tree::ParseTreeListener *listener) override;
    virtual void exitRule(antlr4::tree::ParseTreeListener *listener) override;

    virtual std::any accept(antlr4::tree::ParseTreeVisitor *visitor) override;
   
  };

  Plain_instrContext* plain_instr();

  class  Call_instrContext : public antlr4::ParserRuleContext {
  public:
    Call_instrContext(antlr4::ParserRuleContext *parent, size_t invokingState);
    virtual size_t getRuleIndex() const override;
    antlr4::tree::TerminalNode *CALL_INDIRECT();
    Call_instr_paramsContext *call_instr_params();
    Type_useContext *type_use();

    virtual void enterRule(antlr4::tree::ParseTreeListener *listener) override;
    virtual void exitRule(antlr4::tree::ParseTreeListener *listener) override;

    virtual std::any accept(antlr4::tree::ParseTreeVisitor *visitor) override;
   
  };

  Call_instrContext* call_instr();

  class  Call_instr_paramsContext : public antlr4::ParserRuleContext {
  public:
    Call_instr_paramsContext(antlr4::ParserRuleContext *parent, size_t invokingState);
    virtual size_t getRuleIndex() const override;
    std::vector<antlr4::tree::TerminalNode *> LPAR();
    antlr4::tree::TerminalNode* LPAR(size_t i);
    std::vector<antlr4::tree::TerminalNode *> PARAM();
    antlr4::tree::TerminalNode* PARAM(size_t i);
    std::vector<antlr4::tree::TerminalNode *> RPAR();
    antlr4::tree::TerminalNode* RPAR(size_t i);
    std::vector<antlr4::tree::TerminalNode *> RESULT();
    antlr4::tree::TerminalNode* RESULT(size_t i);
    std::vector<Value_typeContext *> value_type();
    Value_typeContext* value_type(size_t i);

    virtual void enterRule(antlr4::tree::ParseTreeListener *listener) override;
    virtual void exitRule(antlr4::tree::ParseTreeListener *listener) override;

    virtual std::any accept(antlr4::tree::ParseTreeVisitor *visitor) override;
   
  };

  Call_instr_paramsContext* call_instr_params();

  class  Call_instr_instrContext : public antlr4::ParserRuleContext {
  public:
    Call_instr_instrContext(antlr4::ParserRuleContext *parent, size_t invokingState);
    virtual size_t getRuleIndex() const override;
    antlr4::tree::TerminalNode *CALL_INDIRECT();
    Call_instr_params_instrContext *call_instr_params_instr();
    Type_useContext *type_use();

    virtual void enterRule(antlr4::tree::ParseTreeListener *listener) override;
    virtual void exitRule(antlr4::tree::ParseTreeListener *listener) override;

    virtual std::any accept(antlr4::tree::ParseTreeVisitor *visitor) override;
   
  };

  Call_instr_instrContext* call_instr_instr();

  class  Call_instr_params_instrContext : public antlr4::ParserRuleContext {
  public:
    Call_instr_params_instrContext(antlr4::ParserRuleContext *parent, size_t invokingState);
    virtual size_t getRuleIndex() const override;
    Call_instr_results_instrContext *call_instr_results_instr();
    std::vector<antlr4::tree::TerminalNode *> LPAR();
    antlr4::tree::TerminalNode* LPAR(size_t i);
    std::vector<antlr4::tree::TerminalNode *> PARAM();
    antlr4::tree::TerminalNode* PARAM(size_t i);
    std::vector<antlr4::tree::TerminalNode *> RPAR();
    antlr4::tree::TerminalNode* RPAR(size_t i);
    std::vector<Value_typeContext *> value_type();
    Value_typeContext* value_type(size_t i);

    virtual void enterRule(antlr4::tree::ParseTreeListener *listener) override;
    virtual void exitRule(antlr4::tree::ParseTreeListener *listener) override;

    virtual std::any accept(antlr4::tree::ParseTreeVisitor *visitor) override;
   
  };

  Call_instr_params_instrContext* call_instr_params_instr();

  class  Call_instr_results_instrContext : public antlr4::ParserRuleContext {
  public:
    Call_instr_results_instrContext(antlr4::ParserRuleContext *parent, size_t invokingState);
    virtual size_t getRuleIndex() const override;
    InstrContext *instr();
    std::vector<antlr4::tree::TerminalNode *> LPAR();
    antlr4::tree::TerminalNode* LPAR(size_t i);
    std::vector<antlr4::tree::TerminalNode *> RESULT();
    antlr4::tree::TerminalNode* RESULT(size_t i);
    std::vector<antlr4::tree::TerminalNode *> RPAR();
    antlr4::tree::TerminalNode* RPAR(size_t i);
    std::vector<Value_typeContext *> value_type();
    Value_typeContext* value_type(size_t i);

    virtual void enterRule(antlr4::tree::ParseTreeListener *listener) override;
    virtual void exitRule(antlr4::tree::ParseTreeListener *listener) override;

    virtual std::any accept(antlr4::tree::ParseTreeVisitor *visitor) override;
   
  };

  Call_instr_results_instrContext* call_instr_results_instr();

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

    virtual void enterRule(antlr4::tree::ParseTreeListener *listener) override;
    virtual void exitRule(antlr4::tree::ParseTreeListener *listener) override;

    virtual std::any accept(antlr4::tree::ParseTreeVisitor *visitor) override;
   
  };

  Block_instrContext* block_instr();

  class  Block_typeContext : public antlr4::ParserRuleContext {
  public:
    Block_typeContext(antlr4::ParserRuleContext *parent, size_t invokingState);
    virtual size_t getRuleIndex() const override;
    antlr4::tree::TerminalNode *LPAR();
    antlr4::tree::TerminalNode *RESULT();
    Value_typeContext *value_type();
    antlr4::tree::TerminalNode *RPAR();

    virtual void enterRule(antlr4::tree::ParseTreeListener *listener) override;
    virtual void exitRule(antlr4::tree::ParseTreeListener *listener) override;

    virtual std::any accept(antlr4::tree::ParseTreeVisitor *visitor) override;
   
  };

  Block_typeContext* block_type();

  class  BlockContext : public antlr4::ParserRuleContext {
  public:
    BlockContext(antlr4::ParserRuleContext *parent, size_t invokingState);
    virtual size_t getRuleIndex() const override;
    Instr_listContext *instr_list();
    Block_typeContext *block_type();

    virtual void enterRule(antlr4::tree::ParseTreeListener *listener) override;
    virtual void exitRule(antlr4::tree::ParseTreeListener *listener) override;

    virtual std::any accept(antlr4::tree::ParseTreeVisitor *visitor) override;
   
  };

  BlockContext* block();

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
    antlr4::tree::TerminalNode *CALL_INDIRECT();
    Call_expr_typeContext *call_expr_type();
    antlr4::tree::TerminalNode *BLOCK();
    BlockContext *block();
    Bind_varContext *bind_var();
    antlr4::tree::TerminalNode *LOOP();
    antlr4::tree::TerminalNode *IF();
    If_blockContext *if_block();

    virtual void enterRule(antlr4::tree::ParseTreeListener *listener) override;
    virtual void exitRule(antlr4::tree::ParseTreeListener *listener) override;

    virtual std::any accept(antlr4::tree::ParseTreeVisitor *visitor) override;
   
  };

  Expr1Context* expr1();

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
    std::vector<Value_typeContext *> value_type();
    Value_typeContext* value_type(size_t i);

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
    std::vector<Value_typeContext *> value_type();
    Value_typeContext* value_type(size_t i);

    virtual void enterRule(antlr4::tree::ParseTreeListener *listener) override;
    virtual void exitRule(antlr4::tree::ParseTreeListener *listener) override;

    virtual std::any accept(antlr4::tree::ParseTreeVisitor *visitor) override;
   
  };

  Call_expr_resultsContext* call_expr_results();

  class  If_blockContext : public antlr4::ParserRuleContext {
  public:
    If_blockContext(antlr4::ParserRuleContext *parent, size_t invokingState);
    virtual size_t getRuleIndex() const override;
    Block_typeContext *block_type();
    If_blockContext *if_block();
    std::vector<antlr4::tree::TerminalNode *> LPAR();
    antlr4::tree::TerminalNode* LPAR(size_t i);
    antlr4::tree::TerminalNode *THEN();
    std::vector<Instr_listContext *> instr_list();
    Instr_listContext* instr_list(size_t i);
    std::vector<antlr4::tree::TerminalNode *> RPAR();
    antlr4::tree::TerminalNode* RPAR(size_t i);
    std::vector<ExprContext *> expr();
    ExprContext* expr(size_t i);
    antlr4::tree::TerminalNode *ELSE();

    virtual void enterRule(antlr4::tree::ParseTreeListener *listener) override;
    virtual void exitRule(antlr4::tree::ParseTreeListener *listener) override;

    virtual std::any accept(antlr4::tree::ParseTreeVisitor *visitor) override;
   
  };

  If_blockContext* if_block();

  class  Instr_listContext : public antlr4::ParserRuleContext {
  public:
    Instr_listContext(antlr4::ParserRuleContext *parent, size_t invokingState);
    virtual size_t getRuleIndex() const override;
    std::vector<InstrContext *> instr();
    InstrContext* instr(size_t i);
    Call_instrContext *call_instr();

    virtual void enterRule(antlr4::tree::ParseTreeListener *listener) override;
    virtual void exitRule(antlr4::tree::ParseTreeListener *listener) override;

    virtual std::any accept(antlr4::tree::ParseTreeVisitor *visitor) override;
   
  };

  Instr_listContext* instr_list();

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
    antlr4::tree::TerminalNode *LPAR();
    antlr4::tree::TerminalNode *PARAM();
    antlr4::tree::TerminalNode *RPAR();
    Bind_varContext *bind_var();
    std::vector<Value_typeContext *> value_type();
    Value_typeContext* value_type(size_t i);

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
    std::vector<Value_typeContext *> value_type();
    Value_typeContext* value_type(size_t i);

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
    std::vector<Value_typeContext *> value_type();
    Value_typeContext* value_type(size_t i);

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
    std::vector<Value_typeContext *> value_type();
    Value_typeContext* value_type(size_t i);

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
    std::vector<Value_typeContext *> value_type();
    Value_typeContext* value_type(size_t i);

    virtual void enterRule(antlr4::tree::ParseTreeListener *listener) override;
    virtual void exitRule(antlr4::tree::ParseTreeListener *listener) override;

    virtual std::any accept(antlr4::tree::ParseTreeVisitor *visitor) override;
   
  };

  Func_bodyContext* func_body();

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

  class  ElemContext : public antlr4::ParserRuleContext {
  public:
    ElemContext(antlr4::ParserRuleContext *parent, size_t invokingState);
    virtual size_t getRuleIndex() const override;
    antlr4::tree::TerminalNode *LPAR();
    antlr4::tree::TerminalNode *ELEM();
    OffsetContext *offset();
    antlr4::tree::TerminalNode *RPAR();
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
    Inline_importContext *inline_import();
    Inline_exportContext *inline_export();
    Table_fieldsContext *table_fields();
    Elem_typeContext *elem_type();
    antlr4::tree::TerminalNode *LPAR();
    antlr4::tree::TerminalNode *ELEM();
    antlr4::tree::TerminalNode *RPAR();
    std::vector<Var_Context *> var_();
    Var_Context* var_(size_t i);

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
    OffsetContext *offset();
    antlr4::tree::TerminalNode *RPAR();
    Var_Context *var_();
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
    Type_useContext *type_use();
    antlr4::tree::TerminalNode *RPAR();
    Bind_varContext *bind_var();
    Func_typeContext *func_type();
    antlr4::tree::TerminalNode *TABLE();
    Table_typeContext *table_type();
    antlr4::tree::TerminalNode *MEMORY();
    Memory_typeContext *memory_type();
    antlr4::tree::TerminalNode *GLOBAL();
    Global_typeContext *global_type();

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
    antlr4::tree::TerminalNode *FUNC();
    Var_Context *var_();
    antlr4::tree::TerminalNode *RPAR();
    antlr4::tree::TerminalNode *TABLE();
    antlr4::tree::TerminalNode *MEMORY();
    antlr4::tree::TerminalNode *GLOBAL();

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

  class  Type_Context : public antlr4::ParserRuleContext {
  public:
    Type_Context(antlr4::ParserRuleContext *parent, size_t invokingState);
    virtual size_t getRuleIndex() const override;
    Def_typeContext *def_type();

    virtual void enterRule(antlr4::tree::ParseTreeListener *listener) override;
    virtual void exitRule(antlr4::tree::ParseTreeListener *listener) override;

    virtual std::any accept(antlr4::tree::ParseTreeVisitor *visitor) override;
   
  };

  Type_Context* type_();

  class  Type_defContext : public antlr4::ParserRuleContext {
  public:
    Type_defContext(antlr4::ParserRuleContext *parent, size_t invokingState);
    virtual size_t getRuleIndex() const override;
    antlr4::tree::TerminalNode *LPAR();
    antlr4::tree::TerminalNode *TYPE();
    Type_Context *type_();
    antlr4::tree::TerminalNode *RPAR();
    Bind_varContext *bind_var();

    virtual void enterRule(antlr4::tree::ParseTreeListener *listener) override;
    virtual void exitRule(antlr4::tree::ParseTreeListener *listener) override;

    virtual std::any accept(antlr4::tree::ParseTreeVisitor *visitor) override;
   
  };

  Type_defContext* type_def();

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
    Type_defContext *type_def();
    SglobalContext *sglobal();
    TableContext *table();
    MemoryContext *memory();
    Func_Context *func_();
    ElemContext *elem();
    DataContext *data();
    Start_Context *start_();
    SimportContext *simport();
    Export_Context *export_();

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
    Const_listContext *const_list();
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
    Const_listContext *const_list();
    antlr4::tree::TerminalNode *ASSERT_RETURN_CANONICAL_NAN();
    antlr4::tree::TerminalNode *ASSERT_RETURN_ARITHMETIC_NAN();
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
    MetaContext *meta();

    virtual void enterRule(antlr4::tree::ParseTreeListener *listener) override;
    virtual void exitRule(antlr4::tree::ParseTreeListener *listener) override;

    virtual std::any accept(antlr4::tree::ParseTreeVisitor *visitor) override;
   
  };

  CmdContext* cmd();

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

  class  WconstContext : public antlr4::ParserRuleContext {
  public:
    WconstContext(antlr4::ParserRuleContext *parent, size_t invokingState);
    virtual size_t getRuleIndex() const override;
    antlr4::tree::TerminalNode *LPAR();
    antlr4::tree::TerminalNode *CONST();
    LiteralContext *literal();
    antlr4::tree::TerminalNode *RPAR();

    virtual void enterRule(antlr4::tree::ParseTreeListener *listener) override;
    virtual void exitRule(antlr4::tree::ParseTreeListener *listener) override;

    virtual std::any accept(antlr4::tree::ParseTreeVisitor *visitor) override;
   
  };

  WconstContext* wconst();

  class  Const_listContext : public antlr4::ParserRuleContext {
  public:
    Const_listContext(antlr4::ParserRuleContext *parent, size_t invokingState);
    virtual size_t getRuleIndex() const override;
    std::vector<WconstContext *> wconst();
    WconstContext* wconst(size_t i);

    virtual void enterRule(antlr4::tree::ParseTreeListener *listener) override;
    virtual void exitRule(antlr4::tree::ParseTreeListener *listener) override;

    virtual std::any accept(antlr4::tree::ParseTreeVisitor *visitor) override;
   
  };

  Const_listContext* const_list();

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

