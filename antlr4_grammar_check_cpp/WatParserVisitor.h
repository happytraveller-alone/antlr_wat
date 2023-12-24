
// Generated from WatParser.g4 by ANTLR 4.13.1

#pragma once


#include "antlr4-runtime.h"
#include "WatParser.h"



/**
 * This class defines an abstract visitor for a parse tree
 * produced by WatParser.
 */
class  WatParserVisitor : public antlr4::tree::AbstractParseTreeVisitor {
public:

  /**
   * Visit parse trees produced by WatParser.
   */
    virtual std::any visitValue(WatParser::ValueContext *context) = 0;

    virtual std::any visitName(WatParser::NameContext *context) = 0;

    virtual std::any visitValue_type(WatParser::Value_typeContext *context) = 0;

    virtual std::any visitElem_type(WatParser::Elem_typeContext *context) = 0;

    virtual std::any visitGlobal_type(WatParser::Global_typeContext *context) = 0;

    virtual std::any visitDef_type(WatParser::Def_typeContext *context) = 0;

    virtual std::any visitFunc_type(WatParser::Func_typeContext *context) = 0;

    virtual std::any visitTable_type(WatParser::Table_typeContext *context) = 0;

    virtual std::any visitMemory_type(WatParser::Memory_typeContext *context) = 0;

    virtual std::any visitType_use(WatParser::Type_useContext *context) = 0;

    virtual std::any visitLiteral(WatParser::LiteralContext *context) = 0;

    virtual std::any visitVar_(WatParser::Var_Context *context) = 0;

    virtual std::any visitBind_var(WatParser::Bind_varContext *context) = 0;

    virtual std::any visitInstr(WatParser::InstrContext *context) = 0;

    virtual std::any visitPlain_instr(WatParser::Plain_instrContext *context) = 0;

    virtual std::any visitCall_instr(WatParser::Call_instrContext *context) = 0;

    virtual std::any visitCall_instr_params(WatParser::Call_instr_paramsContext *context) = 0;

    virtual std::any visitCall_instr_instr(WatParser::Call_instr_instrContext *context) = 0;

    virtual std::any visitCall_instr_params_instr(WatParser::Call_instr_params_instrContext *context) = 0;

    virtual std::any visitCall_instr_results_instr(WatParser::Call_instr_results_instrContext *context) = 0;

    virtual std::any visitBlock_instr(WatParser::Block_instrContext *context) = 0;

    virtual std::any visitBlock_type(WatParser::Block_typeContext *context) = 0;

    virtual std::any visitBlock(WatParser::BlockContext *context) = 0;

    virtual std::any visitExpr(WatParser::ExprContext *context) = 0;

    virtual std::any visitExpr1(WatParser::Expr1Context *context) = 0;

    virtual std::any visitCall_expr_type(WatParser::Call_expr_typeContext *context) = 0;

    virtual std::any visitCall_expr_params(WatParser::Call_expr_paramsContext *context) = 0;

    virtual std::any visitCall_expr_results(WatParser::Call_expr_resultsContext *context) = 0;

    virtual std::any visitIf_block(WatParser::If_blockContext *context) = 0;

    virtual std::any visitInstr_list(WatParser::Instr_listContext *context) = 0;

    virtual std::any visitConst_expr(WatParser::Const_exprContext *context) = 0;

    virtual std::any visitFunc_(WatParser::Func_Context *context) = 0;

    virtual std::any visitFunc_fields(WatParser::Func_fieldsContext *context) = 0;

    virtual std::any visitFunc_fields_import(WatParser::Func_fields_importContext *context) = 0;

    virtual std::any visitFunc_fields_import_result(WatParser::Func_fields_import_resultContext *context) = 0;

    virtual std::any visitFunc_fields_body(WatParser::Func_fields_bodyContext *context) = 0;

    virtual std::any visitFunc_result_body(WatParser::Func_result_bodyContext *context) = 0;

    virtual std::any visitFunc_body(WatParser::Func_bodyContext *context) = 0;

    virtual std::any visitOffset(WatParser::OffsetContext *context) = 0;

    virtual std::any visitElem(WatParser::ElemContext *context) = 0;

    virtual std::any visitTable(WatParser::TableContext *context) = 0;

    virtual std::any visitTable_fields(WatParser::Table_fieldsContext *context) = 0;

    virtual std::any visitData(WatParser::DataContext *context) = 0;

    virtual std::any visitMemory(WatParser::MemoryContext *context) = 0;

    virtual std::any visitMemory_fields(WatParser::Memory_fieldsContext *context) = 0;

    virtual std::any visitSglobal(WatParser::SglobalContext *context) = 0;

    virtual std::any visitGlobal_fields(WatParser::Global_fieldsContext *context) = 0;

    virtual std::any visitImport_desc(WatParser::Import_descContext *context) = 0;

    virtual std::any visitSimport(WatParser::SimportContext *context) = 0;

    virtual std::any visitInline_import(WatParser::Inline_importContext *context) = 0;

    virtual std::any visitExport_desc(WatParser::Export_descContext *context) = 0;

    virtual std::any visitExport_(WatParser::Export_Context *context) = 0;

    virtual std::any visitInline_export(WatParser::Inline_exportContext *context) = 0;

    virtual std::any visitType_(WatParser::Type_Context *context) = 0;

    virtual std::any visitType_def(WatParser::Type_defContext *context) = 0;

    virtual std::any visitStart_(WatParser::Start_Context *context) = 0;

    virtual std::any visitModule_field(WatParser::Module_fieldContext *context) = 0;

    virtual std::any visitModule_(WatParser::Module_Context *context) = 0;

    virtual std::any visitScript_module(WatParser::Script_moduleContext *context) = 0;

    virtual std::any visitAction_(WatParser::Action_Context *context) = 0;

    virtual std::any visitAssertion(WatParser::AssertionContext *context) = 0;

    virtual std::any visitCmd(WatParser::CmdContext *context) = 0;

    virtual std::any visitMeta(WatParser::MetaContext *context) = 0;

    virtual std::any visitWconst(WatParser::WconstContext *context) = 0;

    virtual std::any visitConst_list(WatParser::Const_listContext *context) = 0;

    virtual std::any visitScript(WatParser::ScriptContext *context) = 0;

    virtual std::any visitModule(WatParser::ModuleContext *context) = 0;


};

