#!/bin/bash
find . -type f -name "*.class" -exec rm -f {} \;
find . -type f -name "*.xml" -exec rm -f {} \;
find . -type f -name "*.java" -exec rm -f {} \;
find . -type f -name "*.interp" -exec rm -f {} \;
find . -type f -name "*.tokens" -exec rm -f {} \;