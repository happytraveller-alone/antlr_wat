%token LPAR RPAR
%token NAT INT FLOAT STRING VAR
%token NUM_TYPE FUNCREF EXTERNREF EXTERN MUT
%token UNREACHABLE NOP DROP SELECT
%token BLOCK END IF THEN ELSE LOOP BR BR_IF BR_TABLE
%token CALL CALL_INDIRECT RETURN
%token LOCAL_GET LOCAL_SET LOCAL_TEE GLOBAL_GET GLOBAL_SET
%token TABLE_GET TABLE_SET
%token TABLE_SIZE TABLE_GROW TABLE_FILL TABLE_COPY TABLE_INIT ELEM_DROP
%token MEMORY_SIZE MEMORY_GROW MEMORY_FILL MEMORY_COPY MEMORY_INIT DATA_DROP
%token LOAD STORE OFFSET_EQ_NAT ALIGN_EQ_NAT
%token CONST UNARY BINARY TEST COMPARE CONVERT
%token REF_NULL REF_FUNC REF_EXTERN REF_IS_NULL
%token FUNC START TYPE PARAM RESULT LOCAL GLOBAL
%token TABLE ELEM MEMORY DATA DECLARE OFFSET ITEM IMPORT EXPORT
%token MODULE BIN QUOTE
%token SCRIPT REGISTER INVOKE GET
%token ASSERT_MALFORMED ASSERT_INVALID ASSERT_SOFT_INVALID ASSERT_UNLINKABLE
%token ASSERT_RETURN ASSERT_TRAP ASSERT_EXHAUSTION
%token NAN
%token INPUT OUTPUT
%token EOF

%token<string> NAT
%token<string> INT
%token<string> FLOAT
%token<string> STRING
%token<string> VAR
%token<Types.num_type> NUM_TYPE
%token<string Source.phrase -> Ast.instr' * Values.num> CONST
%token<Ast.instr'> UNARY
%token<Ast.instr'> BINARY
%token<Ast.instr'> TEST
%token<Ast.instr'> COMPARE
%token<Ast.instr'> CONVERT
%token<int option -> Memory.offset -> Ast.instr'> LOAD
%token<int option -> Memory.offset -> Ast.instr'> STORE
%token<string> OFFSET_EQ_NAT
%token<string> ALIGN_EQ_NAT

%token<Script.nan> NAN

%nonassoc LOW
%nonassoc VAR

%start script script1 module1
%type<Script.script> script
%type<Script.script> script1
%type<Script.var option * Script.definition> module1

%%

/* Auxiliaries */

name :
  | STRING { name $1 (at ()) }

string_list :
  | /* empty */ { "" }
  | string_list STRING { $1 ^ $2 }


/* Types */

ref_kind :
  | FUNC { FuncRefType }
  | EXTERN { ExternRefType }

ref_type :
  | FUNCREF { FuncRefType }
  | EXTERNREF { ExternRefType }

value_type :
  | NUM_TYPE { NumType $1 }
  | ref_type { RefType $1 }

value_type_list :
  | /* empty */ { [] }
  | value_type value_type_list { $1 :: $2 }

global_type :
  | value_type { GlobalType ($1, Immutable) }
  | LPAR MUT value_type RPAR { GlobalType ($3, Mutable) }

def_type :
  | LPAR FUNC func_type RPAR { $3 }

func_type :
  | /* empty */
    { FuncType ([], []) }
  | LPAR RESULT value_type_list RPAR func_type
    { let FuncType (ins, out) = $5 in
      if ins <> [] then error (at ()) "result before parameter";
      FuncType (ins, $3 @ out) }
  | LPAR PARAM value_type_list RPAR func_type
    { let FuncType (ins, out) = $5 in FuncType ($3 @ ins, out) }
  | LPAR PARAM bind_var value_type RPAR func_type  /* Sugar */
    { let FuncType (ins, out) = $6 in FuncType ($4 :: ins, out) }

table_type :
  | limits ref_type { TableType ($1, $2) }

memory_type :
  | limits { MemoryType $1 }

limits :
  | NAT { {min = nat32 $1 (ati 1); max = None} }
  | NAT NAT { {min = nat32 $1 (ati 1); max = Some (nat32 $2 (ati 2))} }

type_use :
  | LPAR TYPE var RPAR { $3 }


/* Immediates */

num :
  | NAT { $1 @@ at () }
  | INT { $1 @@ at () }
  | FLOAT { $1 @@ at () }

var :
  | NAT { let at = at () in fun c lookup -> nat32 $1 at @@ at }
  | VAR { let at = at () in fun c lookup -> lookup c ($1 @@ at) @@ at }

var_list :
  | /* empty */ { fun c lookup -> [] }
  | var var_list { fun c lookup -> $1 c lookup :: $2 c lookup }

