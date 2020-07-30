/* A Bison parser, made by GNU Bison 3.4.1.  */

/* Bison implementation for Yacc-like parsers in C

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

/* C LALR(1) parser skeleton written by Richard Stallman, by
   simplifying the original so-called "semantic" parser.  */

/* All symbols defined below should begin with yy or YY, to avoid
   infringing on user name space.  This should be done even for local
   variables, as they might otherwise be expanded by user macros.
   There are some unavoidable exceptions within include files to
   define necessary library symbols; they are noted "INFRINGES ON
   USER NAME SPACE" below.  */

/* Undocumented macros, especially those whose name start with YY_,
   are private implementation details.  Do not rely on them.  */

/* Identify Bison output.  */
#define YYBISON 1

/* Bison version.  */
#define YYBISON_VERSION "3.4.1"

/* Skeleton name.  */
#define YYSKELETON_NAME "yacc.c"

/* Pure parsers.  */
#define YYPURE 0

/* Push parsers.  */
#define YYPUSH 0

/* Pull parsers.  */
#define YYPULL 1




/* First part of user prologue.  */
#line 1 "./parserC.y"

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

#line 97 "y.tab.c"

# ifndef YY_NULLPTR
#  if defined __cplusplus
#   if 201103L <= __cplusplus
#    define YY_NULLPTR nullptr
#   else
#    define YY_NULLPTR 0
#   endif
#  else
#   define YY_NULLPTR ((void*)0)
#  endif
# endif

/* Enabling verbose error messages.  */
#ifdef YYERROR_VERBOSE
# undef YYERROR_VERBOSE
# define YYERROR_VERBOSE 1
#else
# define YYERROR_VERBOSE 0
#endif

/* Use api.header.include to #include this header
   instead of duplicating it here.  */
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
    begin = 267,
    END = 268,
    ARRAY = 269,
    VAR = 270,
    NOT = 271,
    STRING = 272,
    ASSIGNMENT = 273,
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
    TOK_REL_OP = 297,
    String = 298,
    Char = 299,
    ID = 300,
    AND = 301,
    OR = 302,
    HASH = 303,
    incVal = 304
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
#define begin 267
#define END 268
#define ARRAY 269
#define VAR 270
#define NOT 271
#define STRING 272
#define ASSIGNMENT 273
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
#define TOK_REL_OP 297
#define String 298
#define Char 299
#define ID 300
#define AND 301
#define OR 302
#define HASH 303
#define incVal 304

/* Value type.  */
#if ! defined YYSTYPE && ! defined YYSTYPE_IS_DECLARED
union YYSTYPE
{
#line 31 "./parserC.y"

    struct nodeType *node;

#line 242 "y.tab.c"

};
typedef union YYSTYPE YYSTYPE;
# define YYSTYPE_IS_TRIVIAL 1
# define YYSTYPE_IS_DECLARED 1
#endif


extern YYSTYPE yylval;

int yyparse (void);

#endif /* !YY_YY_Y_TAB_H_INCLUDED  */



#ifdef short
# undef short
#endif

#ifdef YYTYPE_UINT8
typedef YYTYPE_UINT8 yytype_uint8;
#else
typedef unsigned char yytype_uint8;
#endif

#ifdef YYTYPE_INT8
typedef YYTYPE_INT8 yytype_int8;
#else
typedef signed char yytype_int8;
#endif

#ifdef YYTYPE_UINT16
typedef YYTYPE_UINT16 yytype_uint16;
#else
typedef unsigned short yytype_uint16;
#endif

#ifdef YYTYPE_INT16
typedef YYTYPE_INT16 yytype_int16;
#else
typedef short yytype_int16;
#endif

#ifndef YYSIZE_T
# ifdef __SIZE_TYPE__
#  define YYSIZE_T __SIZE_TYPE__
# elif defined size_t
#  define YYSIZE_T size_t
# elif ! defined YYSIZE_T
#  include <stddef.h> /* INFRINGES ON USER NAME SPACE */
#  define YYSIZE_T size_t
# else
#  define YYSIZE_T unsigned
# endif
#endif

#define YYSIZE_MAXIMUM ((YYSIZE_T) -1)

#ifndef YY_
# if defined YYENABLE_NLS && YYENABLE_NLS
#  if ENABLE_NLS
#   include <libintl.h> /* INFRINGES ON USER NAME SPACE */
#   define YY_(Msgid) dgettext ("bison-runtime", Msgid)
#  endif
# endif
# ifndef YY_
#  define YY_(Msgid) Msgid
# endif
#endif

#ifndef YY_ATTRIBUTE
# if (defined __GNUC__                                               \
      && (2 < __GNUC__ || (__GNUC__ == 2 && 96 <= __GNUC_MINOR__)))  \
     || defined __SUNPRO_C && 0x5110 <= __SUNPRO_C
#  define YY_ATTRIBUTE(Spec) __attribute__(Spec)
# else
#  define YY_ATTRIBUTE(Spec) /* empty */
# endif
#endif

#ifndef YY_ATTRIBUTE_PURE
# define YY_ATTRIBUTE_PURE   YY_ATTRIBUTE ((__pure__))
#endif

#ifndef YY_ATTRIBUTE_UNUSED
# define YY_ATTRIBUTE_UNUSED YY_ATTRIBUTE ((__unused__))
#endif

/* Suppress unused-variable warnings by "using" E.  */
#if ! defined lint || defined __GNUC__
# define YYUSE(E) ((void) (E))
#else
# define YYUSE(E) /* empty */
#endif

#if defined __GNUC__ && ! defined __ICC && 407 <= __GNUC__ * 100 + __GNUC_MINOR__
/* Suppress an incorrect diagnostic about yylval being uninitialized.  */
# define YY_IGNORE_MAYBE_UNINITIALIZED_BEGIN \
    _Pragma ("GCC diagnostic push") \
    _Pragma ("GCC diagnostic ignored \"-Wuninitialized\"")\
    _Pragma ("GCC diagnostic ignored \"-Wmaybe-uninitialized\"")
# define YY_IGNORE_MAYBE_UNINITIALIZED_END \
    _Pragma ("GCC diagnostic pop")
#else
# define YY_INITIAL_VALUE(Value) Value
#endif
#ifndef YY_IGNORE_MAYBE_UNINITIALIZED_BEGIN
# define YY_IGNORE_MAYBE_UNINITIALIZED_BEGIN
# define YY_IGNORE_MAYBE_UNINITIALIZED_END
#endif
#ifndef YY_INITIAL_VALUE
# define YY_INITIAL_VALUE(Value) /* Nothing. */
#endif


#define YY_ASSERT(E) ((void) (0 && (E)))

#if ! defined yyoverflow || YYERROR_VERBOSE

/* The parser invokes alloca or malloc; define the necessary symbols.  */

# ifdef YYSTACK_USE_ALLOCA
#  if YYSTACK_USE_ALLOCA
#   ifdef __GNUC__
#    define YYSTACK_ALLOC __builtin_alloca
#   elif defined __BUILTIN_VA_ARG_INCR
#    include <alloca.h> /* INFRINGES ON USER NAME SPACE */
#   elif defined _AIX
#    define YYSTACK_ALLOC __alloca
#   elif defined _MSC_VER
#    include <malloc.h> /* INFRINGES ON USER NAME SPACE */
#    define alloca _alloca
#   else
#    define YYSTACK_ALLOC alloca
#    if ! defined _ALLOCA_H && ! defined EXIT_SUCCESS
#     include <stdlib.h> /* INFRINGES ON USER NAME SPACE */
      /* Use EXIT_SUCCESS as a witness for stdlib.h.  */
#     ifndef EXIT_SUCCESS
#      define EXIT_SUCCESS 0
#     endif
#    endif
#   endif
#  endif
# endif

# ifdef YYSTACK_ALLOC
   /* Pacify GCC's 'empty if-body' warning.  */
#  define YYSTACK_FREE(Ptr) do { /* empty */; } while (0)
#  ifndef YYSTACK_ALLOC_MAXIMUM
    /* The OS might guarantee only one guard page at the bottom of the stack,
       and a page size can be as small as 4096 bytes.  So we cannot safely
       invoke alloca (N) if N exceeds 4096.  Use a slightly smaller number
       to allow for a few compiler-allocated temporary stack slots.  */
#   define YYSTACK_ALLOC_MAXIMUM 4032 /* reasonable circa 2006 */
#  endif
# else
#  define YYSTACK_ALLOC YYMALLOC
#  define YYSTACK_FREE YYFREE
#  ifndef YYSTACK_ALLOC_MAXIMUM
#   define YYSTACK_ALLOC_MAXIMUM YYSIZE_MAXIMUM
#  endif
#  if (defined __cplusplus && ! defined EXIT_SUCCESS \
       && ! ((defined YYMALLOC || defined malloc) \
             && (defined YYFREE || defined free)))
