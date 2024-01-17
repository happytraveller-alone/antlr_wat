
// Generated from WatParser.g4 by ANTLR 4.13.1

#pragma once


#include "antlr4-runtime.h"
#include "WatParserListener.h"


/**
 * This class provides an empty implementation of WatParserListener,
 * which can be extended to create a listener which only needs to handle a subset
 * of the available methods.
 */
class  WatParserBaseListener : public WatParserListener {
public:

  virtual void enterValue(WatParser::ValueContext * /*ctx*/) override { }
  virtual void exitValue(WatParser::ValueContext * /*ctx*/) override { }

  virtual void enterName(WatParser::NameContext * /*ctx*/) override { }
  virtual void exitName(WatParser::NameContext * /*ctx*/) override { }

  virtual void enterNull_opt(WatParser::Null_optContext * /*ctx*/) override { }
  virtual void exitNull_opt(WatParser::Null_optContext * /*ctx*/) override { }

  virtual void enterHeap_type(WatParser::Heap_typeContext * /*ctx*/) override { }
  virtual void exitHeap_type(WatParser::Heap_typeContext * /*ctx*/) override { }

  virtual void enterRef_type(WatParser::Ref_typeContext * /*ctx*/) override { }
  virtual void exitRef_type(WatParser::Ref_typeContext * /*ctx*/) override { }

  virtual void enterVal_type(WatParser::Val_typeContext * /*ctx*/) override { }
  virtual void exitVal_type(WatParser::Val_typeContext * /*ctx*/) override { }

  virtual void enterGlobal_type(WatParser::Global_typeContext * /*ctx*/) override { }
  virtual void exitGlobal_type(WatParser::Global_typeContext * /*ctx*/) override { }

  virtual void enterStorage_type(WatParser::Storage_typeContext * /*ctx*/) override { }
  virtual void exitStorage_type(WatParser::Storage_typeContext * /*ctx*/) override { }

  virtual void enterField_type(WatParser::Field_typeContext * /*ctx*/) override { }
  virtual void exitField_type(WatParser::Field_typeContext * /*ctx*/) override { }

  virtual void enterStruct_type(WatParser::Struct_typeContext * /*ctx*/) override { }
  virtual void exitStruct_type(WatParser::Struct_typeContext * /*ctx*/) override { }

  virtual void enterArray_type(WatParser::Array_typeContext * /*ctx*/) override { }
  virtual void exitArray_type(WatParser::Array_typeContext * /*ctx*/) override { }

  virtual void enterFunc_type(WatParser::Func_typeContext * /*ctx*/) override { }
  virtual void exitFunc_type(WatParser::Func_typeContext * /*ctx*/) override { }

  virtual void enterStr_type(WatParser::Str_typeContext * /*ctx*/) override { }
  virtual void exitStr_type(WatParser::Str_typeContext * /*ctx*/) override { }

  virtual void enterSub_type(WatParser::Sub_typeContext * /*ctx*/) override { }
  virtual void exitSub_type(WatParser::Sub_typeContext * /*ctx*/) override { }

  virtual void enterTable_type(WatParser::Table_typeContext * /*ctx*/) override { }
  virtual void exitTable_type(WatParser::Table_typeContext * /*ctx*/) override { }

  virtual void enterMemory_type(WatParser::Memory_typeContext * /*ctx*/) override { }
  virtual void exitMemory_type(WatParser::Memory_typeContext * /*ctx*/) override { }

  virtual void enterType_use(WatParser::Type_useContext * /*ctx*/) override { }
  virtual void exitType_use(WatParser::Type_useContext * /*ctx*/) override { }

  virtual void enterNat32(WatParser::Nat32Context * /*ctx*/) override { }
  virtual void exitNat32(WatParser::Nat32Context * /*ctx*/) override { }

  virtual void enterNum(WatParser::NumContext * /*ctx*/) override { }
  virtual void exitNum(WatParser::NumContext * /*ctx*/) override { }

  virtual void enterVar_(WatParser::Var_Context * /*ctx*/) override { }
  virtual void exitVar_(WatParser::Var_Context * /*ctx*/) override { }

  virtual void enterBind_var(WatParser::Bind_varContext * /*ctx*/) override { }
  virtual void exitBind_var(WatParser::Bind_varContext * /*ctx*/) override { }

  virtual void enterInstr_list(WatParser::Instr_listContext * /*ctx*/) override { }
  virtual void exitInstr_list(WatParser::Instr_listContext * /*ctx*/) override { }

