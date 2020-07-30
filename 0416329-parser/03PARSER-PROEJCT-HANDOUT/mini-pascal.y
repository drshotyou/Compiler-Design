%{
/*
 * grammar.y
 *
 * Pascal grammar in Yacc format, based originally on BNF given
 * in "Standard Pascal -- User Reference Manual", by Doug Cooper.
 * This in turn is the BNF given by the ANSI and ISO Pascal standards,
 * and so, is PUBLIC DOMAIN. The grammar is for ISO Level 0 Pascal.
 * The grammar has been massaged somewhat to make it LALR, and added
 * the following extensions.
 *
 * constant expressions
 * otherwise statement in a case
 * productions to correctly match else's with if's
 * beginnings of a separate compilation facility
 */
    #include<stdio.h>

    void yyerror (char const *s){
    extern char *yytext;
    extern int line_no;
    fprintf (stderr, "%s: at line %d symbol'%s'\n", s,line_no,yytext);

 }
%}

%type prog identifier_list declarations type standard_type subprogram_declarations
%type subprogram_declaration subprogram_head arguments parameter_list optional_var
%type compound_statement optional_statements statement_list statement variable
%type tail procedure_statement expression_list expression simple_expression term
%type factor addop mulop relop boolexpression


%token PROGRAM ELSE WHILE DO THEN IF OF FUNCTION PROCEDURE BEGINS
%token END ARRAY VAR NOT STRING ASSIGNOP COLON COMMA INTEGER
%token DOT DOTDOT EQUAL notEQUAL GE GT LBRAC LE LPAREN LT
%token MINUS PLUS RBRAC REAL RPAREN SEMICOLON SLASH STAR CHAR
%token NUM ID COMMENTC COMMENTCC AND OR


%%

prog : PROGRAM ID LPAREN identifier_list RPAREN SEMICOLON
  	    declarations
	    subprogram_declarations
	    compound_statement
	    DOT
        ;


identifier_list : ID
    | identifier_list COMMA ID
    ;

declarations : declarations VAR identifier_list COLON type SEMICOLON
    |
    ;

type : standard_type
    | ARRAY LBRAC NUM DOTDOT NUM RBRAC OF type
    ;

standard_type : INTEGER
    | REAL
    | STRING
    ;

subprogram_declarations : subprogram_declarations subprogram_declaration SEMICOLON
    |
    ;

subprogram_declaration : subprogram_head
                         declarations
                         subprogram_declarations
                         compound_statement
                         ;

subprogram_head : FUNCTION ID arguments COLON standard_type SEMICOLON
    | PROCEDURE ID arguments SEMICOLON
    ;

arguments : LPAREN parameter_list RPAREN
    |
    ;

parameter_list : optional_var identifier_list COLON type
    | optional_var identifier_list COLON type SEMICOLON parameter_list
    ;

optional_var : VAR
    |
    ;

compound_statement : BEGINS
                     optional_statements
                     END
    ;

optional_statements : statement_list
    ;

statement_list : statement
    | statement_list SEMICOLON statement
    ;

statement : variable ASSIGNOP expression
    | procedure_statement
    | compound_statement
    | IF expression THEN statement ELSE statement
    | WHILE expression DO statement
    | 
    ;

variable : ID tail
    ;

tail : LBRAC expression RBRAC tail
    |
    ;

procedure_statement : ID
    | ID LPAREN expression_list RPAREN
    ;

expression_list : expression
    | expression_list COMMA expression
    ;

expression : boolexpression
    | boolexpression AND boolexpression
    | boolexpression OR boolexpression
    ;

boolexpression: simple_expression
    | simple_expression relop simple_expression
    ;
simple_expression : term
    | simple_expression addop term
    ;

term : factor
    | term mulop factor
    ;

factor : ID tail
    | ID LPAREN expression_list RPAREN
    | NUM
    | addop NUM
    | STRING
    | LPAREN expression RPAREN
    | NOT factor
    ;

addop : PLUS
    | MINUS
    ;

mulop : STAR
    | SLASH
    ;

relop : LT
    | GT
    | EQUAL
    | LE
    | GE
    | notEQUAL
    ;

%%

#include "lex.yy.c"

int main(int argc, char** argv) {
  /*int i, tok;
  yyin = fopen("test.txt", "r");
  for (i = 0; 1==1; i ++) {
    tok = yylex();
    //fprintf(stderr, "%3d-th token(type:%d) on line %d : %s\n", i, tok,line_no, yytext);
  }*/
  int errorF = yyparse();
  if (!errorF) fprintf(stderr,"OK");
  return(0);
} /* end of main */
