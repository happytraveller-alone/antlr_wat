
// Generated from WatParser.g4 by ANTLR 4.13.1

#pragma once


#include "antlr4-runtime.h"
#include "WatParser.h"


/**
 * This interface defines an abstract listener for a parse tree produced by WatParser.
 */
class  WatParserListener : public antlr4::tree::ParseTreeListener {
public:

  virtual void enterValue(WatParser::ValueContext *ctx) = 0;
  virtual void exitValue(WatParser::ValueContext *ctx) = 0;

  virtual void enterName(WatParser::NameContext *ctx) = 0;
  virtual void exitName(WatParser::NameContext *ctx) = 0;

  virtual void enterNull_opt(WatParser::Null_optContext *ctx) = 0;
  virtual void exitNull_opt(WatParser::Null_optContext *ctx) = 0;

  virtual void enterHeap_type(WatParser::Heap_typeContext *ctx) = 0;
  virtual void exitHeap_type(WatParser::Heap_typeContext *ctx) = 0;

  virtual void enterRef_type(WatParser::Ref_typeContext *ctx) = 0;
  virtual void exitRef_type(WatParser::Ref_typeContext *ctx) = 0;

  virtual void enterVal_type(WatParser::Val_typeContext *ctx) = 0;
  virtual void exitVal_type(WatParser::Val_typeContext *ctx) = 0;

  virtual void enterGlobal_type(WatParser::Global_typeContext *ctx) = 0;
  virtual void exitGlobal_type(WatParser::Global_typeContext *ctx) = 0;

  virtual void enterStorage_type(WatParser::Storage_typeContext *ctx) = 0;
  virtual void exitStorage_type(WatParser::Storage_typeContext *ctx) = 0;

  virtual void enterField_type(WatParser::Field_typeContext *ctx) = 0;
  virtual void exitField_type(WatParser::Field_typeContext *ctx) = 0;

  virtual void enterStruct_type(WatParser::Struct_typeContext *ctx) = 0;
  virtual void exitStruct_type(WatParser::Struct_typeContext *ctx) = 0;

  virtual void enterArray_type(WatParser::Array_typeContext *ctx) = 0;
  virtual void exitArray_type(WatParser::Array_typeContext *ctx) = 0;

  virtual void enterFunc_type(WatParser::Func_typeContext *ctx) = 0;
  virtual void exitFunc_type(WatParser::Func_typeContext *ctx) = 0;

  virtual void enterStr_type(WatParser::Str_typeContext *ctx) = 0;
  virtual void exitStr_type(WatParser::Str_typeContext *ctx) = 0;

  virtual void enterSub_type(WatParser::Sub_typeContext *ctx) = 0;
  virtual void exitSub_type(WatParser::Sub_typeContext *ctx) = 0;

  virtual void enterTable_type(WatParser::Table_typeContext *ctx) = 0;
  virtual void exitTable_type(WatParser::Table_typeContext *ctx) = 0;

  virtual void enterMemory_type(WatParser::Memory_typeContext *ctx) = 0;
  virtual void exitMemory_type(WatParser::Memory_typeContext *ctx) = 0;

  virtual void enterType_use(WatParser::Type_useContext *ctx) = 0;
  virtual void exitType_use(WatParser::Type_useContext *ctx) = 0;

  virtual void enterNat32(WatParser::Nat32Context *ctx) = 0;
  virtual void exitNat32(WatParser::Nat32Context *ctx) = 0;

  virtual void enterNum(WatParser::NumContext *ctx) = 0;
  virtual void exitNum(WatParser::NumContext *ctx) = 0;

  virtual void enterVar_(WatParser::Var_Context *ctx) = 0;
  virtual void exitVar_(WatParser::Var_Context *ctx) = 0;

  virtual void enterBind_var(WatParser::Bind_varContext *ctx) = 0;
  virtual void exitBind_var(WatParser::Bind_varContext *ctx) = 0;

  virtual void enterInstr_list(WatParser::Instr_listContext *ctx) = 0;
  virtual void exitInstr_list(WatParser::Instr_listContext *ctx) = 0;

  virtual void enterInstr(WatParser::InstrContext *ctx) = 0;
  virtual void exitInstr(WatParser::InstrContext *ctx) = 0;

  virtual void enterPlain_instr(WatParser::Plain_instrContext *ctx) = 0;
  virtual void exitPlain_instr(WatParser::Plain_instrContext *ctx) = 0;