#   include <stdlib.h> /* INFRINGES ON USER NAME SPACE */
#   ifndef EXIT_SUCCESS
#    define EXIT_SUCCESS 0
#   endif
#  endif
#  ifndef YYMALLOC
#   define YYMALLOC malloc
#   if ! defined malloc && ! defined EXIT_SUCCESS
void *malloc (YYSIZE_T); /* INFRINGES ON USER NAME SPACE */
#   endif
#  endif
#  ifndef YYFREE
#   define YYFREE free
#   if ! defined free && ! defined EXIT_SUCCESS
void free (void *); /* INFRINGES ON USER NAME SPACE */
#   endif
#  endif
# endif
#endif /* ! defined yyoverflow || YYERROR_VERBOSE */


#if (! defined yyoverflow \
     && (! defined __cplusplus \
         || (defined YYSTYPE_IS_TRIVIAL && YYSTYPE_IS_TRIVIAL)))

/* A type that is properly aligned for any stack member.  */
union yyalloc
{
  yytype_int16 yyss_alloc;
  YYSTYPE yyvs_alloc;
};

/* The size of the maximum gap between one aligned stack and the next.  */
# define YYSTACK_GAP_MAXIMUM (sizeof (union yyalloc) - 1)

/* The size of an array large to enough to hold all stacks, each with
   N elements.  */
# define YYSTACK_BYTES(N) \
     ((N) * (sizeof (yytype_int16) + sizeof (YYSTYPE)) \
      + YYSTACK_GAP_MAXIMUM)

# define YYCOPY_NEEDED 1

/* Relocate STACK from its old location to the new one.  The
   local variables YYSIZE and YYSTACKSIZE give the old and new number of
   elements in the stack, and YYPTR gives the new location of the
   stack.  Advance YYPTR to a properly aligned location for the next
   stack.  */
# define YYSTACK_RELOCATE(Stack_alloc, Stack)                           \
    do                                                                  \
      {                                                                 \
        YYSIZE_T yynewbytes;                                            \
        YYCOPY (&yyptr->Stack_alloc, Stack, yysize);                    \
        Stack = &yyptr->Stack_alloc;                                    \
        yynewbytes = yystacksize * sizeof (*Stack) + YYSTACK_GAP_MAXIMUM; \
        yyptr += yynewbytes / sizeof (*yyptr);                          \
      }                                                                 \
    while (0)

#endif

#if defined YYCOPY_NEEDED && YYCOPY_NEEDED
/* Copy COUNT objects from SRC to DST.  The source and destination do
   not overlap.  */
# ifndef YYCOPY
#  if defined __GNUC__ && 1 < __GNUC__
#   define YYCOPY(Dst, Src, Count) \
      __builtin_memcpy (Dst, Src, (Count) * sizeof (*(Src)))
#  else
#   define YYCOPY(Dst, Src, Count)              \
      do                                        \
        {                                       \
          YYSIZE_T yyi;                         \
          for (yyi = 0; yyi < (Count); yyi++)   \
            (Dst)[yyi] = (Src)[yyi];            \
        }                                       \
      while (0)
#  endif
# endif
#endif /* !YYCOPY_NEEDED */

/* YYFINAL -- State number of the termination state.  */
#define YYFINAL  4
/* YYLAST -- Last index in YYTABLE.  */
#define YYLAST   126

/* YYNTOKENS -- Number of terminals.  */
#define YYNTOKENS  50
/* YYNNTS -- Number of nonterminals.  */
#define YYNNTS  28
/* YYNRULES -- Number of rules.  */
#define YYNRULES  69
/* YYNSTATES -- Number of states.  */
#define YYNSTATES  137

#define YYUNDEFTOK  2
#define YYMAXUTOK   304

/* YYTRANSLATE(TOKEN-NUM) -- Symbol number corresponding to TOKEN-NUM
   as returned by yylex, with out-of-bounds checking.  */
#define YYTRANSLATE(YYX)                                                \
  ((unsigned) (YYX) <= YYMAXUTOK ? yytranslate[YYX] : YYUNDEFTOK)

/* YYTRANSLATE[TOKEN-NUM] -- Symbol number corresponding to TOKEN-NUM
   as returned by yylex.  */
static const yytype_uint8 yytranslate[] =
{
       0,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     1,     2,     3,     4,
       5,     6,     7,     8,     9,    10,    11,    12,    13,    14,
      15,    16,    17,    18,    19,    20,    21,    22,    23,    24,
      25,    26,    27,    28,    29,    30,    31,    32,    33,    34,
      35,    36,    37,    38,    39,    40,    41,    42,    43,    44,
      45,    46,    47,    48,    49
};

#if YYDEBUG
  /* YYRLINE[YYN] -- Source line where rule number YYN was defined.  */
static const yytype_uint16 yyrline[] =
{
       0,    55,    55,    76,    82,    90,   100,   105,   108,   124,
     128,   132,   136,   142,   150,   155,   163,   173,   183,   188,
     194,   200,   210,   213,   218,   229,   235,   240,   247,   256,
     262,   265,   268,   277,   284,   291,   299,   306,   312,   317,
     328,   331,   337,   340,   345,   352,   355,   363,   367,   372,
     380,   383,   391,   396,   403,   406,   410,   414,   419,   431,
     437,   444,   453,   458,   467,   472,   477,   482,   487,   492
};
#endif

#if YYDEBUG || YYERROR_VERBOSE || 0
/* YYTNAME[SYMBOL-NUM] -- String name of the symbol SYMBOL-NUM.
   First, the terminals, then, starting at YYNTOKENS, nonterminals.  */
static const char *const yytname[] =
{
  "$end", "error", "$undefined", "PROGRAM", "ELSE", "WHILE", "DO", "THEN",
  "IF", "OF", "FUNCTION", "PROCEDURE", "begin", "END", "ARRAY", "VAR",
  "NOT", "STRING", "ASSIGNMENT", "COLON", "COMMA", "INTEGER", "DOT",
  "DOTDOT", "EQUAL", "notEQUAL", "GE", "GT", "LBRAC", "LE", "LPAREN", "LT",
  "MINUS", "PLUS", "RBRAC", "REAL", "RPAREN", "SEMICOLON", "SLASH", "STAR",
  "CHAR", "NUM", "TOK_REL_OP", "String", "Char", "ID", "AND", "OR", "HASH",
  "incVal", "$accept", "prog", "identifier_list", "declarations", "type",
  "standard_type", "subprogram_declarations", "subprogram_declaration",
  "subprogram_head", "arguments", "parameter_list", "optional_var",
  "compound_statement", "optional_statements", "statement_list",
  "statement", "variable", "tail", "procedure_statement",
  "expression_list", "expression", "boolexpression", "simple_expression",
  "term", "factor", "num", "mulop", "relop", YY_NULLPTR
};
#endif

# ifdef YYPRINT
/* YYTOKNUM[NUM] -- (External) token number corresponding to the
   (internal) symbol number NUM (which must be that of a token).  */
static const yytype_uint16 yytoknum[] =
{
       0,   256,   257,   258,   259,   260,   261,   262,   263,   264,
     265,   266,   267,   268,   269,   270,   271,   272,   273,   274,
     275,   276,   277,   278,   279,   280,   281,   282,   283,   284,
     285,   286,   287,   288,   289,   290,   291,   292,   293,   294,
     295,   296,   297,   298,   299,   300,   301,   302,   303,   304
};
# endif

#define YYPACT_NINF -76

#define yypact_value_is_default(Yystate) \
  (!!((Yystate) == (-76)))

#define YYTABLE_NINF -38

#define yytable_value_is_error(Yytable_value) \
  0

  /* YYPACT[STATE-NUM] -- Index in YYTABLE of the portion describing
     STATE-NUM.  */
static const yytype_int8 yypact[] =
{
      61,    24,    74,    56,   -76,    47,   -76,    -9,    48,    54,
     -76,   -76,    79,    47,    50,    38,    51,    53,     2,    60,
     -76,    77,    -5,    70,    70,     1,     1,    23,   -76,    88,
     -22,   -76,    84,   -76,   -76,    37,   -76,    75,   -76,   -76,
     -76,   -76,    67,   -76,    90,    87,    71,     1,     1,   -13,
     -13,   -76,   -76,   -76,    35,   101,    34,    46,   -17,   -76,
     -76,   102,     1,     1,   -76,   -76,     2,    62,     1,   -76,
     -13,   -76,   -76,    76,    47,    15,   -76,   -76,    78,   -76,
     -76,     1,   -76,     2,     1,     1,   -76,   -76,   -76,   -76,
     -76,   -76,     1,     1,     1,   -76,   -76,     1,     2,    81,
      -7,   -76,   -76,   -76,   -76,    93,   -76,    63,    73,   -76,
      18,   -76,   -76,   -76,   -17,   -17,    52,   -76,   109,    89,
       1,   -76,   -13,    -5,   -76,   -76,     2,   -76,   -76,    85,
      83,   -76,   112,    90,    -5,   -76,   -76
};

  /* YYDEFACT[STATE-NUM] -- Default reduction number in state STATE-NUM.
     Performed when YYTABLE does not specify something else to do.  Zero
     means the default is an error.  */
