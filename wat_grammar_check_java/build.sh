#!/bin/bash
java -jar /usr/local/lib/antlr-4.13.1-complete.jar -Dlanguage=Java -visitor -listener WatLexer.g4 WatParser.g4