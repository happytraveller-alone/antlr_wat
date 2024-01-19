
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

null_opt
    : NULL? 
    ;

heap_type
    : ANY
    | NONE
    | EQ
    | I31
    | STRUCT
    | ARRAY
    | FUNC
    | NOFUNC
    | EXTERN
    | NOEXTERN
    | EXN
    | EXTERN
    | NAT
    | VAR
    ;

// // GC 没有保存
// ref_kind 
//     : FUNC
//     | EXTERN
//     ;

ref_type 
    : LPAR REF null_opt heap_type RPAR
    | EXTERNREF
    | FUNCREF
    | ANYREF
    | NULLREF
    | EQREF
    | I31REF
    | STRUCTREF
    | ARRAYREF
    | NULLFUNCREF
    | NULLEXTERNREF
    | EXNREF
    | EXTERNREF
    ;

val_type
    : ref_type
    | VEC_TYPE
    | NUM_TYPE
    ;

// elem_type
//     // : FUNCREF
//     : val_type val_type*
//     ;

global_type
    : val_type
    | LPAR MUT val_type RPAR
    ;

storage_type
    : val_type
    | PACK_TYPE
    ;

field_type
    : storage_type
    | LPAR MUT storage_type RPAR
    ;

struct_type
    : (LPAR FIELD (field_type* | bind_var field_type) RPAR)*
    ;

array_type
    : field_type
    ;

// GC 没有保存
// def_type
//     : LPAR FUNC func_type RPAR
//     ;

func_type
    : (LPAR (RESULT val_type* | PARAM val_type* | PARAM bind_var val_type) RPAR)*
    ;

str_type
    : LPAR (STRUCT struct_type | ARRAY array_type | FUNC func_type) RPAR
    ;

sub_type
    : str_type
    | LPAR SUB FINAL? var_* str_type RPAR
    ;

table_type
    : NAT NAT? ref_type 
    ;

memory_type
    : NAT NAT? SHARED?
    ;

type_use
    : LPAR TYPE var_ RPAR
    ;

/* Immediates */
nat32
    : NAT
    ;


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
// instr_list :
//   | /* empty */ { fun c -> [] }
//   | instr1 instr_list { fun c -> $1 c @ $2 c }
//   | select_instr_instr_list { $1 }
//   | call_instr_instr_list { $1 }

// instr1 :
//   | plain_instr { let at = at () in fun c -> [$1 c @@ at] }
//   | block_instr { let at = at () in fun c -> [$1 c @@ at] }
//   | expr { $1 }  /* Sugar */
instr_list
    : instr* (call_instr_instr_list? | select_instr_instr_list?)
    // | instr* 
    ;

instr
    : plain_instr 
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
    | BR_ON_NULL var_
    | BR_ON_CAST var_ ref_type ref_type
    | RETURN
    | CALL var_
    | CALL_REF var_
    | RETURN_CALL var_
    | RETURN_CALL_REF var_
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
    | VEC_LOAD OFFSET_EQ_NAT? ALIGN_EQ_NAT?
    | VEC_STORE OFFSET_EQ_NAT? ALIGN_EQ_NAT?
    | VEC_LOAD_LANE OFFSET_EQ_NAT? ALIGN_EQ_NAT? NAT
    | VEC_STORE_LANE OFFSET_EQ_NAT? ALIGN_EQ_NAT? NAT
    | MEMORY_SIZE
    | MEMORY_GROW
    | CONST num
    | MEMORY_FILL
    | MEMORY_COPY
    | MEMORY_INIT var_
    | DATA_DROP var_
    | REF_NULL heap_type
    | REF_IS_NULL
    | REF_FUNC var_
    | REF_AS_NON_NULL
    | REF_TEST ref_type
    | REF_CAST ref_type
    | REF_EQ
    | REF_I31
    | I31_GET
    | STRUCT_NEW var_
    | STRUCT_GET var_ var_
    | STRUCT_SET var_ var_
    | ARRAY_NEW var_
    | ARRAY_NEW_FIXED var_ nat32
    | ARRAY_NEW_ELEM var_ var_
    | ARRAY_NEW_DATA var_ var_
    | ARRAY_GET var_
    | ARRAY_SET var_
    | ARRAY_LEN
    | ARRAY_COPY var_ var_
    | ARRAY_FILL var_
    | ARRAY_INIT_DATA var_ var_
    | ARRAY_INIT_ELEM var_ var_
    | EXTERN_CONVERT 
    | TEST
    | COMPARE
    | UNARY
    | BINARY
    | CONVERT
    | VEC_CONST VEC_SHAPE num*
    | VEC_UNARY
    | VEC_BINARY
    | VEC_TERNARY
    | VEC_TEST
    | VEC_SHIFT
    | VEC_BITMASK
    | VEC_SHUFFLE num*
    | VEC_SPLAT
    | VEC_EXTRACT NAT
    | VEC_REPLACE NAT
    | MEMORY_ATOMIC_WAIT OFFSET_EQ_NAT? ALIGN_EQ_NAT?
    | MEMORY_ATOMIC_NOTIFY OFFSET_EQ_NAT? ALIGN_EQ_NAT?
    | ATOMIC_FENCE
    | ATOMIC_LOAD OFFSET_EQ_NAT? ALIGN_EQ_NAT?
    | ATOMIC_STORE OFFSET_EQ_NAT? ALIGN_EQ_NAT?
    | ATOMIC_RMW OFFSET_EQ_NAT? ALIGN_EQ_NAT?
    | ATOMIC_RMW_CMPXCHG OFFSET_EQ_NAT? ALIGN_EQ_NAT?
    | THROW var_
    | THROW_REF
    ;



