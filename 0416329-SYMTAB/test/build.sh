#!/bin/sh

yacc -yd ./parserC.y
lex ./scanner.l
cc lex.yy.c y.tab.c node.c symtab.c -ll -g -o parse