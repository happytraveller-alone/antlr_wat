// Generated from WatParser.g4 by ANTLR 4.13.1
import org.antlr.v4.runtime.tree.ParseTreeVisitor;

/**
 * This interface defines a complete generic visitor for a parse tree produced
 * by {@link WatParser}.
 *
 * @param <T> The return type of the visit operation. Use {@link Void} for
 * operations with no return type.
 */
public interface WatParserVisitor<T> extends ParseTreeVisitor<T> {
	/**
	 * Visit a parse tree produced by {@link WatParser#value}.
	 * @param ctx the parse tree
	 * @return the visitor result
	 */
	T visitValue(WatParser.ValueContext ctx);
	/**
	 * Visit a parse tree produced by {@link WatParser#name}.
	 * @param ctx the parse tree
	 * @return the visitor result
	 */
	T visitName(WatParser.NameContext ctx);
	/**
	 * Visit a parse tree produced by {@link WatParser#null_opt}.
	 * @param ctx the parse tree
	 * @return the visitor result
	 */
	T visitNull_opt(WatParser.Null_optContext ctx);
	/**
	 * Visit a parse tree produced by {@link WatParser#heap_type}.
	 * @param ctx the parse tree
	 * @return the visitor result
	 */
	T visitHeap_type(WatParser.Heap_typeContext ctx);
	/**
	 * Visit a parse tree produced by {@link WatParser#ref_type}.
	 * @param ctx the parse tree
	 * @return the visitor result
	 */
	T visitRef_type(WatParser.Ref_typeContext ctx);
	/**
	 * Visit a parse tree produced by {@link WatParser#val_type}.
	 * @param ctx the parse tree
	 * @return the visitor result
	 */
	T visitVal_type(WatParser.Val_typeContext ctx);
	/**
	 * Visit a parse tree produced by {@link WatParser#global_type}.
	 * @param ctx the parse tree
	 * @return the visitor result
	 */
	T visitGlobal_type(WatParser.Global_typeContext ctx);
	/**
	 * Visit a parse tree produced by {@link WatParser#storage_type}.
	 * @param ctx the parse tree
	 * @return the visitor result
	 */
	T visitStorage_type(WatParser.Storage_typeContext ctx);
	/**
	 * Visit a parse tree produced by {@link WatParser#field_type}.
	 * @param ctx the parse tree
	 * @return the visitor result
	 */
	T visitField_type(WatParser.Field_typeContext ctx);
	/**
	 * Visit a parse tree produced by {@link WatParser#struct_type}.
	 * @param ctx the parse tree
	 * @return the visitor result
	 */
	T visitStruct_type(WatParser.Struct_typeContext ctx);
	/**
	 * Visit a parse tree produced by {@link WatParser#array_type}.
	 * @param ctx the parse tree
	 * @return the visitor result
	 */
	T visitArray_type(WatParser.Array_typeContext ctx);
	/**
	 * Visit a parse tree produced by {@link WatParser#func_type}.
	 * @param ctx the parse tree
	 * @return the visitor result
	 */
	T visitFunc_type(WatParser.Func_typeContext ctx);
	/**
	 * Visit a parse tree produced by {@link WatParser#str_type}.
	 * @param ctx the parse tree
	 * @return the visitor result
	 */
	T visitStr_type(WatParser.Str_typeContext ctx);
	/**
	 * Visit a parse tree produced by {@link WatParser#sub_type}.
	 * @param ctx the parse tree
	 * @return the visitor result
	 */
	T visitSub_type(WatParser.Sub_typeContext ctx);
	/**
	 * Visit a parse tree produced by {@link WatParser#table_type}.
	 * @param ctx the parse tree
	 * @return the visitor result
	 */
	T visitTable_type(WatParser.Table_typeContext ctx);
	/**
	 * Visit a parse tree produced by {@link WatParser#memory_type}.
	 * @param ctx the parse tree
	 * @return the visitor result
	 */
	T visitMemory_type(WatParser.Memory_typeContext ctx);
	/**
	 * Visit a parse tree produced by {@link WatParser#type_use}.
	 * @param ctx the parse tree
	 * @return the visitor result
	 */
	T visitType_use(WatParser.Type_useContext ctx);
	/**
	 * Visit a parse tree produced by {@link WatParser#nat32}.
	 * @param ctx the parse tree
	 * @return the visitor result
	 */
	T visitNat32(WatParser.Nat32Context ctx);
	/**
	 * Visit a parse tree produced by {@link WatParser#num}.
	 * @param ctx the parse tree
	 * @return the visitor result
	 */
	T visitNum(WatParser.NumContext ctx);
	/**
	 * Visit a parse tree produced by {@link WatParser#var_}.
	 * @param ctx the parse tree
	 * @return the visitor result
	 */
	T visitVar_(WatParser.Var_Context ctx);
	/**
	 * Visit a parse tree produced by {@link WatParser#bind_var}.
	 * @param ctx the parse tree
	 * @return the visitor result
	 */
	T visitBind_var(WatParser.Bind_varContext ctx);
	/**
	 * Visit a parse tree produced by {@link WatParser#instr_list}.
	 * @param ctx the parse tree
	 * @return the visitor result
	 */
	T visitInstr_list(WatParser.Instr_listContext ctx);
	/**
	 * Visit a parse tree produced by {@link WatParser#instr}.
	 * @param ctx the parse tree
	 * @return the visitor result
	 */
	T visitInstr(WatParser.InstrContext ctx);
	/**
	 * Visit a parse tree produced by {@link WatParser#plain_instr}.
	 * @param ctx the parse tree
	 * @return the visitor result
	 */
	T visitPlain_instr(WatParser.Plain_instrContext ctx);
	/**
	 * Visit a parse tree produced by {@link WatParser#select_instr_instr_list}.
	 * @param ctx the parse tree
	 * @return the visitor result
	 */
	T visitSelect_instr_instr_list(WatParser.Select_instr_instr_listContext ctx);
	/**
	 * Visit a parse tree produced by {@link WatParser#call_instr_instr_list}.
	 * @param ctx the parse tree
	 * @return the visitor result
	 */
	T visitCall_instr_instr_list(WatParser.Call_instr_instr_listContext ctx);
	/**
	 * Visit a parse tree produced by {@link WatParser#call_instr_type_instr_list}.
	 * @param ctx the parse tree
	 * @return the visitor result
	 */
	T visitCall_instr_type_instr_list(WatParser.Call_instr_type_instr_listContext ctx);
	/**
	 * Visit a parse tree produced by {@link WatParser#block_instr}.
	 * @param ctx the parse tree
	 * @return the visitor result
	 */
	T visitBlock_instr(WatParser.Block_instrContext ctx);
	/**
	 * Visit a parse tree produced by {@link WatParser#block}.
	 * @param ctx the parse tree
	 * @return the visitor result
	 */
	T visitBlock(WatParser.BlockContext ctx);
	/**
	 * Visit a parse tree produced by {@link WatParser#block_param_body}.
	 * @param ctx the parse tree
	 * @return the visitor result
	 */
	T visitBlock_param_body(WatParser.Block_param_bodyContext ctx);
	/**
	 * Visit a parse tree produced by {@link WatParser#handler_block}.
	 * @param ctx the parse tree
	 * @return the visitor result
	 */
	T visitHandler_block(WatParser.Handler_blockContext ctx);
	/**
	 * Visit a parse tree produced by {@link WatParser#handler_block_param_body}.
	 * @param ctx the parse tree
	 * @return the visitor result
	 */
	T visitHandler_block_param_body(WatParser.Handler_block_param_bodyContext ctx);
	/**
	 * Visit a parse tree produced by {@link WatParser#handler_block_body}.
	 * @param ctx the parse tree
	 * @return the visitor result
	 */
	T visitHandler_block_body(WatParser.Handler_block_bodyContext ctx);
	/**
	 * Visit a parse tree produced by {@link WatParser#expr}.
	 * @param ctx the parse tree
	 * @return the visitor result
	 */
	T visitExpr(WatParser.ExprContext ctx);
	/**
	 * Visit a parse tree produced by {@link WatParser#expr1}.
	 * @param ctx the parse tree
	 * @return the visitor result
	 */
	T visitExpr1(WatParser.Expr1Context ctx);
	/**
	 * Visit a parse tree produced by {@link WatParser#select_expr_results}.
	 * @param ctx the parse tree
	 * @return the visitor result
	 */
	T visitSelect_expr_results(WatParser.Select_expr_resultsContext ctx);
	/**
	 * Visit a parse tree produced by {@link WatParser#call_expr_type}.
	 * @param ctx the parse tree
	 * @return the visitor result
	 */
	T visitCall_expr_type(WatParser.Call_expr_typeContext ctx);
	/**
	 * Visit a parse tree produced by {@link WatParser#call_expr_params}.
	 * @param ctx the parse tree
	 * @return the visitor result
	 */
	T visitCall_expr_params(WatParser.Call_expr_paramsContext ctx);
	/**
	 * Visit a parse tree produced by {@link WatParser#call_expr_results}.
	 * @param ctx the parse tree
	 * @return the visitor result
	 */
	T visitCall_expr_results(WatParser.Call_expr_resultsContext ctx);
	/**
	 * Visit a parse tree produced by {@link WatParser#if_block}.
	 * @param ctx the parse tree
	 * @return the visitor result
	 */
	T visitIf_block(WatParser.If_blockContext ctx);
	/**
	 * Visit a parse tree produced by {@link WatParser#if_block_result_body}.
	 * @param ctx the parse tree
	 * @return the visitor result
	 */
	T visitIf_block_result_body(WatParser.If_block_result_bodyContext ctx);
	/**
	 * Visit a parse tree produced by {@link WatParser#try_block}.
	 * @param ctx the parse tree
	 * @return the visitor result
	 */
	T visitTry_block(WatParser.Try_blockContext ctx);
	/**
	 * Visit a parse tree produced by {@link WatParser#try_block_param_body}.
	 * @param ctx the parse tree
	 * @return the visitor result
	 */
	T visitTry_block_param_body(WatParser.Try_block_param_bodyContext ctx);
	/**
	 * Visit a parse tree produced by {@link WatParser#try_block_handler_body}.
	 * @param ctx the parse tree
	 * @return the visitor result
	 */
	T visitTry_block_handler_body(WatParser.Try_block_handler_bodyContext ctx);
	/**
	 * Visit a parse tree produced by {@link WatParser#const_expr}.
	 * @param ctx the parse tree
	 * @return the visitor result
	 */
	T visitConst_expr(WatParser.Const_exprContext ctx);
	/**
	 * Visit a parse tree produced by {@link WatParser#func_}.
	 * @param ctx the parse tree
	 * @return the visitor result
	 */
	T visitFunc_(WatParser.Func_Context ctx);
	/**
	 * Visit a parse tree produced by {@link WatParser#func_fields}.
	 * @param ctx the parse tree
	 * @return the visitor result
	 */
	T visitFunc_fields(WatParser.Func_fieldsContext ctx);
	/**
	 * Visit a parse tree produced by {@link WatParser#func_fields_import}.
	 * @param ctx the parse tree
	 * @return the visitor result
	 */
	T visitFunc_fields_import(WatParser.Func_fields_importContext ctx);
	/**
	 * Visit a parse tree produced by {@link WatParser#func_fields_import_result}.
	 * @param ctx the parse tree
	 * @return the visitor result
	 */
	T visitFunc_fields_import_result(WatParser.Func_fields_import_resultContext ctx);
	/**
	 * Visit a parse tree produced by {@link WatParser#func_fields_body}.
	 * @param ctx the parse tree
	 * @return the visitor result
	 */
	T visitFunc_fields_body(WatParser.Func_fields_bodyContext ctx);
	/**
	 * Visit a parse tree produced by {@link WatParser#func_result_body}.
	 * @param ctx the parse tree
	 * @return the visitor result
	 */
	T visitFunc_result_body(WatParser.Func_result_bodyContext ctx);
	/**
	 * Visit a parse tree produced by {@link WatParser#func_body}.
	 * @param ctx the parse tree
	 * @return the visitor result
	 */
	T visitFunc_body(WatParser.Func_bodyContext ctx);
	/**
	 * Visit a parse tree produced by {@link WatParser#table_use}.
	 * @param ctx the parse tree
	 * @return the visitor result
	 */
	T visitTable_use(WatParser.Table_useContext ctx);
	/**
	 * Visit a parse tree produced by {@link WatParser#memory_use}.
	 * @param ctx the parse tree
	 * @return the visitor result
	 */
	T visitMemory_use(WatParser.Memory_useContext ctx);
	/**
	 * Visit a parse tree produced by {@link WatParser#offset}.
	 * @param ctx the parse tree
	 * @return the visitor result
	 */
	T visitOffset(WatParser.OffsetContext ctx);
	/**
	 * Visit a parse tree produced by {@link WatParser#elem_kind}.
	 * @param ctx the parse tree
	 * @return the visitor result
	 */
	T visitElem_kind(WatParser.Elem_kindContext ctx);
	/**
	 * Visit a parse tree produced by {@link WatParser#elem_expr}.
	 * @param ctx the parse tree
	 * @return the visitor result
	 */
	T visitElem_expr(WatParser.Elem_exprContext ctx);
	/**
	 * Visit a parse tree produced by {@link WatParser#elem_list}.
	 * @param ctx the parse tree
	 * @return the visitor result
	 */
	T visitElem_list(WatParser.Elem_listContext ctx);
	/**
	 * Visit a parse tree produced by {@link WatParser#elem}.
	 * @param ctx the parse tree
	 * @return the visitor result
	 */
	T visitElem(WatParser.ElemContext ctx);
	/**
	 * Visit a parse tree produced by {@link WatParser#table}.
	 * @param ctx the parse tree
	 * @return the visitor result
	 */
	T visitTable(WatParser.TableContext ctx);
	/**
	 * Visit a parse tree produced by {@link WatParser#table_fields}.
	 * @param ctx the parse tree
	 * @return the visitor result
	 */
	T visitTable_fields(WatParser.Table_fieldsContext ctx);
	/**
	 * Visit a parse tree produced by {@link WatParser#data}.
	 * @param ctx the parse tree
	 * @return the visitor result
	 */
	T visitData(WatParser.DataContext ctx);
	/**
	 * Visit a parse tree produced by {@link WatParser#memory}.
	 * @param ctx the parse tree
	 * @return the visitor result
	 */
	T visitMemory(WatParser.MemoryContext ctx);
	/**
	 * Visit a parse tree produced by {@link WatParser#memory_fields}.
	 * @param ctx the parse tree
	 * @return the visitor result
	 */
	T visitMemory_fields(WatParser.Memory_fieldsContext ctx);
	/**
	 * Visit a parse tree produced by {@link WatParser#tag}.
	 * @param ctx the parse tree
	 * @return the visitor result
	 */
	T visitTag(WatParser.TagContext ctx);
	/**
	 * Visit a parse tree produced by {@link WatParser#tag_fields}.
	 * @param ctx the parse tree
	 * @return the visitor result
	 */
	T visitTag_fields(WatParser.Tag_fieldsContext ctx);
	/**
	 * Visit a parse tree produced by {@link WatParser#tag_fields_import}.
	 * @param ctx the parse tree
	 * @return the visitor result
	 */
	T visitTag_fields_import(WatParser.Tag_fields_importContext ctx);
	/**
	 * Visit a parse tree produced by {@link WatParser#tag_fields_import_result}.
	 * @param ctx the parse tree
	 * @return the visitor result
	 */
	T visitTag_fields_import_result(WatParser.Tag_fields_import_resultContext ctx);
	/**
	 * Visit a parse tree produced by {@link WatParser#sglobal}.
	 * @param ctx the parse tree
	 * @return the visitor result
	 */
	T visitSglobal(WatParser.SglobalContext ctx);
	/**
	 * Visit a parse tree produced by {@link WatParser#global_fields}.
	 * @param ctx the parse tree
	 * @return the visitor result
	 */
	T visitGlobal_fields(WatParser.Global_fieldsContext ctx);
	/**
	 * Visit a parse tree produced by {@link WatParser#import_desc}.
	 * @param ctx the parse tree
	 * @return the visitor result
	 */
	T visitImport_desc(WatParser.Import_descContext ctx);
	/**
	 * Visit a parse tree produced by {@link WatParser#simport}.
	 * @param ctx the parse tree
	 * @return the visitor result
	 */
	T visitSimport(WatParser.SimportContext ctx);
	/**
	 * Visit a parse tree produced by {@link WatParser#inline_import}.
	 * @param ctx the parse tree
	 * @return the visitor result
	 */
	T visitInline_import(WatParser.Inline_importContext ctx);
	/**
	 * Visit a parse tree produced by {@link WatParser#export_desc}.
	 * @param ctx the parse tree
	 * @return the visitor result
	 */
	T visitExport_desc(WatParser.Export_descContext ctx);
	/**
	 * Visit a parse tree produced by {@link WatParser#export_}.
	 * @param ctx the parse tree
	 * @return the visitor result
	 */
	T visitExport_(WatParser.Export_Context ctx);
	/**
	 * Visit a parse tree produced by {@link WatParser#inline_export}.
	 * @param ctx the parse tree
	 * @return the visitor result
	 */
	T visitInline_export(WatParser.Inline_exportContext ctx);
	/**
	 * Visit a parse tree produced by {@link WatParser#type_def}.
	 * @param ctx the parse tree
	 * @return the visitor result
	 */
	T visitType_def(WatParser.Type_defContext ctx);
	/**
	 * Visit a parse tree produced by {@link WatParser#rec_type}.
	 * @param ctx the parse tree
	 * @return the visitor result
	 */
	T visitRec_type(WatParser.Rec_typeContext ctx);
	/**
	 * Visit a parse tree produced by {@link WatParser#type_}.
	 * @param ctx the parse tree
	 * @return the visitor result
	 */
	T visitType_(WatParser.Type_Context ctx);
	/**
	 * Visit a parse tree produced by {@link WatParser#start_}.
	 * @param ctx the parse tree
	 * @return the visitor result
	 */
	T visitStart_(WatParser.Start_Context ctx);
	/**
	 * Visit a parse tree produced by {@link WatParser#module_field}.
	 * @param ctx the parse tree
	 * @return the visitor result
	 */
	T visitModule_field(WatParser.Module_fieldContext ctx);
	/**
	 * Visit a parse tree produced by {@link WatParser#module_}.
	 * @param ctx the parse tree
	 * @return the visitor result
	 */
	T visitModule_(WatParser.Module_Context ctx);
	/**
	 * Visit a parse tree produced by {@link WatParser#inline_module}.
	 * @param ctx the parse tree
	 * @return the visitor result
	 */
	T visitInline_module(WatParser.Inline_moduleContext ctx);
	/**
	 * Visit a parse tree produced by {@link WatParser#script_module}.
	 * @param ctx the parse tree
	 * @return the visitor result
	 */
	T visitScript_module(WatParser.Script_moduleContext ctx);
	/**
	 * Visit a parse tree produced by {@link WatParser#action_}.
	 * @param ctx the parse tree
	 * @return the visitor result
	 */
	T visitAction_(WatParser.Action_Context ctx);
	/**
	 * Visit a parse tree produced by {@link WatParser#assertion}.
	 * @param ctx the parse tree
	 * @return the visitor result
	 */
	T visitAssertion(WatParser.AssertionContext ctx);
	/**
	 * Visit a parse tree produced by {@link WatParser#cmd}.
	 * @param ctx the parse tree
	 * @return the visitor result
	 */
	T visitCmd(WatParser.CmdContext ctx);
	/**
	 * Visit a parse tree produced by {@link WatParser#shared_cmd_list}.
	 * @param ctx the parse tree
	 * @return the visitor result
	 */
	T visitShared_cmd_list(WatParser.Shared_cmd_listContext ctx);
	/**
	 * Visit a parse tree produced by {@link WatParser#meta}.
	 * @param ctx the parse tree
	 * @return the visitor result
	 */
	T visitMeta(WatParser.MetaContext ctx);
	/**
	 * Visit a parse tree produced by {@link WatParser#literal_num}.
	 * @param ctx the parse tree
	 * @return the visitor result
	 */
	T visitLiteral_num(WatParser.Literal_numContext ctx);
	/**
	 * Visit a parse tree produced by {@link WatParser#literal_vec}.
	 * @param ctx the parse tree
	 * @return the visitor result
	 */
	T visitLiteral_vec(WatParser.Literal_vecContext ctx);
	/**
	 * Visit a parse tree produced by {@link WatParser#literal_ref}.
	 * @param ctx the parse tree
	 * @return the visitor result
	 */
	T visitLiteral_ref(WatParser.Literal_refContext ctx);
	/**
	 * Visit a parse tree produced by {@link WatParser#literal}.
	 * @param ctx the parse tree
	 * @return the visitor result
	 */
	T visitLiteral(WatParser.LiteralContext ctx);
	/**
	 * Visit a parse tree produced by {@link WatParser#literal_list}.
	 * @param ctx the parse tree
	 * @return the visitor result
	 */
	T visitLiteral_list(WatParser.Literal_listContext ctx);
	/**
	 * Visit a parse tree produced by {@link WatParser#numpat}.
	 * @param ctx the parse tree
	 * @return the visitor result
	 */
	T visitNumpat(WatParser.NumpatContext ctx);
	/**
	 * Visit a parse tree produced by {@link WatParser#result}.
	 * @param ctx the parse tree
	 * @return the visitor result
	 */
	T visitResult(WatParser.ResultContext ctx);
	/**
	 * Visit a parse tree produced by {@link WatParser#script}.
	 * @param ctx the parse tree
	 * @return the visitor result
	 */
	T visitScript(WatParser.ScriptContext ctx);
	/**
	 * Visit a parse tree produced by {@link WatParser#module}.
	 * @param ctx the parse tree
	 * @return the visitor result
	 */
	T visitModule(WatParser.ModuleContext ctx);
}