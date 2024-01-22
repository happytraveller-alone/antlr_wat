parser grammar StrParser;

options {
	tokenVocab = StrLexer;
}

left: LPAR DIGIT+ RPAR;
middle: KEY;
right: LBRACE LETTER+ RBRACE;
module: left middle right EOF;