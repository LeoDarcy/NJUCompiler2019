/* A Bison parser, made by GNU Bison 3.0.4.  */

/* Bison implementation for Yacc-like parsers in C

   Copyright (C) 1984, 1989-1990, 2000-2015 Free Software Foundation, Inc.

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

/* Identify Bison output.  */
#define YYBISON 1

/* Bison version.  */
#define YYBISON_VERSION "3.0.4"

/* Skeleton name.  */
#define YYSKELETON_NAME "yacc.c"

/* Pure parsers.  */
#define YYPURE 0

/* Push parsers.  */
#define YYPUSH 0

/* Pull parsers.  */
#define YYPULL 1




/* Copy the first part of user declarations.  */
#line 1 "./syntax.y" /* yacc.c:339  */

	#include "lex.yy.c"
	#include "tree.h"
	
	//extern int yylineno;

#line 73 "./syntax.tab.c" /* yacc.c:339  */

# ifndef YY_NULLPTR
#  if defined __cplusplus && 201103L <= __cplusplus
#   define YY_NULLPTR nullptr
#  else
#   define YY_NULLPTR 0
#  endif
# endif

/* Enabling verbose error messages.  */
#ifdef YYERROR_VERBOSE
# undef YYERROR_VERBOSE
# define YYERROR_VERBOSE 1
#else
# define YYERROR_VERBOSE 1
#endif

/* In a future release of Bison, this section will be replaced
   by #include "syntax.tab.h".  */
#ifndef YY_YY_SYNTAX_TAB_H_INCLUDED
# define YY_YY_SYNTAX_TAB_H_INCLUDED
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
    digit = 258,
    integer = 259,
    letter = 260,
    SPACE = 261,
    TAB = 262,
    LINEBREAK = 263,
    INT = 264,
    FLOAT = 265,
    ID = 266,
    TYPE = 267,
    ASSIGNOP = 268,
    AND = 269,
    OR = 270,
    RELOP = 271,
    PLUS = 272,
    MINUS = 273,
    STAR = 274,
    DIV = 275,
    NOT = 276,
    DOT = 277,
    LP = 278,
    RP = 279,
    LB = 280,
    RB = 281,
    LC = 282,
    RC = 283,
    COMMA = 284,
    SEMI = 285,
    WHILE = 286,
    IF = 287,
    ELSE = 288,
    STRUCT = 289,
    RETURN = 290,
    LOWER_THAN_ELSE = 291
  };
#endif

/* Value type.  */
#if ! defined YYSTYPE && ! defined YYSTYPE_IS_DECLARED

union YYSTYPE
{
#line 9 "./syntax.y" /* yacc.c:355  */

	struct TreeNode* tree_node; //!

#line 154 "./syntax.tab.c" /* yacc.c:355  */
};

typedef union YYSTYPE YYSTYPE;
# define YYSTYPE_IS_TRIVIAL 1
# define YYSTYPE_IS_DECLARED 1
#endif

/* Location type.  */
#if ! defined YYLTYPE && ! defined YYLTYPE_IS_DECLARED
typedef struct YYLTYPE YYLTYPE;
struct YYLTYPE
{
  int first_line;
  int first_column;
  int last_line;
  int last_column;
};
# define YYLTYPE_IS_DECLARED 1
# define YYLTYPE_IS_TRIVIAL 1
#endif


extern YYSTYPE yylval;
extern YYLTYPE yylloc;
int yyparse (void);

#endif /* !YY_YY_SYNTAX_TAB_H_INCLUDED  */

/* Copy the second part of user declarations.  */

#line 185 "./syntax.tab.c" /* yacc.c:358  */

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
typedef unsigned short int yytype_uint16;
#endif

#ifdef YYTYPE_INT16
typedef YYTYPE_INT16 yytype_int16;
#else
typedef short int yytype_int16;
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
#  define YYSIZE_T unsigned int
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

#if !defined _Noreturn \
     && (!defined __STDC_VERSION__ || __STDC_VERSION__ < 201112)
# if defined _MSC_VER && 1200 <= _MSC_VER
#  define _Noreturn __declspec (noreturn)
# else
#  define _Noreturn YY_ATTRIBUTE ((__noreturn__))
# endif
#endif

/* Suppress unused-variable warnings by "using" E.  */
#if ! defined lint || defined __GNUC__
# define YYUSE(E) ((void) (E))
#else
# define YYUSE(E) /* empty */
#endif

#if defined __GNUC__ && 407 <= __GNUC__ * 100 + __GNUC_MINOR__
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
         || (defined YYLTYPE_IS_TRIVIAL && YYLTYPE_IS_TRIVIAL \
             && defined YYSTYPE_IS_TRIVIAL && YYSTYPE_IS_TRIVIAL)))

/* A type that is properly aligned for any stack member.  */
union yyalloc
{
  yytype_int16 yyss_alloc;
  YYSTYPE yyvs_alloc;
  YYLTYPE yyls_alloc;
};

/* The size of the maximum gap between one aligned stack and the next.  */
# define YYSTACK_GAP_MAXIMUM (sizeof (union yyalloc) - 1)

/* The size of an array large to enough to hold all stacks, each with
   N elements.  */
# define YYSTACK_BYTES(N) \
     ((N) * (sizeof (yytype_int16) + sizeof (YYSTYPE) + sizeof (YYLTYPE)) \
      + 2 * YYSTACK_GAP_MAXIMUM)

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
#define YYFINAL  13
/* YYLAST -- Last index in YYTABLE.  */
#define YYLAST   268

/* YYNTOKENS -- Number of terminals.  */
#define YYNTOKENS  37
/* YYNNTS -- Number of nonterminals.  */
#define YYNNTS  22
/* YYNRULES -- Number of rules.  */
#define YYNRULES  72
/* YYNSTATES -- Number of states.  */
#define YYNSTATES  137

/* YYTRANSLATE[YYX] -- Symbol number corresponding to YYX as returned
   by yylex, with out-of-bounds checking.  */
#define YYUNDEFTOK  2
#define YYMAXUTOK   291

#define YYTRANSLATE(YYX)                                                \
  ((unsigned int) (YYX) <= YYMAXUTOK ? yytranslate[YYX] : YYUNDEFTOK)

/* YYTRANSLATE[TOKEN-NUM] -- Symbol number corresponding to TOKEN-NUM
   as returned by yylex, without out-of-bounds checking.  */
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
      35,    36
};

#if YYDEBUG
  /* YYRLINE[YYN] -- Source line where rule number YYN was defined.  */
static const yytype_uint16 yyrline[] =
{
       0,    50,    50,    54,    57,    59,    62,    65,    68,    69,
      70,    72,    75,    81,    84,    88,    91,    96,    99,   101,
     107,   110,   113,   115,   118,   121,   123,   126,   130,   136,
     139,   140,   142,   145,   147,   150,   153,   156,   159,   162,
     165,   166,   167,   171,   174,   176,   179,   181,   184,   188,
     191,   194,   199,   202,   205,   208,   211,   214,   217,   220,
     223,   226,   229,   232,   235,   238,   241,   244,   246,   248,
     250,   253,   256
};
#endif

#if YYDEBUG || YYERROR_VERBOSE || 1
/* YYTNAME[SYMBOL-NUM] -- String name of the symbol SYMBOL-NUM.
   First, the terminals, then, starting at YYNTOKENS, nonterminals.  */
