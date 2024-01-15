
// $antlr-format alignTrailingComments true, columnLimit 150, minEmptyLines 1, maxEmptyLinesToKeep 1, reflowComments false, useTab false
// $antlr-format allowShortRulesOnASingleLine false, allowShortBlocksOnASingleLine true, alignSemicolons hanging, alignColons hanging

parser grammar WatParser;

options {
    tokenVocab = WatLexer;
}

value
    : INT
    | FLOAT
    ;

/* Auxiliaries */

name
    : STRING_
    ;

/* Types */

ref_kind 
    : FUNC
    | EXTERN
    ;

ref_type 
    : FUNCREF
    | EXTERNREF
    ;

num_type
    : NUM_TYPE
    | ref_type
    ;

// elem_type
//     // : FUNCREF
//     : num_type num_type*
//     ;

global_type
    : num_type
    | LPAR MUT num_type RPAR
    ;

def_type
    : LPAR FUNC func_type RPAR
    ;

func_type
    : (LPAR (RESULT num_type* | PARAM num_type* | PARAM bind_var num_type) RPAR)*
    ;

table_type
    : NAT NAT? ref_type 
    ;

memory_type
    : NAT NAT?
    ;

type_use
    : LPAR TYPE var_ RPAR
    ;

/* Immediates */

num
    : NAT
    | INT
    | FLOAT
    ;

var_
    : NAT
    | VAR
    ;

bind_var
    : VAR
    ;

/* Instructions & Expressions */

instr
    : plain_instr
    | select_instr_instr
    | call_instr_instr
    | block_instr
    | expr
    ;

plain_instr
    : UNREACHABLE
    | NOP
    | DROP
    | SELECT
    | BR var_
    | BR_IF var_
    | BR_TABLE var_+
    | RETURN
    | CALL var_
    | LOCAL_GET var_
    | LOCAL_SET var_
    | LOCAL_TEE var_
    | GLOBAL_GET var_
    | GLOBAL_SET var_
    | TABLE_GET var_?
    | TABLE_SET var_?
    | TABLE_SIZE var_?
    | TABLE_GROW var_?
    | TABLE_FILL var_?
    | TABLE_COPY (var_ var_)?
    | TABLE_INIT var_ var_?
    | ELEM_DROP var_
    | LOAD OFFSET_EQ_NAT? ALIGN_EQ_NAT?
    | STORE OFFSET_EQ_NAT? ALIGN_EQ_NAT?
    | MEMORY_SIZE
    | MEMORY_GROW
    | CONST num
    | MEMORY_FILL
    | MEMORY_COPY
    | MEMORY_INIT var_
    | DATA_DROP var_
    | REF_NULL ref_kind
    | REF_IS_NULL
    | REF_FUNC var_
    | TEST
    | COMPARE
    | UNARY
    | BINARY
    | CONVERT
    ;

select_instr 
    : SELECT select_instr_results
    ;

select_instr_results 
    : (LPAR RESULT num_type* RPAR)*
    ;

select_instr_instr 
    : SELECT (LPAR RESULT num_type* RPAR)* instr
    ;

call_instr
    : CALL_INDIRECT var_ type_use? call_instr_params
    | CALL_INDIRECT type_use? call_instr_params
    
    ;

call_instr_params
    : (LPAR (PARAM | RESULT) num_type* RPAR)*
    ;

call_instr_instr
    : CALL_INDIRECT var_ type_use? call_instr_params_instr
    | CALL_INDIRECT type_use? call_instr_params_instr
    ;

call_instr_params_instr
    : (LPAR PARAM num_type* RPAR)* call_instr_results_instr
    ;

call_instr_results_instr
    : (LPAR RESULT num_type* RPAR)* instr
    ;

block_instr
    : (BLOCK | LOOP) bind_var? block END bind_var?
    | IF bind_var? block (ELSE bind_var? instr_list)? END bind_var?
    ;

// block_type
//    : LPAR RESULT num_type RPAR
//    ;

//    : block_type? instr_list
block
    : type_use? block_param_body
    ;

block_param_body 
    : (LPAR PARAM num_type* RPAR)* (LPAR RESULT num_type* RPAR)* instr_list
    ;

expr
    : LPAR expr1 RPAR
    ;

expr1
    : plain_instr expr*
    // | CALL_INDIRECT call_expr_type
    | SELECT select_expr_results
    | CALL_INDIRECT var_? call_expr_params
    | BLOCK bind_var? block
    | LOOP bind_var? block
    | IF bind_var? if_block
    ;

select_expr_results
    : (LPAR RESULT num_type* RPAR)* expr*
    ;

call_expr_type
    : type_use? call_expr_params
    ;

call_expr_params
    : (LPAR PARAM num_type* RPAR)* call_expr_results
    ;

call_expr_results
    : (LPAR RESULT num_type* RPAR)* expr*
    ;


//    : block_type if_block
//    | expr* LPAR THEN instr_list RPAR (LPAR ELSE instr_list RPAR)?
if_block
    : type_use (LPAR PARAM num_type* RPAR)* if_block_result_body
    ;

if_block_result_body
    : (LPAR RESULT num_type* RPAR)* expr* LPAR THEN instr_list RPAR (LPAR ELSE instr_list RPAR)?
    ;

instr_list
    : instr* call_instr?
    | select_instr
    ;

const_expr
    : instr_list
    ;

/* Functions */

func_
    : LPAR FUNC bind_var? func_fields RPAR
    ;

func_fields
    : type_use? func_fields_body
    | inline_import type_use? func_fields_import
    | inline_export func_fields
    ;

func_fields_import
    : (LPAR PARAM num_type* RPAR | LPAR PARAM bind_var num_type RPAR)* func_fields_import_result
    ;

