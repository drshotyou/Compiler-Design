%{
/*
 * scanner.l
 *
 * lex input file for pascal scanner
 *
 * extensions: two ways to spell "external" and "->" ok for "^".
 */

 #include <stdio.h>

 #define   PROGRAM        1
 #define   ID             2
 #define   LPAREN         3
 #define   RPAREN         4
 #define   SEMICOLON      5
 #define   DOT            6
 #define   COMMA          7
 #define   VAR            8
 #define   COLON          9
 #define   ARRAY          10
 #define   LBRAC          11
 #define   RBRAC          12
 #define   NUM            13
 #define   STRING         14
 #define   OF             15
 #define   INTEGER        16
 #define   REAL           17
 #define   FUNCTION       18
 #define   PROCEDURE      19           
 #define   BEGINS          20 
 #define   END            21
 #define   ASSIGNOP       22    
 #define   IF             23
 #define   THEN           24
 #define   ELSE           25
 #define   WHILE          26 
 #define   DO             27 
 #define   LT             28
 #define   GT             29
 #define   LE             30     
 #define   GE             31        
 #define   EQUAL          32 
 #define   NOTEQUAL       33    
 #define   PLUS           34
 #define   MINUS          35 
 #define   MULTIPLY       36    
 #define   DIVIDE         37  
 #define   NOT            38 
 #define   DOTDOT         39  
 #define   COMMENTC       40
 #define   COMMENTCC      41
 #define   YYSTYPE char *;

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
[_a-zA-Z][_a-zA-z0-9]+                    return(ID);
"("                                       return(LPAREN);
")"                                       return(RPAREN);
";"                                       return(SEMICOLON);
"."                                       return(DOT);
","                                       return(COMMA);
":"                                       return(COLON);
"["                                       return(LBRAC);
"]"                                       return(RBRAC);
[-+]?[0-9]+(\.[0-9]+)?(\E[-+]?[0-9]+)?    return(NUM);
\"                                        {ans=1;yymore();BEGIN(IN_STRING);}
<IN_STRING>{
    \"          { yymore();
                  if(ans)
                  {
                      BEGIN(INITIAL);return(STRING);
                  }else{
                      BEGIN(INITIAL);fprintf(stderr,"Lexical analyzer error at line %d : %s\n",line_no,yytext);
                  }}
    .   {yymore();}
    \\(\n)      { yymore();
                  ans=1;char* str;
                  str=strdup(yytext);
                  int len=strlen(str);

                  yytext[len-1]='\n';   
                  yytext[len]='\0';
                  line_no++;}
    \n          { yymore();
                  ans=0;
                  line_no++;}
    
}                                        
":="                                      return(ASSIGNOP);
"<"                                       return(LT);
">"                                       return(GT);
"<="                                      return(LE);
">="                                      return(GE);
"="                                       return(EQUAL);
"!="                                      return(NOTEQUAL);
"+"                                       return(PLUS);
"-"                                       return(MINUS);
"*"                                       return(MULTIPLY);
"/"                                       return(DIVIDE);
".."                                      return(DOTDOT);
\/\*                                      {yymore();BEGIN(IN_COMMENT);}
<IN_COMMENT>{
"/*"    {yymore();}
\*\/    {yymore();BEGIN(INITIAL);return(COMMENTC);}
. {yymore();}
\n  {yymore();line_no++;}    
}
"//".*                                    return(COMMENTCC);
[ \t]+                                            ;
\r                                                  ;
\n                                          line_no++;

"(*"   |
"{"    { register int c;
        while ((c = input()))
        {
            if (c == '}')
            {
                break;
            }
            else if (c == '*')
            {
                if ((c = input()) == ')')
                {
                    break;
                }
                else
                {
                    unput (c);
                }
            }
        else if (c == '\n')
        {
        line_no++;
        }
        else if (c == 0)
        {
            fprintf (stderr, "Unexpected EOF inside comment at line %d\n",line_no);
        }
        }
}
    

    .    {fprintf(stderr,"Lexical analyzer error at line %d : %s\n",line_no,yytext);}

%%


int main(int argc, char** argv) {
  int i, tok;
  yyin = fopen("test.txt", "r");
  for (i = 0; 1==1; i ++) {
    tok = yylex();
    fprintf(stderr, "%3d-th token(type:%d) on line %d : %s\n", i, tok,line_no, yytext);
  }
  return(0);
} /* end of main */

yywrap() {
  fclose(yyin);
  exit(1);
}