bind_var_opt :
  | /* empty */ { fun c anon bind -> anon c }
  | bind_var { fun c anon bind -> bind c $1 }  /* Sugar */

bind_var :
  | VAR { $1 @@ at () }

labeling_opt :
  | /* empty */ %prec LOW
    { fun c xs ->
      List.iter (fun x -> error x.at "mismatching label") xs;
      anon_label c }
  | bind_var
    { fun c xs ->
      List.iter
        (fun x -> if x.it <> $1.it then error x.at "mismatching label") xs;
      bind_label c $1 }

labeling_end_opt :
  | /* empty */ %prec LOW { [] }
  | bind_var { [$1] }

offset_opt :
  | /* empty */ { 0l }
  | OFFSET_EQ_NAT { nat32 $1 (at ()) }

align_opt :
  | /* empty */ { None }
  | ALIGN_EQ_NAT
    { let n = nat $1 (at ()) in
      if not (Lib.Int.is_power_of_two n) then
        error (at ()) "alignment must be a power of two";
      Some (Lib.Int.log2 n) }


/* Instructions & Expressions */

instr :
  | plain_instr { let at = at () in fun c -> [$1 c @@ at] }
  | select_instr_instr { fun c -> let e, es = $1 c in e :: es }
  | call_instr_instr { fun c -> let e, es = $1 c in e :: es }
  | block_instr { let at = at () in fun c -> [$1 c @@ at] }
  | expr { $1 } /* Sugar */

plain_instr :
  | UNREACHABLE { fun c -> unreachable }
  | NOP { fun c -> nop }
  | DROP { fun c -> drop }
  | BR var { fun c -> br ($2 c label) }
  | BR_IF var { fun c -> br_if ($2 c label) }
  | BR_TABLE var var_list
    { fun c -> let xs, x = Lib.List.split_last ($2 c label :: $3 c label) in
      br_table xs x }
  | RETURN { fun c -> return }
  | CALL var { fun c -> call ($2 c func) }
  | LOCAL_GET var { fun c -> local_get ($2 c local) }
  | LOCAL_SET var { fun c -> local_set ($2 c local) }
  | LOCAL_TEE var { fun c -> local_tee ($2 c local) }
  | GLOBAL_GET var { fun c -> global_get ($2 c global) }
  | GLOBAL_SET var { fun c -> global_set ($2 c global) }
  | TABLE_GET var { fun c -> table_get ($2 c table) }
  | TABLE_SET var { fun c -> table_set ($2 c table) }
  | TABLE_SIZE var { fun c -> table_size ($2 c table) }
  | TABLE_GROW var { fun c -> table_grow ($2 c table) }
  | TABLE_FILL var { fun c -> table_fill ($2 c table) }
  | TABLE_COPY var var { fun c -> table_copy ($2 c table) ($3 c table) }
  | TABLE_INIT var var { fun c -> table_init ($2 c table) ($3 c elem) }
  | TABLE_GET { let at = at () in fun c -> table_get (0l @@ at) }  /* Sugar */
  | TABLE_SET { let at = at () in fun c -> table_set (0l @@ at) }  /* Sugar */
  | TABLE_SIZE { let at = at () in fun c -> table_size (0l @@ at) }  /* Sugar */
  | TABLE_GROW { let at = at () in fun c -> table_grow (0l @@ at) }  /* Sugar */
  | TABLE_FILL { let at = at () in fun c -> table_fill (0l @@ at) }  /* Sugar */
  | TABLE_COPY  /* Sugar */
    { let at = at () in fun c -> table_copy (0l @@ at) (0l @@ at) }
  | TABLE_INIT var  /* Sugar */
    { let at = at () in fun c -> table_init (0l @@ at) ($2 c elem) }
  | ELEM_DROP var { fun c -> elem_drop ($2 c elem) }
  | LOAD offset_opt align_opt { fun c -> $1 $3 $2 }
  | STORE offset_opt align_opt { fun c -> $1 $3 $2 }
  | MEMORY_SIZE { fun c -> memory_size }
  | MEMORY_GROW { fun c -> memory_grow }
  | MEMORY_FILL { fun c -> memory_fill }
  | MEMORY_COPY { fun c -> memory_copy }
  | MEMORY_INIT var { fun c -> memory_init ($2 c data) }
  | DATA_DROP var { fun c -> data_drop ($2 c data) }
  | REF_NULL ref_kind { fun c -> ref_null $2 }
  | REF_IS_NULL { fun c -> ref_is_null }
  | REF_FUNC var { fun c -> ref_func ($2 c func) }
  | CONST num { fun c -> fst (num $1 $2) }
  | TEST { fun c -> $1 }
  | COMPARE { fun c -> $1 }
  | UNARY { fun c -> $1 }
  | BINARY { fun c -> $1 }
  | CONVERT { fun c -> $1 }


