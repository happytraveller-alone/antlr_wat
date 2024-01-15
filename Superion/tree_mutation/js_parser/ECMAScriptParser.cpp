
// Generated from ECMAScript.g4 by ANTLR 4.13.1


#include "ECMAScriptVisitor.h"

#include "ECMAScriptParser.h"


using namespace antlrcpp;

using namespace antlr4;

namespace {

struct ECMAScriptParserStaticData final {
  ECMAScriptParserStaticData(std::vector<std::string> ruleNames,
                        std::vector<std::string> literalNames,
                        std::vector<std::string> symbolicNames)
      : ruleNames(std::move(ruleNames)), literalNames(std::move(literalNames)),
        symbolicNames(std::move(symbolicNames)),
        vocabulary(this->literalNames, this->symbolicNames) {}

  ECMAScriptParserStaticData(const ECMAScriptParserStaticData&) = delete;
  ECMAScriptParserStaticData(ECMAScriptParserStaticData&&) = delete;
  ECMAScriptParserStaticData& operator=(const ECMAScriptParserStaticData&) = delete;
  ECMAScriptParserStaticData& operator=(ECMAScriptParserStaticData&&) = delete;

  std::vector<antlr4::dfa::DFA> decisionToDFA;
  antlr4::atn::PredictionContextCache sharedContextCache;
  const std::vector<std::string> ruleNames;
  const std::vector<std::string> literalNames;
  const std::vector<std::string> symbolicNames;
  const antlr4::dfa::Vocabulary vocabulary;
  antlr4::atn::SerializedATNView serializedATN;
  std::unique_ptr<antlr4::atn::ATN> atn;
};

::antlr4::internal::OnceFlag ecmascriptParserOnceFlag;
#if ANTLR4_USE_THREAD_LOCAL_CACHE
static thread_local
#endif
ECMAScriptParserStaticData *ecmascriptParserStaticData = nullptr;

void ecmascriptParserInitialize() {
#if ANTLR4_USE_THREAD_LOCAL_CACHE
  if (ecmascriptParserStaticData != nullptr) {
    return;
  }
#else
  assert(ecmascriptParserStaticData == nullptr);
#endif
  auto staticData = std::make_unique<ECMAScriptParserStaticData>(
    std::vector<std::string>{
      "program", "sourceElements", "sourceElement", "statement", "block", 
      "statementList", "variableStatement", "variableDeclarationList", "variableDeclaration", 
      "initialiser", "emptyStatement", "expressionStatement", "ifStatement", 
      "iterationStatement", "continueStatement", "breakStatement", "returnStatement", 
      "withStatement", "switchStatement", "caseBlock", "caseClauses", "caseClause", 
      "defaultClause", "labelledStatement", "throwStatement", "tryStatement", 
      "catchProduction", "finallyProduction", "debuggerStatement", "functionDeclaration", 
      "formalParameterList", "functionBody", "arrayLiteral", "elementList", 
      "elision", "objectLiteral", "propertyNameAndValueList", "propertyAssignment", 
      "propertyName", "propertySetParameterList", "arguments", "argumentList", 
      "expressionSequence", "singleExpression", "assignmentOperator", "literal", 
      "numericLiteral", "identifierName", "reservedWord", "keyword", "futureReservedWord", 
      "getter", "setter", "eos", "eof"
    },
    std::vector<std::string>{
      "", "", "", "'['", "']'", "'('", "')'", "'{'", "'}'", "';'", "','", 
      "'='", "'\\u003F'", "':'", "'.'", "'++'", "'--'", "'+'", "'-'", "'~'", 
      "'!'", "'*'", "'/'", "'%'", "'>>'", "'<<'", "'>>>'", "'<'", "'>'", 
      "'<='", "'>='", "'=='", "'!='", "'==='", "'!=='", "'&'", "'^'", "'|'", 
      "'&&'", "'||'", "'*='", "'/='", "'%='", "'+='", "'-='", "'<<='", "'>>='", 
      "'>>>='", "'&='", "'^='", "'|='", "'null'", "", "", "", "", "'break'", 
      "'do'", "'instanceof'", "'typeof'", "'case'", "'else'", "'new'", "'var'", 
      "'let'", "'catch'", "'finally'", "'return'", "'void'", "'continue'", 
      "'for'", "'switch'", "'while'", "'debugger'", "'function'", "'this'", 
      "'with'", "'default'", "'if'", "'throw'", "'delete'", "'in'", "'try'", 
      "'class'", "'enum'", "'extends'", "'super'", "'const'", "'export'", 
      "'import'", "'implements'", "'private'", "'public'", "'interface'", 
      "'package'", "'protected'", "'static'", "'yield'"
    },
    std::vector<std::string>{
      "", "RegularExpressionLiteral", "LineTerminator", "OpenBracket", "CloseBracket", 
      "OpenParen", "CloseParen", "OpenBrace", "CloseBrace", "SemiColon", 
      "Comma", "Assign", "QuestionMark", "Colon", "Dot", "PlusPlus", "MinusMinus", 
      "Plus", "Minus", "BitNot", "Not", "Multiply", "Divide", "Modulus", 
      "RightShiftArithmetic", "LeftShiftArithmetic", "RightShiftLogical", 
      "LessThan", "MoreThan", "LessThanEquals", "GreaterThanEquals", "Equals_", 
      "NotEquals", "IdentityEquals", "IdentityNotEquals", "BitAnd", "BitXOr", 
      "BitOr", "And", "Or", "MultiplyAssign", "DivideAssign", "ModulusAssign", 
      "PlusAssign", "MinusAssign", "LeftShiftArithmeticAssign", "RightShiftArithmeticAssign", 
      "RightShiftLogicalAssign", "BitAndAssign", "BitXorAssign", "BitOrAssign", 
      "NullLiteral", "BooleanLiteral", "DecimalLiteral", "HexIntegerLiteral", 
      "OctalIntegerLiteral", "Break", "Do", "Instanceof", "Typeof", "Case", 
      "Else", "New", "Var", "Let", "Catch", "Finally", "Return", "Void", 
      "Continue", "For", "Switch", "While", "Debugger", "Function", "This", 
      "With", "Default", "If", "Throw", "Delete", "In", "Try", "Class", 
      "Enum", "Extends", "Super", "Const", "Export", "Import", "Implements", 
      "Private", "Public", "Interface", "Package", "Protected", "Static", 
      "Yield", "Identifier", "StringLiteral", "WhiteSpaces", "MultiLineComment", 
      "SingleLineComment", "HtmlComment", "UnexpectedCharacter"
    }
  );
  static const int32_t serializedATNSegment[] = {
  	4,1,104,652,2,0,7,0,2,1,7,1,2,2,7,2,2,3,7,3,2,4,7,4,2,5,7,5,2,6,7,6,2,
  	7,7,7,2,8,7,8,2,9,7,9,2,10,7,10,2,11,7,11,2,12,7,12,2,13,7,13,2,14,7,
  	14,2,15,7,15,2,16,7,16,2,17,7,17,2,18,7,18,2,19,7,19,2,20,7,20,2,21,7,
  	21,2,22,7,22,2,23,7,23,2,24,7,24,2,25,7,25,2,26,7,26,2,27,7,27,2,28,7,
  	28,2,29,7,29,2,30,7,30,2,31,7,31,2,32,7,32,2,33,7,33,2,34,7,34,2,35,7,
  	35,2,36,7,36,2,37,7,37,2,38,7,38,2,39,7,39,2,40,7,40,2,41,7,41,2,42,7,
  	42,2,43,7,43,2,44,7,44,2,45,7,45,2,46,7,46,2,47,7,47,2,48,7,48,2,49,7,
  	49,2,50,7,50,2,51,7,51,2,52,7,52,2,53,7,53,2,54,7,54,1,0,3,0,112,8,0,
  	1,0,1,0,1,1,4,1,117,8,1,11,1,12,1,118,1,2,1,2,3,2,123,8,2,1,3,1,3,1,3,
  	1,3,1,3,1,3,1,3,1,3,1,3,1,3,1,3,1,3,1,3,1,3,1,3,3,3,140,8,3,1,4,1,4,3,
  	4,144,8,4,1,4,1,4,1,5,4,5,149,8,5,11,5,12,5,150,1,6,1,6,1,6,1,6,1,6,1,
  	6,1,6,1,6,3,6,161,8,6,1,7,1,7,1,7,5,7,166,8,7,10,7,12,7,169,9,7,1,8,1,
  	8,3,8,173,8,8,1,9,1,9,1,9,1,10,1,10,1,11,1,11,1,11,1,11,1,12,1,12,1,12,
  	1,12,1,12,1,12,1,12,3,12,191,8,12,1,13,1,13,1,13,1,13,1,13,1,13,1,13,
  	1,13,1,13,1,13,1,13,1,13,1,13,1,13,1,13,1,13,1,13,3,13,210,8,13,1,13,
  	1,13,3,13,214,8,13,1,13,1,13,3,13,218,8,13,1,13,1,13,1,13,1,13,1,13,1,
  	13,1,13,1,13,3,13,228,8,13,1,13,1,13,3,13,232,8,13,1,13,1,13,1,13,1,13,
  	1,13,1,13,1,13,1,13,1,13,3,13,243,8,13,1,13,1,13,3,13,247,8,13,1,13,1,
  	13,1,13,1,13,1,13,1,13,1,13,1,13,1,13,1,13,1,13,1,13,1,13,1,13,1,13,1,
  	13,1,13,1,13,1,13,1,13,1,13,1,13,1,13,1,13,1,13,1,13,1,13,1,13,1,13,3,
  	13,278,8,13,1,14,1,14,1,14,3,14,283,8,14,1,14,1,14,1,15,1,15,1,15,3,15,
  	290,8,15,1,15,1,15,1,16,1,16,1,16,3,16,297,8,16,1,16,1,16,1,17,1,17,1,
  	17,1,17,1,17,1,17,1,18,1,18,1,18,1,18,1,18,1,18,1,19,1,19,3,19,315,8,
  	19,1,19,1,19,3,19,319,8,19,3,19,321,8,19,1,19,1,19,1,20,4,20,326,8,20,
  	11,20,12,20,327,1,21,1,21,1,21,1,21,3,21,334,8,21,1,22,1,22,1,22,3,22,
  	339,8,22,1,23,1,23,1,23,1,23,1,24,1,24,1,24,1,24,1,24,1,25,1,25,1,25,
  	1,25,1,25,1,25,1,25,1,25,1,25,1,25,1,25,1,25,1,25,3,25,363,8,25,1,26,
  	1,26,1,26,1,26,1,26,1,26,1,27,1,27,1,27,1,28,1,28,1,28,1,29,1,29,1,29,
  	1,29,3,29,381,8,29,1,29,1,29,1,29,1,29,1,29,1,30,1,30,1,30,5,30,391,8,
  	30,10,30,12,30,394,9,30,1,31,3,31,397,8,31,1,32,1,32,3,32,401,8,32,1,
  	32,3,32,404,8,32,1,32,3,32,407,8,32,1,32,1,32,1,33,3,33,412,8,33,1,33,
  	1,33,1,33,3,33,417,8,33,1,33,5,33,420,8,33,10,33,12,33,423,9,33,1,34,
  	4,34,426,8,34,11,34,12,34,427,1,35,1,35,3,35,432,8,35,1,35,3,35,435,8,
  	35,1,35,1,35,1,36,1,36,1,36,5,36,442,8,36,10,36,12,36,445,9,36,1,37,1,
  	37,1,37,1,37,1,37,1,37,1,37,1,37,1,37,1,37,1,37,1,37,1,37,1,37,1,37,1,
  	37,1,37,1,37,1,37,3,37,466,8,37,1,38,1,38,1,38,3,38,471,8,38,1,39,1,39,
  	1,40,1,40,3,40,477,8,40,1,40,1,40,1,41,1,41,1,41,5,41,484,8,41,10,41,
  	12,41,487,9,41,1,42,1,42,1,42,5,42,492,8,42,10,42,12,42,495,9,42,1,43,
  	1,43,1,43,3,43,500,8,43,1,43,1,43,3,43,504,8,43,1,43,1,43,1,43,1,43,1,
  	43,1,43,1,43,1,43,3,43,514,8,43,1,43,1,43,1,43,1,43,1,43,1,43,1,43,1,
  	43,1,43,1,43,1,43,1,43,1,43,1,43,1,43,1,43,1,43,1,43,1,43,1,43,1,43,1,
  	43,1,43,1,43,1,43,1,43,1,43,3,43,543,8,43,1,43,1,43,1,43,1,43,1,43,1,
  	43,1,43,1,43,1,43,1,43,1,43,1,43,1,43,1,43,1,43,1,43,1,43,1,43,1,43,1,
  	43,1,43,1,43,1,43,1,43,1,43,1,43,1,43,1,43,1,43,1,43,1,43,1,43,1,43,1,
  	43,1,43,1,43,1,43,1,43,1,43,1,43,1,43,1,43,1,43,1,43,1,43,1,43,1,43,1,
  	43,1,43,1,43,1,43,1,43,1,43,1,43,1,43,1,43,1,43,1,43,1,43,1,43,1,43,1,
  	43,1,43,1,43,1,43,5,43,610,8,43,10,43,12,43,613,9,43,1,44,1,44,1,45,1,
  	45,3,45,619,8,45,1,46,1,46,1,47,1,47,3,47,625,8,47,1,48,1,48,1,48,3,48,
  	630,8,48,1,49,1,49,1,50,1,50,1,51,1,51,1,51,1,51,1,52,1,52,1,52,1,52,
  	1,53,1,53,1,53,1,53,3,53,648,8,53,1,54,1,54,1,54,0,1,86,55,0,2,4,6,8,
  	10,12,14,16,18,20,22,24,26,28,30,32,34,36,38,40,42,44,46,48,50,52,54,
  	56,58,60,62,64,66,68,70,72,74,76,78,80,82,84,86,88,90,92,94,96,98,100,
  	102,104,106,108,0,11,1,0,21,23,1,0,17,18,1,0,24,26,1,0,27,30,1,0,31,34,
  	1,0,40,50,3,0,1,1,51,52,99,99,1,0,53,55,1,0,51,52,1,0,56,82,1,0,83,97,
  	710,0,111,1,0,0,0,2,116,1,0,0,0,4,122,1,0,0,0,6,139,1,0,0,0,8,141,1,0,
  	0,0,10,148,1,0,0,0,12,160,1,0,0,0,14,162,1,0,0,0,16,170,1,0,0,0,18,174,
  	1,0,0,0,20,177,1,0,0,0,22,179,1,0,0,0,24,183,1,0,0,0,26,277,1,0,0,0,28,
  	279,1,0,0,0,30,286,1,0,0,0,32,293,1,0,0,0,34,300,1,0,0,0,36,306,1,0,0,
  	0,38,312,1,0,0,0,40,325,1,0,0,0,42,329,1,0,0,0,44,335,1,0,0,0,46,340,
  	1,0,0,0,48,344,1,0,0,0,50,362,1,0,0,0,52,364,1,0,0,0,54,370,1,0,0,0,56,
  	373,1,0,0,0,58,376,1,0,0,0,60,387,1,0,0,0,62,396,1,0,0,0,64,398,1,0,0,
  	0,66,411,1,0,0,0,68,425,1,0,0,0,70,429,1,0,0,0,72,438,1,0,0,0,74,465,
  	1,0,0,0,76,470,1,0,0,0,78,472,1,0,0,0,80,474,1,0,0,0,82,480,1,0,0,0,84,
  	488,1,0,0,0,86,542,1,0,0,0,88,614,1,0,0,0,90,618,1,0,0,0,92,620,1,0,0,
  	0,94,624,1,0,0,0,96,629,1,0,0,0,98,631,1,0,0,0,100,633,1,0,0,0,102,635,
  	1,0,0,0,104,639,1,0,0,0,106,647,1,0,0,0,108,649,1,0,0,0,110,112,3,2,1,
  	0,111,110,1,0,0,0,111,112,1,0,0,0,112,113,1,0,0,0,113,114,5,0,0,1,114,
  	1,1,0,0,0,115,117,3,4,2,0,116,115,1,0,0,0,117,118,1,0,0,0,118,116,1,0,
  	0,0,118,119,1,0,0,0,119,3,1,0,0,0,120,123,3,6,3,0,121,123,3,58,29,0,122,
  	120,1,0,0,0,122,121,1,0,0,0,123,5,1,0,0,0,124,140,3,8,4,0,125,140,3,12,
  	6,0,126,140,3,20,10,0,127,140,3,22,11,0,128,140,3,24,12,0,129,140,3,26,
  	13,0,130,140,3,28,14,0,131,140,3,30,15,0,132,140,3,32,16,0,133,140,3,
  	34,17,0,134,140,3,46,23,0,135,140,3,36,18,0,136,140,3,48,24,0,137,140,
  	3,50,25,0,138,140,3,56,28,0,139,124,1,0,0,0,139,125,1,0,0,0,139,126,1,
  	0,0,0,139,127,1,0,0,0,139,128,1,0,0,0,139,129,1,0,0,0,139,130,1,0,0,0,
  	139,131,1,0,0,0,139,132,1,0,0,0,139,133,1,0,0,0,139,134,1,0,0,0,139,135,
  	1,0,0,0,139,136,1,0,0,0,139,137,1,0,0,0,139,138,1,0,0,0,140,7,1,0,0,0,
  	141,143,5,7,0,0,142,144,3,10,5,0,143,142,1,0,0,0,143,144,1,0,0,0,144,
  	145,1,0,0,0,145,146,5,8,0,0,146,9,1,0,0,0,147,149,3,6,3,0,148,147,1,0,
  	0,0,149,150,1,0,0,0,150,148,1,0,0,0,150,151,1,0,0,0,151,11,1,0,0,0,152,
  	153,5,63,0,0,153,154,3,14,7,0,154,155,3,106,53,0,155,161,1,0,0,0,156,
  	157,5,64,0,0,157,158,3,14,7,0,158,159,3,106,53,0,159,161,1,0,0,0,160,
  	152,1,0,0,0,160,156,1,0,0,0,161,13,1,0,0,0,162,167,3,16,8,0,163,164,5,
  	10,0,0,164,166,3,16,8,0,165,163,1,0,0,0,166,169,1,0,0,0,167,165,1,0,0,
  	0,167,168,1,0,0,0,168,15,1,0,0,0,169,167,1,0,0,0,170,172,5,98,0,0,171,
  	173,3,18,9,0,172,171,1,0,0,0,172,173,1,0,0,0,173,17,1,0,0,0,174,175,5,
  	11,0,0,175,176,3,86,43,0,176,19,1,0,0,0,177,178,5,9,0,0,178,21,1,0,0,
  	0,179,180,4,11,0,0,180,181,3,84,42,0,181,182,3,106,53,0,182,23,1,0,0,
  	0,183,184,5,78,0,0,184,185,5,5,0,0,185,186,3,84,42,0,186,187,5,6,0,0,
  	187,190,3,6,3,0,188,189,5,61,0,0,189,191,3,6,3,0,190,188,1,0,0,0,190,
  	191,1,0,0,0,191,25,1,0,0,0,192,193,5,57,0,0,193,194,3,6,3,0,194,195,5,
  	72,0,0,195,196,5,5,0,0,196,197,3,84,42,0,197,198,5,6,0,0,198,199,3,106,
  	53,0,199,278,1,0,0,0,200,201,5,72,0,0,201,202,5,5,0,0,202,203,3,84,42,
  	0,203,204,5,6,0,0,204,205,3,6,3,0,205,278,1,0,0,0,206,207,5,70,0,0,207,
  	209,5,5,0,0,208,210,3,84,42,0,209,208,1,0,0,0,209,210,1,0,0,0,210,211,
  	1,0,0,0,211,213,5,9,0,0,212,214,3,84,42,0,213,212,1,0,0,0,213,214,1,0,
  	0,0,214,215,1,0,0,0,215,217,5,9,0,0,216,218,3,84,42,0,217,216,1,0,0,0,
  	217,218,1,0,0,0,218,219,1,0,0,0,219,220,5,6,0,0,220,278,3,6,3,0,221,222,
  	5,70,0,0,222,223,5,5,0,0,223,224,5,63,0,0,224,225,3,14,7,0,225,227,5,
  	9,0,0,226,228,3,84,42,0,227,226,1,0,0,0,227,228,1,0,0,0,228,229,1,0,0,
  	0,229,231,5,9,0,0,230,232,3,84,42,0,231,230,1,0,0,0,231,232,1,0,0,0,232,
  	233,1,0,0,0,233,234,5,6,0,0,234,235,3,6,3,0,235,278,1,0,0,0,236,237,5,
  	70,0,0,237,238,5,5,0,0,238,239,5,64,0,0,239,240,3,14,7,0,240,242,5,9,
  	0,0,241,243,3,84,42,0,242,241,1,0,0,0,242,243,1,0,0,0,243,244,1,0,0,0,
  	244,246,5,9,0,0,245,247,3,84,42,0,246,245,1,0,0,0,246,247,1,0,0,0,247,
  	248,1,0,0,0,248,249,5,6,0,0,249,250,3,6,3,0,250,278,1,0,0,0,251,252,5,
  	70,0,0,252,253,5,5,0,0,253,254,3,86,43,0,254,255,5,81,0,0,255,256,3,84,
  	42,0,256,257,5,6,0,0,257,258,3,6,3,0,258,278,1,0,0,0,259,260,5,70,0,0,
  	260,261,5,5,0,0,261,262,5,63,0,0,262,263,3,16,8,0,263,264,5,81,0,0,264,
  	265,3,84,42,0,265,266,5,6,0,0,266,267,3,6,3,0,267,278,1,0,0,0,268,269,
  	5,70,0,0,269,270,5,5,0,0,270,271,5,64,0,0,271,272,3,16,8,0,272,273,5,
  	81,0,0,273,274,3,84,42,0,274,275,5,6,0,0,275,276,3,6,3,0,276,278,1,0,
  	0,0,277,192,1,0,0,0,277,200,1,0,0,0,277,206,1,0,0,0,277,221,1,0,0,0,277,
  	236,1,0,0,0,277,251,1,0,0,0,277,259,1,0,0,0,277,268,1,0,0,0,278,27,1,
  	0,0,0,279,282,5,69,0,0,280,281,4,14,1,0,281,283,5,98,0,0,282,280,1,0,
  	0,0,282,283,1,0,0,0,283,284,1,0,0,0,284,285,3,106,53,0,285,29,1,0,0,0,
  	286,289,5,56,0,0,287,288,4,15,2,0,288,290,5,98,0,0,289,287,1,0,0,0,289,
  	290,1,0,0,0,290,291,1,0,0,0,291,292,3,106,53,0,292,31,1,0,0,0,293,296,
  	5,67,0,0,294,295,4,16,3,0,295,297,3,84,42,0,296,294,1,0,0,0,296,297,1,
  	0,0,0,297,298,1,0,0,0,298,299,3,106,53,0,299,33,1,0,0,0,300,301,5,76,
  	0,0,301,302,5,5,0,0,302,303,3,84,42,0,303,304,5,6,0,0,304,305,3,6,3,0,
  	305,35,1,0,0,0,306,307,5,71,0,0,307,308,5,5,0,0,308,309,3,84,42,0,309,
  	310,5,6,0,0,310,311,3,38,19,0,311,37,1,0,0,0,312,314,5,7,0,0,313,315,
  	3,40,20,0,314,313,1,0,0,0,314,315,1,0,0,0,315,320,1,0,0,0,316,318,3,44,
  	22,0,317,319,3,40,20,0,318,317,1,0,0,0,318,319,1,0,0,0,319,321,1,0,0,
  	0,320,316,1,0,0,0,320,321,1,0,0,0,321,322,1,0,0,0,322,323,5,8,0,0,323,
  	39,1,0,0,0,324,326,3,42,21,0,325,324,1,0,0,0,326,327,1,0,0,0,327,325,
  	1,0,0,0,327,328,1,0,0,0,328,41,1,0,0,0,329,330,5,60,0,0,330,331,3,84,
  	42,0,331,333,5,13,0,0,332,334,3,10,5,0,333,332,1,0,0,0,333,334,1,0,0,
  	0,334,43,1,0,0,0,335,336,5,77,0,0,336,338,5,13,0,0,337,339,3,10,5,0,338,
  	337,1,0,0,0,338,339,1,0,0,0,339,45,1,0,0,0,340,341,5,98,0,0,341,342,5,
  	13,0,0,342,343,3,6,3,0,343,47,1,0,0,0,344,345,5,79,0,0,345,346,4,24,4,
  	0,346,347,3,84,42,0,347,348,3,106,53,0,348,49,1,0,0,0,349,350,5,82,0,
  	0,350,351,3,8,4,0,351,352,3,52,26,0,352,363,1,0,0,0,353,354,5,82,0,0,
  	354,355,3,8,4,0,355,356,3,54,27,0,356,363,1,0,0,0,357,358,5,82,0,0,358,
  	359,3,8,4,0,359,360,3,52,26,0,360,361,3,54,27,0,361,363,1,0,0,0,362,349,
  	1,0,0,0,362,353,1,0,0,0,362,357,1,0,0,0,363,51,1,0,0,0,364,365,5,65,0,
  	0,365,366,5,5,0,0,366,367,5,98,0,0,367,368,5,6,0,0,368,369,3,8,4,0,369,
  	53,1,0,0,0,370,371,5,66,0,0,371,372,3,8,4,0,372,55,1,0,0,0,373,374,5,
  	73,0,0,374,375,3,106,53,0,375,57,1,0,0,0,376,377,5,74,0,0,377,378,5,98,
  	0,0,378,380,5,5,0,0,379,381,3,60,30,0,380,379,1,0,0,0,380,381,1,0,0,0,
  	381,382,1,0,0,0,382,383,5,6,0,0,383,384,5,7,0,0,384,385,3,62,31,0,385,
  	386,5,8,0,0,386,59,1,0,0,0,387,392,5,98,0,0,388,389,5,10,0,0,389,391,
  	5,98,0,0,390,388,1,0,0,0,391,394,1,0,0,0,392,390,1,0,0,0,392,393,1,0,
  	0,0,393,61,1,0,0,0,394,392,1,0,0,0,395,397,3,2,1,0,396,395,1,0,0,0,396,
  	397,1,0,0,0,397,63,1,0,0,0,398,400,5,3,0,0,399,401,3,66,33,0,400,399,
  	1,0,0,0,400,401,1,0,0,0,401,403,1,0,0,0,402,404,5,10,0,0,403,402,1,0,
  	0,0,403,404,1,0,0,0,404,406,1,0,0,0,405,407,3,68,34,0,406,405,1,0,0,0,
  	406,407,1,0,0,0,407,408,1,0,0,0,408,409,5,4,0,0,409,65,1,0,0,0,410,412,
  	3,68,34,0,411,410,1,0,0,0,411,412,1,0,0,0,412,413,1,0,0,0,413,421,3,86,
  	43,0,414,416,5,10,0,0,415,417,3,68,34,0,416,415,1,0,0,0,416,417,1,0,0,
  	0,417,418,1,0,0,0,418,420,3,86,43,0,419,414,1,0,0,0,420,423,1,0,0,0,421,
  	419,1,0,0,0,421,422,1,0,0,0,422,67,1,0,0,0,423,421,1,0,0,0,424,426,5,
  	10,0,0,425,424,1,0,0,0,426,427,1,0,0,0,427,425,1,0,0,0,427,428,1,0,0,
  	0,428,69,1,0,0,0,429,431,5,7,0,0,430,432,3,72,36,0,431,430,1,0,0,0,431,
  	432,1,0,0,0,432,434,1,0,0,0,433,435,5,10,0,0,434,433,1,0,0,0,434,435,
  	1,0,0,0,435,436,1,0,0,0,436,437,5,8,0,0,437,71,1,0,0,0,438,443,3,74,37,
  	0,439,440,5,10,0,0,440,442,3,74,37,0,441,439,1,0,0,0,442,445,1,0,0,0,
  	443,441,1,0,0,0,443,444,1,0,0,0,444,73,1,0,0,0,445,443,1,0,0,0,446,447,
  	3,76,38,0,447,448,5,13,0,0,448,449,3,86,43,0,449,466,1,0,0,0,450,451,
  	3,102,51,0,451,452,5,5,0,0,452,453,5,6,0,0,453,454,5,7,0,0,454,455,3,
  	62,31,0,455,456,5,8,0,0,456,466,1,0,0,0,457,458,3,104,52,0,458,459,5,
  	5,0,0,459,460,3,78,39,0,460,461,5,6,0,0,461,462,5,7,0,0,462,463,3,62,
  	31,0,463,464,5,8,0,0,464,466,1,0,0,0,465,446,1,0,0,0,465,450,1,0,0,0,
  	465,457,1,0,0,0,466,75,1,0,0,0,467,471,3,94,47,0,468,471,5,99,0,0,469,
  	471,3,92,46,0,470,467,1,0,0,0,470,468,1,0,0,0,470,469,1,0,0,0,471,77,
  	1,0,0,0,472,473,5,98,0,0,473,79,1,0,0,0,474,476,5,5,0,0,475,477,3,82,
  	41,0,476,475,1,0,0,0,476,477,1,0,0,0,477,478,1,0,0,0,478,479,5,6,0,0,
  	479,81,1,0,0,0,480,485,3,86,43,0,481,482,5,10,0,0,482,484,3,86,43,0,483,
  	481,1,0,0,0,484,487,1,0,0,0,485,483,1,0,0,0,485,486,1,0,0,0,486,83,1,
  	0,0,0,487,485,1,0,0,0,488,493,3,86,43,0,489,490,5,10,0,0,490,492,3,86,
  	43,0,491,489,1,0,0,0,492,495,1,0,0,0,493,491,1,0,0,0,493,494,1,0,0,0,
  	494,85,1,0,0,0,495,493,1,0,0,0,496,497,6,43,-1,0,497,499,5,74,0,0,498,
  	500,5,98,0,0,499,498,1,0,0,0,499,500,1,0,0,0,500,501,1,0,0,0,501,503,
  	5,5,0,0,502,504,3,60,30,0,503,502,1,0,0,0,503,504,1,0,0,0,504,505,1,0,
  	0,0,505,506,5,6,0,0,506,507,5,7,0,0,507,508,3,62,31,0,508,509,5,8,0,0,
  	509,543,1,0,0,0,510,511,5,62,0,0,511,513,3,86,43,0,512,514,3,80,40,0,
  	513,512,1,0,0,0,513,514,1,0,0,0,514,543,1,0,0,0,515,516,5,80,0,0,516,
  	543,3,86,43,30,517,518,5,68,0,0,518,543,3,86,43,29,519,520,5,59,0,0,520,
  	543,3,86,43,28,521,522,5,15,0,0,522,543,3,86,43,27,523,524,5,16,0,0,524,
  	543,3,86,43,26,525,526,5,17,0,0,526,543,3,86,43,25,527,528,5,18,0,0,528,
  	543,3,86,43,24,529,530,5,19,0,0,530,543,3,86,43,23,531,532,5,20,0,0,532,
  	543,3,86,43,22,533,543,5,75,0,0,534,543,5,98,0,0,535,543,3,90,45,0,536,
  	543,3,64,32,0,537,543,3,70,35,0,538,539,5,5,0,0,539,540,3,84,42,0,540,
  	541,5,6,0,0,541,543,1,0,0,0,542,496,1,0,0,0,542,510,1,0,0,0,542,515,1,
  	0,0,0,542,517,1,0,0,0,542,519,1,0,0,0,542,521,1,0,0,0,542,523,1,0,0,0,
  	542,525,1,0,0,0,542,527,1,0,0,0,542,529,1,0,0,0,542,531,1,0,0,0,542,533,
  	1,0,0,0,542,534,1,0,0,0,542,535,1,0,0,0,542,536,1,0,0,0,542,537,1,0,0,
  	0,542,538,1,0,0,0,543,611,1,0,0,0,544,545,10,21,0,0,545,546,7,0,0,0,546,
  	610,3,86,43,22,547,548,10,20,0,0,548,549,7,1,0,0,549,610,3,86,43,21,550,
  	551,10,19,0,0,551,552,7,2,0,0,552,610,3,86,43,20,553,554,10,18,0,0,554,
  	555,7,3,0,0,555,610,3,86,43,19,556,557,10,17,0,0,557,558,5,58,0,0,558,
  	610,3,86,43,18,559,560,10,16,0,0,560,561,5,81,0,0,561,610,3,86,43,17,
  	562,563,10,15,0,0,563,564,7,4,0,0,564,610,3,86,43,16,565,566,10,14,0,
  	0,566,567,5,35,0,0,567,610,3,86,43,15,568,569,10,13,0,0,569,570,5,36,
  	0,0,570,610,3,86,43,14,571,572,10,12,0,0,572,573,5,37,0,0,573,610,3,86,
  	43,13,574,575,10,11,0,0,575,576,5,38,0,0,576,610,3,86,43,12,577,578,10,
  	10,0,0,578,579,5,39,0,0,579,610,3,86,43,11,580,581,10,9,0,0,581,582,5,
  	12,0,0,582,583,3,86,43,0,583,584,5,13,0,0,584,585,3,86,43,10,585,610,
  	1,0,0,0,586,587,10,8,0,0,587,588,5,11,0,0,588,610,3,86,43,9,589,590,10,
  	7,0,0,590,591,3,88,44,0,591,592,3,86,43,8,592,610,1,0,0,0,593,594,10,
  	36,0,0,594,595,5,3,0,0,595,596,3,84,42,0,596,597,5,4,0,0,597,610,1,0,
  	0,0,598,599,10,35,0,0,599,600,5,14,0,0,600,610,3,94,47,0,601,602,10,34,
  	0,0,602,610,3,80,40,0,603,604,10,32,0,0,604,605,4,43,24,0,605,610,5,15,
  	0,0,606,607,10,31,0,0,607,608,4,43,26,0,608,610,5,16,0,0,609,544,1,0,
  	0,0,609,547,1,0,0,0,609,550,1,0,0,0,609,553,1,0,0,0,609,556,1,0,0,0,609,
  	559,1,0,0,0,609,562,1,0,0,0,609,565,1,0,0,0,609,568,1,0,0,0,609,571,1,
  	0,0,0,609,574,1,0,0,0,609,577,1,0,0,0,609,580,1,0,0,0,609,586,1,0,0,0,
  	609,589,1,0,0,0,609,593,1,0,0,0,609,598,1,0,0,0,609,601,1,0,0,0,609,603,
  	1,0,0,0,609,606,1,0,0,0,610,613,1,0,0,0,611,609,1,0,0,0,611,612,1,0,0,
  	0,612,87,1,0,0,0,613,611,1,0,0,0,614,615,7,5,0,0,615,89,1,0,0,0,616,619,
  	7,6,0,0,617,619,3,92,46,0,618,616,1,0,0,0,618,617,1,0,0,0,619,91,1,0,
  	0,0,620,621,7,7,0,0,621,93,1,0,0,0,622,625,5,98,0,0,623,625,3,96,48,0,
  	624,622,1,0,0,0,624,623,1,0,0,0,625,95,1,0,0,0,626,630,3,98,49,0,627,
  	630,3,100,50,0,628,630,7,8,0,0,629,626,1,0,0,0,629,627,1,0,0,0,629,628,
  	1,0,0,0,630,97,1,0,0,0,631,632,7,9,0,0,632,99,1,0,0,0,633,634,7,10,0,
  	0,634,101,1,0,0,0,635,636,4,51,27,0,636,637,5,98,0,0,637,638,3,76,38,
  	0,638,103,1,0,0,0,639,640,4,52,28,0,640,641,5,98,0,0,641,642,3,76,38,
  	0,642,105,1,0,0,0,643,648,5,9,0,0,644,648,5,0,0,1,645,648,4,53,29,0,646,
  	648,4,53,30,0,647,643,1,0,0,0,647,644,1,0,0,0,647,645,1,0,0,0,647,646,
  	1,0,0,0,648,107,1,0,0,0,649,650,5,0,0,1,650,109,1,0,0,0,56,111,118,122,
  	139,143,150,160,167,172,190,209,213,217,227,231,242,246,277,282,289,296,
  	314,318,320,327,333,338,362,380,392,396,400,403,406,411,416,421,427,431,
  	434,443,465,470,476,485,493,499,503,513,542,609,611,618,624,629,647
  };
  staticData->serializedATN = antlr4::atn::SerializedATNView(serializedATNSegment, sizeof(serializedATNSegment) / sizeof(serializedATNSegment[0]));

  antlr4::atn::ATNDeserializer deserializer;
  staticData->atn = deserializer.deserialize(staticData->serializedATN);

  const size_t count = staticData->atn->getNumberOfDecisions();
  staticData->decisionToDFA.reserve(count);
  for (size_t i = 0; i < count; i++) { 
    staticData->decisionToDFA.emplace_back(staticData->atn->getDecisionState(i), i);
  }
  ecmascriptParserStaticData = staticData.release();
}

}