static const char *const yytname[] =
{
  "$end", "error", "$undefined", "digit", "integer", "letter", "SPACE",
  "TAB", "LINEBREAK", "INT", "FLOAT", "ID", "TYPE", "ASSIGNOP", "AND",
  "OR", "RELOP", "PLUS", "MINUS", "STAR", "DIV", "NOT", "DOT", "LP", "RP",
  "LB", "RB", "LC", "RC", "COMMA", "SEMI", "WHILE", "IF", "ELSE", "STRUCT",
  "RETURN", "LOWER_THAN_ELSE", "$accept", "Program", "ExtDefList",
  "ExtDef", "ExtDecList", "Specifier", "StructSpecifier", "OptTag", "Tag",
  "VarDec", "FunDec", "VarList", "ParamDec", "CompSt", "StmtList", "Stmt",
  "DefList", "Def", "DecList", "Dec", "Exp", "Args", YY_NULLPTR
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
     285,   286,   287,   288,   289,   290,   291
};
# endif

#define YYPACT_NINF -55

#define yypact_value_is_default(Yystate) \
  (!!((Yystate) == (-55)))

#define YYTABLE_NINF -34

#define yytable_value_is_error(Yytable_value) \
  0

  /* YYPACT[STATE-NUM] -- Index in YYTABLE of the portion describing
     STATE-NUM.  */
static const yytype_int16 yypact[] =
{
      11,   -23,   -55,    43,    16,   -55,    11,    18,   -55,   -55,
      35,    59,   -55,   -55,   -55,    72,    37,   -55,    75,    62,
       5,    10,   -55,    10,   -55,    19,   -55,   104,     7,   -55,
     -55,    13,    86,    10,    40,    98,   -55,     7,   108,   109,
     113,   124,   -55,   -55,    89,    34,   122,   133,   -55,   -55,
     125,   -55,   -55,   140,   150,   150,   150,   142,    51,   150,
     -55,    29,    85,    63,   -55,   141,   -55,    10,   -55,   150,
     -55,   150,   -55,    54,   -55,   146,   115,    82,   175,   150,
     148,   150,   111,   -55,   -55,   -55,   152,   150,   150,   150,
     150,   150,   150,   150,   150,   173,   100,   -55,   -55,   214,
     214,     0,   -55,   -55,   129,   172,   -55,   188,    85,   201,
     -55,   -55,   214,   234,   224,   243,   115,   115,    82,    82,
     -55,   159,   161,   150,   -55,    85,   165,    85,   -55,   -55,
     -55,   -55,    85,   176,   -55,    85,   -55
};

  /* YYDEFACT[STATE-NUM] -- Default reduction number in state STATE-NUM.
     Performed when YYTABLE does not specify something else to do.  Zero
     means the default is an error.  */
static const yytype_uint8 yydefact[] =
{
       0,     0,    13,    18,     0,     2,     0,     0,    14,    10,
      19,     0,    16,     1,     3,     0,    20,     6,     0,    11,
       0,    44,    22,    44,     9,     0,     5,     0,     0,     8,
       7,     0,     0,    44,     0,     0,    24,     0,     0,    27,
       0,     0,    20,    12,     0,    49,     0,    47,    15,    43,
       0,    68,    69,    67,     0,     0,     0,     0,     0,     0,
      35,     0,    33,     0,    25,    28,    23,     0,    21,     0,
      46,     0,    45,     0,    30,     0,    61,    62,     0,     0,
       0,     0,     0,    31,    29,    32,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,    34,    26,    51,
      50,     0,    48,    64,    72,     0,    60,     0,     0,     0,
      36,    40,    52,    53,    54,    55,    56,    57,    58,    59,
      66,     0,     0,     0,    63,     0,    41,     0,    70,    65,
      71,    39,     0,    37,    42,     0,    38
};

  /* YYPGOTO[NTERM-NUM].  */
static const yytype_int16 yypgoto[] =
{
     -55,   -55,   205,   -55,   194,     3,   -55,   -55,   -55,   -27,
     -55,   157,   -55,    69,   183,   -35,    33,   -55,   162,   -55,
     -54,   114
};

  /* YYDEFGOTO[NTERM-NUM].  */
static const yytype_int8 yydefgoto[] =
{
      -1,     4,     5,     6,    18,    31,     8,    11,    12,    19,
      20,    38,    39,    60,    61,    62,    32,    33,    46,    47,
      63,   105
};

  /* YYTABLE[YYPACT[STATE-NUM]] -- What to do in state STATE-NUM.  If
     positive, shift that token.  If negative, reduce the rule whose
     number is the opposite.  If YYTABLE_NINF, syntax error.  */
static const yytype_int16 yytable[] =
{
      76,    77,    78,     7,    45,    82,    29,     9,    41,     7,
      65,    -4,     1,    69,    44,    99,    13,   100,    42,    15,
      35,   104,     2,     2,    42,   107,    22,   109,    37,    16,
      83,     2,    23,   112,   113,   114,   115,   116,   117,   118,
     119,    50,   122,    36,     3,     3,    45,    71,    17,    51,
      52,    53,    80,     3,    10,   101,    34,    84,    54,    27,
      25,    55,   -17,    56,    86,    42,    49,    23,   -33,   104,
      37,    57,    58,   126,    81,    59,    87,    88,    89,    90,
      91,    92,    93,    94,    24,    95,    21,    27,    96,    30,
     131,    28,   133,    97,    51,    52,    53,   134,    22,    23,
     136,   121,    69,    54,    95,    26,    55,    96,    56,    51,
      52,    53,    23,    40,    48,    22,    57,    58,    54,    70,
      59,    55,    64,    56,    87,    88,    89,    90,    91,    92,
      93,    94,    66,    95,    93,    94,    96,    95,    67,    68,
      96,   110,    87,    88,    89,    90,    91,    92,    93,    94,
      22,    95,    72,    74,    96,    51,    52,    53,   123,    51,
      52,    53,    73,    75,    54,    79,    27,    55,    54,    56,
     103,    55,   108,    56,    87,    88,    89,    90,    91,    92,
      93,    94,   111,    95,   120,   128,    96,   129,    87,    88,
      89,    90,    91,    92,    93,    94,   124,    95,   132,   106,
      96,    87,    88,    89,    90,    91,    92,    93,    94,   135,
      95,    14,   125,    96,    87,    88,    89,    90,    91,    92,
      93,    94,    43,    95,    98,   127,    96,    87,    88,    89,
      90,    91,    92,    93,    94,   102,    95,   130,    88,    96,
      90,    91,    92,    93,    94,    85,    95,     0,     0,    96,
      90,    91,    92,    93,    94,     0,    95,     0,     0,    96,
      91,    92,    93,    94,     0,    95,     0,     0,    96
};