  virtual void enterInstr(WatParser::InstrContext * /*ctx*/) override { }
  virtual void exitInstr(WatParser::InstrContext * /*ctx*/) override { }

  virtual void enterPlain_instr(WatParser::Plain_instrContext * /*ctx*/) override { }
  virtual void exitPlain_instr(WatParser::Plain_instrContext * /*ctx*/) override { }

  virtual void enterSelect_instr_instr_list(WatParser::Select_instr_instr_listContext * /*ctx*/) override { }
  virtual void exitSelect_instr_instr_list(WatParser::Select_instr_instr_listContext * /*ctx*/) override { }

  virtual void enterCall_instr_instr_list(WatParser::Call_instr_instr_listContext * /*ctx*/) override { }
  virtual void exitCall_instr_instr_list(WatParser::Call_instr_instr_listContext * /*ctx*/) override { }

  virtual void enterCall_instr_type_instr_list(WatParser::Call_instr_type_instr_listContext * /*ctx*/) override { }
  virtual void exitCall_instr_type_instr_list(WatParser::Call_instr_type_instr_listContext * /*ctx*/) override { }

  virtual void enterBlock_instr(WatParser::Block_instrContext * /*ctx*/) override { }
  virtual void exitBlock_instr(WatParser::Block_instrContext * /*ctx*/) override { }

  virtual void enterBlock(WatParser::BlockContext * /*ctx*/) override { }
  virtual void exitBlock(WatParser::BlockContext * /*ctx*/) override { }

  virtual void enterBlock_param_body(WatParser::Block_param_bodyContext * /*ctx*/) override { }
  virtual void exitBlock_param_body(WatParser::Block_param_bodyContext * /*ctx*/) override { }

  virtual void enterExpr(WatParser::ExprContext * /*ctx*/) override { }
  virtual void exitExpr(WatParser::ExprContext * /*ctx*/) override { }

  virtual void enterExpr1(WatParser::Expr1Context * /*ctx*/) override { }
  virtual void exitExpr1(WatParser::Expr1Context * /*ctx*/) override { }

  virtual void enterSelect_expr_results(WatParser::Select_expr_resultsContext * /*ctx*/) override { }
  virtual void exitSelect_expr_results(WatParser::Select_expr_resultsContext * /*ctx*/) override { }

  virtual void enterCall_expr_type(WatParser::Call_expr_typeContext * /*ctx*/) override { }
  virtual void exitCall_expr_type(WatParser::Call_expr_typeContext * /*ctx*/) override { }

  virtual void enterCall_expr_params(WatParser::Call_expr_paramsContext * /*ctx*/) override { }
  virtual void exitCall_expr_params(WatParser::Call_expr_paramsContext * /*ctx*/) override { }

  virtual void enterCall_expr_results(WatParser::Call_expr_resultsContext * /*ctx*/) override { }
  virtual void exitCall_expr_results(WatParser::Call_expr_resultsContext * /*ctx*/) override { }

  virtual void enterIf_block(WatParser::If_blockContext * /*ctx*/) override { }
  virtual void exitIf_block(WatParser::If_blockContext * /*ctx*/) override { }

  virtual void enterIf_block_result_body(WatParser::If_block_result_bodyContext * /*ctx*/) override { }
  virtual void exitIf_block_result_body(WatParser::If_block_result_bodyContext * /*ctx*/) override { }

  virtual void enterConst_expr(WatParser::Const_exprContext * /*ctx*/) override { }
  virtual void exitConst_expr(WatParser::Const_exprContext * /*ctx*/) override { }

  virtual void enterFunc_(WatParser::Func_Context * /*ctx*/) override { }
  virtual void exitFunc_(WatParser::Func_Context * /*ctx*/) override { }

  virtual void enterFunc_fields(WatParser::Func_fieldsContext * /*ctx*/) override { }
  virtual void exitFunc_fields(WatParser::Func_fieldsContext * /*ctx*/) override { }

  virtual void enterFunc_fields_import(WatParser::Func_fields_importContext * /*ctx*/) override { }
  virtual void exitFunc_fields_import(WatParser::Func_fields_importContext * /*ctx*/) override { }

  virtual void enterFunc_fields_import_result(WatParser::Func_fields_import_resultContext * /*ctx*/) override { }
  virtual void exitFunc_fields_import_result(WatParser::Func_fields_import_resultContext * /*ctx*/) override { }

