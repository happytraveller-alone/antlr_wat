#!/bin/bash
for file in *.java
do
    if [ $file != "Check.java" ]
    then
        rm -f "$file"
    fi
done
find . -type f -name "*.class" -exec rm -f {} \;
find . -type f -name "*.xml" -exec rm -f {} \;
find . -type f -name "*.interp" -exec rm -f {} \;
find . -type f -name "*.tokens" -exec rm -f {} \;