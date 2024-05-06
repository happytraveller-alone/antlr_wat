#!/bin/bash

# 文件列表
files=(
    "JavaScriptLexer.cpp"
    "JavaScriptParserBaseVisitor.h"
    "JavaScriptLexer.h"
    "JavaScriptParser.cpp"
    "JavaScriptParserListener.cpp"
    "JavaScriptLexer.interp"
    "JavaScriptParser.h"
    "JavaScriptParserBaseListener.cpp"
    "JavaScriptParserListener.h"
    "JavaScriptLexer.tokens"
    "JavaScriptParser.interp"
    "JavaScriptParserBaseListener.h"
    "JavaScriptParserVisitor.cpp"
    "JavaScriptParser.tokens"
    "JavaScriptParserBaseVisitor.cpp"
    "JavaScriptParserVisitor.h"
)

# 遍历文件列表并检查及删除
for file in "${files[@]}"; do
    if [ -f "$file" ]; then
        echo "File $file found, deleting..."
        rm "$file"
    else
        echo "File $file not found."
    fi
done