  virtual void enterFunc_fields_body(WatParser::Func_fields_bodyContext * /*ctx*/) override { }
  virtual void exitFunc_fields_body(WatParser::Func_fields_bodyContext * /*ctx*/) override { }

  virtual void enterFunc_result_body(WatParser::Func_result_bodyContext * /*ctx*/) override { }
  virtual void exitFunc_result_body(WatParser::Func_result_bodyContext * /*ctx*/) override { }

  virtual void enterFunc_body(WatParser::Func_bodyContext * /*ctx*/) override { }
  virtual void exitFunc_body(WatParser::Func_bodyContext * /*ctx*/) override { }

  virtual void enterTable_use(WatParser::Table_useContext * /*ctx*/) override { }
  virtual void exitTable_use(WatParser::Table_useContext * /*ctx*/) override { }

  virtual void enterMemory_use(WatParser::Memory_useContext * /*ctx*/) override { }
  virtual void exitMemory_use(WatParser::Memory_useContext * /*ctx*/) override { }

  virtual void enterOffset(WatParser::OffsetContext * /*ctx*/) override { }
  virtual void exitOffset(WatParser::OffsetContext * /*ctx*/) override { }

  virtual void enterElem_kind(WatParser::Elem_kindContext * /*ctx*/) override { }
  virtual void exitElem_kind(WatParser::Elem_kindContext * /*ctx*/) override { }

  virtual void enterElem_expr(WatParser::Elem_exprContext * /*ctx*/) override { }
  virtual void exitElem_expr(WatParser::Elem_exprContext * /*ctx*/) override { }

  virtual void enterElem_list(WatParser::Elem_listContext * /*ctx*/) override { }
  virtual void exitElem_list(WatParser::Elem_listContext * /*ctx*/) override { }

  virtual void enterElem(WatParser::ElemContext * /*ctx*/) override { }
  virtual void exitElem(WatParser::ElemContext * /*ctx*/) override { }

  virtual void enterTable(WatParser::TableContext * /*ctx*/) override { }
  virtual void exitTable(WatParser::TableContext * /*ctx*/) override { }

  virtual void enterTable_fields(WatParser::Table_fieldsContext * /*ctx*/) override { }
  virtual void exitTable_fields(WatParser::Table_fieldsContext * /*ctx*/) override { }

  virtual void enterData(WatParser::DataContext * /*ctx*/) override { }
  virtual void exitData(WatParser::DataContext * /*ctx*/) override { }

  virtual void enterMemory(WatParser::MemoryContext * /*ctx*/) override { }
  virtual void exitMemory(WatParser::MemoryContext * /*ctx*/) override { }

  virtual void enterMemory_fields(WatParser::Memory_fieldsContext * /*ctx*/) override { }
  virtual void exitMemory_fields(WatParser::Memory_fieldsContext * /*ctx*/) override { }

  virtual void enterSglobal(WatParser::SglobalContext * /*ctx*/) override { }
  virtual void exitSglobal(WatParser::SglobalContext * /*ctx*/) override { }

  virtual void enterGlobal_fields(WatParser::Global_fieldsContext * /*ctx*/) override { }
  virtual void exitGlobal_fields(WatParser::Global_fieldsContext * /*ctx*/) override { }

  virtual void enterImport_desc(WatParser::Import_descContext * /*ctx*/) override { }
  virtual void exitImport_desc(WatParser::Import_descContext * /*ctx*/) override { }

  virtual void enterSimport(WatParser::SimportContext * /*ctx*/) override { }
  virtual void exitSimport(WatParser::SimportContext * /*ctx*/) override { }

  virtual void enterInline_import(WatParser::Inline_importContext * /*ctx*/) override { }
  virtual void exitInline_import(WatParser::Inline_importContext * /*ctx*/) override { }

  virtual void enterExport_desc(WatParser::Export_descContext * /*ctx*/) override { }
  virtual void exitExport_desc(WatParser::Export_descContext * /*ctx*/) override { }

  virtual void enterExport_(WatParser::Export_Context * /*ctx*/) override { }
  virtual void exitExport_(WatParser::Export_Context * /*ctx*/) override { }

  virtual void enterInline_export(WatParser::Inline_exportContext * /*ctx*/) override { }
  virtual void exitInline_export(WatParser::Inline_exportContext * /*ctx*/) override { }