select_instr_instr_list
    : SELECT (LPAR RESULT val_type* RPAR)* instr_list
    ;

call_instr_instr_list
    : CALL_INDIRECT var_? call_instr_type_instr_list
    | RETURN_CALL_INDIRECT var_? call_instr_type_instr_list
    ;

call_instr_type_instr_list
    : type_use? (LPAR PARAM val_type* RPAR)* (LPAR RESULT val_type* RPAR)* instr_list
    ;

block_instr
    : (BLOCK | LOOP) bind_var? block END bind_var?
    | IF bind_var? block (ELSE bind_var? instr_list)? END bind_var?
    | TRY_TABLE bind_var? handler_block END bind_var?
    ;

block
    : type_use? block_param_body
    ;

block_param_body 
    : (LPAR PARAM val_type* RPAR)* (LPAR RESULT val_type* RPAR)* instr_list
    ;

handler_block
    : type_use? handler_block_param_body
    ;

handler_block_param_body
    : (LPAR PARAM val_type* RPAR)* (LPAR RESULT val_type* RPAR)* handler_block_body
    ;

handler_block_body
    : (LPAR (CATCH var_ | CATCH_REF var_ | CATCH_ALL | CATCH_ALL_REF) var_ RPAR)* instr_list
    ;
expr
    : LPAR (plain_instr expr*
            | SELECT select_expr_results
            | CALL_INDIRECT var_? call_expr_type
            | RETURN_CALL_INDIRECT var_? call_expr_type
            | BLOCK bind_var? block
            | LOOP bind_var? block
            | IF bind_var? if_block
            | TRY_TABLE bind_var? try_block) RPAR
    ;


select_expr_results
    : (LPAR RESULT val_type* RPAR)* expr*
    ;

call_expr_type
    : type_use? call_expr_params
    ;

call_expr_params
    : (LPAR PARAM val_type* RPAR)* call_expr_results
    ;

call_expr_results
    : (LPAR RESULT val_type* RPAR)* expr*
    ;

if_block
    : type_use? (LPAR PARAM val_type* RPAR)* if_block_result_body
    ;

if_block_result_body
    : (LPAR RESULT val_type* RPAR)* expr* LPAR THEN instr_list RPAR (LPAR ELSE instr_list RPAR)?
    ;

try_block
    : type_use? try_block_param_body
    ;

try_block_param_body
    : (LPAR PARAM val_type* RPAR)* (LPAR RESULT val_type* RPAR)* try_block_handler_body
    ;

try_block_handler_body
    : (LPAR (CATCH var_ | CATCH_REF var_ | CATCH_ALL | CATCH_ALL_REF) var_ RPAR)* instr_list
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
    : (LPAR PARAM val_type* RPAR | LPAR PARAM bind_var val_type RPAR)* func_fields_import_result
    ;

func_fields_import_result
    : (LPAR RESULT val_type* RPAR)*
    ;

func_fields_body
    : (LPAR PARAM val_type* RPAR | LPAR PARAM bind_var val_type RPAR)* func_result_body
    ;

func_result_body
    : (LPAR RESULT val_type* RPAR)* func_body
    ;

func_body
//    : (LPAR LOCAL val_type* RPAR | LPAR LOCAL bind_var val_type RPAR)* instr_list
    : (LPAR LOCAL  (bind_var val_type| val_type*)  RPAR)* instr_list
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
    // | LPAR REF_NULL elem_kind RPAR  // bulk memory
    // | LPAR REF_FUNC var_ RPAR   // bulk memory
    | expr
    ;

// elem_expr_list
//     : elem_expr*
//     ;

// elem_var_list
//     : var_*
//     ;

