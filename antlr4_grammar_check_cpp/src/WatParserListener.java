// Generated from WatParser.g4 by ANTLR 4.13.1
import org.antlr.v4.runtime.tree.ParseTreeListener;

/**
 * This interface defines a complete listener for a parse tree produced by
 * {@link WatParser}.
 */
public interface WatParserListener extends ParseTreeListener {
	/**
	 * Enter a parse tree produced by {@link WatParser#value}.
	 * @param ctx the parse tree
	 */
	void enterValue(WatParser.ValueContext ctx);
	/**
	 * Exit a parse tree produced by {@link WatParser#value}.
	 * @param ctx the parse tree
	 */
	void exitValue(WatParser.ValueContext ctx);
	/**
	 * Enter a parse tree produced by {@link WatParser#name}.
	 * @param ctx the parse tree
	 */
	void enterName(WatParser.NameContext ctx);
	/**
	 * Exit a parse tree produced by {@link WatParser#name}.
	 * @param ctx the parse tree
	 */
	void exitName(WatParser.NameContext ctx);
	/**
	 * Enter a parse tree produced by {@link WatParser#null_opt}.
	 * @param ctx the parse tree
	 */
	void enterNull_opt(WatParser.Null_optContext ctx);
	/**
	 * Exit a parse tree produced by {@link WatParser#null_opt}.
	 * @param ctx the parse tree
	 */
	void exitNull_opt(WatParser.Null_optContext ctx);
	/**
	 * Enter a parse tree produced by {@link WatParser#heap_type}.
	 * @param ctx the parse tree
	 */
	void enterHeap_type(WatParser.Heap_typeContext ctx);
	/**
	 * Exit a parse tree produced by {@link WatParser#heap_type}.
	 * @param ctx the parse tree
	 */
	void exitHeap_type(WatParser.Heap_typeContext ctx);
	/**
	 * Enter a parse tree produced by {@link WatParser#ref_type}.
	 * @param ctx the parse tree
	 */
	void enterRef_type(WatParser.Ref_typeContext ctx);
	/**
	 * Exit a parse tree produced by {@link WatParser#ref_type}.
	 * @param ctx the parse tree
	 */
	void exitRef_type(WatParser.Ref_typeContext ctx);
	/**
	 * Enter a parse tree produced by {@link WatParser#val_type}.
	 * @param ctx the parse tree
	 */
	void enterVal_type(WatParser.Val_typeContext ctx);
	/**
	 * Exit a parse tree produced by {@link WatParser#val_type}.
	 * @param ctx the parse tree
	 */
	void exitVal_type(WatParser.Val_typeContext ctx);
	/**
	 * Enter a parse tree produced by {@link WatParser#global_type}.
	 * @param ctx the parse tree
	 */
	void enterGlobal_type(WatParser.Global_typeContext ctx);
	/**
	 * Exit a parse tree produced by {@link WatParser#global_type}.
	 * @param ctx the parse tree
	 */
	void exitGlobal_type(WatParser.Global_typeContext ctx);
	/**
	 * Enter a parse tree produced by {@link WatParser#storage_type}.
	 * @param ctx the parse tree
	 */
	void enterStorage_type(WatParser.Storage_typeContext ctx);
	/**
	 * Exit a parse tree produced by {@link WatParser#storage_type}.
	 * @param ctx the parse tree
	 */
	void exitStorage_type(WatParser.Storage_typeContext ctx);
	/**
	 * Enter a parse tree produced by {@link WatParser#field_type}.
	 * @param ctx the parse tree
	 */
	void enterField_type(WatParser.Field_typeContext ctx);
	/**
	 * Exit a parse tree produced by {@link WatParser#field_type}.
	 * @param ctx the parse tree
	 */
	void exitField_type(WatParser.Field_typeContext ctx);
	/**
	 * Enter a parse tree produced by {@link WatParser#struct_type}.
	 * @param ctx the parse tree
	 */
	void enterStruct_type(WatParser.Struct_typeContext ctx);
	/**
	 * Exit a parse tree produced by {@link WatParser#struct_type}.
	 * @param ctx the parse tree
	 */
	void exitStruct_type(WatParser.Struct_typeContext ctx);
	/**
	 * Enter a parse tree produced by {@link WatParser#array_type}.
	 * @param ctx the parse tree
	 */
	void enterArray_type(WatParser.Array_typeContext ctx);
	/**
	 * Exit a parse tree produced by {@link WatParser#array_type}.
	 * @param ctx the parse tree
	 */
	void exitArray_type(WatParser.Array_typeContext ctx);
	/**
	 * Enter a parse tree produced by {@link WatParser#func_type}.
	 * @param ctx the parse tree
	 */
	void enterFunc_type(WatParser.Func_typeContext ctx);
	/**
	 * Exit a parse tree produced by {@link WatParser#func_type}.
	 * @param ctx the parse tree
	 */
	void exitFunc_type(WatParser.Func_typeContext ctx);
	/**
	 * Enter a parse tree produced by {@link WatParser#str_type}.
	 * @param ctx the parse tree
	 */
	void enterStr_type(WatParser.Str_typeContext ctx);
	/**
	 * Exit a parse tree produced by {@link WatParser#str_type}.
	 * @param ctx the parse tree
	 */
	void exitStr_type(WatParser.Str_typeContext ctx);
	/**
	 * Enter a parse tree produced by {@link WatParser#sub_type}.
	 * @param ctx the parse tree
	 */
	void enterSub_type(WatParser.Sub_typeContext ctx);
	/**
	 * Exit a parse tree produced by {@link WatParser#sub_type}.
	 * @param ctx the parse tree
	 */
	void exitSub_type(WatParser.Sub_typeContext ctx);
	/**
	 * Enter a parse tree produced by {@link WatParser#table_type}.
	 * @param ctx the parse tree
	 */
	void enterTable_type(WatParser.Table_typeContext ctx);
	/**
	 * Exit a parse tree produced by {@link WatParser#table_type}.
	 * @param ctx the parse tree
	 */
	void exitTable_type(WatParser.Table_typeContext ctx);
	/**
	 * Enter a parse tree produced by {@link WatParser#memory_type}.
	 * @param ctx the parse tree
	 */
	void enterMemory_type(WatParser.Memory_typeContext ctx);
	/**
	 * Exit a parse tree produced by {@link WatParser#memory_type}.
	 * @param ctx the parse tree
	 */
	void exitMemory_type(WatParser.Memory_typeContext ctx);
	/**
	 * Enter a parse tree produced by {@link WatParser#type_use}.
	 * @param ctx the parse tree
	 */
	void enterType_use(WatParser.Type_useContext ctx);
	/**
	 * Exit a parse tree produced by {@link WatParser#type_use}.
	 * @param ctx the parse tree
	 */
	void exitType_use(WatParser.Type_useContext ctx);
	/**
	 * Enter a parse tree produced by {@link WatParser#nat32}.
	 * @param ctx the parse tree
	 */
	void enterNat32(WatParser.Nat32Context ctx);
	/**
	 * Exit a parse tree produced by {@link WatParser#nat32}.
	 * @param ctx the parse tree
	 */
	void exitNat32(WatParser.Nat32Context ctx);
	/**
	 * Enter a parse tree produced by {@link WatParser#num}.
	 * @param ctx the parse tree
	 */
	void enterNum(WatParser.NumContext ctx);
	/**
	 * Exit a parse tree produced by {@link WatParser#num}.
	 * @param ctx the parse tree
	 */
	void exitNum(WatParser.NumContext ctx);
	/**
	 * Enter a parse tree produced by {@link WatParser#var_}.
	 * @param ctx the parse tree
	 */
	void enterVar_(WatParser.Var_Context ctx);
	/**
	 * Exit a parse tree produced by {@link WatParser#var_}.
	 * @param ctx the parse tree
	 */
	void exitVar_(WatParser.Var_Context ctx);
	/**
	 * Enter a parse tree produced by {@link WatParser#bind_var}.
	 * @param ctx the parse tree
	 */
	void enterBind_var(WatParser.Bind_varContext ctx);
	/**
	 * Exit a parse tree produced by {@link WatParser#bind_var}.
	 * @param ctx the parse tree
	 */
	void exitBind_var(WatParser.Bind_varContext ctx);
	/**
	 * Enter a parse tree produced by {@link WatParser#instr_list}.
	 * @param ctx the parse tree
	 */
	void enterInstr_list(WatParser.Instr_listContext ctx);
	/**
	 * Exit a parse tree produced by {@link WatParser#instr_list}.
	 * @param ctx the parse tree
	 */
	void exitInstr_list(WatParser.Instr_listContext ctx);
	/**
	 * Enter a parse tree produced by {@link WatParser#instr}.
	 * @param ctx the parse tree
	 */
	void enterInstr(WatParser.InstrContext ctx);
	/**
	 * Exit a parse tree produced by {@link WatParser#instr}.
	 * @param ctx the parse tree
	 */
	void exitInstr(WatParser.InstrContext ctx);
	/**
	 * Enter a parse tree produced by {@link WatParser#plain_instr}.
	 * @param ctx the parse tree
	 */
	void enterPlain_instr(WatParser.Plain_instrContext ctx);
	/**
	 * Exit a parse tree produced by {@link WatParser#plain_instr}.
	 * @param ctx the parse tree
	 */
	void exitPlain_instr(WatParser.Plain_instrContext ctx);
	/**
	 * Enter a parse tree produced by {@link WatParser#select_instr_instr_list}.
	 * @param ctx the parse tree
	 */
	void enterSelect_instr_instr_list(WatParser.Select_instr_instr_listContext ctx);
	/**
	 * Exit a parse tree produced by {@link WatParser#select_instr_instr_list}.
	 * @param ctx the parse tree
	 */
	void exitSelect_instr_instr_list(WatParser.Select_instr_instr_listContext ctx);
	/**
	 * Enter a parse tree produced by {@link WatParser#call_instr_instr_list}.
	 * @param ctx the parse tree
	 */
	void enterCall_instr_instr_list(WatParser.Call_instr_instr_listContext ctx);
	/**
	 * Exit a parse tree produced by {@link WatParser#call_instr_instr_list}.
	 * @param ctx the parse tree
	 */
	void exitCall_instr_instr_list(WatParser.Call_instr_instr_listContext ctx);
	/**
	 * Enter a parse tree produced by {@link WatParser#call_instr_type_instr_list}.
	 * @param ctx the parse tree
	 */
	void enterCall_instr_type_instr_list(WatParser.Call_instr_type_instr_listContext ctx);
	/**
	 * Exit a parse tree produced by {@link WatParser#call_instr_type_instr_list}.
	 * @param ctx the parse tree
	 */
	void exitCall_instr_type_instr_list(WatParser.Call_instr_type_instr_listContext ctx);
	/**
	 * Enter a parse tree produced by {@link WatParser#block_instr}.
	 * @param ctx the parse tree
	 */
	void enterBlock_instr(WatParser.Block_instrContext ctx);
	/**
	 * Exit a parse tree produced by {@link WatParser#block_instr}.
	 * @param ctx the parse tree
	 */
	void exitBlock_instr(WatParser.Block_instrContext ctx);
	/**
	 * Enter a parse tree produced by {@link WatParser#block}.
	 * @param ctx the parse tree
	 */
	void enterBlock(WatParser.BlockContext ctx);
	/**
	 * Exit a parse tree produced by {@link WatParser#block}.
	 * @param ctx the parse tree
	 */
	void exitBlock(WatParser.BlockContext ctx);
	/**
	 * Enter a parse tree produced by {@link WatParser#block_param_body}.
	 * @param ctx the parse tree
	 */
	void enterBlock_param_body(WatParser.Block_param_bodyContext ctx);
	/**
	 * Exit a parse tree produced by {@link WatParser#block_param_body}.
	 * @param ctx the parse tree
	 */
	void exitBlock_param_body(WatParser.Block_param_bodyContext ctx);
	/**
	 * Enter a parse tree produced by {@link WatParser#handler_block}.
	 * @param ctx the parse tree
	 */
	void enterHandler_block(WatParser.Handler_blockContext ctx);
	/**
	 * Exit a parse tree produced by {@link WatParser#handler_block}.
	 * @param ctx the parse tree
	 */
	void exitHandler_block(WatParser.Handler_blockContext ctx);
	/**
	 * Enter a parse tree produced by {@link WatParser#handler_block_param_body}.
	 * @param ctx the parse tree
	 */
	void enterHandler_block_param_body(WatParser.Handler_block_param_bodyContext ctx);
	/**
	 * Exit a parse tree produced by {@link WatParser#handler_block_param_body}.
	 * @param ctx the parse tree
	 */
	void exitHandler_block_param_body(WatParser.Handler_block_param_bodyContext ctx);
	/**
	 * Enter a parse tree produced by {@link WatParser#handler_block_body}.
	 * @param ctx the parse tree
	 */
	void enterHandler_block_body(WatParser.Handler_block_bodyContext ctx);
	/**
	 * Exit a parse tree produced by {@link WatParser#handler_block_body}.
	 * @param ctx the parse tree
	 */
	void exitHandler_block_body(WatParser.Handler_block_bodyContext ctx);
	/**
	 * Enter a parse tree produced by {@link WatParser#expr}.
	 * @param ctx the parse tree
	 */
	void enterExpr(WatParser.ExprContext ctx);
	/**
	 * Exit a parse tree produced by {@link WatParser#expr}.
	 * @param ctx the parse tree
	 */
	void exitExpr(WatParser.ExprContext ctx);
	/**
	 * Enter a parse tree produced by {@link WatParser#expr1}.
	 * @param ctx the parse tree
	 */
	void enterExpr1(WatParser.Expr1Context ctx);
	/**
	 * Exit a parse tree produced by {@link WatParser#expr1}.
	 * @param ctx the parse tree
	 */
	void exitExpr1(WatParser.Expr1Context ctx);
	/**
	 * Enter a parse tree produced by {@link WatParser#select_expr_results}.
	 * @param ctx the parse tree
	 */
	void enterSelect_expr_results(WatParser.Select_expr_resultsContext ctx);
	/**
	 * Exit a parse tree produced by {@link WatParser#select_expr_results}.
	 * @param ctx the parse tree
	 */
	void exitSelect_expr_results(WatParser.Select_expr_resultsContext ctx);
	/**
	 * Enter a parse tree produced by {@link WatParser#call_expr_type}.
	 * @param ctx the parse tree
	 */
	void enterCall_expr_type(WatParser.Call_expr_typeContext ctx);
	/**
	 * Exit a parse tree produced by {@link WatParser#call_expr_type}.
	 * @param ctx the parse tree
	 */
	void exitCall_expr_type(WatParser.Call_expr_typeContext ctx);
	/**
	 * Enter a parse tree produced by {@link WatParser#call_expr_params}.
	 * @param ctx the parse tree
	 */
	void enterCall_expr_params(WatParser.Call_expr_paramsContext ctx);
	/**
	 * Exit a parse tree produced by {@link WatParser#call_expr_params}.
	 * @param ctx the parse tree
	 */
	void exitCall_expr_params(WatParser.Call_expr_paramsContext ctx);
	/**
	 * Enter a parse tree produced by {@link WatParser#call_expr_results}.
	 * @param ctx the parse tree
	 */
	void enterCall_expr_results(WatParser.Call_expr_resultsContext ctx);
	/**
	 * Exit a parse tree produced by {@link WatParser#call_expr_results}.
	 * @param ctx the parse tree
	 */
	void exitCall_expr_results(WatParser.Call_expr_resultsContext ctx);
	/**
	 * Enter a parse tree produced by {@link WatParser#if_block}.
	 * @param ctx the parse tree
	 */
	void enterIf_block(WatParser.If_blockContext ctx);
	/**
	 * Exit a parse tree produced by {@link WatParser#if_block}.
	 * @param ctx the parse tree
	 */
	void exitIf_block(WatParser.If_blockContext ctx);
	/**
	 * Enter a parse tree produced by {@link WatParser#if_block_result_body}.
	 * @param ctx the parse tree
	 */
	void enterIf_block_result_body(WatParser.If_block_result_bodyContext ctx);
	/**
	 * Exit a parse tree produced by {@link WatParser#if_block_result_body}.
	 * @param ctx the parse tree
	 */
	void exitIf_block_result_body(WatParser.If_block_result_bodyContext ctx);
	/**
	 * Enter a parse tree produced by {@link WatParser#try_block}.
	 * @param ctx the parse tree
	 */
	void enterTry_block(WatParser.Try_blockContext ctx);
	/**
	 * Exit a parse tree produced by {@link WatParser#try_block}.
	 * @param ctx the parse tree
	 */
	void exitTry_block(WatParser.Try_blockContext ctx);
	/**
	 * Enter a parse tree produced by {@link WatParser#try_block_param_body}.
	 * @param ctx the parse tree
	 */
	void enterTry_block_param_body(WatParser.Try_block_param_bodyContext ctx);
	/**
	 * Exit a parse tree produced by {@link WatParser#try_block_param_body}.
	 * @param ctx the parse tree
	 */
	void exitTry_block_param_body(WatParser.Try_block_param_bodyContext ctx);
	/**
	 * Enter a parse tree produced by {@link WatParser#try_block_handler_body}.
	 * @param ctx the parse tree
	 */
	void enterTry_block_handler_body(WatParser.Try_block_handler_bodyContext ctx);
	/**
	 * Exit a parse tree produced by {@link WatParser#try_block_handler_body}.
	 * @param ctx the parse tree
	 */
	void exitTry_block_handler_body(WatParser.Try_block_handler_bodyContext ctx);
	/**
	 * Enter a parse tree produced by {@link WatParser#const_expr}.
	 * @param ctx the parse tree
	 */
	void enterConst_expr(WatParser.Const_exprContext ctx);
	/**
	 * Exit a parse tree produced by {@link WatParser#const_expr}.
	 * @param ctx the parse tree
	 */
	void exitConst_expr(WatParser.Const_exprContext ctx);
	/**
	 * Enter a parse tree produced by {@link WatParser#func_}.
	 * @param ctx the parse tree
	 */
	void enterFunc_(WatParser.Func_Context ctx);
	/**
	 * Exit a parse tree produced by {@link WatParser#func_}.
	 * @param ctx the parse tree
	 */
	void exitFunc_(WatParser.Func_Context ctx);
	/**
	 * Enter a parse tree produced by {@link WatParser#func_fields}.
	 * @param ctx the parse tree
	 */
	void enterFunc_fields(WatParser.Func_fieldsContext ctx);
	/**
	 * Exit a parse tree produced by {@link WatParser#func_fields}.
	 * @param ctx the parse tree
	 */
	void exitFunc_fields(WatParser.Func_fieldsContext ctx);
	/**
	 * Enter a parse tree produced by {@link WatParser#func_fields_import}.
	 * @param ctx the parse tree
	 */
	void enterFunc_fields_import(WatParser.Func_fields_importContext ctx);
	/**
	 * Exit a parse tree produced by {@link WatParser#func_fields_import}.
	 * @param ctx the parse tree
	 */
	void exitFunc_fields_import(WatParser.Func_fields_importContext ctx);
	/**
	 * Enter a parse tree produced by {@link WatParser#func_fields_import_result}.
	 * @param ctx the parse tree
	 */
	void enterFunc_fields_import_result(WatParser.Func_fields_import_resultContext ctx);
	/**
	 * Exit a parse tree produced by {@link WatParser#func_fields_import_result}.
	 * @param ctx the parse tree
	 */
	void exitFunc_fields_import_result(WatParser.Func_fields_import_resultContext ctx);
	/**
	 * Enter a parse tree produced by {@link WatParser#func_fields_body}.
	 * @param ctx the parse tree
	 */
	void enterFunc_fields_body(WatParser.Func_fields_bodyContext ctx);
	/**
	 * Exit a parse tree produced by {@link WatParser#func_fields_body}.
	 * @param ctx the parse tree
	 */
	void exitFunc_fields_body(WatParser.Func_fields_bodyContext ctx);
	/**
	 * Enter a parse tree produced by {@link WatParser#func_result_body}.
	 * @param ctx the parse tree
	 */
	void enterFunc_result_body(WatParser.Func_result_bodyContext ctx);
	/**
	 * Exit a parse tree produced by {@link WatParser#func_result_body}.
	 * @param ctx the parse tree
	 */
	void exitFunc_result_body(WatParser.Func_result_bodyContext ctx);
	/**
	 * Enter a parse tree produced by {@link WatParser#func_body}.
	 * @param ctx the parse tree
	 */
	void enterFunc_body(WatParser.Func_bodyContext ctx);
	/**
	 * Exit a parse tree produced by {@link WatParser#func_body}.
	 * @param ctx the parse tree
	 */
	void exitFunc_body(WatParser.Func_bodyContext ctx);
	/**
	 * Enter a parse tree produced by {@link WatParser#table_use}.
	 * @param ctx the parse tree
	 */
	void enterTable_use(WatParser.Table_useContext ctx);
	/**
	 * Exit a parse tree produced by {@link WatParser#table_use}.
	 * @param ctx the parse tree
	 */
	void exitTable_use(WatParser.Table_useContext ctx);
	/**
	 * Enter a parse tree produced by {@link WatParser#memory_use}.
	 * @param ctx the parse tree
	 */
	void enterMemory_use(WatParser.Memory_useContext ctx);
	/**
	 * Exit a parse tree produced by {@link WatParser#memory_use}.
	 * @param ctx the parse tree
	 */
	void exitMemory_use(WatParser.Memory_useContext ctx);
	/**
	 * Enter a parse tree produced by {@link WatParser#offset}.
	 * @param ctx the parse tree
	 */
	void enterOffset(WatParser.OffsetContext ctx);
	/**
	 * Exit a parse tree produced by {@link WatParser#offset}.
	 * @param ctx the parse tree
	 */
	void exitOffset(WatParser.OffsetContext ctx);
	/**
	 * Enter a parse tree produced by {@link WatParser#elem_kind}.
	 * @param ctx the parse tree
	 */
	void enterElem_kind(WatParser.Elem_kindContext ctx);
	/**
	 * Exit a parse tree produced by {@link WatParser#elem_kind}.
	 * @param ctx the parse tree
	 */
	void exitElem_kind(WatParser.Elem_kindContext ctx);
	/**
	 * Enter a parse tree produced by {@link WatParser#elem_expr}.
	 * @param ctx the parse tree
	 */
	void enterElem_expr(WatParser.Elem_exprContext ctx);
	/**
	 * Exit a parse tree produced by {@link WatParser#elem_expr}.
	 * @param ctx the parse tree
	 */
	void exitElem_expr(WatParser.Elem_exprContext ctx);
	/**
	 * Enter a parse tree produced by {@link WatParser#elem_list}.
	 * @param ctx the parse tree
	 */
	void enterElem_list(WatParser.Elem_listContext ctx);
	/**
	 * Exit a parse tree produced by {@link WatParser#elem_list}.
	 * @param ctx the parse tree
	 */
	void exitElem_list(WatParser.Elem_listContext ctx);
	/**
	 * Enter a parse tree produced by {@link WatParser#elem}.
	 * @param ctx the parse tree
	 */
	void enterElem(WatParser.ElemContext ctx);
	/**
	 * Exit a parse tree produced by {@link WatParser#elem}.
	 * @param ctx the parse tree
	 */
	void exitElem(WatParser.ElemContext ctx);
	/**
	 * Enter a parse tree produced by {@link WatParser#table}.
	 * @param ctx the parse tree
	 */
	void enterTable(WatParser.TableContext ctx);
	/**
	 * Exit a parse tree produced by {@link WatParser#table}.
	 * @param ctx the parse tree
	 */
	void exitTable(WatParser.TableContext ctx);
	/**
	 * Enter a parse tree produced by {@link WatParser#table_fields}.
	 * @param ctx the parse tree
	 */
	void enterTable_fields(WatParser.Table_fieldsContext ctx);
	/**
	 * Exit a parse tree produced by {@link WatParser#table_fields}.
	 * @param ctx the parse tree
	 */
	void exitTable_fields(WatParser.Table_fieldsContext ctx);
	/**
	 * Enter a parse tree produced by {@link WatParser#data}.
	 * @param ctx the parse tree
	 */
	void enterData(WatParser.DataContext ctx);
	/**
	 * Exit a parse tree produced by {@link WatParser#data}.
	 * @param ctx the parse tree
	 */
	void exitData(WatParser.DataContext ctx);
	/**
	 * Enter a parse tree produced by {@link WatParser#memory}.
	 * @param ctx the parse tree
	 */
	void enterMemory(WatParser.MemoryContext ctx);
	/**
	 * Exit a parse tree produced by {@link WatParser#memory}.
	 * @param ctx the parse tree
	 */
	void exitMemory(WatParser.MemoryContext ctx);
	/**
	 * Enter a parse tree produced by {@link WatParser#memory_fields}.
	 * @param ctx the parse tree
	 */
	void enterMemory_fields(WatParser.Memory_fieldsContext ctx);
	/**
	 * Exit a parse tree produced by {@link WatParser#memory_fields}.
	 * @param ctx the parse tree
	 */
	void exitMemory_fields(WatParser.Memory_fieldsContext ctx);
	/**
	 * Enter a parse tree produced by {@link WatParser#tag}.
	 * @param ctx the parse tree
	 */
	void enterTag(WatParser.TagContext ctx);
	/**
	 * Exit a parse tree produced by {@link WatParser#tag}.
	 * @param ctx the parse tree
	 */
	void exitTag(WatParser.TagContext ctx);
	/**
	 * Enter a parse tree produced by {@link WatParser#tag_fields}.
	 * @param ctx the parse tree
	 */
	void enterTag_fields(WatParser.Tag_fieldsContext ctx);
	/**
	 * Exit a parse tree produced by {@link WatParser#tag_fields}.
	 * @param ctx the parse tree
	 */
	void exitTag_fields(WatParser.Tag_fieldsContext ctx);
	/**
	 * Enter a parse tree produced by {@link WatParser#tag_fields_import}.
	 * @param ctx the parse tree
	 */
	void enterTag_fields_import(WatParser.Tag_fields_importContext ctx);
	/**
	 * Exit a parse tree produced by {@link WatParser#tag_fields_import}.
	 * @param ctx the parse tree
	 */
	void exitTag_fields_import(WatParser.Tag_fields_importContext ctx);
	/**
	 * Enter a parse tree produced by {@link WatParser#tag_fields_import_result}.
	 * @param ctx the parse tree
	 */
	void enterTag_fields_import_result(WatParser.Tag_fields_import_resultContext ctx);
	/**
	 * Exit a parse tree produced by {@link WatParser#tag_fields_import_result}.
	 * @param ctx the parse tree
	 */
	void exitTag_fields_import_result(WatParser.Tag_fields_import_resultContext ctx);
	/**
	 * Enter a parse tree produced by {@link WatParser#sglobal}.
	 * @param ctx the parse tree
	 */
	void enterSglobal(WatParser.SglobalContext ctx);
	/**
	 * Exit a parse tree produced by {@link WatParser#sglobal}.
	 * @param ctx the parse tree
	 */
	void exitSglobal(WatParser.SglobalContext ctx);
	/**
	 * Enter a parse tree produced by {@link WatParser#global_fields}.
	 * @param ctx the parse tree
	 */
	void enterGlobal_fields(WatParser.Global_fieldsContext ctx);
	/**
	 * Exit a parse tree produced by {@link WatParser#global_fields}.
	 * @param ctx the parse tree
	 */
	void exitGlobal_fields(WatParser.Global_fieldsContext ctx);
	/**
	 * Enter a parse tree produced by {@link WatParser#import_desc}.
	 * @param ctx the parse tree
	 */
	void enterImport_desc(WatParser.Import_descContext ctx);
	/**
	 * Exit a parse tree produced by {@link WatParser#import_desc}.
	 * @param ctx the parse tree
	 */
	void exitImport_desc(WatParser.Import_descContext ctx);
	/**
	 * Enter a parse tree produced by {@link WatParser#simport}.
	 * @param ctx the parse tree
	 */
	void enterSimport(WatParser.SimportContext ctx);
	/**
	 * Exit a parse tree produced by {@link WatParser#simport}.
	 * @param ctx the parse tree
	 */
	void exitSimport(WatParser.SimportContext ctx);
	/**
	 * Enter a parse tree produced by {@link WatParser#inline_import}.
	 * @param ctx the parse tree
	 */
	void enterInline_import(WatParser.Inline_importContext ctx);
	/**
	 * Exit a parse tree produced by {@link WatParser#inline_import}.
	 * @param ctx the parse tree
	 */
	void exitInline_import(WatParser.Inline_importContext ctx);
	/**
	 * Enter a parse tree produced by {@link WatParser#export_desc}.
	 * @param ctx the parse tree
	 */
	void enterExport_desc(WatParser.Export_descContext ctx);
	/**
	 * Exit a parse tree produced by {@link WatParser#export_desc}.
	 * @param ctx the parse tree
	 */
	void exitExport_desc(WatParser.Export_descContext ctx);
	/**
	 * Enter a parse tree produced by {@link WatParser#export_}.
	 * @param ctx the parse tree
	 */
	void enterExport_(WatParser.Export_Context ctx);
	/**
	 * Exit a parse tree produced by {@link WatParser#export_}.
	 * @param ctx the parse tree
	 */
	void exitExport_(WatParser.Export_Context ctx);
	/**
	 * Enter a parse tree produced by {@link WatParser#inline_export}.
	 * @param ctx the parse tree
	 */
	void enterInline_export(WatParser.Inline_exportContext ctx);
	/**
	 * Exit a parse tree produced by {@link WatParser#inline_export}.
	 * @param ctx the parse tree
	 */
	void exitInline_export(WatParser.Inline_exportContext ctx);
	/**
	 * Enter a parse tree produced by {@link WatParser#type_def}.
	 * @param ctx the parse tree
	 */
	void enterType_def(WatParser.Type_defContext ctx);
	/**
	 * Exit a parse tree produced by {@link WatParser#type_def}.
	 * @param ctx the parse tree
	 */
	void exitType_def(WatParser.Type_defContext ctx);
	/**
	 * Enter a parse tree produced by {@link WatParser#rec_type}.
	 * @param ctx the parse tree
	 */
	void enterRec_type(WatParser.Rec_typeContext ctx);
	/**
	 * Exit a parse tree produced by {@link WatParser#rec_type}.
	 * @param ctx the parse tree
	 */
	void exitRec_type(WatParser.Rec_typeContext ctx);
	/**
	 * Enter a parse tree produced by {@link WatParser#type_}.
	 * @param ctx the parse tree
	 */
	void enterType_(WatParser.Type_Context ctx);
	/**
	 * Exit a parse tree produced by {@link WatParser#type_}.
	 * @param ctx the parse tree
	 */
	void exitType_(WatParser.Type_Context ctx);
	/**
	 * Enter a parse tree produced by {@link WatParser#start_}.
	 * @param ctx the parse tree
	 */
	void enterStart_(WatParser.Start_Context ctx);
	/**
	 * Exit a parse tree produced by {@link WatParser#start_}.
	 * @param ctx the parse tree
	 */
	void exitStart_(WatParser.Start_Context ctx);
	/**
	 * Enter a parse tree produced by {@link WatParser#module_field}.
	 * @param ctx the parse tree
	 */
	void enterModule_field(WatParser.Module_fieldContext ctx);
	/**
	 * Exit a parse tree produced by {@link WatParser#module_field}.
	 * @param ctx the parse tree
	 */
	void exitModule_field(WatParser.Module_fieldContext ctx);
	/**
	 * Enter a parse tree produced by {@link WatParser#module_}.
	 * @param ctx the parse tree
	 */
	void enterModule_(WatParser.Module_Context ctx);
	/**
	 * Exit a parse tree produced by {@link WatParser#module_}.
	 * @param ctx the parse tree
	 */
	void exitModule_(WatParser.Module_Context ctx);
	/**
	 * Enter a parse tree produced by {@link WatParser#inline_module}.
	 * @param ctx the parse tree
	 */
	void enterInline_module(WatParser.Inline_moduleContext ctx);
	/**
	 * Exit a parse tree produced by {@link WatParser#inline_module}.
	 * @param ctx the parse tree
	 */
	void exitInline_module(WatParser.Inline_moduleContext ctx);
	/**
	 * Enter a parse tree produced by {@link WatParser#script_module}.
	 * @param ctx the parse tree
	 */
	void enterScript_module(WatParser.Script_moduleContext ctx);
	/**
	 * Exit a parse tree produced by {@link WatParser#script_module}.
	 * @param ctx the parse tree
	 */
	void exitScript_module(WatParser.Script_moduleContext ctx);
	/**
	 * Enter a parse tree produced by {@link WatParser#action_}.
	 * @param ctx the parse tree
	 */
	void enterAction_(WatParser.Action_Context ctx);
	/**
	 * Exit a parse tree produced by {@link WatParser#action_}.
	 * @param ctx the parse tree
	 */
	void exitAction_(WatParser.Action_Context ctx);
	/**
	 * Enter a parse tree produced by {@link WatParser#assertion}.
	 * @param ctx the parse tree
	 */
	void enterAssertion(WatParser.AssertionContext ctx);
	/**
	 * Exit a parse tree produced by {@link WatParser#assertion}.
	 * @param ctx the parse tree
	 */
	void exitAssertion(WatParser.AssertionContext ctx);
	/**
	 * Enter a parse tree produced by {@link WatParser#cmd}.
	 * @param ctx the parse tree
	 */
	void enterCmd(WatParser.CmdContext ctx);
	/**
	 * Exit a parse tree produced by {@link WatParser#cmd}.
	 * @param ctx the parse tree
	 */
	void exitCmd(WatParser.CmdContext ctx);
	/**
	 * Enter a parse tree produced by {@link WatParser#shared_cmd_list}.
	 * @param ctx the parse tree
	 */
	void enterShared_cmd_list(WatParser.Shared_cmd_listContext ctx);
	/**
	 * Exit a parse tree produced by {@link WatParser#shared_cmd_list}.
	 * @param ctx the parse tree
	 */
	void exitShared_cmd_list(WatParser.Shared_cmd_listContext ctx);
	/**
	 * Enter a parse tree produced by {@link WatParser#meta}.
	 * @param ctx the parse tree
	 */
	void enterMeta(WatParser.MetaContext ctx);
	/**
	 * Exit a parse tree produced by {@link WatParser#meta}.
	 * @param ctx the parse tree
	 */
	void exitMeta(WatParser.MetaContext ctx);
	/**
	 * Enter a parse tree produced by {@link WatParser#literal_num}.
	 * @param ctx the parse tree
	 */
	void enterLiteral_num(WatParser.Literal_numContext ctx);
	/**
	 * Exit a parse tree produced by {@link WatParser#literal_num}.
	 * @param ctx the parse tree
	 */
	void exitLiteral_num(WatParser.Literal_numContext ctx);
	/**
	 * Enter a parse tree produced by {@link WatParser#literal_vec}.
	 * @param ctx the parse tree
	 */
	void enterLiteral_vec(WatParser.Literal_vecContext ctx);
	/**
	 * Exit a parse tree produced by {@link WatParser#literal_vec}.
	 * @param ctx the parse tree
	 */
	void exitLiteral_vec(WatParser.Literal_vecContext ctx);
	/**
	 * Enter a parse tree produced by {@link WatParser#literal_ref}.
	 * @param ctx the parse tree
	 */
	void enterLiteral_ref(WatParser.Literal_refContext ctx);
	/**
	 * Exit a parse tree produced by {@link WatParser#literal_ref}.
	 * @param ctx the parse tree
	 */
	void exitLiteral_ref(WatParser.Literal_refContext ctx);
	/**
	 * Enter a parse tree produced by {@link WatParser#literal}.
	 * @param ctx the parse tree
	 */
	void enterLiteral(WatParser.LiteralContext ctx);
	/**
	 * Exit a parse tree produced by {@link WatParser#literal}.
	 * @param ctx the parse tree
	 */
	void exitLiteral(WatParser.LiteralContext ctx);
	/**
	 * Enter a parse tree produced by {@link WatParser#literal_list}.
	 * @param ctx the parse tree
	 */
	void enterLiteral_list(WatParser.Literal_listContext ctx);
	/**
	 * Exit a parse tree produced by {@link WatParser#literal_list}.
	 * @param ctx the parse tree
	 */
	void exitLiteral_list(WatParser.Literal_listContext ctx);
	/**
	 * Enter a parse tree produced by {@link WatParser#numpat}.
	 * @param ctx the parse tree
	 */
	void enterNumpat(WatParser.NumpatContext ctx);
	/**
	 * Exit a parse tree produced by {@link WatParser#numpat}.
	 * @param ctx the parse tree
	 */
	void exitNumpat(WatParser.NumpatContext ctx);
	/**
	 * Enter a parse tree produced by {@link WatParser#result}.
	 * @param ctx the parse tree
	 */
	void enterResult(WatParser.ResultContext ctx);
	/**
	 * Exit a parse tree produced by {@link WatParser#result}.
	 * @param ctx the parse tree
	 */
	void exitResult(WatParser.ResultContext ctx);
	/**
	 * Enter a parse tree produced by {@link WatParser#script}.
	 * @param ctx the parse tree
	 */
	void enterScript(WatParser.ScriptContext ctx);
	/**
	 * Exit a parse tree produced by {@link WatParser#script}.
	 * @param ctx the parse tree
	 */
	void exitScript(WatParser.ScriptContext ctx);
	/**
	 * Enter a parse tree produced by {@link WatParser#module}.
	 * @param ctx the parse tree
	 */
	void enterModule(WatParser.ModuleContext ctx);
	/**
	 * Exit a parse tree produced by {@link WatParser#module}.
	 * @param ctx the parse tree
	 */
	void exitModule(WatParser.ModuleContext ctx);
}