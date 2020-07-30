%{
/***************
*input type:String,Char,NUM
*number:int,float,scientific
****************/
#include<stdio.h>
#include<stdlib.h>
#include <string.h>
#include "symtab.h"

//#include "symtab.c"
//#include "node.c"

extern int line_no;
int yydebug=1;
int yylex();
struct nodeType* newOpNode(int op);
extern struct nodeType* ASTRoot;


void yyerror (char const *s){
    extern char *yytext;
    extern int line_no;
    fprintf (stderr, "%s: at line %d symbol'%s'\n", s,line_no,yytext);
 }
%}

/* The union structure for yylval
   Here all terminals/nonterminals are represented by the same type
   you can add other types, and use yylval.type to access the union field */
%union {
    struct nodeType *node;
}

/* Declare the types for each terminal/nonterminal */
%token <node> PROGRAM ELSE WHILE DO THEN IF OF FUNCTION PROCEDURE begin
%token <node> END ARRAY VAR NOT STRING ASSIGNMENT COLON COMMA INTEGER 
%token <node> DOT DOTDOT EQUAL notEQUAL GE GT LBRAC LE LPAREN LT 
%token <node> MINUS PLUS RBRAC REAL RPAREN SEMICOLON SLASH STAR CHAR  
%token <node> NUM TOK_REL_OP
%token <node> String Char ID
%token <node> AND OR HASH incVal


%type <node> prog identifier_list declarations type standard_type subprogram_declarations
%type <node> subprogram_declaration subprogram_head arguments parameter_list optional_var
%type <node> compound_statement optional_statements statement_list statement variable
%type <node> tail procedure_statement expression_list expression simple_expression term
%type <node> factor addop mulop relop  boolexpression num

%%



prog : PROGRAM ID LPAREN identifier_list RPAREN SEMICOLON
      declarations
      subprogram_declarations
      compound_statement
      DOT{
        $$=newNode(NODE_prog);
        $$->string=$2->string;//program name
        //printf("program name:%s\n",$2->string);
        //addChild($$,$4);
        addChild($$,$7);
        addChild($$,$8);
        addChild($$,$9);
        ASTRoot = $$;
        deleteNode($1);
        deleteNode($3);
        deleteNode($5);
        deleteNode($6);
        deleteNode($10);
      }
   ;

identifier_list : ID{
      $$=newNode(NODE_identifier_list);
      $$->lineno=line_no;
      $1->nodeType=NODE_ID;
      addChild($$,$1);
    }
  | identifier_list COMMA ID{
      $$=$1;
      $3->nodeType=NODE_ID;
      addChild($$,$3);
      deleteNode($2);
    }
  ;

declarations : declarations VAR identifier_list COLON type SEMICOLON{
      
      $$=newNode(NODE_declarations);
      addChild($$,$1);     
      addChild($$,$3);
      addChild($$,$5);
      deleteNode($2);
      deleteNode($4);
      deleteNode($6);
    }
  | {
      $$=newNode(NODE_declarations);
    }
  ;

type : standard_type{
      $$=$1;
    }
  | ARRAY LBRAC num DOTDOT num RBRAC OF type{ 
      $$=$1;
      $$->nodeType=NODE_TYPE_ARRAY;
      $3->nodeType = NODE_NUM;
      addChild($$,$3);
      $5->nodeType = NODE_NUM;
      addChild($$,$5);
      addChild($$,$8);

      deleteNode($2);
      deleteNode($4);
      deleteNode($6);
      deleteNode($7);
    }
  ;

standard_type : INTEGER{
      $$=$1;
      $$->nodeType = NODE_TYPE_INT;
    }
  | REAL{
      $$=$1;
      $$->nodeType = NODE_TYPE_REAL;
    }
    | STRING{
        $$=$1;
        $$->nodeType = NODE_TYPE_STRING;
      }
    | CHAR{
        $$=$1;
        $$->nodeType = NODE_TYPE_CHAR;
      }
    ;

subprogram_declarations : subprogram_declarations subprogram_declaration SEMICOLON{
     
      $$=newNode(NODE_subprogram_declarations);
      addChild($$,$1);
      addChild($$,$2);
      
      deleteNode($3);
    }
  | {
      $$=newNode(NODE_subprogram_declarations);
    }
  ;

