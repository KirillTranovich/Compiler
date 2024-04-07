/* A Bison parser, made by GNU Bison 3.8.2.  */

/* Bison implementation for Yacc-like parsers in C

   Copyright (C) 1984, 1989-1990, 2000-2015, 2018-2021 Free Software Foundation,
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
   along with this program.  If not, see <https://www.gnu.org/licenses/>.  */

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

/* DO NOT RELY ON FEATURES THAT ARE NOT DOCUMENTED in the manual,
   especially those whose name start with YY_ or yy_.  They are
   private implementation details that can be changed or removed.  */

/* All symbols defined below should begin with yy or YY, to avoid
   infringing on user name space.  This should be done even for local
   variables, as they might otherwise be expanded by user macros.
   There are some unavoidable exceptions within include files to
   define necessary library symbols; they are noted "INFRINGES ON
   USER NAME SPACE" below.  */

/* Identify Bison output, and Bison version.  */
#define YYBISON 30802

/* Bison version string.  */
#define YYBISON_VERSION "3.8.2"

/* Skeleton name.  */
#define YYSKELETON_NAME "yacc.c"

/* Pure parsers.  */
#define YYPURE 0

/* Push parsers.  */
#define YYPUSH 0

/* Pull parsers.  */
#define YYPULL 1




/* First part of user prologue.  */
#line 3 "parser.y"

#include <stdarg.h>
#include <stdio.h>
#include <stdlib.h>
#include "main.h"
#include <string.h>
char* concat_strings(char* str1, char* str2) {
    // Calculate the length of the resulting string
    size_t len1 = strlen(str1);
    size_t len2 = strlen(str2);
    size_t total_len = len1 + len2 + 1;

    // Allocate memory for the resulting string
    char* result = (char*)malloc(total_len * sizeof(char));
    if (result == NULL) {
        fprintf(stderr, "Memory allocation failed\n");
        exit(EXIT_FAILURE);
    }

    // Copy the first string to the resulting string
    strncpy(result, str1, len1);

    // Concatenate the second string to the resulting string
    strncpy(result + len1, str2, len2 + 1);

    return result;
}

extern struct ast;

#line 102 "parser.tab.c"

# ifndef YY_CAST
#  ifdef __cplusplus
#   define YY_CAST(Type, Val) static_cast<Type> (Val)
#   define YY_REINTERPRET_CAST(Type, Val) reinterpret_cast<Type> (Val)
#  else
#   define YY_CAST(Type, Val) ((Type) (Val))
#   define YY_REINTERPRET_CAST(Type, Val) ((Type) (Val))
#  endif
# endif
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

#include "parser.tab.h"
/* Symbol kind.  */
enum yysymbol_kind_t
{
  YYSYMBOL_YYEMPTY = -2,
  YYSYMBOL_YYEOF = 0,                      /* "end of file"  */
  YYSYMBOL_YYerror = 1,                    /* error  */
  YYSYMBOL_YYUNDEF = 2,                    /* "invalid token"  */
  YYSYMBOL_NUMBER = 3,                     /* NUMBER  */
  YYSYMBOL_NAME = 4,                       /* NAME  */
  YYSYMBOL_STRING = 5,                     /* STRING  */
  YYSYMBOL_IF = 6,                         /* IF  */
  YYSYMBOL_ELSE = 7,                       /* ELSE  */
  YYSYMBOL_WHILE = 8,                      /* WHILE  */
  YYSYMBOL_FOR = 9,                        /* FOR  */
  YYSYMBOL_DEF = 10,                       /* DEF  */
  YYSYMBOL_CLASS = 11,                     /* CLASS  */
  YYSYMBOL_NEW = 12,                       /* NEW  */
  YYSYMBOL_AND = 13,                       /* AND  */
  YYSYMBOL_OR = 14,                        /* OR  */
  YYSYMBOL_CMP = 15,                       /* CMP  */
  YYSYMBOL_16_ = 16,                       /* '='  */
  YYSYMBOL_17_ = 17,                       /* '+'  */
  YYSYMBOL_18_ = 18,                       /* '-'  */
  YYSYMBOL_19_ = 19,                       /* '*'  */
  YYSYMBOL_20_ = 20,                       /* '/'  */
  YYSYMBOL_21_ = 21,                       /* '|'  */
  YYSYMBOL_UMINUS = 22,                    /* UMINUS  */
  YYSYMBOL_23_ = 23,                       /* ';'  */
  YYSYMBOL_24_ = 24,                       /* '('  */
  YYSYMBOL_25_ = 25,                       /* ')'  */
  YYSYMBOL_26_ = 26,                       /* '.'  */
  YYSYMBOL_27_ = 27,                       /* '['  */
  YYSYMBOL_28_ = 28,                       /* ']'  */
  YYSYMBOL_29_ = 29,                       /* ':'  */
  YYSYMBOL_30_ = 30,                       /* '{'  */
  YYSYMBOL_31_ = 31,                       /* '}'  */
  YYSYMBOL_32_ = 32,                       /* ','  */
  YYSYMBOL_YYACCEPT = 33,                  /* $accept  */
  YYSYMBOL_command = 34,                   /* command  */
  YYSYMBOL_name = 35,                      /* name  */
  YYSYMBOL_new_class = 36,                 /* new_class  */
  YYSYMBOL_cr_class = 37,                  /* cr_class  */
  YYSYMBOL_cr_func = 38,                   /* cr_func  */
  YYSYMBOL_condition = 39,                 /* condition  */
  YYSYMBOL_cycle = 40,                     /* cycle  */
  YYSYMBOL_level = 41,                     /* level  */
  YYSYMBOL_exp = 42,                       /* exp  */
  YYSYMBOL_explist = 43                    /* explist  */
};
typedef enum yysymbol_kind_t yysymbol_kind_t;




#ifdef short
# undef short
#endif

/* On compilers that do not define __PTRDIFF_MAX__ etc., make sure
   <limits.h> and (if available) <stdint.h> are included
   so that the code can choose integer types of a good width.  */

#ifndef __PTRDIFF_MAX__
# include <limits.h> /* INFRINGES ON USER NAME SPACE */
# if defined __STDC_VERSION__ && 199901 <= __STDC_VERSION__
#  include <stdint.h> /* INFRINGES ON USER NAME SPACE */
#  define YY_STDINT_H
# endif
#endif

/* Narrow types that promote to a signed type and that can represent a
   signed or unsigned integer of at least N bits.  In tables they can
   save space and decrease cache pressure.  Promoting to a signed type
   helps avoid bugs in integer arithmetic.  */

#ifdef __INT_LEAST8_MAX__
typedef __INT_LEAST8_TYPE__ yytype_int8;
#elif defined YY_STDINT_H
typedef int_least8_t yytype_int8;
#else
typedef signed char yytype_int8;
#endif