static const yytype_uint8 yydefact[] =
{
       0,     0,     0,     0,     1,     0,     3,     0,     0,     0,
       4,     6,    14,     0,     0,     0,     0,     0,    34,     0,
       6,     0,     0,    19,    19,     0,     0,    38,    31,     0,
      25,    26,     0,    30,    13,     0,     2,     0,    11,     9,
      10,    12,     0,     7,    23,     0,     0,     0,     0,     0,
       0,    59,    55,    56,    37,     0,    42,    45,    47,    50,
      54,     0,     0,     0,    35,    24,    34,     0,     0,    15,
       0,     5,    22,     0,     0,     0,    17,    58,     0,    61,
      60,     0,    52,    34,     0,     0,    66,    69,    68,    65,
      67,    64,     0,     0,     0,    63,    62,     0,    34,     0,
       0,    40,    27,    28,    29,     0,    18,     0,     0,    57,
       0,    33,    43,    44,    49,    48,    46,    51,     0,    37,
       0,    39,     0,     0,    16,    53,    34,    36,    41,     0,
      20,    32,     0,    23,     0,    21,     8
};

  /* YYPGOTO[NTERM-NUM].  */
static const yytype_int8 yypgoto[] =
{
     -76,   -76,    -8,    98,   -75,    49,   -76,   -76,   -76,    99,
     -11,   -76,     4,   -76,   -76,   -58,   -76,   -52,   -76,    44,
     -25,     3,    32,    -3,   -41,   -46,   -76,   -76
};

  /* YYDEFGOTO[NTERM-NUM].  */
static const yytype_int8 yydefgoto[] =
{
      -1,     2,     7,    12,    42,    43,    14,    19,    20,    45,
      73,    74,    28,    29,    30,    31,    32,    64,    33,   100,
     101,    56,    57,    58,    59,    60,    97,    94
};

  /* YYTABLE[YYPACT[STATE-NUM]] -- What to do in state STATE-NUM.  If
     positive, shift that token.  If negative, reduce the rule whose
     number is the opposite.  If YYTABLE_NINF, syntax error.  */
static const yytype_int16 yytable[] =
{
      55,    61,    82,    79,    80,    15,    77,    25,   102,    37,
      26,     8,    38,   120,    18,    66,    39,    47,    21,    49,
      50,    95,    96,    78,   105,   111,    67,     9,    51,   121,
      40,    48,    38,    49,    50,    41,    39,    99,   120,    69,
     118,   -37,    51,   104,    52,    53,    54,    27,   130,    18,
      40,    62,    13,    63,   125,    41,   117,    22,     8,   136,
      16,    17,    18,    62,     1,    81,   107,   127,   131,     3,
      86,    87,    88,    89,     4,    90,   129,    91,    92,    93,
      84,    85,   123,     8,    92,    93,     5,   112,   113,   114,
     115,    11,     6,    10,    13,   128,    23,    34,    24,    36,
      44,    65,    68,    70,    71,    72,    75,    83,    76,    98,
     124,   103,   106,   126,   109,   119,   122,    62,    35,   132,
     133,   134,   135,    46,   108,   110,   116
};

static const yytype_uint8 yycheck[] =
{
      25,    26,    54,    49,    50,    13,    47,     5,    66,    14,
       8,    20,    17,    20,    12,    37,    21,    16,    14,    32,
      33,    38,    39,    48,    70,    83,    48,    36,    41,    36,
      35,    30,    17,    32,    33,    40,    21,    62,    20,    35,
      98,    18,    41,    68,    43,    44,    45,    45,   123,    12,
      35,    28,    15,    30,    36,    40,    97,    19,    20,   134,
      10,    11,    12,    28,     3,    30,    74,   119,   126,    45,
      24,    25,    26,    27,     0,    29,   122,    31,    32,    33,
      46,    47,    19,    20,    32,    33,    30,    84,    85,    92,
      93,    37,    45,    45,    15,   120,    45,    37,    45,    22,
      30,    13,    18,    28,    37,    15,    19,     6,    37,     7,
      37,    49,    36,     4,    36,    34,    23,    28,    20,    34,
      37,     9,   133,    24,    75,    81,    94
};

  /* YYSTOS[STATE-NUM] -- The (internal number of the) accessing
     symbol of state STATE-NUM.  */
static const yytype_uint8 yystos[] =
{
       0,     3,    51,    45,     0,    30,    45,    52,    20,    36,
      45,    37,    53,    15,    56,    52,    10,    11,    12,    57,
      58,    62,    19,    45,    45,     5,     8,    45,    62,    63,
      64,    65,    66,    68,    37,    53,    22,    14,    17,    21,
      35,    40,    54,    55,    30,    59,    59,    16,    30,    32,
      33,    41,    43,    44,    45,    70,    71,    72,    73,    74,
      75,    70,    28,    30,    67,    13,    37,    48,    18,    62,
      28,    37,    15,    60,    61,    19,    37,    74,    70,    75,
      75,    30,    67,     6,    46,    47,    24,    25,    26,    27,
      29,    31,    32,    33,    77,    38,    39,    76,     7,    70,
      69,    70,    65,    49,    70,    75,    36,    52,    55,    36,
      69,    65,    71,    71,    73,    73,    72,    74,    65,    34,
      20,    36,    23,    19,    37,    36,     4,    67,    70,    75,
      54,    65,    34,    37,     9,    60,    54
};

  /* YYR1[YYN] -- Symbol number of symbol that rule YYN derives.  */
static const yytype_uint8 yyr1[] =
{
       0,    50,    51,    52,    52,    53,    53,    54,    54,    55,
      55,    55,    55,    56,    56,    57,    58,    58,    59,    59,
      60,    60,    61,    61,    62,    63,    64,    64,    64,    65,
      65,    65,    65,    65,    65,    66,    67,    67,    68,    68,
      69,    69,    70,    70,    70,    71,    71,    72,    72,    72,
      73,    73,    74,    74,    74,    74,    74,    74,    74,    75,
      75,    75,    76,    76,    77,    77,    77,    77,    77,    77
};

  /* YYR2[YYN] -- Number of symbols on the right hand side of rule YYN.  */
static const yytype_uint8 yyr2[] =
{
       0,     2,    10,     1,     3,     6,     0,     1,     8,     1,
       1,     1,     1,     3,     0,     3,     6,     4,     3,     0,
       4,     6,     1,     0,     3,     1,     1,     3,     3,     3,
       1,     1,     6,     4,     0,     2,     4,     0,     1,     4,
       1,     3,     1,     3,     3,     1,     3,     1,     3,     3,
       1,     3,     2,     4,     1,     1,     1,     3,     2,     1,
       2,     2,     1,     1,     1,     1,     1,     1,     1,     1
};


#define yyerrok         (yyerrstatus = 0)
#define yyclearin       (yychar = YYEMPTY)
#define YYEMPTY         (-2)
#define YYEOF           0

#define YYACCEPT        goto yyacceptlab
#define YYABORT         goto yyabortlab
#define YYERROR         goto yyerrorlab


#define YYRECOVERING()  (!!yyerrstatus)

#define YYBACKUP(Token, Value)                                    \
  do                                                              \
    if (yychar == YYEMPTY)                                        \
      {                                                           \
        yychar = (Token);                                         \
        yylval = (Value);                                         \
        YYPOPSTACK (yylen);                                       \
        yystate = *yyssp;                                         \
        goto yybackup;                                            \
      }                                                           \
    else                                                          \
      {                                                           \
        yyerror (YY_("syntax error: cannot back up")); \
        YYERROR;                                                  \
      }                                                           \
  while (0)

/* Error token number */
#define YYTERROR        1
#define YYERRCODE       256



/* Enable debugging if requested.  */
#if YYDEBUG

# ifndef YYFPRINTF
#  include <stdio.h> /* INFRINGES ON USER NAME SPACE */
#  define YYFPRINTF fprintf
# endif

# define YYDPRINTF(Args)                        \
do {                                            \
  if (yydebug)                                  \
    YYFPRINTF Args;                             \
} while (0)

/* This macro is provided for backward compatibility. */
#ifndef YY_LOCATION_PRINT
# define YY_LOCATION_PRINT(File, Loc) ((void) 0)
#endif


# define YY_SYMBOL_PRINT(Title, Type, Value, Location)                    \
do {                                                                      \
  if (yydebug)                                                            \
    {                                                                     \
      YYFPRINTF (stderr, "%s ", Title);                                   \
      yy_symbol_print (stderr,                                            \
                  Type, Value); \
      YYFPRINTF (stderr, "\n");                                           \
    }                                                                     \
} while (0)


/*-----------------------------------.
| Print this symbol's value on YYO.  |
`-----------------------------------*/

static void
yy_symbol_value_print (FILE *yyo, int yytype, YYSTYPE const * const yyvaluep)
{
  FILE *yyoutput = yyo;
  YYUSE (yyoutput);
  if (!yyvaluep)
    return;
# ifdef YYPRINT
  if (yytype < YYNTOKENS)
    YYPRINT (yyo, yytoknum[yytype], *yyvaluep);
# endif
  YYUSE (yytype);
}


/*---------------------------.
| Print this symbol on YYO.  |
`---------------------------*/

static void
yy_symbol_print (FILE *yyo, int yytype, YYSTYPE const * const yyvaluep)
{
  YYFPRINTF (yyo, "%s %s (",
             yytype < YYNTOKENS ? "token" : "nterm", yytname[yytype]);

  yy_symbol_value_print (yyo, yytype, yyvaluep);
  YYFPRINTF (yyo, ")");
}

