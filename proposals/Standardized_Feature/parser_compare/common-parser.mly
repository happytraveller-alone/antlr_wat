%token CALL CALL_INDIRECT RETURN
%token LOCAL_GET LOCAL_SET LOCAL_TEE GLOBAL_GET GLOBAL_SET


%token INPUT OUTPUT
%token EOF


%token TABLE ELEM MEMORY DATA DECLARE OFFSET ITEM IMPORT EXPORT
%token MODULE BIN QUOTE
%token SCRIPT REGISTER INVOKE GET

%token<Ast.instr'> UNARY
%token<Ast.instr'> BINARY
%token<Ast.instr'> TEST
%token<Ast.instr'> COMPARE
%token<Ast.instr'> CONVERT

%token<string> NAT
%token<string> INT
%token<string> FLOAT
%token<string> STRING
%token<string> VAR
%token<Types.num_type> NUM_TYPE

%start script script1 module1
%type<Script.script> script
%type<Script.script> script1
%type<Script.var option * Script.definition> module1

%token<string> OFFSET_EQ_NAT
%token<string> ALIGN_EQ_NAT

%token<string Source.phrase -> Ast.instr' * Values.num> CONST
%token<int option -> Memory.offset -> Ast.instr'> LOAD
%token<int option -> Memory.offset -> Ast.instr'> STORE

%nonassoc LOW
%nonassoc VAR

%%

/* Auxiliaries */

name :
  | STRING { name $1 (at ()) }

string_list :
  | /* empty */ { "" }
  | string_list STRING { $1 ^ $2 }

/* Types */

value_type :
  | NUM_TYPE { NumType $1 }

value_type_list :
  | /* empty */ { [] }
  | value_type value_type_list { $1 :: $2 }