#ifdef __INT_LEAST16_MAX__
typedef __INT_LEAST16_TYPE__ yytype_int16;
#elif defined YY_STDINT_H
typedef int_least16_t yytype_int16;
#else
typedef short yytype_int16;
#endif

/* Work around bug in HP-UX 11.23, which defines these macros
   incorrectly for preprocessor constants.  This workaround can likely
   be removed in 2023, as HPE has promised support for HP-UX 11.23
   (aka HP-UX 11i v2) only through the end of 2022; see Table 2 of
   <https://h20195.www2.hpe.com/V2/getpdf.aspx/4AA4-7673ENW.pdf>.  */
#ifdef __hpux
# undef UINT_LEAST8_MAX
# undef UINT_LEAST16_MAX
# define UINT_LEAST8_MAX 255
# define UINT_LEAST16_MAX 65535
#endif

#if defined __UINT_LEAST8_MAX__ && __UINT_LEAST8_MAX__ <= __INT_MAX__
typedef __UINT_LEAST8_TYPE__ yytype_uint8;
#elif (!defined __UINT_LEAST8_MAX__ && defined YY_STDINT_H \
       && UINT_LEAST8_MAX <= INT_MAX)
typedef uint_least8_t yytype_uint8;
#elif !defined __UINT_LEAST8_MAX__ && UCHAR_MAX <= INT_MAX
typedef unsigned char yytype_uint8;
#else
typedef short yytype_uint8;
#endif

#if defined __UINT_LEAST16_MAX__ && __UINT_LEAST16_MAX__ <= __INT_MAX__
typedef __UINT_LEAST16_TYPE__ yytype_uint16;
#elif (!defined __UINT_LEAST16_MAX__ && defined YY_STDINT_H \
       && UINT_LEAST16_MAX <= INT_MAX)
typedef uint_least16_t yytype_uint16;
#elif !defined __UINT_LEAST16_MAX__ && USHRT_MAX <= INT_MAX
typedef unsigned short yytype_uint16;
#else
typedef int yytype_uint16;
#endif

#ifndef YYPTRDIFF_T
# if defined __PTRDIFF_TYPE__ && defined __PTRDIFF_MAX__
#  define YYPTRDIFF_T __PTRDIFF_TYPE__
#  define YYPTRDIFF_MAXIMUM __PTRDIFF_MAX__
# elif defined PTRDIFF_MAX
#  ifndef ptrdiff_t
#   include <stddef.h> /* INFRINGES ON USER NAME SPACE */
#  endif
#  define YYPTRDIFF_T ptrdiff_t
#  define YYPTRDIFF_MAXIMUM PTRDIFF_MAX
# else
#  define YYPTRDIFF_T long
#  define YYPTRDIFF_MAXIMUM LONG_MAX
# endif
#endif

#ifndef YYSIZE_T
# ifdef __SIZE_TYPE__
#  define YYSIZE_T __SIZE_TYPE__
# elif defined size_t
#  define YYSIZE_T size_t
# elif defined __STDC_VERSION__ && 199901 <= __STDC_VERSION__
#  include <stddef.h> /* INFRINGES ON USER NAME SPACE */
#  define YYSIZE_T size_t
# else
#  define YYSIZE_T unsigned
# endif
#endif

#define YYSIZE_MAXIMUM                                  \
  YY_CAST (YYPTRDIFF_T,                                 \
           (YYPTRDIFF_MAXIMUM < YY_CAST (YYSIZE_T, -1)  \
            ? YYPTRDIFF_MAXIMUM                         \
            : YY_CAST (YYSIZE_T, -1)))

#define YYSIZEOF(X) YY_CAST (YYPTRDIFF_T, sizeof (X))


/* Stored state numbers (used for stacks). */
typedef yytype_int8 yy_state_t;

/* State numbers in computations.  */
typedef int yy_state_fast_t;

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


#ifndef YY_ATTRIBUTE_PURE
# if defined __GNUC__ && 2 < __GNUC__ + (96 <= __GNUC_MINOR__)
#  define YY_ATTRIBUTE_PURE __attribute__ ((__pure__))
# else
#  define YY_ATTRIBUTE_PURE
# endif
#endif

#ifndef YY_ATTRIBUTE_UNUSED
# if defined __GNUC__ && 2 < __GNUC__ + (7 <= __GNUC_MINOR__)
#  define YY_ATTRIBUTE_UNUSED __attribute__ ((__unused__))
# else
#  define YY_ATTRIBUTE_UNUSED
# endif
#endif

/* Suppress unused-variable warnings by "using" E.  */
#if ! defined lint || defined __GNUC__
# define YY_USE(E) ((void) (E))
#else
# define YY_USE(E) /* empty */
#endif

/* Suppress an incorrect diagnostic about yylval being uninitialized.  */
#if defined __GNUC__ && ! defined __ICC && 406 <= __GNUC__ * 100 + __GNUC_MINOR__
# if __GNUC__ * 100 + __GNUC_MINOR__ < 407
#  define YY_IGNORE_MAYBE_UNINITIALIZED_BEGIN                           \
    _Pragma ("GCC diagnostic push")                                     \
    _Pragma ("GCC diagnostic ignored \"-Wuninitialized\"")
# else
#  define YY_IGNORE_MAYBE_UNINITIALIZED_BEGIN                           \
    _Pragma ("GCC diagnostic push")                                     \
    _Pragma ("GCC diagnostic ignored \"-Wuninitialized\"")              \
    _Pragma ("GCC diagnostic ignored \"-Wmaybe-uninitialized\"")
# endif
# define YY_IGNORE_MAYBE_UNINITIALIZED_END      \
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

#if defined __cplusplus && defined __GNUC__ && ! defined __ICC && 6 <= __GNUC__
# define YY_IGNORE_USELESS_CAST_BEGIN                          \
    _Pragma ("GCC diagnostic push")                            \
    _Pragma ("GCC diagnostic ignored \"-Wuseless-cast\"")
# define YY_IGNORE_USELESS_CAST_END            \
    _Pragma ("GCC diagnostic pop")
#endif
#ifndef YY_IGNORE_USELESS_CAST_BEGIN
# define YY_IGNORE_USELESS_CAST_BEGIN
# define YY_IGNORE_USELESS_CAST_END
#endif


#define YY_ASSERT(E) ((void) (0 && (E)))

#if !defined yyoverflow

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
#endif /* !defined yyoverflow */

#if (! defined yyoverflow \
     && (! defined __cplusplus \
         || (defined YYSTYPE_IS_TRIVIAL && YYSTYPE_IS_TRIVIAL)))

