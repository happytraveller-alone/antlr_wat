// $antlr-format alignTrailingComments true, columnLimit 150, maxEmptyLinesToKeep 1, reflowComments false, useTab false
// $antlr-format allowShortRulesOnASingleLine true, allowShortBlocksOnASingleLine true, minEmptyLines 0, alignSemicolons ownLine
// $antlr-format alignColons trailing, singleLineOverrulesHangingColon true, alignLexerCommands true, alignLabels true, alignTrailers true

lexer grammar WatLexer;

fragment Num: Digit ('_'? Digit)*;

fragment HexNum: HexDigit ('_'? HexDigit)*;

fragment Sign: '+' | '-';

fragment Digit: [0-9];

fragment HexDigit: [0-9a-fA-F];

fragment Letter: [a-zA-Z];

fragment Nat     : Num | ('0x' HexNum);
fragment Int     : Sign Nat;
fragment Frac    : Num;
fragment HexFrac : HexNum;

fragment Float:
    Sign? Num '.' Frac?
    | Sign? Num ('.' Frac?)? ('e' | 'E') Sign? Num
    | Sign? '0x' HexNum '.' HexFrac?
    | Sign? '0x' HexNum ('.' HexFrac?)? ('p' | 'P') Sign? Num
    | Sign? 'inf'
    | Sign? 'nan'
    | Sign? 'nan:' '0x' HexNum
;

fragment String_:
    '"' (Char | '\n' | '\t' | '\r' | '\\' | '\'' | '\\"' | '\\' HexDigit HexDigit | '\\u{' HexDigit+ '}')* '"'
    | Utf8Enc
;

fragment Name: '$' (Letter | Digit | '_' | Symbol)+;