  virtual void enterSelect_instr_instr_list(WatParser::Select_instr_instr_listContext *ctx) = 0;
  virtual void exitSelect_instr_instr_list(WatParser::Select_instr_instr_listContext *ctx) = 0;

  virtual void enterCall_instr_instr_list(WatParser::Call_instr_instr_listContext *ctx) = 0;
  virtual void exitCall_instr_instr_list(WatParser::Call_instr_instr_listContext *ctx) = 0;

  virtual void enterCall_instr_type_instr_list(WatParser::Call_instr_type_instr_listContext *ctx) = 0;
  virtual void exitCall_instr_type_instr_list(WatParser::Call_instr_type_instr_listContext *ctx) = 0;

  virtual void enterBlock_instr(WatParser::Block_instrContext *ctx) = 0;
  virtual void exitBlock_instr(WatParser::Block_instrContext *ctx) = 0;

  virtual void enterBlock(WatParser::BlockContext *ctx) = 0;
  virtual void exitBlock(WatParser::BlockContext *ctx) = 0;

  virtual void enterBlock_param_body(WatParser::Block_param_bodyContext *ctx) = 0;
  virtual void exitBlock_param_body(WatParser::Block_param_bodyContext *ctx) = 0;

  virtual void enterHandler_block(WatParser::Handler_blockContext *ctx) = 0;
  virtual void exitHandler_block(WatParser::Handler_blockContext *ctx) = 0;

  virtual void enterHandler_block_param_body(WatParser::Handler_block_param_bodyContext *ctx) = 0;
  virtual void exitHandler_block_param_body(WatParser::Handler_block_param_bodyContext *ctx) = 0;

  virtual void enterHandler_block_body(WatParser::Handler_block_bodyContext *ctx) = 0;
  virtual void exitHandler_block_body(WatParser::Handler_block_bodyContext *ctx) = 0;

  virtual void enterExpr(WatParser::ExprContext *ctx) = 0;
  virtual void exitExpr(WatParser::ExprContext *ctx) = 0;

  virtual void enterSelect_expr_results(WatParser::Select_expr_resultsContext *ctx) = 0;
  virtual void exitSelect_expr_results(WatParser::Select_expr_resultsContext *ctx) = 0;

  virtual void enterCall_expr_type(WatParser::Call_expr_typeContext *ctx) = 0;
  virtual void exitCall_expr_type(WatParser::Call_expr_typeContext *ctx) = 0;

  virtual void enterCall_expr_params(WatParser::Call_expr_paramsContext *ctx) = 0;
  virtual void exitCall_expr_params(WatParser::Call_expr_paramsContext *ctx) = 0;

  virtual void enterCall_expr_results(WatParser::Call_expr_resultsContext *ctx) = 0;
  virtual void exitCall_expr_results(WatParser::Call_expr_resultsContext *ctx) = 0;

  virtual void enterIf_block(WatParser::If_blockContext *ctx) = 0;
  virtual void exitIf_block(WatParser::If_blockContext *ctx) = 0;

  virtual void enterIf_block_result_body(WatParser::If_block_result_bodyContext *ctx) = 0;
  virtual void exitIf_block_result_body(WatParser::If_block_result_bodyContext *ctx) = 0;

  virtual void enterTry_block(WatParser::Try_blockContext *ctx) = 0;
  virtual void exitTry_block(WatParser::Try_blockContext *ctx) = 0;

  virtual void enterTry_block_param_body(WatParser::Try_block_param_bodyContext *ctx) = 0;
  virtual void exitTry_block_param_body(WatParser::Try_block_param_bodyContext *ctx) = 0;

  virtual void enterTry_block_handler_body(WatParser::Try_block_handler_bodyContext *ctx) = 0;
  virtual void exitTry_block_handler_body(WatParser::Try_block_handler_bodyContext *ctx) = 0;

  virtual void enterConst_expr(WatParser::Const_exprContext *ctx) = 0;
  virtual void exitConst_expr(WatParser::Const_exprContext *ctx) = 0;

  virtual void enterFunc_(WatParser::Func_Context *ctx) = 0;
  virtual void exitFunc_(WatParser::Func_Context *ctx) = 0;

  virtual void enterFunc_fields(WatParser::Func_fieldsContext *ctx) = 0;
  virtual void exitFunc_fields(WatParser::Func_fieldsContext *ctx) = 0;