/* A type that is properly aligned for any stack member.  */
union yyalloc
{
  yy_state_t yyss_alloc;
  YYSTYPE yyvs_alloc;
};

/* The size of the maximum gap between one aligned stack and the next.  */
# define YYSTACK_GAP_MAXIMUM (YYSIZEOF (union yyalloc) - 1)

/* The size of an array large to enough to hold all stacks, each with
   N elements.  */
# define YYSTACK_BYTES(N) \
     ((N) * (YYSIZEOF (yy_state_t) + YYSIZEOF (YYSTYPE)) \
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
        YYPTRDIFF_T yynewbytes;                                         \
        YYCOPY (&yyptr->Stack_alloc, Stack, yysize);                    \
        Stack = &yyptr->Stack_alloc;                                    \
        yynewbytes = yystacksize * YYSIZEOF (*Stack) + YYSTACK_GAP_MAXIMUM; \
        yyptr += yynewbytes / YYSIZEOF (*yyptr);                        \
      }                                                                 \
    while (0)

#endif

#if defined YYCOPY_NEEDED && YYCOPY_NEEDED
/* Copy COUNT objects from SRC to DST.  The source and destination do
   not overlap.  */
# ifndef YYCOPY
#  if defined __GNUC__ && 1 < __GNUC__
#   define YYCOPY(Dst, Src, Count) \
      __builtin_memcpy (Dst, Src, YY_CAST (YYSIZE_T, (Count)) * sizeof (*(Src)))
#  else
#   define YYCOPY(Dst, Src, Count)              \
      do                                        \
        {                                       \
          YYPTRDIFF_T yyi;                      \
          for (yyi = 0; yyi < (Count); yyi++)   \
            (Dst)[yyi] = (Src)[yyi];            \
        }                                       \
      while (0)
#  endif
# endif
#endif /* !YYCOPY_NEEDED */

/* YYFINAL -- State number of the termination state.  */
#define YYFINAL  2
/* YYLAST -- Last index in YYTABLE.  */
#define YYLAST   296

/* YYNTOKENS -- Number of terminals.  */
#define YYNTOKENS  33
/* YYNNTS -- Number of nonterminals.  */
#define YYNNTS  11
/* YYNRULES -- Number of rules.  */
#define YYNRULES  43
/* YYNSTATES -- Number of states.  */
#define YYNSTATES  106

/* YYMAXUTOK -- Last valid token kind.  */
#define YYMAXUTOK   271


/* YYTRANSLATE(TOKEN-NUM) -- Symbol number corresponding to TOKEN-NUM
   as returned by yylex, with out-of-bounds checking.  */
#define YYTRANSLATE(YYX)                                \
  (0 <= (YYX) && (YYX) <= YYMAXUTOK                     \
   ? YY_CAST (yysymbol_kind_t, yytranslate[YYX])        \
   : YYSYMBOL_YYUNDEF)

/* YYTRANSLATE[TOKEN-NUM] -- Symbol number corresponding to TOKEN-NUM
   as returned by yylex.  */
static const yytype_int8 yytranslate[] =
{
       0,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
      24,    25,    19,    17,    32,    18,    26,    20,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,    29,    23,
       2,    16,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,    27,     2,    28,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,    30,    21,    31,     2,     2,     2,     2,
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
      15,    22
};

#if YYDEBUG
/* YYRLINE[YYN] -- Source line where rule number YYN was defined.  */
static const yytype_uint8 yyrline[] =
{
       0,    59,    59,    60,    62,    64,    66,    68,    70,    72,
      74,    78,    79,    81,    82,    83,    85,    88,    89,    92,
      93,    96,    97,   100,   101,   104,   105,   106,   109,   112,
     114,   116,   118,   120,   122,   124,   126,   128,   130,   131,
     133,   134,   137,   138
};
#endif

/** Accessing symbol of state STATE.  */
#define YY_ACCESSING_SYMBOL(State) YY_CAST (yysymbol_kind_t, yystos[State])

#if YYDEBUG || 0
/* The user-facing name of the symbol whose (internal) number is
   YYSYMBOL.  No bounds checking.  */
static const char *yysymbol_name (yysymbol_kind_t yysymbol) YY_ATTRIBUTE_UNUSED;

/* YYTNAME[SYMBOL-NUM] -- String name of the symbol SYMBOL-NUM.
   First, the terminals, then, starting at YYNTOKENS, nonterminals.  */
static const char *const yytname[] =
{
  "\"end of file\"", "error", "\"invalid token\"", "NUMBER", "NAME",
  "STRING", "IF", "ELSE", "WHILE", "FOR", "DEF", "CLASS", "NEW", "AND",
  "OR", "CMP", "'='", "'+'", "'-'", "'*'", "'/'", "'|'", "UMINUS", "';'",
  "'('", "')'", "'.'", "'['", "']'", "':'", "'{'", "'}'", "','", "$accept",
  "command", "name", "new_class", "cr_class", "cr_func", "condition",
  "cycle", "level", "exp", "explist", YY_NULLPTR
};

static const char *
yysymbol_name (yysymbol_kind_t yysymbol)
{
  return yytname[yysymbol];
}
#endif

#define YYPACT_NINF (-36)

#define yypact_value_is_default(Yyn) \
  ((Yyn) == YYPACT_NINF)

#define YYTABLE_NINF (-19)

#define yytable_value_is_error(Yyn) \
  ((Yyn) == YYTABLE_NINF)

/* YYPACT[STATE-NUM] -- Index in YYTABLE of the portion describing
   STATE-NUM.  */
static const yytype_int16 yypact[] =
{
     -36,    98,   -36,   -36,   -36,   -36,   -19,   -12,    -2,     7,
       4,     4,   176,   -36,   176,   -36,    28,     2,    14,    16,
     -36,   -36,   -36,   227,   176,   -36,   176,   176,    65,    69,
      37,   -36,   178,   126,   -36,   164,   121,    39,   176,   -36,
     -36,   -36,   176,   176,   176,   176,   176,   176,   176,   -36,
     191,   200,    -3,   238,   137,   148,   176,   -36,   -36,     4,
     276,   -36,   260,   -18,   -36,   -22,    57,    57,   268,    61,
      61,   -36,   -36,   -12,   -12,   176,   176,   -12,   -16,   -12,
       8,    86,   -36,   176,   -36,   -36,   -36,   209,   249,   -36,
     -12,   -36,   -12,   160,   260,   -12,   176,   -36,   -36,    33,
      10,   -36,   218,    34,   -12,   -36
};

/* YYDEFACT[STATE-NUM] -- Default reduction number in state STATE-NUM.
   Performed when YYTABLE does not specify something else to do.  Zero
   means the default is an error.  */