static const yytype_int16 yycheck[] =
{
      54,    55,    56,     0,    31,    59,     1,    30,     1,     6,
      37,     0,     1,    13,     1,    69,     0,    71,    11,     1,
       1,    75,    12,    12,    11,    79,    26,    81,    25,    11,
       1,    12,    27,    87,    88,    89,    90,    91,    92,    93,
      94,     1,    96,    24,    34,    34,    73,    13,    30,     9,
      10,    11,     1,    34,    11,     1,    23,    28,    18,    25,
      23,    21,    27,    23,     1,    11,    33,    27,    28,   123,
      67,    31,    32,   108,    23,    35,    13,    14,    15,    16,
      17,    18,    19,    20,    15,    22,    27,    25,    25,    20,
     125,    29,   127,    30,     9,    10,    11,   132,    26,    27,
     135,     1,    13,    18,    22,    30,    21,    25,    23,     9,
      10,    11,    27,     9,    28,    26,    31,    32,    18,    30,
      35,    21,    24,    23,    13,    14,    15,    16,    17,    18,
      19,    20,    24,    22,    19,    20,    25,    22,    29,    26,
      25,    30,    13,    14,    15,    16,    17,    18,    19,    20,
      26,    22,    30,    28,    25,     9,    10,    11,    29,     9,
      10,    11,    29,    23,    18,    23,    25,    21,    18,    23,
      24,    21,    24,    23,    13,    14,    15,    16,    17,    18,
      19,    20,    30,    22,    11,    26,    25,    26,    13,    14,
      15,    16,    17,    18,    19,    20,    24,    22,    33,    24,
      25,    13,    14,    15,    16,    17,    18,    19,    20,    33,
      22,     6,    24,    25,    13,    14,    15,    16,    17,    18,
      19,    20,    28,    22,    67,    24,    25,    13,    14,    15,
      16,    17,    18,    19,    20,    73,    22,   123,    14,    25,
      16,    17,    18,    19,    20,    62,    22,    -1,    -1,    25,
      16,    17,    18,    19,    20,    -1,    22,    -1,    -1,    25,
      17,    18,    19,    20,    -1,    22,    -1,    -1,    25
};

  /* YYSTOS[STATE-NUM] -- The (internal number of the) accessing
     symbol of state STATE-NUM.  */
static const yytype_uint8 yystos[] =
{
       0,     1,    12,    34,    38,    39,    40,    42,    43,    30,
      11,    44,    45,     0,    39,     1,    11,    30,    41,    46,
      47,    27,    26,    27,    50,    23,    30,    25,    29,     1,
      50,    42,    53,    54,    53,     1,    24,    42,    48,    49,
       9,     1,    11,    41,     1,    46,    55,    56,    28,    53,
       1,     9,    10,    11,    18,    21,    23,    31,    32,    35,
      50,    51,    52,    57,    24,    46,    24,    29,    26,    13,
      30,    13,    30,    29,    28,    23,    57,    57,    57,    23,
       1,    23,    57,     1,    28,    51,     1,    13,    14,    15,
      16,    17,    18,    19,    20,    22,    25,    30,    48,    57,
      57,     1,    55,    24,    57,    58,    24,    57,    24,    57,
      30,    30,    57,    57,    57,    57,    57,    57,    57,    57,
      11,     1,    57,    29,    24,    24,    52,    24,    26,    26,
      58,    52,    33,    52,    52,    33,    52
};

  /* YYR1[YYN] -- Symbol number of symbol that rule YYN derives.  */
static const yytype_uint8 yyr1[] =
{
       0,    37,    38,    39,    39,    40,    40,    40,    40,    40,
      40,    41,    41,    42,    42,    43,    43,    44,    44,    45,
      46,    46,    46,    47,    47,    47,    48,    48,    49,    50,
      50,    50,    51,    51,    52,    52,    52,    52,    52,    52,
      52,    52,    52,    53,    53,    54,    54,    55,    55,    56,
      56,    56,    57,    57,    57,    57,    57,    57,    57,    57,
      57,    57,    57,    57,    57,    57,    57,    57,    57,    57,
      57,    58,    58
};

  /* YYR2[YYN] -- Number of symbols on the right hand side of rule YYN.  */
static const yytype_uint8 yyr2[] =
{
       0,     2,     1,     2,     0,     3,     2,     3,     3,     3,
       2,     1,     3,     1,     1,     5,     2,     1,     0,     1,
       1,     4,     2,     4,     3,     4,     3,     1,     2,     4,
       4,     4,     2,     0,     2,     1,     3,     5,     7,     5,
       3,     4,     6,     2,     0,     3,     3,     1,     3,     1,
       3,     3,     3,     3,     3,     3,     3,     3,     3,     3,
       3,     2,     2,     4,     3,     4,     3,     1,     1,     1,
       4,     3,     1
};


#define yyerrok         (yyerrstatus = 0)
#define yyclearin       (yychar = YYEMPTY)
#define YYEMPTY         (-2)
#define YYEOF           0

#define YYACCEPT        goto yyacceptlab
#define YYABORT         goto yyabortlab
#define YYERROR         goto yyerrorlab


#define YYRECOVERING()  (!!yyerrstatus)

#define YYBACKUP(Token, Value)                                  \
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


/* YYLLOC_DEFAULT -- Set CURRENT to span from RHS[1] to RHS[N].
   If N is 0, then set CURRENT to the empty location which ends
   the previous symbol: RHS[0] (always defined).  */

#ifndef YYLLOC_DEFAULT
# define YYLLOC_DEFAULT(Current, Rhs, N)                                \
    do                                                                  \
      if (N)                                                            \
        {                                                               \
          (Current).first_line   = YYRHSLOC (Rhs, 1).first_line;        \
          (Current).first_column = YYRHSLOC (Rhs, 1).first_column;      \
          (Current).last_line    = YYRHSLOC (Rhs, N).last_line;         \
          (Current).last_column  = YYRHSLOC (Rhs, N).last_column;       \
        }                                                               \
      else                                                              \
        {                                                               \
          (Current).first_line   = (Current).last_line   =              \
            YYRHSLOC (Rhs, 0).last_line;                                \
          (Current).first_column = (Current).last_column =              \
            YYRHSLOC (Rhs, 0).last_column;                              \
        }                                                               \
    while (0)
#endif

#define YYRHSLOC(Rhs, K) ((Rhs)[K])


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


/* YY_LOCATION_PRINT -- Print the location on the stream.
   This macro was not mandated originally: define only if we know
   we won't break user code: when these are the locations we know.  */

#ifndef YY_LOCATION_PRINT
# if defined YYLTYPE_IS_TRIVIAL && YYLTYPE_IS_TRIVIAL

/* Print *YYLOCP on YYO.  Private, do not rely on its existence. */

YY_ATTRIBUTE_UNUSED
static unsigned
yy_location_print_ (FILE *yyo, YYLTYPE const * const yylocp)
{
  unsigned res = 0;
  int end_col = 0 != yylocp->last_column ? yylocp->last_column - 1 : 0;
  if (0 <= yylocp->first_line)
    {
      res += YYFPRINTF (yyo, "%d", yylocp->first_line);
      if (0 <= yylocp->first_column)
        res += YYFPRINTF (yyo, ".%d", yylocp->first_column);
    }
  if (0 <= yylocp->last_line)
    {
      if (yylocp->first_line < yylocp->last_line)
        {
          res += YYFPRINTF (yyo, "-%d", yylocp->last_line);
          if (0 <= end_col)
            res += YYFPRINTF (yyo, ".%d", end_col);
        }
      else if (0 <= end_col && yylocp->first_column < end_col)
        res += YYFPRINTF (yyo, "-%d", end_col);
    }
  return res;
 }

#  define YY_LOCATION_PRINT(File, Loc)          \
  yy_location_print_ (File, &(Loc))

# else
#  define YY_LOCATION_PRINT(File, Loc) ((void) 0)
# endif
#endif


# define YY_SYMBOL_PRINT(Title, Type, Value, Location)                    \
do {                                                                      \
  if (yydebug)                                                            \
    {                                                                     \
      YYFPRINTF (stderr, "%s ", Title);                                   \
      yy_symbol_print (stderr,                                            \
                  Type, Value, Location); \
      YYFPRINTF (stderr, "\n");                                           \
    }                                                                     \
} while (0)


/*----------------------------------------.
| Print this symbol's value on YYOUTPUT.  |
`----------------------------------------*/