fragment Escape: [nrt'"\\];

fragment IXX      : 'i' ('32' | '64');
fragment FXX      : 'f' ('32' | '64');
fragment NXX      : IXX | FXX;
fragment MIXX     : 'i' ('8' | '16' | '32' | '64');
fragment MFXX     : 'f' ('32' | '64');
fragment SIGN     : 's' | 'u';
fragment MEM_SIZE : '8' | '16' | '32';
fragment RMW      : 'add' | 'sub' | 'and' | 'or' | 'xor' | 'xchg';
// fragment Newline : Ascii_Newline | []
// fragment COMMENT_CONTENT: C

fragment VXXX                     : 'v128';
fragment V128_INT_SHAPE           : 'i8x16' | 'i16x8' | 'i32x4' | 'i64x2';
fragment V128_INT_SHAPE_EXCEPT_64 : 'i8x16' | 'i16x8' | 'i32x4';
fragment V128_FLOAT_SHAPE         : 'f32x4' | 'f64x2';
fragment V128_SHAPE               : V128_INT_SHAPE | V128_FLOAT_SHAPE;
fragment Char                     : ~["'\\\u0000-\u001f\u007f-\u00ff];
fragment Ascii                    : [\u0000-\u007f];
fragment Ascii_no_nl              : [\u0000-\u0009\u000b-\u007f];
fragment Utf8Cont                 : [\u0080-\u00bf];
fragment Utf8                     : Ascii | Utf8Enc;
fragment Utf8_no_nl               : Ascii_no_nl | Utf8Enc;

fragment Utf8Enc:
    [\u00c2-\u00df] Utf8Cont
    | [\u00e0] [\u00a0-\u00bf] Utf8Cont
    | [\u00ed] [\u0080-\u009f] Utf8Cont
    | [\u00e1-\u00ec\u00ee-\u00ef] Utf8Cont Utf8Cont
    | [\u00f0] [\u0090-\u00bf] Utf8Cont Utf8Cont
    | [\u00f4] [\u0080-\u008f] Utf8Cont Utf8Cont
    | [\u00f1-\u00f3] Utf8Cont Utf8Cont Utf8Cont
;

fragment Symbol:
    '.'
    | '+'
    | '-'
    | '*'
    | '/'
    | '\\'
    | '^'
    | '~'
    | '='
    | '<'
    | '>'
    | '!'
    | '?'
    | '@'
    | '#'
    | '$'
    | '%'
    | '&'
    | '|'
    | ':'
    | '\''
    | '`'
;

LPAR : '(';
RPAR : ')';

NAT      : Nat;
INT      : Int;
FLOAT    : Float;
STRING_  : String_;
NUM_TYPE : NXX;
PACK_TYPE: 'i8' | 'i16';

VEC_TYPE  : VXXX;
VEC_SHAPE : V128_SHAPE;

CONST     : NXX '.const';
VEC_CONST : VXXX '.const';

ANY       : 'any';
ANYREF    : 'anyref';
NONE      : 'none';
NULLREF   : 'nullref';
EQ        : 'eq';
EQREF     : 'eqref';
I31       : 'i31';
I31REF    : 'i31ref';
STRUCTREF : 'structref';
ARRAYREF  : 'arrayref';
NOFUNC    : 'nofunc';

FUNCREF : 'funcref';
MUT     : 'mut';
SHARED  : 'shared';

NULLFUNCREF   : 'nullfuncref';
EXTERN        : 'extern';
NOEXTERN      : 'noextern';
EXTERNREF     : 'externref';
NULLEXTERNREF : 'nullexternref';
REF           : 'ref';
NULL          : 'null';
EXN           : 'exn';
EXNREF        : 'exnref';

ARRAY         : 'array';
STRUCT        : 'struct';
FIELD         : 'field';
SUB           : 'sub';
FINAL         : 'final';
REC           : 'rec';

REF_NULL    : 'ref.null';
REF_FUNC    : 'ref.func';
REF_STRUCT  : 'ref.struct';
REF_ARRAY   : 'ref.array';
REF_HOST    : 'ref.host';
REF_EXTERN  : 'ref.extern';
REF_IS_NULL : 'ref.is_null';
REF_AS_NON_NULL : 'ref.as_non_null';
REF_TEST    : 'ref.test';
REF_CAST    : 'ref.cast';
REF_EQ      : 'ref.eq';
REF_I31 : 'ref.i31';
REF_EXN : 'ref.exn';

TRY_TABLE : 'try_table';
CATCH     : 'catch';
CATCH_REF : 'catch_ref';
CATCH_ALL : 'catch_all';
CATCH_ALL_REF : 'catch_all_ref';
THROW     : 'throw';
THROW_REF : 'throw_ref';

I31_GET : 'i31.get_' SIGN;
STRUCT_NEW :
    'struct.new'
    | 'struct.new_default'
    ;
STRUCT_GET:
    'struct.get'
    | 'struct.get_' SIGN
    ;
STRUCT_SET: 'struct.set';

ARRAY_NEW : 'array.new' | 'array.new_default';
ARRAY_NEW_FIXED : 'array.new_fixed';
ARRAY_NEW_ELEM : 'array.new_elem';
ARRAY_NEW_DATA : 'array.new_data';
ARRAY_GET : 'array.get' | 'array.get_' SIGN;
ARRAY_SET : 'array.set';
ARRAY_LEN : 'array.len';
ARRAY_COPY : 'array.copy';
ARRAY_FILL : 'array.fill';
ARRAY_INIT_DATA : 'array.init_data';
ARRAY_INIT_ELEM : 'array.init_elem';
EXTERN_CONVERT : 'extern.convert_any' | 'any.convert_extern';

MEMORY_ATOMIC_NOTIFY : 'memory.atomic.notify';
MEMORY_ATOMIC_WAIT  : 'memory.atomic.wait' ('32' | '64');
ATOMIC_FENCE        : 'atomic.fence';
ATOMIC_LOAD         : 
    IXX '.atomic.load'
    | 'i64.atomic.load' MEM_SIZE '_u'
    | 'i32.atomic.load' ('8' | '16' )'_u'
    ;
ATOMIC_STORE :
    IXX '.atomic.store'
    | 'i64.atomic.store' MEM_SIZE
    | 'i32.atomic.store' ('8' | '16' )
    ;
ATOMIC_RMW :
    IXX '.atomic.rmw.' RMW
    | 'i64.atomic.rmw' MEM_SIZE '.' RMW '_u'
    | 'i32.atomic.rmw' ('8' | '16' ) '.' RMW'_u'
    ;
ATOMIC_RMW_CMPXCHG :
    IXX '.atomic.rmw.cmpxchg'
    | 'i64.atomic.rmw' MEM_SIZE '.cmpxchg_u'
    | 'i32.atomic.rmw' ('8' | '16' )'.cmpxchg_u'
    ;


NOP                  : 'nop';
UNREACHABLE          : 'unreachable';
DROP                 : 'drop';
BLOCK                : 'block';
LOOP                 : 'loop';
END                  : 'end';
BR                   : 'br';
BR_IF                : 'br_if';
BR_TABLE             : 'br_table';
RETURN               : 'return';
IF                   : 'if';
THEN                 : 'then';
ELSE                 : 'else';
SELECT               : 'select';
CALL                 : 'call';
CALL_INDIRECT        : 'call_indirect';
CALL_REF             : 'call_ref';
RETURN_CALL          : 'return_call';
RETURN_CALL_REF      : 'return_call_ref';
RETURN_CALL_INDIRECT : 'return_call_indirect';

BR_ON_NULL : 'br_on_null' | 'br_on_non_null';
BR_ON_CAST : 'br_on_cast' | 'br_on_cast_fail';

LOCAL_GET  : 'local.get';
LOCAL_SET  : 'local.set';
LOCAL_TEE  : 'local.tee';
GLOBAL_GET : 'global.get';
GLOBAL_SET : 'global.set';

TABLE_GET  : 'table.get';
TABLE_SET  : 'table.set';
TABLE_SIZE : 'table.size';
TABLE_GROW : 'table.grow';
TABLE_FILL : 'table.fill';
TABLE_COPY : 'table.copy';
TABLE_INIT : 'table.init';

DATA_DROP : 'data.drop';
ELEM_DROP : 'elem.drop';

LOAD  : 
    NXX '.load' (MEM_SIZE '_' SIGN)? 
    | IXX '.store' ('8' | '16')
    | 'i64.store32'
    ;
STORE : NXX '.store' (MEM_SIZE)?;

OFFSET_EQ_NAT : 'offset=' Nat;
ALIGN_EQ_NAT  : 'align=' Nat;

UNARY:
    IXX ('.clz' | '.ctz' | '.popcnt' | '.extend8_s' | '.extend16_s')
    | 'i64.extend32_s'
    | FXX ('.neg' | '.abs' | '.sqrt' | '.ceil' | '.floor' | '.trunc' | '.nearest')
;

BINARY:
    IXX (
        '.add'
        | '.sub'
        | '.mul'
        | '.div_s'
        | '.div_u'
        | '.rem_s'
        | '.rem_u'
        | '.and'
        | '.or'
        | '.xor'
        | '.shl'
        | '.shr_s'
        | '.shr_u'
        | '.rotl'
        | '.rotr'
    )
    | FXX ('.add' | '.sub' | '.mul' | '.div' | '.min' | '.max' | '.copysign')
;

TEST: IXX '.eqz';

COMPARE:
    IXX (
        '.eq'
        | '.ne'
        | '.lt_s'
        | '.lt_u'
        | '.le_s'
        | '.le_u'
        | '.gt_s'
        | '.gt_u'
        | '.ge_s'
        | '.ge_u'
    )
    | FXX ('.eq' | '.ne' | '.lt' | '.le' | '.gt' | '.ge')
;

CONVERT:
    'i32.wrap_i64'
    | 'i64.extend_i32_s'
    | 'i64.extend_i32_u'
    | 'f32.demote_f64'
    | 'f64.promote_f32'
    | IXX ('.trunc_f32_s' | '.trunc_f32_u' | '.trunc_f64_s' | '.trunc_f64_u')
    | IXX ('.trunc_sat_f32_s' | '.trunc_sat_f32_u' | '.trunc_sat_f64_s' | '.trunc_sat_f64_u')
    | FXX ('.convert_i32_s' | '.convert_i32_u' | '.convert_i64_s' | '.convert_i64_u')
    | 'f32.reinterpret_i32'
    | 'f64.reinterpret_i64'
    | 'i32.reinterpret_f32'
    | 'i64.reinterpret_f64'
;

VEC_LOAD:
    VXXX '.load' ('32'|'64') '_zero'
    | VXXX '.load' ('8x8' | '16x4' | '32x2') '_' SIGN
    | VXXX '.load' ('8' | '16' | '32' | '64') '_splat'
    | VXXX '.load'
;
VEC_STORE: 'v128.store';
VEC_LOAD_LANE  : VXXX '.load' ('8' | '16' | '32' | '64') '_lane';
VEC_STORE_LANE : VXXX '.store' ('8' | '16' | '32' | '64') '_lane';
VEC_UNARY:
    VXXX ('.not' | '.and' | '.andnot' | '.or' | '.xor')
    | V128_SHAPE ('.neg' | '.abs')
    | 'i8x16.popcnt'
    | 'i8x16.avgr_u'
    | 'i16x8.avgr_u'
    | 'f64x2.promote_low_f32x4'
    | 'f32x4.demote_f64x2_zero'
    | V128_FLOAT_SHAPE ('.sqrt' | '.ceil' | '.floor' | '.trunc' | '.nearest')
    | (
        'i32x4.trunc_sat_f32x4_'
        | 'f32x4.convert_i32x4_'
        | 'f64x2.convert_low_i32x4_'
        | 'i16x8.extadd_pairwise_i8x16_'
        | 'i32x4.extadd_pairwise_i16x8_'
        | 'i16x8.extend_low_i8x16_'
        | 'i16x8.extend_high_i8x16_'
        | 'i32x4.extend_low_i16x8_'
        | 'i32x4.extend_high_i16x8_'
        | 'i64x2.extend_low_i32x4_'
        | 'i64x2.extend_high_i32x4_'
    ) SIGN
    | 'i32x4.trunc_sat_f64x2_' SIGN '_zero'
    | 'i32x4.relaxed_trunc_f32x4_' SIGN
    | 'i32x4.relaxed_trunc_f64x2_' SIGN '_zero'
    | V128_FLOAT_SHAPE ('.relaxed_madd' | '.relaxed_nmadd' | '.relaxed_min' | '.relaxed_max')
;
VEC_BINARY:
    V128_SHAPE ('.eq' | '.ne' | '.add' | '.sub')
    | V128_INT_SHAPE_EXCEPT_64 (
        '.lt_u'
        | '.le_u'
        | '.gt_u'
        | '.ge_u'
        | '.min_s'
        | '.min_u'
        | '.max_s'
        | '.max_u'
    )
    | ('i16x8' | 'i32x4' | 'i64x2') '.mul'
    | V128_INT_SHAPE ('.lt_s' | '.le_s' | '.gt_s' | '.ge_s')
    | V128_FLOAT_SHAPE (
        '.lt'
        | '.le'
        | '.gt'
        | '.ge'
        | '.mul'
        | '.div'
        | '.min'
        | '.max'
        | '.pmin'
        | '.pmax'
    )
    | (
        'i8x16.add_sat_'
        | 'i8x16.sub_sat_'
        | 'i16x8.add_sat_'
        | 'i16x8.sub_sat_'
        | 'i8x16.narrow_i16x8_'
        | 'i16x8.narrow_i32x4_'
        | 'i16x8.extmul_low_i8x16_'
        | 'i16x8.extmul_high_i8x16_'
        | 'i32x4.extmul_low_i16x8_'
        | 'i32x4.extmul_high_i16x8_'
        | 'i64x2.extmul_low_i32x4_'
        | 'i64x2.extmul_high_i32x4_'
    ) SIGN
    | 'i16x8.q15mulr_sat_s'
    | 'i32x4.dot_i16x8_s'
    | 'i8x16.swizzle'
    | 'i8x16.relaxed_swizzle'
    | 'i16x8.relaxed_q15mulr_s'
    | 'i16x8.relaxed_dot_i8x16_i7x16_s'
    | 'i32x4.relaxed_dot_i8x16_i7x16_add_s'
;
VEC_TERNARY : 
    VXXX '.bitselect'
    | V128_INT_SHAPE '.relaxed_laneselect'   
;
VEC_TEST    : VXXX '.any_true' | V128_INT_SHAPE '.all_true';
VEC_BITMASK : V128_INT_SHAPE '.bitmask';

VEC_SHIFT: V128_INT_SHAPE ('.shl' | '.shr_s' | '.shr_u');

VEC_SHUFFLE : 'i8x16.shuffle';
VEC_SPLAT   : V128_SHAPE '.splat';
VEC_EXTRACT:
    ('i32x4' | 'i64x2') '.extract_lane'
    | ('i8x16' | 'i16x8') '.extract_lane_' SIGN
    | V128_FLOAT_SHAPE '.extract_lane'
;
VEC_REPLACE : V128_SHAPE '.replace_lane';
MEMORY_SIZE : 'memory.size';
MEMORY_GROW : 'memory.grow';
MEMORY_FILL : 'memory.fill';
MEMORY_COPY : 'memory.copy';
MEMORY_INIT : 'memory.init';

TYPE    : 'type';
FUNC    : 'func';
START_  : 'start';
PARAM   : 'param';
RESULT  : 'result';
LOCAL   : 'local';
GLOBAL  : 'global';
TABLE   : 'table';
MEMORY  : 'memory';
ELEM    : 'elem';
DATA    : 'data';
OFFSET  : 'offset';
IMPORT  : 'import';
EXPORT  : 'export';
DECLARE : 'declare';
ITEM    : 'item';
TAG     : 'tag';

MODULE : 'module';
BIN    : 'binary';
QUOTE  : 'quote';
EITHER : 'either';
THREAD : 'thread';
WAIT   : 'wait';

SCRIPT                       : 'script';
REGISTER                     : 'register';
INVOKE                       : 'invoke';
GET                          : 'get';
ASSERT_MALFORMED             : 'assert_malformed';
ASSERT_INVALID               : 'assert_invalid';
ASSERT_UNLINKABLE            : 'assert_unlinkable';
ASSERT_RETURN                : 'assert_return';
// ASSERT_RETURN_CANONICAL_NAN  : 'assert_return_canonical_nan';
// ASSERT_RETURN_ARITHMETIC_NAN : 'assert_return_arithmetic_nan';
ASSERT_EXCEPTION             : 'assert_exception';
ASSERT_TRAP                  : 'assert_trap';
ASSERT_EXHAUSTION            : 'assert_exhaustion';
INPUT                        : 'input';
OUTPUT                       : 'output';
NAN_                          : 'nan:canonical' | 'nan:arithmetic';
VAR: Name;

SPACE: [ \t\r\n] -> skip;

LCOMMENT: '(;';
RCOMMENT: ';)';
// COMMENT: ( '(;' .*? ';)' | ';;' .*? '\n' ) -> skip;
COMMENT: (';;' .*? '\n' | '(;' ( COMMENT | ~(')') | ')' | ';')* ';)') -> skip;