elem_list
    : elem_kind var_*
    | ref_type elem_expr*
    ;

elem
    // : LPAR ELEM var_? offset var_* RPAR
    // : LPAR ELEM bind_var? elem_list RPAR
    // : LPAR ELEM bind_var?  elem_list RPAR
    // | LPAR ELEM bind_var?  elem_list RPAR
    : LPAR ELEM bind_var? (table_use offset | offset? | DECLARE) elem_list RPAR
    | LPAR ELEM bind_var? offset var_* RPAR
    ;

table
    : LPAR TABLE bind_var? table_fields RPAR
    ;

table_fields
    : table_type (instr instr_list)?
    | inline_import table_type
    | inline_export table_fields
    | ref_type LPAR ELEM (var_* | elem_expr*) RPAR
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

tag
    : LPAR TAG bind_var? tag_fields RPAR
    ;

tag_fields
    : inline_export* type_use? func_type
    | inline_export* inline_import type_use? tag_fields_import
    ;

tag_fields_import
    : (LPAR PARAM (val_type* | bind_var val_type) RPAR)* tag_fields_import_result
    ;

tag_fields_import_result
    : (LPAR RESULT val_type* RPAR)*
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
    | LPAR TAG bind_var? ( type_use | func_type ) RPAR
    ;

simport
    : LPAR IMPORT name name import_desc RPAR
    ;

inline_import
    : LPAR IMPORT name name RPAR
    ;

export_desc
    : LPAR (FUNC | TABLE | MEMORY | GLOBAL | TAG) var_ RPAR
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
type_def
    : LPAR TYPE bind_var? sub_type RPAR
    ;

rec_type
    : type_def
    | LPAR REC type_def* RPAR
    ;
type_
    : rec_type
    ;

// type_def
//     : LPAR TYPE bind_var? type_ RPAR
//     ;

start_
    : LPAR START_ var_ RPAR
    ;

module_field
    : (type_ | sglobal | table | memory | func_ | elem | data | start_ | simport | export_ | tag)+
    ;

module_
    : LPAR MODULE VAR? module_field* RPAR
    ;

inline_module
    : module_field?
    ;
/* Scripts */

script_module
    : module_
    | LPAR MODULE VAR? (BIN | QUOTE) STRING_* RPAR
    ;

action_
    : LPAR INVOKE VAR? name literal_list RPAR
    | LPAR GET VAR? name RPAR
    ;

assertion
    : LPAR ASSERT_MALFORMED script_module STRING_ RPAR
    | LPAR ASSERT_INVALID script_module STRING_ RPAR
    | LPAR ASSERT_UNLINKABLE script_module STRING_ RPAR
    | LPAR ASSERT_TRAP script_module STRING_ RPAR
    | LPAR ASSERT_RETURN action_ result* RPAR
    | LPAR ASSERT_EXCEPTION action_ RPAR
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
    | LPAR THREAD VAR? shared_cmd_list RPAR
    | LPAR WAIT VAR? RPAR
    | meta
    ;

shared_cmd_list
    : (LPAR SHARED LPAR MODULE VAR RPAR RPAR)* cmd*
    ;

meta
    : LPAR SCRIPT VAR? cmd* RPAR
    | LPAR INPUT VAR? STRING_ RPAR
    | LPAR OUTPUT VAR? STRING_ RPAR
    | LPAR OUTPUT VAR? RPAR
    ;

// wconst
//     : LPAR CONST num RPAR
//     | LPAR REF_NULL ref_kind RPAR
//     | LPAR REF_EXTERN NAT RPAR
//     ;
literal_num
    : LPAR CONST num RPAR
    ;

literal_vec
    : LPAR VEC_CONST VEC_SHAPE num* RPAR
    ;

literal_ref
    : LPAR REF_NULL heap_type RPAR
    | LPAR REF_HOST NAT RPAR
    | LPAR REF_EXTERN NAT RPAR
    ;

literal
    : literal_num
    | literal_vec
    | literal_ref
    ;

literal_list
    : literal*
    ;

numpat 
    : num
    | NAN_
    ;
// numpat_list
//     : numpat*
//     ;
result
    : literal_num
    | literal_ref
    | LPAR CONST NAN_ RPAR
    | LPAR (REF_FUNC 
            | REF
            | REF_EQ
            | REF_I31
            | REF_STRUCT
            | REF_ARRAY
            | REF_NULL
            | REF_EXTERN) RPAR
    | LPAR VEC_CONST VEC_SHAPE numpat* RPAR
    | LPAR EITHER result* RPAR
    ;


script
    : cmd* EOF
    | module_field+ EOF
    ;

module
    : module_ EOF
    | module_field* EOF
    ;