static void
yy_symbol_value_print (FILE *yyoutput, int yytype, YYSTYPE const * const yyvaluep, YYLTYPE const * const yylocationp)
{
  FILE *yyo = yyoutput;
  YYUSE (yyo);
  YYUSE (yylocationp);
  if (!yyvaluep)
    return;
# ifdef YYPRINT
  if (yytype < YYNTOKENS)
    YYPRINT (yyoutput, yytoknum[yytype], *yyvaluep);
# endif
  YYUSE (yytype);
}


/*--------------------------------.
| Print this symbol on YYOUTPUT.  |
`--------------------------------*/

static void
yy_symbol_print (FILE *yyoutput, int yytype, YYSTYPE const * const yyvaluep, YYLTYPE const * const yylocationp)
{
  YYFPRINTF (yyoutput, "%s %s (",
             yytype < YYNTOKENS ? "token" : "nterm", yytname[yytype]);

  YY_LOCATION_PRINT (yyoutput, *yylocationp);
  YYFPRINTF (yyoutput, ": ");
  yy_symbol_value_print (yyoutput, yytype, yyvaluep, yylocationp);
  YYFPRINTF (yyoutput, ")");
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
yy_reduce_print (yytype_int16 *yyssp, YYSTYPE *yyvsp, YYLTYPE *yylsp, int yyrule)
{
  unsigned long int yylno = yyrline[yyrule];
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
                       &(yyvsp[(yyi + 1) - (yynrhs)])
                       , &(yylsp[(yyi + 1) - (yynrhs)])                       );
      YYFPRINTF (stderr, "\n");
    }
}

