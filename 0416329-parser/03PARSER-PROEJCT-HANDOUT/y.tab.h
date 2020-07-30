/* A Bison parser, made by GNU Bison 3.3.2.  */

/* Bison interface for Yacc-like parsers in C

   Copyright (C) 1984, 1989-1990, 2000-2015, 2018-2019 Free Software Foundation,
   Inc.

   This program is free software: you can redistribute it and/or modify
   it under the terms of the GNU General Public License as published by
   the Free Software Foundation, either version 3 of the License, or
   (at your option) any later version.

   This program is distributed in the hope that it will be useful,
   but WITHOUT ANY WARRANTY; without even the implied warranty of
   MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
   GNU General Public License for more details.

   You should have received a copy of the GNU General Public License
   along with this program.  If not, see <http://www.gnu.org/licenses/>.  */

/* As a special exception, you may create a larger work that contains
   part or all of the Bison parser skeleton and distribute that work
   under terms of your choice, so long as that work isn't itself a
   parser generator using the skeleton or a modified version thereof
   as a parser skeleton.  Alternatively, if you modify or redistribute
   the parser skeleton itself, you may (at your option) remove this
   special exception, which will cause the skeleton and the resulting
   Bison output files to be licensed under the GNU General Public
   License without this special exception.

   This special exception was added by the Free Software Foundation in
   version 2.2 of Bison.  */

/* Undocumented macros, especially those whose name start with YY_,
   are private implementation details.  Do not rely on them.  */

#ifndef YY_YY_Y_TAB_H_INCLUDED
# define YY_YY_Y_TAB_H_INCLUDED
/* Debug traces.  */
#ifndef YYDEBUG
# define YYDEBUG 0
#endif
#if YYDEBUG
extern int yydebug;
#endif

/* Token type.  */
#ifndef YYTOKENTYPE
# define YYTOKENTYPE
  enum yytokentype
  {
    PROGRAM = 258,
    ELSE = 259,
    WHILE = 260,
    DO = 261,
    THEN = 262,
    IF = 263,
    OF = 264,
    FUNCTION = 265,
    PROCEDURE = 266,
    BEGINS = 267,
    END = 268,
    ARRAY = 269,
    VAR = 270,
    NOT = 271,
    STRING = 272,
    ASSIGNOP = 273,
    COLON = 274,
    COMMA = 275,
    INTEGER = 276,
    DOT = 277,
    DOTDOT = 278,
    EQUAL = 279,
    notEQUAL = 280,
    GE = 281,
    GT = 282,
    LBRAC = 283,
    LE = 284,
    LPAREN = 285,
    LT = 286,
    MINUS = 287,
    PLUS = 288,
    RBRAC = 289,
    REAL = 290,
    RPAREN = 291,
    SEMICOLON = 292,
    SLASH = 293,
    STAR = 294,
    CHAR = 295,
    NUM = 296,
    ID = 297,
    COMMENTC = 298,
    COMMENTCC = 299,
    AND = 300,
    OR = 301
  };
#endif
/* Tokens.  */
#define PROGRAM 258
#define ELSE 259
#define WHILE 260
#define DO 261
#define THEN 262
#define IF 263
#define OF 264
#define FUNCTION 265
#define PROCEDURE 266
#define BEGINS 267
#define END 268
#define ARRAY 269
#define VAR 270
#define NOT 271
#define STRING 272
#define ASSIGNOP 273
#define COLON 274
#define COMMA 275
#define INTEGER 276
#define DOT 277
#define DOTDOT 278
#define EQUAL 279
#define notEQUAL 280
#define GE 281
#define GT 282
#define LBRAC 283
#define LE 284
#define LPAREN 285
#define LT 286
#define MINUS 287
#define PLUS 288
#define RBRAC 289
#define REAL 290
#define RPAREN 291
#define SEMICOLON 292
#define SLASH 293
#define STAR 294
#define CHAR 295
#define NUM 296
#define ID 297
#define COMMENTC 298
#define COMMENTCC 299
#define AND 300
#define OR 301

/* Value type.  */
#if ! defined YYSTYPE && ! defined YYSTYPE_IS_DECLARED
typedef int YYSTYPE;
# define YYSTYPE_IS_TRIVIAL 1
# define YYSTYPE_IS_DECLARED 1
#endif


extern YYSTYPE yylval;

int yyparse (void);

#endif /* !YY_YY_Y_TAB_H_INCLUDED  */