select_instr :
  | SELECT select_instr_results
    { let at = at () in fun c -> let b, ts = $2 in
      select (if b then (Some ts) else None) @@ at }

select_instr_results :
  | LPAR RESULT value_type_list RPAR select_instr_results
    { let _, ts = $5 in true, $3 @ ts }
  | /* empty */
    { false, [] }

select_instr_instr :
  | SELECT select_instr_results_instr
    { let at1 = ati 1 in
      fun c -> let b, ts, es = $2 c in
      select (if b then (Some ts) else None) @@ at1, es }

select_instr_results_instr :
  | LPAR RESULT value_type_list RPAR select_instr_results_instr
    { fun c -> let _, ts, es = $5 c in true, $3 @ ts, es }
  | instr
    { fun c -> false, [], $1 c }


call_instr :
  | CALL_INDIRECT var call_instr_type
    { let at = at () in fun c -> call_indirect ($2 c table) ($3 c) @@ at }
  | CALL_INDIRECT call_instr_type  /* Sugar */
    { let at = at () in fun c -> call_indirect (0l @@ at) ($2 c) @@ at }

call_instr_type :
  | type_use call_instr_params
    { let at1 = ati 1 in
      fun c ->
      match $2 c with
      | FuncType ([], []) -> $1 c type_
      | ft -> inline_type_explicit c ($1 c type_) ft at1 }
  | call_instr_params
    { let at = at () in fun c -> inline_type c ($1 c) at }

call_instr_params :
  | LPAR PARAM value_type_list RPAR call_instr_params
    { fun c -> let FuncType (ts1, ts2) = $5 c in FuncType ($3 @ ts1, ts2) }
  | call_instr_results
    { fun c -> FuncType ([], $1 c) }

call_instr_results :
  | LPAR RESULT value_type_list RPAR call_instr_results
    { fun c -> $3 @ $5 c }
  | /* empty */
    { fun c -> [] }


call_instr_instr :
  | CALL_INDIRECT var call_instr_type_instr
    { let at1 = ati 1 in
      fun c -> let x, es = $3 c in call_indirect ($2 c table) x @@ at1, es }
  | CALL_INDIRECT call_instr_type_instr  /* Sugar */
    { let at1 = ati 1 in
      fun c -> let x, es = $2 c in call_indirect (0l @@ at1) x @@ at1, es }

call_instr_type_instr :
  | type_use call_instr_params_instr
    { let at1 = ati 1 in
      fun c ->
      match $2 c with
      | FuncType ([], []), es -> $1 c type_, es
      | ft, es -> inline_type_explicit c ($1 c type_) ft at1, es }
  | call_instr_params_instr
    { let at = at () in
      fun c -> let ft, es = $1 c in inline_type c ft at, es }

call_instr_params_instr :
  | LPAR PARAM value_type_list RPAR call_instr_params_instr
    { fun c ->
      let FuncType (ts1, ts2), es = $5 c in FuncType ($3 @ ts1, ts2), es }
  | call_instr_results_instr
    { fun c -> let ts, es = $1 c in FuncType ([], ts), es }

call_instr_results_instr :
  | LPAR RESULT value_type_list RPAR call_instr_results_instr
    { fun c -> let ts, es = $5 c in $3 @ ts, es }
  | instr
    { fun c -> [], $1 c }


block_instr :
  | BLOCK labeling_opt block END labeling_end_opt
    { fun c -> let c' = $2 c $5 in let bt, es = $3 c' in block bt es }
  | LOOP labeling_opt block END labeling_end_opt
    { fun c -> let c' = $2 c $5 in let bt, es = $3 c' in loop bt es }
  | IF labeling_opt block END labeling_end_opt
    { fun c -> let c' = $2 c $5 in let bt, es = $3 c' in if_ bt es [] }
  | IF labeling_opt block ELSE labeling_end_opt instr_list END labeling_end_opt
    { fun c -> let c' = $2 c ($5 @ $8) in
      let ts, es1 = $3 c' in if_ ts es1 ($6 c') }

block :
  | type_use block_param_body
    { let at1 = ati 1 in
      fun c ->
      VarBlockType (inline_type_explicit c ($1 c type_) (fst $2) at1),
      snd $2 c }
  | block_param_body  /* Sugar */
    { let at = at () in
      fun c ->
      let bt =
        match fst $1 with
        | FuncType ([], []) -> ValBlockType None
        | FuncType ([], [t]) -> ValBlockType (Some t)
        | ft ->  VarBlockType (inline_type c ft at)
      in bt, snd $1 c }

block_param_body :
  | block_result_body { $1 }
  | LPAR PARAM value_type_list RPAR block_param_body
    { let FuncType (ins, out) = fst $5 in
      FuncType ($3 @ ins, out), snd $5 }