# define YY_REDUCE_PRINT(Rule)          \
do {                                    \
  if (yydebug)                          \
    yy_reduce_print (yyssp, yyvsp, yylsp, Rule); \
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
            /* Fall through.  */
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

  return yystpcpy (yyres, yystr) - yyres;
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
                  if (! (yysize <= yysize1
                         && yysize1 <= YYSTACK_ALLOC_MAXIMUM))
                    return 2;
                  yysize = yysize1;
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
    if (! (yysize <= yysize1 && yysize1 <= YYSTACK_ALLOC_MAXIMUM))
      return 2;
    yysize = yysize1;
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
yydestruct (const char *yymsg, int yytype, YYSTYPE *yyvaluep, YYLTYPE *yylocationp)
{
  YYUSE (yyvaluep);
  YYUSE (yylocationp);
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
/* Location data for the lookahead symbol.  */
YYLTYPE yylloc
# if defined YYLTYPE_IS_TRIVIAL && YYLTYPE_IS_TRIVIAL
  = { 1, 1, 1, 1 }
# endif
;
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
       'yyls': related to locations.

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

    /* The location stack.  */
    YYLTYPE yylsa[YYINITDEPTH];
    YYLTYPE *yyls;
    YYLTYPE *yylsp;

    /* The locations where the error started and ended.  */
    YYLTYPE yyerror_range[3];

    YYSIZE_T yystacksize;

  int yyn;
  int yyresult;
  /* Lookahead token as an internal (translated) token number.  */
  int yytoken = 0;
  /* The variables used to return semantic value and location from the
     action routines.  */
  YYSTYPE yyval;
  YYLTYPE yyloc;

#if YYERROR_VERBOSE
  /* Buffer for error messages, and its allocated size.  */
  char yymsgbuf[128];
  char *yymsg = yymsgbuf;
  YYSIZE_T yymsg_alloc = sizeof yymsgbuf;
#endif

#define YYPOPSTACK(N)   (yyvsp -= (N), yyssp -= (N), yylsp -= (N))

  /* The number of symbols on the RHS of the reduced rule.
     Keep to zero when no symbol should be popped.  */
  int yylen = 0;

  yyssp = yyss = yyssa;
  yyvsp = yyvs = yyvsa;
  yylsp = yyls = yylsa;
  yystacksize = YYINITDEPTH;

  YYDPRINTF ((stderr, "Starting parse\n"));

  yystate = 0;
  yyerrstatus = 0;
  yynerrs = 0;
  yychar = YYEMPTY; /* Cause a token to be read.  */
  yylsp[0] = yylloc;
  goto yysetstate;

/*------------------------------------------------------------.
| yynewstate -- Push a new state, which is found in yystate.  |
`------------------------------------------------------------*/
 yynewstate:
  /* In all cases, when you get here, the value and location stacks
     have just been pushed.  So pushing a state here evens the stacks.  */
  yyssp++;

 yysetstate:
  *yyssp = yystate;

  if (yyss + yystacksize - 1 <= yyssp)
    {
      /* Get the current used size of the three stacks, in elements.  */
      YYSIZE_T yysize = yyssp - yyss + 1;

#ifdef yyoverflow
      {
        /* Give user a chance to reallocate the stack.  Use copies of
           these so that the &'s don't force the real ones into
           memory.  */
        YYSTYPE *yyvs1 = yyvs;
        yytype_int16 *yyss1 = yyss;
        YYLTYPE *yyls1 = yyls;

        /* Each stack pointer address is followed by the size of the
           data in use in that stack, in bytes.  This used to be a
           conditional around just the two extra args, but that might
           be undefined if yyoverflow is a macro.  */
        yyoverflow (YY_("memory exhausted"),
                    &yyss1, yysize * sizeof (*yyssp),
                    &yyvs1, yysize * sizeof (*yyvsp),
                    &yyls1, yysize * sizeof (*yylsp),
                    &yystacksize);

        yyls = yyls1;
        yyss = yyss1;
        yyvs = yyvs1;
      }
#else /* no yyoverflow */
# ifndef YYSTACK_RELOCATE
      goto yyexhaustedlab;
# else
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
        YYSTACK_RELOCATE (yyls_alloc, yyls);
#  undef YYSTACK_RELOCATE
        if (yyss1 != yyssa)
          YYSTACK_FREE (yyss1);
      }
# endif
#endif /* no yyoverflow */

      yyssp = yyss + yysize - 1;
      yyvsp = yyvs + yysize - 1;
      yylsp = yyls + yysize - 1;

      YYDPRINTF ((stderr, "Stack size increased to %lu\n",
                  (unsigned long int) yystacksize));

      if (yyss + yystacksize - 1 <= yyssp)
        YYABORT;
    }

  YYDPRINTF ((stderr, "Entering state %d\n", yystate));

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
  *++yylsp = yylloc;
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
| yyreduce -- Do a reduction.  |
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

  /* Default location.  */
  YYLLOC_DEFAULT (yyloc, (yylsp - yylen), yylen);
  YY_REDUCE_PRINT (yyn);
  switch (yyn)
    {
        case 2:
#line 51 "./syntax.y" /* yacc.c:1646  */
    { (yyval.tree_node)=newNode((yyloc).first_line,TYPE_Program,"Program","");
		 	root=(yyval.tree_node);root->depth=0;insertTree(root,(yyvsp[0].tree_node)); }
#line 1475 "./syntax.tab.c" /* yacc.c:1646  */
    break;

  case 3:
#line 55 "./syntax.y" /* yacc.c:1646  */
    { (yyval.tree_node)=newNode((yyloc).first_line,TYPE_ExtDefList,"ExtDefList","");
				insertTree((yyval.tree_node),(yyvsp[-1].tree_node));insertTree((yyval.tree_node),(yyvsp[0].tree_node)); }
#line 1482 "./syntax.tab.c" /* yacc.c:1646  */
    break;

  case 4:
#line 57 "./syntax.y" /* yacc.c:1646  */
    { (yyval.tree_node)=NULL; }
#line 1488 "./syntax.tab.c" /* yacc.c:1646  */
    break;

  case 5:
#line 60 "./syntax.y" /* yacc.c:1646  */
    { (yyval.tree_node)=newNode((yyloc).first_line,TYPE_ExtDef,"ExtDef","");
				insertTree((yyval.tree_node),(yyvsp[-2].tree_node));insertTree((yyval.tree_node),(yyvsp[-1].tree_node));insertTree((yyval.tree_node),(yyvsp[0].tree_node)); }
#line 1495 "./syntax.tab.c" /* yacc.c:1646  */
    break;

  case 6:
#line 63 "./syntax.y" /* yacc.c:1646  */
    { (yyval.tree_node)=newNode((yyloc).first_line,TYPE_ExtDef,"ExtDef","");
			insertTree((yyval.tree_node),(yyvsp[-1].tree_node));insertTree((yyval.tree_node),(yyvsp[0].tree_node)); }
#line 1502 "./syntax.tab.c" /* yacc.c:1646  */
    break;

  case 7:
#line 66 "./syntax.y" /* yacc.c:1646  */
    { (yyval.tree_node)=newNode((yyloc).first_line,TYPE_ExtDef,"ExtDef","");
			insertTree((yyval.tree_node),(yyvsp[-2].tree_node));insertTree((yyval.tree_node),(yyvsp[-1].tree_node));insertTree((yyval.tree_node),(yyvsp[0].tree_node)); }
#line 1509 "./syntax.tab.c" /* yacc.c:1646  */
    break;

  case 8:
#line 68 "./syntax.y" /* yacc.c:1646  */
    { ErrorSyn=true; }
#line 1515 "./syntax.tab.c" /* yacc.c:1646  */
    break;

  case 9:
#line 69 "./syntax.y" /* yacc.c:1646  */
    { ErrorSyn=true; }
#line 1521 "./syntax.tab.c" /* yacc.c:1646  */
    break;

  case 10:
#line 70 "./syntax.y" /* yacc.c:1646  */
    { ErrorSyn=true; }
#line 1527 "./syntax.tab.c" /* yacc.c:1646  */
    break;

  case 11:
#line 73 "./syntax.y" /* yacc.c:1646  */
    { (yyval.tree_node)=newNode((yyloc).first_line,TYPE_ExtDecList,"ExtDecList","");
				insertTree((yyval.tree_node),(yyvsp[0].tree_node)); }
#line 1534 "./syntax.tab.c" /* yacc.c:1646  */
    break;

  case 12:
#line 76 "./syntax.y" /* yacc.c:1646  */
    { (yyval.tree_node)=newNode((yyloc).first_line,TYPE_ExtDecList,"ExtDecList","");
			insertTree((yyval.tree_node),(yyvsp[-2].tree_node));insertTree((yyval.tree_node),(yyvsp[-1].tree_node));insertTree((yyval.tree_node),(yyvsp[0].tree_node)); }
#line 1541 "./syntax.tab.c" /* yacc.c:1646  */
    break;

  case 13:
#line 82 "./syntax.y" /* yacc.c:1646  */
    { (yyval.tree_node)=newNode((yyloc).first_line,TYPE_Specifier,"Specifier","");
				insertTree((yyval.tree_node),(yyvsp[0].tree_node)); }
#line 1548 "./syntax.tab.c" /* yacc.c:1646  */
    break;

  case 14:
#line 85 "./syntax.y" /* yacc.c:1646  */
    { (yyval.tree_node)=newNode((yyloc).first_line,TYPE_Specifier,"Specifier","");
			insertTree((yyval.tree_node),(yyvsp[0].tree_node)); }
#line 1555 "./syntax.tab.c" /* yacc.c:1646  */
    break;

  case 15:
#line 89 "./syntax.y" /* yacc.c:1646  */
    { (yyval.tree_node)=newNode((yyloc).first_line,TYPE_StructSpecifier,"StructSpecifier","");
				insertTree((yyval.tree_node),(yyvsp[-4].tree_node));insertTree((yyval.tree_node),(yyvsp[-3].tree_node));insertTree((yyval.tree_node),(yyvsp[-2].tree_node));insertTree((yyval.tree_node),(yyvsp[-1].tree_node));insertTree((yyval.tree_node),(yyvsp[0].tree_node)); }
#line 1562 "./syntax.tab.c" /* yacc.c:1646  */
    break;

  case 16:
#line 92 "./syntax.y" /* yacc.c:1646  */
    { (yyval.tree_node)=newNode((yyloc).first_line,TYPE_StructSpecifier,"StructSpecifier","");
			insertTree((yyval.tree_node),(yyvsp[-1].tree_node));insertTree((yyval.tree_node),(yyvsp[0].tree_node)); }
#line 1569 "./syntax.tab.c" /* yacc.c:1646  */
    break;

  case 17:
#line 97 "./syntax.y" /* yacc.c:1646  */
    { (yyval.tree_node)=newNode((yyloc).first_line,TYPE_OptTag,"OptTag","");
			insertTree((yyval.tree_node),(yyvsp[0].tree_node)); }
#line 1576 "./syntax.tab.c" /* yacc.c:1646  */
    break;

  case 18:
#line 99 "./syntax.y" /* yacc.c:1646  */
    { (yyval.tree_node)=NULL; }
#line 1582 "./syntax.tab.c" /* yacc.c:1646  */
    break;

  case 19:
#line 102 "./syntax.y" /* yacc.c:1646  */
    { (yyval.tree_node)=newNode((yyloc).first_line,TYPE_Tag,"Tag","");
			insertTree((yyval.tree_node),(yyvsp[0].tree_node)); }
#line 1589 "./syntax.tab.c" /* yacc.c:1646  */
    break;

  case 20:
#line 108 "./syntax.y" /* yacc.c:1646  */
    { (yyval.tree_node)=newNode((yyloc).first_line,TYPE_VarDec,"VarDec","");
			insertTree((yyval.tree_node),(yyvsp[0].tree_node)); }
#line 1596 "./syntax.tab.c" /* yacc.c:1646  */
    break;

  case 21:
#line 111 "./syntax.y" /* yacc.c:1646  */
    { (yyval.tree_node)=newNode((yyloc).first_line,TYPE_VarDec,"VarDec","");
			insertTree((yyval.tree_node),(yyvsp[-3].tree_node));insertTree((yyval.tree_node),(yyvsp[-2].tree_node));insertTree((yyval.tree_node),(yyvsp[-1].tree_node));insertTree((yyval.tree_node),(yyvsp[0].tree_node)); }
#line 1603 "./syntax.tab.c" /* yacc.c:1646  */
    break;

  case 22:
#line 113 "./syntax.y" /* yacc.c:1646  */
    { ErrorSyn=true; }
#line 1609 "./syntax.tab.c" /* yacc.c:1646  */
    break;

  case 23:
#line 116 "./syntax.y" /* yacc.c:1646  */
    { (yyval.tree_node)=newNode((yyloc).first_line,TYPE_FuncDec,"FunDec","");
			insertTree((yyval.tree_node),(yyvsp[-3].tree_node));insertTree((yyval.tree_node),(yyvsp[-2].tree_node));insertTree((yyval.tree_node),(yyvsp[-1].tree_node));insertTree((yyval.tree_node),(yyvsp[0].tree_node)); }
#line 1616 "./syntax.tab.c" /* yacc.c:1646  */
    break;

  case 24:
#line 119 "./syntax.y" /* yacc.c:1646  */
    { (yyval.tree_node)=newNode((yyloc).first_line,TYPE_FuncDec,"FunDec","");
			insertTree((yyval.tree_node),(yyvsp[-2].tree_node));insertTree((yyval.tree_node),(yyvsp[-1].tree_node));insertTree((yyval.tree_node),(yyvsp[0].tree_node)); }
#line 1623 "./syntax.tab.c" /* yacc.c:1646  */
    break;

  case 25:
#line 121 "./syntax.y" /* yacc.c:1646  */
    { ErrorSyn=true; }
#line 1629 "./syntax.tab.c" /* yacc.c:1646  */
    break;

  case 26:
#line 124 "./syntax.y" /* yacc.c:1646  */
    { (yyval.tree_node)=newNode((yyloc).first_line,TYPE_VarList,"VarList","");
			insertTree((yyval.tree_node),(yyvsp[-2].tree_node));insertTree((yyval.tree_node),(yyvsp[-1].tree_node));insertTree((yyval.tree_node),(yyvsp[0].tree_node)); }
#line 1636 "./syntax.tab.c" /* yacc.c:1646  */
    break;

  case 27:
#line 127 "./syntax.y" /* yacc.c:1646  */
    { (yyval.tree_node)=newNode((yyloc).first_line,TYPE_VarList,"VarList","");
			insertTree((yyval.tree_node),(yyvsp[0].tree_node)); }
#line 1643 "./syntax.tab.c" /* yacc.c:1646  */
    break;

  case 28:
#line 131 "./syntax.y" /* yacc.c:1646  */
    { (yyval.tree_node)=newNode((yyloc).first_line,TYPE_ParamDec,"ParamDec","");
				insertTree((yyval.tree_node),(yyvsp[-1].tree_node));insertTree((yyval.tree_node),(yyvsp[0].tree_node)); }
#line 1650 "./syntax.tab.c" /* yacc.c:1646  */
    break;

  case 29:
#line 137 "./syntax.y" /* yacc.c:1646  */
    { (yyval.tree_node)=newNode((yyloc).first_line,TYPE_CompSt,"CompSt","");
			insertTree((yyval.tree_node),(yyvsp[-3].tree_node));insertTree((yyval.tree_node),(yyvsp[-2].tree_node));insertTree((yyval.tree_node),(yyvsp[-1].tree_node));insertTree((yyval.tree_node),(yyvsp[0].tree_node)); }
#line 1657 "./syntax.tab.c" /* yacc.c:1646  */
    break;

  case 30:
#line 139 "./syntax.y" /* yacc.c:1646  */
    { ErrorSyn=true; }
#line 1663 "./syntax.tab.c" /* yacc.c:1646  */
    break;

  case 31:
#line 140 "./syntax.y" /* yacc.c:1646  */
    { ErrorSyn=true; }
#line 1669 "./syntax.tab.c" /* yacc.c:1646  */
    break;

  case 32:
#line 143 "./syntax.y" /* yacc.c:1646  */
    { (yyval.tree_node)=newNode((yyloc).first_line,TYPE_StmtList,"StmtList","");
				insertTree((yyval.tree_node),(yyvsp[-1].tree_node));insertTree((yyval.tree_node),(yyvsp[0].tree_node)); }
#line 1676 "./syntax.tab.c" /* yacc.c:1646  */
    break;

  case 33:
#line 145 "./syntax.y" /* yacc.c:1646  */
    { (yyval.tree_node)=NULL; }
#line 1682 "./syntax.tab.c" /* yacc.c:1646  */
    break;

  case 34:
#line 148 "./syntax.y" /* yacc.c:1646  */
    { (yyval.tree_node)=newNode((yyloc).first_line,TYPE_Stmt,"Stmt","");
			insertTree((yyval.tree_node),(yyvsp[-1].tree_node));insertTree((yyval.tree_node),(yyvsp[0].tree_node)); }
#line 1689 "./syntax.tab.c" /* yacc.c:1646  */
    break;

  case 35:
#line 151 "./syntax.y" /* yacc.c:1646  */
    { (yyval.tree_node)=newNode((yyloc).first_line,TYPE_Stmt,"Stmt","");
			insertTree((yyval.tree_node),(yyvsp[0].tree_node)); }
#line 1696 "./syntax.tab.c" /* yacc.c:1646  */
    break;

  case 36:
#line 154 "./syntax.y" /* yacc.c:1646  */
    { (yyval.tree_node)=newNode((yyloc).first_line,TYPE_Stmt,"Stmt","");
			insertTree((yyval.tree_node),(yyvsp[-2].tree_node));insertTree((yyval.tree_node),(yyvsp[-1].tree_node));insertTree((yyval.tree_node),(yyvsp[0].tree_node)); }
#line 1703 "./syntax.tab.c" /* yacc.c:1646  */
    break;

  case 37:
#line 157 "./syntax.y" /* yacc.c:1646  */
    { (yyval.tree_node)=newNode((yyloc).first_line,TYPE_Stmt,"Stmt","");
			insertTree((yyval.tree_node),(yyvsp[-4].tree_node));insertTree((yyval.tree_node),(yyvsp[-3].tree_node));insertTree((yyval.tree_node),(yyvsp[-2].tree_node));insertTree((yyval.tree_node),(yyvsp[-1].tree_node));insertTree((yyval.tree_node),(yyvsp[0].tree_node)); }
#line 1710 "./syntax.tab.c" /* yacc.c:1646  */
    break;

  case 38:
#line 160 "./syntax.y" /* yacc.c:1646  */
    { (yyval.tree_node)=newNode((yyloc).first_line,TYPE_Stmt,"Stmt","");
			insertTree((yyval.tree_node),(yyvsp[-6].tree_node));insertTree((yyval.tree_node),(yyvsp[-5].tree_node));insertTree((yyval.tree_node),(yyvsp[-4].tree_node));insertTree((yyval.tree_node),(yyvsp[-3].tree_node));insertTree((yyval.tree_node),(yyvsp[-2].tree_node));insertTree((yyval.tree_node),(yyvsp[-1].tree_node));insertTree((yyval.tree_node),(yyvsp[0].tree_node)); }
#line 1717 "./syntax.tab.c" /* yacc.c:1646  */
    break;

  case 39:
#line 163 "./syntax.y" /* yacc.c:1646  */
    { (yyval.tree_node)=newNode((yyloc).first_line,TYPE_Stmt,"Stmt","");
			insertTree((yyval.tree_node),(yyvsp[-4].tree_node));insertTree((yyval.tree_node),(yyvsp[-3].tree_node));insertTree((yyval.tree_node),(yyvsp[-2].tree_node));insertTree((yyval.tree_node),(yyvsp[-1].tree_node));insertTree((yyval.tree_node),(yyvsp[0].tree_node)); }
#line 1724 "./syntax.tab.c" /* yacc.c:1646  */
    break;

  case 40:
#line 165 "./syntax.y" /* yacc.c:1646  */
    { ErrorSyn=true; }
#line 1730 "./syntax.tab.c" /* yacc.c:1646  */
    break;

  case 41:
#line 166 "./syntax.y" /* yacc.c:1646  */
    { ErrorSyn=true; }
#line 1736 "./syntax.tab.c" /* yacc.c:1646  */
    break;

  case 42:
#line 167 "./syntax.y" /* yacc.c:1646  */
    { ErrorSyn=true; }
#line 1742 "./syntax.tab.c" /* yacc.c:1646  */
    break;

  case 43:
#line 172 "./syntax.y" /* yacc.c:1646  */
    { (yyval.tree_node)=newNode((yyloc).first_line,TYPE_DefList,"DefList","");
			insertTree((yyval.tree_node),(yyvsp[-1].tree_node));insertTree((yyval.tree_node),(yyvsp[0].tree_node)); }
#line 1749 "./syntax.tab.c" /* yacc.c:1646  */
    break;

  case 44:
#line 174 "./syntax.y" /* yacc.c:1646  */
    { (yyval.tree_node)=NULL; }
#line 1755 "./syntax.tab.c" /* yacc.c:1646  */
    break;

  case 45:
#line 177 "./syntax.y" /* yacc.c:1646  */
    { (yyval.tree_node)=newNode((yyloc).first_line,TYPE_Def,"Def","");
			insertTree((yyval.tree_node),(yyvsp[-2].tree_node));insertTree((yyval.tree_node),(yyvsp[-1].tree_node));insertTree((yyval.tree_node),(yyvsp[0].tree_node)); }
#line 1762 "./syntax.tab.c" /* yacc.c:1646  */
    break;

  case 46:
#line 179 "./syntax.y" /* yacc.c:1646  */
    { ErrorSyn=true; }
#line 1768 "./syntax.tab.c" /* yacc.c:1646  */
    break;

  case 47:
#line 182 "./syntax.y" /* yacc.c:1646  */
    { (yyval.tree_node)=newNode((yyloc).first_line,TYPE_DecList,"DecList","");
			insertTree((yyval.tree_node),(yyvsp[0].tree_node)); }
#line 1775 "./syntax.tab.c" /* yacc.c:1646  */
    break;

  case 48:
#line 185 "./syntax.y" /* yacc.c:1646  */
    { (yyval.tree_node)=newNode((yyloc).first_line,TYPE_DecList,"DecList","");
			insertTree((yyval.tree_node),(yyvsp[-2].tree_node));insertTree((yyval.tree_node),(yyvsp[-1].tree_node));insertTree((yyval.tree_node),(yyvsp[0].tree_node)); }
#line 1782 "./syntax.tab.c" /* yacc.c:1646  */
    break;

  case 49:
#line 189 "./syntax.y" /* yacc.c:1646  */
    { (yyval.tree_node)=newNode((yyloc).first_line,TYPE_Dec,"Dec","");
			insertTree((yyval.tree_node),(yyvsp[0].tree_node)); }
#line 1789 "./syntax.tab.c" /* yacc.c:1646  */
    break;

  case 50:
#line 192 "./syntax.y" /* yacc.c:1646  */
    { (yyval.tree_node)=newNode((yyloc).first_line,TYPE_Dec,"Dec","");
			insertTree((yyval.tree_node),(yyvsp[-2].tree_node));insertTree((yyval.tree_node),(yyvsp[-1].tree_node));insertTree((yyval.tree_node),(yyvsp[0].tree_node)); }
#line 1796 "./syntax.tab.c" /* yacc.c:1646  */
    break;

  case 51:
#line 194 "./syntax.y" /* yacc.c:1646  */
    { ErrorSyn=true; }
#line 1802 "./syntax.tab.c" /* yacc.c:1646  */
    break;

  case 52:
#line 200 "./syntax.y" /* yacc.c:1646  */
    { (yyval.tree_node)=newNode((yyloc).first_line,TYPE_Exp,"Exp","");
			insertTree((yyval.tree_node),(yyvsp[-2].tree_node));insertTree((yyval.tree_node),(yyvsp[-1].tree_node));insertTree((yyval.tree_node),(yyvsp[0].tree_node)); }
#line 1809 "./syntax.tab.c" /* yacc.c:1646  */
    break;

  case 53:
#line 203 "./syntax.y" /* yacc.c:1646  */
    { (yyval.tree_node)=newNode((yyloc).first_line,TYPE_Exp,"Exp","");
			insertTree((yyval.tree_node),(yyvsp[-2].tree_node));insertTree((yyval.tree_node),(yyvsp[-1].tree_node));insertTree((yyval.tree_node),(yyvsp[0].tree_node)); }
#line 1816 "./syntax.tab.c" /* yacc.c:1646  */
    break;

  case 54:
#line 206 "./syntax.y" /* yacc.c:1646  */
    { (yyval.tree_node)=newNode((yyloc).first_line,TYPE_Exp,"Exp","");
			insertTree((yyval.tree_node),(yyvsp[-2].tree_node));insertTree((yyval.tree_node),(yyvsp[-1].tree_node));insertTree((yyval.tree_node),(yyvsp[0].tree_node)); }
#line 1823 "./syntax.tab.c" /* yacc.c:1646  */
    break;

  case 55:
#line 209 "./syntax.y" /* yacc.c:1646  */
    { (yyval.tree_node)=newNode((yyloc).first_line,TYPE_Exp,"Exp","");
			insertTree((yyval.tree_node),(yyvsp[-2].tree_node));insertTree((yyval.tree_node),(yyvsp[-1].tree_node));insertTree((yyval.tree_node),(yyvsp[0].tree_node)); }
#line 1830 "./syntax.tab.c" /* yacc.c:1646  */
    break;

  case 56:
#line 212 "./syntax.y" /* yacc.c:1646  */
    { (yyval.tree_node)=newNode((yyloc).first_line,TYPE_Exp,"Exp","");
			insertTree((yyval.tree_node),(yyvsp[-2].tree_node));insertTree((yyval.tree_node),(yyvsp[-1].tree_node));insertTree((yyval.tree_node),(yyvsp[0].tree_node)); }
#line 1837 "./syntax.tab.c" /* yacc.c:1646  */
    break;

  case 57:
#line 215 "./syntax.y" /* yacc.c:1646  */
    { (yyval.tree_node)=newNode((yyloc).first_line,TYPE_Exp,"Exp","");
			insertTree((yyval.tree_node),(yyvsp[-2].tree_node));insertTree((yyval.tree_node),(yyvsp[-1].tree_node));insertTree((yyval.tree_node),(yyvsp[0].tree_node)); }
#line 1844 "./syntax.tab.c" /* yacc.c:1646  */
    break;

  case 58:
#line 218 "./syntax.y" /* yacc.c:1646  */
    { (yyval.tree_node)=newNode((yyloc).first_line,TYPE_Exp,"Exp","");
			insertTree((yyval.tree_node),(yyvsp[-2].tree_node));insertTree((yyval.tree_node),(yyvsp[-1].tree_node));insertTree((yyval.tree_node),(yyvsp[0].tree_node)); }
#line 1851 "./syntax.tab.c" /* yacc.c:1646  */
    break;

  case 59:
#line 221 "./syntax.y" /* yacc.c:1646  */
    { (yyval.tree_node)=newNode((yyloc).first_line,TYPE_Exp,"Exp","");
			insertTree((yyval.tree_node),(yyvsp[-2].tree_node));insertTree((yyval.tree_node),(yyvsp[-1].tree_node));insertTree((yyval.tree_node),(yyvsp[0].tree_node)); }
#line 1858 "./syntax.tab.c" /* yacc.c:1646  */
    break;

  case 60:
#line 224 "./syntax.y" /* yacc.c:1646  */
    { (yyval.tree_node)=newNode((yyloc).first_line,TYPE_Exp,"Exp","");
			insertTree((yyval.tree_node),(yyvsp[-2].tree_node));insertTree((yyval.tree_node),(yyvsp[-1].tree_node));insertTree((yyval.tree_node),(yyvsp[0].tree_node)); }
#line 1865 "./syntax.tab.c" /* yacc.c:1646  */
    break;

  case 61:
#line 227 "./syntax.y" /* yacc.c:1646  */
    { (yyval.tree_node)=newNode((yyloc).first_line,TYPE_Exp,"Exp","");
			insertTree((yyval.tree_node),(yyvsp[-1].tree_node));insertTree((yyval.tree_node),(yyvsp[0].tree_node)); }
#line 1872 "./syntax.tab.c" /* yacc.c:1646  */
    break;

  case 62:
#line 230 "./syntax.y" /* yacc.c:1646  */
    { (yyval.tree_node)=newNode((yyloc).first_line,TYPE_Exp,"Exp","");
			insertTree((yyval.tree_node),(yyvsp[-1].tree_node));insertTree((yyval.tree_node),(yyvsp[0].tree_node)); }
#line 1879 "./syntax.tab.c" /* yacc.c:1646  */
    break;

  case 63:
#line 233 "./syntax.y" /* yacc.c:1646  */
    { (yyval.tree_node)=newNode((yyloc).first_line,TYPE_Exp,"Exp","");
			insertTree((yyval.tree_node),(yyvsp[-3].tree_node));insertTree((yyval.tree_node),(yyvsp[-2].tree_node));insertTree((yyval.tree_node),(yyvsp[-1].tree_node));insertTree((yyval.tree_node),(yyvsp[0].tree_node)); }
#line 1886 "./syntax.tab.c" /* yacc.c:1646  */
    break;

  case 64:
#line 236 "./syntax.y" /* yacc.c:1646  */
    { (yyval.tree_node)=newNode((yyloc).first_line,TYPE_Exp,"Exp","");
			insertTree((yyval.tree_node),(yyvsp[-2].tree_node));insertTree((yyval.tree_node),(yyvsp[-1].tree_node));insertTree((yyval.tree_node),(yyvsp[0].tree_node)); }
#line 1893 "./syntax.tab.c" /* yacc.c:1646  */
    break;

  case 65:
#line 239 "./syntax.y" /* yacc.c:1646  */
    { (yyval.tree_node)=newNode((yyloc).first_line,TYPE_Exp,"Exp","");
			insertTree((yyval.tree_node),(yyvsp[-3].tree_node));insertTree((yyval.tree_node),(yyvsp[-2].tree_node));insertTree((yyval.tree_node),(yyvsp[-1].tree_node));insertTree((yyval.tree_node),(yyvsp[0].tree_node)); }
#line 1900 "./syntax.tab.c" /* yacc.c:1646  */
    break;

  case 66:
#line 242 "./syntax.y" /* yacc.c:1646  */
    { (yyval.tree_node)=newNode((yyloc).first_line,TYPE_Exp,"Exp","");
			insertTree((yyval.tree_node),(yyvsp[-2].tree_node));insertTree((yyval.tree_node),(yyvsp[-1].tree_node));insertTree((yyval.tree_node),(yyvsp[0].tree_node)); }
#line 1907 "./syntax.tab.c" /* yacc.c:1646  */
    break;

  case 67:
#line 245 "./syntax.y" /* yacc.c:1646  */
    { (yyval.tree_node)=newNode((yyloc).first_line,TYPE_Exp,"Exp",""); insertTree((yyval.tree_node),(yyvsp[0].tree_node)); }
#line 1913 "./syntax.tab.c" /* yacc.c:1646  */
    break;

  case 68:
#line 247 "./syntax.y" /* yacc.c:1646  */
    { (yyval.tree_node)=newNode((yyloc).first_line,TYPE_Exp,"Exp",""); insertTree((yyval.tree_node),(yyvsp[0].tree_node)); }
#line 1919 "./syntax.tab.c" /* yacc.c:1646  */
    break;

  case 69:
#line 249 "./syntax.y" /* yacc.c:1646  */
    { (yyval.tree_node)=newNode((yyloc).first_line,TYPE_Exp,"Exp","");insertTree((yyval.tree_node),(yyvsp[0].tree_node)); }
#line 1925 "./syntax.tab.c" /* yacc.c:1646  */
    break;

  case 70:
#line 250 "./syntax.y" /* yacc.c:1646  */
    { ErrorSyn=true; }
#line 1931 "./syntax.tab.c" /* yacc.c:1646  */
    break;

  case 71:
#line 254 "./syntax.y" /* yacc.c:1646  */
    { (yyval.tree_node)=newNode((yyloc).first_line,TYPE_Args,"Args","");
			insertTree((yyval.tree_node),(yyvsp[-2].tree_node));insertTree((yyval.tree_node),(yyvsp[-1].tree_node));insertTree((yyval.tree_node),(yyvsp[0].tree_node)); }
#line 1938 "./syntax.tab.c" /* yacc.c:1646  */
    break;

  case 72:
#line 257 "./syntax.y" /* yacc.c:1646  */
    { (yyval.tree_node)=newNode((yyloc).first_line,TYPE_Args,"Args","");insertTree((yyval.tree_node),(yyvsp[0].tree_node)); }
#line 1944 "./syntax.tab.c" /* yacc.c:1646  */
    break;


#line 1948 "./syntax.tab.c" /* yacc.c:1646  */
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
  *++yylsp = yyloc;

  /* Now 'shift' the result of the reduction.  Determine what state
     that goes to, based on the state we popped back to and the rule
     number reduced by.  */

  yyn = yyr1[yyn];

  yystate = yypgoto[yyn - YYNTOKENS] + *yyssp;
  if (0 <= yystate && yystate <= YYLAST && yycheck[yystate] == *yyssp)
    yystate = yytable[yystate];
  else
    yystate = yydefgoto[yyn - YYNTOKENS];

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

  yyerror_range[1] = yylloc;

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
                      yytoken, &yylval, &yylloc);
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

  /* Pacify compilers like GCC when the user code never invokes
     YYERROR and the label yyerrorlab therefore never appears in user
     code.  */
  if (/*CONSTCOND*/ 0)
     goto yyerrorlab;

  yyerror_range[1] = yylsp[1-yylen];
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

      yyerror_range[1] = *yylsp;
      yydestruct ("Error: popping",
                  yystos[yystate], yyvsp, yylsp);
      YYPOPSTACK (1);
      yystate = *yyssp;
      YY_STACK_PRINT (yyss, yyssp);
    }

  YY_IGNORE_MAYBE_UNINITIALIZED_BEGIN
  *++yyvsp = yylval;
  YY_IGNORE_MAYBE_UNINITIALIZED_END

  yyerror_range[2] = yylloc;
  /* Using YYLLOC is tempting, but would change the location of
     the lookahead.  YYLOC is available though.  */
  YYLLOC_DEFAULT (yyloc, yyerror_range, 2);
  *++yylsp = yyloc;

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

yyreturn:
  if (yychar != YYEMPTY)
    {
      /* Make sure we have latest lookahead translation.  See comments at
         user semantic actions for why this is necessary.  */
      yytoken = YYTRANSLATE (yychar);
      yydestruct ("Cleanup: discarding lookahead",
                  yytoken, &yylval, &yylloc);
    }
  /* Do not reclaim the symbols of the rule whose action triggered
     this YYABORT or YYACCEPT.  */
  YYPOPSTACK (yylen);
  YY_STACK_PRINT (yyss, yyssp);
  while (yyssp != yyss)
    {
      yydestruct ("Cleanup: popping",
                  yystos[*yyssp], yyvsp, yylsp);
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
#line 260 "./syntax.y" /* yacc.c:1906  */

yyerror(char* msg)  //rewrite
{
	if(!ErrorLex)// guarantee one error per line
		fprintf(stderr,"Error type B at Line %d: %s\n",yylineno,msg);
}	