/*------------------------------------------------------------------.
| yy_stack_print -- Print the state stack from its BOTTOM up to its |
| TOP (included).                                                   |
`------------------------------------------------------------------*/

static void
yy_stack_print (yytype_int16 *yybottom, yytype_int16 *yytop)
{
  YYFPRINTF (stderr, "Stack now");
  for (; yybottom <= yytop; yybottom++)
    {
      int yybot = *yybottom;
      YYFPRINTF (stderr, " %d", yybot);
    }
  YYFPRINTF (stderr, "\n");
}

# define YY_STACK_PRINT(Bottom, Top)                            \
do {                                                            \
  if (yydebug)                                                  \
    yy_stack_print ((Bottom), (Top));                           \
} while (0)


/*------------------------------------------------.
| Report that the YYRULE is going to be reduced.  |
`------------------------------------------------*/

static void
yy_reduce_print (yytype_int16 *yyssp, YYSTYPE *yyvsp, int yyrule)
{
  unsigned long yylno = yyrline[yyrule];
  int yynrhs = yyr2[yyrule];
  int yyi;
  YYFPRINTF (stderr, "Reducing stack by rule %d (line %lu):\n",
             yyrule - 1, yylno);
  /* The symbols being reduced.  */
  for (yyi = 0; yyi < yynrhs; yyi++)
    {
      YYFPRINTF (stderr, "   $%d = ", yyi + 1);
      yy_symbol_print (stderr,
                       yystos[yyssp[yyi + 1 - yynrhs]],
                       &yyvsp[(yyi + 1) - (yynrhs)]
                                              );
      YYFPRINTF (stderr, "\n");
    }
}

# define YY_REDUCE_PRINT(Rule)          \
do {                                    \
  if (yydebug)                          \
    yy_reduce_print (yyssp, yyvsp, Rule); \
} while (0)

/* Nonzero means print parse trace.  It is left uninitialized so that
   multiple parsers can coexist.  */
int yydebug;
#else /* !YYDEBUG */
# define YYDPRINTF(Args)
# define YY_SYMBOL_PRINT(Title, Type, Value, Location)
# define YY_STACK_PRINT(Bottom, Top)
# define YY_REDUCE_PRINT(Rule)
#endif /* !YYDEBUG */


/* YYINITDEPTH -- initial size of the parser's stacks.  */
#ifndef YYINITDEPTH
# define YYINITDEPTH 200
#endif

/* YYMAXDEPTH -- maximum size the stacks can grow to (effective only
   if the built-in stack extension method is used).

   Do not make this value too large; the results are undefined if
   YYSTACK_ALLOC_MAXIMUM < YYSTACK_BYTES (YYMAXDEPTH)
   evaluated with infinite-precision integer arithmetic.  */

#ifndef YYMAXDEPTH
# define YYMAXDEPTH 10000
#endif


#if YYERROR_VERBOSE

# ifndef yystrlen
#  if defined __GLIBC__ && defined _STRING_H
#   define yystrlen strlen
#  else
/* Return the length of YYSTR.  */
static YYSIZE_T
yystrlen (const char *yystr)
{
  YYSIZE_T yylen;
  for (yylen = 0; yystr[yylen]; yylen++)
    continue;
  return yylen;
}
#  endif
# endif

# ifndef yystpcpy
#  if defined __GLIBC__ && defined _STRING_H && defined _GNU_SOURCE
#   define yystpcpy stpcpy
#  else
/* Copy YYSRC to YYDEST, returning the address of the terminating '\0' in
   YYDEST.  */
static char *
yystpcpy (char *yydest, const char *yysrc)
{
  char *yyd = yydest;
  const char *yys = yysrc;

  while ((*yyd++ = *yys++) != '\0')
    continue;

  return yyd - 1;
}
#  endif
# endif

# ifndef yytnamerr
/* Copy to YYRES the contents of YYSTR after stripping away unnecessary
   quotes and backslashes, so that it's suitable for yyerror.  The
   heuristic is that double-quoting is unnecessary unless the string
   contains an apostrophe, a comma, or backslash (other than
   backslash-backslash).  YYSTR is taken from yytname.  If YYRES is
   null, do not copy; instead, return the length of what the result
   would have been.  */
static YYSIZE_T
yytnamerr (char *yyres, const char *yystr)
{
  if (*yystr == '"')
    {
      YYSIZE_T yyn = 0;
      char const *yyp = yystr;

      for (;;)
        switch (*++yyp)
          {
          case '\'':
          case ',':
            goto do_not_strip_quotes;

          case '\\':
            if (*++yyp != '\\')
              goto do_not_strip_quotes;
            else
              goto append;

          append:
          default:
            if (yyres)
              yyres[yyn] = *yyp;
            yyn++;
            break;

          case '"':
            if (yyres)
              yyres[yyn] = '\0';
            return yyn;
          }
    do_not_strip_quotes: ;
    }

  if (! yyres)
    return yystrlen (yystr);

  return (YYSIZE_T) (yystpcpy (yyres, yystr) - yyres);
}
# endif

/* Copy into *YYMSG, which is of size *YYMSG_ALLOC, an error message
   about the unexpected token YYTOKEN for the state stack whose top is
   YYSSP.

   Return 0 if *YYMSG was successfully written.  Return 1 if *YYMSG is
   not large enough to hold the message.  In that case, also set
   *YYMSG_ALLOC to the required number of bytes.  Return 2 if the
   required number of bytes is too large to store.  */
static int
yysyntax_error (YYSIZE_T *yymsg_alloc, char **yymsg,
                yytype_int16 *yyssp, int yytoken)
{
  YYSIZE_T yysize0 = yytnamerr (YY_NULLPTR, yytname[yytoken]);
  YYSIZE_T yysize = yysize0;
  enum { YYERROR_VERBOSE_ARGS_MAXIMUM = 5 };
  /* Internationalized format string. */
  const char *yyformat = YY_NULLPTR;
  /* Arguments of yyformat. */
  char const *yyarg[YYERROR_VERBOSE_ARGS_MAXIMUM];
  /* Number of reported tokens (one for the "unexpected", one per
     "expected"). */
  int yycount = 0;

  /* There are many possibilities here to consider:
     - If this state is a consistent state with a default action, then
       the only way this function was invoked is if the default action
       is an error action.  In that case, don't check for expected
       tokens because there are none.
     - The only way there can be no lookahead present (in yychar) is if
       this state is a consistent state with a default action.  Thus,
       detecting the absence of a lookahead is sufficient to determine
       that there is no unexpected or expected token to report.  In that
       case, just report a simple "syntax error".
     - Don't assume there isn't a lookahead just because this state is a
       consistent state with a default action.  There might have been a
       previous inconsistent state, consistent state with a non-default
       action, or user semantic action that manipulated yychar.
     - Of course, the expected token list depends on states to have
       correct lookahead information, and it depends on the parser not
       to perform extra reductions after fetching a lookahead from the
       scanner and before detecting a syntax error.  Thus, state merging
       (from LALR or IELR) and default reductions corrupt the expected
       token list.  However, the list is correct for canonical LR with
       one exception: it will still contain any token that will not be
       accepted due to an error action in a later state.
  */
  if (yytoken != YYEMPTY)
    {
      int yyn = yypact[*yyssp];
      yyarg[yycount++] = yytname[yytoken];
      if (!yypact_value_is_default (yyn))
        {
          /* Start YYX at -YYN if negative to avoid negative indexes in
             YYCHECK.  In other words, skip the first -YYN actions for
             this state because they are default actions.  */
          int yyxbegin = yyn < 0 ? -yyn : 0;
          /* Stay within bounds of both yycheck and yytname.  */
          int yychecklim = YYLAST - yyn + 1;
          int yyxend = yychecklim < YYNTOKENS ? yychecklim : YYNTOKENS;
          int yyx;

          for (yyx = yyxbegin; yyx < yyxend; ++yyx)
            if (yycheck[yyx + yyn] == yyx && yyx != YYTERROR
                && !yytable_value_is_error (yytable[yyx + yyn]))
              {
                if (yycount == YYERROR_VERBOSE_ARGS_MAXIMUM)
                  {
                    yycount = 1;
                    yysize = yysize0;
                    break;
                  }
                yyarg[yycount++] = yytname[yyx];
                {
                  YYSIZE_T yysize1 = yysize + yytnamerr (YY_NULLPTR, yytname[yyx]);
                  if (yysize <= yysize1 && yysize1 <= YYSTACK_ALLOC_MAXIMUM)
                    yysize = yysize1;
                  else
                    return 2;
                }
              }
        }
    }

  switch (yycount)
    {
# define YYCASE_(N, S)                      \
      case N:                               \
        yyformat = S;                       \
      break
    default: /* Avoid compiler warnings. */
      YYCASE_(0, YY_("syntax error"));
      YYCASE_(1, YY_("syntax error, unexpected %s"));
      YYCASE_(2, YY_("syntax error, unexpected %s, expecting %s"));
      YYCASE_(3, YY_("syntax error, unexpected %s, expecting %s or %s"));
      YYCASE_(4, YY_("syntax error, unexpected %s, expecting %s or %s or %s"));
      YYCASE_(5, YY_("syntax error, unexpected %s, expecting %s or %s or %s or %s"));
# undef YYCASE_
    }

  {
    YYSIZE_T yysize1 = yysize + yystrlen (yyformat);
    if (yysize <= yysize1 && yysize1 <= YYSTACK_ALLOC_MAXIMUM)
      yysize = yysize1;
    else
      return 2;
  }

  if (*yymsg_alloc < yysize)
    {
      *yymsg_alloc = 2 * yysize;
      if (! (yysize <= *yymsg_alloc
             && *yymsg_alloc <= YYSTACK_ALLOC_MAXIMUM))
        *yymsg_alloc = YYSTACK_ALLOC_MAXIMUM;
      return 1;
    }

  /* Avoid sprintf, as that infringes on the user's name space.
     Don't have undefined behavior even if the translation
     produced a string with the wrong number of "%s"s.  */
  {
    char *yyp = *yymsg;
    int yyi = 0;
    while ((*yyp = *yyformat) != '\0')
      if (*yyp == '%' && yyformat[1] == 's' && yyi < yycount)
        {
          yyp += yytnamerr (yyp, yyarg[yyi++]);
          yyformat += 2;
        }
      else
        {
          yyp++;
          yyformat++;
        }
  }
  return 0;
}
#endif /* YYERROR_VERBOSE */