ECMAScriptParser::ECMAScriptParser(TokenStream *input) : ECMAScriptParser(input, antlr4::atn::ParserATNSimulatorOptions()) {}

ECMAScriptParser::ECMAScriptParser(TokenStream *input, const antlr4::atn::ParserATNSimulatorOptions &options) : Parser(input) {
  ECMAScriptParser::initialize();
  _interpreter = new atn::ParserATNSimulator(this, *ecmascriptParserStaticData->atn, ecmascriptParserStaticData->decisionToDFA, ecmascriptParserStaticData->sharedContextCache, options);
}

ECMAScriptParser::~ECMAScriptParser() {
  delete _interpreter;
}

const atn::ATN& ECMAScriptParser::getATN() const {
  return *ecmascriptParserStaticData->atn;
}

std::string ECMAScriptParser::getGrammarFileName() const {
  return "ECMAScript.g4";
}

const std::vector<std::string>& ECMAScriptParser::getRuleNames() const {
  return ecmascriptParserStaticData->ruleNames;
}

const dfa::Vocabulary& ECMAScriptParser::getVocabulary() const {
  return ecmascriptParserStaticData->vocabulary;
}

antlr4::atn::SerializedATNView ECMAScriptParser::getSerializedATN() const {
  return ecmascriptParserStaticData->serializedATN;
}


//----------------- ProgramContext ------------------------------------------------------------------

ECMAScriptParser::ProgramContext::ProgramContext(ParserRuleContext *parent, size_t invokingState)
  : ParserRuleContext(parent, invokingState) {
}

tree::TerminalNode* ECMAScriptParser::ProgramContext::EOF() {
  return getToken(ECMAScriptParser::EOF, 0);
}

ECMAScriptParser::SourceElementsContext* ECMAScriptParser::ProgramContext::sourceElements() {
  return getRuleContext<ECMAScriptParser::SourceElementsContext>(0);
}


size_t ECMAScriptParser::ProgramContext::getRuleIndex() const {
  return ECMAScriptParser::RuleProgram;
}


std::any ECMAScriptParser::ProgramContext::accept(tree::ParseTreeVisitor *visitor) {
  if (auto parserVisitor = dynamic_cast<ECMAScriptVisitor*>(visitor))
    return parserVisitor->visitProgram(this);
  else
    return visitor->visitChildren(this);
}

