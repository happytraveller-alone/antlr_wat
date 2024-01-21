# antlr4_test

基于antlr4文法构建一个简单的测试样例，便于后期wat文法的迁移

## 书写vlun.c程序，构建触发崩溃的特殊字符串(完成)
```c
#include <signal.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int main() {
  char buffer[50];

  printf("Please enter a string:\n");
  fgets(buffer, 50, stdin);

  // Remove newline character
  buffer[strcspn(buffer, "\n")] = 0;

  // Check string length
  if (strlen(buffer) != 19) {
    printf("The length of the input string is incorrect.\n");
    return 0;
  }

  if (strcmp(buffer, "(13574)visit{fafav}") == 0) {
    printf("Triggering crash...\n");
    raise(SIGSEGV); // Trigger crash
  } else {
    printf("The input string is: %s\n", buffer);
  }

  return 0;
}
```
- 字符串输入，固定字符串长度为19，满足特定字符串值崩溃退出
## 按照词法和语法两大块构建简单语法，语法可以触发特殊字符串(完成)
- lexer文法
```antlr
lexer grammar StrLexer;

fragment Digit: [0-9];
fragment Letter: [a-zA-Z];
KEY: 'visit';
DIGIT: Digit;
LETTER: Letter;
LPAR: '(';
RPAR: ')';
LBRACE: '{';
RBRACE: '}';
```
- parser文法
```antlr
parser grammar StrParser;

options {
	tokenVocab = StrLexer;
}

left: LPAR DIGIT+ RPAR;
middle: KEY;
right: LBRACE LETTER+ RBRACE;
module: left middle right EOF;
```
## 构建antlr4代码库，编译生成静态库
- download antlr4 cpp runtime.zip and unzip to runtime folder
- mkdir build && mkdir run && cd build
- cmake .. -DANTLR_JAR_LOCATION=/home/xyf/antlr_wat/antlr4_grammar_check_cpp/tool/antlr-4.13.1-complete.jar -DWITH_DEMO=False -DWITH_LIBCXX=On -DCMAKE_CXX_STANDARD=17
- make -j32



## 书写custom mutator部分
## 进行fuzz