static const yytype_int8 yydefact[] =
{
       2,     0,     1,    38,    11,    40,     0,     0,     0,     0,
       0,     0,     0,     3,     0,     2,    41,     0,     0,     0,
      10,     9,     8,     0,     0,    24,     0,     0,     0,     0,
      41,    37,     0,     0,    12,     0,     0,     0,     0,     4,
       5,     6,     0,     0,     0,     0,     0,     0,     0,     7,
       0,     0,    41,     0,     0,     0,     0,    36,    28,     0,
      39,    13,    42,     0,    14,     0,    30,    31,    29,    32,
      33,    34,    35,     0,     0,     0,     0,    13,     0,    13,
       0,     0,    15,     0,    16,    23,    27,     0,     0,    22,
      15,    20,    15,     0,    43,     0,     0,    21,    19,    13,
       0,    26,     0,    15,     0,    25
};

/* YYPGOTO[NTERM-NUM].  */
static const yytype_int8 yypgoto[] =
{
     -36,    47,     1,   -36,   -36,   -36,   -36,   -36,    -7,     3,
     -35
};

/* YYDEFGOTO[NTERM-NUM].  */
static const yytype_int8 yydefgoto[] =
{
       0,     1,    30,    17,    18,    19,    20,    21,    22,    62,
      63
};

/* YYTABLE[YYPACT[STATE-NUM]] -- What to do in state STATE-NUM.  If
   positive, shift that token.  If negative, reduce the rule whose
   number is the opposite.  If YYTABLE_NINF, syntax error.  */
static const yytype_int8 yytable[] =
{
      25,    34,    16,    65,    23,    24,    84,    82,     4,    90,
      83,    28,    29,    56,    83,    31,    83,    32,    15,    78,
      80,    36,    26,    37,    38,    39,    75,    50,    52,    51,
      53,    27,    34,    92,    16,   103,    23,    40,    60,    41,
      83,    34,    83,    64,    35,    66,    67,    68,    69,    70,
      71,    72,    36,    56,    37,    38,   -18,   -17,   100,    60,
      81,    36,    33,    37,    38,     0,    85,    86,     0,    34,
      89,     0,    91,    34,    45,    46,    47,    48,    87,    88,
      47,    48,     0,    97,     0,    98,    94,     0,   101,    54,
      34,    37,    38,    55,     0,    37,    38,   105,     2,   102,
       0,     3,     4,     5,     6,     7,     8,     9,    10,    11,
      93,     0,    37,    38,     0,     0,    12,     0,     0,     0,
       0,    13,    14,     0,     3,     4,     5,     0,    15,     3,
       4,     5,     6,     7,     8,     9,    10,    11,     0,    12,
       3,     4,     5,     0,    12,    14,    61,     0,     0,    13,
      14,     3,     4,     5,     0,    12,    15,    58,     0,     0,
       0,    14,    77,     3,     4,     5,    12,     3,     4,     5,
       0,     0,    14,    79,     0,     0,    59,     0,    12,     3,
       4,     5,    12,     0,    14,    99,     0,     0,    14,     0,
       0,    42,    43,    44,    12,    45,    46,    47,    48,     0,
      14,     0,     0,    57,    42,    43,    44,     0,    45,    46,
      47,    48,     0,    42,    43,    44,    73,    45,    46,    47,
      48,     0,    42,    43,    44,    74,    45,    46,    47,    48,
       0,    42,    43,    44,    95,    45,    46,    47,    48,     0,
      42,    43,    44,   104,    45,    46,    47,    48,     0,     0,
      49,    42,    43,    44,     0,    45,    46,    47,    48,     0,
       0,    76,    42,    43,    44,     0,    45,    46,    47,    48,
       0,     0,    96,    42,    43,    44,     0,    45,    46,    47,
      48,    42,    43,   -19,     0,    45,    46,    47,    48,    42,
      43,     0,     0,    45,    46,    47,    48
};

static const yytype_int8 yycheck[] =
{
       7,     4,     1,    38,     1,    24,    28,    25,     4,    25,
      32,    10,    11,    16,    32,    12,    32,    14,    30,    54,
      55,    24,    24,    26,    27,    23,    29,    24,    27,    26,
      27,    24,     4,    25,    33,    25,    33,    23,    35,    23,
      32,     4,    32,     4,    16,    42,    43,    44,    45,    46,
      47,    48,    24,    16,    26,    27,    23,    23,    93,    56,
      59,    24,    15,    26,    27,    -1,    73,    74,    -1,     4,
      77,    -1,    79,     4,    17,    18,    19,    20,    75,    76,
      19,    20,    -1,    90,    -1,    92,    83,    -1,    95,    24,
       4,    26,    27,    24,    -1,    26,    27,   104,     0,    96,
      -1,     3,     4,     5,     6,     7,     8,     9,    10,    11,
      24,    -1,    26,    27,    -1,    -1,    18,    -1,    -1,    -1,
      -1,    23,    24,    -1,     3,     4,     5,    -1,    30,     3,
       4,     5,     6,     7,     8,     9,    10,    11,    -1,    18,
       3,     4,     5,    -1,    18,    24,    25,    -1,    -1,    23,
      24,     3,     4,     5,    -1,    18,    30,    31,    -1,    -1,
      -1,    24,    25,     3,     4,     5,    18,     3,     4,     5,
      -1,    -1,    24,    25,    -1,    -1,    12,    -1,    18,     3,
       4,     5,    18,    -1,    24,    25,    -1,    -1,    24,    -1,
      -1,    13,    14,    15,    18,    17,    18,    19,    20,    -1,
      24,    -1,    -1,    25,    13,    14,    15,    -1,    17,    18,
      19,    20,    -1,    13,    14,    15,    25,    17,    18,    19,
      20,    -1,    13,    14,    15,    25,    17,    18,    19,    20,
      -1,    13,    14,    15,    25,    17,    18,    19,    20,    -1,
      13,    14,    15,    25,    17,    18,    19,    20,    -1,    -1,
      23,    13,    14,    15,    -1,    17,    18,    19,    20,    -1,
      -1,    23,    13,    14,    15,    -1,    17,    18,    19,    20,
      -1,    -1,    23,    13,    14,    15,    -1,    17,    18,    19,
      20,    13,    14,    15,    -1,    17,    18,    19,    20,    13,
      14,    -1,    -1,    17,    18,    19,    20
};

/* YYSTOS[STATE-NUM] -- The symbol kind of the accessing symbol of
   state STATE-NUM.  */
