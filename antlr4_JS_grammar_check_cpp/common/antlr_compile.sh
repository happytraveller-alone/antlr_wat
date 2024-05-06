#!/bin/bash
cd /home/xyf/antlr_wat/antlr4_JS_grammar_check_cpp
antlr4 -listener -visitor -Dlanguage=Cpp -o /home/xyf/antlr_wat/antlr4_JS_grammar_check_cpp/common/  JavaScriptLexer.g4 JavaScriptParser.g4