ECMAScriptParser::ProgramContext* ECMAScriptParser::program() {
  ProgramContext *_localctx = _tracker.createInstance<ProgramContext>(_ctx, getState());
  enterRule(_localctx, 0, ECMAScriptParser::RuleProgram);

#if __cplusplus > 201703L
  auto onExit = finally([=, this] {
#else
  auto onExit = finally([=] {
#endif
    exitRule();
  });
  try {
    enterOuterAlt(_localctx, 1);
    setState(111);
    _errHandler->sync(this);

    switch (getInterpreter<atn::ParserATNSimulator>()->adaptivePredict(_input, 0, _ctx)) {
    case 1: {
      setState(110);
      sourceElements();
      break;
    }

    default:
      break;
    }
    setState(113);
    match(ECMAScriptParser::EOF);
   
  }
  catch (RecognitionException &e) {
    _errHandler->reportError(this, e);
    _localctx->exception = std::current_exception();
    _errHandler->recover(this, _localctx->exception);
  }

  return _localctx;
}

//----------------- SourceElementsContext ------------------------------------------------------------------

ECMAScriptParser::SourceElementsContext::SourceElementsContext(ParserRuleContext *parent, size_t invokingState)
  : ParserRuleContext(parent, invokingState) {
}

std::vector<ECMAScriptParser::SourceElementContext *> ECMAScriptParser::SourceElementsContext::sourceElement() {
  return getRuleContexts<ECMAScriptParser::SourceElementContext>();
}

ECMAScriptParser::SourceElementContext* ECMAScriptParser::SourceElementsContext::sourceElement(size_t i) {
  return getRuleContext<ECMAScriptParser::SourceElementContext>(i);
}


size_t ECMAScriptParser::SourceElementsContext::getRuleIndex() const {
  return ECMAScriptParser::RuleSourceElements;
}


std::any ECMAScriptParser::SourceElementsContext::accept(tree::ParseTreeVisitor *visitor) {
  if (auto parserVisitor = dynamic_cast<ECMAScriptVisitor*>(visitor))
    return parserVisitor->visitSourceElements(this);
  else
    return visitor->visitChildren(this);
}

ECMAScriptParser::SourceElementsContext* ECMAScriptParser::sourceElements() {
  SourceElementsContext *_localctx = _tracker.createInstance<SourceElementsContext>(_ctx, getState());
  enterRule(_localctx, 2, ECMAScriptParser::RuleSourceElements);

#if __cplusplus > 201703L
  auto onExit = finally([=, this] {
#else
  auto onExit = finally([=] {
#endif
    exitRule();
  });
  try {
    size_t alt;
    enterOuterAlt(_localctx, 1);
    setState(116); 
    _errHandler->sync(this);
    alt = 1;
    do {
      switch (alt) {
        case 1: {
              setState(115);
              sourceElement();
              break;
            }

      default:
        throw NoViableAltException(this);
      }
      setState(118); 
      _errHandler->sync(this);
      alt = getInterpreter<atn::ParserATNSimulator>()->adaptivePredict(_input, 1, _ctx);
    } while (alt != 2 && alt != atn::ATN::INVALID_ALT_NUMBER);
   
  }
  catch (RecognitionException &e) {
    _errHandler->reportError(this, e);
    _localctx->exception = std::current_exception();
    _errHandler->recover(this, _localctx->exception);
  }

  return _localctx;
}

//----------------- SourceElementContext ------------------------------------------------------------------

ECMAScriptParser::SourceElementContext::SourceElementContext(ParserRuleContext *parent, size_t invokingState)
  : ParserRuleContext(parent, invokingState) {
}

ECMAScriptParser::StatementContext* ECMAScriptParser::SourceElementContext::statement() {
  return getRuleContext<ECMAScriptParser::StatementContext>(0);
}

ECMAScriptParser::FunctionDeclarationContext* ECMAScriptParser::SourceElementContext::functionDeclaration() {
  return getRuleContext<ECMAScriptParser::FunctionDeclarationContext>(0);
}


size_t ECMAScriptParser::SourceElementContext::getRuleIndex() const {
  return ECMAScriptParser::RuleSourceElement;
}


std::any ECMAScriptParser::SourceElementContext::accept(tree::ParseTreeVisitor *visitor) {
  if (auto parserVisitor = dynamic_cast<ECMAScriptVisitor*>(visitor))
    return parserVisitor->visitSourceElement(this);
  else
    return visitor->visitChildren(this);
}

ECMAScriptParser::SourceElementContext* ECMAScriptParser::sourceElement() {
  SourceElementContext *_localctx = _tracker.createInstance<SourceElementContext>(_ctx, getState());
  enterRule(_localctx, 4, ECMAScriptParser::RuleSourceElement);

#if __cplusplus > 201703L
  auto onExit = finally([=, this] {
#else
  auto onExit = finally([=] {
#endif
    exitRule();
  });
  try {
    setState(122);
    _errHandler->sync(this);
    switch (getInterpreter<atn::ParserATNSimulator>()->adaptivePredict(_input, 2, _ctx)) {
    case 1: {
      enterOuterAlt(_localctx, 1);
      setState(120);
      statement();
      break;
    }

    case 2: {
      enterOuterAlt(_localctx, 2);
      setState(121);
      functionDeclaration();
      break;
    }

    default:
      break;
    }
   
  }
  catch (RecognitionException &e) {
    _errHandler->reportError(this, e);
    _localctx->exception = std::current_exception();
    _errHandler->recover(this, _localctx->exception);
  }

  return _localctx;
}

//----------------- StatementContext ------------------------------------------------------------------

ECMAScriptParser::StatementContext::StatementContext(ParserRuleContext *parent, size_t invokingState)
  : ParserRuleContext(parent, invokingState) {
}

ECMAScriptParser::BlockContext* ECMAScriptParser::StatementContext::block() {
  return getRuleContext<ECMAScriptParser::BlockContext>(0);
}

ECMAScriptParser::VariableStatementContext* ECMAScriptParser::StatementContext::variableStatement() {
  return getRuleContext<ECMAScriptParser::VariableStatementContext>(0);
}

ECMAScriptParser::EmptyStatementContext* ECMAScriptParser::StatementContext::emptyStatement() {
  return getRuleContext<ECMAScriptParser::EmptyStatementContext>(0);
}

ECMAScriptParser::ExpressionStatementContext* ECMAScriptParser::StatementContext::expressionStatement() {
  return getRuleContext<ECMAScriptParser::ExpressionStatementContext>(0);
}

ECMAScriptParser::IfStatementContext* ECMAScriptParser::StatementContext::ifStatement() {
  return getRuleContext<ECMAScriptParser::IfStatementContext>(0);
}

ECMAScriptParser::IterationStatementContext* ECMAScriptParser::StatementContext::iterationStatement() {
  return getRuleContext<ECMAScriptParser::IterationStatementContext>(0);
}

ECMAScriptParser::ContinueStatementContext* ECMAScriptParser::StatementContext::continueStatement() {
  return getRuleContext<ECMAScriptParser::ContinueStatementContext>(0);
}

ECMAScriptParser::BreakStatementContext* ECMAScriptParser::StatementContext::breakStatement() {
  return getRuleContext<ECMAScriptParser::BreakStatementContext>(0);
}

ECMAScriptParser::ReturnStatementContext* ECMAScriptParser::StatementContext::returnStatement() {
  return getRuleContext<ECMAScriptParser::ReturnStatementContext>(0);
}

ECMAScriptParser::WithStatementContext* ECMAScriptParser::StatementContext::withStatement() {
  return getRuleContext<ECMAScriptParser::WithStatementContext>(0);
}

ECMAScriptParser::LabelledStatementContext* ECMAScriptParser::StatementContext::labelledStatement() {
  return getRuleContext<ECMAScriptParser::LabelledStatementContext>(0);
}

ECMAScriptParser::SwitchStatementContext* ECMAScriptParser::StatementContext::switchStatement() {
  return getRuleContext<ECMAScriptParser::SwitchStatementContext>(0);
}

ECMAScriptParser::ThrowStatementContext* ECMAScriptParser::StatementContext::throwStatement() {
  return getRuleContext<ECMAScriptParser::ThrowStatementContext>(0);
}

ECMAScriptParser::TryStatementContext* ECMAScriptParser::StatementContext::tryStatement() {
  return getRuleContext<ECMAScriptParser::TryStatementContext>(0);
}

ECMAScriptParser::DebuggerStatementContext* ECMAScriptParser::StatementContext::debuggerStatement() {
  return getRuleContext<ECMAScriptParser::DebuggerStatementContext>(0);
}


size_t ECMAScriptParser::StatementContext::getRuleIndex() const {
  return ECMAScriptParser::RuleStatement;
}


std::any ECMAScriptParser::StatementContext::accept(tree::ParseTreeVisitor *visitor) {
  if (auto parserVisitor = dynamic_cast<ECMAScriptVisitor*>(visitor))
    return parserVisitor->visitStatement(this);
  else
    return visitor->visitChildren(this);
}

ECMAScriptParser::StatementContext* ECMAScriptParser::statement() {
  StatementContext *_localctx = _tracker.createInstance<StatementContext>(_ctx, getState());
  enterRule(_localctx, 6, ECMAScriptParser::RuleStatement);

#if __cplusplus > 201703L
  auto onExit = finally([=, this] {
#else
  auto onExit = finally([=] {
#endif
    exitRule();
  });
  try {
    setState(139);
    _errHandler->sync(this);
    switch (getInterpreter<atn::ParserATNSimulator>()->adaptivePredict(_input, 3, _ctx)) {
    case 1: {
      enterOuterAlt(_localctx, 1);
      setState(124);
      block();
      break;
    }

    case 2: {
      enterOuterAlt(_localctx, 2);
      setState(125);
      variableStatement();
      break;
    }

    case 3: {
      enterOuterAlt(_localctx, 3);
      setState(126);
      emptyStatement();
      break;
    }

    case 4: {
      enterOuterAlt(_localctx, 4);
      setState(127);
      expressionStatement();
      break;
    }

    case 5: {
      enterOuterAlt(_localctx, 5);
      setState(128);
      ifStatement();
      break;
    }

    case 6: {
      enterOuterAlt(_localctx, 6);
      setState(129);
      iterationStatement();
      break;
    }

    case 7: {
      enterOuterAlt(_localctx, 7);
      setState(130);
      continueStatement();
      break;
    }

    case 8: {
      enterOuterAlt(_localctx, 8);
      setState(131);
      breakStatement();
      break;
    }

    case 9: {
      enterOuterAlt(_localctx, 9);
      setState(132);
      returnStatement();
      break;
    }

    case 10: {
      enterOuterAlt(_localctx, 10);
      setState(133);
      withStatement();
      break;
    }

    case 11: {
      enterOuterAlt(_localctx, 11);
      setState(134);
      labelledStatement();
      break;
    }

    case 12: {
      enterOuterAlt(_localctx, 12);
      setState(135);
      switchStatement();
      break;
    }

    case 13: {
      enterOuterAlt(_localctx, 13);
      setState(136);
      throwStatement();
      break;
    }

    case 14: {
      enterOuterAlt(_localctx, 14);
      setState(137);
      tryStatement();
      break;
    }

    case 15: {
      enterOuterAlt(_localctx, 15);
      setState(138);
      debuggerStatement();
      break;
    }

    default:
      break;
    }
   
  }
  catch (RecognitionException &e) {
    _errHandler->reportError(this, e);
    _localctx->exception = std::current_exception();
    _errHandler->recover(this, _localctx->exception);
  }

  return _localctx;
}

//----------------- BlockContext ------------------------------------------------------------------

ECMAScriptParser::BlockContext::BlockContext(ParserRuleContext *parent, size_t invokingState)
  : ParserRuleContext(parent, invokingState) {
}

tree::TerminalNode* ECMAScriptParser::BlockContext::OpenBrace() {
  return getToken(ECMAScriptParser::OpenBrace, 0);
}

tree::TerminalNode* ECMAScriptParser::BlockContext::CloseBrace() {
  return getToken(ECMAScriptParser::CloseBrace, 0);
}

ECMAScriptParser::StatementListContext* ECMAScriptParser::BlockContext::statementList() {
  return getRuleContext<ECMAScriptParser::StatementListContext>(0);
}


size_t ECMAScriptParser::BlockContext::getRuleIndex() const {
  return ECMAScriptParser::RuleBlock;
}


std::any ECMAScriptParser::BlockContext::accept(tree::ParseTreeVisitor *visitor) {
  if (auto parserVisitor = dynamic_cast<ECMAScriptVisitor*>(visitor))
    return parserVisitor->visitBlock(this);
  else
    return visitor->visitChildren(this);
}

ECMAScriptParser::BlockContext* ECMAScriptParser::block() {
  BlockContext *_localctx = _tracker.createInstance<BlockContext>(_ctx, getState());
  enterRule(_localctx, 8, ECMAScriptParser::RuleBlock);

#if __cplusplus > 201703L
  auto onExit = finally([=, this] {
#else
  auto onExit = finally([=] {
#endif
    exitRule();
  });
  try {
    enterOuterAlt(_localctx, 1);
    setState(141);
    match(ECMAScriptParser::OpenBrace);
    setState(143);
    _errHandler->sync(this);

    switch (getInterpreter<atn::ParserATNSimulator>()->adaptivePredict(_input, 4, _ctx)) {
    case 1: {
      setState(142);
      statementList();
      break;
    }

    default:
      break;
    }
    setState(145);
    match(ECMAScriptParser::CloseBrace);
   
  }
  catch (RecognitionException &e) {
    _errHandler->reportError(this, e);
    _localctx->exception = std::current_exception();
    _errHandler->recover(this, _localctx->exception);
  }

  return _localctx;
}

//----------------- StatementListContext ------------------------------------------------------------------

ECMAScriptParser::StatementListContext::StatementListContext(ParserRuleContext *parent, size_t invokingState)
  : ParserRuleContext(parent, invokingState) {
}

std::vector<ECMAScriptParser::StatementContext *> ECMAScriptParser::StatementListContext::statement() {
  return getRuleContexts<ECMAScriptParser::StatementContext>();
}

ECMAScriptParser::StatementContext* ECMAScriptParser::StatementListContext::statement(size_t i) {
  return getRuleContext<ECMAScriptParser::StatementContext>(i);
}


size_t ECMAScriptParser::StatementListContext::getRuleIndex() const {
  return ECMAScriptParser::RuleStatementList;
}


std::any ECMAScriptParser::StatementListContext::accept(tree::ParseTreeVisitor *visitor) {
  if (auto parserVisitor = dynamic_cast<ECMAScriptVisitor*>(visitor))
    return parserVisitor->visitStatementList(this);
  else
    return visitor->visitChildren(this);
}

ECMAScriptParser::StatementListContext* ECMAScriptParser::statementList() {
  StatementListContext *_localctx = _tracker.createInstance<StatementListContext>(_ctx, getState());
  enterRule(_localctx, 10, ECMAScriptParser::RuleStatementList);

#if __cplusplus > 201703L
  auto onExit = finally([=, this] {
#else
  auto onExit = finally([=] {
#endif
    exitRule();
  });
  try {
    size_t alt;
    enterOuterAlt(_localctx, 1);
    setState(148); 
    _errHandler->sync(this);
    alt = 1;
    do {
      switch (alt) {
        case 1: {
              setState(147);
              statement();
              break;
            }

      default:
        throw NoViableAltException(this);
      }
      setState(150); 
      _errHandler->sync(this);
      alt = getInterpreter<atn::ParserATNSimulator>()->adaptivePredict(_input, 5, _ctx);
    } while (alt != 2 && alt != atn::ATN::INVALID_ALT_NUMBER);
   
  }
  catch (RecognitionException &e) {
    _errHandler->reportError(this, e);
    _localctx->exception = std::current_exception();
    _errHandler->recover(this, _localctx->exception);
  }

  return _localctx;
}

//----------------- VariableStatementContext ------------------------------------------------------------------

ECMAScriptParser::VariableStatementContext::VariableStatementContext(ParserRuleContext *parent, size_t invokingState)
  : ParserRuleContext(parent, invokingState) {
}

tree::TerminalNode* ECMAScriptParser::VariableStatementContext::Var() {
  return getToken(ECMAScriptParser::Var, 0);
}

ECMAScriptParser::VariableDeclarationListContext* ECMAScriptParser::VariableStatementContext::variableDeclarationList() {
  return getRuleContext<ECMAScriptParser::VariableDeclarationListContext>(0);
}

ECMAScriptParser::EosContext* ECMAScriptParser::VariableStatementContext::eos() {
  return getRuleContext<ECMAScriptParser::EosContext>(0);
}

tree::TerminalNode* ECMAScriptParser::VariableStatementContext::Let() {
  return getToken(ECMAScriptParser::Let, 0);
}


size_t ECMAScriptParser::VariableStatementContext::getRuleIndex() const {
  return ECMAScriptParser::RuleVariableStatement;
}


std::any ECMAScriptParser::VariableStatementContext::accept(tree::ParseTreeVisitor *visitor) {
  if (auto parserVisitor = dynamic_cast<ECMAScriptVisitor*>(visitor))
    return parserVisitor->visitVariableStatement(this);
  else
    return visitor->visitChildren(this);
}

ECMAScriptParser::VariableStatementContext* ECMAScriptParser::variableStatement() {
  VariableStatementContext *_localctx = _tracker.createInstance<VariableStatementContext>(_ctx, getState());
  enterRule(_localctx, 12, ECMAScriptParser::RuleVariableStatement);

#if __cplusplus > 201703L
  auto onExit = finally([=, this] {
#else
  auto onExit = finally([=] {
#endif
    exitRule();
  });
  try {
    setState(160);
    _errHandler->sync(this);
    switch (_input->LA(1)) {
      case ECMAScriptParser::Var: {
        enterOuterAlt(_localctx, 1);
        setState(152);
        match(ECMAScriptParser::Var);
        setState(153);
        variableDeclarationList();
        setState(154);
        eos();
        break;
      }

      case ECMAScriptParser::Let: {
        enterOuterAlt(_localctx, 2);
        setState(156);
        match(ECMAScriptParser::Let);
        setState(157);
        variableDeclarationList();
        setState(158);
        eos();
        break;
      }

    default:
      throw NoViableAltException(this);
    }
   
  }
  catch (RecognitionException &e) {
    _errHandler->reportError(this, e);
    _localctx->exception = std::current_exception();
    _errHandler->recover(this, _localctx->exception);
  }

  return _localctx;
}

//----------------- VariableDeclarationListContext ------------------------------------------------------------------

ECMAScriptParser::VariableDeclarationListContext::VariableDeclarationListContext(ParserRuleContext *parent, size_t invokingState)
  : ParserRuleContext(parent, invokingState) {
}

std::vector<ECMAScriptParser::VariableDeclarationContext *> ECMAScriptParser::VariableDeclarationListContext::variableDeclaration() {
  return getRuleContexts<ECMAScriptParser::VariableDeclarationContext>();
}

ECMAScriptParser::VariableDeclarationContext* ECMAScriptParser::VariableDeclarationListContext::variableDeclaration(size_t i) {
  return getRuleContext<ECMAScriptParser::VariableDeclarationContext>(i);
}

std::vector<tree::TerminalNode *> ECMAScriptParser::VariableDeclarationListContext::Comma() {
  return getTokens(ECMAScriptParser::Comma);
}

tree::TerminalNode* ECMAScriptParser::VariableDeclarationListContext::Comma(size_t i) {
  return getToken(ECMAScriptParser::Comma, i);
}


size_t ECMAScriptParser::VariableDeclarationListContext::getRuleIndex() const {
  return ECMAScriptParser::RuleVariableDeclarationList;
}


std::any ECMAScriptParser::VariableDeclarationListContext::accept(tree::ParseTreeVisitor *visitor) {
  if (auto parserVisitor = dynamic_cast<ECMAScriptVisitor*>(visitor))
    return parserVisitor->visitVariableDeclarationList(this);
  else
    return visitor->visitChildren(this);
}

ECMAScriptParser::VariableDeclarationListContext* ECMAScriptParser::variableDeclarationList() {
  VariableDeclarationListContext *_localctx = _tracker.createInstance<VariableDeclarationListContext>(_ctx, getState());
  enterRule(_localctx, 14, ECMAScriptParser::RuleVariableDeclarationList);

#if __cplusplus > 201703L
  auto onExit = finally([=, this] {
#else
  auto onExit = finally([=] {
#endif
    exitRule();
  });
  try {
    size_t alt;
    enterOuterAlt(_localctx, 1);
    setState(162);
    variableDeclaration();
    setState(167);
    _errHandler->sync(this);
    alt = getInterpreter<atn::ParserATNSimulator>()->adaptivePredict(_input, 7, _ctx);
    while (alt != 2 && alt != atn::ATN::INVALID_ALT_NUMBER) {
      if (alt == 1) {
        setState(163);
        match(ECMAScriptParser::Comma);
        setState(164);
        variableDeclaration(); 
      }
      setState(169);
      _errHandler->sync(this);
      alt = getInterpreter<atn::ParserATNSimulator>()->adaptivePredict(_input, 7, _ctx);
    }
   
  }
  catch (RecognitionException &e) {
    _errHandler->reportError(this, e);
    _localctx->exception = std::current_exception();
    _errHandler->recover(this, _localctx->exception);
  }

  return _localctx;
}

//----------------- VariableDeclarationContext ------------------------------------------------------------------

ECMAScriptParser::VariableDeclarationContext::VariableDeclarationContext(ParserRuleContext *parent, size_t invokingState)
  : ParserRuleContext(parent, invokingState) {
}

tree::TerminalNode* ECMAScriptParser::VariableDeclarationContext::Identifier() {
  return getToken(ECMAScriptParser::Identifier, 0);
}

ECMAScriptParser::InitialiserContext* ECMAScriptParser::VariableDeclarationContext::initialiser() {
  return getRuleContext<ECMAScriptParser::InitialiserContext>(0);
}


size_t ECMAScriptParser::VariableDeclarationContext::getRuleIndex() const {
  return ECMAScriptParser::RuleVariableDeclaration;
}


std::any ECMAScriptParser::VariableDeclarationContext::accept(tree::ParseTreeVisitor *visitor) {
  if (auto parserVisitor = dynamic_cast<ECMAScriptVisitor*>(visitor))
    return parserVisitor->visitVariableDeclaration(this);
  else
    return visitor->visitChildren(this);
}

ECMAScriptParser::VariableDeclarationContext* ECMAScriptParser::variableDeclaration() {
  VariableDeclarationContext *_localctx = _tracker.createInstance<VariableDeclarationContext>(_ctx, getState());
  enterRule(_localctx, 16, ECMAScriptParser::RuleVariableDeclaration);

#if __cplusplus > 201703L
  auto onExit = finally([=, this] {
#else
  auto onExit = finally([=] {
#endif
    exitRule();
  });
  try {
    enterOuterAlt(_localctx, 1);
    setState(170);
    match(ECMAScriptParser::Identifier);
    setState(172);
    _errHandler->sync(this);

    switch (getInterpreter<atn::ParserATNSimulator>()->adaptivePredict(_input, 8, _ctx)) {
    case 1: {
      setState(171);
      initialiser();
      break;
    }

    default:
      break;
    }
   
  }
  catch (RecognitionException &e) {
    _errHandler->reportError(this, e);
    _localctx->exception = std::current_exception();
    _errHandler->recover(this, _localctx->exception);
  }

  return _localctx;
}

//----------------- InitialiserContext ------------------------------------------------------------------

ECMAScriptParser::InitialiserContext::InitialiserContext(ParserRuleContext *parent, size_t invokingState)
  : ParserRuleContext(parent, invokingState) {
}

tree::TerminalNode* ECMAScriptParser::InitialiserContext::Assign() {
  return getToken(ECMAScriptParser::Assign, 0);
}

ECMAScriptParser::SingleExpressionContext* ECMAScriptParser::InitialiserContext::singleExpression() {
  return getRuleContext<ECMAScriptParser::SingleExpressionContext>(0);
}


size_t ECMAScriptParser::InitialiserContext::getRuleIndex() const {
  return ECMAScriptParser::RuleInitialiser;
}


std::any ECMAScriptParser::InitialiserContext::accept(tree::ParseTreeVisitor *visitor) {
  if (auto parserVisitor = dynamic_cast<ECMAScriptVisitor*>(visitor))
    return parserVisitor->visitInitialiser(this);
  else
    return visitor->visitChildren(this);
}

ECMAScriptParser::InitialiserContext* ECMAScriptParser::initialiser() {
  InitialiserContext *_localctx = _tracker.createInstance<InitialiserContext>(_ctx, getState());
  enterRule(_localctx, 18, ECMAScriptParser::RuleInitialiser);

#if __cplusplus > 201703L
  auto onExit = finally([=, this] {
#else
  auto onExit = finally([=] {
#endif
    exitRule();
  });
  try {
    enterOuterAlt(_localctx, 1);
    setState(174);
    match(ECMAScriptParser::Assign);
    setState(175);
    singleExpression(0);
   
  }
  catch (RecognitionException &e) {
    _errHandler->reportError(this, e);
    _localctx->exception = std::current_exception();
    _errHandler->recover(this, _localctx->exception);
  }

  return _localctx;
}

//----------------- EmptyStatementContext ------------------------------------------------------------------

ECMAScriptParser::EmptyStatementContext::EmptyStatementContext(ParserRuleContext *parent, size_t invokingState)
  : ParserRuleContext(parent, invokingState) {
}

tree::TerminalNode* ECMAScriptParser::EmptyStatementContext::SemiColon() {
  return getToken(ECMAScriptParser::SemiColon, 0);
}


size_t ECMAScriptParser::EmptyStatementContext::getRuleIndex() const {
  return ECMAScriptParser::RuleEmptyStatement;
}


std::any ECMAScriptParser::EmptyStatementContext::accept(tree::ParseTreeVisitor *visitor) {
  if (auto parserVisitor = dynamic_cast<ECMAScriptVisitor*>(visitor))
    return parserVisitor->visitEmptyStatement(this);
  else
    return visitor->visitChildren(this);
}

ECMAScriptParser::EmptyStatementContext* ECMAScriptParser::emptyStatement() {
  EmptyStatementContext *_localctx = _tracker.createInstance<EmptyStatementContext>(_ctx, getState());
  enterRule(_localctx, 20, ECMAScriptParser::RuleEmptyStatement);

#if __cplusplus > 201703L
  auto onExit = finally([=, this] {
#else
  auto onExit = finally([=] {
#endif
    exitRule();
  });
  try {
    enterOuterAlt(_localctx, 1);
    setState(177);
    match(ECMAScriptParser::SemiColon);
   
  }
  catch (RecognitionException &e) {
    _errHandler->reportError(this, e);
    _localctx->exception = std::current_exception();
    _errHandler->recover(this, _localctx->exception);
  }

  return _localctx;
}

//----------------- ExpressionStatementContext ------------------------------------------------------------------

ECMAScriptParser::ExpressionStatementContext::ExpressionStatementContext(ParserRuleContext *parent, size_t invokingState)
  : ParserRuleContext(parent, invokingState) {
}

ECMAScriptParser::ExpressionSequenceContext* ECMAScriptParser::ExpressionStatementContext::expressionSequence() {
  return getRuleContext<ECMAScriptParser::ExpressionSequenceContext>(0);
}

ECMAScriptParser::EosContext* ECMAScriptParser::ExpressionStatementContext::eos() {
  return getRuleContext<ECMAScriptParser::EosContext>(0);
}


size_t ECMAScriptParser::ExpressionStatementContext::getRuleIndex() const {
  return ECMAScriptParser::RuleExpressionStatement;
}


std::any ECMAScriptParser::ExpressionStatementContext::accept(tree::ParseTreeVisitor *visitor) {
  if (auto parserVisitor = dynamic_cast<ECMAScriptVisitor*>(visitor))
    return parserVisitor->visitExpressionStatement(this);
  else
    return visitor->visitChildren(this);
}

ECMAScriptParser::ExpressionStatementContext* ECMAScriptParser::expressionStatement() {
  ExpressionStatementContext *_localctx = _tracker.createInstance<ExpressionStatementContext>(_ctx, getState());
  enterRule(_localctx, 22, ECMAScriptParser::RuleExpressionStatement);

#if __cplusplus > 201703L
  auto onExit = finally([=, this] {
#else
  auto onExit = finally([=] {
#endif
    exitRule();
  });
  try {
    enterOuterAlt(_localctx, 1);
    setState(179);

    if (!((_input.La(1) != OpenBrace) && (_input.La(1) != Function))) throw FailedPredicateException(this, "(_input.La(1) != OpenBrace) && (_input.La(1) != Function)");
    setState(180);
    expressionSequence();
    setState(181);
    eos();
   
  }
  catch (RecognitionException &e) {
    _errHandler->reportError(this, e);
    _localctx->exception = std::current_exception();
    _errHandler->recover(this, _localctx->exception);
  }

  return _localctx;
}

//----------------- IfStatementContext ------------------------------------------------------------------

ECMAScriptParser::IfStatementContext::IfStatementContext(ParserRuleContext *parent, size_t invokingState)
  : ParserRuleContext(parent, invokingState) {
}

tree::TerminalNode* ECMAScriptParser::IfStatementContext::If() {
  return getToken(ECMAScriptParser::If, 0);
}

tree::TerminalNode* ECMAScriptParser::IfStatementContext::OpenParen() {
  return getToken(ECMAScriptParser::OpenParen, 0);
}

ECMAScriptParser::ExpressionSequenceContext* ECMAScriptParser::IfStatementContext::expressionSequence() {
  return getRuleContext<ECMAScriptParser::ExpressionSequenceContext>(0);
}

tree::TerminalNode* ECMAScriptParser::IfStatementContext::CloseParen() {
  return getToken(ECMAScriptParser::CloseParen, 0);
}

std::vector<ECMAScriptParser::StatementContext *> ECMAScriptParser::IfStatementContext::statement() {
  return getRuleContexts<ECMAScriptParser::StatementContext>();
}

ECMAScriptParser::StatementContext* ECMAScriptParser::IfStatementContext::statement(size_t i) {
  return getRuleContext<ECMAScriptParser::StatementContext>(i);
}

tree::TerminalNode* ECMAScriptParser::IfStatementContext::Else() {
  return getToken(ECMAScriptParser::Else, 0);
}


size_t ECMAScriptParser::IfStatementContext::getRuleIndex() const {
  return ECMAScriptParser::RuleIfStatement;
}


std::any ECMAScriptParser::IfStatementContext::accept(tree::ParseTreeVisitor *visitor) {
  if (auto parserVisitor = dynamic_cast<ECMAScriptVisitor*>(visitor))
    return parserVisitor->visitIfStatement(this);
  else
    return visitor->visitChildren(this);
}

ECMAScriptParser::IfStatementContext* ECMAScriptParser::ifStatement() {
  IfStatementContext *_localctx = _tracker.createInstance<IfStatementContext>(_ctx, getState());
  enterRule(_localctx, 24, ECMAScriptParser::RuleIfStatement);

#if __cplusplus > 201703L
  auto onExit = finally([=, this] {
#else
  auto onExit = finally([=] {
#endif
    exitRule();
  });
  try {
    enterOuterAlt(_localctx, 1);
    setState(183);
    match(ECMAScriptParser::If);
    setState(184);
    match(ECMAScriptParser::OpenParen);
    setState(185);
    expressionSequence();
    setState(186);
    match(ECMAScriptParser::CloseParen);
    setState(187);
    statement();
    setState(190);
    _errHandler->sync(this);

    switch (getInterpreter<atn::ParserATNSimulator>()->adaptivePredict(_input, 9, _ctx)) {
    case 1: {
      setState(188);
      match(ECMAScriptParser::Else);
      setState(189);
      statement();
      break;
    }

    default:
      break;
    }
   
  }
  catch (RecognitionException &e) {
    _errHandler->reportError(this, e);
    _localctx->exception = std::current_exception();
    _errHandler->recover(this, _localctx->exception);
  }

  return _localctx;
}

//----------------- IterationStatementContext ------------------------------------------------------------------

ECMAScriptParser::IterationStatementContext::IterationStatementContext(ParserRuleContext *parent, size_t invokingState)
  : ParserRuleContext(parent, invokingState) {
}


size_t ECMAScriptParser::IterationStatementContext::getRuleIndex() const {
  return ECMAScriptParser::RuleIterationStatement;
}

void ECMAScriptParser::IterationStatementContext::copyFrom(IterationStatementContext *ctx) {
  ParserRuleContext::copyFrom(ctx);
}

//----------------- DoStatementContext ------------------------------------------------------------------

tree::TerminalNode* ECMAScriptParser::DoStatementContext::Do() {
  return getToken(ECMAScriptParser::Do, 0);
}

ECMAScriptParser::StatementContext* ECMAScriptParser::DoStatementContext::statement() {
  return getRuleContext<ECMAScriptParser::StatementContext>(0);
}

tree::TerminalNode* ECMAScriptParser::DoStatementContext::While() {
  return getToken(ECMAScriptParser::While, 0);
}

tree::TerminalNode* ECMAScriptParser::DoStatementContext::OpenParen() {
  return getToken(ECMAScriptParser::OpenParen, 0);
}

ECMAScriptParser::ExpressionSequenceContext* ECMAScriptParser::DoStatementContext::expressionSequence() {
  return getRuleContext<ECMAScriptParser::ExpressionSequenceContext>(0);
}

tree::TerminalNode* ECMAScriptParser::DoStatementContext::CloseParen() {
  return getToken(ECMAScriptParser::CloseParen, 0);
}

ECMAScriptParser::EosContext* ECMAScriptParser::DoStatementContext::eos() {
  return getRuleContext<ECMAScriptParser::EosContext>(0);
}

ECMAScriptParser::DoStatementContext::DoStatementContext(IterationStatementContext *ctx) { copyFrom(ctx); }


std::any ECMAScriptParser::DoStatementContext::accept(tree::ParseTreeVisitor *visitor) {
  if (auto parserVisitor = dynamic_cast<ECMAScriptVisitor*>(visitor))
    return parserVisitor->visitDoStatement(this);
  else
    return visitor->visitChildren(this);
}
//----------------- ForVarStatementContext ------------------------------------------------------------------

tree::TerminalNode* ECMAScriptParser::ForVarStatementContext::For() {
  return getToken(ECMAScriptParser::For, 0);
}

tree::TerminalNode* ECMAScriptParser::ForVarStatementContext::OpenParen() {
  return getToken(ECMAScriptParser::OpenParen, 0);
}

tree::TerminalNode* ECMAScriptParser::ForVarStatementContext::Var() {
  return getToken(ECMAScriptParser::Var, 0);
}

ECMAScriptParser::VariableDeclarationListContext* ECMAScriptParser::ForVarStatementContext::variableDeclarationList() {
  return getRuleContext<ECMAScriptParser::VariableDeclarationListContext>(0);
}

std::vector<tree::TerminalNode *> ECMAScriptParser::ForVarStatementContext::SemiColon() {
  return getTokens(ECMAScriptParser::SemiColon);
}

tree::TerminalNode* ECMAScriptParser::ForVarStatementContext::SemiColon(size_t i) {
  return getToken(ECMAScriptParser::SemiColon, i);
}

tree::TerminalNode* ECMAScriptParser::ForVarStatementContext::CloseParen() {
  return getToken(ECMAScriptParser::CloseParen, 0);
}

ECMAScriptParser::StatementContext* ECMAScriptParser::ForVarStatementContext::statement() {
  return getRuleContext<ECMAScriptParser::StatementContext>(0);
}

std::vector<ECMAScriptParser::ExpressionSequenceContext *> ECMAScriptParser::ForVarStatementContext::expressionSequence() {
  return getRuleContexts<ECMAScriptParser::ExpressionSequenceContext>();
}

ECMAScriptParser::ExpressionSequenceContext* ECMAScriptParser::ForVarStatementContext::expressionSequence(size_t i) {
  return getRuleContext<ECMAScriptParser::ExpressionSequenceContext>(i);
}

ECMAScriptParser::ForVarStatementContext::ForVarStatementContext(IterationStatementContext *ctx) { copyFrom(ctx); }


std::any ECMAScriptParser::ForVarStatementContext::accept(tree::ParseTreeVisitor *visitor) {
  if (auto parserVisitor = dynamic_cast<ECMAScriptVisitor*>(visitor))
    return parserVisitor->visitForVarStatement(this);
  else
    return visitor->visitChildren(this);
}
//----------------- ForVarInStatementContext ------------------------------------------------------------------

tree::TerminalNode* ECMAScriptParser::ForVarInStatementContext::For() {
  return getToken(ECMAScriptParser::For, 0);
}

tree::TerminalNode* ECMAScriptParser::ForVarInStatementContext::OpenParen() {
  return getToken(ECMAScriptParser::OpenParen, 0);
}

tree::TerminalNode* ECMAScriptParser::ForVarInStatementContext::Var() {
  return getToken(ECMAScriptParser::Var, 0);
}

ECMAScriptParser::VariableDeclarationContext* ECMAScriptParser::ForVarInStatementContext::variableDeclaration() {
  return getRuleContext<ECMAScriptParser::VariableDeclarationContext>(0);
}

tree::TerminalNode* ECMAScriptParser::ForVarInStatementContext::In() {
  return getToken(ECMAScriptParser::In, 0);
}

ECMAScriptParser::ExpressionSequenceContext* ECMAScriptParser::ForVarInStatementContext::expressionSequence() {
  return getRuleContext<ECMAScriptParser::ExpressionSequenceContext>(0);
}

tree::TerminalNode* ECMAScriptParser::ForVarInStatementContext::CloseParen() {
  return getToken(ECMAScriptParser::CloseParen, 0);
}

ECMAScriptParser::StatementContext* ECMAScriptParser::ForVarInStatementContext::statement() {
  return getRuleContext<ECMAScriptParser::StatementContext>(0);
}

ECMAScriptParser::ForVarInStatementContext::ForVarInStatementContext(IterationStatementContext *ctx) { copyFrom(ctx); }


std::any ECMAScriptParser::ForVarInStatementContext::accept(tree::ParseTreeVisitor *visitor) {
  if (auto parserVisitor = dynamic_cast<ECMAScriptVisitor*>(visitor))
    return parserVisitor->visitForVarInStatement(this);
  else
    return visitor->visitChildren(this);
}
//----------------- ForLetInStatementContext ------------------------------------------------------------------

tree::TerminalNode* ECMAScriptParser::ForLetInStatementContext::For() {
  return getToken(ECMAScriptParser::For, 0);
}

tree::TerminalNode* ECMAScriptParser::ForLetInStatementContext::OpenParen() {
  return getToken(ECMAScriptParser::OpenParen, 0);
}

tree::TerminalNode* ECMAScriptParser::ForLetInStatementContext::Let() {
  return getToken(ECMAScriptParser::Let, 0);
}

ECMAScriptParser::VariableDeclarationContext* ECMAScriptParser::ForLetInStatementContext::variableDeclaration() {
  return getRuleContext<ECMAScriptParser::VariableDeclarationContext>(0);
}

tree::TerminalNode* ECMAScriptParser::ForLetInStatementContext::In() {
  return getToken(ECMAScriptParser::In, 0);
}

ECMAScriptParser::ExpressionSequenceContext* ECMAScriptParser::ForLetInStatementContext::expressionSequence() {
  return getRuleContext<ECMAScriptParser::ExpressionSequenceContext>(0);
}

tree::TerminalNode* ECMAScriptParser::ForLetInStatementContext::CloseParen() {
  return getToken(ECMAScriptParser::CloseParen, 0);
}

ECMAScriptParser::StatementContext* ECMAScriptParser::ForLetInStatementContext::statement() {
  return getRuleContext<ECMAScriptParser::StatementContext>(0);
}

ECMAScriptParser::ForLetInStatementContext::ForLetInStatementContext(IterationStatementContext *ctx) { copyFrom(ctx); }


std::any ECMAScriptParser::ForLetInStatementContext::accept(tree::ParseTreeVisitor *visitor) {
  if (auto parserVisitor = dynamic_cast<ECMAScriptVisitor*>(visitor))
    return parserVisitor->visitForLetInStatement(this);
  else
    return visitor->visitChildren(this);
}
//----------------- ForLetStatementContext ------------------------------------------------------------------

tree::TerminalNode* ECMAScriptParser::ForLetStatementContext::For() {
  return getToken(ECMAScriptParser::For, 0);
}

tree::TerminalNode* ECMAScriptParser::ForLetStatementContext::OpenParen() {
  return getToken(ECMAScriptParser::OpenParen, 0);
}

tree::TerminalNode* ECMAScriptParser::ForLetStatementContext::Let() {
  return getToken(ECMAScriptParser::Let, 0);
}

ECMAScriptParser::VariableDeclarationListContext* ECMAScriptParser::ForLetStatementContext::variableDeclarationList() {
  return getRuleContext<ECMAScriptParser::VariableDeclarationListContext>(0);
}

std::vector<tree::TerminalNode *> ECMAScriptParser::ForLetStatementContext::SemiColon() {
  return getTokens(ECMAScriptParser::SemiColon);
}

tree::TerminalNode* ECMAScriptParser::ForLetStatementContext::SemiColon(size_t i) {
  return getToken(ECMAScriptParser::SemiColon, i);
}

tree::TerminalNode* ECMAScriptParser::ForLetStatementContext::CloseParen() {
  return getToken(ECMAScriptParser::CloseParen, 0);
}

ECMAScriptParser::StatementContext* ECMAScriptParser::ForLetStatementContext::statement() {
  return getRuleContext<ECMAScriptParser::StatementContext>(0);
}

std::vector<ECMAScriptParser::ExpressionSequenceContext *> ECMAScriptParser::ForLetStatementContext::expressionSequence() {
  return getRuleContexts<ECMAScriptParser::ExpressionSequenceContext>();
}

ECMAScriptParser::ExpressionSequenceContext* ECMAScriptParser::ForLetStatementContext::expressionSequence(size_t i) {
  return getRuleContext<ECMAScriptParser::ExpressionSequenceContext>(i);
}

ECMAScriptParser::ForLetStatementContext::ForLetStatementContext(IterationStatementContext *ctx) { copyFrom(ctx); }


std::any ECMAScriptParser::ForLetStatementContext::accept(tree::ParseTreeVisitor *visitor) {
  if (auto parserVisitor = dynamic_cast<ECMAScriptVisitor*>(visitor))
    return parserVisitor->visitForLetStatement(this);
  else
    return visitor->visitChildren(this);
}
//----------------- WhileStatementContext ------------------------------------------------------------------

tree::TerminalNode* ECMAScriptParser::WhileStatementContext::While() {
  return getToken(ECMAScriptParser::While, 0);
}

tree::TerminalNode* ECMAScriptParser::WhileStatementContext::OpenParen() {
  return getToken(ECMAScriptParser::OpenParen, 0);
}

ECMAScriptParser::ExpressionSequenceContext* ECMAScriptParser::WhileStatementContext::expressionSequence() {
  return getRuleContext<ECMAScriptParser::ExpressionSequenceContext>(0);
}

tree::TerminalNode* ECMAScriptParser::WhileStatementContext::CloseParen() {
  return getToken(ECMAScriptParser::CloseParen, 0);
}

ECMAScriptParser::StatementContext* ECMAScriptParser::WhileStatementContext::statement() {
  return getRuleContext<ECMAScriptParser::StatementContext>(0);
}

ECMAScriptParser::WhileStatementContext::WhileStatementContext(IterationStatementContext *ctx) { copyFrom(ctx); }


std::any ECMAScriptParser::WhileStatementContext::accept(tree::ParseTreeVisitor *visitor) {
  if (auto parserVisitor = dynamic_cast<ECMAScriptVisitor*>(visitor))
    return parserVisitor->visitWhileStatement(this);
  else
    return visitor->visitChildren(this);
}
//----------------- ForStatementContext ------------------------------------------------------------------

tree::TerminalNode* ECMAScriptParser::ForStatementContext::For() {
  return getToken(ECMAScriptParser::For, 0);
}

tree::TerminalNode* ECMAScriptParser::ForStatementContext::OpenParen() {
  return getToken(ECMAScriptParser::OpenParen, 0);
}

std::vector<tree::TerminalNode *> ECMAScriptParser::ForStatementContext::SemiColon() {
  return getTokens(ECMAScriptParser::SemiColon);
}

tree::TerminalNode* ECMAScriptParser::ForStatementContext::SemiColon(size_t i) {
  return getToken(ECMAScriptParser::SemiColon, i);
}

tree::TerminalNode* ECMAScriptParser::ForStatementContext::CloseParen() {
  return getToken(ECMAScriptParser::CloseParen, 0);
}

ECMAScriptParser::StatementContext* ECMAScriptParser::ForStatementContext::statement() {
  return getRuleContext<ECMAScriptParser::StatementContext>(0);
}

std::vector<ECMAScriptParser::ExpressionSequenceContext *> ECMAScriptParser::ForStatementContext::expressionSequence() {
  return getRuleContexts<ECMAScriptParser::ExpressionSequenceContext>();
}

ECMAScriptParser::ExpressionSequenceContext* ECMAScriptParser::ForStatementContext::expressionSequence(size_t i) {
  return getRuleContext<ECMAScriptParser::ExpressionSequenceContext>(i);
}

ECMAScriptParser::ForStatementContext::ForStatementContext(IterationStatementContext *ctx) { copyFrom(ctx); }


std::any ECMAScriptParser::ForStatementContext::accept(tree::ParseTreeVisitor *visitor) {
  if (auto parserVisitor = dynamic_cast<ECMAScriptVisitor*>(visitor))
    return parserVisitor->visitForStatement(this);
  else
    return visitor->visitChildren(this);
}
//----------------- ForInStatementContext ------------------------------------------------------------------

tree::TerminalNode* ECMAScriptParser::ForInStatementContext::For() {
  return getToken(ECMAScriptParser::For, 0);
}

tree::TerminalNode* ECMAScriptParser::ForInStatementContext::OpenParen() {
  return getToken(ECMAScriptParser::OpenParen, 0);
}

ECMAScriptParser::SingleExpressionContext* ECMAScriptParser::ForInStatementContext::singleExpression() {
  return getRuleContext<ECMAScriptParser::SingleExpressionContext>(0);
}

tree::TerminalNode* ECMAScriptParser::ForInStatementContext::In() {
  return getToken(ECMAScriptParser::In, 0);
}

ECMAScriptParser::ExpressionSequenceContext* ECMAScriptParser::ForInStatementContext::expressionSequence() {
  return getRuleContext<ECMAScriptParser::ExpressionSequenceContext>(0);
}

tree::TerminalNode* ECMAScriptParser::ForInStatementContext::CloseParen() {
  return getToken(ECMAScriptParser::CloseParen, 0);
}

ECMAScriptParser::StatementContext* ECMAScriptParser::ForInStatementContext::statement() {
  return getRuleContext<ECMAScriptParser::StatementContext>(0);
}

ECMAScriptParser::ForInStatementContext::ForInStatementContext(IterationStatementContext *ctx) { copyFrom(ctx); }


std::any ECMAScriptParser::ForInStatementContext::accept(tree::ParseTreeVisitor *visitor) {
  if (auto parserVisitor = dynamic_cast<ECMAScriptVisitor*>(visitor))
    return parserVisitor->visitForInStatement(this);
  else
    return visitor->visitChildren(this);
}
ECMAScriptParser::IterationStatementContext* ECMAScriptParser::iterationStatement() {
  IterationStatementContext *_localctx = _tracker.createInstance<IterationStatementContext>(_ctx, getState());
  enterRule(_localctx, 26, ECMAScriptParser::RuleIterationStatement);
  size_t _la = 0;

#if __cplusplus > 201703L
  auto onExit = finally([=, this] {
#else
  auto onExit = finally([=] {
#endif
    exitRule();
  });
  try {
    setState(277);
    _errHandler->sync(this);
    switch (getInterpreter<atn::ParserATNSimulator>()->adaptivePredict(_input, 17, _ctx)) {
    case 1: {
      _localctx = _tracker.createInstance<ECMAScriptParser::DoStatementContext>(_localctx);
      enterOuterAlt(_localctx, 1);
      setState(192);
      match(ECMAScriptParser::Do);
      setState(193);
      statement();
      setState(194);
      match(ECMAScriptParser::While);
      setState(195);
      match(ECMAScriptParser::OpenParen);
      setState(196);
      expressionSequence();
      setState(197);
      match(ECMAScriptParser::CloseParen);
      setState(198);
      eos();
      break;
    }

    case 2: {
      _localctx = _tracker.createInstance<ECMAScriptParser::WhileStatementContext>(_localctx);
      enterOuterAlt(_localctx, 2);
      setState(200);
      match(ECMAScriptParser::While);
      setState(201);
      match(ECMAScriptParser::OpenParen);
      setState(202);
      expressionSequence();
      setState(203);
      match(ECMAScriptParser::CloseParen);
      setState(204);
      statement();
      break;
    }

    case 3: {
      _localctx = _tracker.createInstance<ECMAScriptParser::ForStatementContext>(_localctx);
      enterOuterAlt(_localctx, 3);
      setState(206);
      match(ECMAScriptParser::For);
      setState(207);
      match(ECMAScriptParser::OpenParen);
      setState(209);
      _errHandler->sync(this);

      _la = _input->LA(1);
      if ((((_la & ~ 0x3fULL) == 0) &&
        ((1ULL << _la) & 5257952564957118634) != 0) || ((((_la - 68) & ~ 0x3fULL) == 0) &&
        ((1ULL << (_la - 68)) & 3221229761) != 0)) {
        setState(208);
        expressionSequence();
      }
      setState(211);
      match(ECMAScriptParser::SemiColon);
      setState(213);
      _errHandler->sync(this);

      _la = _input->LA(1);
      if ((((_la & ~ 0x3fULL) == 0) &&
        ((1ULL << _la) & 5257952564957118634) != 0) || ((((_la - 68) & ~ 0x3fULL) == 0) &&
        ((1ULL << (_la - 68)) & 3221229761) != 0)) {
        setState(212);
        expressionSequence();
      }
      setState(215);
      match(ECMAScriptParser::SemiColon);
      setState(217);
      _errHandler->sync(this);

      _la = _input->LA(1);
      if ((((_la & ~ 0x3fULL) == 0) &&
        ((1ULL << _la) & 5257952564957118634) != 0) || ((((_la - 68) & ~ 0x3fULL) == 0) &&
        ((1ULL << (_la - 68)) & 3221229761) != 0)) {
        setState(216);
        expressionSequence();
      }
      setState(219);
      match(ECMAScriptParser::CloseParen);
      setState(220);
      statement();
      break;
    }

    case 4: {
      _localctx = _tracker.createInstance<ECMAScriptParser::ForVarStatementContext>(_localctx);
      enterOuterAlt(_localctx, 4);
      setState(221);
      match(ECMAScriptParser::For);
      setState(222);
      match(ECMAScriptParser::OpenParen);
      setState(223);
      match(ECMAScriptParser::Var);
      setState(224);
      variableDeclarationList();
      setState(225);
      match(ECMAScriptParser::SemiColon);
      setState(227);
      _errHandler->sync(this);

      _la = _input->LA(1);
      if ((((_la & ~ 0x3fULL) == 0) &&
        ((1ULL << _la) & 5257952564957118634) != 0) || ((((_la - 68) & ~ 0x3fULL) == 0) &&
        ((1ULL << (_la - 68)) & 3221229761) != 0)) {
        setState(226);
        expressionSequence();
      }
      setState(229);
      match(ECMAScriptParser::SemiColon);
      setState(231);
      _errHandler->sync(this);

      _la = _input->LA(1);
      if ((((_la & ~ 0x3fULL) == 0) &&
        ((1ULL << _la) & 5257952564957118634) != 0) || ((((_la - 68) & ~ 0x3fULL) == 0) &&
        ((1ULL << (_la - 68)) & 3221229761) != 0)) {
        setState(230);
        expressionSequence();
      }
      setState(233);
      match(ECMAScriptParser::CloseParen);
      setState(234);
      statement();
      break;
    }

    case 5: {
      _localctx = _tracker.createInstance<ECMAScriptParser::ForLetStatementContext>(_localctx);
      enterOuterAlt(_localctx, 5);
      setState(236);
      match(ECMAScriptParser::For);
      setState(237);
      match(ECMAScriptParser::OpenParen);
      setState(238);
      match(ECMAScriptParser::Let);
      setState(239);
      variableDeclarationList();
      setState(240);
      match(ECMAScriptParser::SemiColon);
      setState(242);
      _errHandler->sync(this);

      _la = _input->LA(1);
      if ((((_la & ~ 0x3fULL) == 0) &&
        ((1ULL << _la) & 5257952564957118634) != 0) || ((((_la - 68) & ~ 0x3fULL) == 0) &&
        ((1ULL << (_la - 68)) & 3221229761) != 0)) {
        setState(241);
        expressionSequence();
      }
      setState(244);
      match(ECMAScriptParser::SemiColon);
      setState(246);
      _errHandler->sync(this);

      _la = _input->LA(1);
      if ((((_la & ~ 0x3fULL) == 0) &&
        ((1ULL << _la) & 5257952564957118634) != 0) || ((((_la - 68) & ~ 0x3fULL) == 0) &&
        ((1ULL << (_la - 68)) & 3221229761) != 0)) {
        setState(245);
        expressionSequence();
      }
      setState(248);
      match(ECMAScriptParser::CloseParen);
      setState(249);
      statement();
      break;
    }

    case 6: {
      _localctx = _tracker.createInstance<ECMAScriptParser::ForInStatementContext>(_localctx);
      enterOuterAlt(_localctx, 6);
      setState(251);
      match(ECMAScriptParser::For);
      setState(252);
      match(ECMAScriptParser::OpenParen);
      setState(253);
      singleExpression(0);
      setState(254);
      match(ECMAScriptParser::In);
      setState(255);
      expressionSequence();
      setState(256);
      match(ECMAScriptParser::CloseParen);
      setState(257);
      statement();
      break;
    }

    case 7: {
      _localctx = _tracker.createInstance<ECMAScriptParser::ForVarInStatementContext>(_localctx);
      enterOuterAlt(_localctx, 7);
      setState(259);
      match(ECMAScriptParser::For);
      setState(260);
      match(ECMAScriptParser::OpenParen);
      setState(261);
      match(ECMAScriptParser::Var);
      setState(262);
      variableDeclaration();
      setState(263);
      match(ECMAScriptParser::In);
      setState(264);
      expressionSequence();
      setState(265);
      match(ECMAScriptParser::CloseParen);
      setState(266);
      statement();
      break;
    }

    case 8: {
      _localctx = _tracker.createInstance<ECMAScriptParser::ForLetInStatementContext>(_localctx);
      enterOuterAlt(_localctx, 8);
      setState(268);
      match(ECMAScriptParser::For);
      setState(269);
      match(ECMAScriptParser::OpenParen);
      setState(270);
      match(ECMAScriptParser::Let);
      setState(271);
      variableDeclaration();
      setState(272);
      match(ECMAScriptParser::In);
      setState(273);
      expressionSequence();
      setState(274);
      match(ECMAScriptParser::CloseParen);
      setState(275);
      statement();
      break;
    }

    default:
      break;
    }
   
  }
  catch (RecognitionException &e) {
    _errHandler->reportError(this, e);
    _localctx->exception = std::current_exception();
    _errHandler->recover(this, _localctx->exception);
  }

  return _localctx;
}

//----------------- ContinueStatementContext ------------------------------------------------------------------

ECMAScriptParser::ContinueStatementContext::ContinueStatementContext(ParserRuleContext *parent, size_t invokingState)
  : ParserRuleContext(parent, invokingState) {
}

tree::TerminalNode* ECMAScriptParser::ContinueStatementContext::Continue() {
  return getToken(ECMAScriptParser::Continue, 0);
}

ECMAScriptParser::EosContext* ECMAScriptParser::ContinueStatementContext::eos() {
  return getRuleContext<ECMAScriptParser::EosContext>(0);
}

tree::TerminalNode* ECMAScriptParser::ContinueStatementContext::Identifier() {
  return getToken(ECMAScriptParser::Identifier, 0);
}


size_t ECMAScriptParser::ContinueStatementContext::getRuleIndex() const {
  return ECMAScriptParser::RuleContinueStatement;
}


std::any ECMAScriptParser::ContinueStatementContext::accept(tree::ParseTreeVisitor *visitor) {
  if (auto parserVisitor = dynamic_cast<ECMAScriptVisitor*>(visitor))
    return parserVisitor->visitContinueStatement(this);
  else
    return visitor->visitChildren(this);
}

ECMAScriptParser::ContinueStatementContext* ECMAScriptParser::continueStatement() {
  ContinueStatementContext *_localctx = _tracker.createInstance<ContinueStatementContext>(_ctx, getState());
  enterRule(_localctx, 28, ECMAScriptParser::RuleContinueStatement);

#if __cplusplus > 201703L
  auto onExit = finally([=, this] {
#else
  auto onExit = finally([=] {
#endif
    exitRule();
  });
  try {
    enterOuterAlt(_localctx, 1);
    setState(279);
    match(ECMAScriptParser::Continue);
    setState(282);
    _errHandler->sync(this);

    switch (getInterpreter<atn::ParserATNSimulator>()->adaptivePredict(_input, 18, _ctx)) {
    case 1: {
      setState(280);

      if (!(!here(LineTerminator))) throw FailedPredicateException(this, "!here(LineTerminator)");
      setState(281);
      match(ECMAScriptParser::Identifier);
      break;
    }

    default:
      break;
    }
    setState(284);
    eos();
   
  }
  catch (RecognitionException &e) {
    _errHandler->reportError(this, e);
    _localctx->exception = std::current_exception();
    _errHandler->recover(this, _localctx->exception);
  }

  return _localctx;
}

//----------------- BreakStatementContext ------------------------------------------------------------------

ECMAScriptParser::BreakStatementContext::BreakStatementContext(ParserRuleContext *parent, size_t invokingState)
  : ParserRuleContext(parent, invokingState) {
}

tree::TerminalNode* ECMAScriptParser::BreakStatementContext::Break() {
  return getToken(ECMAScriptParser::Break, 0);
}

ECMAScriptParser::EosContext* ECMAScriptParser::BreakStatementContext::eos() {
  return getRuleContext<ECMAScriptParser::EosContext>(0);
}

tree::TerminalNode* ECMAScriptParser::BreakStatementContext::Identifier() {
  return getToken(ECMAScriptParser::Identifier, 0);
}


size_t ECMAScriptParser::BreakStatementContext::getRuleIndex() const {
  return ECMAScriptParser::RuleBreakStatement;
}


std::any ECMAScriptParser::BreakStatementContext::accept(tree::ParseTreeVisitor *visitor) {
  if (auto parserVisitor = dynamic_cast<ECMAScriptVisitor*>(visitor))
    return parserVisitor->visitBreakStatement(this);
  else
    return visitor->visitChildren(this);
}

ECMAScriptParser::BreakStatementContext* ECMAScriptParser::breakStatement() {
  BreakStatementContext *_localctx = _tracker.createInstance<BreakStatementContext>(_ctx, getState());
  enterRule(_localctx, 30, ECMAScriptParser::RuleBreakStatement);

#if __cplusplus > 201703L
  auto onExit = finally([=, this] {
#else
  auto onExit = finally([=] {
#endif
    exitRule();
  });
  try {
    enterOuterAlt(_localctx, 1);
    setState(286);
    match(ECMAScriptParser::Break);
    setState(289);
    _errHandler->sync(this);

    switch (getInterpreter<atn::ParserATNSimulator>()->adaptivePredict(_input, 19, _ctx)) {
    case 1: {
      setState(287);

      if (!(!here(LineTerminator))) throw FailedPredicateException(this, "!here(LineTerminator)");
      setState(288);
      match(ECMAScriptParser::Identifier);
      break;
    }

    default:
      break;
    }
    setState(291);
    eos();
   
  }
  catch (RecognitionException &e) {
    _errHandler->reportError(this, e);
    _localctx->exception = std::current_exception();
    _errHandler->recover(this, _localctx->exception);
  }

  return _localctx;
}

//----------------- ReturnStatementContext ------------------------------------------------------------------

ECMAScriptParser::ReturnStatementContext::ReturnStatementContext(ParserRuleContext *parent, size_t invokingState)
  : ParserRuleContext(parent, invokingState) {
}

tree::TerminalNode* ECMAScriptParser::ReturnStatementContext::Return() {
  return getToken(ECMAScriptParser::Return, 0);
}

ECMAScriptParser::EosContext* ECMAScriptParser::ReturnStatementContext::eos() {
  return getRuleContext<ECMAScriptParser::EosContext>(0);
}

ECMAScriptParser::ExpressionSequenceContext* ECMAScriptParser::ReturnStatementContext::expressionSequence() {
  return getRuleContext<ECMAScriptParser::ExpressionSequenceContext>(0);
}


size_t ECMAScriptParser::ReturnStatementContext::getRuleIndex() const {
  return ECMAScriptParser::RuleReturnStatement;
}


std::any ECMAScriptParser::ReturnStatementContext::accept(tree::ParseTreeVisitor *visitor) {
  if (auto parserVisitor = dynamic_cast<ECMAScriptVisitor*>(visitor))
    return parserVisitor->visitReturnStatement(this);
  else
    return visitor->visitChildren(this);
}

ECMAScriptParser::ReturnStatementContext* ECMAScriptParser::returnStatement() {
  ReturnStatementContext *_localctx = _tracker.createInstance<ReturnStatementContext>(_ctx, getState());
  enterRule(_localctx, 32, ECMAScriptParser::RuleReturnStatement);

#if __cplusplus > 201703L
  auto onExit = finally([=, this] {
#else
  auto onExit = finally([=] {
#endif
    exitRule();
  });
  try {
    enterOuterAlt(_localctx, 1);
    setState(293);
    match(ECMAScriptParser::Return);
    setState(296);
    _errHandler->sync(this);

    switch (getInterpreter<atn::ParserATNSimulator>()->adaptivePredict(_input, 20, _ctx)) {
    case 1: {
      setState(294);

      if (!(!here(LineTerminator))) throw FailedPredicateException(this, "!here(LineTerminator)");
      setState(295);
      expressionSequence();
      break;
    }

    default:
      break;
    }
    setState(298);
    eos();
   
  }
  catch (RecognitionException &e) {
    _errHandler->reportError(this, e);
    _localctx->exception = std::current_exception();
    _errHandler->recover(this, _localctx->exception);
  }

  return _localctx;
}

//----------------- WithStatementContext ------------------------------------------------------------------

ECMAScriptParser::WithStatementContext::WithStatementContext(ParserRuleContext *parent, size_t invokingState)
  : ParserRuleContext(parent, invokingState) {
}

tree::TerminalNode* ECMAScriptParser::WithStatementContext::With() {
  return getToken(ECMAScriptParser::With, 0);
}

tree::TerminalNode* ECMAScriptParser::WithStatementContext::OpenParen() {
  return getToken(ECMAScriptParser::OpenParen, 0);
}

ECMAScriptParser::ExpressionSequenceContext* ECMAScriptParser::WithStatementContext::expressionSequence() {
  return getRuleContext<ECMAScriptParser::ExpressionSequenceContext>(0);
}

tree::TerminalNode* ECMAScriptParser::WithStatementContext::CloseParen() {
  return getToken(ECMAScriptParser::CloseParen, 0);
}

ECMAScriptParser::StatementContext* ECMAScriptParser::WithStatementContext::statement() {
  return getRuleContext<ECMAScriptParser::StatementContext>(0);
}


size_t ECMAScriptParser::WithStatementContext::getRuleIndex() const {
  return ECMAScriptParser::RuleWithStatement;
}


std::any ECMAScriptParser::WithStatementContext::accept(tree::ParseTreeVisitor *visitor) {
  if (auto parserVisitor = dynamic_cast<ECMAScriptVisitor*>(visitor))
    return parserVisitor->visitWithStatement(this);
  else
    return visitor->visitChildren(this);
}

ECMAScriptParser::WithStatementContext* ECMAScriptParser::withStatement() {
  WithStatementContext *_localctx = _tracker.createInstance<WithStatementContext>(_ctx, getState());
  enterRule(_localctx, 34, ECMAScriptParser::RuleWithStatement);

#if __cplusplus > 201703L
  auto onExit = finally([=, this] {
#else
  auto onExit = finally([=] {
#endif
    exitRule();
  });
  try {
    enterOuterAlt(_localctx, 1);
    setState(300);
    match(ECMAScriptParser::With);
    setState(301);
    match(ECMAScriptParser::OpenParen);
    setState(302);
    expressionSequence();
    setState(303);
    match(ECMAScriptParser::CloseParen);
    setState(304);
    statement();
   
  }
  catch (RecognitionException &e) {
    _errHandler->reportError(this, e);
    _localctx->exception = std::current_exception();
    _errHandler->recover(this, _localctx->exception);
  }

  return _localctx;
}

//----------------- SwitchStatementContext ------------------------------------------------------------------

ECMAScriptParser::SwitchStatementContext::SwitchStatementContext(ParserRuleContext *parent, size_t invokingState)
  : ParserRuleContext(parent, invokingState) {
}

tree::TerminalNode* ECMAScriptParser::SwitchStatementContext::Switch() {
  return getToken(ECMAScriptParser::Switch, 0);
}

tree::TerminalNode* ECMAScriptParser::SwitchStatementContext::OpenParen() {
  return getToken(ECMAScriptParser::OpenParen, 0);
}

ECMAScriptParser::ExpressionSequenceContext* ECMAScriptParser::SwitchStatementContext::expressionSequence() {
  return getRuleContext<ECMAScriptParser::ExpressionSequenceContext>(0);
}

tree::TerminalNode* ECMAScriptParser::SwitchStatementContext::CloseParen() {
  return getToken(ECMAScriptParser::CloseParen, 0);
}

ECMAScriptParser::CaseBlockContext* ECMAScriptParser::SwitchStatementContext::caseBlock() {
  return getRuleContext<ECMAScriptParser::CaseBlockContext>(0);
}


size_t ECMAScriptParser::SwitchStatementContext::getRuleIndex() const {
  return ECMAScriptParser::RuleSwitchStatement;
}


std::any ECMAScriptParser::SwitchStatementContext::accept(tree::ParseTreeVisitor *visitor) {
  if (auto parserVisitor = dynamic_cast<ECMAScriptVisitor*>(visitor))
    return parserVisitor->visitSwitchStatement(this);
  else
    return visitor->visitChildren(this);
}

ECMAScriptParser::SwitchStatementContext* ECMAScriptParser::switchStatement() {
  SwitchStatementContext *_localctx = _tracker.createInstance<SwitchStatementContext>(_ctx, getState());
  enterRule(_localctx, 36, ECMAScriptParser::RuleSwitchStatement);

#if __cplusplus > 201703L
  auto onExit = finally([=, this] {
#else
  auto onExit = finally([=] {
#endif
    exitRule();
  });
  try {
    enterOuterAlt(_localctx, 1);
    setState(306);
    match(ECMAScriptParser::Switch);
    setState(307);
    match(ECMAScriptParser::OpenParen);
    setState(308);
    expressionSequence();
    setState(309);
    match(ECMAScriptParser::CloseParen);
    setState(310);
    caseBlock();
   
  }
  catch (RecognitionException &e) {
    _errHandler->reportError(this, e);
    _localctx->exception = std::current_exception();
    _errHandler->recover(this, _localctx->exception);
  }

  return _localctx;
}

//----------------- CaseBlockContext ------------------------------------------------------------------

ECMAScriptParser::CaseBlockContext::CaseBlockContext(ParserRuleContext *parent, size_t invokingState)
  : ParserRuleContext(parent, invokingState) {
}

tree::TerminalNode* ECMAScriptParser::CaseBlockContext::OpenBrace() {
  return getToken(ECMAScriptParser::OpenBrace, 0);
}

tree::TerminalNode* ECMAScriptParser::CaseBlockContext::CloseBrace() {
  return getToken(ECMAScriptParser::CloseBrace, 0);
}

std::vector<ECMAScriptParser::CaseClausesContext *> ECMAScriptParser::CaseBlockContext::caseClauses() {
  return getRuleContexts<ECMAScriptParser::CaseClausesContext>();
}

ECMAScriptParser::CaseClausesContext* ECMAScriptParser::CaseBlockContext::caseClauses(size_t i) {
  return getRuleContext<ECMAScriptParser::CaseClausesContext>(i);
}

ECMAScriptParser::DefaultClauseContext* ECMAScriptParser::CaseBlockContext::defaultClause() {
  return getRuleContext<ECMAScriptParser::DefaultClauseContext>(0);
}


size_t ECMAScriptParser::CaseBlockContext::getRuleIndex() const {
  return ECMAScriptParser::RuleCaseBlock;
}


std::any ECMAScriptParser::CaseBlockContext::accept(tree::ParseTreeVisitor *visitor) {
  if (auto parserVisitor = dynamic_cast<ECMAScriptVisitor*>(visitor))
    return parserVisitor->visitCaseBlock(this);
  else
    return visitor->visitChildren(this);
}

ECMAScriptParser::CaseBlockContext* ECMAScriptParser::caseBlock() {
  CaseBlockContext *_localctx = _tracker.createInstance<CaseBlockContext>(_ctx, getState());
  enterRule(_localctx, 38, ECMAScriptParser::RuleCaseBlock);
  size_t _la = 0;

#if __cplusplus > 201703L
  auto onExit = finally([=, this] {
#else
  auto onExit = finally([=] {
#endif
    exitRule();
  });
  try {
    enterOuterAlt(_localctx, 1);
    setState(312);
    match(ECMAScriptParser::OpenBrace);
    setState(314);
    _errHandler->sync(this);

    _la = _input->LA(1);
    if (_la == ECMAScriptParser::Case) {
      setState(313);
      caseClauses();
    }
    setState(320);
    _errHandler->sync(this);

    _la = _input->LA(1);
    if (_la == ECMAScriptParser::Default) {
      setState(316);
      defaultClause();
      setState(318);
      _errHandler->sync(this);

      _la = _input->LA(1);
      if (_la == ECMAScriptParser::Case) {
        setState(317);
        caseClauses();
      }
    }
    setState(322);
    match(ECMAScriptParser::CloseBrace);
   
  }
  catch (RecognitionException &e) {
    _errHandler->reportError(this, e);
    _localctx->exception = std::current_exception();
    _errHandler->recover(this, _localctx->exception);
  }

  return _localctx;
}

//----------------- CaseClausesContext ------------------------------------------------------------------

ECMAScriptParser::CaseClausesContext::CaseClausesContext(ParserRuleContext *parent, size_t invokingState)
  : ParserRuleContext(parent, invokingState) {
}

std::vector<ECMAScriptParser::CaseClauseContext *> ECMAScriptParser::CaseClausesContext::caseClause() {
  return getRuleContexts<ECMAScriptParser::CaseClauseContext>();
}

ECMAScriptParser::CaseClauseContext* ECMAScriptParser::CaseClausesContext::caseClause(size_t i) {
  return getRuleContext<ECMAScriptParser::CaseClauseContext>(i);
}


size_t ECMAScriptParser::CaseClausesContext::getRuleIndex() const {
  return ECMAScriptParser::RuleCaseClauses;
}


std::any ECMAScriptParser::CaseClausesContext::accept(tree::ParseTreeVisitor *visitor) {
  if (auto parserVisitor = dynamic_cast<ECMAScriptVisitor*>(visitor))
    return parserVisitor->visitCaseClauses(this);
  else
    return visitor->visitChildren(this);
}

ECMAScriptParser::CaseClausesContext* ECMAScriptParser::caseClauses() {
  CaseClausesContext *_localctx = _tracker.createInstance<CaseClausesContext>(_ctx, getState());
  enterRule(_localctx, 40, ECMAScriptParser::RuleCaseClauses);
  size_t _la = 0;

#if __cplusplus > 201703L
  auto onExit = finally([=, this] {
#else
  auto onExit = finally([=] {
#endif
    exitRule();
  });
  try {
    enterOuterAlt(_localctx, 1);
    setState(325); 
    _errHandler->sync(this);
    _la = _input->LA(1);
    do {
      setState(324);
      caseClause();
      setState(327); 
      _errHandler->sync(this);
      _la = _input->LA(1);
    } while (_la == ECMAScriptParser::Case);
   
  }
  catch (RecognitionException &e) {
    _errHandler->reportError(this, e);
    _localctx->exception = std::current_exception();
    _errHandler->recover(this, _localctx->exception);
  }

  return _localctx;
}

//----------------- CaseClauseContext ------------------------------------------------------------------

ECMAScriptParser::CaseClauseContext::CaseClauseContext(ParserRuleContext *parent, size_t invokingState)
  : ParserRuleContext(parent, invokingState) {
}

tree::TerminalNode* ECMAScriptParser::CaseClauseContext::Case() {
  return getToken(ECMAScriptParser::Case, 0);
}

ECMAScriptParser::ExpressionSequenceContext* ECMAScriptParser::CaseClauseContext::expressionSequence() {
  return getRuleContext<ECMAScriptParser::ExpressionSequenceContext>(0);
}

tree::TerminalNode* ECMAScriptParser::CaseClauseContext::Colon() {
  return getToken(ECMAScriptParser::Colon, 0);
}

ECMAScriptParser::StatementListContext* ECMAScriptParser::CaseClauseContext::statementList() {
  return getRuleContext<ECMAScriptParser::StatementListContext>(0);
}


size_t ECMAScriptParser::CaseClauseContext::getRuleIndex() const {
  return ECMAScriptParser::RuleCaseClause;
}


std::any ECMAScriptParser::CaseClauseContext::accept(tree::ParseTreeVisitor *visitor) {
  if (auto parserVisitor = dynamic_cast<ECMAScriptVisitor*>(visitor))
    return parserVisitor->visitCaseClause(this);
  else
    return visitor->visitChildren(this);
}

ECMAScriptParser::CaseClauseContext* ECMAScriptParser::caseClause() {
  CaseClauseContext *_localctx = _tracker.createInstance<CaseClauseContext>(_ctx, getState());
  enterRule(_localctx, 42, ECMAScriptParser::RuleCaseClause);

#if __cplusplus > 201703L
  auto onExit = finally([=, this] {
#else
  auto onExit = finally([=] {
#endif
    exitRule();
  });
  try {
    enterOuterAlt(_localctx, 1);
    setState(329);
    match(ECMAScriptParser::Case);
    setState(330);
    expressionSequence();
    setState(331);
    match(ECMAScriptParser::Colon);
    setState(333);
    _errHandler->sync(this);

    switch (getInterpreter<atn::ParserATNSimulator>()->adaptivePredict(_input, 25, _ctx)) {
    case 1: {
      setState(332);
      statementList();
      break;
    }

    default:
      break;
    }
   
  }
  catch (RecognitionException &e) {
    _errHandler->reportError(this, e);
    _localctx->exception = std::current_exception();
    _errHandler->recover(this, _localctx->exception);
  }

  return _localctx;
}

//----------------- DefaultClauseContext ------------------------------------------------------------------

ECMAScriptParser::DefaultClauseContext::DefaultClauseContext(ParserRuleContext *parent, size_t invokingState)
  : ParserRuleContext(parent, invokingState) {
}

tree::TerminalNode* ECMAScriptParser::DefaultClauseContext::Default() {
  return getToken(ECMAScriptParser::Default, 0);
}

tree::TerminalNode* ECMAScriptParser::DefaultClauseContext::Colon() {
  return getToken(ECMAScriptParser::Colon, 0);
}

ECMAScriptParser::StatementListContext* ECMAScriptParser::DefaultClauseContext::statementList() {
  return getRuleContext<ECMAScriptParser::StatementListContext>(0);
}


size_t ECMAScriptParser::DefaultClauseContext::getRuleIndex() const {
  return ECMAScriptParser::RuleDefaultClause;
}


std::any ECMAScriptParser::DefaultClauseContext::accept(tree::ParseTreeVisitor *visitor) {
  if (auto parserVisitor = dynamic_cast<ECMAScriptVisitor*>(visitor))
    return parserVisitor->visitDefaultClause(this);
  else
    return visitor->visitChildren(this);
}

ECMAScriptParser::DefaultClauseContext* ECMAScriptParser::defaultClause() {
  DefaultClauseContext *_localctx = _tracker.createInstance<DefaultClauseContext>(_ctx, getState());
  enterRule(_localctx, 44, ECMAScriptParser::RuleDefaultClause);

#if __cplusplus > 201703L
  auto onExit = finally([=, this] {
#else
  auto onExit = finally([=] {
#endif
    exitRule();
  });
  try {
    enterOuterAlt(_localctx, 1);
    setState(335);
    match(ECMAScriptParser::Default);
    setState(336);
    match(ECMAScriptParser::Colon);
    setState(338);
    _errHandler->sync(this);

    switch (getInterpreter<atn::ParserATNSimulator>()->adaptivePredict(_input, 26, _ctx)) {
    case 1: {
      setState(337);
      statementList();
      break;
    }

    default:
      break;
    }
   
  }
  catch (RecognitionException &e) {
    _errHandler->reportError(this, e);
    _localctx->exception = std::current_exception();
    _errHandler->recover(this, _localctx->exception);
  }

  return _localctx;
}

//----------------- LabelledStatementContext ------------------------------------------------------------------

ECMAScriptParser::LabelledStatementContext::LabelledStatementContext(ParserRuleContext *parent, size_t invokingState)
  : ParserRuleContext(parent, invokingState) {
}

tree::TerminalNode* ECMAScriptParser::LabelledStatementContext::Identifier() {
  return getToken(ECMAScriptParser::Identifier, 0);
}

tree::TerminalNode* ECMAScriptParser::LabelledStatementContext::Colon() {
  return getToken(ECMAScriptParser::Colon, 0);
}

ECMAScriptParser::StatementContext* ECMAScriptParser::LabelledStatementContext::statement() {
  return getRuleContext<ECMAScriptParser::StatementContext>(0);
}


size_t ECMAScriptParser::LabelledStatementContext::getRuleIndex() const {
  return ECMAScriptParser::RuleLabelledStatement;
}


std::any ECMAScriptParser::LabelledStatementContext::accept(tree::ParseTreeVisitor *visitor) {
  if (auto parserVisitor = dynamic_cast<ECMAScriptVisitor*>(visitor))
    return parserVisitor->visitLabelledStatement(this);
  else
    return visitor->visitChildren(this);
}

ECMAScriptParser::LabelledStatementContext* ECMAScriptParser::labelledStatement() {
  LabelledStatementContext *_localctx = _tracker.createInstance<LabelledStatementContext>(_ctx, getState());
  enterRule(_localctx, 46, ECMAScriptParser::RuleLabelledStatement);

#if __cplusplus > 201703L
  auto onExit = finally([=, this] {
#else
  auto onExit = finally([=] {
#endif
    exitRule();
  });
  try {
    enterOuterAlt(_localctx, 1);
    setState(340);
    match(ECMAScriptParser::Identifier);
    setState(341);
    match(ECMAScriptParser::Colon);
    setState(342);
    statement();
   
  }
  catch (RecognitionException &e) {
    _errHandler->reportError(this, e);
    _localctx->exception = std::current_exception();
    _errHandler->recover(this, _localctx->exception);
  }

  return _localctx;
}

//----------------- ThrowStatementContext ------------------------------------------------------------------

ECMAScriptParser::ThrowStatementContext::ThrowStatementContext(ParserRuleContext *parent, size_t invokingState)
  : ParserRuleContext(parent, invokingState) {
}

tree::TerminalNode* ECMAScriptParser::ThrowStatementContext::Throw() {
  return getToken(ECMAScriptParser::Throw, 0);
}

ECMAScriptParser::ExpressionSequenceContext* ECMAScriptParser::ThrowStatementContext::expressionSequence() {
  return getRuleContext<ECMAScriptParser::ExpressionSequenceContext>(0);
}

ECMAScriptParser::EosContext* ECMAScriptParser::ThrowStatementContext::eos() {
  return getRuleContext<ECMAScriptParser::EosContext>(0);
}


size_t ECMAScriptParser::ThrowStatementContext::getRuleIndex() const {
  return ECMAScriptParser::RuleThrowStatement;
}


std::any ECMAScriptParser::ThrowStatementContext::accept(tree::ParseTreeVisitor *visitor) {
  if (auto parserVisitor = dynamic_cast<ECMAScriptVisitor*>(visitor))
    return parserVisitor->visitThrowStatement(this);
  else
    return visitor->visitChildren(this);
}

ECMAScriptParser::ThrowStatementContext* ECMAScriptParser::throwStatement() {
  ThrowStatementContext *_localctx = _tracker.createInstance<ThrowStatementContext>(_ctx, getState());
  enterRule(_localctx, 48, ECMAScriptParser::RuleThrowStatement);

#if __cplusplus > 201703L
  auto onExit = finally([=, this] {
#else
  auto onExit = finally([=] {
#endif
    exitRule();
  });
  try {
    enterOuterAlt(_localctx, 1);
    setState(344);
    match(ECMAScriptParser::Throw);
    setState(345);

    if (!(!here(LineTerminator))) throw FailedPredicateException(this, "!here(LineTerminator)");
    setState(346);
    expressionSequence();
    setState(347);
    eos();
   
  }
  catch (RecognitionException &e) {
    _errHandler->reportError(this, e);
    _localctx->exception = std::current_exception();
    _errHandler->recover(this, _localctx->exception);
  }

  return _localctx;
}

//----------------- TryStatementContext ------------------------------------------------------------------

ECMAScriptParser::TryStatementContext::TryStatementContext(ParserRuleContext *parent, size_t invokingState)
  : ParserRuleContext(parent, invokingState) {
}

tree::TerminalNode* ECMAScriptParser::TryStatementContext::Try() {
  return getToken(ECMAScriptParser::Try, 0);
}

ECMAScriptParser::BlockContext* ECMAScriptParser::TryStatementContext::block() {
  return getRuleContext<ECMAScriptParser::BlockContext>(0);
}

ECMAScriptParser::CatchProductionContext* ECMAScriptParser::TryStatementContext::catchProduction() {
  return getRuleContext<ECMAScriptParser::CatchProductionContext>(0);
}

ECMAScriptParser::FinallyProductionContext* ECMAScriptParser::TryStatementContext::finallyProduction() {
  return getRuleContext<ECMAScriptParser::FinallyProductionContext>(0);
}


size_t ECMAScriptParser::TryStatementContext::getRuleIndex() const {
  return ECMAScriptParser::RuleTryStatement;
}


std::any ECMAScriptParser::TryStatementContext::accept(tree::ParseTreeVisitor *visitor) {
  if (auto parserVisitor = dynamic_cast<ECMAScriptVisitor*>(visitor))
    return parserVisitor->visitTryStatement(this);
  else
    return visitor->visitChildren(this);
}

ECMAScriptParser::TryStatementContext* ECMAScriptParser::tryStatement() {
  TryStatementContext *_localctx = _tracker.createInstance<TryStatementContext>(_ctx, getState());
  enterRule(_localctx, 50, ECMAScriptParser::RuleTryStatement);

#if __cplusplus > 201703L
  auto onExit = finally([=, this] {
#else
  auto onExit = finally([=] {
#endif
    exitRule();
  });
  try {
    setState(362);
    _errHandler->sync(this);
    switch (getInterpreter<atn::ParserATNSimulator>()->adaptivePredict(_input, 27, _ctx)) {
    case 1: {
      enterOuterAlt(_localctx, 1);
      setState(349);
      match(ECMAScriptParser::Try);
      setState(350);
      block();
      setState(351);
      catchProduction();
      break;
    }

    case 2: {
      enterOuterAlt(_localctx, 2);
      setState(353);
      match(ECMAScriptParser::Try);
      setState(354);
      block();
      setState(355);
      finallyProduction();
      break;
    }

    case 3: {
      enterOuterAlt(_localctx, 3);
      setState(357);
      match(ECMAScriptParser::Try);
      setState(358);
      block();
      setState(359);
      catchProduction();
      setState(360);
      finallyProduction();
      break;
    }

    default:
      break;
    }
   
  }
  catch (RecognitionException &e) {
    _errHandler->reportError(this, e);
    _localctx->exception = std::current_exception();
    _errHandler->recover(this, _localctx->exception);
  }

  return _localctx;
}

//----------------- CatchProductionContext ------------------------------------------------------------------

ECMAScriptParser::CatchProductionContext::CatchProductionContext(ParserRuleContext *parent, size_t invokingState)
  : ParserRuleContext(parent, invokingState) {
}

tree::TerminalNode* ECMAScriptParser::CatchProductionContext::Catch() {
  return getToken(ECMAScriptParser::Catch, 0);
}

tree::TerminalNode* ECMAScriptParser::CatchProductionContext::OpenParen() {
  return getToken(ECMAScriptParser::OpenParen, 0);
}

tree::TerminalNode* ECMAScriptParser::CatchProductionContext::Identifier() {
  return getToken(ECMAScriptParser::Identifier, 0);
}

tree::TerminalNode* ECMAScriptParser::CatchProductionContext::CloseParen() {
  return getToken(ECMAScriptParser::CloseParen, 0);
}

ECMAScriptParser::BlockContext* ECMAScriptParser::CatchProductionContext::block() {
  return getRuleContext<ECMAScriptParser::BlockContext>(0);
}


size_t ECMAScriptParser::CatchProductionContext::getRuleIndex() const {
  return ECMAScriptParser::RuleCatchProduction;
}


std::any ECMAScriptParser::CatchProductionContext::accept(tree::ParseTreeVisitor *visitor) {
  if (auto parserVisitor = dynamic_cast<ECMAScriptVisitor*>(visitor))
    return parserVisitor->visitCatchProduction(this);
  else
    return visitor->visitChildren(this);
}

ECMAScriptParser::CatchProductionContext* ECMAScriptParser::catchProduction() {
  CatchProductionContext *_localctx = _tracker.createInstance<CatchProductionContext>(_ctx, getState());
  enterRule(_localctx, 52, ECMAScriptParser::RuleCatchProduction);

#if __cplusplus > 201703L
  auto onExit = finally([=, this] {
#else
  auto onExit = finally([=] {
#endif
    exitRule();
  });
  try {
    enterOuterAlt(_localctx, 1);
    setState(364);
    match(ECMAScriptParser::Catch);
    setState(365);
    match(ECMAScriptParser::OpenParen);
    setState(366);
    match(ECMAScriptParser::Identifier);
    setState(367);
    match(ECMAScriptParser::CloseParen);
    setState(368);
    block();
   
  }
  catch (RecognitionException &e) {
    _errHandler->reportError(this, e);
    _localctx->exception = std::current_exception();
    _errHandler->recover(this, _localctx->exception);
  }

  return _localctx;
}

//----------------- FinallyProductionContext ------------------------------------------------------------------

ECMAScriptParser::FinallyProductionContext::FinallyProductionContext(ParserRuleContext *parent, size_t invokingState)
  : ParserRuleContext(parent, invokingState) {
}

tree::TerminalNode* ECMAScriptParser::FinallyProductionContext::Finally() {
  return getToken(ECMAScriptParser::Finally, 0);
}

ECMAScriptParser::BlockContext* ECMAScriptParser::FinallyProductionContext::block() {
  return getRuleContext<ECMAScriptParser::BlockContext>(0);
}


size_t ECMAScriptParser::FinallyProductionContext::getRuleIndex() const {
  return ECMAScriptParser::RuleFinallyProduction;
}


std::any ECMAScriptParser::FinallyProductionContext::accept(tree::ParseTreeVisitor *visitor) {
  if (auto parserVisitor = dynamic_cast<ECMAScriptVisitor*>(visitor))
    return parserVisitor->visitFinallyProduction(this);
  else
    return visitor->visitChildren(this);
}

ECMAScriptParser::FinallyProductionContext* ECMAScriptParser::finallyProduction() {
  FinallyProductionContext *_localctx = _tracker.createInstance<FinallyProductionContext>(_ctx, getState());
  enterRule(_localctx, 54, ECMAScriptParser::RuleFinallyProduction);

#if __cplusplus > 201703L
  auto onExit = finally([=, this] {
#else
  auto onExit = finally([=] {
#endif
    exitRule();
  });
  try {
    enterOuterAlt(_localctx, 1);
    setState(370);
    match(ECMAScriptParser::Finally);
    setState(371);
    block();
   
  }
  catch (RecognitionException &e) {
    _errHandler->reportError(this, e);
    _localctx->exception = std::current_exception();
    _errHandler->recover(this, _localctx->exception);
  }

  return _localctx;
}

//----------------- DebuggerStatementContext ------------------------------------------------------------------

ECMAScriptParser::DebuggerStatementContext::DebuggerStatementContext(ParserRuleContext *parent, size_t invokingState)
  : ParserRuleContext(parent, invokingState) {
}

tree::TerminalNode* ECMAScriptParser::DebuggerStatementContext::Debugger() {
  return getToken(ECMAScriptParser::Debugger, 0);
}

ECMAScriptParser::EosContext* ECMAScriptParser::DebuggerStatementContext::eos() {
  return getRuleContext<ECMAScriptParser::EosContext>(0);
}


size_t ECMAScriptParser::DebuggerStatementContext::getRuleIndex() const {
  return ECMAScriptParser::RuleDebuggerStatement;
}


std::any ECMAScriptParser::DebuggerStatementContext::accept(tree::ParseTreeVisitor *visitor) {
  if (auto parserVisitor = dynamic_cast<ECMAScriptVisitor*>(visitor))
    return parserVisitor->visitDebuggerStatement(this);
  else
    return visitor->visitChildren(this);
}

ECMAScriptParser::DebuggerStatementContext* ECMAScriptParser::debuggerStatement() {
  DebuggerStatementContext *_localctx = _tracker.createInstance<DebuggerStatementContext>(_ctx, getState());
  enterRule(_localctx, 56, ECMAScriptParser::RuleDebuggerStatement);

#if __cplusplus > 201703L
  auto onExit = finally([=, this] {
#else
  auto onExit = finally([=] {
#endif
    exitRule();
  });
  try {
    enterOuterAlt(_localctx, 1);
    setState(373);
    match(ECMAScriptParser::Debugger);
    setState(374);
    eos();
   
  }
  catch (RecognitionException &e) {
    _errHandler->reportError(this, e);
    _localctx->exception = std::current_exception();
    _errHandler->recover(this, _localctx->exception);
  }

  return _localctx;
}

//----------------- FunctionDeclarationContext ------------------------------------------------------------------

ECMAScriptParser::FunctionDeclarationContext::FunctionDeclarationContext(ParserRuleContext *parent, size_t invokingState)
  : ParserRuleContext(parent, invokingState) {
}

tree::TerminalNode* ECMAScriptParser::FunctionDeclarationContext::Function() {
  return getToken(ECMAScriptParser::Function, 0);
}

tree::TerminalNode* ECMAScriptParser::FunctionDeclarationContext::Identifier() {
  return getToken(ECMAScriptParser::Identifier, 0);
}

tree::TerminalNode* ECMAScriptParser::FunctionDeclarationContext::OpenParen() {
  return getToken(ECMAScriptParser::OpenParen, 0);
}

tree::TerminalNode* ECMAScriptParser::FunctionDeclarationContext::CloseParen() {
  return getToken(ECMAScriptParser::CloseParen, 0);
}

tree::TerminalNode* ECMAScriptParser::FunctionDeclarationContext::OpenBrace() {
  return getToken(ECMAScriptParser::OpenBrace, 0);
}

ECMAScriptParser::FunctionBodyContext* ECMAScriptParser::FunctionDeclarationContext::functionBody() {
  return getRuleContext<ECMAScriptParser::FunctionBodyContext>(0);
}

tree::TerminalNode* ECMAScriptParser::FunctionDeclarationContext::CloseBrace() {
  return getToken(ECMAScriptParser::CloseBrace, 0);
}

ECMAScriptParser::FormalParameterListContext* ECMAScriptParser::FunctionDeclarationContext::formalParameterList() {
  return getRuleContext<ECMAScriptParser::FormalParameterListContext>(0);
}


size_t ECMAScriptParser::FunctionDeclarationContext::getRuleIndex() const {
  return ECMAScriptParser::RuleFunctionDeclaration;
}


std::any ECMAScriptParser::FunctionDeclarationContext::accept(tree::ParseTreeVisitor *visitor) {
  if (auto parserVisitor = dynamic_cast<ECMAScriptVisitor*>(visitor))
    return parserVisitor->visitFunctionDeclaration(this);
  else
    return visitor->visitChildren(this);
}

ECMAScriptParser::FunctionDeclarationContext* ECMAScriptParser::functionDeclaration() {
  FunctionDeclarationContext *_localctx = _tracker.createInstance<FunctionDeclarationContext>(_ctx, getState());
  enterRule(_localctx, 58, ECMAScriptParser::RuleFunctionDeclaration);
  size_t _la = 0;

#if __cplusplus > 201703L
  auto onExit = finally([=, this] {
#else
  auto onExit = finally([=] {
#endif
    exitRule();
  });
  try {
    enterOuterAlt(_localctx, 1);
    setState(376);
    match(ECMAScriptParser::Function);
    setState(377);
    match(ECMAScriptParser::Identifier);
    setState(378);
    match(ECMAScriptParser::OpenParen);
    setState(380);
    _errHandler->sync(this);

    _la = _input->LA(1);
    if (_la == ECMAScriptParser::Identifier) {
      setState(379);
      formalParameterList();
    }
    setState(382);
    match(ECMAScriptParser::CloseParen);
    setState(383);
    match(ECMAScriptParser::OpenBrace);
    setState(384);
    functionBody();
    setState(385);
    match(ECMAScriptParser::CloseBrace);
   
  }
  catch (RecognitionException &e) {
    _errHandler->reportError(this, e);
    _localctx->exception = std::current_exception();
    _errHandler->recover(this, _localctx->exception);
  }

  return _localctx;
}

//----------------- FormalParameterListContext ------------------------------------------------------------------

ECMAScriptParser::FormalParameterListContext::FormalParameterListContext(ParserRuleContext *parent, size_t invokingState)
  : ParserRuleContext(parent, invokingState) {
}

std::vector<tree::TerminalNode *> ECMAScriptParser::FormalParameterListContext::Identifier() {
  return getTokens(ECMAScriptParser::Identifier);
}

tree::TerminalNode* ECMAScriptParser::FormalParameterListContext::Identifier(size_t i) {
  return getToken(ECMAScriptParser::Identifier, i);
}

std::vector<tree::TerminalNode *> ECMAScriptParser::FormalParameterListContext::Comma() {
  return getTokens(ECMAScriptParser::Comma);
}

tree::TerminalNode* ECMAScriptParser::FormalParameterListContext::Comma(size_t i) {
  return getToken(ECMAScriptParser::Comma, i);
}


size_t ECMAScriptParser::FormalParameterListContext::getRuleIndex() const {
  return ECMAScriptParser::RuleFormalParameterList;
}


std::any ECMAScriptParser::FormalParameterListContext::accept(tree::ParseTreeVisitor *visitor) {
  if (auto parserVisitor = dynamic_cast<ECMAScriptVisitor*>(visitor))
    return parserVisitor->visitFormalParameterList(this);
  else
    return visitor->visitChildren(this);
}

ECMAScriptParser::FormalParameterListContext* ECMAScriptParser::formalParameterList() {
  FormalParameterListContext *_localctx = _tracker.createInstance<FormalParameterListContext>(_ctx, getState());
  enterRule(_localctx, 60, ECMAScriptParser::RuleFormalParameterList);
  size_t _la = 0;

#if __cplusplus > 201703L
  auto onExit = finally([=, this] {
#else
  auto onExit = finally([=] {
#endif
    exitRule();
  });
  try {
    enterOuterAlt(_localctx, 1);
    setState(387);
    match(ECMAScriptParser::Identifier);
    setState(392);
    _errHandler->sync(this);
    _la = _input->LA(1);
    while (_la == ECMAScriptParser::Comma) {
      setState(388);
      match(ECMAScriptParser::Comma);
      setState(389);
      match(ECMAScriptParser::Identifier);
      setState(394);
      _errHandler->sync(this);
      _la = _input->LA(1);
    }
   
  }
  catch (RecognitionException &e) {
    _errHandler->reportError(this, e);
    _localctx->exception = std::current_exception();
    _errHandler->recover(this, _localctx->exception);
  }

  return _localctx;
}

//----------------- FunctionBodyContext ------------------------------------------------------------------

ECMAScriptParser::FunctionBodyContext::FunctionBodyContext(ParserRuleContext *parent, size_t invokingState)
  : ParserRuleContext(parent, invokingState) {
}

ECMAScriptParser::SourceElementsContext* ECMAScriptParser::FunctionBodyContext::sourceElements() {
  return getRuleContext<ECMAScriptParser::SourceElementsContext>(0);
}


size_t ECMAScriptParser::FunctionBodyContext::getRuleIndex() const {
  return ECMAScriptParser::RuleFunctionBody;
}


std::any ECMAScriptParser::FunctionBodyContext::accept(tree::ParseTreeVisitor *visitor) {
  if (auto parserVisitor = dynamic_cast<ECMAScriptVisitor*>(visitor))
    return parserVisitor->visitFunctionBody(this);
  else
    return visitor->visitChildren(this);
}

ECMAScriptParser::FunctionBodyContext* ECMAScriptParser::functionBody() {
  FunctionBodyContext *_localctx = _tracker.createInstance<FunctionBodyContext>(_ctx, getState());
  enterRule(_localctx, 62, ECMAScriptParser::RuleFunctionBody);

#if __cplusplus > 201703L
  auto onExit = finally([=, this] {
#else
  auto onExit = finally([=] {
#endif
    exitRule();
  });
  try {
    enterOuterAlt(_localctx, 1);
    setState(396);
    _errHandler->sync(this);

    switch (getInterpreter<atn::ParserATNSimulator>()->adaptivePredict(_input, 30, _ctx)) {
    case 1: {
      setState(395);
      sourceElements();
      break;
    }

    default:
      break;
    }
   
  }
  catch (RecognitionException &e) {
    _errHandler->reportError(this, e);
    _localctx->exception = std::current_exception();
    _errHandler->recover(this, _localctx->exception);
  }

  return _localctx;
}

//----------------- ArrayLiteralContext ------------------------------------------------------------------

ECMAScriptParser::ArrayLiteralContext::ArrayLiteralContext(ParserRuleContext *parent, size_t invokingState)
  : ParserRuleContext(parent, invokingState) {
}

tree::TerminalNode* ECMAScriptParser::ArrayLiteralContext::OpenBracket() {
  return getToken(ECMAScriptParser::OpenBracket, 0);
}

tree::TerminalNode* ECMAScriptParser::ArrayLiteralContext::CloseBracket() {
  return getToken(ECMAScriptParser::CloseBracket, 0);
}

ECMAScriptParser::ElementListContext* ECMAScriptParser::ArrayLiteralContext::elementList() {
  return getRuleContext<ECMAScriptParser::ElementListContext>(0);
}

tree::TerminalNode* ECMAScriptParser::ArrayLiteralContext::Comma() {
  return getToken(ECMAScriptParser::Comma, 0);
}

ECMAScriptParser::ElisionContext* ECMAScriptParser::ArrayLiteralContext::elision() {
  return getRuleContext<ECMAScriptParser::ElisionContext>(0);
}


size_t ECMAScriptParser::ArrayLiteralContext::getRuleIndex() const {
  return ECMAScriptParser::RuleArrayLiteral;
}


std::any ECMAScriptParser::ArrayLiteralContext::accept(tree::ParseTreeVisitor *visitor) {
  if (auto parserVisitor = dynamic_cast<ECMAScriptVisitor*>(visitor))
    return parserVisitor->visitArrayLiteral(this);
  else
    return visitor->visitChildren(this);
}

ECMAScriptParser::ArrayLiteralContext* ECMAScriptParser::arrayLiteral() {
  ArrayLiteralContext *_localctx = _tracker.createInstance<ArrayLiteralContext>(_ctx, getState());
  enterRule(_localctx, 64, ECMAScriptParser::RuleArrayLiteral);
  size_t _la = 0;

#if __cplusplus > 201703L
  auto onExit = finally([=, this] {
#else
  auto onExit = finally([=] {
#endif
    exitRule();
  });
  try {
    enterOuterAlt(_localctx, 1);
    setState(398);
    match(ECMAScriptParser::OpenBracket);
    setState(400);
    _errHandler->sync(this);

    switch (getInterpreter<atn::ParserATNSimulator>()->adaptivePredict(_input, 31, _ctx)) {
    case 1: {
      setState(399);
      elementList();
      break;
    }

    default:
      break;
    }
    setState(403);
    _errHandler->sync(this);

    switch (getInterpreter<atn::ParserATNSimulator>()->adaptivePredict(_input, 32, _ctx)) {
    case 1: {
      setState(402);
      match(ECMAScriptParser::Comma);
      break;
    }

    default:
      break;
    }
    setState(406);
    _errHandler->sync(this);

    _la = _input->LA(1);
    if (_la == ECMAScriptParser::Comma) {
      setState(405);
      elision();
    }
    setState(408);
    match(ECMAScriptParser::CloseBracket);
   
  }
  catch (RecognitionException &e) {
    _errHandler->reportError(this, e);
    _localctx->exception = std::current_exception();
    _errHandler->recover(this, _localctx->exception);
  }

  return _localctx;
}

//----------------- ElementListContext ------------------------------------------------------------------

ECMAScriptParser::ElementListContext::ElementListContext(ParserRuleContext *parent, size_t invokingState)
  : ParserRuleContext(parent, invokingState) {
}

std::vector<ECMAScriptParser::SingleExpressionContext *> ECMAScriptParser::ElementListContext::singleExpression() {
  return getRuleContexts<ECMAScriptParser::SingleExpressionContext>();
}

ECMAScriptParser::SingleExpressionContext* ECMAScriptParser::ElementListContext::singleExpression(size_t i) {
  return getRuleContext<ECMAScriptParser::SingleExpressionContext>(i);
}

std::vector<ECMAScriptParser::ElisionContext *> ECMAScriptParser::ElementListContext::elision() {
  return getRuleContexts<ECMAScriptParser::ElisionContext>();
}

ECMAScriptParser::ElisionContext* ECMAScriptParser::ElementListContext::elision(size_t i) {
  return getRuleContext<ECMAScriptParser::ElisionContext>(i);
}

std::vector<tree::TerminalNode *> ECMAScriptParser::ElementListContext::Comma() {
  return getTokens(ECMAScriptParser::Comma);
}

tree::TerminalNode* ECMAScriptParser::ElementListContext::Comma(size_t i) {
  return getToken(ECMAScriptParser::Comma, i);
}


size_t ECMAScriptParser::ElementListContext::getRuleIndex() const {
  return ECMAScriptParser::RuleElementList;
}


std::any ECMAScriptParser::ElementListContext::accept(tree::ParseTreeVisitor *visitor) {
  if (auto parserVisitor = dynamic_cast<ECMAScriptVisitor*>(visitor))
    return parserVisitor->visitElementList(this);
  else
    return visitor->visitChildren(this);
}

ECMAScriptParser::ElementListContext* ECMAScriptParser::elementList() {
  ElementListContext *_localctx = _tracker.createInstance<ElementListContext>(_ctx, getState());
  enterRule(_localctx, 66, ECMAScriptParser::RuleElementList);
  size_t _la = 0;

#if __cplusplus > 201703L
  auto onExit = finally([=, this] {
#else
  auto onExit = finally([=] {
#endif
    exitRule();
  });
  try {
    size_t alt;
    enterOuterAlt(_localctx, 1);
    setState(411);
    _errHandler->sync(this);

    _la = _input->LA(1);
    if (_la == ECMAScriptParser::Comma) {
      setState(410);
      elision();
    }
    setState(413);
    singleExpression(0);
    setState(421);
    _errHandler->sync(this);
    alt = getInterpreter<atn::ParserATNSimulator>()->adaptivePredict(_input, 36, _ctx);
    while (alt != 2 && alt != atn::ATN::INVALID_ALT_NUMBER) {
      if (alt == 1) {
        setState(414);
        match(ECMAScriptParser::Comma);
        setState(416);
        _errHandler->sync(this);

        _la = _input->LA(1);
        if (_la == ECMAScriptParser::Comma) {
          setState(415);
          elision();
        }
        setState(418);
        singleExpression(0); 
      }
      setState(423);
      _errHandler->sync(this);
      alt = getInterpreter<atn::ParserATNSimulator>()->adaptivePredict(_input, 36, _ctx);
    }
   
  }
  catch (RecognitionException &e) {
    _errHandler->reportError(this, e);
    _localctx->exception = std::current_exception();
    _errHandler->recover(this, _localctx->exception);
  }

  return _localctx;
}

//----------------- ElisionContext ------------------------------------------------------------------

ECMAScriptParser::ElisionContext::ElisionContext(ParserRuleContext *parent, size_t invokingState)
  : ParserRuleContext(parent, invokingState) {
}

std::vector<tree::TerminalNode *> ECMAScriptParser::ElisionContext::Comma() {
  return getTokens(ECMAScriptParser::Comma);
}

tree::TerminalNode* ECMAScriptParser::ElisionContext::Comma(size_t i) {
  return getToken(ECMAScriptParser::Comma, i);
}


size_t ECMAScriptParser::ElisionContext::getRuleIndex() const {
  return ECMAScriptParser::RuleElision;
}


std::any ECMAScriptParser::ElisionContext::accept(tree::ParseTreeVisitor *visitor) {
  if (auto parserVisitor = dynamic_cast<ECMAScriptVisitor*>(visitor))
    return parserVisitor->visitElision(this);
  else
    return visitor->visitChildren(this);
}

ECMAScriptParser::ElisionContext* ECMAScriptParser::elision() {
  ElisionContext *_localctx = _tracker.createInstance<ElisionContext>(_ctx, getState());
  enterRule(_localctx, 68, ECMAScriptParser::RuleElision);
  size_t _la = 0;

#if __cplusplus > 201703L
  auto onExit = finally([=, this] {
#else
  auto onExit = finally([=] {
#endif
    exitRule();
  });
  try {
    enterOuterAlt(_localctx, 1);
    setState(425); 
    _errHandler->sync(this);
    _la = _input->LA(1);
    do {
      setState(424);
      match(ECMAScriptParser::Comma);
      setState(427); 
      _errHandler->sync(this);
      _la = _input->LA(1);
    } while (_la == ECMAScriptParser::Comma);
   
  }
  catch (RecognitionException &e) {
    _errHandler->reportError(this, e);
    _localctx->exception = std::current_exception();
    _errHandler->recover(this, _localctx->exception);
  }

  return _localctx;
}

//----------------- ObjectLiteralContext ------------------------------------------------------------------

ECMAScriptParser::ObjectLiteralContext::ObjectLiteralContext(ParserRuleContext *parent, size_t invokingState)
  : ParserRuleContext(parent, invokingState) {
}

tree::TerminalNode* ECMAScriptParser::ObjectLiteralContext::OpenBrace() {
  return getToken(ECMAScriptParser::OpenBrace, 0);
}

tree::TerminalNode* ECMAScriptParser::ObjectLiteralContext::CloseBrace() {
  return getToken(ECMAScriptParser::CloseBrace, 0);
}

ECMAScriptParser::PropertyNameAndValueListContext* ECMAScriptParser::ObjectLiteralContext::propertyNameAndValueList() {
  return getRuleContext<ECMAScriptParser::PropertyNameAndValueListContext>(0);
}

tree::TerminalNode* ECMAScriptParser::ObjectLiteralContext::Comma() {
  return getToken(ECMAScriptParser::Comma, 0);
}


size_t ECMAScriptParser::ObjectLiteralContext::getRuleIndex() const {
  return ECMAScriptParser::RuleObjectLiteral;
}


std::any ECMAScriptParser::ObjectLiteralContext::accept(tree::ParseTreeVisitor *visitor) {
  if (auto parserVisitor = dynamic_cast<ECMAScriptVisitor*>(visitor))
    return parserVisitor->visitObjectLiteral(this);
  else
    return visitor->visitChildren(this);
}

ECMAScriptParser::ObjectLiteralContext* ECMAScriptParser::objectLiteral() {
  ObjectLiteralContext *_localctx = _tracker.createInstance<ObjectLiteralContext>(_ctx, getState());
  enterRule(_localctx, 70, ECMAScriptParser::RuleObjectLiteral);
  size_t _la = 0;

#if __cplusplus > 201703L
  auto onExit = finally([=, this] {
#else
  auto onExit = finally([=] {
#endif
    exitRule();
  });
  try {
    enterOuterAlt(_localctx, 1);
    setState(429);
    match(ECMAScriptParser::OpenBrace);
    setState(431);
    _errHandler->sync(this);

    switch (getInterpreter<atn::ParserATNSimulator>()->adaptivePredict(_input, 38, _ctx)) {
    case 1: {
      setState(430);
      propertyNameAndValueList();
      break;
    }

    default:
      break;
    }
    setState(434);
    _errHandler->sync(this);

    _la = _input->LA(1);
    if (_la == ECMAScriptParser::Comma) {
      setState(433);
      match(ECMAScriptParser::Comma);
    }
    setState(436);
    match(ECMAScriptParser::CloseBrace);
   
  }
  catch (RecognitionException &e) {
    _errHandler->reportError(this, e);
    _localctx->exception = std::current_exception();
    _errHandler->recover(this, _localctx->exception);
  }

  return _localctx;
}

//----------------- PropertyNameAndValueListContext ------------------------------------------------------------------

ECMAScriptParser::PropertyNameAndValueListContext::PropertyNameAndValueListContext(ParserRuleContext *parent, size_t invokingState)
  : ParserRuleContext(parent, invokingState) {
}

std::vector<ECMAScriptParser::PropertyAssignmentContext *> ECMAScriptParser::PropertyNameAndValueListContext::propertyAssignment() {
  return getRuleContexts<ECMAScriptParser::PropertyAssignmentContext>();
}

ECMAScriptParser::PropertyAssignmentContext* ECMAScriptParser::PropertyNameAndValueListContext::propertyAssignment(size_t i) {
  return getRuleContext<ECMAScriptParser::PropertyAssignmentContext>(i);
}

std::vector<tree::TerminalNode *> ECMAScriptParser::PropertyNameAndValueListContext::Comma() {
  return getTokens(ECMAScriptParser::Comma);
}

tree::TerminalNode* ECMAScriptParser::PropertyNameAndValueListContext::Comma(size_t i) {
  return getToken(ECMAScriptParser::Comma, i);
}


size_t ECMAScriptParser::PropertyNameAndValueListContext::getRuleIndex() const {
  return ECMAScriptParser::RulePropertyNameAndValueList;
}


std::any ECMAScriptParser::PropertyNameAndValueListContext::accept(tree::ParseTreeVisitor *visitor) {
  if (auto parserVisitor = dynamic_cast<ECMAScriptVisitor*>(visitor))
    return parserVisitor->visitPropertyNameAndValueList(this);
  else
    return visitor->visitChildren(this);
}

ECMAScriptParser::PropertyNameAndValueListContext* ECMAScriptParser::propertyNameAndValueList() {
  PropertyNameAndValueListContext *_localctx = _tracker.createInstance<PropertyNameAndValueListContext>(_ctx, getState());
  enterRule(_localctx, 72, ECMAScriptParser::RulePropertyNameAndValueList);

#if __cplusplus > 201703L
  auto onExit = finally([=, this] {
#else
  auto onExit = finally([=] {
#endif
    exitRule();
  });
  try {
    size_t alt;
    enterOuterAlt(_localctx, 1);
    setState(438);
    propertyAssignment();
    setState(443);
    _errHandler->sync(this);
    alt = getInterpreter<atn::ParserATNSimulator>()->adaptivePredict(_input, 40, _ctx);
    while (alt != 2 && alt != atn::ATN::INVALID_ALT_NUMBER) {
      if (alt == 1) {
        setState(439);
        match(ECMAScriptParser::Comma);
        setState(440);
        propertyAssignment(); 
      }
      setState(445);
      _errHandler->sync(this);
      alt = getInterpreter<atn::ParserATNSimulator>()->adaptivePredict(_input, 40, _ctx);
    }
   
  }
  catch (RecognitionException &e) {
    _errHandler->reportError(this, e);
    _localctx->exception = std::current_exception();
    _errHandler->recover(this, _localctx->exception);
  }

  return _localctx;
}

//----------------- PropertyAssignmentContext ------------------------------------------------------------------

ECMAScriptParser::PropertyAssignmentContext::PropertyAssignmentContext(ParserRuleContext *parent, size_t invokingState)
  : ParserRuleContext(parent, invokingState) {
}


size_t ECMAScriptParser::PropertyAssignmentContext::getRuleIndex() const {
  return ECMAScriptParser::RulePropertyAssignment;
}

void ECMAScriptParser::PropertyAssignmentContext::copyFrom(PropertyAssignmentContext *ctx) {
  ParserRuleContext::copyFrom(ctx);
}

//----------------- PropertyExpressionAssignmentContext ------------------------------------------------------------------

ECMAScriptParser::PropertyNameContext* ECMAScriptParser::PropertyExpressionAssignmentContext::propertyName() {
  return getRuleContext<ECMAScriptParser::PropertyNameContext>(0);
}

tree::TerminalNode* ECMAScriptParser::PropertyExpressionAssignmentContext::Colon() {
  return getToken(ECMAScriptParser::Colon, 0);
}

ECMAScriptParser::SingleExpressionContext* ECMAScriptParser::PropertyExpressionAssignmentContext::singleExpression() {
  return getRuleContext<ECMAScriptParser::SingleExpressionContext>(0);
}

ECMAScriptParser::PropertyExpressionAssignmentContext::PropertyExpressionAssignmentContext(PropertyAssignmentContext *ctx) { copyFrom(ctx); }


std::any ECMAScriptParser::PropertyExpressionAssignmentContext::accept(tree::ParseTreeVisitor *visitor) {
  if (auto parserVisitor = dynamic_cast<ECMAScriptVisitor*>(visitor))
    return parserVisitor->visitPropertyExpressionAssignment(this);
  else
    return visitor->visitChildren(this);
}
//----------------- PropertySetterContext ------------------------------------------------------------------

ECMAScriptParser::SetterContext* ECMAScriptParser::PropertySetterContext::setter() {
  return getRuleContext<ECMAScriptParser::SetterContext>(0);
}

tree::TerminalNode* ECMAScriptParser::PropertySetterContext::OpenParen() {
  return getToken(ECMAScriptParser::OpenParen, 0);
}

ECMAScriptParser::PropertySetParameterListContext* ECMAScriptParser::PropertySetterContext::propertySetParameterList() {
  return getRuleContext<ECMAScriptParser::PropertySetParameterListContext>(0);
}

tree::TerminalNode* ECMAScriptParser::PropertySetterContext::CloseParen() {
  return getToken(ECMAScriptParser::CloseParen, 0);
}

tree::TerminalNode* ECMAScriptParser::PropertySetterContext::OpenBrace() {
  return getToken(ECMAScriptParser::OpenBrace, 0);
}

ECMAScriptParser::FunctionBodyContext* ECMAScriptParser::PropertySetterContext::functionBody() {
  return getRuleContext<ECMAScriptParser::FunctionBodyContext>(0);
}

tree::TerminalNode* ECMAScriptParser::PropertySetterContext::CloseBrace() {
  return getToken(ECMAScriptParser::CloseBrace, 0);
}

ECMAScriptParser::PropertySetterContext::PropertySetterContext(PropertyAssignmentContext *ctx) { copyFrom(ctx); }


std::any ECMAScriptParser::PropertySetterContext::accept(tree::ParseTreeVisitor *visitor) {
  if (auto parserVisitor = dynamic_cast<ECMAScriptVisitor*>(visitor))
    return parserVisitor->visitPropertySetter(this);
  else
    return visitor->visitChildren(this);
}
//----------------- PropertyGetterContext ------------------------------------------------------------------

ECMAScriptParser::GetterContext* ECMAScriptParser::PropertyGetterContext::getter() {
  return getRuleContext<ECMAScriptParser::GetterContext>(0);
}

tree::TerminalNode* ECMAScriptParser::PropertyGetterContext::OpenParen() {
  return getToken(ECMAScriptParser::OpenParen, 0);
}

tree::TerminalNode* ECMAScriptParser::PropertyGetterContext::CloseParen() {
  return getToken(ECMAScriptParser::CloseParen, 0);
}

tree::TerminalNode* ECMAScriptParser::PropertyGetterContext::OpenBrace() {
  return getToken(ECMAScriptParser::OpenBrace, 0);
}

ECMAScriptParser::FunctionBodyContext* ECMAScriptParser::PropertyGetterContext::functionBody() {
  return getRuleContext<ECMAScriptParser::FunctionBodyContext>(0);
}

tree::TerminalNode* ECMAScriptParser::PropertyGetterContext::CloseBrace() {
  return getToken(ECMAScriptParser::CloseBrace, 0);
}

ECMAScriptParser::PropertyGetterContext::PropertyGetterContext(PropertyAssignmentContext *ctx) { copyFrom(ctx); }


std::any ECMAScriptParser::PropertyGetterContext::accept(tree::ParseTreeVisitor *visitor) {
  if (auto parserVisitor = dynamic_cast<ECMAScriptVisitor*>(visitor))
    return parserVisitor->visitPropertyGetter(this);
  else
    return visitor->visitChildren(this);
}
ECMAScriptParser::PropertyAssignmentContext* ECMAScriptParser::propertyAssignment() {
  PropertyAssignmentContext *_localctx = _tracker.createInstance<PropertyAssignmentContext>(_ctx, getState());
  enterRule(_localctx, 74, ECMAScriptParser::RulePropertyAssignment);

#if __cplusplus > 201703L
  auto onExit = finally([=, this] {
#else
  auto onExit = finally([=] {
#endif
    exitRule();
  });
  try {
    setState(465);
    _errHandler->sync(this);
    switch (getInterpreter<atn::ParserATNSimulator>()->adaptivePredict(_input, 41, _ctx)) {
    case 1: {
      _localctx = _tracker.createInstance<ECMAScriptParser::PropertyExpressionAssignmentContext>(_localctx);
      enterOuterAlt(_localctx, 1);
      setState(446);
      propertyName();
      setState(447);
      match(ECMAScriptParser::Colon);
      setState(448);
      singleExpression(0);
      break;
    }

    case 2: {
      _localctx = _tracker.createInstance<ECMAScriptParser::PropertyGetterContext>(_localctx);
      enterOuterAlt(_localctx, 2);
      setState(450);
      getter();
      setState(451);
      match(ECMAScriptParser::OpenParen);
      setState(452);
      match(ECMAScriptParser::CloseParen);
      setState(453);
      match(ECMAScriptParser::OpenBrace);
      setState(454);
      functionBody();
      setState(455);
      match(ECMAScriptParser::CloseBrace);
      break;
    }

    case 3: {
      _localctx = _tracker.createInstance<ECMAScriptParser::PropertySetterContext>(_localctx);
      enterOuterAlt(_localctx, 3);
      setState(457);
      setter();
      setState(458);
      match(ECMAScriptParser::OpenParen);
      setState(459);
      propertySetParameterList();
      setState(460);
      match(ECMAScriptParser::CloseParen);
      setState(461);
      match(ECMAScriptParser::OpenBrace);
      setState(462);
      functionBody();
      setState(463);
      match(ECMAScriptParser::CloseBrace);
      break;
    }

    default:
      break;
    }
   
  }
  catch (RecognitionException &e) {
    _errHandler->reportError(this, e);
    _localctx->exception = std::current_exception();
    _errHandler->recover(this, _localctx->exception);
  }

  return _localctx;
}

//----------------- PropertyNameContext ------------------------------------------------------------------

ECMAScriptParser::PropertyNameContext::PropertyNameContext(ParserRuleContext *parent, size_t invokingState)
  : ParserRuleContext(parent, invokingState) {
}

ECMAScriptParser::IdentifierNameContext* ECMAScriptParser::PropertyNameContext::identifierName() {
  return getRuleContext<ECMAScriptParser::IdentifierNameContext>(0);
}

tree::TerminalNode* ECMAScriptParser::PropertyNameContext::StringLiteral() {
  return getToken(ECMAScriptParser::StringLiteral, 0);
}

ECMAScriptParser::NumericLiteralContext* ECMAScriptParser::PropertyNameContext::numericLiteral() {
  return getRuleContext<ECMAScriptParser::NumericLiteralContext>(0);
}


size_t ECMAScriptParser::PropertyNameContext::getRuleIndex() const {
  return ECMAScriptParser::RulePropertyName;
}


std::any ECMAScriptParser::PropertyNameContext::accept(tree::ParseTreeVisitor *visitor) {
  if (auto parserVisitor = dynamic_cast<ECMAScriptVisitor*>(visitor))
    return parserVisitor->visitPropertyName(this);
  else
    return visitor->visitChildren(this);
}

ECMAScriptParser::PropertyNameContext* ECMAScriptParser::propertyName() {
  PropertyNameContext *_localctx = _tracker.createInstance<PropertyNameContext>(_ctx, getState());
  enterRule(_localctx, 76, ECMAScriptParser::RulePropertyName);

#if __cplusplus > 201703L
  auto onExit = finally([=, this] {
#else
  auto onExit = finally([=] {
#endif
    exitRule();
  });
  try {
    setState(470);
    _errHandler->sync(this);
    switch (_input->LA(1)) {
      case ECMAScriptParser::NullLiteral:
      case ECMAScriptParser::BooleanLiteral:
      case ECMAScriptParser::Break:
      case ECMAScriptParser::Do:
      case ECMAScriptParser::Instanceof:
      case ECMAScriptParser::Typeof:
      case ECMAScriptParser::Case:
      case ECMAScriptParser::Else:
      case ECMAScriptParser::New:
      case ECMAScriptParser::Var:
      case ECMAScriptParser::Let:
      case ECMAScriptParser::Catch:
      case ECMAScriptParser::Finally:
      case ECMAScriptParser::Return:
      case ECMAScriptParser::Void:
      case ECMAScriptParser::Continue:
      case ECMAScriptParser::For:
      case ECMAScriptParser::Switch:
      case ECMAScriptParser::While:
      case ECMAScriptParser::Debugger:
      case ECMAScriptParser::Function:
      case ECMAScriptParser::This:
      case ECMAScriptParser::With:
      case ECMAScriptParser::Default:
      case ECMAScriptParser::If:
      case ECMAScriptParser::Throw:
      case ECMAScriptParser::Delete:
      case ECMAScriptParser::In:
      case ECMAScriptParser::Try:
      case ECMAScriptParser::Class:
      case ECMAScriptParser::Enum:
      case ECMAScriptParser::Extends:
      case ECMAScriptParser::Super:
      case ECMAScriptParser::Const:
      case ECMAScriptParser::Export:
      case ECMAScriptParser::Import:
      case ECMAScriptParser::Implements:
      case ECMAScriptParser::Private:
      case ECMAScriptParser::Public:
      case ECMAScriptParser::Interface:
      case ECMAScriptParser::Package:
      case ECMAScriptParser::Protected:
      case ECMAScriptParser::Static:
      case ECMAScriptParser::Yield:
      case ECMAScriptParser::Identifier: {
        enterOuterAlt(_localctx, 1);
        setState(467);
        identifierName();
        break;
      }

      case ECMAScriptParser::StringLiteral: {
        enterOuterAlt(_localctx, 2);
        setState(468);
        match(ECMAScriptParser::StringLiteral);
        break;
      }

      case ECMAScriptParser::DecimalLiteral:
      case ECMAScriptParser::HexIntegerLiteral:
      case ECMAScriptParser::OctalIntegerLiteral: {
        enterOuterAlt(_localctx, 3);
        setState(469);
        numericLiteral();
        break;
      }

    default:
      throw NoViableAltException(this);
    }
   
  }
  catch (RecognitionException &e) {
    _errHandler->reportError(this, e);
    _localctx->exception = std::current_exception();
    _errHandler->recover(this, _localctx->exception);
  }

  return _localctx;
}

//----------------- PropertySetParameterListContext ------------------------------------------------------------------

ECMAScriptParser::PropertySetParameterListContext::PropertySetParameterListContext(ParserRuleContext *parent, size_t invokingState)
  : ParserRuleContext(parent, invokingState) {
}

tree::TerminalNode* ECMAScriptParser::PropertySetParameterListContext::Identifier() {
  return getToken(ECMAScriptParser::Identifier, 0);
}


size_t ECMAScriptParser::PropertySetParameterListContext::getRuleIndex() const {
  return ECMAScriptParser::RulePropertySetParameterList;
}


std::any ECMAScriptParser::PropertySetParameterListContext::accept(tree::ParseTreeVisitor *visitor) {
  if (auto parserVisitor = dynamic_cast<ECMAScriptVisitor*>(visitor))
    return parserVisitor->visitPropertySetParameterList(this);
  else
    return visitor->visitChildren(this);
}

ECMAScriptParser::PropertySetParameterListContext* ECMAScriptParser::propertySetParameterList() {
  PropertySetParameterListContext *_localctx = _tracker.createInstance<PropertySetParameterListContext>(_ctx, getState());
  enterRule(_localctx, 78, ECMAScriptParser::RulePropertySetParameterList);

#if __cplusplus > 201703L
  auto onExit = finally([=, this] {
#else
  auto onExit = finally([=] {
#endif
    exitRule();
  });
  try {
    enterOuterAlt(_localctx, 1);
    setState(472);
    match(ECMAScriptParser::Identifier);
   
  }
  catch (RecognitionException &e) {
    _errHandler->reportError(this, e);
    _localctx->exception = std::current_exception();
    _errHandler->recover(this, _localctx->exception);
  }

  return _localctx;
}

//----------------- ArgumentsContext ------------------------------------------------------------------

ECMAScriptParser::ArgumentsContext::ArgumentsContext(ParserRuleContext *parent, size_t invokingState)
  : ParserRuleContext(parent, invokingState) {
}

tree::TerminalNode* ECMAScriptParser::ArgumentsContext::OpenParen() {
  return getToken(ECMAScriptParser::OpenParen, 0);
}

tree::TerminalNode* ECMAScriptParser::ArgumentsContext::CloseParen() {
  return getToken(ECMAScriptParser::CloseParen, 0);
}

ECMAScriptParser::ArgumentListContext* ECMAScriptParser::ArgumentsContext::argumentList() {
  return getRuleContext<ECMAScriptParser::ArgumentListContext>(0);
}


size_t ECMAScriptParser::ArgumentsContext::getRuleIndex() const {
  return ECMAScriptParser::RuleArguments;
}


std::any ECMAScriptParser::ArgumentsContext::accept(tree::ParseTreeVisitor *visitor) {
  if (auto parserVisitor = dynamic_cast<ECMAScriptVisitor*>(visitor))
    return parserVisitor->visitArguments(this);
  else
    return visitor->visitChildren(this);
}

ECMAScriptParser::ArgumentsContext* ECMAScriptParser::arguments() {
  ArgumentsContext *_localctx = _tracker.createInstance<ArgumentsContext>(_ctx, getState());
  enterRule(_localctx, 80, ECMAScriptParser::RuleArguments);
  size_t _la = 0;

#if __cplusplus > 201703L
  auto onExit = finally([=, this] {
#else
  auto onExit = finally([=] {
#endif
    exitRule();
  });
  try {
    enterOuterAlt(_localctx, 1);
    setState(474);
    match(ECMAScriptParser::OpenParen);
    setState(476);
    _errHandler->sync(this);

    _la = _input->LA(1);
    if ((((_la & ~ 0x3fULL) == 0) &&
      ((1ULL << _la) & 5257952564957118634) != 0) || ((((_la - 68) & ~ 0x3fULL) == 0) &&
      ((1ULL << (_la - 68)) & 3221229761) != 0)) {
      setState(475);
      argumentList();
    }
    setState(478);
    match(ECMAScriptParser::CloseParen);
   
  }
  catch (RecognitionException &e) {
    _errHandler->reportError(this, e);
    _localctx->exception = std::current_exception();
    _errHandler->recover(this, _localctx->exception);
  }

  return _localctx;
}

//----------------- ArgumentListContext ------------------------------------------------------------------

ECMAScriptParser::ArgumentListContext::ArgumentListContext(ParserRuleContext *parent, size_t invokingState)
  : ParserRuleContext(parent, invokingState) {
}

std::vector<ECMAScriptParser::SingleExpressionContext *> ECMAScriptParser::ArgumentListContext::singleExpression() {
  return getRuleContexts<ECMAScriptParser::SingleExpressionContext>();
}

ECMAScriptParser::SingleExpressionContext* ECMAScriptParser::ArgumentListContext::singleExpression(size_t i) {
  return getRuleContext<ECMAScriptParser::SingleExpressionContext>(i);
}

std::vector<tree::TerminalNode *> ECMAScriptParser::ArgumentListContext::Comma() {
  return getTokens(ECMAScriptParser::Comma);
}

tree::TerminalNode* ECMAScriptParser::ArgumentListContext::Comma(size_t i) {
  return getToken(ECMAScriptParser::Comma, i);
}


size_t ECMAScriptParser::ArgumentListContext::getRuleIndex() const {
  return ECMAScriptParser::RuleArgumentList;
}


std::any ECMAScriptParser::ArgumentListContext::accept(tree::ParseTreeVisitor *visitor) {
  if (auto parserVisitor = dynamic_cast<ECMAScriptVisitor*>(visitor))
    return parserVisitor->visitArgumentList(this);
  else
    return visitor->visitChildren(this);
}

ECMAScriptParser::ArgumentListContext* ECMAScriptParser::argumentList() {
  ArgumentListContext *_localctx = _tracker.createInstance<ArgumentListContext>(_ctx, getState());
  enterRule(_localctx, 82, ECMAScriptParser::RuleArgumentList);
  size_t _la = 0;

#if __cplusplus > 201703L
  auto onExit = finally([=, this] {
#else
  auto onExit = finally([=] {
#endif
    exitRule();
  });
  try {
    enterOuterAlt(_localctx, 1);
    setState(480);
    singleExpression(0);
    setState(485);
    _errHandler->sync(this);
    _la = _input->LA(1);
    while (_la == ECMAScriptParser::Comma) {
      setState(481);
      match(ECMAScriptParser::Comma);
      setState(482);
      singleExpression(0);
      setState(487);
      _errHandler->sync(this);
      _la = _input->LA(1);
    }
   
  }
  catch (RecognitionException &e) {
    _errHandler->reportError(this, e);
    _localctx->exception = std::current_exception();
    _errHandler->recover(this, _localctx->exception);
  }

  return _localctx;
}

//----------------- ExpressionSequenceContext ------------------------------------------------------------------

ECMAScriptParser::ExpressionSequenceContext::ExpressionSequenceContext(ParserRuleContext *parent, size_t invokingState)
  : ParserRuleContext(parent, invokingState) {
}

std::vector<ECMAScriptParser::SingleExpressionContext *> ECMAScriptParser::ExpressionSequenceContext::singleExpression() {
  return getRuleContexts<ECMAScriptParser::SingleExpressionContext>();
}

ECMAScriptParser::SingleExpressionContext* ECMAScriptParser::ExpressionSequenceContext::singleExpression(size_t i) {
  return getRuleContext<ECMAScriptParser::SingleExpressionContext>(i);
}

std::vector<tree::TerminalNode *> ECMAScriptParser::ExpressionSequenceContext::Comma() {
  return getTokens(ECMAScriptParser::Comma);
}

tree::TerminalNode* ECMAScriptParser::ExpressionSequenceContext::Comma(size_t i) {
  return getToken(ECMAScriptParser::Comma, i);
}


size_t ECMAScriptParser::ExpressionSequenceContext::getRuleIndex() const {
  return ECMAScriptParser::RuleExpressionSequence;
}


std::any ECMAScriptParser::ExpressionSequenceContext::accept(tree::ParseTreeVisitor *visitor) {
  if (auto parserVisitor = dynamic_cast<ECMAScriptVisitor*>(visitor))
    return parserVisitor->visitExpressionSequence(this);
  else
    return visitor->visitChildren(this);
}

ECMAScriptParser::ExpressionSequenceContext* ECMAScriptParser::expressionSequence() {
  ExpressionSequenceContext *_localctx = _tracker.createInstance<ExpressionSequenceContext>(_ctx, getState());
  enterRule(_localctx, 84, ECMAScriptParser::RuleExpressionSequence);

#if __cplusplus > 201703L
  auto onExit = finally([=, this] {
#else
  auto onExit = finally([=] {
#endif
    exitRule();
  });
  try {
    size_t alt;
    enterOuterAlt(_localctx, 1);
    setState(488);
    singleExpression(0);
    setState(493);
    _errHandler->sync(this);
    alt = getInterpreter<atn::ParserATNSimulator>()->adaptivePredict(_input, 45, _ctx);
    while (alt != 2 && alt != atn::ATN::INVALID_ALT_NUMBER) {
      if (alt == 1) {
        setState(489);
        match(ECMAScriptParser::Comma);
        setState(490);
        singleExpression(0); 
      }
      setState(495);
      _errHandler->sync(this);
      alt = getInterpreter<atn::ParserATNSimulator>()->adaptivePredict(_input, 45, _ctx);
    }
   
  }
  catch (RecognitionException &e) {
    _errHandler->reportError(this, e);
    _localctx->exception = std::current_exception();
    _errHandler->recover(this, _localctx->exception);
  }

  return _localctx;
}

//----------------- SingleExpressionContext ------------------------------------------------------------------

ECMAScriptParser::SingleExpressionContext::SingleExpressionContext(ParserRuleContext *parent, size_t invokingState)
  : ParserRuleContext(parent, invokingState) {
}


size_t ECMAScriptParser::SingleExpressionContext::getRuleIndex() const {
  return ECMAScriptParser::RuleSingleExpression;
}

void ECMAScriptParser::SingleExpressionContext::copyFrom(SingleExpressionContext *ctx) {
  ParserRuleContext::copyFrom(ctx);
}

//----------------- TernaryExpressionContext ------------------------------------------------------------------

std::vector<ECMAScriptParser::SingleExpressionContext *> ECMAScriptParser::TernaryExpressionContext::singleExpression() {
  return getRuleContexts<ECMAScriptParser::SingleExpressionContext>();
}

ECMAScriptParser::SingleExpressionContext* ECMAScriptParser::TernaryExpressionContext::singleExpression(size_t i) {
  return getRuleContext<ECMAScriptParser::SingleExpressionContext>(i);
}

tree::TerminalNode* ECMAScriptParser::TernaryExpressionContext::QuestionMark() {
  return getToken(ECMAScriptParser::QuestionMark, 0);
}

tree::TerminalNode* ECMAScriptParser::TernaryExpressionContext::Colon() {
  return getToken(ECMAScriptParser::Colon, 0);
}

ECMAScriptParser::TernaryExpressionContext::TernaryExpressionContext(SingleExpressionContext *ctx) { copyFrom(ctx); }


std::any ECMAScriptParser::TernaryExpressionContext::accept(tree::ParseTreeVisitor *visitor) {
  if (auto parserVisitor = dynamic_cast<ECMAScriptVisitor*>(visitor))
    return parserVisitor->visitTernaryExpression(this);
  else
    return visitor->visitChildren(this);
}
//----------------- LogicalAndExpressionContext ------------------------------------------------------------------

std::vector<ECMAScriptParser::SingleExpressionContext *> ECMAScriptParser::LogicalAndExpressionContext::singleExpression() {
  return getRuleContexts<ECMAScriptParser::SingleExpressionContext>();
}

ECMAScriptParser::SingleExpressionContext* ECMAScriptParser::LogicalAndExpressionContext::singleExpression(size_t i) {
  return getRuleContext<ECMAScriptParser::SingleExpressionContext>(i);
}

tree::TerminalNode* ECMAScriptParser::LogicalAndExpressionContext::And() {
  return getToken(ECMAScriptParser::And, 0);
}

ECMAScriptParser::LogicalAndExpressionContext::LogicalAndExpressionContext(SingleExpressionContext *ctx) { copyFrom(ctx); }


std::any ECMAScriptParser::LogicalAndExpressionContext::accept(tree::ParseTreeVisitor *visitor) {
  if (auto parserVisitor = dynamic_cast<ECMAScriptVisitor*>(visitor))
    return parserVisitor->visitLogicalAndExpression(this);
  else
    return visitor->visitChildren(this);
}
//----------------- PreIncrementExpressionContext ------------------------------------------------------------------

tree::TerminalNode* ECMAScriptParser::PreIncrementExpressionContext::PlusPlus() {
  return getToken(ECMAScriptParser::PlusPlus, 0);
}

ECMAScriptParser::SingleExpressionContext* ECMAScriptParser::PreIncrementExpressionContext::singleExpression() {
  return getRuleContext<ECMAScriptParser::SingleExpressionContext>(0);
}

ECMAScriptParser::PreIncrementExpressionContext::PreIncrementExpressionContext(SingleExpressionContext *ctx) { copyFrom(ctx); }


std::any ECMAScriptParser::PreIncrementExpressionContext::accept(tree::ParseTreeVisitor *visitor) {
  if (auto parserVisitor = dynamic_cast<ECMAScriptVisitor*>(visitor))
    return parserVisitor->visitPreIncrementExpression(this);
  else
    return visitor->visitChildren(this);
}
//----------------- ObjectLiteralExpressionContext ------------------------------------------------------------------

ECMAScriptParser::ObjectLiteralContext* ECMAScriptParser::ObjectLiteralExpressionContext::objectLiteral() {
  return getRuleContext<ECMAScriptParser::ObjectLiteralContext>(0);
}

ECMAScriptParser::ObjectLiteralExpressionContext::ObjectLiteralExpressionContext(SingleExpressionContext *ctx) { copyFrom(ctx); }


std::any ECMAScriptParser::ObjectLiteralExpressionContext::accept(tree::ParseTreeVisitor *visitor) {
  if (auto parserVisitor = dynamic_cast<ECMAScriptVisitor*>(visitor))
    return parserVisitor->visitObjectLiteralExpression(this);
  else
    return visitor->visitChildren(this);
}
//----------------- InExpressionContext ------------------------------------------------------------------

std::vector<ECMAScriptParser::SingleExpressionContext *> ECMAScriptParser::InExpressionContext::singleExpression() {
  return getRuleContexts<ECMAScriptParser::SingleExpressionContext>();
}

ECMAScriptParser::SingleExpressionContext* ECMAScriptParser::InExpressionContext::singleExpression(size_t i) {
  return getRuleContext<ECMAScriptParser::SingleExpressionContext>(i);
}

tree::TerminalNode* ECMAScriptParser::InExpressionContext::In() {
  return getToken(ECMAScriptParser::In, 0);
}

ECMAScriptParser::InExpressionContext::InExpressionContext(SingleExpressionContext *ctx) { copyFrom(ctx); }


std::any ECMAScriptParser::InExpressionContext::accept(tree::ParseTreeVisitor *visitor) {
  if (auto parserVisitor = dynamic_cast<ECMAScriptVisitor*>(visitor))
    return parserVisitor->visitInExpression(this);
  else
    return visitor->visitChildren(this);
}
//----------------- LogicalOrExpressionContext ------------------------------------------------------------------

std::vector<ECMAScriptParser::SingleExpressionContext *> ECMAScriptParser::LogicalOrExpressionContext::singleExpression() {
  return getRuleContexts<ECMAScriptParser::SingleExpressionContext>();
}

ECMAScriptParser::SingleExpressionContext* ECMAScriptParser::LogicalOrExpressionContext::singleExpression(size_t i) {
  return getRuleContext<ECMAScriptParser::SingleExpressionContext>(i);
}

tree::TerminalNode* ECMAScriptParser::LogicalOrExpressionContext::Or() {
  return getToken(ECMAScriptParser::Or, 0);
}

ECMAScriptParser::LogicalOrExpressionContext::LogicalOrExpressionContext(SingleExpressionContext *ctx) { copyFrom(ctx); }


std::any ECMAScriptParser::LogicalOrExpressionContext::accept(tree::ParseTreeVisitor *visitor) {
  if (auto parserVisitor = dynamic_cast<ECMAScriptVisitor*>(visitor))
    return parserVisitor->visitLogicalOrExpression(this);
  else
    return visitor->visitChildren(this);
}
//----------------- NotExpressionContext ------------------------------------------------------------------

tree::TerminalNode* ECMAScriptParser::NotExpressionContext::Not() {
  return getToken(ECMAScriptParser::Not, 0);
}

ECMAScriptParser::SingleExpressionContext* ECMAScriptParser::NotExpressionContext::singleExpression() {
  return getRuleContext<ECMAScriptParser::SingleExpressionContext>(0);
}

ECMAScriptParser::NotExpressionContext::NotExpressionContext(SingleExpressionContext *ctx) { copyFrom(ctx); }


std::any ECMAScriptParser::NotExpressionContext::accept(tree::ParseTreeVisitor *visitor) {
  if (auto parserVisitor = dynamic_cast<ECMAScriptVisitor*>(visitor))
    return parserVisitor->visitNotExpression(this);
  else
    return visitor->visitChildren(this);
}
//----------------- PreDecreaseExpressionContext ------------------------------------------------------------------

tree::TerminalNode* ECMAScriptParser::PreDecreaseExpressionContext::MinusMinus() {
  return getToken(ECMAScriptParser::MinusMinus, 0);
}

ECMAScriptParser::SingleExpressionContext* ECMAScriptParser::PreDecreaseExpressionContext::singleExpression() {
  return getRuleContext<ECMAScriptParser::SingleExpressionContext>(0);
}

ECMAScriptParser::PreDecreaseExpressionContext::PreDecreaseExpressionContext(SingleExpressionContext *ctx) { copyFrom(ctx); }


std::any ECMAScriptParser::PreDecreaseExpressionContext::accept(tree::ParseTreeVisitor *visitor) {
  if (auto parserVisitor = dynamic_cast<ECMAScriptVisitor*>(visitor))
    return parserVisitor->visitPreDecreaseExpression(this);
  else
    return visitor->visitChildren(this);
}
//----------------- ArgumentsExpressionContext ------------------------------------------------------------------

ECMAScriptParser::SingleExpressionContext* ECMAScriptParser::ArgumentsExpressionContext::singleExpression() {
  return getRuleContext<ECMAScriptParser::SingleExpressionContext>(0);
}

ECMAScriptParser::ArgumentsContext* ECMAScriptParser::ArgumentsExpressionContext::arguments() {
  return getRuleContext<ECMAScriptParser::ArgumentsContext>(0);
}

ECMAScriptParser::ArgumentsExpressionContext::ArgumentsExpressionContext(SingleExpressionContext *ctx) { copyFrom(ctx); }


std::any ECMAScriptParser::ArgumentsExpressionContext::accept(tree::ParseTreeVisitor *visitor) {
  if (auto parserVisitor = dynamic_cast<ECMAScriptVisitor*>(visitor))
    return parserVisitor->visitArgumentsExpression(this);
  else
    return visitor->visitChildren(this);
}
//----------------- ThisExpressionContext ------------------------------------------------------------------

tree::TerminalNode* ECMAScriptParser::ThisExpressionContext::This() {
  return getToken(ECMAScriptParser::This, 0);
}

ECMAScriptParser::ThisExpressionContext::ThisExpressionContext(SingleExpressionContext *ctx) { copyFrom(ctx); }


std::any ECMAScriptParser::ThisExpressionContext::accept(tree::ParseTreeVisitor *visitor) {
  if (auto parserVisitor = dynamic_cast<ECMAScriptVisitor*>(visitor))
    return parserVisitor->visitThisExpression(this);
  else
    return visitor->visitChildren(this);
}
//----------------- FunctionExpressionContext ------------------------------------------------------------------

tree::TerminalNode* ECMAScriptParser::FunctionExpressionContext::Function() {
  return getToken(ECMAScriptParser::Function, 0);
}

tree::TerminalNode* ECMAScriptParser::FunctionExpressionContext::OpenParen() {
  return getToken(ECMAScriptParser::OpenParen, 0);
}

tree::TerminalNode* ECMAScriptParser::FunctionExpressionContext::CloseParen() {
  return getToken(ECMAScriptParser::CloseParen, 0);
}

tree::TerminalNode* ECMAScriptParser::FunctionExpressionContext::OpenBrace() {
  return getToken(ECMAScriptParser::OpenBrace, 0);
}

ECMAScriptParser::FunctionBodyContext* ECMAScriptParser::FunctionExpressionContext::functionBody() {
  return getRuleContext<ECMAScriptParser::FunctionBodyContext>(0);
}

tree::TerminalNode* ECMAScriptParser::FunctionExpressionContext::CloseBrace() {
  return getToken(ECMAScriptParser::CloseBrace, 0);
}

tree::TerminalNode* ECMAScriptParser::FunctionExpressionContext::Identifier() {
  return getToken(ECMAScriptParser::Identifier, 0);
}

ECMAScriptParser::FormalParameterListContext* ECMAScriptParser::FunctionExpressionContext::formalParameterList() {
  return getRuleContext<ECMAScriptParser::FormalParameterListContext>(0);
}

ECMAScriptParser::FunctionExpressionContext::FunctionExpressionContext(SingleExpressionContext *ctx) { copyFrom(ctx); }


std::any ECMAScriptParser::FunctionExpressionContext::accept(tree::ParseTreeVisitor *visitor) {
  if (auto parserVisitor = dynamic_cast<ECMAScriptVisitor*>(visitor))
    return parserVisitor->visitFunctionExpression(this);
  else
    return visitor->visitChildren(this);
}
//----------------- UnaryMinusExpressionContext ------------------------------------------------------------------

tree::TerminalNode* ECMAScriptParser::UnaryMinusExpressionContext::Minus() {
  return getToken(ECMAScriptParser::Minus, 0);
}

ECMAScriptParser::SingleExpressionContext* ECMAScriptParser::UnaryMinusExpressionContext::singleExpression() {
  return getRuleContext<ECMAScriptParser::SingleExpressionContext>(0);
}

ECMAScriptParser::UnaryMinusExpressionContext::UnaryMinusExpressionContext(SingleExpressionContext *ctx) { copyFrom(ctx); }


std::any ECMAScriptParser::UnaryMinusExpressionContext::accept(tree::ParseTreeVisitor *visitor) {
  if (auto parserVisitor = dynamic_cast<ECMAScriptVisitor*>(visitor))
    return parserVisitor->visitUnaryMinusExpression(this);
  else
    return visitor->visitChildren(this);
}
//----------------- AssignmentExpressionContext ------------------------------------------------------------------

std::vector<ECMAScriptParser::SingleExpressionContext *> ECMAScriptParser::AssignmentExpressionContext::singleExpression() {
  return getRuleContexts<ECMAScriptParser::SingleExpressionContext>();
}

ECMAScriptParser::SingleExpressionContext* ECMAScriptParser::AssignmentExpressionContext::singleExpression(size_t i) {
  return getRuleContext<ECMAScriptParser::SingleExpressionContext>(i);
}

tree::TerminalNode* ECMAScriptParser::AssignmentExpressionContext::Assign() {
  return getToken(ECMAScriptParser::Assign, 0);
}

ECMAScriptParser::AssignmentExpressionContext::AssignmentExpressionContext(SingleExpressionContext *ctx) { copyFrom(ctx); }


std::any ECMAScriptParser::AssignmentExpressionContext::accept(tree::ParseTreeVisitor *visitor) {
  if (auto parserVisitor = dynamic_cast<ECMAScriptVisitor*>(visitor))
    return parserVisitor->visitAssignmentExpression(this);
  else
    return visitor->visitChildren(this);
}
//----------------- PostDecreaseExpressionContext ------------------------------------------------------------------

ECMAScriptParser::SingleExpressionContext* ECMAScriptParser::PostDecreaseExpressionContext::singleExpression() {
  return getRuleContext<ECMAScriptParser::SingleExpressionContext>(0);
}

tree::TerminalNode* ECMAScriptParser::PostDecreaseExpressionContext::MinusMinus() {
  return getToken(ECMAScriptParser::MinusMinus, 0);
}

ECMAScriptParser::PostDecreaseExpressionContext::PostDecreaseExpressionContext(SingleExpressionContext *ctx) { copyFrom(ctx); }


std::any ECMAScriptParser::PostDecreaseExpressionContext::accept(tree::ParseTreeVisitor *visitor) {
  if (auto parserVisitor = dynamic_cast<ECMAScriptVisitor*>(visitor))
    return parserVisitor->visitPostDecreaseExpression(this);
  else
    return visitor->visitChildren(this);
}
//----------------- TypeofExpressionContext ------------------------------------------------------------------

tree::TerminalNode* ECMAScriptParser::TypeofExpressionContext::Typeof() {
  return getToken(ECMAScriptParser::Typeof, 0);
}

ECMAScriptParser::SingleExpressionContext* ECMAScriptParser::TypeofExpressionContext::singleExpression() {
  return getRuleContext<ECMAScriptParser::SingleExpressionContext>(0);
}

ECMAScriptParser::TypeofExpressionContext::TypeofExpressionContext(SingleExpressionContext *ctx) { copyFrom(ctx); }


std::any ECMAScriptParser::TypeofExpressionContext::accept(tree::ParseTreeVisitor *visitor) {
  if (auto parserVisitor = dynamic_cast<ECMAScriptVisitor*>(visitor))
    return parserVisitor->visitTypeofExpression(this);
  else
    return visitor->visitChildren(this);
}
//----------------- InstanceofExpressionContext ------------------------------------------------------------------

std::vector<ECMAScriptParser::SingleExpressionContext *> ECMAScriptParser::InstanceofExpressionContext::singleExpression() {
  return getRuleContexts<ECMAScriptParser::SingleExpressionContext>();
}

ECMAScriptParser::SingleExpressionContext* ECMAScriptParser::InstanceofExpressionContext::singleExpression(size_t i) {
  return getRuleContext<ECMAScriptParser::SingleExpressionContext>(i);
}

tree::TerminalNode* ECMAScriptParser::InstanceofExpressionContext::Instanceof() {
  return getToken(ECMAScriptParser::Instanceof, 0);
}

ECMAScriptParser::InstanceofExpressionContext::InstanceofExpressionContext(SingleExpressionContext *ctx) { copyFrom(ctx); }


std::any ECMAScriptParser::InstanceofExpressionContext::accept(tree::ParseTreeVisitor *visitor) {
  if (auto parserVisitor = dynamic_cast<ECMAScriptVisitor*>(visitor))
    return parserVisitor->visitInstanceofExpression(this);
  else
    return visitor->visitChildren(this);
}
//----------------- UnaryPlusExpressionContext ------------------------------------------------------------------

tree::TerminalNode* ECMAScriptParser::UnaryPlusExpressionContext::Plus() {
  return getToken(ECMAScriptParser::Plus, 0);
}

ECMAScriptParser::SingleExpressionContext* ECMAScriptParser::UnaryPlusExpressionContext::singleExpression() {
  return getRuleContext<ECMAScriptParser::SingleExpressionContext>(0);
}

ECMAScriptParser::UnaryPlusExpressionContext::UnaryPlusExpressionContext(SingleExpressionContext *ctx) { copyFrom(ctx); }


std::any ECMAScriptParser::UnaryPlusExpressionContext::accept(tree::ParseTreeVisitor *visitor) {
  if (auto parserVisitor = dynamic_cast<ECMAScriptVisitor*>(visitor))
    return parserVisitor->visitUnaryPlusExpression(this);
  else
    return visitor->visitChildren(this);
}
//----------------- DeleteExpressionContext ------------------------------------------------------------------

tree::TerminalNode* ECMAScriptParser::DeleteExpressionContext::Delete() {
  return getToken(ECMAScriptParser::Delete, 0);
}

ECMAScriptParser::SingleExpressionContext* ECMAScriptParser::DeleteExpressionContext::singleExpression() {
  return getRuleContext<ECMAScriptParser::SingleExpressionContext>(0);
}

ECMAScriptParser::DeleteExpressionContext::DeleteExpressionContext(SingleExpressionContext *ctx) { copyFrom(ctx); }


std::any ECMAScriptParser::DeleteExpressionContext::accept(tree::ParseTreeVisitor *visitor) {
  if (auto parserVisitor = dynamic_cast<ECMAScriptVisitor*>(visitor))
    return parserVisitor->visitDeleteExpression(this);
  else
    return visitor->visitChildren(this);
}
//----------------- EqualityExpressionContext ------------------------------------------------------------------

std::vector<ECMAScriptParser::SingleExpressionContext *> ECMAScriptParser::EqualityExpressionContext::singleExpression() {
  return getRuleContexts<ECMAScriptParser::SingleExpressionContext>();
}

ECMAScriptParser::SingleExpressionContext* ECMAScriptParser::EqualityExpressionContext::singleExpression(size_t i) {
  return getRuleContext<ECMAScriptParser::SingleExpressionContext>(i);
}

tree::TerminalNode* ECMAScriptParser::EqualityExpressionContext::Equals_() {
  return getToken(ECMAScriptParser::Equals_, 0);
}

tree::TerminalNode* ECMAScriptParser::EqualityExpressionContext::NotEquals() {
  return getToken(ECMAScriptParser::NotEquals, 0);
}

tree::TerminalNode* ECMAScriptParser::EqualityExpressionContext::IdentityEquals() {
  return getToken(ECMAScriptParser::IdentityEquals, 0);
}

tree::TerminalNode* ECMAScriptParser::EqualityExpressionContext::IdentityNotEquals() {
  return getToken(ECMAScriptParser::IdentityNotEquals, 0);
}

ECMAScriptParser::EqualityExpressionContext::EqualityExpressionContext(SingleExpressionContext *ctx) { copyFrom(ctx); }


std::any ECMAScriptParser::EqualityExpressionContext::accept(tree::ParseTreeVisitor *visitor) {
  if (auto parserVisitor = dynamic_cast<ECMAScriptVisitor*>(visitor))
    return parserVisitor->visitEqualityExpression(this);
  else
    return visitor->visitChildren(this);
}
//----------------- BitXOrExpressionContext ------------------------------------------------------------------

std::vector<ECMAScriptParser::SingleExpressionContext *> ECMAScriptParser::BitXOrExpressionContext::singleExpression() {
  return getRuleContexts<ECMAScriptParser::SingleExpressionContext>();
}

ECMAScriptParser::SingleExpressionContext* ECMAScriptParser::BitXOrExpressionContext::singleExpression(size_t i) {
  return getRuleContext<ECMAScriptParser::SingleExpressionContext>(i);
}

tree::TerminalNode* ECMAScriptParser::BitXOrExpressionContext::BitXOr() {
  return getToken(ECMAScriptParser::BitXOr, 0);
}

ECMAScriptParser::BitXOrExpressionContext::BitXOrExpressionContext(SingleExpressionContext *ctx) { copyFrom(ctx); }


std::any ECMAScriptParser::BitXOrExpressionContext::accept(tree::ParseTreeVisitor *visitor) {
  if (auto parserVisitor = dynamic_cast<ECMAScriptVisitor*>(visitor))
    return parserVisitor->visitBitXOrExpression(this);
  else
    return visitor->visitChildren(this);
}
//----------------- MultiplicativeExpressionContext ------------------------------------------------------------------

std::vector<ECMAScriptParser::SingleExpressionContext *> ECMAScriptParser::MultiplicativeExpressionContext::singleExpression() {
  return getRuleContexts<ECMAScriptParser::SingleExpressionContext>();
}

ECMAScriptParser::SingleExpressionContext* ECMAScriptParser::MultiplicativeExpressionContext::singleExpression(size_t i) {
  return getRuleContext<ECMAScriptParser::SingleExpressionContext>(i);
}

tree::TerminalNode* ECMAScriptParser::MultiplicativeExpressionContext::Multiply() {
  return getToken(ECMAScriptParser::Multiply, 0);
}

tree::TerminalNode* ECMAScriptParser::MultiplicativeExpressionContext::Divide() {
  return getToken(ECMAScriptParser::Divide, 0);
}

tree::TerminalNode* ECMAScriptParser::MultiplicativeExpressionContext::Modulus() {
  return getToken(ECMAScriptParser::Modulus, 0);
}

ECMAScriptParser::MultiplicativeExpressionContext::MultiplicativeExpressionContext(SingleExpressionContext *ctx) { copyFrom(ctx); }


std::any ECMAScriptParser::MultiplicativeExpressionContext::accept(tree::ParseTreeVisitor *visitor) {
  if (auto parserVisitor = dynamic_cast<ECMAScriptVisitor*>(visitor))
    return parserVisitor->visitMultiplicativeExpression(this);
  else
    return visitor->visitChildren(this);
}
//----------------- BitShiftExpressionContext ------------------------------------------------------------------

std::vector<ECMAScriptParser::SingleExpressionContext *> ECMAScriptParser::BitShiftExpressionContext::singleExpression() {
  return getRuleContexts<ECMAScriptParser::SingleExpressionContext>();
}

ECMAScriptParser::SingleExpressionContext* ECMAScriptParser::BitShiftExpressionContext::singleExpression(size_t i) {
  return getRuleContext<ECMAScriptParser::SingleExpressionContext>(i);
}

tree::TerminalNode* ECMAScriptParser::BitShiftExpressionContext::LeftShiftArithmetic() {
  return getToken(ECMAScriptParser::LeftShiftArithmetic, 0);
}

tree::TerminalNode* ECMAScriptParser::BitShiftExpressionContext::RightShiftArithmetic() {
  return getToken(ECMAScriptParser::RightShiftArithmetic, 0);
}

tree::TerminalNode* ECMAScriptParser::BitShiftExpressionContext::RightShiftLogical() {
  return getToken(ECMAScriptParser::RightShiftLogical, 0);
}

ECMAScriptParser::BitShiftExpressionContext::BitShiftExpressionContext(SingleExpressionContext *ctx) { copyFrom(ctx); }


std::any ECMAScriptParser::BitShiftExpressionContext::accept(tree::ParseTreeVisitor *visitor) {
  if (auto parserVisitor = dynamic_cast<ECMAScriptVisitor*>(visitor))
    return parserVisitor->visitBitShiftExpression(this);
  else
    return visitor->visitChildren(this);
}
//----------------- ParenthesizedExpressionContext ------------------------------------------------------------------

tree::TerminalNode* ECMAScriptParser::ParenthesizedExpressionContext::OpenParen() {
  return getToken(ECMAScriptParser::OpenParen, 0);
}

ECMAScriptParser::ExpressionSequenceContext* ECMAScriptParser::ParenthesizedExpressionContext::expressionSequence() {
  return getRuleContext<ECMAScriptParser::ExpressionSequenceContext>(0);
}

tree::TerminalNode* ECMAScriptParser::ParenthesizedExpressionContext::CloseParen() {
  return getToken(ECMAScriptParser::CloseParen, 0);
}

ECMAScriptParser::ParenthesizedExpressionContext::ParenthesizedExpressionContext(SingleExpressionContext *ctx) { copyFrom(ctx); }


std::any ECMAScriptParser::ParenthesizedExpressionContext::accept(tree::ParseTreeVisitor *visitor) {
  if (auto parserVisitor = dynamic_cast<ECMAScriptVisitor*>(visitor))
    return parserVisitor->visitParenthesizedExpression(this);
  else
    return visitor->visitChildren(this);
}
//----------------- AdditiveExpressionContext ------------------------------------------------------------------

std::vector<ECMAScriptParser::SingleExpressionContext *> ECMAScriptParser::AdditiveExpressionContext::singleExpression() {
  return getRuleContexts<ECMAScriptParser::SingleExpressionContext>();
}

ECMAScriptParser::SingleExpressionContext* ECMAScriptParser::AdditiveExpressionContext::singleExpression(size_t i) {
  return getRuleContext<ECMAScriptParser::SingleExpressionContext>(i);
}

tree::TerminalNode* ECMAScriptParser::AdditiveExpressionContext::Plus() {
  return getToken(ECMAScriptParser::Plus, 0);
}

tree::TerminalNode* ECMAScriptParser::AdditiveExpressionContext::Minus() {
  return getToken(ECMAScriptParser::Minus, 0);
}

ECMAScriptParser::AdditiveExpressionContext::AdditiveExpressionContext(SingleExpressionContext *ctx) { copyFrom(ctx); }


std::any ECMAScriptParser::AdditiveExpressionContext::accept(tree::ParseTreeVisitor *visitor) {
  if (auto parserVisitor = dynamic_cast<ECMAScriptVisitor*>(visitor))
    return parserVisitor->visitAdditiveExpression(this);
  else
    return visitor->visitChildren(this);
}
//----------------- RelationalExpressionContext ------------------------------------------------------------------

std::vector<ECMAScriptParser::SingleExpressionContext *> ECMAScriptParser::RelationalExpressionContext::singleExpression() {
  return getRuleContexts<ECMAScriptParser::SingleExpressionContext>();
}

ECMAScriptParser::SingleExpressionContext* ECMAScriptParser::RelationalExpressionContext::singleExpression(size_t i) {
  return getRuleContext<ECMAScriptParser::SingleExpressionContext>(i);
}

tree::TerminalNode* ECMAScriptParser::RelationalExpressionContext::LessThan() {
  return getToken(ECMAScriptParser::LessThan, 0);
}

tree::TerminalNode* ECMAScriptParser::RelationalExpressionContext::MoreThan() {
  return getToken(ECMAScriptParser::MoreThan, 0);
}

tree::TerminalNode* ECMAScriptParser::RelationalExpressionContext::LessThanEquals() {
  return getToken(ECMAScriptParser::LessThanEquals, 0);
}

tree::TerminalNode* ECMAScriptParser::RelationalExpressionContext::GreaterThanEquals() {
  return getToken(ECMAScriptParser::GreaterThanEquals, 0);
}

ECMAScriptParser::RelationalExpressionContext::RelationalExpressionContext(SingleExpressionContext *ctx) { copyFrom(ctx); }


std::any ECMAScriptParser::RelationalExpressionContext::accept(tree::ParseTreeVisitor *visitor) {
  if (auto parserVisitor = dynamic_cast<ECMAScriptVisitor*>(visitor))
    return parserVisitor->visitRelationalExpression(this);
  else
    return visitor->visitChildren(this);
}
//----------------- PostIncrementExpressionContext ------------------------------------------------------------------

ECMAScriptParser::SingleExpressionContext* ECMAScriptParser::PostIncrementExpressionContext::singleExpression() {
  return getRuleContext<ECMAScriptParser::SingleExpressionContext>(0);
}

tree::TerminalNode* ECMAScriptParser::PostIncrementExpressionContext::PlusPlus() {
  return getToken(ECMAScriptParser::PlusPlus, 0);
}

ECMAScriptParser::PostIncrementExpressionContext::PostIncrementExpressionContext(SingleExpressionContext *ctx) { copyFrom(ctx); }


std::any ECMAScriptParser::PostIncrementExpressionContext::accept(tree::ParseTreeVisitor *visitor) {
  if (auto parserVisitor = dynamic_cast<ECMAScriptVisitor*>(visitor))
    return parserVisitor->visitPostIncrementExpression(this);
  else
    return visitor->visitChildren(this);
}
//----------------- BitNotExpressionContext ------------------------------------------------------------------

tree::TerminalNode* ECMAScriptParser::BitNotExpressionContext::BitNot() {
  return getToken(ECMAScriptParser::BitNot, 0);
}

ECMAScriptParser::SingleExpressionContext* ECMAScriptParser::BitNotExpressionContext::singleExpression() {
  return getRuleContext<ECMAScriptParser::SingleExpressionContext>(0);
}

ECMAScriptParser::BitNotExpressionContext::BitNotExpressionContext(SingleExpressionContext *ctx) { copyFrom(ctx); }


std::any ECMAScriptParser::BitNotExpressionContext::accept(tree::ParseTreeVisitor *visitor) {
  if (auto parserVisitor = dynamic_cast<ECMAScriptVisitor*>(visitor))
    return parserVisitor->visitBitNotExpression(this);
  else
    return visitor->visitChildren(this);
}
//----------------- NewExpressionContext ------------------------------------------------------------------

tree::TerminalNode* ECMAScriptParser::NewExpressionContext::New() {
  return getToken(ECMAScriptParser::New, 0);
}

ECMAScriptParser::SingleExpressionContext* ECMAScriptParser::NewExpressionContext::singleExpression() {
  return getRuleContext<ECMAScriptParser::SingleExpressionContext>(0);
}

ECMAScriptParser::ArgumentsContext* ECMAScriptParser::NewExpressionContext::arguments() {
  return getRuleContext<ECMAScriptParser::ArgumentsContext>(0);
}

ECMAScriptParser::NewExpressionContext::NewExpressionContext(SingleExpressionContext *ctx) { copyFrom(ctx); }


std::any ECMAScriptParser::NewExpressionContext::accept(tree::ParseTreeVisitor *visitor) {
  if (auto parserVisitor = dynamic_cast<ECMAScriptVisitor*>(visitor))
    return parserVisitor->visitNewExpression(this);
  else
    return visitor->visitChildren(this);
}
//----------------- LiteralExpressionContext ------------------------------------------------------------------

ECMAScriptParser::LiteralContext* ECMAScriptParser::LiteralExpressionContext::literal() {
  return getRuleContext<ECMAScriptParser::LiteralContext>(0);
}

ECMAScriptParser::LiteralExpressionContext::LiteralExpressionContext(SingleExpressionContext *ctx) { copyFrom(ctx); }


std::any ECMAScriptParser::LiteralExpressionContext::accept(tree::ParseTreeVisitor *visitor) {
  if (auto parserVisitor = dynamic_cast<ECMAScriptVisitor*>(visitor))
    return parserVisitor->visitLiteralExpression(this);
  else
    return visitor->visitChildren(this);
}
//----------------- ArrayLiteralExpressionContext ------------------------------------------------------------------

ECMAScriptParser::ArrayLiteralContext* ECMAScriptParser::ArrayLiteralExpressionContext::arrayLiteral() {
  return getRuleContext<ECMAScriptParser::ArrayLiteralContext>(0);
}

ECMAScriptParser::ArrayLiteralExpressionContext::ArrayLiteralExpressionContext(SingleExpressionContext *ctx) { copyFrom(ctx); }


std::any ECMAScriptParser::ArrayLiteralExpressionContext::accept(tree::ParseTreeVisitor *visitor) {
  if (auto parserVisitor = dynamic_cast<ECMAScriptVisitor*>(visitor))
    return parserVisitor->visitArrayLiteralExpression(this);
  else
    return visitor->visitChildren(this);
}
//----------------- MemberDotExpressionContext ------------------------------------------------------------------

ECMAScriptParser::SingleExpressionContext* ECMAScriptParser::MemberDotExpressionContext::singleExpression() {
  return getRuleContext<ECMAScriptParser::SingleExpressionContext>(0);
}

tree::TerminalNode* ECMAScriptParser::MemberDotExpressionContext::Dot() {
  return getToken(ECMAScriptParser::Dot, 0);
}

ECMAScriptParser::IdentifierNameContext* ECMAScriptParser::MemberDotExpressionContext::identifierName() {
  return getRuleContext<ECMAScriptParser::IdentifierNameContext>(0);
}

ECMAScriptParser::MemberDotExpressionContext::MemberDotExpressionContext(SingleExpressionContext *ctx) { copyFrom(ctx); }


std::any ECMAScriptParser::MemberDotExpressionContext::accept(tree::ParseTreeVisitor *visitor) {
  if (auto parserVisitor = dynamic_cast<ECMAScriptVisitor*>(visitor))
    return parserVisitor->visitMemberDotExpression(this);
  else
    return visitor->visitChildren(this);
}
//----------------- MemberIndexExpressionContext ------------------------------------------------------------------

ECMAScriptParser::SingleExpressionContext* ECMAScriptParser::MemberIndexExpressionContext::singleExpression() {
  return getRuleContext<ECMAScriptParser::SingleExpressionContext>(0);
}

tree::TerminalNode* ECMAScriptParser::MemberIndexExpressionContext::OpenBracket() {
  return getToken(ECMAScriptParser::OpenBracket, 0);
}

ECMAScriptParser::ExpressionSequenceContext* ECMAScriptParser::MemberIndexExpressionContext::expressionSequence() {
  return getRuleContext<ECMAScriptParser::ExpressionSequenceContext>(0);
}

tree::TerminalNode* ECMAScriptParser::MemberIndexExpressionContext::CloseBracket() {
  return getToken(ECMAScriptParser::CloseBracket, 0);
}

ECMAScriptParser::MemberIndexExpressionContext::MemberIndexExpressionContext(SingleExpressionContext *ctx) { copyFrom(ctx); }


std::any ECMAScriptParser::MemberIndexExpressionContext::accept(tree::ParseTreeVisitor *visitor) {
  if (auto parserVisitor = dynamic_cast<ECMAScriptVisitor*>(visitor))
    return parserVisitor->visitMemberIndexExpression(this);
  else
    return visitor->visitChildren(this);
}
//----------------- IdentifierExpressionContext ------------------------------------------------------------------

tree::TerminalNode* ECMAScriptParser::IdentifierExpressionContext::Identifier() {
  return getToken(ECMAScriptParser::Identifier, 0);
}

ECMAScriptParser::IdentifierExpressionContext::IdentifierExpressionContext(SingleExpressionContext *ctx) { copyFrom(ctx); }


std::any ECMAScriptParser::IdentifierExpressionContext::accept(tree::ParseTreeVisitor *visitor) {
  if (auto parserVisitor = dynamic_cast<ECMAScriptVisitor*>(visitor))
    return parserVisitor->visitIdentifierExpression(this);
  else
    return visitor->visitChildren(this);
}
//----------------- BitAndExpressionContext ------------------------------------------------------------------

std::vector<ECMAScriptParser::SingleExpressionContext *> ECMAScriptParser::BitAndExpressionContext::singleExpression() {
  return getRuleContexts<ECMAScriptParser::SingleExpressionContext>();
}

ECMAScriptParser::SingleExpressionContext* ECMAScriptParser::BitAndExpressionContext::singleExpression(size_t i) {
  return getRuleContext<ECMAScriptParser::SingleExpressionContext>(i);
}

tree::TerminalNode* ECMAScriptParser::BitAndExpressionContext::BitAnd() {
  return getToken(ECMAScriptParser::BitAnd, 0);
}

ECMAScriptParser::BitAndExpressionContext::BitAndExpressionContext(SingleExpressionContext *ctx) { copyFrom(ctx); }


std::any ECMAScriptParser::BitAndExpressionContext::accept(tree::ParseTreeVisitor *visitor) {
  if (auto parserVisitor = dynamic_cast<ECMAScriptVisitor*>(visitor))
    return parserVisitor->visitBitAndExpression(this);
  else
    return visitor->visitChildren(this);
}
//----------------- BitOrExpressionContext ------------------------------------------------------------------

std::vector<ECMAScriptParser::SingleExpressionContext *> ECMAScriptParser::BitOrExpressionContext::singleExpression() {
  return getRuleContexts<ECMAScriptParser::SingleExpressionContext>();
}

ECMAScriptParser::SingleExpressionContext* ECMAScriptParser::BitOrExpressionContext::singleExpression(size_t i) {
  return getRuleContext<ECMAScriptParser::SingleExpressionContext>(i);
}

tree::TerminalNode* ECMAScriptParser::BitOrExpressionContext::BitOr() {
  return getToken(ECMAScriptParser::BitOr, 0);
}

ECMAScriptParser::BitOrExpressionContext::BitOrExpressionContext(SingleExpressionContext *ctx) { copyFrom(ctx); }


std::any ECMAScriptParser::BitOrExpressionContext::accept(tree::ParseTreeVisitor *visitor) {
  if (auto parserVisitor = dynamic_cast<ECMAScriptVisitor*>(visitor))
    return parserVisitor->visitBitOrExpression(this);
  else
    return visitor->visitChildren(this);
}
//----------------- AssignmentOperatorExpressionContext ------------------------------------------------------------------

std::vector<ECMAScriptParser::SingleExpressionContext *> ECMAScriptParser::AssignmentOperatorExpressionContext::singleExpression() {
  return getRuleContexts<ECMAScriptParser::SingleExpressionContext>();
}

ECMAScriptParser::SingleExpressionContext* ECMAScriptParser::AssignmentOperatorExpressionContext::singleExpression(size_t i) {
  return getRuleContext<ECMAScriptParser::SingleExpressionContext>(i);
}

ECMAScriptParser::AssignmentOperatorContext* ECMAScriptParser::AssignmentOperatorExpressionContext::assignmentOperator() {
  return getRuleContext<ECMAScriptParser::AssignmentOperatorContext>(0);
}

ECMAScriptParser::AssignmentOperatorExpressionContext::AssignmentOperatorExpressionContext(SingleExpressionContext *ctx) { copyFrom(ctx); }


std::any ECMAScriptParser::AssignmentOperatorExpressionContext::accept(tree::ParseTreeVisitor *visitor) {
  if (auto parserVisitor = dynamic_cast<ECMAScriptVisitor*>(visitor))
    return parserVisitor->visitAssignmentOperatorExpression(this);
  else
    return visitor->visitChildren(this);
}
//----------------- VoidExpressionContext ------------------------------------------------------------------

tree::TerminalNode* ECMAScriptParser::VoidExpressionContext::Void() {
  return getToken(ECMAScriptParser::Void, 0);
}

ECMAScriptParser::SingleExpressionContext* ECMAScriptParser::VoidExpressionContext::singleExpression() {
  return getRuleContext<ECMAScriptParser::SingleExpressionContext>(0);
}

ECMAScriptParser::VoidExpressionContext::VoidExpressionContext(SingleExpressionContext *ctx) { copyFrom(ctx); }


std::any ECMAScriptParser::VoidExpressionContext::accept(tree::ParseTreeVisitor *visitor) {
  if (auto parserVisitor = dynamic_cast<ECMAScriptVisitor*>(visitor))
    return parserVisitor->visitVoidExpression(this);
  else
    return visitor->visitChildren(this);
}

ECMAScriptParser::SingleExpressionContext* ECMAScriptParser::singleExpression() {
   return singleExpression(0);
}

ECMAScriptParser::SingleExpressionContext* ECMAScriptParser::singleExpression(int precedence) {
  ParserRuleContext *parentContext = _ctx;
  size_t parentState = getState();
  ECMAScriptParser::SingleExpressionContext *_localctx = _tracker.createInstance<SingleExpressionContext>(_ctx, parentState);
  ECMAScriptParser::SingleExpressionContext *previousContext = _localctx;
  (void)previousContext; // Silence compiler, in case the context is not used by generated code.
  size_t startState = 86;
  enterRecursionRule(_localctx, 86, ECMAScriptParser::RuleSingleExpression, precedence);

    size_t _la = 0;

#if __cplusplus > 201703L
  auto onExit = finally([=, this] {
#else
  auto onExit = finally([=] {
#endif
    unrollRecursionContexts(parentContext);
  });
  try {
    size_t alt;
    enterOuterAlt(_localctx, 1);
    setState(542);
    _errHandler->sync(this);
    switch (_input->LA(1)) {
      case ECMAScriptParser::Function: {
        _localctx = _tracker.createInstance<FunctionExpressionContext>(_localctx);
        _ctx = _localctx;
        previousContext = _localctx;

        setState(497);
        match(ECMAScriptParser::Function);
        setState(499);
        _errHandler->sync(this);

        _la = _input->LA(1);
        if (_la == ECMAScriptParser::Identifier) {
          setState(498);
          match(ECMAScriptParser::Identifier);
        }
        setState(501);
        match(ECMAScriptParser::OpenParen);
        setState(503);
        _errHandler->sync(this);

        _la = _input->LA(1);
        if (_la == ECMAScriptParser::Identifier) {
          setState(502);
          formalParameterList();
        }
        setState(505);
        match(ECMAScriptParser::CloseParen);
        setState(506);
        match(ECMAScriptParser::OpenBrace);
        setState(507);
        functionBody();
        setState(508);
        match(ECMAScriptParser::CloseBrace);
        break;
      }

      case ECMAScriptParser::New: {
        _localctx = _tracker.createInstance<NewExpressionContext>(_localctx);
        _ctx = _localctx;
        previousContext = _localctx;
        setState(510);
        match(ECMAScriptParser::New);
        setState(511);
        singleExpression(0);
        setState(513);
        _errHandler->sync(this);

        switch (getInterpreter<atn::ParserATNSimulator>()->adaptivePredict(_input, 48, _ctx)) {
        case 1: {
          setState(512);
          arguments();
          break;
        }

        default:
          break;
        }
        break;
      }

      case ECMAScriptParser::Delete: {
        _localctx = _tracker.createInstance<DeleteExpressionContext>(_localctx);
        _ctx = _localctx;
        previousContext = _localctx;
        setState(515);
        match(ECMAScriptParser::Delete);
        setState(516);
        singleExpression(30);
        break;
      }

      case ECMAScriptParser::Void: {
        _localctx = _tracker.createInstance<VoidExpressionContext>(_localctx);
        _ctx = _localctx;
        previousContext = _localctx;
        setState(517);
        match(ECMAScriptParser::Void);
        setState(518);
        singleExpression(29);
        break;
      }

      case ECMAScriptParser::Typeof: {
        _localctx = _tracker.createInstance<TypeofExpressionContext>(_localctx);
        _ctx = _localctx;
        previousContext = _localctx;
        setState(519);
        match(ECMAScriptParser::Typeof);
        setState(520);
        singleExpression(28);
        break;
      }

      case ECMAScriptParser::PlusPlus: {
        _localctx = _tracker.createInstance<PreIncrementExpressionContext>(_localctx);
        _ctx = _localctx;
        previousContext = _localctx;
        setState(521);
        match(ECMAScriptParser::PlusPlus);
        setState(522);
        singleExpression(27);
        break;
      }

      case ECMAScriptParser::MinusMinus: {
        _localctx = _tracker.createInstance<PreDecreaseExpressionContext>(_localctx);
        _ctx = _localctx;
        previousContext = _localctx;
        setState(523);
        match(ECMAScriptParser::MinusMinus);
        setState(524);
        singleExpression(26);
        break;
      }

      case ECMAScriptParser::Plus: {
        _localctx = _tracker.createInstance<UnaryPlusExpressionContext>(_localctx);
        _ctx = _localctx;
        previousContext = _localctx;
        setState(525);
        match(ECMAScriptParser::Plus);
        setState(526);
        singleExpression(25);
        break;
      }

      case ECMAScriptParser::Minus: {
        _localctx = _tracker.createInstance<UnaryMinusExpressionContext>(_localctx);
        _ctx = _localctx;
        previousContext = _localctx;
        setState(527);
        match(ECMAScriptParser::Minus);
        setState(528);
        singleExpression(24);
        break;
      }

      case ECMAScriptParser::BitNot: {
        _localctx = _tracker.createInstance<BitNotExpressionContext>(_localctx);
        _ctx = _localctx;
        previousContext = _localctx;
        setState(529);
        match(ECMAScriptParser::BitNot);
        setState(530);
        singleExpression(23);
        break;
      }

      case ECMAScriptParser::Not: {
        _localctx = _tracker.createInstance<NotExpressionContext>(_localctx);
        _ctx = _localctx;
        previousContext = _localctx;
        setState(531);
        match(ECMAScriptParser::Not);
        setState(532);
        singleExpression(22);
        break;
      }

      case ECMAScriptParser::This: {
        _localctx = _tracker.createInstance<ThisExpressionContext>(_localctx);
        _ctx = _localctx;
        previousContext = _localctx;
        setState(533);
        match(ECMAScriptParser::This);
        break;
      }

      case ECMAScriptParser::Identifier: {
        _localctx = _tracker.createInstance<IdentifierExpressionContext>(_localctx);
        _ctx = _localctx;
        previousContext = _localctx;
        setState(534);
        match(ECMAScriptParser::Identifier);
        break;
      }

      case ECMAScriptParser::RegularExpressionLiteral:
      case ECMAScriptParser::NullLiteral:
      case ECMAScriptParser::BooleanLiteral:
      case ECMAScriptParser::DecimalLiteral:
      case ECMAScriptParser::HexIntegerLiteral:
      case ECMAScriptParser::OctalIntegerLiteral:
      case ECMAScriptParser::StringLiteral: {
        _localctx = _tracker.createInstance<LiteralExpressionContext>(_localctx);
        _ctx = _localctx;
        previousContext = _localctx;
        setState(535);
        literal();
        break;
      }

      case ECMAScriptParser::OpenBracket: {
        _localctx = _tracker.createInstance<ArrayLiteralExpressionContext>(_localctx);
        _ctx = _localctx;
        previousContext = _localctx;
        setState(536);
        arrayLiteral();
        break;
      }

      case ECMAScriptParser::OpenBrace: {
        _localctx = _tracker.createInstance<ObjectLiteralExpressionContext>(_localctx);
        _ctx = _localctx;
        previousContext = _localctx;
        setState(537);
        objectLiteral();
        break;
      }

      case ECMAScriptParser::OpenParen: {
        _localctx = _tracker.createInstance<ParenthesizedExpressionContext>(_localctx);
        _ctx = _localctx;
        previousContext = _localctx;
        setState(538);
        match(ECMAScriptParser::OpenParen);
        setState(539);
        expressionSequence();
        setState(540);
        match(ECMAScriptParser::CloseParen);
        break;
      }

    default:
      throw NoViableAltException(this);
    }
    _ctx->stop = _input->LT(-1);
    setState(611);
    _errHandler->sync(this);
    alt = getInterpreter<atn::ParserATNSimulator>()->adaptivePredict(_input, 51, _ctx);
    while (alt != 2 && alt != atn::ATN::INVALID_ALT_NUMBER) {
      if (alt == 1) {
        if (!_parseListeners.empty())
          triggerExitRuleEvent();
        previousContext = _localctx;
        setState(609);
        _errHandler->sync(this);
        switch (getInterpreter<atn::ParserATNSimulator>()->adaptivePredict(_input, 50, _ctx)) {
        case 1: {
          auto newContext = _tracker.createInstance<MultiplicativeExpressionContext>(_tracker.createInstance<SingleExpressionContext>(parentContext, parentState));
          _localctx = newContext;
          pushNewRecursionContext(newContext, startState, RuleSingleExpression);
          setState(544);

          if (!(precpred(_ctx, 21))) throw FailedPredicateException(this, "precpred(_ctx, 21)");
          setState(545);
          _la = _input->LA(1);
          if (!((((_la & ~ 0x3fULL) == 0) &&
            ((1ULL << _la) & 14680064) != 0))) {
          _errHandler->recoverInline(this);
          }
          else {
            _errHandler->reportMatch(this);
            consume();
          }
          setState(546);
          singleExpression(22);
          break;
        }

        case 2: {
          auto newContext = _tracker.createInstance<AdditiveExpressionContext>(_tracker.createInstance<SingleExpressionContext>(parentContext, parentState));
          _localctx = newContext;
          pushNewRecursionContext(newContext, startState, RuleSingleExpression);
          setState(547);

          if (!(precpred(_ctx, 20))) throw FailedPredicateException(this, "precpred(_ctx, 20)");
          setState(548);
          _la = _input->LA(1);
          if (!(_la == ECMAScriptParser::Plus

          || _la == ECMAScriptParser::Minus)) {
          _errHandler->recoverInline(this);
          }
          else {
            _errHandler->reportMatch(this);
            consume();
          }
          setState(549);
          singleExpression(21);
          break;
        }

        case 3: {
          auto newContext = _tracker.createInstance<BitShiftExpressionContext>(_tracker.createInstance<SingleExpressionContext>(parentContext, parentState));
          _localctx = newContext;
          pushNewRecursionContext(newContext, startState, RuleSingleExpression);
          setState(550);

          if (!(precpred(_ctx, 19))) throw FailedPredicateException(this, "precpred(_ctx, 19)");
          setState(551);
          _la = _input->LA(1);
          if (!((((_la & ~ 0x3fULL) == 0) &&
            ((1ULL << _la) & 117440512) != 0))) {
          _errHandler->recoverInline(this);
          }
          else {
            _errHandler->reportMatch(this);
            consume();
          }
          setState(552);
          singleExpression(20);
          break;
        }

        case 4: {
          auto newContext = _tracker.createInstance<RelationalExpressionContext>(_tracker.createInstance<SingleExpressionContext>(parentContext, parentState));
          _localctx = newContext;
          pushNewRecursionContext(newContext, startState, RuleSingleExpression);
          setState(553);

          if (!(precpred(_ctx, 18))) throw FailedPredicateException(this, "precpred(_ctx, 18)");
          setState(554);
          _la = _input->LA(1);
          if (!((((_la & ~ 0x3fULL) == 0) &&
            ((1ULL << _la) & 2013265920) != 0))) {
          _errHandler->recoverInline(this);
          }
          else {
            _errHandler->reportMatch(this);
            consume();
          }
          setState(555);
          singleExpression(19);
          break;
        }

        case 5: {
          auto newContext = _tracker.createInstance<InstanceofExpressionContext>(_tracker.createInstance<SingleExpressionContext>(parentContext, parentState));
          _localctx = newContext;
          pushNewRecursionContext(newContext, startState, RuleSingleExpression);
          setState(556);

          if (!(precpred(_ctx, 17))) throw FailedPredicateException(this, "precpred(_ctx, 17)");
          setState(557);
          match(ECMAScriptParser::Instanceof);
          setState(558);
          singleExpression(18);
          break;
        }

        case 6: {
          auto newContext = _tracker.createInstance<InExpressionContext>(_tracker.createInstance<SingleExpressionContext>(parentContext, parentState));
          _localctx = newContext;
          pushNewRecursionContext(newContext, startState, RuleSingleExpression);
          setState(559);

          if (!(precpred(_ctx, 16))) throw FailedPredicateException(this, "precpred(_ctx, 16)");
          setState(560);
          match(ECMAScriptParser::In);
          setState(561);
          singleExpression(17);
          break;
        }

        case 7: {
          auto newContext = _tracker.createInstance<EqualityExpressionContext>(_tracker.createInstance<SingleExpressionContext>(parentContext, parentState));
          _localctx = newContext;
          pushNewRecursionContext(newContext, startState, RuleSingleExpression);
          setState(562);

          if (!(precpred(_ctx, 15))) throw FailedPredicateException(this, "precpred(_ctx, 15)");
          setState(563);
          _la = _input->LA(1);
          if (!((((_la & ~ 0x3fULL) == 0) &&
            ((1ULL << _la) & 32212254720) != 0))) {
          _errHandler->recoverInline(this);
          }
          else {
            _errHandler->reportMatch(this);
            consume();
          }
          setState(564);
          singleExpression(16);
          break;
        }

        case 8: {
          auto newContext = _tracker.createInstance<BitAndExpressionContext>(_tracker.createInstance<SingleExpressionContext>(parentContext, parentState));
          _localctx = newContext;
          pushNewRecursionContext(newContext, startState, RuleSingleExpression);
          setState(565);

          if (!(precpred(_ctx, 14))) throw FailedPredicateException(this, "precpred(_ctx, 14)");
          setState(566);
          match(ECMAScriptParser::BitAnd);
          setState(567);
          singleExpression(15);
          break;
        }

        case 9: {
          auto newContext = _tracker.createInstance<BitXOrExpressionContext>(_tracker.createInstance<SingleExpressionContext>(parentContext, parentState));
          _localctx = newContext;
          pushNewRecursionContext(newContext, startState, RuleSingleExpression);
          setState(568);

          if (!(precpred(_ctx, 13))) throw FailedPredicateException(this, "precpred(_ctx, 13)");
          setState(569);
          match(ECMAScriptParser::BitXOr);
          setState(570);
          singleExpression(14);
          break;
        }

        case 10: {
          auto newContext = _tracker.createInstance<BitOrExpressionContext>(_tracker.createInstance<SingleExpressionContext>(parentContext, parentState));
          _localctx = newContext;
          pushNewRecursionContext(newContext, startState, RuleSingleExpression);
          setState(571);

          if (!(precpred(_ctx, 12))) throw FailedPredicateException(this, "precpred(_ctx, 12)");
          setState(572);
          match(ECMAScriptParser::BitOr);
          setState(573);
          singleExpression(13);
          break;
        }

        case 11: {
          auto newContext = _tracker.createInstance<LogicalAndExpressionContext>(_tracker.createInstance<SingleExpressionContext>(parentContext, parentState));
          _localctx = newContext;
          pushNewRecursionContext(newContext, startState, RuleSingleExpression);
          setState(574);

          if (!(precpred(_ctx, 11))) throw FailedPredicateException(this, "precpred(_ctx, 11)");
          setState(575);
          match(ECMAScriptParser::And);
          setState(576);
          singleExpression(12);
          break;
        }

        case 12: {
          auto newContext = _tracker.createInstance<LogicalOrExpressionContext>(_tracker.createInstance<SingleExpressionContext>(parentContext, parentState));
          _localctx = newContext;
          pushNewRecursionContext(newContext, startState, RuleSingleExpression);
          setState(577);

          if (!(precpred(_ctx, 10))) throw FailedPredicateException(this, "precpred(_ctx, 10)");
          setState(578);
          match(ECMAScriptParser::Or);
          setState(579);
          singleExpression(11);
          break;
        }

        case 13: {
          auto newContext = _tracker.createInstance<TernaryExpressionContext>(_tracker.createInstance<SingleExpressionContext>(parentContext, parentState));
          _localctx = newContext;
          pushNewRecursionContext(newContext, startState, RuleSingleExpression);
          setState(580);

          if (!(precpred(_ctx, 9))) throw FailedPredicateException(this, "precpred(_ctx, 9)");
          setState(581);
          match(ECMAScriptParser::QuestionMark);
          setState(582);
          singleExpression(0);
          setState(583);
          match(ECMAScriptParser::Colon);
          setState(584);
          singleExpression(10);
          break;
        }

        case 14: {
          auto newContext = _tracker.createInstance<AssignmentExpressionContext>(_tracker.createInstance<SingleExpressionContext>(parentContext, parentState));
          _localctx = newContext;
          pushNewRecursionContext(newContext, startState, RuleSingleExpression);
          setState(586);

          if (!(precpred(_ctx, 8))) throw FailedPredicateException(this, "precpred(_ctx, 8)");
          setState(587);
          match(ECMAScriptParser::Assign);
          setState(588);
          singleExpression(9);
          break;
        }

        case 15: {
          auto newContext = _tracker.createInstance<AssignmentOperatorExpressionContext>(_tracker.createInstance<SingleExpressionContext>(parentContext, parentState));
          _localctx = newContext;
          pushNewRecursionContext(newContext, startState, RuleSingleExpression);
          setState(589);

          if (!(precpred(_ctx, 7))) throw FailedPredicateException(this, "precpred(_ctx, 7)");
          setState(590);
          assignmentOperator();
          setState(591);
          singleExpression(8);
          break;
        }

        case 16: {
          auto newContext = _tracker.createInstance<MemberIndexExpressionContext>(_tracker.createInstance<SingleExpressionContext>(parentContext, parentState));
          _localctx = newContext;
          pushNewRecursionContext(newContext, startState, RuleSingleExpression);
          setState(593);

          if (!(precpred(_ctx, 36))) throw FailedPredicateException(this, "precpred(_ctx, 36)");
          setState(594);
          match(ECMAScriptParser::OpenBracket);
          setState(595);
          expressionSequence();
          setState(596);
          match(ECMAScriptParser::CloseBracket);
          break;
        }

        case 17: {
          auto newContext = _tracker.createInstance<MemberDotExpressionContext>(_tracker.createInstance<SingleExpressionContext>(parentContext, parentState));
          _localctx = newContext;
          pushNewRecursionContext(newContext, startState, RuleSingleExpression);
          setState(598);

          if (!(precpred(_ctx, 35))) throw FailedPredicateException(this, "precpred(_ctx, 35)");
          setState(599);
          match(ECMAScriptParser::Dot);
          setState(600);
          identifierName();
          break;
        }

        case 18: {
          auto newContext = _tracker.createInstance<ArgumentsExpressionContext>(_tracker.createInstance<SingleExpressionContext>(parentContext, parentState));
          _localctx = newContext;
          pushNewRecursionContext(newContext, startState, RuleSingleExpression);
          setState(601);

          if (!(precpred(_ctx, 34))) throw FailedPredicateException(this, "precpred(_ctx, 34)");
          setState(602);
          arguments();
          break;
        }

        case 19: {
          auto newContext = _tracker.createInstance<PostIncrementExpressionContext>(_tracker.createInstance<SingleExpressionContext>(parentContext, parentState));
          _localctx = newContext;
          pushNewRecursionContext(newContext, startState, RuleSingleExpression);
          setState(603);

          if (!(precpred(_ctx, 32))) throw FailedPredicateException(this, "precpred(_ctx, 32)");
          setState(604);

          if (!(!here(LineTerminator))) throw FailedPredicateException(this, "!here(LineTerminator)");
          setState(605);
          match(ECMAScriptParser::PlusPlus);
          break;
        }

        case 20: {
          auto newContext = _tracker.createInstance<PostDecreaseExpressionContext>(_tracker.createInstance<SingleExpressionContext>(parentContext, parentState));
          _localctx = newContext;
          pushNewRecursionContext(newContext, startState, RuleSingleExpression);
          setState(606);

          if (!(precpred(_ctx, 31))) throw FailedPredicateException(this, "precpred(_ctx, 31)");
          setState(607);

          if (!(!here(LineTerminator))) throw FailedPredicateException(this, "!here(LineTerminator)");
          setState(608);
          match(ECMAScriptParser::MinusMinus);
          break;
        }

        default:
          break;
        } 
      }
      setState(613);
      _errHandler->sync(this);
      alt = getInterpreter<atn::ParserATNSimulator>()->adaptivePredict(_input, 51, _ctx);
    }
  }
  catch (RecognitionException &e) {
    _errHandler->reportError(this, e);
    _localctx->exception = std::current_exception();
    _errHandler->recover(this, _localctx->exception);
  }
  return _localctx;
}

//----------------- AssignmentOperatorContext ------------------------------------------------------------------

ECMAScriptParser::AssignmentOperatorContext::AssignmentOperatorContext(ParserRuleContext *parent, size_t invokingState)
  : ParserRuleContext(parent, invokingState) {
}

tree::TerminalNode* ECMAScriptParser::AssignmentOperatorContext::MultiplyAssign() {
  return getToken(ECMAScriptParser::MultiplyAssign, 0);
}

tree::TerminalNode* ECMAScriptParser::AssignmentOperatorContext::DivideAssign() {
  return getToken(ECMAScriptParser::DivideAssign, 0);
}

tree::TerminalNode* ECMAScriptParser::AssignmentOperatorContext::ModulusAssign() {
  return getToken(ECMAScriptParser::ModulusAssign, 0);
}

tree::TerminalNode* ECMAScriptParser::AssignmentOperatorContext::PlusAssign() {
  return getToken(ECMAScriptParser::PlusAssign, 0);
}

tree::TerminalNode* ECMAScriptParser::AssignmentOperatorContext::MinusAssign() {
  return getToken(ECMAScriptParser::MinusAssign, 0);
}

tree::TerminalNode* ECMAScriptParser::AssignmentOperatorContext::LeftShiftArithmeticAssign() {
  return getToken(ECMAScriptParser::LeftShiftArithmeticAssign, 0);
}

tree::TerminalNode* ECMAScriptParser::AssignmentOperatorContext::RightShiftArithmeticAssign() {
  return getToken(ECMAScriptParser::RightShiftArithmeticAssign, 0);
}

tree::TerminalNode* ECMAScriptParser::AssignmentOperatorContext::RightShiftLogicalAssign() {
  return getToken(ECMAScriptParser::RightShiftLogicalAssign, 0);
}

tree::TerminalNode* ECMAScriptParser::AssignmentOperatorContext::BitAndAssign() {
  return getToken(ECMAScriptParser::BitAndAssign, 0);
}

tree::TerminalNode* ECMAScriptParser::AssignmentOperatorContext::BitXorAssign() {
  return getToken(ECMAScriptParser::BitXorAssign, 0);
}

tree::TerminalNode* ECMAScriptParser::AssignmentOperatorContext::BitOrAssign() {
  return getToken(ECMAScriptParser::BitOrAssign, 0);
}


size_t ECMAScriptParser::AssignmentOperatorContext::getRuleIndex() const {
  return ECMAScriptParser::RuleAssignmentOperator;
}


std::any ECMAScriptParser::AssignmentOperatorContext::accept(tree::ParseTreeVisitor *visitor) {
  if (auto parserVisitor = dynamic_cast<ECMAScriptVisitor*>(visitor))
    return parserVisitor->visitAssignmentOperator(this);
  else
    return visitor->visitChildren(this);
}

ECMAScriptParser::AssignmentOperatorContext* ECMAScriptParser::assignmentOperator() {
  AssignmentOperatorContext *_localctx = _tracker.createInstance<AssignmentOperatorContext>(_ctx, getState());
  enterRule(_localctx, 88, ECMAScriptParser::RuleAssignmentOperator);
  size_t _la = 0;

#if __cplusplus > 201703L
  auto onExit = finally([=, this] {
#else
  auto onExit = finally([=] {
#endif
    exitRule();
  });
  try {
    enterOuterAlt(_localctx, 1);
    setState(614);
    _la = _input->LA(1);
    if (!((((_la & ~ 0x3fULL) == 0) &&
      ((1ULL << _la) & 2250700302057472) != 0))) {
    _errHandler->recoverInline(this);
    }
    else {
      _errHandler->reportMatch(this);
      consume();
    }
   
  }
  catch (RecognitionException &e) {
    _errHandler->reportError(this, e);
    _localctx->exception = std::current_exception();
    _errHandler->recover(this, _localctx->exception);
  }

  return _localctx;
}

//----------------- LiteralContext ------------------------------------------------------------------

ECMAScriptParser::LiteralContext::LiteralContext(ParserRuleContext *parent, size_t invokingState)
  : ParserRuleContext(parent, invokingState) {
}

tree::TerminalNode* ECMAScriptParser::LiteralContext::NullLiteral() {
  return getToken(ECMAScriptParser::NullLiteral, 0);
}

tree::TerminalNode* ECMAScriptParser::LiteralContext::BooleanLiteral() {
  return getToken(ECMAScriptParser::BooleanLiteral, 0);
}

tree::TerminalNode* ECMAScriptParser::LiteralContext::StringLiteral() {
  return getToken(ECMAScriptParser::StringLiteral, 0);
}

tree::TerminalNode* ECMAScriptParser::LiteralContext::RegularExpressionLiteral() {
  return getToken(ECMAScriptParser::RegularExpressionLiteral, 0);
}

ECMAScriptParser::NumericLiteralContext* ECMAScriptParser::LiteralContext::numericLiteral() {
  return getRuleContext<ECMAScriptParser::NumericLiteralContext>(0);
}


size_t ECMAScriptParser::LiteralContext::getRuleIndex() const {
  return ECMAScriptParser::RuleLiteral;
}


std::any ECMAScriptParser::LiteralContext::accept(tree::ParseTreeVisitor *visitor) {
  if (auto parserVisitor = dynamic_cast<ECMAScriptVisitor*>(visitor))
    return parserVisitor->visitLiteral(this);
  else
    return visitor->visitChildren(this);
}

ECMAScriptParser::LiteralContext* ECMAScriptParser::literal() {
  LiteralContext *_localctx = _tracker.createInstance<LiteralContext>(_ctx, getState());
  enterRule(_localctx, 90, ECMAScriptParser::RuleLiteral);
  size_t _la = 0;

#if __cplusplus > 201703L
  auto onExit = finally([=, this] {
#else
  auto onExit = finally([=] {
#endif
    exitRule();
  });
  try {
    setState(618);
    _errHandler->sync(this);
    switch (_input->LA(1)) {
      case ECMAScriptParser::RegularExpressionLiteral:
      case ECMAScriptParser::NullLiteral:
      case ECMAScriptParser::BooleanLiteral:
      case ECMAScriptParser::StringLiteral: {
        enterOuterAlt(_localctx, 1);
        setState(616);
        _la = _input->LA(1);
        if (!((((_la & ~ 0x3fULL) == 0) &&
          ((1ULL << _la) & 6755399441055746) != 0) || _la == ECMAScriptParser::StringLiteral)) {
        _errHandler->recoverInline(this);
        }
        else {
          _errHandler->reportMatch(this);
          consume();
        }
        break;
      }

      case ECMAScriptParser::DecimalLiteral:
      case ECMAScriptParser::HexIntegerLiteral:
      case ECMAScriptParser::OctalIntegerLiteral: {
        enterOuterAlt(_localctx, 2);
        setState(617);
        numericLiteral();
        break;
      }

    default:
      throw NoViableAltException(this);
    }
   
  }
  catch (RecognitionException &e) {
    _errHandler->reportError(this, e);
    _localctx->exception = std::current_exception();
    _errHandler->recover(this, _localctx->exception);
  }

  return _localctx;
}

//----------------- NumericLiteralContext ------------------------------------------------------------------

ECMAScriptParser::NumericLiteralContext::NumericLiteralContext(ParserRuleContext *parent, size_t invokingState)
  : ParserRuleContext(parent, invokingState) {
}

tree::TerminalNode* ECMAScriptParser::NumericLiteralContext::DecimalLiteral() {
  return getToken(ECMAScriptParser::DecimalLiteral, 0);
}

tree::TerminalNode* ECMAScriptParser::NumericLiteralContext::HexIntegerLiteral() {
  return getToken(ECMAScriptParser::HexIntegerLiteral, 0);
}

tree::TerminalNode* ECMAScriptParser::NumericLiteralContext::OctalIntegerLiteral() {
  return getToken(ECMAScriptParser::OctalIntegerLiteral, 0);
}


size_t ECMAScriptParser::NumericLiteralContext::getRuleIndex() const {
  return ECMAScriptParser::RuleNumericLiteral;
}


std::any ECMAScriptParser::NumericLiteralContext::accept(tree::ParseTreeVisitor *visitor) {
  if (auto parserVisitor = dynamic_cast<ECMAScriptVisitor*>(visitor))
    return parserVisitor->visitNumericLiteral(this);
  else
    return visitor->visitChildren(this);
}

ECMAScriptParser::NumericLiteralContext* ECMAScriptParser::numericLiteral() {
  NumericLiteralContext *_localctx = _tracker.createInstance<NumericLiteralContext>(_ctx, getState());
  enterRule(_localctx, 92, ECMAScriptParser::RuleNumericLiteral);
  size_t _la = 0;

#if __cplusplus > 201703L
  auto onExit = finally([=, this] {
#else
  auto onExit = finally([=] {
#endif
    exitRule();
  });
  try {
    enterOuterAlt(_localctx, 1);
    setState(620);
    _la = _input->LA(1);
    if (!((((_la & ~ 0x3fULL) == 0) &&
      ((1ULL << _la) & 63050394783186944) != 0))) {
    _errHandler->recoverInline(this);
    }
    else {
      _errHandler->reportMatch(this);
      consume();
    }
   
  }
  catch (RecognitionException &e) {
    _errHandler->reportError(this, e);
    _localctx->exception = std::current_exception();
    _errHandler->recover(this, _localctx->exception);
  }

  return _localctx;
}

//----------------- IdentifierNameContext ------------------------------------------------------------------

ECMAScriptParser::IdentifierNameContext::IdentifierNameContext(ParserRuleContext *parent, size_t invokingState)
  : ParserRuleContext(parent, invokingState) {
}

tree::TerminalNode* ECMAScriptParser::IdentifierNameContext::Identifier() {
  return getToken(ECMAScriptParser::Identifier, 0);
}

ECMAScriptParser::ReservedWordContext* ECMAScriptParser::IdentifierNameContext::reservedWord() {
  return getRuleContext<ECMAScriptParser::ReservedWordContext>(0);
}


size_t ECMAScriptParser::IdentifierNameContext::getRuleIndex() const {
  return ECMAScriptParser::RuleIdentifierName;
}


std::any ECMAScriptParser::IdentifierNameContext::accept(tree::ParseTreeVisitor *visitor) {
  if (auto parserVisitor = dynamic_cast<ECMAScriptVisitor*>(visitor))
    return parserVisitor->visitIdentifierName(this);
  else
    return visitor->visitChildren(this);
}

ECMAScriptParser::IdentifierNameContext* ECMAScriptParser::identifierName() {
  IdentifierNameContext *_localctx = _tracker.createInstance<IdentifierNameContext>(_ctx, getState());
  enterRule(_localctx, 94, ECMAScriptParser::RuleIdentifierName);

#if __cplusplus > 201703L
  auto onExit = finally([=, this] {
#else
  auto onExit = finally([=] {
#endif
    exitRule();
  });
  try {
    setState(624);
    _errHandler->sync(this);
    switch (_input->LA(1)) {
      case ECMAScriptParser::Identifier: {
        enterOuterAlt(_localctx, 1);
        setState(622);
        match(ECMAScriptParser::Identifier);
        break;
      }

      case ECMAScriptParser::NullLiteral:
      case ECMAScriptParser::BooleanLiteral:
      case ECMAScriptParser::Break:
      case ECMAScriptParser::Do:
      case ECMAScriptParser::Instanceof:
      case ECMAScriptParser::Typeof:
      case ECMAScriptParser::Case:
      case ECMAScriptParser::Else:
      case ECMAScriptParser::New:
      case ECMAScriptParser::Var:
      case ECMAScriptParser::Let:
      case ECMAScriptParser::Catch:
      case ECMAScriptParser::Finally:
      case ECMAScriptParser::Return:
      case ECMAScriptParser::Void:
      case ECMAScriptParser::Continue:
      case ECMAScriptParser::For:
      case ECMAScriptParser::Switch:
      case ECMAScriptParser::While:
      case ECMAScriptParser::Debugger:
      case ECMAScriptParser::Function:
      case ECMAScriptParser::This:
      case ECMAScriptParser::With:
      case ECMAScriptParser::Default:
      case ECMAScriptParser::If:
      case ECMAScriptParser::Throw:
      case ECMAScriptParser::Delete:
      case ECMAScriptParser::In:
      case ECMAScriptParser::Try:
      case ECMAScriptParser::Class:
      case ECMAScriptParser::Enum:
      case ECMAScriptParser::Extends:
      case ECMAScriptParser::Super:
      case ECMAScriptParser::Const:
      case ECMAScriptParser::Export:
      case ECMAScriptParser::Import:
      case ECMAScriptParser::Implements:
      case ECMAScriptParser::Private:
      case ECMAScriptParser::Public:
      case ECMAScriptParser::Interface:
      case ECMAScriptParser::Package:
      case ECMAScriptParser::Protected:
      case ECMAScriptParser::Static:
      case ECMAScriptParser::Yield: {
        enterOuterAlt(_localctx, 2);
        setState(623);
        reservedWord();
        break;
      }

    default:
      throw NoViableAltException(this);
    }
   
  }
  catch (RecognitionException &e) {
    _errHandler->reportError(this, e);
    _localctx->exception = std::current_exception();
    _errHandler->recover(this, _localctx->exception);
  }

  return _localctx;
}

//----------------- ReservedWordContext ------------------------------------------------------------------

ECMAScriptParser::ReservedWordContext::ReservedWordContext(ParserRuleContext *parent, size_t invokingState)
  : ParserRuleContext(parent, invokingState) {
}

ECMAScriptParser::KeywordContext* ECMAScriptParser::ReservedWordContext::keyword() {
  return getRuleContext<ECMAScriptParser::KeywordContext>(0);
}

ECMAScriptParser::FutureReservedWordContext* ECMAScriptParser::ReservedWordContext::futureReservedWord() {
  return getRuleContext<ECMAScriptParser::FutureReservedWordContext>(0);
}

tree::TerminalNode* ECMAScriptParser::ReservedWordContext::NullLiteral() {
  return getToken(ECMAScriptParser::NullLiteral, 0);
}

tree::TerminalNode* ECMAScriptParser::ReservedWordContext::BooleanLiteral() {
  return getToken(ECMAScriptParser::BooleanLiteral, 0);
}


size_t ECMAScriptParser::ReservedWordContext::getRuleIndex() const {
  return ECMAScriptParser::RuleReservedWord;
}


std::any ECMAScriptParser::ReservedWordContext::accept(tree::ParseTreeVisitor *visitor) {
  if (auto parserVisitor = dynamic_cast<ECMAScriptVisitor*>(visitor))
    return parserVisitor->visitReservedWord(this);
  else
    return visitor->visitChildren(this);
}

ECMAScriptParser::ReservedWordContext* ECMAScriptParser::reservedWord() {
  ReservedWordContext *_localctx = _tracker.createInstance<ReservedWordContext>(_ctx, getState());
  enterRule(_localctx, 96, ECMAScriptParser::RuleReservedWord);
  size_t _la = 0;

#if __cplusplus > 201703L
  auto onExit = finally([=, this] {
#else
  auto onExit = finally([=] {
#endif
    exitRule();
  });
  try {
    setState(629);
    _errHandler->sync(this);
    switch (_input->LA(1)) {
      case ECMAScriptParser::Break:
      case ECMAScriptParser::Do:
      case ECMAScriptParser::Instanceof:
      case ECMAScriptParser::Typeof:
      case ECMAScriptParser::Case:
      case ECMAScriptParser::Else:
      case ECMAScriptParser::New:
      case ECMAScriptParser::Var:
      case ECMAScriptParser::Let:
      case ECMAScriptParser::Catch:
      case ECMAScriptParser::Finally:
      case ECMAScriptParser::Return:
      case ECMAScriptParser::Void:
      case ECMAScriptParser::Continue:
      case ECMAScriptParser::For:
      case ECMAScriptParser::Switch:
      case ECMAScriptParser::While:
      case ECMAScriptParser::Debugger:
      case ECMAScriptParser::Function:
      case ECMAScriptParser::This:
      case ECMAScriptParser::With:
      case ECMAScriptParser::Default:
      case ECMAScriptParser::If:
      case ECMAScriptParser::Throw:
      case ECMAScriptParser::Delete:
      case ECMAScriptParser::In:
      case ECMAScriptParser::Try: {
        enterOuterAlt(_localctx, 1);
        setState(626);
        keyword();
        break;
      }

      case ECMAScriptParser::Class:
      case ECMAScriptParser::Enum:
      case ECMAScriptParser::Extends:
      case ECMAScriptParser::Super:
      case ECMAScriptParser::Const:
      case ECMAScriptParser::Export:
      case ECMAScriptParser::Import:
      case ECMAScriptParser::Implements:
      case ECMAScriptParser::Private:
      case ECMAScriptParser::Public:
      case ECMAScriptParser::Interface:
      case ECMAScriptParser::Package:
      case ECMAScriptParser::Protected:
      case ECMAScriptParser::Static:
      case ECMAScriptParser::Yield: {
        enterOuterAlt(_localctx, 2);
        setState(627);
        futureReservedWord();
        break;
      }

      case ECMAScriptParser::NullLiteral:
      case ECMAScriptParser::BooleanLiteral: {
        enterOuterAlt(_localctx, 3);
        setState(628);
        _la = _input->LA(1);
        if (!(_la == ECMAScriptParser::NullLiteral

        || _la == ECMAScriptParser::BooleanLiteral)) {
        _errHandler->recoverInline(this);
        }
        else {
          _errHandler->reportMatch(this);
          consume();
        }
        break;
      }

    default:
      throw NoViableAltException(this);
    }
   
  }
  catch (RecognitionException &e) {
    _errHandler->reportError(this, e);
    _localctx->exception = std::current_exception();
    _errHandler->recover(this, _localctx->exception);
  }

  return _localctx;
}

//----------------- KeywordContext ------------------------------------------------------------------

ECMAScriptParser::KeywordContext::KeywordContext(ParserRuleContext *parent, size_t invokingState)
  : ParserRuleContext(parent, invokingState) {
}

tree::TerminalNode* ECMAScriptParser::KeywordContext::Break() {
  return getToken(ECMAScriptParser::Break, 0);
}

tree::TerminalNode* ECMAScriptParser::KeywordContext::Do() {
  return getToken(ECMAScriptParser::Do, 0);
}

tree::TerminalNode* ECMAScriptParser::KeywordContext::Instanceof() {
  return getToken(ECMAScriptParser::Instanceof, 0);
}

tree::TerminalNode* ECMAScriptParser::KeywordContext::Typeof() {
  return getToken(ECMAScriptParser::Typeof, 0);
}

tree::TerminalNode* ECMAScriptParser::KeywordContext::Case() {
  return getToken(ECMAScriptParser::Case, 0);
}

tree::TerminalNode* ECMAScriptParser::KeywordContext::Else() {
  return getToken(ECMAScriptParser::Else, 0);
}

tree::TerminalNode* ECMAScriptParser::KeywordContext::New() {
  return getToken(ECMAScriptParser::New, 0);
}

tree::TerminalNode* ECMAScriptParser::KeywordContext::Var() {
  return getToken(ECMAScriptParser::Var, 0);
}

tree::TerminalNode* ECMAScriptParser::KeywordContext::Let() {
  return getToken(ECMAScriptParser::Let, 0);
}

tree::TerminalNode* ECMAScriptParser::KeywordContext::Catch() {
  return getToken(ECMAScriptParser::Catch, 0);
}

tree::TerminalNode* ECMAScriptParser::KeywordContext::Finally() {
  return getToken(ECMAScriptParser::Finally, 0);
}

tree::TerminalNode* ECMAScriptParser::KeywordContext::Return() {
  return getToken(ECMAScriptParser::Return, 0);
}

tree::TerminalNode* ECMAScriptParser::KeywordContext::Void() {
  return getToken(ECMAScriptParser::Void, 0);
}

tree::TerminalNode* ECMAScriptParser::KeywordContext::Continue() {
  return getToken(ECMAScriptParser::Continue, 0);
}

tree::TerminalNode* ECMAScriptParser::KeywordContext::For() {
  return getToken(ECMAScriptParser::For, 0);
}

tree::TerminalNode* ECMAScriptParser::KeywordContext::Switch() {
  return getToken(ECMAScriptParser::Switch, 0);
}

tree::TerminalNode* ECMAScriptParser::KeywordContext::While() {
  return getToken(ECMAScriptParser::While, 0);
}

tree::TerminalNode* ECMAScriptParser::KeywordContext::Debugger() {
  return getToken(ECMAScriptParser::Debugger, 0);
}

tree::TerminalNode* ECMAScriptParser::KeywordContext::Function() {
  return getToken(ECMAScriptParser::Function, 0);
}

tree::TerminalNode* ECMAScriptParser::KeywordContext::This() {
  return getToken(ECMAScriptParser::This, 0);
}

tree::TerminalNode* ECMAScriptParser::KeywordContext::With() {
  return getToken(ECMAScriptParser::With, 0);
}

tree::TerminalNode* ECMAScriptParser::KeywordContext::Default() {
  return getToken(ECMAScriptParser::Default, 0);
}

tree::TerminalNode* ECMAScriptParser::KeywordContext::If() {
  return getToken(ECMAScriptParser::If, 0);
}

tree::TerminalNode* ECMAScriptParser::KeywordContext::Throw() {
  return getToken(ECMAScriptParser::Throw, 0);
}

tree::TerminalNode* ECMAScriptParser::KeywordContext::Delete() {
  return getToken(ECMAScriptParser::Delete, 0);
}

tree::TerminalNode* ECMAScriptParser::KeywordContext::In() {
  return getToken(ECMAScriptParser::In, 0);
}

tree::TerminalNode* ECMAScriptParser::KeywordContext::Try() {
  return getToken(ECMAScriptParser::Try, 0);
}


size_t ECMAScriptParser::KeywordContext::getRuleIndex() const {
  return ECMAScriptParser::RuleKeyword;
}


std::any ECMAScriptParser::KeywordContext::accept(tree::ParseTreeVisitor *visitor) {
  if (auto parserVisitor = dynamic_cast<ECMAScriptVisitor*>(visitor))
    return parserVisitor->visitKeyword(this);
  else
    return visitor->visitChildren(this);
}

ECMAScriptParser::KeywordContext* ECMAScriptParser::keyword() {
  KeywordContext *_localctx = _tracker.createInstance<KeywordContext>(_ctx, getState());
  enterRule(_localctx, 98, ECMAScriptParser::RuleKeyword);
  size_t _la = 0;

#if __cplusplus > 201703L
  auto onExit = finally([=, this] {
#else
  auto onExit = finally([=] {
#endif
    exitRule();
  });
  try {
    enterOuterAlt(_localctx, 1);
    setState(631);
    _la = _input->LA(1);
    if (!(((((_la - 56) & ~ 0x3fULL) == 0) &&
      ((1ULL << (_la - 56)) & 134217727) != 0))) {
    _errHandler->recoverInline(this);
    }
    else {
      _errHandler->reportMatch(this);
      consume();
    }
   
  }
  catch (RecognitionException &e) {
    _errHandler->reportError(this, e);
    _localctx->exception = std::current_exception();
    _errHandler->recover(this, _localctx->exception);
  }

  return _localctx;
}

//----------------- FutureReservedWordContext ------------------------------------------------------------------

ECMAScriptParser::FutureReservedWordContext::FutureReservedWordContext(ParserRuleContext *parent, size_t invokingState)
  : ParserRuleContext(parent, invokingState) {
}

tree::TerminalNode* ECMAScriptParser::FutureReservedWordContext::Class() {
  return getToken(ECMAScriptParser::Class, 0);
}

tree::TerminalNode* ECMAScriptParser::FutureReservedWordContext::Enum() {
  return getToken(ECMAScriptParser::Enum, 0);
}

tree::TerminalNode* ECMAScriptParser::FutureReservedWordContext::Extends() {
  return getToken(ECMAScriptParser::Extends, 0);
}

tree::TerminalNode* ECMAScriptParser::FutureReservedWordContext::Super() {
  return getToken(ECMAScriptParser::Super, 0);
}

tree::TerminalNode* ECMAScriptParser::FutureReservedWordContext::Const() {
  return getToken(ECMAScriptParser::Const, 0);
}

tree::TerminalNode* ECMAScriptParser::FutureReservedWordContext::Export() {
  return getToken(ECMAScriptParser::Export, 0);
}

tree::TerminalNode* ECMAScriptParser::FutureReservedWordContext::Import() {
  return getToken(ECMAScriptParser::Import, 0);
}

tree::TerminalNode* ECMAScriptParser::FutureReservedWordContext::Implements() {
  return getToken(ECMAScriptParser::Implements, 0);
}

tree::TerminalNode* ECMAScriptParser::FutureReservedWordContext::Private() {
  return getToken(ECMAScriptParser::Private, 0);
}

tree::TerminalNode* ECMAScriptParser::FutureReservedWordContext::Public() {
  return getToken(ECMAScriptParser::Public, 0);
}

tree::TerminalNode* ECMAScriptParser::FutureReservedWordContext::Interface() {
  return getToken(ECMAScriptParser::Interface, 0);
}

tree::TerminalNode* ECMAScriptParser::FutureReservedWordContext::Package() {
  return getToken(ECMAScriptParser::Package, 0);
}

tree::TerminalNode* ECMAScriptParser::FutureReservedWordContext::Protected() {
  return getToken(ECMAScriptParser::Protected, 0);
}

tree::TerminalNode* ECMAScriptParser::FutureReservedWordContext::Static() {
  return getToken(ECMAScriptParser::Static, 0);
}

tree::TerminalNode* ECMAScriptParser::FutureReservedWordContext::Yield() {
  return getToken(ECMAScriptParser::Yield, 0);
}


size_t ECMAScriptParser::FutureReservedWordContext::getRuleIndex() const {
  return ECMAScriptParser::RuleFutureReservedWord;
}


std::any ECMAScriptParser::FutureReservedWordContext::accept(tree::ParseTreeVisitor *visitor) {
  if (auto parserVisitor = dynamic_cast<ECMAScriptVisitor*>(visitor))
    return parserVisitor->visitFutureReservedWord(this);
  else
    return visitor->visitChildren(this);
}

ECMAScriptParser::FutureReservedWordContext* ECMAScriptParser::futureReservedWord() {
  FutureReservedWordContext *_localctx = _tracker.createInstance<FutureReservedWordContext>(_ctx, getState());
  enterRule(_localctx, 100, ECMAScriptParser::RuleFutureReservedWord);
  size_t _la = 0;

#if __cplusplus > 201703L
  auto onExit = finally([=, this] {
#else
  auto onExit = finally([=] {
#endif
    exitRule();
  });
  try {
    enterOuterAlt(_localctx, 1);
    setState(633);
    _la = _input->LA(1);
    if (!(((((_la - 83) & ~ 0x3fULL) == 0) &&
      ((1ULL << (_la - 83)) & 32767) != 0))) {
    _errHandler->recoverInline(this);
    }
    else {
      _errHandler->reportMatch(this);
      consume();
    }
   
  }
  catch (RecognitionException &e) {
    _errHandler->reportError(this, e);
    _localctx->exception = std::current_exception();
    _errHandler->recover(this, _localctx->exception);
  }

  return _localctx;
}

//----------------- GetterContext ------------------------------------------------------------------

ECMAScriptParser::GetterContext::GetterContext(ParserRuleContext *parent, size_t invokingState)
  : ParserRuleContext(parent, invokingState) {
}

tree::TerminalNode* ECMAScriptParser::GetterContext::Identifier() {
  return getToken(ECMAScriptParser::Identifier, 0);
}

ECMAScriptParser::PropertyNameContext* ECMAScriptParser::GetterContext::propertyName() {
  return getRuleContext<ECMAScriptParser::PropertyNameContext>(0);
}


size_t ECMAScriptParser::GetterContext::getRuleIndex() const {
  return ECMAScriptParser::RuleGetter;
}


std::any ECMAScriptParser::GetterContext::accept(tree::ParseTreeVisitor *visitor) {
  if (auto parserVisitor = dynamic_cast<ECMAScriptVisitor*>(visitor))
    return parserVisitor->visitGetter(this);
  else
    return visitor->visitChildren(this);
}

ECMAScriptParser::GetterContext* ECMAScriptParser::getter() {
  GetterContext *_localctx = _tracker.createInstance<GetterContext>(_ctx, getState());
  enterRule(_localctx, 102, ECMAScriptParser::RuleGetter);

#if __cplusplus > 201703L
  auto onExit = finally([=, this] {
#else
  auto onExit = finally([=] {
#endif
    exitRule();
  });
  try {
    enterOuterAlt(_localctx, 1);
    setState(635);

    if (!(_input.Lt(1).Text.Equals("get"))) throw FailedPredicateException(this, "_input.Lt(1).Text.Equals(\"get\")");
    setState(636);
    match(ECMAScriptParser::Identifier);
    setState(637);
    propertyName();
   
  }
  catch (RecognitionException &e) {
    _errHandler->reportError(this, e);
    _localctx->exception = std::current_exception();
    _errHandler->recover(this, _localctx->exception);
  }

  return _localctx;
}

//----------------- SetterContext ------------------------------------------------------------------

ECMAScriptParser::SetterContext::SetterContext(ParserRuleContext *parent, size_t invokingState)
  : ParserRuleContext(parent, invokingState) {
}

tree::TerminalNode* ECMAScriptParser::SetterContext::Identifier() {
  return getToken(ECMAScriptParser::Identifier, 0);
}

ECMAScriptParser::PropertyNameContext* ECMAScriptParser::SetterContext::propertyName() {
  return getRuleContext<ECMAScriptParser::PropertyNameContext>(0);
}


size_t ECMAScriptParser::SetterContext::getRuleIndex() const {
  return ECMAScriptParser::RuleSetter;
}


std::any ECMAScriptParser::SetterContext::accept(tree::ParseTreeVisitor *visitor) {
  if (auto parserVisitor = dynamic_cast<ECMAScriptVisitor*>(visitor))
    return parserVisitor->visitSetter(this);
  else
    return visitor->visitChildren(this);
}

ECMAScriptParser::SetterContext* ECMAScriptParser::setter() {
  SetterContext *_localctx = _tracker.createInstance<SetterContext>(_ctx, getState());
  enterRule(_localctx, 104, ECMAScriptParser::RuleSetter);

#if __cplusplus > 201703L
  auto onExit = finally([=, this] {
#else
  auto onExit = finally([=] {
#endif
    exitRule();
  });
  try {
    enterOuterAlt(_localctx, 1);
    setState(639);

    if (!(_input.Lt(1).Text.Equals("set"))) throw FailedPredicateException(this, "_input.Lt(1).Text.Equals(\"set\")");
    setState(640);
    match(ECMAScriptParser::Identifier);
    setState(641);
    propertyName();
   
  }
  catch (RecognitionException &e) {
    _errHandler->reportError(this, e);
    _localctx->exception = std::current_exception();
    _errHandler->recover(this, _localctx->exception);
  }

  return _localctx;
}

//----------------- EosContext ------------------------------------------------------------------

ECMAScriptParser::EosContext::EosContext(ParserRuleContext *parent, size_t invokingState)
  : ParserRuleContext(parent, invokingState) {
}

tree::TerminalNode* ECMAScriptParser::EosContext::SemiColon() {
  return getToken(ECMAScriptParser::SemiColon, 0);
}

tree::TerminalNode* ECMAScriptParser::EosContext::EOF() {
  return getToken(ECMAScriptParser::EOF, 0);
}


size_t ECMAScriptParser::EosContext::getRuleIndex() const {
  return ECMAScriptParser::RuleEos;
}


std::any ECMAScriptParser::EosContext::accept(tree::ParseTreeVisitor *visitor) {
  if (auto parserVisitor = dynamic_cast<ECMAScriptVisitor*>(visitor))
    return parserVisitor->visitEos(this);
  else
    return visitor->visitChildren(this);
}

ECMAScriptParser::EosContext* ECMAScriptParser::eos() {
  EosContext *_localctx = _tracker.createInstance<EosContext>(_ctx, getState());
  enterRule(_localctx, 106, ECMAScriptParser::RuleEos);

#if __cplusplus > 201703L
  auto onExit = finally([=, this] {
#else
  auto onExit = finally([=] {
#endif
    exitRule();
  });
  try {
    setState(647);
    _errHandler->sync(this);
    switch (getInterpreter<atn::ParserATNSimulator>()->adaptivePredict(_input, 55, _ctx)) {
    case 1: {
      enterOuterAlt(_localctx, 1);
      setState(643);
      match(ECMAScriptParser::SemiColon);
      break;
    }

    case 2: {
      enterOuterAlt(_localctx, 2);
      setState(644);
      match(ECMAScriptParser::EOF);
      break;
    }

    case 3: {
      enterOuterAlt(_localctx, 3);
      setState(645);

      if (!(lineTerminatorAhead())) throw FailedPredicateException(this, "lineTerminatorAhead()");
      break;
    }

    case 4: {
      enterOuterAlt(_localctx, 4);
      setState(646);

      if (!(_input.Lt(1).Type == CloseBrace)) throw FailedPredicateException(this, "_input.Lt(1).Type == CloseBrace");
      break;
    }

    default:
      break;
    }
   
  }
  catch (RecognitionException &e) {
    _errHandler->reportError(this, e);
    _localctx->exception = std::current_exception();
    _errHandler->recover(this, _localctx->exception);
  }

  return _localctx;
}

//----------------- EofContext ------------------------------------------------------------------

ECMAScriptParser::EofContext::EofContext(ParserRuleContext *parent, size_t invokingState)
  : ParserRuleContext(parent, invokingState) {
}

tree::TerminalNode* ECMAScriptParser::EofContext::EOF() {
  return getToken(ECMAScriptParser::EOF, 0);
}


size_t ECMAScriptParser::EofContext::getRuleIndex() const {
  return ECMAScriptParser::RuleEof;
}


std::any ECMAScriptParser::EofContext::accept(tree::ParseTreeVisitor *visitor) {
  if (auto parserVisitor = dynamic_cast<ECMAScriptVisitor*>(visitor))
    return parserVisitor->visitEof(this);
  else
    return visitor->visitChildren(this);
}

ECMAScriptParser::EofContext* ECMAScriptParser::eof() {
  EofContext *_localctx = _tracker.createInstance<EofContext>(_ctx, getState());
  enterRule(_localctx, 108, ECMAScriptParser::RuleEof);

#if __cplusplus > 201703L
  auto onExit = finally([=, this] {
#else
  auto onExit = finally([=] {
#endif
    exitRule();
  });
  try {
    enterOuterAlt(_localctx, 1);
    setState(649);
    match(ECMAScriptParser::EOF);
   
  }
  catch (RecognitionException &e) {
    _errHandler->reportError(this, e);
    _localctx->exception = std::current_exception();
    _errHandler->recover(this, _localctx->exception);
  }

  return _localctx;
}

bool ECMAScriptParser::sempred(RuleContext *context, size_t ruleIndex, size_t predicateIndex) {
  switch (ruleIndex) {
    case 11: return expressionStatementSempred(antlrcpp::downCast<ExpressionStatementContext *>(context), predicateIndex);
    case 14: return continueStatementSempred(antlrcpp::downCast<ContinueStatementContext *>(context), predicateIndex);
    case 15: return breakStatementSempred(antlrcpp::downCast<BreakStatementContext *>(context), predicateIndex);
    case 16: return returnStatementSempred(antlrcpp::downCast<ReturnStatementContext *>(context), predicateIndex);
    case 24: return throwStatementSempred(antlrcpp::downCast<ThrowStatementContext *>(context), predicateIndex);
    case 43: return singleExpressionSempred(antlrcpp::downCast<SingleExpressionContext *>(context), predicateIndex);
    case 51: return getterSempred(antlrcpp::downCast<GetterContext *>(context), predicateIndex);
    case 52: return setterSempred(antlrcpp::downCast<SetterContext *>(context), predicateIndex);
    case 53: return eosSempred(antlrcpp::downCast<EosContext *>(context), predicateIndex);

  default:
    break;
  }
  return true;
}

bool ECMAScriptParser::expressionStatementSempred(ExpressionStatementContext *_localctx, size_t predicateIndex) {
  switch (predicateIndex) {
    case 0: return (_input.La(1) != OpenBrace) && (_input.La(1) != Function);

  default:
    break;
  }
  return true;
}

bool ECMAScriptParser::continueStatementSempred(ContinueStatementContext *_localctx, size_t predicateIndex) {
  switch (predicateIndex) {
    case 1: return !here(LineTerminator);

  default:
    break;
  }
  return true;
}

bool ECMAScriptParser::breakStatementSempred(BreakStatementContext *_localctx, size_t predicateIndex) {
  switch (predicateIndex) {
    case 2: return !here(LineTerminator);

  default:
    break;
  }
  return true;
}

bool ECMAScriptParser::returnStatementSempred(ReturnStatementContext *_localctx, size_t predicateIndex) {
  switch (predicateIndex) {
    case 3: return !here(LineTerminator);

  default:
    break;
  }
  return true;
}

bool ECMAScriptParser::throwStatementSempred(ThrowStatementContext *_localctx, size_t predicateIndex) {
  switch (predicateIndex) {
    case 4: return !here(LineTerminator);

  default:
    break;
  }
  return true;
}

bool ECMAScriptParser::singleExpressionSempred(SingleExpressionContext *_localctx, size_t predicateIndex) {
  switch (predicateIndex) {
    case 5: return precpred(_ctx, 21);
    case 6: return precpred(_ctx, 20);
    case 7: return precpred(_ctx, 19);
    case 8: return precpred(_ctx, 18);
    case 9: return precpred(_ctx, 17);
    case 10: return precpred(_ctx, 16);
    case 11: return precpred(_ctx, 15);
    case 12: return precpred(_ctx, 14);
    case 13: return precpred(_ctx, 13);
    case 14: return precpred(_ctx, 12);
    case 15: return precpred(_ctx, 11);
    case 16: return precpred(_ctx, 10);
    case 17: return precpred(_ctx, 9);
    case 18: return precpred(_ctx, 8);
    case 19: return precpred(_ctx, 7);
    case 20: return precpred(_ctx, 36);
    case 21: return precpred(_ctx, 35);
    case 22: return precpred(_ctx, 34);
    case 23: return precpred(_ctx, 32);
    case 24: return !here(LineTerminator);
    case 25: return precpred(_ctx, 31);
    case 26: return !here(LineTerminator);

  default:
    break;
  }
  return true;
}

bool ECMAScriptParser::getterSempred(GetterContext *_localctx, size_t predicateIndex) {
  switch (predicateIndex) {
    case 27: return _input.Lt(1).Text.Equals("get");

  default:
    break;
  }
  return true;
}

bool ECMAScriptParser::setterSempred(SetterContext *_localctx, size_t predicateIndex) {
  switch (predicateIndex) {
    case 28: return _input.Lt(1).Text.Equals("set");

  default:
    break;
  }
  return true;
}

bool ECMAScriptParser::eosSempred(EosContext *_localctx, size_t predicateIndex) {
  switch (predicateIndex) {
    case 29: return lineTerminatorAhead();
    case 30: return _input.Lt(1).Type == CloseBrace;

  default:
    break;
  }
  return true;
}

void ECMAScriptParser::initialize() {
#if ANTLR4_USE_THREAD_LOCAL_CACHE
  ecmascriptParserInitialize();
#else
  ::antlr4::internal::call_once(ecmascriptParserOnceFlag, ecmascriptParserInitialize);
#endif
}