static const yytype_int8 yystos[] =
{
       0,    34,     0,     3,     4,     5,     6,     7,     8,     9,
      10,    11,    18,    23,    24,    30,    35,    36,    37,    38,
      39,    40,    41,    42,    24,    41,    24,    24,    35,    35,
      35,    42,    42,    34,     4,    16,    24,    26,    27,    23,
      23,    23,    13,    14,    15,    17,    18,    19,    20,    23,
      42,    42,    35,    42,    24,    24,    16,    25,    31,    12,
      42,    25,    42,    43,     4,    43,    42,    42,    42,    42,
      42,    42,    42,    25,    25,    29,    23,    25,    43,    25,
      43,    35,    25,    32,    28,    41,    41,    42,    42,    41,
      25,    41,    25,    24,    42,    25,    23,    41,    41,    25,
      43,    41,    42,    25,    25,    41
};

/* YYR1[RULE-NUM] -- Symbol kind of the left-hand side of rule RULE-NUM.  */
static const yytype_int8 yyr1[] =
{
       0,    33,    34,    34,    34,    34,    34,    34,    34,    34,
      34,    35,    35,    35,    35,    35,    35,    36,    36,    37,
      37,    38,    38,    39,    39,    40,    40,    40,    41,    42,
      42,    42,    42,    42,    42,    42,    42,    42,    42,    42,
      42,    42,    43,    43
};

/* YYR2[RULE-NUM] -- Number of symbols on the right-hand side of rule RULE-NUM.  */
static const yytype_int8 yyr2[] =
{
       0,     2,     0,     2,     3,     3,     3,     3,     2,     2,
       2,     1,     2,     3,     3,     4,     4,     7,     6,     6,
       5,     6,     5,     5,     2,     9,     7,     5,     3,     3,
       3,     3,     3,     3,     3,     3,     3,     2,     1,     3,
       1,     1,     1,     3
};


enum { YYENOMEM = -2 };

#define yyerrok         (yyerrstatus = 0)
#define yyclearin       (yychar = YYEMPTY)

#define YYACCEPT        goto yyacceptlab
#define YYABORT         goto yyabortlab
#define YYERROR         goto yyerrorlab
#define YYNOMEM         goto yyexhaustedlab


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

/* Backward compatibility with an undocumented macro.
   Use YYerror or YYUNDEF. */
#define YYERRCODE YYUNDEF


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




# define YY_SYMBOL_PRINT(Title, Kind, Value, Location)                    \
do {                                                                      \
  if (yydebug)                                                            \
    {                                                                     \
      YYFPRINTF (stderr, "%s ", Title);                                   \
      yy_symbol_print (stderr,                                            \
                  Kind, Value); \
      YYFPRINTF (stderr, "\n");                                           \
    }                                                                     \
} while (0)


/*-----------------------------------.
| Print this symbol's value on YYO.  |
`-----------------------------------*/

static void
yy_symbol_value_print (FILE *yyo,
                       yysymbol_kind_t yykind, YYSTYPE const * const yyvaluep)
{
  FILE *yyoutput = yyo;
  YY_USE (yyoutput);
  if (!yyvaluep)
    return;
  YY_IGNORE_MAYBE_UNINITIALIZED_BEGIN
  YY_USE (yykind);
  YY_IGNORE_MAYBE_UNINITIALIZED_END
}


/*---------------------------.
| Print this symbol on YYO.  |
`---------------------------*/

static void
yy_symbol_print (FILE *yyo,
                 yysymbol_kind_t yykind, YYSTYPE const * const yyvaluep)
{
  YYFPRINTF (yyo, "%s %s (",
             yykind < YYNTOKENS ? "token" : "nterm", yysymbol_name (yykind));

  yy_symbol_value_print (yyo, yykind, yyvaluep);
  YYFPRINTF (yyo, ")");
}

/*------------------------------------------------------------------.
| yy_stack_print -- Print the state stack from its BOTTOM up to its |
| TOP (included).                                                   |
`------------------------------------------------------------------*/

