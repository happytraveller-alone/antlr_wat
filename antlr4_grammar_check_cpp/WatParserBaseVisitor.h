
// Generated from WatParser.g4 by ANTLR 4.13.1

#pragma once


#include "antlr4-runtime.h"
#include "WatParserVisitor.h"


/**
 * This class provides an empty implementation of WatParserVisitor, which can be
 * extended to create a visitor which only needs to handle a subset of the available methods.
 */
class  WatParserBaseVisitor : public WatParserVisitor {
public:

  virtual std::any visitValue(WatParser::ValueContext *ctx) override {
    return visitChildren(ctx);
  }

  virtual std::any visitName(WatParser::NameContext *ctx) override {
    return visitChildren(ctx);
  }

  virtual std::any visitValue_type(WatParser::Value_typeContext *ctx) override {
    return visitChildren(ctx);
  }

  virtual std::any visitElem_type(WatParser::Elem_typeContext *ctx) override {
    return visitChildren(ctx);
  }

  virtual std::any visitGlobal_type(WatParser::Global_typeContext *ctx) override {
    return visitChildren(ctx);
  }

  virtual std::any visitDef_type(WatParser::Def_typeContext *ctx) override {
    return visitChildren(ctx);
  }

  virtual std::any visitFunc_type(WatParser::Func_typeContext *ctx) override {
    return visitChildren(ctx);
  }

  virtual std::any visitTable_type(WatParser::Table_typeContext *ctx) override {
    return visitChildren(ctx);
  }

  virtual std::any visitMemory_type(WatParser::Memory_typeContext *ctx) override {
    return visitChildren(ctx);
  }

  virtual std::any visitType_use(WatParser::Type_useContext *ctx) override {
    return visitChildren(ctx);
  }

  virtual std::any visitLiteral(WatParser::LiteralContext *ctx) override {
    return visitChildren(ctx);
  }

  virtual std::any visitVar_(WatParser::Var_Context *ctx) override {
    return visitChildren(ctx);
  }

  virtual std::any visitBind_var(WatParser::Bind_varContext *ctx) override {
    return visitChildren(ctx);
  }

  virtual std::any visitInstr(WatParser::InstrContext *ctx) override {
    return visitChildren(ctx);
  }

  virtual std::any visitPlain_instr(WatParser::Plain_instrContext *ctx) override {
    return visitChildren(ctx);
  }

  virtual std::any visitCall_instr(WatParser::Call_instrContext *ctx) override {
    return visitChildren(ctx);
  }

  virtual std::any visitCall_instr_params(WatParser::Call_instr_paramsContext *ctx) override {
    return visitChildren(ctx);
  }

  virtual std::any visitCall_instr_instr(WatParser::Call_instr_instrContext *ctx) override {
    return visitChildren(ctx);
  }

  virtual std::any visitCall_instr_params_instr(WatParser::Call_instr_params_instrContext *ctx) override {
    return visitChildren(ctx);
  }

  virtual std::any visitCall_instr_results_instr(WatParser::Call_instr_results_instrContext *ctx) override {
    return visitChildren(ctx);
  }

  virtual std::any visitBlock_instr(WatParser::Block_instrContext *ctx) override {
    return visitChildren(ctx);
  }

  virtual std::any visitBlock_type(WatParser::Block_typeContext *ctx) override {
    return visitChildren(ctx);
  }

  virtual std::any visitBlock(WatParser::BlockContext *ctx) override {
    return visitChildren(ctx);
  }

  virtual std::any visitExpr(WatParser::ExprContext *ctx) override {
    return visitChildren(ctx);
  }

  virtual std::any visitExpr1(WatParser::Expr1Context *ctx) override {
    return visitChildren(ctx);
  }

  virtual std::any visitCall_expr_type(WatParser::Call_expr_typeContext *ctx) override {
    return visitChildren(ctx);
  }

  virtual std::any visitCall_expr_params(WatParser::Call_expr_paramsContext *ctx) override {
    return visitChildren(ctx);
  }

  virtual std::any visitCall_expr_results(WatParser::Call_expr_resultsContext *ctx) override {
    return visitChildren(ctx);
  }

  virtual std::any visitIf_block(WatParser::If_blockContext *ctx) override {
    return visitChildren(ctx);
  }

  virtual std::any visitInstr_list(WatParser::Instr_listContext *ctx) override {
    return visitChildren(ctx);
  }

  virtual std::any visitConst_expr(WatParser::Const_exprContext *ctx) override {
    return visitChildren(ctx);
  }