block_result_body :
  | instr_list { FuncType ([], []), $1 }
  | LPAR RESULT value_type_list RPAR block_result_body
    { let FuncType (ins, out) = fst $5 in
      FuncType (ins, $3 @ out), snd $5 }


expr :  /* Sugar */
  | LPAR expr1 RPAR
    { let at = at () in fun c -> let es, e' = $2 c in es @ [e' @@ at] }

expr1 :  /* Sugar */
  | plain_instr expr_list { fun c -> $2 c, $1 c }
  | SELECT select_expr_results
    { fun c -> let b, ts, es = $2 c in es, select (if b then (Some ts) else None) }
  | CALL_INDIRECT var call_expr_type
    { fun c -> let x, es = $3 c in es, call_indirect ($2 c table) x }
  | CALL_INDIRECT call_expr_type  /* Sugar */
    { let at1 = ati 1 in
      fun c -> let x, es = $2 c in es, call_indirect (0l @@ at1) x }
  | BLOCK labeling_opt block
    { fun c -> let c' = $2 c [] in let bt, es = $3 c' in [], block bt es }
  | LOOP labeling_opt block
    { fun c -> let c' = $2 c [] in let bt, es = $3 c' in [], loop bt es }
  | IF labeling_opt if_block
    { fun c -> let c' = $2 c [] in
      let bt, (es, es1, es2) = $3 c c' in es, if_ bt es1 es2 }

select_expr_results :
  | LPAR RESULT value_type_list RPAR select_expr_results
    { fun c -> let _, ts, es = $5 c in true, $3 @ ts, es }
  | expr_list
    { fun c -> false, [], $1 c }

call_expr_type :
  | type_use call_expr_params
    { let at1 = ati 1 in
      fun c ->
      match $2 c with
      | FuncType ([], []), es -> $1 c type_, es
      | ft, es -> inline_type_explicit c ($1 c type_) ft at1, es }
  | call_expr_params
    { let at1 = ati 1 in
      fun c -> let ft, es = $1 c in inline_type c ft at1, es }

call_expr_params :
  | LPAR PARAM value_type_list RPAR call_expr_params
    { fun c ->
      let FuncType (ts1, ts2), es = $5 c in FuncType ($3 @ ts1, ts2), es }
  | call_expr_results
    { fun c -> let ts, es = $1 c in FuncType ([], ts), es }

call_expr_results :
  | LPAR RESULT value_type_list RPAR call_expr_results
    { fun c -> let ts, es = $5 c in $3 @ ts, es }
  | expr_list
    { fun c -> [], $1 c }


if_block :
  | type_use if_block_param_body
    { let at = at () in
      fun c c' ->
      VarBlockType (inline_type_explicit c ($1 c type_) (fst $2) at),
      snd $2 c c' }
  | if_block_param_body  /* Sugar */
    { let at = at () in
      fun c c' ->
      let bt =
        match fst $1 with
        | FuncType ([], []) -> ValBlockType None
        | FuncType ([], [t]) -> ValBlockType (Some t)
        | ft ->  VarBlockType (inline_type c ft at)
      in bt, snd $1 c c' }

if_block_param_body :
  | if_block_result_body { $1 }
  | LPAR PARAM value_type_list RPAR if_block_param_body
    { let FuncType (ins, out) = fst $5 in
      FuncType ($3 @ ins, out), snd $5 }

if_block_result_body :
  | if_ { FuncType ([], []), $1 }
  | LPAR RESULT value_type_list RPAR if_block_result_body
    { let FuncType (ins, out) = fst $5 in
      FuncType (ins, $3 @ out), snd $5 }

if_ :
  | expr if_
    { fun c c' -> let es = $1 c in let es0, es1, es2 = $2 c c' in
      es @ es0, es1, es2 }
  | LPAR THEN instr_list RPAR LPAR ELSE instr_list RPAR  /* Sugar */
    { fun c c' -> [], $3 c', $7 c' }
  | LPAR THEN instr_list RPAR  /* Sugar */
    { fun c c' -> [], $3 c', [] }

instr_list :
  | /* empty */ { fun c -> [] }
  | select_instr { fun c -> [$1 c] }
  | call_instr { fun c -> [$1 c] }
  | instr instr_list { fun c -> $1 c @ $2 c }

expr_list :
  | /* empty */ { fun c -> [] }
  | expr expr_list { fun c -> $1 c @ $2 c }

const_expr :
  | instr_list { let at = at () in fun c -> $1 c @@ at }


/* Functions */

func :
  | LPAR FUNC bind_var_opt func_fields RPAR
    { let at = at () in
      fun c -> let x = $3 c anon_func bind_func @@ at in fun () -> $4 c x at }

func_fields :
  | type_use func_fields_body
    { fun c x at ->
      let c' = enter_func c in
      let y = inline_type_explicit c' ($1 c' type_) (fst $2) at in
      [{(snd $2 c') with ftype = y} @@ at], [], [] }
  | func_fields_body  /* Sugar */
    { fun c x at ->
      let c' = enter_func c in
      let y = inline_type c' (fst $1) at in
      [{(snd $1 c') with ftype = y} @@ at], [], [] }
  | inline_import type_use func_fields_import  /* Sugar */
    { fun c x at ->
      let y = inline_type_explicit c ($2 c type_) $3 at in
      [],
      [{ module_name = fst $1; item_name = snd $1;
         idesc = FuncImport y @@ at } @@ at ], [] }
  | inline_import func_fields_import  /* Sugar */
    { fun c x at ->
      let y = inline_type c $2 at in
      [],
      [{ module_name = fst $1; item_name = snd $1;
         idesc = FuncImport y @@ at } @@ at ], [] }
  | inline_export func_fields  /* Sugar */
    { fun c x at ->
      let fns, ims, exs = $2 c x at in fns, ims, $1 (FuncExport x) c :: exs }

func_fields_import :  /* Sugar */
  | func_fields_import_result { $1 }
  | LPAR PARAM value_type_list RPAR func_fields_import
    { let FuncType (ins, out) = $5 in FuncType ($3 @ ins, out) }
  | LPAR PARAM bind_var value_type RPAR func_fields_import  /* Sugar */
    { let FuncType (ins, out) = $6 in FuncType ($4 :: ins, out) }

func_fields_import_result :  /* Sugar */
  | /* empty */ { FuncType ([], []) }
  | LPAR RESULT value_type_list RPAR func_fields_import_result
    { let FuncType (ins, out) = $5 in FuncType (ins, $3 @ out) }

func_fields_body :
  | func_result_body { $1 }
  | LPAR PARAM value_type_list RPAR func_fields_body
    { let FuncType (ins, out) = fst $5 in
      FuncType ($3 @ ins, out),
      fun c -> anon_locals c (lazy $3); snd $5 c }
  | LPAR PARAM bind_var value_type RPAR func_fields_body  /* Sugar */
    { let FuncType (ins, out) = fst $6 in
      FuncType ($4 :: ins, out),
      fun c -> ignore (bind_local c $3); snd $6 c }

func_result_body :
  | func_body { FuncType ([], []), $1 }
  | LPAR RESULT value_type_list RPAR func_result_body
    { let FuncType (ins, out) = fst $5 in
      FuncType (ins, $3 @ out), snd $5 }

func_body :
  | instr_list
    { fun c -> let c' = anon_label c in
      {ftype = -1l @@ at(); locals = []; body = $1 c'} }
  | LPAR LOCAL value_type_list RPAR func_body
    { fun c -> anon_locals c (lazy $3); let f = $5 c in
      {f with locals = $3 @ f.locals} }
  | LPAR LOCAL bind_var value_type RPAR func_body  /* Sugar */
    { fun c -> ignore (bind_local c $3); let f = $6 c in
      {f with locals = $4 :: f.locals} }


/* Tables, Memories & Globals */

table_use :
  | LPAR TABLE var RPAR { fun c -> $3 c }

memory_use :
  | LPAR MEMORY var RPAR { fun c -> $3 c }

offset :
  | LPAR OFFSET const_expr RPAR { $3 }
  | expr { let at = at () in fun c -> $1 c @@ at }  /* Sugar */

elem_kind :
  | FUNC { FuncRefType }

elem_expr :
  | LPAR ITEM const_expr RPAR { $3 }
  | expr { let at = at () in fun c -> $1 c @@ at }  /* Sugar */

elem_expr_list :
  | /* empty */ { fun c -> [] }
  | elem_expr elem_expr_list { fun c -> $1 c :: $2 c }

elem_var_list :
  | var_list
    { let f = function {at; _} as x -> [ref_func x @@ at] @@ at in
      fun c lookup -> List.map f ($1 c lookup) }

elem_list :
  | elem_kind elem_var_list
    { ($1, fun c -> $2 c func) }
  | ref_type elem_expr_list
    { ($1, fun c -> $2 c) }


elem :
  | LPAR ELEM bind_var_opt elem_list RPAR
    { let at = at () in
      fun c -> ignore ($3 c anon_elem bind_elem);
      fun () ->
      { etype = (fst $4); einit = (snd $4) c; emode = Passive @@ at } @@ at }
  | LPAR ELEM bind_var_opt table_use offset elem_list RPAR
    { let at = at () in
      fun c -> ignore ($3 c anon_elem bind_elem);
      fun () ->
      { etype = (fst $6); einit = (snd $6) c;
        emode = Active {index = $4 c table; offset = $5 c} @@ at } @@ at }
  | LPAR ELEM bind_var_opt DECLARE elem_list RPAR
    { let at = at () in
      fun c -> ignore ($3 c anon_elem bind_elem);
      fun () ->
      { etype = (fst $5); einit = (snd $5) c; emode = Declarative @@ at } @@ at }
  | LPAR ELEM bind_var_opt offset elem_list RPAR  /* Sugar */
    { let at = at () in
      fun c -> ignore ($3 c anon_elem bind_elem);
      fun () ->
      { etype = (fst $5); einit = (snd $5) c;
        emode = Active {index = 0l @@ at; offset = $4 c} @@ at } @@ at }
  | LPAR ELEM bind_var_opt offset elem_var_list RPAR  /* Sugar */
    { let at = at () in
      fun c -> ignore ($3 c anon_elem bind_elem);
      fun () ->
      { etype = FuncRefType; einit = $5 c func;
        emode = Active {index = 0l @@ at; offset = $4 c} @@ at } @@ at }

table :
  | LPAR TABLE bind_var_opt table_fields RPAR
    { let at = at () in
      fun c -> let x = $3 c anon_table bind_table @@ at in
      fun () -> $4 c x at }

table_fields :
  | table_type
    { fun c x at -> [{ttype = $1} @@ at], [], [], [] }
  | inline_import table_type  /* Sugar */
    { fun c x at ->
      [], [],
      [{ module_name = fst $1; item_name = snd $1;
        idesc = TableImport $2 @@ at } @@ at], [] }
  | inline_export table_fields  /* Sugar */
    { fun c x at -> let tabs, elems, ims, exs = $2 c x at in
      tabs, elems, ims, $1 (TableExport x) c :: exs }
  | ref_type LPAR ELEM elem_var_list RPAR  /* Sugar */
    { fun c x at ->
      let offset = [i32_const (0l @@ at) @@ at] @@ at in
      let einit = $4 c func in
      let size = Lib.List32.length einit in
      let emode = Active {index = x; offset} @@ at in
      [{ttype = TableType ({min = size; max = Some size}, $1)} @@ at],
      [{etype = FuncRefType; einit; emode} @@ at],
      [], [] }
  | ref_type LPAR ELEM elem_expr elem_expr_list RPAR  /* Sugar */
    { fun c x at ->
      let offset = [i32_const (0l @@ at) @@ at] @@ at in
      let einit = (fun c -> $4 c :: $5 c) c in
      let size = Lib.List32.length einit in
      let emode = Active {index = x; offset} @@ at in
      [{ttype = TableType ({min = size; max = Some size}, $1)} @@ at],
      [{etype = FuncRefType; einit; emode} @@ at],
      [], [] }

data :
  | LPAR DATA bind_var_opt string_list RPAR
    { let at = at () in
      fun c -> ignore ($3 c anon_data bind_data);
      fun () -> {dinit = $4; dmode = Passive @@ at} @@ at }
  | LPAR DATA bind_var_opt memory_use offset string_list RPAR
    { let at = at () in
      fun c -> ignore ($3 c anon_data bind_data);
      fun () ->
      {dinit = $6; dmode = Active {index = $4 c memory; offset = $5 c} @@ at} @@ at }
  | LPAR DATA bind_var_opt offset string_list RPAR  /* Sugar */
    { let at = at () in
      fun c -> ignore ($3 c anon_data bind_data);
      fun () ->
      {dinit = $5; dmode = Active {index = 0l @@ at; offset = $4 c} @@ at} @@ at }

memory :
  | LPAR MEMORY bind_var_opt memory_fields RPAR
    { let at = at () in
      fun c -> let x = $3 c anon_memory bind_memory @@ at in
      fun () -> $4 c x at }

memory_fields :
  | memory_type
    { fun c x at -> [{mtype = $1} @@ at], [], [], [] }
  | inline_import memory_type  /* Sugar */
    { fun c x at ->
      [], [],
      [{ module_name = fst $1; item_name = snd $1;
         idesc = MemoryImport $2 @@ at } @@ at], [] }
  | inline_export memory_fields  /* Sugar */
    { fun c x at -> let mems, data, ims, exs = $2 c x at in
      mems, data, ims, $1 (MemoryExport x) c :: exs }
  | LPAR DATA string_list RPAR  /* Sugar */
    { fun c x at ->
      let offset = [i32_const (0l @@ at) @@ at] @@ at in
      let size = Int32.(div (add (of_int (String.length $3)) 65535l) 65536l) in
      [{mtype = MemoryType {min = size; max = Some size}} @@ at],
      [{dinit = $3; dmode = Active {index = x; offset} @@ at} @@ at],
      [], [] }

global :
  | LPAR GLOBAL bind_var_opt global_fields RPAR
    { let at = at () in
      fun c -> let x = $3 c anon_global bind_global @@ at in
      fun () -> $4 c x at }

global_fields :
  | global_type const_expr
    { fun c x at -> [{gtype = $1; ginit = $2 c} @@ at], [], [] }
  | inline_import global_type  /* Sugar */
    { fun c x at ->
      [],
      [{ module_name = fst $1; item_name = snd $1;
         idesc = GlobalImport $2 @@ at } @@ at], [] }
  | inline_export global_fields  /* Sugar */
    { fun c x at -> let globs, ims, exs = $2 c x at in
      globs, ims, $1 (GlobalExport x) c :: exs }


/* Imports & Exports */

import_desc :
  | LPAR FUNC bind_var_opt type_use RPAR
    { fun c -> ignore ($3 c anon_func bind_func);
      fun () -> FuncImport ($4 c type_) }
  | LPAR FUNC bind_var_opt func_type RPAR  /* Sugar */
    { let at4 = ati 4 in
      fun c -> ignore ($3 c anon_func bind_func);
      fun () -> FuncImport (inline_type c $4 at4) }
  | LPAR TABLE bind_var_opt table_type RPAR
    { fun c -> ignore ($3 c anon_table bind_table);
      fun () -> TableImport $4 }
  | LPAR MEMORY bind_var_opt memory_type RPAR
    { fun c -> ignore ($3 c anon_memory bind_memory);
      fun () -> MemoryImport $4 }
  | LPAR GLOBAL bind_var_opt global_type RPAR
    { fun c -> ignore ($3 c anon_global bind_global);
      fun () -> GlobalImport $4 }

import :
  | LPAR IMPORT name name import_desc RPAR
    { let at = at () and at5 = ati 5 in
      fun c -> let df = $5 c in
      fun () -> {module_name = $3; item_name = $4; idesc = df () @@ at5} @@ at }

inline_import :
  | LPAR IMPORT name name RPAR { $3, $4 }

export_desc :
  | LPAR FUNC var RPAR { fun c -> FuncExport ($3 c func) }
  | LPAR TABLE var RPAR { fun c -> TableExport ($3 c table) }
  | LPAR MEMORY var RPAR { fun c -> MemoryExport ($3 c memory) }
  | LPAR GLOBAL var RPAR { fun c -> GlobalExport ($3 c global) }

export :
  | LPAR EXPORT name export_desc RPAR
    { let at = at () and at4 = ati 4 in
      fun c -> {name = $3; edesc = $4 c @@ at4} @@ at }

inline_export :
  | LPAR EXPORT name RPAR
    { let at = at () in fun d c -> {name = $3; edesc = d @@ at} @@ at }


/* Modules */

type_ :
  | def_type { $1 @@ at () }

type_def :
  | LPAR TYPE type_ RPAR
    { fun c -> anon_type c $3 }
  | LPAR TYPE bind_var type_ RPAR  /* Sugar */
    { fun c -> bind_type c $3 $4 }

start :
  | LPAR START var RPAR
    { fun c -> $3 c func }

module_fields :
  | /* empty */
    { fun (c : context) () -> {empty_module with types = c.types.list} }
  | module_fields1 { $1 }

module_fields1 :
  | type_def module_fields
    { fun c -> ignore ($1 c); $2 c }
  | global module_fields
    { fun c -> let gf = $1 c in let mf = $2 c in
      fun () -> let globs, ims, exs = gf () in let m = mf () in
      if globs <> [] && m.imports <> [] then
        error (List.hd m.imports).at "import after global definition";
      { m with globals = globs @ m.globals;
        imports = ims @ m.imports; exports = exs @ m.exports } }
  | table module_fields
    { fun c -> let tf = $1 c in let mf = $2 c in
      fun () -> let tabs, elems, ims, exs = tf () in let m = mf () in
      if tabs <> [] && m.imports <> [] then
        error (List.hd m.imports).at "import after table definition";
      { m with tables = tabs @ m.tables; elems = elems @ m.elems;
        imports = ims @ m.imports; exports = exs @ m.exports } }
  | memory module_fields
    { fun c -> let mmf = $1 c in let mf = $2 c in
      fun () -> let mems, data, ims, exs = mmf () in let m = mf () in
      if mems <> [] && m.imports <> [] then
        error (List.hd m.imports).at "import after memory definition";
      { m with memories = mems @ m.memories; datas = data @ m.datas;
        imports = ims @ m.imports; exports = exs @ m.exports } }
  | func module_fields
    { fun c -> let ff = $1 c in let mf = $2 c in
      fun () -> let funcs, ims, exs = ff () in let m = mf () in
      if funcs <> [] && m.imports <> [] then
        error (List.hd m.imports).at "import after function definition";
      { m with funcs = funcs @ m.funcs;
        imports = ims @ m.imports; exports = exs @ m.exports } }
  | elem module_fields
    { fun c -> let ef = $1 c in let mf = $2 c in
      fun () -> let elems = ef () in let m = mf () in
      {m with elems = elems :: m.elems} }
  | data module_fields
    { fun c -> let df = $1 c in let mf = $2 c in
      fun () -> let data = df () in let m = mf () in
      {m with datas = data :: m.datas} }
  | start module_fields
    { fun c -> let mf = $2 c in
      fun () -> let m = mf () in let x = $1 c in
      match m.start with
      | Some _ -> error x.at "multiple start sections"
      | None -> {m with start = Some x} }
  | import module_fields
    { fun c -> let imf = $1 c in let mf = $2 c in
      fun () -> let im = imf () in let m = mf () in
      {m with imports = im :: m.imports} }
  | export module_fields
    { fun c -> let mf = $2 c in
      fun () -> let m = mf () in
      {m with exports = $1 c :: m.exports} }

module_var_opt :
  | /* empty */ { None }
  | VAR { Some ($1 @@ at ()) }  /* Sugar */

module_ :
  | LPAR MODULE module_var_opt module_fields RPAR
    { $3, Textual ($4 (empty_context ()) () @@ at ()) @@ at () }

inline_module :  /* Sugar */
  | module_fields { Textual ($1 (empty_context ()) () @@ at ()) @@ at () }

inline_module1 :  /* Sugar */
  | module_fields1 { Textual ($1 (empty_context ()) () @@ at ()) @@ at () }


/* Scripts */

script_var_opt :
  | /* empty */ { None }
  | VAR { Some ($1 @@ at ()) }  /* Sugar */

script_module :
  | module_ { $1 }
  | LPAR MODULE module_var_opt BIN string_list RPAR
    { $3, Encoded ("binary:" ^ string_of_pos (at()).left, $5) @@ at() }
  | LPAR MODULE module_var_opt QUOTE string_list RPAR
    { $3, Quoted ("quote:" ^ string_of_pos (at()).left, $5) @@ at() }

action :
  | LPAR INVOKE module_var_opt name const_list RPAR
    { Invoke ($3, $4, $5) @@ at () }
  | LPAR GET module_var_opt name RPAR
    { Get ($3, $4) @@ at() }

assertion :
  | LPAR ASSERT_MALFORMED script_module STRING RPAR
    { AssertMalformed (snd $3, $4) @@ at () }
  | LPAR ASSERT_INVALID script_module STRING RPAR
    { AssertInvalid (snd $3, $4) @@ at () }
  | LPAR ASSERT_UNLINKABLE script_module STRING RPAR
    { AssertUnlinkable (snd $3, $4) @@ at () }
  | LPAR ASSERT_TRAP script_module STRING RPAR
    { AssertUninstantiable (snd $3, $4) @@ at () }
  | LPAR ASSERT_RETURN action result_list RPAR { AssertReturn ($3, $4) @@ at () }
  | LPAR ASSERT_TRAP action STRING RPAR { AssertTrap ($3, $4) @@ at () }
  | LPAR ASSERT_EXHAUSTION action STRING RPAR { AssertExhaustion ($3, $4) @@ at () }

cmd :
  | action { Action $1 @@ at () }
  | assertion { Assertion $1 @@ at () }
  | script_module { Module (fst $1, snd $1) @@ at () }
  | LPAR REGISTER name module_var_opt RPAR { Register ($3, $4) @@ at () }
  | meta { Meta $1 @@ at () }

cmd_list :
  | /* empty */ { [] }
  | cmd cmd_list { $1 :: $2 }

meta :
  | LPAR SCRIPT script_var_opt cmd_list RPAR { Script ($3, $4) @@ at () }
  | LPAR INPUT script_var_opt STRING RPAR { Input ($3, $4) @@ at () }
  | LPAR OUTPUT script_var_opt STRING RPAR { Output ($3, Some $4) @@ at () }
  | LPAR OUTPUT script_var_opt RPAR { Output ($3, None) @@ at () }

const :
  | LPAR CONST num RPAR { Values.Num (snd (num $2 $3)) @@ at () }
  | LPAR REF_NULL ref_kind RPAR { Values.Ref (Values.NullRef $3) @@ at () }
  | LPAR REF_EXTERN NAT RPAR { Values.Ref (ExternRef (nat32 $3 (ati 3))) @@ at () }

const_list :
  | /* empty */ { [] }
  | const const_list { $1 :: $2 }

result :
  | const { LitResult $1 @@ at () }
  | LPAR CONST NAN RPAR { NanResult (nanop $2 ($3 @@ ati 3)) @@ at () }
  | LPAR REF_FUNC RPAR { RefResult FuncRefType @@ at () }
  | LPAR REF_EXTERN RPAR { RefResult ExternRefType @@ at () }

result_list :
  | /* empty */ { [] }
  | result result_list { $1 :: $2 }

script :
  | cmd_list EOF { $1 }
  | inline_module1 EOF { [Module (None, $1) @@ at ()] }  /* Sugar */

script1 :
  | cmd { [$1] }

module1 :
  | module_ EOF { $1 }
  | inline_module EOF { None, $1 }  /* Sugar */
%%