/*-----------------------------------------------.
| Release the memory associated to this symbol.  |
`-----------------------------------------------*/

static void
yydestruct (const char *yymsg, int yytype, YYSTYPE *yyvaluep)
{
  YYUSE (yyvaluep);
  if (!yymsg)
    yymsg = "Deleting";
  YY_SYMBOL_PRINT (yymsg, yytype, yyvaluep, yylocationp);

  YY_IGNORE_MAYBE_UNINITIALIZED_BEGIN
  YYUSE (yytype);
  YY_IGNORE_MAYBE_UNINITIALIZED_END
}




/* The lookahead symbol.  */
int yychar;

/* The semantic value of the lookahead symbol.  */
YYSTYPE yylval;
/* Number of syntax errors so far.  */
int yynerrs;


/*----------.
| yyparse.  |
`----------*/

int
yyparse (void)
{
    int yystate;
    /* Number of tokens to shift before error messages enabled.  */
    int yyerrstatus;

    /* The stacks and their tools:
       'yyss': related to states.
       'yyvs': related to semantic values.

       Refer to the stacks through separate pointers, to allow yyoverflow
       to reallocate them elsewhere.  */

    /* The state stack.  */
    yytype_int16 yyssa[YYINITDEPTH];
    yytype_int16 *yyss;
    yytype_int16 *yyssp;

    /* The semantic value stack.  */
    YYSTYPE yyvsa[YYINITDEPTH];
    YYSTYPE *yyvs;
    YYSTYPE *yyvsp;

    YYSIZE_T yystacksize;

  int yyn;
  int yyresult;
  /* Lookahead token as an internal (translated) token number.  */
  int yytoken = 0;
  /* The variables used to return semantic value and location from the
     action routines.  */
  YYSTYPE yyval;

#if YYERROR_VERBOSE
  /* Buffer for error messages, and its allocated size.  */
  char yymsgbuf[128];
  char *yymsg = yymsgbuf;
  YYSIZE_T yymsg_alloc = sizeof yymsgbuf;
#endif

#define YYPOPSTACK(N)   (yyvsp -= (N), yyssp -= (N))

  /* The number of symbols on the RHS of the reduced rule.
     Keep to zero when no symbol should be popped.  */
  int yylen = 0;

  yyssp = yyss = yyssa;
  yyvsp = yyvs = yyvsa;
  yystacksize = YYINITDEPTH;

  YYDPRINTF ((stderr, "Starting parse\n"));

  yystate = 0;
  yyerrstatus = 0;
  yynerrs = 0;
  yychar = YYEMPTY; /* Cause a token to be read.  */
  goto yysetstate;


/*------------------------------------------------------------.
| yynewstate -- push a new state, which is found in yystate.  |
`------------------------------------------------------------*/
yynewstate:
  /* In all cases, when you get here, the value and location stacks
     have just been pushed.  So pushing a state here evens the stacks.  */
  yyssp++;


/*--------------------------------------------------------------------.
| yynewstate -- set current state (the top of the stack) to yystate.  |
`--------------------------------------------------------------------*/
yysetstate:
  YYDPRINTF ((stderr, "Entering state %d\n", yystate));
  YY_ASSERT (0 <= yystate && yystate < YYNSTATES);
  *yyssp = (yytype_int16) yystate;

  if (yyss + yystacksize - 1 <= yyssp)
#if !defined yyoverflow && !defined YYSTACK_RELOCATE
    goto yyexhaustedlab;
#else
    {
      /* Get the current used size of the three stacks, in elements.  */
      YYSIZE_T yysize = (YYSIZE_T) (yyssp - yyss + 1);

# if defined yyoverflow
      {
        /* Give user a chance to reallocate the stack.  Use copies of
           these so that the &'s don't force the real ones into
           memory.  */
        YYSTYPE *yyvs1 = yyvs;
        yytype_int16 *yyss1 = yyss;

        /* Each stack pointer address is followed by the size of the
           data in use in that stack, in bytes.  This used to be a
           conditional around just the two extra args, but that might
           be undefined if yyoverflow is a macro.  */
        yyoverflow (YY_("memory exhausted"),
                    &yyss1, yysize * sizeof (*yyssp),
                    &yyvs1, yysize * sizeof (*yyvsp),
                    &yystacksize);
        yyss = yyss1;
        yyvs = yyvs1;
      }
# else /* defined YYSTACK_RELOCATE */
      /* Extend the stack our own way.  */
      if (YYMAXDEPTH <= yystacksize)
        goto yyexhaustedlab;
      yystacksize *= 2;
      if (YYMAXDEPTH < yystacksize)
        yystacksize = YYMAXDEPTH;

      {
        yytype_int16 *yyss1 = yyss;
        union yyalloc *yyptr =
          (union yyalloc *) YYSTACK_ALLOC (YYSTACK_BYTES (yystacksize));
        if (! yyptr)
          goto yyexhaustedlab;
        YYSTACK_RELOCATE (yyss_alloc, yyss);
        YYSTACK_RELOCATE (yyvs_alloc, yyvs);
# undef YYSTACK_RELOCATE
        if (yyss1 != yyssa)
          YYSTACK_FREE (yyss1);
      }
# endif

      yyssp = yyss + yysize - 1;
      yyvsp = yyvs + yysize - 1;

      YYDPRINTF ((stderr, "Stack size increased to %lu\n",
                  (unsigned long) yystacksize));

      if (yyss + yystacksize - 1 <= yyssp)
        YYABORT;
    }
#endif /* !defined yyoverflow && !defined YYSTACK_RELOCATE */

  if (yystate == YYFINAL)
    YYACCEPT;

  goto yybackup;


/*-----------.
| yybackup.  |
`-----------*/
yybackup:
  /* Do appropriate processing given the current state.  Read a
     lookahead token if we need one and don't already have one.  */

  /* First try to decide what to do without reference to lookahead token.  */
  yyn = yypact[yystate];
  if (yypact_value_is_default (yyn))
    goto yydefault;

  /* Not known => get a lookahead token if don't already have one.  */

  /* YYCHAR is either YYEMPTY or YYEOF or a valid lookahead symbol.  */
  if (yychar == YYEMPTY)
    {
      YYDPRINTF ((stderr, "Reading a token: "));
      yychar = yylex ();
    }

  if (yychar <= YYEOF)
    {
      yychar = yytoken = YYEOF;
      YYDPRINTF ((stderr, "Now at end of input.\n"));
    }
  else
    {
      yytoken = YYTRANSLATE (yychar);
      YY_SYMBOL_PRINT ("Next token is", yytoken, &yylval, &yylloc);
    }

  /* If the proper action on seeing token YYTOKEN is to reduce or to
     detect an error, take that action.  */
  yyn += yytoken;
  if (yyn < 0 || YYLAST < yyn || yycheck[yyn] != yytoken)
    goto yydefault;
  yyn = yytable[yyn];
  if (yyn <= 0)
    {
      if (yytable_value_is_error (yyn))
        goto yyerrlab;
      yyn = -yyn;
      goto yyreduce;
    }

  /* Count tokens shifted since error; after three, turn off error
     status.  */
  if (yyerrstatus)
    yyerrstatus--;

  /* Shift the lookahead token.  */
  YY_SYMBOL_PRINT ("Shifting", yytoken, &yylval, &yylloc);

  /* Discard the shifted token.  */
  yychar = YYEMPTY;

  yystate = yyn;
  YY_IGNORE_MAYBE_UNINITIALIZED_BEGIN
  *++yyvsp = yylval;
  YY_IGNORE_MAYBE_UNINITIALIZED_END
  goto yynewstate;


/*-----------------------------------------------------------.
| yydefault -- do the default action for the current state.  |
`-----------------------------------------------------------*/
yydefault:
  yyn = yydefact[yystate];
  if (yyn == 0)
    goto yyerrlab;
  goto yyreduce;


/*-----------------------------.
| yyreduce -- do a reduction.  |
`-----------------------------*/
yyreduce:
  /* yyn is the number of a rule to reduce with.  */
  yylen = yyr2[yyn];

  /* If YYLEN is nonzero, implement the default value of the action:
     '$$ = $1'.

     Otherwise, the following line sets YYVAL to garbage.
     This behavior is undocumented and Bison
     users should not rely upon it.  Assigning to YYVAL
     unconditionally makes the parser a bit smaller, and it avoids a
     GCC warning that YYVAL may be used uninitialized.  */
  yyval = yyvsp[1-yylen];


  YY_REDUCE_PRINT (yyn);
  switch (yyn)
    {
  case 2:
#line 59 "./parserC.y"
    {
        (yyval.node)=newNode(NODE_prog);
        (yyval.node)->string=(yyvsp[-8].node)->string;//program name
        //printf("program name:%s\n",$2->string);
        //addChild($$,$4);
        addChild((yyval.node),(yyvsp[-3].node));
        addChild((yyval.node),(yyvsp[-2].node));
        addChild((yyval.node),(yyvsp[-1].node));
        ASTRoot = (yyval.node);
        deleteNode((yyvsp[-9].node));
        deleteNode((yyvsp[-7].node));
        deleteNode((yyvsp[-5].node));
        deleteNode((yyvsp[-4].node));
        deleteNode((yyvsp[0].node));
      }
#line 1442 "y.tab.c"
    break;

  case 3:
#line 76 "./parserC.y"
    {
      (yyval.node)=newNode(NODE_identifier_list);
      (yyval.node)->lineno=line_no;
      (yyvsp[0].node)->nodeType=NODE_ID;
      addChild((yyval.node),(yyvsp[0].node));
    }
#line 1453 "y.tab.c"
    break;

  case 4:
#line 82 "./parserC.y"
    {
      (yyval.node)=(yyvsp[-2].node);
      (yyvsp[0].node)->nodeType=NODE_ID;
      addChild((yyval.node),(yyvsp[0].node));
      deleteNode((yyvsp[-1].node));
    }
#line 1464 "y.tab.c"
    break;

  case 5:
#line 90 "./parserC.y"
    {
      
      (yyval.node)=newNode(NODE_declarations);
      addChild((yyval.node),(yyvsp[-5].node));     
      addChild((yyval.node),(yyvsp[-3].node));
      addChild((yyval.node),(yyvsp[-1].node));
      deleteNode((yyvsp[-4].node));
      deleteNode((yyvsp[-2].node));
      deleteNode((yyvsp[0].node));
    }
#line 1479 "y.tab.c"
    break;

  case 6:
#line 100 "./parserC.y"
    {
      (yyval.node)=newNode(NODE_declarations);
    }
#line 1487 "y.tab.c"
    break;

  case 7:
#line 105 "./parserC.y"
    {
      (yyval.node)=(yyvsp[0].node);
    }
#line 1495 "y.tab.c"
    break;

  case 8:
#line 108 "./parserC.y"
    { 
      (yyval.node)=(yyvsp[-7].node);
      (yyval.node)->nodeType=NODE_TYPE_ARRAY;
      (yyvsp[-5].node)->nodeType = NODE_NUM;
      addChild((yyval.node),(yyvsp[-5].node));
      (yyvsp[-3].node)->nodeType = NODE_NUM;
      addChild((yyval.node),(yyvsp[-3].node));
      addChild((yyval.node),(yyvsp[0].node));

      deleteNode((yyvsp[-6].node));
      deleteNode((yyvsp[-4].node));
      deleteNode((yyvsp[-2].node));
      deleteNode((yyvsp[-1].node));
    }
#line 1514 "y.tab.c"
    break;

  case 9:
#line 124 "./parserC.y"
    {
      (yyval.node)=(yyvsp[0].node);
      (yyval.node)->nodeType = NODE_TYPE_INT;
    }
#line 1523 "y.tab.c"
    break;

  case 10:
#line 128 "./parserC.y"
    {
      (yyval.node)=(yyvsp[0].node);
      (yyval.node)->nodeType = NODE_TYPE_REAL;
    }
#line 1532 "y.tab.c"
    break;

  case 11:
#line 132 "./parserC.y"
    {
        (yyval.node)=(yyvsp[0].node);
        (yyval.node)->nodeType = NODE_TYPE_STRING;
      }
#line 1541 "y.tab.c"
    break;

  case 12:
#line 136 "./parserC.y"
    {
        (yyval.node)=(yyvsp[0].node);
        (yyval.node)->nodeType = NODE_TYPE_CHAR;
      }
#line 1550 "y.tab.c"
    break;

  case 13:
#line 142 "./parserC.y"
    {
     
      (yyval.node)=newNode(NODE_subprogram_declarations);
      addChild((yyval.node),(yyvsp[-2].node));
      addChild((yyval.node),(yyvsp[-1].node));
      
      deleteNode((yyvsp[0].node));
    }
#line 1563 "y.tab.c"
    break;

  case 14:
#line 150 "./parserC.y"
    {
      (yyval.node)=newNode(NODE_subprogram_declarations);
    }
#line 1571 "y.tab.c"
    break;

  case 15:
#line 155 "./parserC.y"
    {
              (yyval.node)=newNode(NODE_subprogram_declaration);
              addChild((yyval.node),(yyvsp[-2].node));
              addChild((yyval.node),(yyvsp[-1].node));
              addChild((yyval.node),(yyvsp[0].node));
            }
#line 1582 "y.tab.c"
    break;

  case 16:
#line 163 "./parserC.y"
    {//funcion declaration
      (yyval.node)=newNode(NODE_subprogram_head);
      (yyvsp[-4].node)->nodeType=NODE_FUNCTION;
      addChild((yyval.node),(yyvsp[-4].node));
      addChild((yyval.node),(yyvsp[-3].node));
      addChild((yyval.node),(yyvsp[-1].node));
      deleteNode((yyvsp[-5].node));
      deleteNode((yyvsp[-2].node));
      deleteNode((yyvsp[0].node));
    }
#line 1597 "y.tab.c"
    break;

  case 17:
#line 173 "./parserC.y"
    {//procedure declaration
      (yyval.node)=newNode(NODE_subprogram_head);
      (yyvsp[-2].node)->nodeType=NODE_PROCEDURE;
      addChild((yyval.node),(yyvsp[-2].node));
      addChild((yyval.node),(yyvsp[-1].node));
      deleteNode((yyvsp[-3].node));
    }
#line 1609 "y.tab.c"
    break;

  case 18:
#line 183 "./parserC.y"
    {
      (yyval.node)=(yyvsp[-1].node);
      deleteNode((yyvsp[-2].node));
      deleteNode((yyvsp[0].node));
    }
#line 1619 "y.tab.c"
    break;

  case 19:
#line 188 "./parserC.y"
    {
      (yyval.node)=newNode(NODE_arguments);  
    }
#line 1627 "y.tab.c"
    break;

  case 20:
#line 194 "./parserC.y"
    {
      (yyval.node)=newNode(NODE_parameter_list);
      addChild((yyval.node),(yyvsp[-2].node));
      addChild((yyval.node),(yyvsp[0].node));
      deleteNode((yyvsp[-1].node));
    }
#line 1638 "y.tab.c"
    break;

  case 21:
#line 200 "./parserC.y"
    {
      (yyval.node)=newNode(NODE_parameter_list);
      addChild((yyval.node),(yyvsp[-4].node));
      addChild((yyval.node),(yyvsp[-2].node));
      addChild((yyval.node),(yyvsp[0].node));
      deleteNode((yyvsp[-3].node));
      deleteNode((yyvsp[-1].node));
    }
#line 1651 "y.tab.c"
    break;

  case 22:
#line 210 "./parserC.y"
    {
        
      }
#line 1659 "y.tab.c"
    break;

  case 23:
#line 213 "./parserC.y"
    {
         
      }
#line 1667 "y.tab.c"
    break;

  case 24:
#line 218 "./parserC.y"
    {
      (yyval.node)=newNode(NODE_compound_statement);
      addChild((yyval.node),(yyvsp[-1].node));
      (yyvsp[0].node)->nodeType=NODE_END;
      addChild((yyval.node),(yyvsp[0].node));
      deleteNode((yyvsp[-2].node));
    }
#line 1679 "y.tab.c"
    break;

  case 25:
#line 229 "./parserC.y"
    {
      (yyval.node)=(yyvsp[0].node);
    }
#line 1687 "y.tab.c"
    break;

  case 26:
#line 235 "./parserC.y"
    {
      
      (yyval.node)=newNode(NODE_statement_list);
      addChild((yyval.node),(yyvsp[0].node));
    }
#line 1697 "y.tab.c"
    break;

  case 27:
#line 240 "./parserC.y"
    {
      
      (yyval.node)=newNode(NODE_statement_list);
      addChild((yyval.node),(yyvsp[-2].node));
      addChild((yyval.node),(yyvsp[0].node));
      deleteNode((yyvsp[-1].node));
    }
#line 1709 "y.tab.c"
    break;

  case 28:
#line 248 "./parserC.y"
    {

    (yyval.node)=newNode(NODE_statement_list);
    addChild((yyval.node),(yyvsp[-2].node));
  }
#line 1719 "y.tab.c"
    break;

  case 29:
#line 256 "./parserC.y"
    {
      (yyval.node)=(yyvsp[-1].node);
      (yyval.node)->nodeType=NODE_ASSIGNMENT;
      addChild((yyval.node),(yyvsp[-2].node));
      addChild((yyval.node),(yyvsp[0].node)); 
    }
#line 1730 "y.tab.c"
    break;

  case 30:
#line 262 "./parserC.y"
    {
      (yyval.node)=(yyvsp[0].node);
    }
#line 1738 "y.tab.c"
    break;

  case 31:
#line 265 "./parserC.y"
    {
      (yyval.node)=(yyvsp[0].node);
    }
#line 1746 "y.tab.c"
    break;

  case 32:
#line 268 "./parserC.y"
    {
      (yyval.node)=newNode(NODE_if);
      addChild((yyval.node),(yyvsp[-4].node));
      addChild((yyval.node),(yyvsp[-2].node));
      addChild((yyval.node),(yyvsp[0].node));
      deleteNode((yyvsp[-5].node));
      deleteNode((yyvsp[-3].node));
      deleteNode((yyvsp[-1].node));
    }
#line 1760 "y.tab.c"
    break;

  case 33:
#line 277 "./parserC.y"
    {
      (yyval.node)=newNode(NODE_while);
      addChild((yyval.node),(yyvsp[-2].node));
      addChild((yyval.node),(yyvsp[0].node));
      deleteNode((yyvsp[-3].node));
      deleteNode((yyvsp[-1].node));
    }
#line 1772 "y.tab.c"
    break;

  case 34:
#line 284 "./parserC.y"
    {
      (yyval.node)=newNode(NODE_statement);
    }
#line 1780 "y.tab.c"
    break;

  case 35:
#line 291 "./parserC.y"
    {
      (yyval.node)=(yyvsp[-1].node);
      (yyvsp[-1].node)->nodeType=NODE_SYM_REF;
      addChild((yyval.node),(yyvsp[0].node));
    }
#line 1790 "y.tab.c"
    break;

  case 36:
#line 299 "./parserC.y"
    {
      (yyval.node)=newNode(NODE_tail);
      addChild((yyval.node),(yyvsp[-2].node));
      addChild((yyval.node),(yyvsp[0].node));
      deleteNode((yyvsp[-3].node));
      deleteNode((yyvsp[-1].node));
    }
#line 1802 "y.tab.c"
    break;

  case 37:
#line 306 "./parserC.y"
    {
      (yyval.node)=newNode(NODE_tail);  
    }
#line 1810 "y.tab.c"
    break;

  case 38:
#line 312 "./parserC.y"
    {
      (yyval.node)=newNode(NODE_procedure_statement);
      (yyvsp[0].node)->nodeType=NODE_ID;
      addChild((yyval.node),(yyvsp[0].node));
    }
#line 1820 "y.tab.c"
    break;

  case 39:
#line 317 "./parserC.y"
    {
      (yyval.node)=newNode(NODE_procedure_statement);
      (yyvsp[-3].node)->nodeType=NODE_ID;
      addChild((yyval.node),(yyvsp[-3].node));
      addChild((yyval.node),(yyvsp[-1].node));
      deleteNode((yyvsp[-2].node));
      deleteNode((yyvsp[0].node));
    }
#line 1833 "y.tab.c"
    break;

  case 40:
#line 328 "./parserC.y"
    {
      (yyval.node)=(yyvsp[0].node);
    }
#line 1841 "y.tab.c"
    break;

  case 41:
#line 331 "./parserC.y"
    {
      (yyval.node)=(yyvsp[-2].node);
      addChild((yyval.node),(yyvsp[0].node));
      deleteNode((yyvsp[-1].node));
    }
#line 1851 "y.tab.c"
    break;

  case 42:
#line 337 "./parserC.y"
    {
    (yyval.node) = (yyvsp[0].node);
}
#line 1859 "y.tab.c"
    break;

  case 43:
#line 340 "./parserC.y"
    {
  (yyval.node) = newNode(AND);
  addChild((yyval.node),(yyvsp[-2].node));
  addChild((yyval.node),(yyvsp[-1].node));
}
#line 1869 "y.tab.c"
    break;

  case 44:
#line 345 "./parserC.y"
    {
  (yyval.node) = newNode(OR);
  addChild((yyval.node),(yyvsp[-2].node));
  addChild((yyval.node),(yyvsp[-1].node));
}
#line 1879 "y.tab.c"
    break;

  case 45:
#line 352 "./parserC.y"
    {
      (yyval.node)=(yyvsp[0].node);
    }
#line 1887 "y.tab.c"
    break;

  case 46:
#line 355 "./parserC.y"
    {
      (yyval.node)=(yyvsp[-1].node);
      addChild((yyval.node),(yyvsp[-2].node));
      addChild((yyval.node),(yyvsp[0].node));
    }
#line 1897 "y.tab.c"
    break;

  case 47:
#line 363 "./parserC.y"
    {
      (yyval.node)=(yyvsp[0].node);

    }
#line 1906 "y.tab.c"
    break;

  case 48:
#line 367 "./parserC.y"
    {
      (yyval.node)=(yyvsp[-1].node);
      addChild((yyval.node),(yyvsp[-2].node));
      addChild((yyval.node),(yyvsp[0].node));
    }
#line 1916 "y.tab.c"
    break;

  case 49:
#line 372 "./parserC.y"
    {
       (yyval.node)=(yyvsp[-1].node);
      addChild((yyval.node),(yyvsp[-2].node));
      addChild((yyval.node),(yyvsp[0].node));
  }
#line 1926 "y.tab.c"
    break;

  case 50:
#line 380 "./parserC.y"
    {
      (yyval.node)=(yyvsp[0].node);
    }
#line 1934 "y.tab.c"
    break;

  case 51:
#line 383 "./parserC.y"
    {
      (yyval.node)=(yyvsp[-1].node);
      addChild((yyval.node),(yyvsp[-2].node));
      addChild((yyval.node),(yyvsp[0].node));
    }
#line 1944 "y.tab.c"
    break;

  case 52:
#line 391 "./parserC.y"
    {
      (yyval.node)=(yyvsp[-1].node);
      (yyval.node)->nodeType=NODE_ID;
      addChild((yyval.node),(yyvsp[0].node));
    }
#line 1954 "y.tab.c"
    break;

  case 53:
#line 396 "./parserC.y"
    {
      (yyval.node)=(yyvsp[-3].node);
      (yyval.node)->nodeType=NODE_ID;
      addChild((yyval.node),(yyvsp[-1].node));
      deleteNode((yyvsp[-2].node));
      deleteNode((yyvsp[0].node));
    }
#line 1966 "y.tab.c"
    break;

  case 54:
#line 403 "./parserC.y"
    {
    (yyval.node)=(yyvsp[0].node);
    }
#line 1974 "y.tab.c"
    break;

  case 55:
#line 406 "./parserC.y"
    {
      (yyval.node)=(yyvsp[0].node);
      (yyval.node)->nodeType=NODE_String;
    }
#line 1983 "y.tab.c"
    break;

  case 56:
#line 410 "./parserC.y"
    {
      (yyval.node)=(yyvsp[0].node);
      (yyval.node)->nodeType=NODE_Char;
    }
#line 1992 "y.tab.c"
    break;

  case 57:
#line 414 "./parserC.y"
    {
      (yyval.node)=(yyvsp[-1].node);
      deleteNode((yyvsp[-2].node));
      deleteNode((yyvsp[0].node));
    }
#line 2002 "y.tab.c"
    break;

  case 58:
#line 419 "./parserC.y"
    {
      (yyval.node)=newNode(NODE_factor);
      int lineno=(yyvsp[-1].node)->lineno;
      (yyvsp[-1].node)=newOpNode(OP_NOT);
      (yyvsp[-1].node)->lineno=lineno;

      addChild((yyval.node),(yyvsp[-1].node));
      addChild((yyval.node),(yyvsp[0].node));
    }
#line 2016 "y.tab.c"
    break;

  case 59:
#line 432 "./parserC.y"
    {
      (yyval.node)=(yyvsp[0].node);
        (yyval.node)->nodeType=NODE_NUM;
        (yyval.node)->string=(yyvsp[0].node)->string;
    }
#line 2026 "y.tab.c"
    break;

  case 60:
#line 438 "./parserC.y"
    {
      (yyval.node)=newOpNode(OP_PLUS);
      (yyval.node)->lineno=(yyvsp[-1].node)->lineno;
      addChild((yyval.node),(yyvsp[0].node));
      deleteNode((yyvsp[-1].node));
    }
#line 2037 "y.tab.c"
    break;

  case 61:
#line 445 "./parserC.y"
    {
      (yyval.node)=newOpNode(OP_MINUS);
      (yyval.node)->lineno=(yyvsp[-1].node)->lineno;
      addChild((yyval.node),(yyvsp[0].node));
    }
#line 2047 "y.tab.c"
    break;

  case 62:
#line 453 "./parserC.y"
    {
      (yyval.node)=newOpNode(OP_MUL);
      (yyval.node)->lineno=(yyvsp[0].node)->lineno;
      deleteNode((yyvsp[0].node));
    }
#line 2057 "y.tab.c"
    break;

  case 63:
#line 458 "./parserC.y"
    {
      (yyval.node)=newOpNode(OP_SLASH);
      (yyval.node)->lineno=(yyvsp[0].node)->lineno;
      deleteNode((yyvsp[0].node));
    }
#line 2067 "y.tab.c"
    break;

  case 64:
#line 467 "./parserC.y"
    {
      (yyval.node)=newOpNode(OP_LT);
      (yyval.node)->lineno=(yyvsp[0].node)->lineno;
      deleteNode((yyvsp[0].node));
    }
#line 2077 "y.tab.c"
    break;

  case 65:
#line 472 "./parserC.y"
    {
      (yyval.node)=newOpNode(OP_GT);
      (yyval.node)->lineno=(yyvsp[0].node)->lineno;
      deleteNode((yyvsp[0].node));
    }
#line 2087 "y.tab.c"
    break;

  case 66:
#line 477 "./parserC.y"
    {
      (yyval.node)=newOpNode(OP_EQUAL);
      (yyval.node)->lineno=(yyvsp[0].node)->lineno;
      deleteNode((yyvsp[0].node));
    }
#line 2097 "y.tab.c"
    break;

  case 67:
#line 482 "./parserC.y"
    {
      (yyval.node)=newOpNode(OP_LE);
      (yyval.node)->lineno=(yyvsp[0].node)->lineno;
      deleteNode((yyvsp[0].node));
    }
#line 2107 "y.tab.c"
    break;

  case 68:
#line 487 "./parserC.y"
    {
      (yyval.node)=newOpNode(OP_GE);
      (yyval.node)->lineno=(yyvsp[0].node)->lineno;
      deleteNode((yyvsp[0].node));
    }
#line 2117 "y.tab.c"
    break;

  case 69:
#line 492 "./parserC.y"
    {
      (yyval.node)=newOpNode(OP_notEQUAL);
      (yyval.node)->lineno=(yyvsp[0].node)->lineno;
      deleteNode((yyvsp[0].node));
    }
#line 2127 "y.tab.c"
    break;


#line 2131 "y.tab.c"

      default: break;
    }
  /* User semantic actions sometimes alter yychar, and that requires
     that yytoken be updated with the new translation.  We take the
     approach of translating immediately before every use of yytoken.
     One alternative is translating here after every semantic action,
     but that translation would be missed if the semantic action invokes
     YYABORT, YYACCEPT, or YYERROR immediately after altering yychar or
     if it invokes YYBACKUP.  In the case of YYABORT or YYACCEPT, an
     incorrect destructor might then be invoked immediately.  In the
     case of YYERROR or YYBACKUP, subsequent parser actions might lead
     to an incorrect destructor call or verbose syntax error message
     before the lookahead is translated.  */
  YY_SYMBOL_PRINT ("-> $$ =", yyr1[yyn], &yyval, &yyloc);

  YYPOPSTACK (yylen);
  yylen = 0;
  YY_STACK_PRINT (yyss, yyssp);

  *++yyvsp = yyval;

  /* Now 'shift' the result of the reduction.  Determine what state
     that goes to, based on the state we popped back to and the rule
     number reduced by.  */
  {
    const int yylhs = yyr1[yyn] - YYNTOKENS;
    const int yyi = yypgoto[yylhs] + *yyssp;
    yystate = (0 <= yyi && yyi <= YYLAST && yycheck[yyi] == *yyssp
               ? yytable[yyi]
               : yydefgoto[yylhs]);
  }

  goto yynewstate;


/*--------------------------------------.
| yyerrlab -- here on detecting error.  |
`--------------------------------------*/
yyerrlab:
  /* Make sure we have latest lookahead translation.  See comments at
     user semantic actions for why this is necessary.  */
  yytoken = yychar == YYEMPTY ? YYEMPTY : YYTRANSLATE (yychar);

  /* If not already recovering from an error, report this error.  */
  if (!yyerrstatus)
    {
      ++yynerrs;
#if ! YYERROR_VERBOSE
      yyerror (YY_("syntax error"));
#else
# define YYSYNTAX_ERROR yysyntax_error (&yymsg_alloc, &yymsg, \
                                        yyssp, yytoken)
      {
        char const *yymsgp = YY_("syntax error");
        int yysyntax_error_status;
        yysyntax_error_status = YYSYNTAX_ERROR;
        if (yysyntax_error_status == 0)
          yymsgp = yymsg;
        else if (yysyntax_error_status == 1)
          {
            if (yymsg != yymsgbuf)
              YYSTACK_FREE (yymsg);
            yymsg = (char *) YYSTACK_ALLOC (yymsg_alloc);
            if (!yymsg)
              {
                yymsg = yymsgbuf;
                yymsg_alloc = sizeof yymsgbuf;
                yysyntax_error_status = 2;
              }
            else
              {
                yysyntax_error_status = YYSYNTAX_ERROR;
                yymsgp = yymsg;
              }
          }
        yyerror (yymsgp);
        if (yysyntax_error_status == 2)
          goto yyexhaustedlab;
      }
# undef YYSYNTAX_ERROR
#endif
    }



  if (yyerrstatus == 3)
    {
      /* If just tried and failed to reuse lookahead token after an
         error, discard it.  */

      if (yychar <= YYEOF)
        {
          /* Return failure if at end of input.  */
          if (yychar == YYEOF)
            YYABORT;
        }
      else
        {
          yydestruct ("Error: discarding",
                      yytoken, &yylval);
          yychar = YYEMPTY;
        }
    }

  /* Else will try to reuse lookahead token after shifting the error
     token.  */
  goto yyerrlab1;