  virtual std::any visitFunc_(WatParser::Func_Context *ctx) override {
    return visitChildren(ctx);
  }

  virtual std::any visitFunc_fields(WatParser::Func_fieldsContext *ctx) override {
    return visitChildren(ctx);
  }

  virtual std::any visitFunc_fields_import(WatParser::Func_fields_importContext *ctx) override {
    return visitChildren(ctx);
  }

  virtual std::any visitFunc_fields_import_result(WatParser::Func_fields_import_resultContext *ctx) override {
    return visitChildren(ctx);
  }

  virtual std::any visitFunc_fields_body(WatParser::Func_fields_bodyContext *ctx) override {
    return visitChildren(ctx);
  }

  virtual std::any visitFunc_result_body(WatParser::Func_result_bodyContext *ctx) override {
    return visitChildren(ctx);
  }

  virtual std::any visitFunc_body(WatParser::Func_bodyContext *ctx) override {
    return visitChildren(ctx);
  }

  virtual std::any visitOffset(WatParser::OffsetContext *ctx) override {
    return visitChildren(ctx);
  }

  virtual std::any visitElem(WatParser::ElemContext *ctx) override {
    return visitChildren(ctx);
  }

  virtual std::any visitTable(WatParser::TableContext *ctx) override {
    return visitChildren(ctx);
  }

  virtual std::any visitTable_fields(WatParser::Table_fieldsContext *ctx) override {
    return visitChildren(ctx);
  }

  virtual std::any visitData(WatParser::DataContext *ctx) override {
    return visitChildren(ctx);
  }

  virtual std::any visitMemory(WatParser::MemoryContext *ctx) override {
    return visitChildren(ctx);
  }

  virtual std::any visitMemory_fields(WatParser::Memory_fieldsContext *ctx) override {
    return visitChildren(ctx);
  }

  virtual std::any visitSglobal(WatParser::SglobalContext *ctx) override {
    return visitChildren(ctx);
  }

  virtual std::any visitGlobal_fields(WatParser::Global_fieldsContext *ctx) override {
    return visitChildren(ctx);
  }

  virtual std::any visitImport_desc(WatParser::Import_descContext *ctx) override {
    return visitChildren(ctx);
  }

  virtual std::any visitSimport(WatParser::SimportContext *ctx) override {
    return visitChildren(ctx);
  }

  virtual std::any visitInline_import(WatParser::Inline_importContext *ctx) override {
    return visitChildren(ctx);
  }

  virtual std::any visitExport_desc(WatParser::Export_descContext *ctx) override {
    return visitChildren(ctx);
  }

  virtual std::any visitExport_(WatParser::Export_Context *ctx) override {
    return visitChildren(ctx);
  }

  virtual std::any visitInline_export(WatParser::Inline_exportContext *ctx) override {
    return visitChildren(ctx);
  }

  virtual std::any visitType_(WatParser::Type_Context *ctx) override {
    return visitChildren(ctx);
  }

  virtual std::any visitType_def(WatParser::Type_defContext *ctx) override {
    return visitChildren(ctx);
  }

  virtual std::any visitStart_(WatParser::Start_Context *ctx) override {
    return visitChildren(ctx);
  }

  virtual std::any visitModule_field(WatParser::Module_fieldContext *ctx) override {
    return visitChildren(ctx);
  }

  virtual std::any visitModule_(WatParser::Module_Context *ctx) override {
    return visitChildren(ctx);
  }

  virtual std::any visitScript_module(WatParser::Script_moduleContext *ctx) override {
    return visitChildren(ctx);
  }

  virtual std::any visitAction_(WatParser::Action_Context *ctx) override {
    return visitChildren(ctx);
  }

  virtual std::any visitAssertion(WatParser::AssertionContext *ctx) override {
    return visitChildren(ctx);
  }

  virtual std::any visitCmd(WatParser::CmdContext *ctx) override {
    return visitChildren(ctx);
  }

  virtual std::any visitMeta(WatParser::MetaContext *ctx) override {
    return visitChildren(ctx);
  }

  virtual std::any visitWconst(WatParser::WconstContext *ctx) override {
    return visitChildren(ctx);
  }

  virtual std::any visitConst_list(WatParser::Const_listContext *ctx) override {
    return visitChildren(ctx);
  }

  virtual std::any visitScript(WatParser::ScriptContext *ctx) override {
    return visitChildren(ctx);
  }

  virtual std::any visitModule(WatParser::ModuleContext *ctx) override {
    return visitChildren(ctx);
  }


};