subprogram_declaration : subprogram_head declarations compound_statement{
              $$=newNode(NODE_subprogram_declaration);
              addChild($$,$1);
              addChild($$,$2);
              addChild($$,$3);
            } 
            ;

subprogram_head : FUNCTION ID arguments COLON standard_type SEMICOLON{//funcion declaration
      $$=newNode(NODE_subprogram_head);
      $2->nodeType=NODE_FUNCTION;
      addChild($$,$2);
      addChild($$,$3);
      addChild($$,$5);
      deleteNode($1);
      deleteNode($4);
      deleteNode($6);
    }
  | PROCEDURE ID arguments SEMICOLON{//procedure declaration
      $$=newNode(NODE_subprogram_head);
      $2->nodeType=NODE_PROCEDURE;
      addChild($$,$2);
      addChild($$,$3);
      deleteNode($1);
    } 
  ;


arguments : LPAREN parameter_list RPAREN{
      $$=$2;
      deleteNode($1);
      deleteNode($3);
    }
  | {
      $$=newNode(NODE_arguments);  
    }
  ;


parameter_list : optional_var identifier_list COLON type{
      $$=newNode(NODE_parameter_list);
      addChild($$,$2);
      addChild($$,$4);
      deleteNode($3);
    }
  | optional_var identifier_list COLON type SEMICOLON parameter_list{
      $$=newNode(NODE_parameter_list);
      addChild($$,$2);
      addChild($$,$4);
      addChild($$,$6);
      deleteNode($3);
      deleteNode($5);
    } 
  ;

optional_var : VAR{
        
      }
      | {
         
      }
      ;

compound_statement : begin optional_statements END{
      $$=newNode(NODE_compound_statement);
      addChild($$,$2);
      $3->nodeType=NODE_END;
      addChild($$,$3);
      deleteNode($1);
    }
  ;



optional_statements : statement_list{
      $$=$1;
    } 
  ;


statement_list : statement {
      
      $$=newNode(NODE_statement_list);
      addChild($$,$1);
    }
  | statement_list SEMICOLON statement{
      
      $$=newNode(NODE_statement_list);
      addChild($$,$1);
      addChild($$,$3);
      deleteNode($2);
    }
  | statement_list HASH incVal
  {

    $$=newNode(NODE_statement_list);
    addChild($$,$1);
  }
  ;


statement : variable ASSIGNMENT expression{
      $$=$2;
      $$->nodeType=NODE_ASSIGNMENT;
      addChild($$,$1);
      addChild($$,$3); 
    }
  | procedure_statement{
      $$=$1;
    }
  | compound_statement{
      $$=$1;
    }
  | IF expression THEN statement ELSE statement{
      $$=newNode(NODE_if);
      addChild($$,$2);
      addChild($$,$4);
      addChild($$,$6);
      deleteNode($1);
      deleteNode($3);
      deleteNode($5);
    }
  | WHILE expression DO statement{
      $$=newNode(NODE_while);
      addChild($$,$2);
      addChild($$,$4);
      deleteNode($1);
      deleteNode($3);
    }
  | {
      $$=newNode(NODE_statement);
    }

  ;


variable : ID tail {
      $$=$1;
      $1->nodeType=NODE_SYM_REF;
      addChild($$,$2);
    }
  ;


tail : LBRAC expression RBRAC tail{
      $$=newNode(NODE_tail);
      addChild($$,$2);
      addChild($$,$4);
      deleteNode($1);
      deleteNode($3);
    }
  | {
      $$=newNode(NODE_tail);  
    } 
  ;


procedure_statement : ID{
      $$=newNode(NODE_procedure_statement);
      $1->nodeType=NODE_ID;
      addChild($$,$1);
    }
  | ID LPAREN expression_list RPAREN{
      $$=newNode(NODE_procedure_statement);
      $1->nodeType=NODE_ID;
      addChild($$,$1);
      addChild($$,$3);
      deleteNode($2);
      deleteNode($4);
    }
  ;


expression_list : expression{
      $$=$1;
    }
  | expression_list COMMA expression{
      $$=$1;
      addChild($$,$3);
      deleteNode($2);
    }
  ;
expression : boolexpression {
    $$ = $1;
}
| boolexpression AND boolexpression {
  $$ = newNode(AND);
  addChild($$,$1);
  addChild($$,$2);
}
| boolexpression OR boolexpression {
  $$ = newNode(OR);
  addChild($$,$1);
  addChild($$,$2);
}
;