/*---------------------------------------------------.
| yyerrorlab -- error raised explicitly by YYERROR.  |
`---------------------------------------------------*/
yyerrorlab:
  /* Pacify compilers when the user code never invokes YYERROR and the
     label yyerrorlab therefore never appears in user code.  */
  if (0)
    YYERROR;

  /* Do not reclaim the symbols of the rule whose action triggered
     this YYERROR.  */
  YYPOPSTACK (yylen);
  yylen = 0;
  YY_STACK_PRINT (yyss, yyssp);
  yystate = *yyssp;
  goto yyerrlab1;


/*-------------------------------------------------------------.
| yyerrlab1 -- common code for both syntax error and YYERROR.  |
`-------------------------------------------------------------*/
yyerrlab1:
  yyerrstatus = 3;      /* Each real token shifted decrements this.  */

  for (;;)
    {
      yyn = yypact[yystate];
      if (!yypact_value_is_default (yyn))
        {
          yyn += YYTERROR;
          if (0 <= yyn && yyn <= YYLAST && yycheck[yyn] == YYTERROR)
            {
              yyn = yytable[yyn];
              if (0 < yyn)
                break;
            }
        }

      /* Pop the current state because it cannot handle the error token.  */
      if (yyssp == yyss)
        YYABORT;


      yydestruct ("Error: popping",
                  yystos[yystate], yyvsp);
      YYPOPSTACK (1);
      yystate = *yyssp;
      YY_STACK_PRINT (yyss, yyssp);
    }

  YY_IGNORE_MAYBE_UNINITIALIZED_BEGIN
  *++yyvsp = yylval;
  YY_IGNORE_MAYBE_UNINITIALIZED_END


  /* Shift the error token.  */
  YY_SYMBOL_PRINT ("Shifting", yystos[yyn], yyvsp, yylsp);

  yystate = yyn;
  goto yynewstate;