  virtual void enterFunc_fields_import(WatParser::Func_fields_importContext *ctx) = 0;
  virtual void exitFunc_fields_import(WatParser::Func_fields_importContext *ctx) = 0;

  virtual void enterFunc_fields_import_result(WatParser::Func_fields_import_resultContext *ctx) = 0;
  virtual void exitFunc_fields_import_result(WatParser::Func_fields_import_resultContext *ctx) = 0;

  virtual void enterFunc_fields_body(WatParser::Func_fields_bodyContext *ctx) = 0;
  virtual void exitFunc_fields_body(WatParser::Func_fields_bodyContext *ctx) = 0;

  virtual void enterFunc_result_body(WatParser::Func_result_bodyContext *ctx) = 0;
  virtual void exitFunc_result_body(WatParser::Func_result_bodyContext *ctx) = 0;

  virtual void enterFunc_body(WatParser::Func_bodyContext *ctx) = 0;
  virtual void exitFunc_body(WatParser::Func_bodyContext *ctx) = 0;

  virtual void enterTable_use(WatParser::Table_useContext *ctx) = 0;
  virtual void exitTable_use(WatParser::Table_useContext *ctx) = 0;

  virtual void enterMemory_use(WatParser::Memory_useContext *ctx) = 0;
  virtual void exitMemory_use(WatParser::Memory_useContext *ctx) = 0;

  virtual void enterOffset(WatParser::OffsetContext *ctx) = 0;
  virtual void exitOffset(WatParser::OffsetContext *ctx) = 0;

  virtual void enterElem_kind(WatParser::Elem_kindContext *ctx) = 0;
  virtual void exitElem_kind(WatParser::Elem_kindContext *ctx) = 0;

  virtual void enterElem_expr(WatParser::Elem_exprContext *ctx) = 0;
  virtual void exitElem_expr(WatParser::Elem_exprContext *ctx) = 0;

  virtual void enterElem_list(WatParser::Elem_listContext *ctx) = 0;
  virtual void exitElem_list(WatParser::Elem_listContext *ctx) = 0;

  virtual void enterElem(WatParser::ElemContext *ctx) = 0;
  virtual void exitElem(WatParser::ElemContext *ctx) = 0;

  virtual void enterTable(WatParser::TableContext *ctx) = 0;
  virtual void exitTable(WatParser::TableContext *ctx) = 0;

  virtual void enterTable_fields(WatParser::Table_fieldsContext *ctx) = 0;
  virtual void exitTable_fields(WatParser::Table_fieldsContext *ctx) = 0;

  virtual void enterData(WatParser::DataContext *ctx) = 0;
  virtual void exitData(WatParser::DataContext *ctx) = 0;

  virtual void enterMemory(WatParser::MemoryContext *ctx) = 0;
  virtual void exitMemory(WatParser::MemoryContext *ctx) = 0;

  virtual void enterMemory_fields(WatParser::Memory_fieldsContext *ctx) = 0;
  virtual void exitMemory_fields(WatParser::Memory_fieldsContext *ctx) = 0;

  virtual void enterTag(WatParser::TagContext *ctx) = 0;
  virtual void exitTag(WatParser::TagContext *ctx) = 0;

  virtual void enterTag_fields(WatParser::Tag_fieldsContext *ctx) = 0;
  virtual void exitTag_fields(WatParser::Tag_fieldsContext *ctx) = 0;

  virtual void enterTag_fields_import(WatParser::Tag_fields_importContext *ctx) = 0;
  virtual void exitTag_fields_import(WatParser::Tag_fields_importContext *ctx) = 0;

  virtual void enterTag_fields_import_result(WatParser::Tag_fields_import_resultContext *ctx) = 0;
  virtual void exitTag_fields_import_result(WatParser::Tag_fields_import_resultContext *ctx) = 0;

  virtual void enterSglobal(WatParser::SglobalContext *ctx) = 0;
  virtual void exitSglobal(WatParser::SglobalContext *ctx) = 0;

  virtual void enterGlobal_fields(WatParser::Global_fieldsContext *ctx) = 0;
  virtual void exitGlobal_fields(WatParser::Global_fieldsContext *ctx) = 0;

  virtual void enterImport_desc(WatParser::Import_descContext *ctx) = 0;
  virtual void exitImport_desc(WatParser::Import_descContext *ctx) = 0;

  virtual void enterSimport(WatParser::SimportContext *ctx) = 0;
  virtual void exitSimport(WatParser::SimportContext *ctx) = 0;

