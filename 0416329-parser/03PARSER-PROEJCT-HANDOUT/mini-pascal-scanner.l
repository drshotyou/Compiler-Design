%{
/*
 * scanner.l
 *
 * lex input file for pascal scanner
 *
 * extensions: two ways to spell "external" and "->" ok for "^".
 */

 #include <stdio.h>
 #include "y.tab.h"
 int line_no = 1;
 int ans = 0;
 int cc = 0;
 int chars = 0;

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

%x IN_COMMENT
%x IN_STRING


%%
"["                                       return(LBRAC);
"]"                                       return(RBRAC);
{P}{R}{O}{G}{R}{A}{M}                     return(PROGRAM);
{V}{A}{R}                                 return(VAR);
{A}{R}{R}{A}{Y}                           return(ARRAY);
{F}{U}{N}{C}{T}{I}{O}{N}                  return(FUNCTION);
{P}{R}{O}{C}{E}{D}{U}{R}{E}               return(PROCEDURE);
{B}{E}{G}{I}{N}                           return(BEGINS);
{E}{N}{D}                                 return(END);
{O}{F}                                    return(OF);
{I}{F}                                    return(IF);
{T}{H}{E}{N}                              return(THEN);
{E}{L}{S}{E}                              return(ELSE);
{W}{H}{I}{L}{E}                           return(WHILE);
{D}{O}                                    return(DO);
{N}{O}{T}                                 return(NOT);
{I}{N}{T}{E}{G}{E}{R}                     return(INTEGER);
{R}{E}{A}{L}                              return(REAL);
{A}{N}{D}                                 return(AND);
{O}{R}                                    return(OR);
(_)?[a-zA-Z]+[0-9]*                       return(ID);
"("                                       return(LPAREN);
")"                                       return(RPAREN);
";"                                       return(SEMICOLON);
"."                                       return(DOT);
","                                       return(COMMA);
":"                                       return(COLON);
[0-9]+(\.[0-9]+)?(\E[-+]?[0-9]+)?    return(NUM);
\"                                        {ans=1;BEGIN(IN_STRING);}
<IN_STRING>{
    \"          {
                  if(ans)
                  {
                      BEGIN(INITIAL);return(STRING);
                  }else{
                      BEGIN(INITIAL);
                      }

                  }
    .   ;
    \\(\n)      { ans=1;
                  line_no++;}
    \n          { ans=0;
                  line_no++;}

}
":="                                      return(ASSIGNOP);
"<"                                       return(LT);
">"                                       return(GT);
"<="                                      return(LE);
">="                                      return(GE);
"="                                       return(EQUAL);
"!="                                      return(notEQUAL);
"+"                                       return(PLUS);
"-"                                       return(MINUS);
"*"                                       return(STAR);
"/"                                       return(SLASH);
".."                                      return(DOTDOT);
\/\*                                      {BEGIN(IN_COMMENT);}
<IN_COMMENT>{
"/*"    ;
\*\/    {BEGIN(INITIAL);}
.       ;
\n      {line_no++;}
}
"//".*    ;
[ \t]+    ;
\r        ;
\n        line_no++;

    .     ;

%%

yywrap() {
  return 1;
}