/*-------------------------------------.
| yyacceptlab -- YYACCEPT comes here.  |
`-------------------------------------*/
yyacceptlab:
  yyresult = 0;
  goto yyreturn;


/*-----------------------------------.
| yyabortlab -- YYABORT comes here.  |
`-----------------------------------*/
yyabortlab:
  yyresult = 1;
  goto yyreturn;


#if !defined yyoverflow || YYERROR_VERBOSE
/*-------------------------------------------------.
| yyexhaustedlab -- memory exhaustion comes here.  |
`-------------------------------------------------*/
yyexhaustedlab:
  yyerror (YY_("memory exhausted"));
  yyresult = 2;
  /* Fall through.  */
#endif


/*-----------------------------------------------------.
| yyreturn -- parsing is finished, return the result.  |
`-----------------------------------------------------*/
yyreturn:
  if (yychar != YYEMPTY)
    {
      /* Make sure we have latest lookahead translation.  See comments at
         user semantic actions for why this is necessary.  */
      yytoken = YYTRANSLATE (yychar);
      yydestruct ("Cleanup: discarding lookahead",
                  yytoken, &yylval);
    }
  /* Do not reclaim the symbols of the rule whose action triggered
     this YYABORT or YYACCEPT.  */
  YYPOPSTACK (yylen);
  YY_STACK_PRINT (yyss, yyssp);
  while (yyssp != yyss)
    {
      yydestruct ("Cleanup: popping",
                  yystos[*yyssp], yyvsp);
      YYPOPSTACK (1);
    }
#ifndef yyoverflow
  if (yyss != yyssa)
    YYSTACK_FREE (yyss);
#endif
#if YYERROR_VERBOSE
  if (yymsg != yymsgbuf)
    YYSTACK_FREE (yymsg);
#endif
  return yyresult;
}
#line 499 "./parserC.y"

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
