%{
/* 
 *  MINI-PASCAL-GRAMMAR
 *  
 *  Course: Introduction to Compiler Design
 *  Subject: LEX .l file
 *  Writer_ID: 0416047
 */

#include <stdio.h>
#include <stdlib.h>
#include "y.tab.h"
#include "node.h"

int line_no = 1;
int ans = 0;
struct nodeType* newTokenNode(int tokenType)
{
  struct nodeType *node = newNode(NODE_TOKEN);
  node->tokenType = tokenType;

  return node;
}

%}

A [aA]
B [bB]
C [cC]
D [dD]
E [eE]
F [fF]
G [gG]
H [hH]
I [iI]
J [jJ]
K [kK]
L [lL]
M [mM]
N [nN]
O [oO]
P [pP]
Q [qQ]
R [rR]
S [sS]
T [tT]
U [uU]
V [vV]
W [wW]
X [xX]
Y [yY]
Z [zZ]
NQUOTE [^'"\n]
%x IN_STRING
%x IN_COMMENT
%%


{P}{R}{O}{G}{R}{A}{M}       {yylval.node = newTokenNode(PROGRAM);yylval.node->lineno=line_no;return(PROGRAM);}
{E}{L}{S}{E}                {yylval.node = newTokenNode(ELSE);return(ELSE);}
{W}{H}{I}{L}{E}             {yylval.node = newTokenNode(WHILE);return(WHILE);}
{D}{O}                      {yylval.node = newTokenNode(DO);return(DO);}
{T}{H}{E}{N}                {yylval.node = newTokenNode(THEN);return(THEN);}
{I}{F}                      {yylval.node = newTokenNode(IF);return(IF);}
{O}{F}                      {yylval.node = newTokenNode(OF);return(OF);}
{F}{U}{N}{C}{T}{I}{O}{N}    {yylval.node = newTokenNode(FUNCTION);yylval.node->lineno=line_no;return(FUNCTION);}
{P}{R}{O}{C}{E}{D}{U}{R}{E} {yylval.node = newTokenNode(PROCEDURE);yylval.node->lineno=line_no;return(PROCEDURE);}
{B}{E}{G}{I}{N}             {yylval.node = newTokenNode(begin);return(begin);}
{E}{N}{D}                   {yylval.node = newTokenNode(END);yylval.node->lineno=line_no;return(END);}
{A}{R}{R}{A}{Y}             {yylval.node = newTokenNode(ARRAY);yylval.node->lineno=line_no;return(ARRAY);}
{V}{A}{R}                   {yylval.node = newTokenNode(VAR);return(VAR);}
{N}{O}{T}                   {yylval.node = newTokenNode(NOT);return(NOT);}
{I}{N}{T}{E}{G}{E}{R}       {yylval.node = newTokenNode(INTEGER);yylval.node->lineno=line_no;return(INTEGER);}
{R}{E}{A}{L}                {yylval.node = newTokenNode(REAL);yylval.node->lineno=line_no;return(REAL);}
{S}{T}{R}{I}{N}{G}          {yylval.node = newTokenNode(STRING);yylval.node->lineno=line_no;return(STRING);}
{C}{H}{A}{R}                {yylval.node = newTokenNode(CHAR);yylval.node->lineno=line_no;return(CHAR);}
{A}{N}{D}                   {yylval.node = newTokenNode(AND);yylval.node->lineno=line_no;return(AND);}
{O}{R}                      {yylval.node = newTokenNode(OR);yylval.node->lineno=line_no;return(OR);}
[\'][a-zA-Z][\']            {yylval.node = newTokenNode(NODE_Char);yylval.node->lineno=line_no;yylval.node->string=strdup(yytext);return(Char);}
[\"].*[\"]                  {yylval.node = newTokenNode(NODE_String);yylval.node->lineno=line_no;yylval.node->string=strdup(yytext);return(String);}
[\_]*[a-zA-Z][a-zA-Z0-9_]*  {yylval.node = newTokenNode(NODE_ID);yylval.node->lineno=line_no;yylval.node->nodeType=NODE_ID;yylval.node->string=strdup(yytext);return(ID);}

":="                         {yylval.node = newTokenNode(ASSIGNMENT);yylval.node->lineno=line_no;return(ASSIGNMENT);}
":"                          {yylval.node = newTokenNode(COLON);return(COLON);}
","                          {yylval.node = newTokenNode(COMMA);return(COMMA);}
"."                          {yylval.node = newTokenNode(DOT);return(DOT);}
".."                         {yylval.node = newTokenNode(DOTDOT);return(DOTDOT);}
"="                          {yylval.node = newTokenNode(TOK_REL_OP);yylval.node->lineno=line_no;yylval.node->op = OP_EQUAL;return(EQUAL);}
"!="                         {yylval.node = newTokenNode(TOK_REL_OP);yylval.node->lineno=line_no;yylval.node->op = OP_notEQUAL;return(notEQUAL);}
">="                         {yylval.node = newTokenNode(TOK_REL_OP);yylval.node->lineno=line_no;yylval.node->op = OP_GE;return(GE);}
">"                          {yylval.node = newTokenNode(TOK_REL_OP);yylval.node->lineno=line_no;yylval.node->op = OP_GT;return(GT);}
"["                          {yylval.node = newTokenNode(LBRAC);return(LBRAC);}
"<="                         {yylval.node = newTokenNode(TOK_REL_OP);yylval.node->lineno=line_no;yylval.node->op = OP_LE;return(LE);}
"("                          {yylval.node = newTokenNode(LPAREN);return(LPAREN);}
"<"                          {yylval.node = newTokenNode(TOK_REL_OP);yylval.node->lineno=line_no;yylval.node->op = OP_LT;return(LT);}
"-"                          {yylval.node = newTokenNode(TOK_REL_OP);yylval.node->lineno=line_no;yylval.node->op = OP_MINUS;return(MINUS);}
"+"                          {yylval.node = newTokenNode(TOK_REL_OP);yylval.node->lineno=line_no;yylval.node->op = OP_PLUS;return(PLUS);}
"]"                          {yylval.node = newTokenNode(RBRAC);return(RBRAC);}
")"                          {yylval.node = newTokenNode(RPAREN);return(RPAREN);}
";"                          {yylval.node = newTokenNode(SEMICOLON);return(SEMICOLON);}
"/"                          {yylval.node = newTokenNode(TOK_REL_OP);yylval.node->lineno=line_no;yylval.node->op = OP_SLASH;return(SLASH);}
"*"                          {yylval.node = newTokenNode(TOK_REL_OP);yylval.node->lineno=line_no;yylval.node->op = OP_MUL;return(STAR);}


([0-9]+) {yylval.node = newTokenNode(NUM);yylval.node->lineno=line_no;yylval.node->valueValid = VALUE_I_VALID;yylval.node->iValue = atoi(yytext);return(NUM); }
([0-9]+"."[0-9]+) {yylval.node = newTokenNode(NUM);yylval.node->lineno=line_no;yylval.node->valueValid = VALUE_R_VALID;yylval.node->rValue = atof(yytext);return(NUM); }
([0-9]+[E][\+\-][0-9]+)|([0-9]+"."[0-9]+[E][\+\-][0-9]+) {yylval.node = newTokenNode(NUM);yylval.node->lineno=line_no;yylval.node->valueValid = VALUE_R_VALID;yylval.node->rValue = atof(yytext);return(NUM); }




"//".*[\r\n]        {
                      //fprintf (stderr, "This is a comment at line %d: %s\n ",line_no,yytext);
                      line_no++;
                    }



[ \t\f]    ;

\r         ;
\n    line_no++;

.    {fprintf(stderr,"Lexical analyzer error at line %d : %s\n",line_no,yytext);}

%%