func_fields_import_result
    : (LPAR RESULT num_type* RPAR)*
    ;

func_fields_body
    : (LPAR PARAM num_type* RPAR | LPAR PARAM bind_var num_type RPAR)* func_result_body
    ;

func_result_body
    : (LPAR RESULT num_type* RPAR)* func_body
    ;

func_body
//    : (LPAR LOCAL num_type* RPAR | LPAR LOCAL bind_var num_type RPAR)* instr_list
    : (LPAR LOCAL  (bind_var num_type| num_type*)  RPAR)* instr_list
    ;

/* Tables, Memories & Globals */
table_use
    : LPAR TABLE var_ RPAR
    ;

memory_use
    : LPAR MEMORY var_ RPAR
    ;


offset
    : LPAR OFFSET const_expr RPAR
    | expr
    ;

elem_kind
    : FUNC
    ;

elem_expr
    : LPAR ITEM const_expr RPAR
    | LPAR REF_NULL elem_kind RPAR  // bulk memory
    | LPAR REF_FUNC var_ RPAR   // bulk memory
    | expr
    ;

elem_expr_list
    : elem_expr*
    ;

elem_var_list
    : var_*
    ;

elem_list
    : elem_kind elem_var_list
    | ref_type elem_expr_list
    ;

elem
    // : LPAR ELEM var_? offset var_* RPAR
    // : LPAR ELEM bind_var? elem_list RPAR
    : LPAR ELEM bind_var? table_use offset elem_list RPAR
    // | LPAR ELEM bind_var?  elem_list RPAR
    | LPAR ELEM bind_var? (offset? | DECLARE) elem_list RPAR
    | LPAR ELEM bind_var? offset elem_var_list RPAR
    ;

table
    : LPAR TABLE bind_var? table_fields RPAR
    ;

table_fields
    : table_type
    | inline_import table_type
    | inline_export table_fields
    | ref_type LPAR ELEM (var_* | elem_expr elem_expr*) RPAR
    ;

data
    // : LPAR DATA var_? offset STRING_* RPAR
    : LPAR DATA bind_var? memory_use offset STRING_* RPAR
    | LPAR DATA bind_var? offset? STRING_* RPAR
    ;

memory
    : LPAR MEMORY bind_var? memory_fields RPAR
    ;

memory_fields
    : memory_type
    | inline_import memory_type
    | inline_export memory_fields
    | LPAR DATA STRING_* RPAR
    ;

sglobal
    : LPAR GLOBAL bind_var? global_fields RPAR
    ;

global_fields
    : global_type const_expr
    | inline_import global_type
    | inline_export global_fields
    ;

/* Imports & Exports */

import_desc
    : LPAR FUNC bind_var? (type_use|func_type) RPAR
//    | LPAR FUNC bind_var? func_type RPAR
    | LPAR TABLE bind_var? table_type RPAR
    | LPAR MEMORY bind_var? memory_type RPAR
    | LPAR GLOBAL bind_var? global_type RPAR
    ;

simport
    : LPAR IMPORT name name import_desc RPAR
    ;

inline_import
    : LPAR IMPORT name name RPAR
    ;

export_desc
    : LPAR (FUNC | TABLE | MEMORY | GLOBAL) var_ RPAR
//    | LPAR TABLE var_ RPAR
//    | LPAR MEMORY var_ RPAR
//    | LPAR GLOBAL var_ RPAR
    ;

export_
    : LPAR EXPORT name export_desc RPAR
    ;

inline_export
    : LPAR EXPORT name RPAR
    ;

/* Modules */

type_
    : def_type
    ;

type_def
    : LPAR TYPE bind_var? type_ RPAR
    ;

start_
    : LPAR START_ var_ RPAR
    ;

module_field
    : type_def
    | sglobal
    | table
    | memory
    | func_
    | elem
    | data
    | start_
    | simport
    | export_
    ;

module_
    : LPAR MODULE VAR? module_field* RPAR
    ;

/* Scripts */

script_module
    : module_
    | LPAR MODULE VAR? (BIN | QUOTE) STRING_* RPAR
    ;

action_
    : LPAR INVOKE VAR? name const_list RPAR
    | LPAR GET VAR? name RPAR
    ;

assertion
    : LPAR ASSERT_MALFORMED script_module STRING_ RPAR
    | LPAR ASSERT_INVALID script_module STRING_ RPAR
    | LPAR ASSERT_UNLINKABLE script_module STRING_ RPAR
    | LPAR ASSERT_TRAP script_module STRING_ RPAR
    | LPAR ASSERT_RETURN action_ result* RPAR
    // | LPAR ASSERT_RETURN_CANONICAL_NAN action_ RPAR
    // | LPAR ASSERT_RETURN_ARITHMETIC_NAN action_ RPAR
    | LPAR ASSERT_TRAP action_ STRING_ RPAR
    | LPAR ASSERT_EXHAUSTION action_ STRING_ RPAR
    ;

cmd
    : action_
    | assertion
    | script_module
    | LPAR REGISTER name VAR? RPAR
    | meta
    ;

meta
    : LPAR SCRIPT VAR? cmd* RPAR
    | LPAR INPUT VAR? STRING_ RPAR
    | LPAR OUTPUT VAR? STRING_ RPAR
    | LPAR OUTPUT VAR? RPAR
    ;

wconst
    : LPAR CONST num RPAR
    | LPAR REF_NULL ref_kind RPAR
    | LPAR REF_EXTERN NAT RPAR
    ;

const_list
    : wconst*
    ;

result
    : wconst
    | LPAR CONST NAN RPAR
    | LPAR (REF_FUNC | REF_EXTERN) RPAR
    ;


script
    : cmd* EOF
    | module_field+ EOF
    ;

module
    : module_ EOF
    | module_field* EOF
    ;