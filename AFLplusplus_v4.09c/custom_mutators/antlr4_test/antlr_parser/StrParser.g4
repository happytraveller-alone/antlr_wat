parser grammar StrParser;

options {
	tokenVocab = StrLexer;
}

left: LPAR DIGIT DIGIT DIGIT DIGIT DIGIT RPAR;
middle: KEY;
right: LBRACE LETTER LETTER LETTER LETTER LETTER RBRACE;
module: left middle right EOF;