  virtual void enterInline_import(WatParser::Inline_importContext *ctx) = 0;
  virtual void exitInline_import(WatParser::Inline_importContext *ctx) = 0;

  virtual void enterExport_desc(WatParser::Export_descContext *ctx) = 0;
  virtual void exitExport_desc(WatParser::Export_descContext *ctx) = 0;

  virtual void enterExport_(WatParser::Export_Context *ctx) = 0;
  virtual void exitExport_(WatParser::Export_Context *ctx) = 0;

  virtual void enterInline_export(WatParser::Inline_exportContext *ctx) = 0;
  virtual void exitInline_export(WatParser::Inline_exportContext *ctx) = 0;

  virtual void enterType_def(WatParser::Type_defContext *ctx) = 0;
  virtual void exitType_def(WatParser::Type_defContext *ctx) = 0;

  virtual void enterRec_type(WatParser::Rec_typeContext *ctx) = 0;
  virtual void exitRec_type(WatParser::Rec_typeContext *ctx) = 0;

  virtual void enterType_(WatParser::Type_Context *ctx) = 0;
  virtual void exitType_(WatParser::Type_Context *ctx) = 0;

  virtual void enterStart_(WatParser::Start_Context *ctx) = 0;
  virtual void exitStart_(WatParser::Start_Context *ctx) = 0;

  virtual void enterModule_field(WatParser::Module_fieldContext *ctx) = 0;
  virtual void exitModule_field(WatParser::Module_fieldContext *ctx) = 0;

  virtual void enterModule_(WatParser::Module_Context *ctx) = 0;
  virtual void exitModule_(WatParser::Module_Context *ctx) = 0;

  virtual void enterInline_module(WatParser::Inline_moduleContext *ctx) = 0;
  virtual void exitInline_module(WatParser::Inline_moduleContext *ctx) = 0;

  virtual void enterScript_module(WatParser::Script_moduleContext *ctx) = 0;
  virtual void exitScript_module(WatParser::Script_moduleContext *ctx) = 0;

  virtual void enterAction_(WatParser::Action_Context *ctx) = 0;
  virtual void exitAction_(WatParser::Action_Context *ctx) = 0;

  virtual void enterAssertion(WatParser::AssertionContext *ctx) = 0;
  virtual void exitAssertion(WatParser::AssertionContext *ctx) = 0;

  virtual void enterCmd(WatParser::CmdContext *ctx) = 0;
  virtual void exitCmd(WatParser::CmdContext *ctx) = 0;

  virtual void enterShared_cmd_list(WatParser::Shared_cmd_listContext *ctx) = 0;
  virtual void exitShared_cmd_list(WatParser::Shared_cmd_listContext *ctx) = 0;

  virtual void enterMeta(WatParser::MetaContext *ctx) = 0;
  virtual void exitMeta(WatParser::MetaContext *ctx) = 0;

  virtual void enterLiteral_num(WatParser::Literal_numContext *ctx) = 0;
  virtual void exitLiteral_num(WatParser::Literal_numContext *ctx) = 0;

  virtual void enterLiteral_vec(WatParser::Literal_vecContext *ctx) = 0;
  virtual void exitLiteral_vec(WatParser::Literal_vecContext *ctx) = 0;

  virtual void enterLiteral_ref(WatParser::Literal_refContext *ctx) = 0;
  virtual void exitLiteral_ref(WatParser::Literal_refContext *ctx) = 0;

  virtual void enterLiteral(WatParser::LiteralContext *ctx) = 0;
  virtual void exitLiteral(WatParser::LiteralContext *ctx) = 0;

  virtual void enterLiteral_list(WatParser::Literal_listContext *ctx) = 0;
  virtual void exitLiteral_list(WatParser::Literal_listContext *ctx) = 0;

  virtual void enterNumpat(WatParser::NumpatContext *ctx) = 0;
  virtual void exitNumpat(WatParser::NumpatContext *ctx) = 0;

  virtual void enterResult(WatParser::ResultContext *ctx) = 0;
  virtual void exitResult(WatParser::ResultContext *ctx) = 0;

  virtual void enterScript(WatParser::ScriptContext *ctx) = 0;
  virtual void exitScript(WatParser::ScriptContext *ctx) = 0;

  virtual void enterModule(WatParser::ModuleContext *ctx) = 0;
  virtual void exitModule(WatParser::ModuleContext *ctx) = 0;


};