  virtual void enterType_def(WatParser::Type_defContext * /*ctx*/) override { }
  virtual void exitType_def(WatParser::Type_defContext * /*ctx*/) override { }

  virtual void enterRec_type(WatParser::Rec_typeContext * /*ctx*/) override { }
  virtual void exitRec_type(WatParser::Rec_typeContext * /*ctx*/) override { }

  virtual void enterType_(WatParser::Type_Context * /*ctx*/) override { }
  virtual void exitType_(WatParser::Type_Context * /*ctx*/) override { }

  virtual void enterStart_(WatParser::Start_Context * /*ctx*/) override { }
  virtual void exitStart_(WatParser::Start_Context * /*ctx*/) override { }

  virtual void enterModule_field(WatParser::Module_fieldContext * /*ctx*/) override { }
  virtual void exitModule_field(WatParser::Module_fieldContext * /*ctx*/) override { }

  virtual void enterModule_(WatParser::Module_Context * /*ctx*/) override { }
  virtual void exitModule_(WatParser::Module_Context * /*ctx*/) override { }

  virtual void enterInline_module(WatParser::Inline_moduleContext * /*ctx*/) override { }
  virtual void exitInline_module(WatParser::Inline_moduleContext * /*ctx*/) override { }

  virtual void enterScript_module(WatParser::Script_moduleContext * /*ctx*/) override { }
  virtual void exitScript_module(WatParser::Script_moduleContext * /*ctx*/) override { }

  virtual void enterAction_(WatParser::Action_Context * /*ctx*/) override { }
  virtual void exitAction_(WatParser::Action_Context * /*ctx*/) override { }

  virtual void enterAssertion(WatParser::AssertionContext * /*ctx*/) override { }
  virtual void exitAssertion(WatParser::AssertionContext * /*ctx*/) override { }

  virtual void enterCmd(WatParser::CmdContext * /*ctx*/) override { }
  virtual void exitCmd(WatParser::CmdContext * /*ctx*/) override { }

  virtual void enterShared_cmd_list(WatParser::Shared_cmd_listContext * /*ctx*/) override { }
  virtual void exitShared_cmd_list(WatParser::Shared_cmd_listContext * /*ctx*/) override { }

  virtual void enterMeta(WatParser::MetaContext * /*ctx*/) override { }
  virtual void exitMeta(WatParser::MetaContext * /*ctx*/) override { }

  virtual void enterLiteral_num(WatParser::Literal_numContext * /*ctx*/) override { }
  virtual void exitLiteral_num(WatParser::Literal_numContext * /*ctx*/) override { }

  virtual void enterLiteral_vec(WatParser::Literal_vecContext * /*ctx*/) override { }
  virtual void exitLiteral_vec(WatParser::Literal_vecContext * /*ctx*/) override { }

  virtual void enterLiteral_ref(WatParser::Literal_refContext * /*ctx*/) override { }
  virtual void exitLiteral_ref(WatParser::Literal_refContext * /*ctx*/) override { }

  virtual void enterLiteral(WatParser::LiteralContext * /*ctx*/) override { }
  virtual void exitLiteral(WatParser::LiteralContext * /*ctx*/) override { }

  virtual void enterLiteral_list(WatParser::Literal_listContext * /*ctx*/) override { }
  virtual void exitLiteral_list(WatParser::Literal_listContext * /*ctx*/) override { }

  virtual void enterNumpat(WatParser::NumpatContext * /*ctx*/) override { }
  virtual void exitNumpat(WatParser::NumpatContext * /*ctx*/) override { }

  virtual void enterResult(WatParser::ResultContext * /*ctx*/) override { }
  virtual void exitResult(WatParser::ResultContext * /*ctx*/) override { }

  virtual void enterScript(WatParser::ScriptContext * /*ctx*/) override { }
  virtual void exitScript(WatParser::ScriptContext * /*ctx*/) override { }

  virtual void enterModule(WatParser::ModuleContext * /*ctx*/) override { }
  virtual void exitModule(WatParser::ModuleContext * /*ctx*/) override { }


  virtual void enterEveryRule(antlr4::ParserRuleContext * /*ctx*/) override { }
  virtual void exitEveryRule(antlr4::ParserRuleContext * /*ctx*/) override { }
  virtual void visitTerminal(antlr4::tree::TerminalNode * /*node*/) override { }
  virtual void visitErrorNode(antlr4::tree::ErrorNode * /*node*/) override { }

};

