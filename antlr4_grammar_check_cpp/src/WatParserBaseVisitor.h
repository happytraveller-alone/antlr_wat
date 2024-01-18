
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

  virtual std::any visitNull_opt(WatParser::Null_optContext *ctx) override {
    return visitChildren(ctx);
  }

  virtual std::any visitHeap_type(WatParser::Heap_typeContext *ctx) override {
    return visitChildren(ctx);
  }

  virtual std::any visitRef_type(WatParser::Ref_typeContext *ctx) override {
    return visitChildren(ctx);
  }

  virtual std::any visitVal_type(WatParser::Val_typeContext *ctx) override {
    return visitChildren(ctx);
  }

  virtual std::any visitGlobal_type(WatParser::Global_typeContext *ctx) override {
    return visitChildren(ctx);
  }

  virtual std::any visitStorage_type(WatParser::Storage_typeContext *ctx) override {
    return visitChildren(ctx);
  }

  virtual std::any visitField_type(WatParser::Field_typeContext *ctx) override {
    return visitChildren(ctx);
  }

  virtual std::any visitStruct_type(WatParser::Struct_typeContext *ctx) override {
    return visitChildren(ctx);
  }

  virtual std::any visitArray_type(WatParser::Array_typeContext *ctx) override {
    return visitChildren(ctx);
  }

  virtual std::any visitFunc_type(WatParser::Func_typeContext *ctx) override {
    return visitChildren(ctx);
  }

  virtual std::any visitStr_type(WatParser::Str_typeContext *ctx) override {
    return visitChildren(ctx);
  }

  virtual std::any visitSub_type(WatParser::Sub_typeContext *ctx) override {
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

  virtual std::any visitNat32(WatParser::Nat32Context *ctx) override {
    return visitChildren(ctx);
  }

  virtual std::any visitNum(WatParser::NumContext *ctx) override {
    return visitChildren(ctx);
  }

  virtual std::any visitVar_(WatParser::Var_Context *ctx) override {
    return visitChildren(ctx);
  }

  virtual std::any visitBind_var(WatParser::Bind_varContext *ctx) override {
    return visitChildren(ctx);
  }

  virtual std::any visitInstr_list(WatParser::Instr_listContext *ctx) override {
    return visitChildren(ctx);
  }

  virtual std::any visitInstr(WatParser::InstrContext *ctx) override {
    return visitChildren(ctx);
  }

  virtual std::any visitPlain_instr(WatParser::Plain_instrContext *ctx) override {
    return visitChildren(ctx);
  }

  virtual std::any visitSelect_instr_instr_list(WatParser::Select_instr_instr_listContext *ctx) override {
    return visitChildren(ctx);
  }

  virtual std::any visitCall_instr_instr_list(WatParser::Call_instr_instr_listContext *ctx) override {
    return visitChildren(ctx);
  }

  virtual std::any visitCall_instr_type_instr_list(WatParser::Call_instr_type_instr_listContext *ctx) override {
    return visitChildren(ctx);
  }

  virtual std::any visitBlock_instr(WatParser::Block_instrContext *ctx) override {
    return visitChildren(ctx);
  }

  virtual std::any visitBlock(WatParser::BlockContext *ctx) override {
    return visitChildren(ctx);
  }

  virtual std::any visitBlock_param_body(WatParser::Block_param_bodyContext *ctx) override {
    return visitChildren(ctx);
  }

  virtual std::any visitHandler_block(WatParser::Handler_blockContext *ctx) override {
    return visitChildren(ctx);
  }

  virtual std::any visitHandler_block_param_body(WatParser::Handler_block_param_bodyContext *ctx) override {
    return visitChildren(ctx);
  }

  virtual std::any visitHandler_block_body(WatParser::Handler_block_bodyContext *ctx) override {
    return visitChildren(ctx);
  }

  virtual std::any visitExpr(WatParser::ExprContext *ctx) override {
    return visitChildren(ctx);
  }

  virtual std::any visitExpr1(WatParser::Expr1Context *ctx) override {
    return visitChildren(ctx);
  }

  virtual std::any visitSelect_expr_results(WatParser::Select_expr_resultsContext *ctx) override {
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

  virtual std::any visitIf_block_result_body(WatParser::If_block_result_bodyContext *ctx) override {
    return visitChildren(ctx);
  }

  virtual std::any visitTry_block(WatParser::Try_blockContext *ctx) override {
    return visitChildren(ctx);
  }

  virtual std::any visitTry_block_param_body(WatParser::Try_block_param_bodyContext *ctx) override {
    return visitChildren(ctx);
  }

  virtual std::any visitTry_block_handler_body(WatParser::Try_block_handler_bodyContext *ctx) override {
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

  virtual std::any visitTable_use(WatParser::Table_useContext *ctx) override {
    return visitChildren(ctx);
  }

  virtual std::any visitMemory_use(WatParser::Memory_useContext *ctx) override {
    return visitChildren(ctx);
  }

  virtual std::any visitOffset(WatParser::OffsetContext *ctx) override {
    return visitChildren(ctx);
  }

  virtual std::any visitElem_kind(WatParser::Elem_kindContext *ctx) override {
    return visitChildren(ctx);
  }

  virtual std::any visitElem_expr(WatParser::Elem_exprContext *ctx) override {
    return visitChildren(ctx);
  }

  virtual std::any visitElem_list(WatParser::Elem_listContext *ctx) override {
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

  virtual std::any visitTag(WatParser::TagContext *ctx) override {
    return visitChildren(ctx);
  }

  virtual std::any visitTag_fields(WatParser::Tag_fieldsContext *ctx) override {
    return visitChildren(ctx);
  }

  virtual std::any visitTag_fields_import(WatParser::Tag_fields_importContext *ctx) override {
    return visitChildren(ctx);
  }

  virtual std::any visitTag_fields_import_result(WatParser::Tag_fields_import_resultContext *ctx) override {
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

  virtual std::any visitType_def(WatParser::Type_defContext *ctx) override {
    return visitChildren(ctx);
  }

  virtual std::any visitRec_type(WatParser::Rec_typeContext *ctx) override {
    return visitChildren(ctx);
  }

  virtual std::any visitType_(WatParser::Type_Context *ctx) override {
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

  virtual std::any visitInline_module(WatParser::Inline_moduleContext *ctx) override {
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

  virtual std::any visitShared_cmd_list(WatParser::Shared_cmd_listContext *ctx) override {
    return visitChildren(ctx);
  }

  virtual std::any visitMeta(WatParser::MetaContext *ctx) override {
    return visitChildren(ctx);
  }

  virtual std::any visitLiteral_num(WatParser::Literal_numContext *ctx) override {
    return visitChildren(ctx);
  }

  virtual std::any visitLiteral_vec(WatParser::Literal_vecContext *ctx) override {
    return visitChildren(ctx);
  }

  virtual std::any visitLiteral_ref(WatParser::Literal_refContext *ctx) override {
    return visitChildren(ctx);
  }

  virtual std::any visitLiteral(WatParser::LiteralContext *ctx) override {
    return visitChildren(ctx);
  }

  virtual std::any visitLiteral_list(WatParser::Literal_listContext *ctx) override {
    return visitChildren(ctx);
  }

  virtual std::any visitNumpat(WatParser::NumpatContext *ctx) override {
    return visitChildren(ctx);
  }

  virtual std::any visitResult(WatParser::ResultContext *ctx) override {
    return visitChildren(ctx);
  }

  virtual std::any visitScript(WatParser::ScriptContext *ctx) override {
    return visitChildren(ctx);
  }

  virtual std::any visitModule(WatParser::ModuleContext *ctx) override {
    return visitChildren(ctx);
  }


};