boolexpression : simple_expression {
      $$=$1;
    }
  | simple_expression relop simple_expression{
      $$=$2;
      addChild($$,$1);
      addChild($$,$3);
    }
  ;


simple_expression : term{
      $$=$1;

    }
  | simple_expression PLUS term{
      $$=$2;
      addChild($$,$1);
      addChild($$,$3);
    }
  | simple_expression MINUS term {
       $$=$2;
      addChild($$,$1);
      addChild($$,$3);
  }
  ;


term : factor{
      $$=$1;
    }
  | term mulop factor{
      $$=$2;
      addChild($$,$1);
      addChild($$,$3);
    }
  ;


factor : ID tail{
      $$=$1;
      $$->nodeType=NODE_ID;
      addChild($$,$2);
    }
  | ID LPAREN expression_list RPAREN{
      $$=$1;
      $$->nodeType=NODE_ID;
      addChild($$,$3);
      deleteNode($2);
      deleteNode($4);
    }
  | num {
    $$=$1;
    }
  | String{
      $$=$1;
      $$->nodeType=NODE_String;
    }
  | Char{
      $$=$1;
      $$->nodeType=NODE_Char;
    }     
  | LPAREN expression RPAREN{
      $$=$2;
      deleteNode($1);
      deleteNode($3);
    }
  | NOT factor{
      $$=newNode(NODE_factor);
      int lineno=$1->lineno;
      $1=newOpNode(OP_NOT);
      $1->lineno=lineno;

      addChild($$,$1);
      addChild($$,$2);
    }
  ;

num : 
    NUM  
    {
      $$=$1;
        $$->nodeType=NODE_NUM;
        $$->string=$1->string;
    }
    | PLUS num
    {
      $$=newOpNode(OP_PLUS);
      $$->lineno=$1->lineno;
      addChild($$,$2);
      deleteNode($1);
    }
    | MINUS num
    {
      $$=newOpNode(OP_MINUS);
      $$->lineno=$1->lineno;
      addChild($$,$2);
    }
;


mulop : STAR {
      $$=newOpNode(OP_MUL);
      $$->lineno=$1->lineno;
      deleteNode($1);
    }
    | SLASH{
      $$=newOpNode(OP_SLASH);
      $$->lineno=$1->lineno;
      deleteNode($1);
    }
    ;



relop : LT {
      $$=newOpNode(OP_LT);
      $$->lineno=$1->lineno;
      deleteNode($1);
    }
  | GT{
      $$=newOpNode(OP_GT);
      $$->lineno=$1->lineno;
      deleteNode($1);
    }
  | EQUAL{
      $$=newOpNode(OP_EQUAL);
      $$->lineno=$1->lineno;
      deleteNode($1);
    }
  | LE{
      $$=newOpNode(OP_LE);
      $$->lineno=$1->lineno;
      deleteNode($1);
    }
  | GE{
      $$=newOpNode(OP_GE);
      $$->lineno=$1->lineno;
      deleteNode($1);
    }
  | notEQUAL{
      $$=newOpNode(OP_notEQUAL);
      $$->lineno=$1->lineno;
      deleteNode($1);
    }
  ;

%%
//# include "lex.yy.c"
int yywrap()
{
    return 1;
} 

struct nodeType *ASTRoot;

struct nodeType* newOpNode(int op) {
    struct nodeType *node = newNode(NODE_OP);
    node->op = op;

    return node;
}
int main(int argc, char** argv)
{
  int res;

  if(argc>1 && freopen(argv[1],"r",stdin)==NULL){exit(1);}
    printf("call yyparse\n");
  res = yyparse();
  printTree(ASTRoot,0);
  if(res > 0)
  {
    fprintf(stderr, "after call yyparse, res = %d.\n", res);
    return 0;
  }
    if(res==0)
    {
        printf("********************************\n"
         "*       No syntax error!       *\n"
         "********************************\n");
    }
  

  
  //printf("semantic check starting\n\n\n");
  SymbolTable.size = 0;
  SymbolTable.status=1;
  ScopeStack[0]=&SymbolTable;
  //printf("Create a new Scope\n");
  //printf("Create a new SymbolTable\n");
  semanticCheck(ASTRoot);
  //printf("Close a scope\n");
  //printf("Close a SymbolTable\n");

  

  printTable();
  return 0;
}