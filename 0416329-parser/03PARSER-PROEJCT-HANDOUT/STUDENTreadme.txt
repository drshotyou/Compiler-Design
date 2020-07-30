Steps to compile Parser
1) yacc -d mini-pascal.y
2) flex mini-pascal-scanner.l
3) cc y.tab.c -ly -ll
To use the test files ./a.out < "testfile".p &> "testfile".txt
where "testfile" should be replaced with the name of the test file
you wish to use. The second part of the command &> "testfile".txt
is to save the output into a text file, i use the same name as
input file for the output file.



EDIT: I changed

optional_statements : statement_list
    |
    ;

to 

optional_statements : statement_list
    ;

The | lambda line produces a reduce/reduce conflict.