static void
yy_stack_print (yy_state_t *yybottom, yy_state_t *yytop)
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
yy_reduce_print (yy_state_t *yyssp, YYSTYPE *yyvsp,
                 int yyrule)
{
  int yylno = yyrline[yyrule];
  int yynrhs = yyr2[yyrule];
  int yyi;
  YYFPRINTF (stderr, "Reducing stack by rule %d (line %d):\n",
             yyrule - 1, yylno);
  /* The symbols being reduced.  */
  for (yyi = 0; yyi < yynrhs; yyi++)
    {
      YYFPRINTF (stderr, "   $%d = ", yyi + 1);
      yy_symbol_print (stderr,
                       YY_ACCESSING_SYMBOL (+yyssp[yyi + 1 - yynrhs]),
                       &yyvsp[(yyi + 1) - (yynrhs)]);
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
# define YYDPRINTF(Args) ((void) 0)
# define YY_SYMBOL_PRINT(Title, Kind, Value, Location)
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






/*-----------------------------------------------.
| Release the memory associated to this symbol.  |
`-----------------------------------------------*/

static void
yydestruct (const char *yymsg,
            yysymbol_kind_t yykind, YYSTYPE *yyvaluep)
{
  YY_USE (yyvaluep);
  if (!yymsg)
    yymsg = "Deleting";
  YY_SYMBOL_PRINT (yymsg, yykind, yyvaluep, yylocationp);

  YY_IGNORE_MAYBE_UNINITIALIZED_BEGIN
  YY_USE (yykind);
  YY_IGNORE_MAYBE_UNINITIALIZED_END
}


/* Lookahead token kind.  */
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
    yy_state_fast_t yystate = 0;
    /* Number of tokens to shift before error messages enabled.  */
    int yyerrstatus = 0;

    /* Refer to the stacks through separate pointers, to allow yyoverflow
       to reallocate them elsewhere.  */

    /* Their size.  */
    YYPTRDIFF_T yystacksize = YYINITDEPTH;

    /* The state stack: array, bottom, top.  */
    yy_state_t yyssa[YYINITDEPTH];
    yy_state_t *yyss = yyssa;
    yy_state_t *yyssp = yyss;

    /* The semantic value stack: array, bottom, top.  */
    YYSTYPE yyvsa[YYINITDEPTH];
    YYSTYPE *yyvs = yyvsa;
    YYSTYPE *yyvsp = yyvs;

  int yyn;
  /* The return value of yyparse.  */
  int yyresult;
  /* Lookahead symbol kind.  */
  yysymbol_kind_t yytoken = YYSYMBOL_YYEMPTY;
  /* The variables used to return semantic value and location from the
     action routines.  */
  YYSTYPE yyval;



#define YYPOPSTACK(N)   (yyvsp -= (N), yyssp -= (N))

  /* The number of symbols on the RHS of the reduced rule.
     Keep to zero when no symbol should be popped.  */
  int yylen = 0;

  YYDPRINTF ((stderr, "Starting parse\n"));

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
| yysetstate -- set current state (the top of the stack) to yystate.  |
`--------------------------------------------------------------------*/
yysetstate:
  YYDPRINTF ((stderr, "Entering state %d\n", yystate));
  YY_ASSERT (0 <= yystate && yystate < YYNSTATES);
  YY_IGNORE_USELESS_CAST_BEGIN
  *yyssp = YY_CAST (yy_state_t, yystate);
  YY_IGNORE_USELESS_CAST_END
  YY_STACK_PRINT (yyss, yyssp);

  if (yyss + yystacksize - 1 <= yyssp)
#if !defined yyoverflow && !defined YYSTACK_RELOCATE
    YYNOMEM;
#else
    {
      /* Get the current used size of the three stacks, in elements.  */
      YYPTRDIFF_T yysize = yyssp - yyss + 1;

# if defined yyoverflow
      {
        /* Give user a chance to reallocate the stack.  Use copies of
           these so that the &'s don't force the real ones into
           memory.  */
        yy_state_t *yyss1 = yyss;
        YYSTYPE *yyvs1 = yyvs;

        /* Each stack pointer address is followed by the size of the
           data in use in that stack, in bytes.  This used to be a
           conditional around just the two extra args, but that might
           be undefined if yyoverflow is a macro.  */
        yyoverflow (YY_("memory exhausted"),
                    &yyss1, yysize * YYSIZEOF (*yyssp),
                    &yyvs1, yysize * YYSIZEOF (*yyvsp),
                    &yystacksize);
        yyss = yyss1;
        yyvs = yyvs1;
      }
# else /* defined YYSTACK_RELOCATE */
      /* Extend the stack our own way.  */
      if (YYMAXDEPTH <= yystacksize)
        YYNOMEM;
      yystacksize *= 2;
      if (YYMAXDEPTH < yystacksize)
        yystacksize = YYMAXDEPTH;

      {
        yy_state_t *yyss1 = yyss;
        union yyalloc *yyptr =
          YY_CAST (union yyalloc *,
                   YYSTACK_ALLOC (YY_CAST (YYSIZE_T, YYSTACK_BYTES (yystacksize))));
        if (! yyptr)
          YYNOMEM;
        YYSTACK_RELOCATE (yyss_alloc, yyss);
        YYSTACK_RELOCATE (yyvs_alloc, yyvs);
#  undef YYSTACK_RELOCATE
        if (yyss1 != yyssa)
          YYSTACK_FREE (yyss1);
      }
# endif

      yyssp = yyss + yysize - 1;
      yyvsp = yyvs + yysize - 1;

      YY_IGNORE_USELESS_CAST_BEGIN
      YYDPRINTF ((stderr, "Stack size increased to %ld\n",
                  YY_CAST (long, yystacksize)));
      YY_IGNORE_USELESS_CAST_END

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

  /* YYCHAR is either empty, or end-of-input, or a valid lookahead.  */
  if (yychar == YYEMPTY)
    {
      YYDPRINTF ((stderr, "Reading a token\n"));
      yychar = yylex ();
    }

  if (yychar <= YYEOF)
    {
      yychar = YYEOF;
      yytoken = YYSYMBOL_YYEOF;
      YYDPRINTF ((stderr, "Now at end of input.\n"));
    }
  else if (yychar == YYerror)
    {
      /* The scanner already issued an error message, process directly
         to error recovery.  But do not keep the error token as
         lookahead, it is too special and may lead us to an endless
         loop in error recovery. */
      yychar = YYUNDEF;
      yytoken = YYSYMBOL_YYerror;
      goto yyerrlab1;
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
  yystate = yyn;
  YY_IGNORE_MAYBE_UNINITIALIZED_BEGIN
  *++yyvsp = yylval;
  YY_IGNORE_MAYBE_UNINITIALIZED_END

  /* Discard the shifted token.  */
  yychar = YYEMPTY;
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
  case 2: /* command: %empty  */
#line 59 "parser.y"
                {(yyval.a).type="command";(yyval.a).in_level->line=0;(yyval.a).in_level->next=0;}
#line 1226 "parser.tab.c"
    break;

  case 3: /* command: command ';'  */
#line 60 "parser.y"
                        {(yyval.a).type="command";(yyval.a).in_level->line=(yyvsp[-1].a).in_level->line;(yyval.a).in_level->next=(yyvsp[-1].a).in_level->next;
(yyvsp[-1].a).in_level->prev=(yyval.a).in_level->prev;}
#line 1233 "parser.tab.c"
    break;

  case 4: /* command: command new_class ';'  */
#line 62 "parser.y"
                        {(yyval.a).type="command";(yyval.a).in_level->line=&(yyvsp[-1].a);(yyval.a).in_level->next=(yyvsp[-2].a).in_level;
(yyvsp[-2].a).in_level->prev=(yyval.a).in_level;}
#line 1240 "parser.tab.c"
    break;

  case 5: /* command: command cr_class ';'  */
#line 64 "parser.y"
                        {(yyval.a).type="command";(yyval.a).in_level->line=&(yyvsp[-1].a);(yyval.a).in_level->next=(yyvsp[-2].a).in_level;
(yyvsp[-2].a).in_level->prev=(yyval.a).in_level;}
#line 1247 "parser.tab.c"
    break;

  case 6: /* command: command cr_func ';'  */
#line 66 "parser.y"
                        {(yyval.a).type="command";(yyval.a).in_level->line=&(yyvsp[-1].a);(yyval.a).in_level->next=(yyvsp[-2].a).in_level;
(yyvsp[-2].a).in_level->prev=(yyval.a).in_level;}
#line 1254 "parser.tab.c"
    break;

  case 7: /* command: command exp ';'  */
#line 68 "parser.y"
                        {(yyval.a).type="command";(yyval.a).in_level->line=&(yyvsp[-1].a);(yyval.a).in_level->next=(yyvsp[-2].a).in_level;
(yyvsp[-2].a).in_level->prev=(yyval.a).in_level;}
#line 1261 "parser.tab.c"
    break;

  case 8: /* command: command level  */
#line 70 "parser.y"
                {(yyval.a).type="command";(yyval.a).in_level->line=&(yyvsp[0].a);(yyval.a).in_level->next=(yyvsp[-1].a).in_level;
(yyvsp[-1].a).in_level->prev=(yyval.a).in_level;}
#line 1268 "parser.tab.c"
    break;

  case 9: /* command: command cycle  */
#line 72 "parser.y"
                {(yyval.a).type="command";(yyval.a).in_level->line=&(yyvsp[0].a);(yyval.a).in_level->next=(yyvsp[-1].a).in_level;
(yyvsp[-1].a).in_level->prev=(yyval.a).in_level;}
#line 1275 "parser.tab.c"
    break;

  case 10: /* command: command condition  */
#line 74 "parser.y"
                    {(yyval.a).type="command";(yyval.a).in_level->line=&(yyvsp[0].a);(yyval.a).in_level->next=(yyvsp[-1].a).in_level;
(yyvsp[-1].a).in_level->prev=(yyval.a).in_level;}
#line 1282 "parser.tab.c"
    break;

  case 11: /* name: NAME  */
#line 78 "parser.y"
            {(yyval.a).type = "Name"; (yyval.a).name = (yyvsp[0].str); printf("%s\n",(yyval.a).name);}
#line 1288 "parser.tab.c"
    break;

  case 12: /* name: name NAME  */
#line 79 "parser.y"
            {(yyval.a).type = ""; (yyval.a).name = (yyvsp[0].str);(yyvsp[-1].a).type = "type"; printf("%s\n",(yyval.a).name);
            (yyvsp[-1].a).parent = &(yyval.a);}
#line 1295 "parser.tab.c"
    break;

  case 13: /* name: name '(' ')'  */
#line 81 "parser.y"
             {(yyval.a).type = "Callfunk"; (yyval.a).name = concat_strings((yyvsp[-2].a).name, "()"); printf("%s\n",(yyval.a).name);}
#line 1301 "parser.tab.c"
    break;

  case 14: /* name: name '.' NAME  */
#line 82 "parser.y"
                  { (yyval.a).type = "Name"; (yyval.a).name = concat_strings((yyvsp[0].str), (yyvsp[-2].a).name); printf("%s\n",(yyval.a).name);}
#line 1307 "parser.tab.c"
    break;

  case 15: /* name: name '(' explist ')'  */
#line 83 "parser.y"
                        {(yyval.a).type="Callfunk";(yyval.a).name=(yyvsp[-3].a).name;(yyval.a).args->line=(yyvsp[-1].a).args->line;(yyval.a).args->next=(yyvsp[-1].a).args->next;  }
#line 1313 "parser.tab.c"
    break;

  case 16: /* name: name '[' explist ']'  */
#line 85 "parser.y"
                            {(yyval.a).type="arr_member";(yyval.a).name=(yyvsp[-3].a).name;(yyval.a).args->line=(yyvsp[-1].a).args->line;(yyval.a).args->next=(yyvsp[-1].a).args->next; }
#line 1319 "parser.tab.c"
    break;

  case 17: /* new_class: name '=' NEW name '(' explist ')'  */
#line 88 "parser.y"
                                              {(yyval.a).type=concat_strings("ex_of_class",(yyvsp[-3].a).name); (yyval.a).name=(yyvsp[-6].a).name;(yyval.a).args->line=(yyvsp[-1].a).args->line;(yyval.a).args->next=(yyvsp[-1].a).args->next;}
#line 1325 "parser.tab.c"
    break;

  case 18: /* new_class: name '=' NEW name '(' ')'  */
#line 89 "parser.y"
                             {(yyval.a).type=concat_strings("ex_of_class",(yyvsp[-2].a).name); (yyval.a).name=(yyvsp[-5].a).name;(yyval.a).args->line=0;(yyval.a).args->next=0;}
#line 1331 "parser.tab.c"
    break;

  case 19: /* cr_class: CLASS name '(' explist ')' level  */
#line 92 "parser.y"
                                                       {(yyval.a).type=concat_strings("class",(yyvsp[-2].a).name); (yyval.a).name=(yyvsp[-4].a).name;(yyval.a).args->line=(yyvsp[0].a).args->line;(yyval.a).args->next=(yyvsp[0].a).args->next;}
#line 1337 "parser.tab.c"
    break;

  case 20: /* cr_class: CLASS name '(' ')' level  */
#line 93 "parser.y"
                                         {}
#line 1343 "parser.tab.c"
    break;

  case 21: /* cr_func: DEF name '(' explist ')' level  */
#line 96 "parser.y"
                                                       {}
#line 1349 "parser.tab.c"
    break;

  case 22: /* cr_func: DEF name '(' ')' level  */
#line 97 "parser.y"
                                   {}
#line 1355 "parser.tab.c"
    break;

  case 23: /* condition: IF '(' exp ')' level  */
#line 100 "parser.y"
                                                      {}
#line 1361 "parser.tab.c"
    break;

  case 24: /* condition: ELSE level  */
#line 101 "parser.y"
                                               {}
#line 1367 "parser.tab.c"
    break;

  case 25: /* cycle: FOR '(' exp ';' exp ';' exp ')' level  */
#line 104 "parser.y"
                                                      {}
#line 1373 "parser.tab.c"
    break;

  case 26: /* cycle: FOR '(' name ':' exp ')' level  */
#line 105 "parser.y"
                                                      {}
#line 1379 "parser.tab.c"
    break;

  case 27: /* cycle: WHILE '(' exp ')' level  */
#line 106 "parser.y"
                                                      {}
#line 1385 "parser.tab.c"
    break;

  case 28: /* level: '{' command '}'  */
#line 109 "parser.y"
                      {(yyval.a).type = "lvl"; (yyval.a).left_child=&(yyvsp[-1].a);(yyvsp[-1].a).parent=&(yyval.a);}
#line 1391 "parser.tab.c"
    break;

  case 29: /* exp: exp CMP exp  */
#line 112 "parser.y"
                            { (yyval.a).type=(yyvsp[-1].str); (yyval.a).left_child = &(yyvsp[-2].a); (yyval.a).right_child = &(yyvsp[0].a);
                              (yyvsp[-2].a).parent = &(yyval.a); (yyvsp[0].a).parent = &(yyval.a); }
#line 1398 "parser.tab.c"
    break;

  case 30: /* exp: exp AND exp  */
#line 114 "parser.y"
                            {(yyval.a).type="and";  (yyval.a).left_child = &(yyvsp[-2].a); (yyval.a).right_child = &(yyvsp[0].a);
                              (yyvsp[-2].a).parent = &(yyval.a); (yyvsp[0].a).parent = &(yyval.a); }
#line 1405 "parser.tab.c"
    break;

  case 31: /* exp: exp OR exp  */
#line 116 "parser.y"
                            {(yyval.a).type="or";  (yyval.a).left_child = &(yyvsp[-2].a); (yyval.a).right_child = &(yyvsp[0].a);
                              (yyvsp[-2].a).parent = &(yyval.a); (yyvsp[0].a).parent = &(yyval.a); }
#line 1412 "parser.tab.c"
    break;

  case 32: /* exp: exp '+' exp  */
#line 118 "parser.y"
                            {(yyval.a).type="+"; (yyval.a).left_child = &(yyvsp[-2].a); (yyval.a).right_child = &(yyvsp[0].a);
                              (yyvsp[-2].a).parent = &(yyval.a); (yyvsp[0].a).parent = &(yyval.a); }
#line 1419 "parser.tab.c"
    break;

  case 33: /* exp: exp '-' exp  */
#line 120 "parser.y"
                            {(yyval.a).type="-";  (yyval.a).left_child = &(yyvsp[-2].a); (yyval.a).right_child = &(yyvsp[0].a);
                              (yyvsp[-2].a).parent = &(yyval.a); (yyvsp[0].a).parent = &(yyval.a); }
#line 1426 "parser.tab.c"
    break;

  case 34: /* exp: exp '*' exp  */
#line 122 "parser.y"
                            {(yyval.a).type="*";  (yyval.a).left_child = &(yyvsp[-2].a); (yyval.a).right_child = &(yyvsp[0].a);
                              (yyvsp[-2].a).parent = &(yyval.a); (yyvsp[0].a).parent = &(yyval.a); }
#line 1433 "parser.tab.c"
    break;

  case 35: /* exp: exp '/' exp  */
#line 124 "parser.y"
                            {(yyval.a).type="/";  (yyval.a).left_child = &(yyvsp[-2].a); (yyval.a).right_child = &(yyvsp[0].a);
                              (yyvsp[-2].a).parent = &(yyval.a); (yyvsp[0].a).parent = &(yyval.a); }
#line 1440 "parser.tab.c"
    break;

  case 36: /* exp: '(' exp ')'  */
#line 126 "parser.y"
                            { (yyval.a).type=concat_strings(concat_strings("(",(yyvsp[-1].a).type),")"); (yyval.a).left_child = &(yyvsp[-1].a);
                              (yyvsp[-1].a).parent = &(yyval.a); }
#line 1447 "parser.tab.c"
    break;

  case 37: /* exp: '-' exp  */
#line 128 "parser.y"
                            {(yyval.a).type=concat_strings("-",(yyvsp[0].a).name);  (yyval.a).left_child = &(yyvsp[0].a);
                              (yyvsp[0].a).parent = &(yyval.a); }
#line 1454 "parser.tab.c"
    break;

  case 38: /* exp: NUMBER  */
#line 130 "parser.y"
                            {(yyval.a).type = "Digit"; (yyval.a).value = (yyvsp[0].str); printf("%s\n",(yyval.a).value); }
#line 1460 "parser.tab.c"
    break;

  case 39: /* exp: name '=' exp  */
#line 131 "parser.y"
                            { (yyval.a).type="="; (yyval.a).left_child = &(yyvsp[-2].a); (yyval.a).right_child = &(yyvsp[0].a);
                              (yyvsp[-2].a).parent = &(yyval.a); (yyvsp[0].a).parent = &(yyval.a); }
#line 1467 "parser.tab.c"
    break;

  case 40: /* exp: STRING  */
#line 133 "parser.y"
                            { (yyval.a).type = "String"; (yyval.a).value = (yyvsp[0].str); printf("%s\n",(yyval.a).value); }
#line 1473 "parser.tab.c"
    break;

  case 41: /* exp: name  */
#line 134 "parser.y"
                            {(yyval.a).type=(yyvsp[0].a).type; (yyval.a).value = "extern value"; (yyval.a).name=(yyvsp[0].a).name;(yyval.a).left_child = &(yyvsp[0].a);(yyvsp[0].a).parent = &(yyval.a);}
#line 1479 "parser.tab.c"
    break;

  case 42: /* explist: exp  */
#line 137 "parser.y"
             {(yyval.a).type="arg";(yyval.a).args->line=&(yyvsp[0].a); }
#line 1485 "parser.tab.c"
    break;

  case 43: /* explist: explist ',' exp  */
#line 138 "parser.y"
                    {(yyvsp[-2].a).type="arg";(yyval.a).type="args";(yyval.a).args->next = (yyvsp[-2].a).args;(yyval.a).args->line=&(yyvsp[0].a);    }
#line 1491 "parser.tab.c"
    break;


#line 1495 "parser.tab.c"

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
  YY_SYMBOL_PRINT ("-> $$ =", YY_CAST (yysymbol_kind_t, yyr1[yyn]), &yyval, &yyloc);

  YYPOPSTACK (yylen);
  yylen = 0;

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
  yytoken = yychar == YYEMPTY ? YYSYMBOL_YYEMPTY : YYTRANSLATE (yychar);
  /* If not already recovering from an error, report this error.  */
  if (!yyerrstatus)
    {
      ++yynerrs;
      yyerror (YY_("syntax error"));
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
  ++yynerrs;

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

  /* Pop stack until we find a state that shifts the error token.  */
  for (;;)
    {
      yyn = yypact[yystate];
      if (!yypact_value_is_default (yyn))
        {
          yyn += YYSYMBOL_YYerror;
          if (0 <= yyn && yyn <= YYLAST && yycheck[yyn] == YYSYMBOL_YYerror)
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
                  YY_ACCESSING_SYMBOL (yystate), yyvsp);
      YYPOPSTACK (1);
      yystate = *yyssp;
      YY_STACK_PRINT (yyss, yyssp);
    }

  YY_IGNORE_MAYBE_UNINITIALIZED_BEGIN
  *++yyvsp = yylval;
  YY_IGNORE_MAYBE_UNINITIALIZED_END


  /* Shift the error token.  */
  YY_SYMBOL_PRINT ("Shifting", YY_ACCESSING_SYMBOL (yyn), yyvsp, yylsp);

  yystate = yyn;
  goto yynewstate;


/*-------------------------------------.
| yyacceptlab -- YYACCEPT comes here.  |
`-------------------------------------*/
yyacceptlab:
  yyresult = 0;
  goto yyreturnlab;


/*-----------------------------------.
| yyabortlab -- YYABORT comes here.  |
`-----------------------------------*/
yyabortlab:
  yyresult = 1;
  goto yyreturnlab;


/*-----------------------------------------------------------.
| yyexhaustedlab -- YYNOMEM (memory exhaustion) comes here.  |
`-----------------------------------------------------------*/
yyexhaustedlab:
  yyerror (YY_("memory exhausted"));
  yyresult = 2;
  goto yyreturnlab;


/*----------------------------------------------------------.
| yyreturnlab -- parsing is finished, clean up and return.  |
`----------------------------------------------------------*/
yyreturnlab:
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
                  YY_ACCESSING_SYMBOL (+*yyssp), yyvsp);
      YYPOPSTACK (1);
    }
#ifndef yyoverflow
  if (yyss != yyssa)
    YYSTACK_FREE (yyss);
#endif

  return yyresult;
}

#line 147 "parser.y"


int main()
{
    
    yyparse();
    
    
}
void yyerror(char *s)
{
fprintf(stderr, "error: %s\n", s);
}
