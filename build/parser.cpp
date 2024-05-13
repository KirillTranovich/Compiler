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
#line 21 "C:/Users/packard/Desktop/test_coml/Compiler/parser.y"

//тут валяется структура аст дерева
#include "main.h"

//функция возвращает ссылку на озданный узел


//без вот этой штуки ничего не работает не спрашивай что она делает
extern int yylex(void);
extern int yycolumn;
//без этой тоже
void yyerror(struct ast *endroot, const char *s);




#line 88 "C:/Users/packard/Desktop/test_coml/Compiler/build/parser.cpp"

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

#include "parser.hpp"
/* Symbol kind.  */
enum yysymbol_kind_t
{
  YYSYMBOL_YYEMPTY = -2,
  YYSYMBOL_YYEOF = 0,                      /* "end of file"  */
  YYSYMBOL_YYerror = 1,                    /* error  */
  YYSYMBOL_YYUNDEF = 2,                    /* "invalid token"  */
  YYSYMBOL_NUMBER = 3,                     /* NUMBER  */
  YYSYMBOL_ERR = 4,                        /* ERR  */
  YYSYMBOL_NAME = 5,                       /* NAME  */
  YYSYMBOL_STRING = 6,                     /* STRING  */
  YYSYMBOL_IF = 7,                         /* IF  */
  YYSYMBOL_ELSE = 8,                       /* ELSE  */
  YYSYMBOL_WHILE = 9,                      /* WHILE  */
  YYSYMBOL_FOR = 10,                       /* FOR  */
  YYSYMBOL_DEF = 11,                       /* DEF  */
  YYSYMBOL_CLASS = 12,                     /* CLASS  */
  YYSYMBOL_NEW = 13,                       /* NEW  */
  YYSYMBOL_AND = 14,                       /* AND  */
  YYSYMBOL_OR = 15,                        /* OR  */
  YYSYMBOL_EF = 16,                        /* EF  */
  YYSYMBOL_RET = 17,                       /* RET  */
  YYSYMBOL_CMP = 18,                       /* CMP  */
  YYSYMBOL_19_ = 19,                       /* '='  */
  YYSYMBOL_20_ = 20,                       /* '+'  */
  YYSYMBOL_21_ = 21,                       /* '-'  */
  YYSYMBOL_22_ = 22,                       /* '*'  */
  YYSYMBOL_23_ = 23,                       /* '/'  */
  YYSYMBOL_24_ = 24,                       /* '|'  */
  YYSYMBOL_UMINUS = 25,                    /* UMINUS  */
  YYSYMBOL_26_ = 26,                       /* ';'  */
  YYSYMBOL_27_ = 27,                       /* '.'  */
  YYSYMBOL_28_ = 28,                       /* '['  */
  YYSYMBOL_29_ = 29,                       /* ']'  */
  YYSYMBOL_30_ = 30,                       /* '('  */
  YYSYMBOL_31_ = 31,                       /* ')'  */
  YYSYMBOL_32_ = 32,                       /* ':'  */
  YYSYMBOL_33_ = 33,                       /* '{'  */
  YYSYMBOL_34_ = 34,                       /* '}'  */
  YYSYMBOL_35_ = 35,                       /* ','  */
  YYSYMBOL_YYACCEPT = 36,                  /* $accept  */
  YYSYMBOL_command = 37,                   /* command  */
  YYSYMBOL_name = 38,                      /* name  */
  YYSYMBOL_return = 39,                    /* return  */
  YYSYMBOL_new_class = 40,                 /* new_class  */
  YYSYMBOL_cr_class = 41,                  /* cr_class  */
  YYSYMBOL_cr_func = 42,                   /* cr_func  */
  YYSYMBOL_condition = 43,                 /* condition  */
  YYSYMBOL_cycle = 44,                     /* cycle  */
  YYSYMBOL_level = 45,                     /* level  */
  YYSYMBOL_exp = 46,                       /* exp  */
  YYSYMBOL_explist = 47                    /* explist  */
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
         || (defined YYLTYPE_IS_TRIVIAL && YYLTYPE_IS_TRIVIAL \
             && defined YYSTYPE_IS_TRIVIAL && YYSTYPE_IS_TRIVIAL)))

/* A type that is properly aligned for any stack member.  */
union yyalloc
{
  yy_state_t yyss_alloc;
  YYSTYPE yyvs_alloc;
  YYLTYPE yyls_alloc;
};

/* The size of the maximum gap between one aligned stack and the next.  */
# define YYSTACK_GAP_MAXIMUM (YYSIZEOF (union yyalloc) - 1)

/* The size of an array large to enough to hold all stacks, each with
   N elements.  */
# define YYSTACK_BYTES(N) \
     ((N) * (YYSIZEOF (yy_state_t) + YYSIZEOF (YYSTYPE) \
             + YYSIZEOF (YYLTYPE)) \
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
#define YYLAST   292

/* YYNTOKENS -- Number of terminals.  */
#define YYNTOKENS  36
/* YYNNTS -- Number of nonterminals.  */
#define YYNNTS  12
/* YYNRULES -- Number of rules.  */
#define YYNRULES  47
/* YYNSTATES -- Number of states.  */
#define YYNSTATES  111

/* YYMAXUTOK -- Last valid token kind.  */
#define YYMAXUTOK   274


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
      30,    31,    22,    20,    35,    21,    27,    23,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,    32,    26,
       2,    19,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,    28,     2,    29,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,    33,    24,    34,     2,     2,     2,     2,
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
      15,    16,    17,    18,    25
};

#if YYDEBUG
/* YYRLINE[YYN] -- Source line where rule number YYN was defined.  */
static const yytype_int16 yyrline[] =
{
       0,    90,    90,   104,   107,   110,   113,   116,   119,   122,
     125,   128,   131,   138,   141,   146,   149,   152,   157,   160,
     163,   168,   171,   176,   179,   184,   188,   194,   198,   202,
     208,   214,   218,   222,   226,   229,   233,   237,   241,   245,
     249,   253,   257,   261,   265,   269,   274,   278
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
  "\"end of file\"", "error", "\"invalid token\"", "NUMBER", "ERR",
  "NAME", "STRING", "IF", "ELSE", "WHILE", "FOR", "DEF", "CLASS", "NEW",
  "AND", "OR", "EF", "RET", "CMP", "'='", "'+'", "'-'", "'*'", "'/'",
  "'|'", "UMINUS", "';'", "'.'", "'['", "']'", "'('", "')'", "':'", "'{'",
  "'}'", "','", "$accept", "command", "name", "return", "new_class",
  "cr_class", "cr_func", "condition", "cycle", "level", "exp", "explist", YY_NULLPTR
};

static const char *
yysymbol_name (yysymbol_kind_t yysymbol)
{
  return yytname[yysymbol];
}
#endif

#define YYPACT_NINF (-30)

#define yypact_value_is_default(Yyn) \
  ((Yyn) == YYPACT_NINF)

#define YYTABLE_NINF (-1)

#define yytable_value_is_error(Yyn) \
  ((Yyn) == YYTABLE_NINF)

/* YYPACT[STATE-NUM] -- Index in YYTABLE of the portion describing
   STATE-NUM.  */
static const yytype_int16 yypact[] =
{
     -30,   100,   -30,   -30,   -23,   -30,   -22,   -16,   -20,    16,
      15,    15,   -30,   122,   122,   -30,   122,   -30,    40,    21,
      38,    49,    54,   -30,   -30,   -30,   219,    66,     6,   122,
     -30,   122,   122,     4,    36,    35,    96,   249,   -30,   159,
     129,   -30,   148,    85,   -30,   -30,   -30,   -30,   122,   122,
     122,   122,   122,   122,   122,   -30,   -30,   249,   -10,   -30,
     -29,   171,   183,   139,   229,    18,    61,   -30,   122,   -30,
     -30,    15,   269,   -30,   265,   265,   259,     7,     7,   -30,
     -30,   -30,   122,   -30,   -16,   -16,   122,   122,   -16,    -9,
     -16,    52,   249,   -30,   -30,   195,   239,   -30,   -16,   -30,
      55,   -16,   122,   -30,   -30,    62,   -30,   207,   -30,   -16,
     -30
};

/* YYDEFACT[STATE-NUM] -- Default reduction number in state STATE-NUM.
   Performed when YYTABLE does not specify something else to do.  Zero
   means the default is an error.  */
static const yytype_int8 yydefact[] =
{
       2,     0,     1,    40,    13,    42,     0,     0,     0,     0,
       0,     0,    12,     0,     0,     3,     0,     2,    43,     0,
       0,     0,     0,    11,    10,     9,     0,     0,     0,     0,
      26,     0,     0,    13,     0,     0,    43,    18,    39,     0,
       0,    14,     0,     0,     8,     4,     5,     6,     0,     0,
       0,     0,     0,     0,     0,     7,    17,    46,     0,    44,
       0,     0,     0,    43,     0,     0,     0,    21,     0,    38,
      30,     0,    41,    15,    32,    33,    31,    34,    35,    36,
      37,    16,     0,    45,     0,     0,     0,     0,     0,     0,
       0,     0,    47,    25,    29,     0,     0,    24,     0,    22,
       0,     0,     0,    23,    20,     0,    28,     0,    19,     0,
      27
};

/* YYPGOTO[NTERM-NUM].  */
static const yytype_int8 yypgoto[] =
{
     -30,    81,     3,   -30,   -30,   -30,   -30,   -30,   -30,    -7,
       2,   -27
};

/* YYDEFGOTO[NTERM-NUM].  */
static const yytype_int8 yydefgoto[] =
{
       0,     1,    36,    19,    20,    21,    22,    23,    24,    25,
      57,    58
};

/* YYTABLE[YYPACT[STATE-NUM]] -- What to do in state STATE-NUM.  If
   positive, shift that token.  If negative, reduce the rule whose
   number is the opposite.  If YYTABLE_NINF, syntax error.  */
static const yytype_int8 yytable[] =
{
      30,    60,    83,    26,    18,    27,    82,    28,    29,     3,
      31,     4,     5,    34,    35,    37,    38,    17,    39,    81,
      33,     3,    98,     4,     5,    82,    82,    14,    67,    53,
      54,    61,    27,    62,    64,    63,    16,    59,    89,    14,
      41,    41,    26,    18,    72,    41,    32,    44,    16,    88,
      74,    75,    76,    77,    78,    79,    80,    41,     3,    42,
       4,     5,    43,    43,    45,    66,    65,    43,    17,     3,
      72,     4,     5,   105,    91,    46,    14,    93,    94,    43,
      47,    97,   100,    99,    92,    16,   104,    14,    95,    96,
      73,   103,    90,   108,   106,    56,    16,    82,    40,     0,
       2,    41,   110,     3,   107,     4,     5,     6,     7,     8,
       9,    10,    11,     0,     0,    68,    12,    13,     0,     0,
       0,    14,     0,    43,     0,     3,    15,     4,     5,     0,
      16,     0,     3,    17,     4,     5,     6,     7,     8,     9,
      10,    11,     0,    14,    41,    12,    13,     0,     0,     0,
      14,     3,    16,     4,     5,    15,     0,     0,    68,    16,
       0,    71,    17,    70,     0,     0,    43,     0,     0,    14,
       0,    86,     0,    48,    49,     0,     0,    50,    16,    51,
      52,    53,    54,     0,     0,    48,    49,     0,     0,    50,
      69,    51,    52,    53,    54,     0,     0,    48,    49,     0,
       0,    50,    84,    51,    52,    53,    54,     0,     0,    48,
      49,     0,     0,    50,    85,    51,    52,    53,    54,     0,
       0,    48,    49,     0,     0,    50,   101,    51,    52,    53,
      54,     0,     0,    48,    49,     0,     0,    50,   109,    51,
      52,    53,    54,    48,    49,    55,     0,    50,     0,    51,
      52,    53,    54,    48,    49,    87,     0,    50,     0,    51,
      52,    53,    54,    48,    49,   102,     0,    50,     0,    51,
      52,    53,    54,    48,    49,     0,     0,    -1,     0,    51,
      52,    53,    54,    48,    49,    51,    52,    53,    54,    51,
      52,    53,    54
};

static const yytype_int8 yycheck[] =
{
       7,    28,    31,     1,     1,    28,    35,    30,    30,     3,
      30,     5,     6,    10,    11,    13,    14,    33,    16,    29,
       5,     3,    31,     5,     6,    35,    35,    21,    35,    22,
      23,    29,    28,    31,    32,    32,    30,    31,    65,    21,
       5,     5,    40,    40,    42,     5,    30,    26,    30,    31,
      48,    49,    50,    51,    52,    53,    54,     5,     3,    19,
       5,     6,    27,    27,    26,    30,    30,    27,    33,     3,
      68,     5,     6,   100,    71,    26,    21,    84,    85,    27,
      26,    88,    30,    90,    82,    30,    31,    21,    86,    87,
       5,    98,    31,    31,   101,    29,    30,    35,    17,    -1,
       0,     5,   109,     3,   102,     5,     6,     7,     8,     9,
      10,    11,    12,    -1,    -1,    19,    16,    17,    -1,    -1,
      -1,    21,    -1,    27,    -1,     3,    26,     5,     6,    -1,
      30,    -1,     3,    33,     5,     6,     7,     8,     9,    10,
      11,    12,    -1,    21,     5,    16,    17,    -1,    -1,    -1,
      21,     3,    30,     5,     6,    26,    -1,    -1,    19,    30,
      -1,    13,    33,    34,    -1,    -1,    27,    -1,    -1,    21,
      -1,    32,    -1,    14,    15,    -1,    -1,    18,    30,    20,
      21,    22,    23,    -1,    -1,    14,    15,    -1,    -1,    18,
      31,    20,    21,    22,    23,    -1,    -1,    14,    15,    -1,
      -1,    18,    31,    20,    21,    22,    23,    -1,    -1,    14,
      15,    -1,    -1,    18,    31,    20,    21,    22,    23,    -1,
      -1,    14,    15,    -1,    -1,    18,    31,    20,    21,    22,
      23,    -1,    -1,    14,    15,    -1,    -1,    18,    31,    20,
      21,    22,    23,    14,    15,    26,    -1,    18,    -1,    20,
      21,    22,    23,    14,    15,    26,    -1,    18,    -1,    20,
      21,    22,    23,    14,    15,    26,    -1,    18,    -1,    20,
      21,    22,    23,    14,    15,    -1,    -1,    18,    -1,    20,
      21,    22,    23,    14,    15,    20,    21,    22,    23,    20,
      21,    22,    23
};

/* YYSTOS[STATE-NUM] -- The symbol kind of the accessing symbol of
   state STATE-NUM.  */
static const yytype_int8 yystos[] =
{
       0,    37,     0,     3,     5,     6,     7,     8,     9,    10,
      11,    12,    16,    17,    21,    26,    30,    33,    38,    39,
      40,    41,    42,    43,    44,    45,    46,    28,    30,    30,
      45,    30,    30,     5,    38,    38,    38,    46,    46,    46,
      37,     5,    19,    27,    26,    26,    26,    26,    14,    15,
      18,    20,    21,    22,    23,    26,    29,    46,    47,    31,
      47,    46,    46,    38,    46,    30,    30,    45,    19,    31,
      34,    13,    46,     5,    46,    46,    46,    46,    46,    46,
      46,    29,    35,    31,    31,    31,    32,    26,    31,    47,
      31,    38,    46,    45,    45,    46,    46,    45,    31,    45,
      30,    31,    26,    45,    31,    47,    45,    46,    31,    31,
      45
};

/* YYR1[RULE-NUM] -- Symbol kind of the left-hand side of rule RULE-NUM.  */
static const yytype_int8 yyr1[] =
{
       0,    36,    37,    37,    37,    37,    37,    37,    37,    37,
      37,    37,    37,    38,    38,    38,    38,    38,    39,    40,
      40,    41,    41,    42,    42,    43,    43,    44,    44,    44,
      45,    46,    46,    46,    46,    46,    46,    46,    46,    46,
      46,    46,    46,    46,    46,    46,    47,    47
};

/* YYR2[RULE-NUM] -- Number of symbols on the right-hand side of rule RULE-NUM.  */
static const yytype_int8 yyr2[] =
{
       0,     2,     0,     2,     3,     3,     3,     3,     3,     2,
       2,     2,     2,     1,     2,     3,     4,     3,     2,     7,
       6,     3,     5,     6,     5,     5,     2,     9,     7,     5,
       3,     3,     3,     3,     3,     3,     3,     3,     3,     2,
       1,     3,     1,     1,     3,     4,     1,     3
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
        yyerror (endroot, YY_("syntax error: cannot back up")); \
        YYERROR;                                                  \
      }                                                           \
  while (0)

/* Backward compatibility with an undocumented macro.
   Use YYerror or YYUNDEF. */
#define YYERRCODE YYUNDEF

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


/* YYLOCATION_PRINT -- Print the location on the stream.
   This macro was not mandated originally: define only if we know
   we won't break user code: when these are the locations we know.  */

# ifndef YYLOCATION_PRINT

#  if defined YY_LOCATION_PRINT

   /* Temporary convenience wrapper in case some people defined the
      undocumented and private YY_LOCATION_PRINT macros.  */
#   define YYLOCATION_PRINT(File, Loc)  YY_LOCATION_PRINT(File, *(Loc))

#  elif defined YYLTYPE_IS_TRIVIAL && YYLTYPE_IS_TRIVIAL

/* Print *YYLOCP on YYO.  Private, do not rely on its existence. */

YY_ATTRIBUTE_UNUSED
static int
yy_location_print_ (FILE *yyo, YYLTYPE const * const yylocp)
{
  int res = 0;
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

#   define YYLOCATION_PRINT  yy_location_print_

    /* Temporary convenience wrapper in case some people defined the
       undocumented and private YY_LOCATION_PRINT macros.  */
#   define YY_LOCATION_PRINT(File, Loc)  YYLOCATION_PRINT(File, &(Loc))

#  else

#   define YYLOCATION_PRINT(File, Loc) ((void) 0)
    /* Temporary convenience wrapper in case some people defined the
       undocumented and private YY_LOCATION_PRINT macros.  */
#   define YY_LOCATION_PRINT  YYLOCATION_PRINT

#  endif
# endif /* !defined YYLOCATION_PRINT */


# define YY_SYMBOL_PRINT(Title, Kind, Value, Location)                    \
do {                                                                      \
  if (yydebug)                                                            \
    {                                                                     \
      YYFPRINTF (stderr, "%s ", Title);                                   \
      yy_symbol_print (stderr,                                            \
                  Kind, Value, Location, endroot); \
      YYFPRINTF (stderr, "\n");                                           \
    }                                                                     \
} while (0)


/*-----------------------------------.
| Print this symbol's value on YYO.  |
`-----------------------------------*/

static void
yy_symbol_value_print (FILE *yyo,
                       yysymbol_kind_t yykind, YYSTYPE const * const yyvaluep, YYLTYPE const * const yylocationp, struct ast *endroot)
{
  FILE *yyoutput = yyo;
  YY_USE (yyoutput);
  YY_USE (yylocationp);
  YY_USE (endroot);
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
                 yysymbol_kind_t yykind, YYSTYPE const * const yyvaluep, YYLTYPE const * const yylocationp, struct ast *endroot)
{
  YYFPRINTF (yyo, "%s %s (",
             yykind < YYNTOKENS ? "token" : "nterm", yysymbol_name (yykind));

  YYLOCATION_PRINT (yyo, yylocationp);
  YYFPRINTF (yyo, ": ");
  yy_symbol_value_print (yyo, yykind, yyvaluep, yylocationp, endroot);
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
yy_reduce_print (yy_state_t *yyssp, YYSTYPE *yyvsp, YYLTYPE *yylsp,
                 int yyrule, struct ast *endroot)
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
                       &yyvsp[(yyi + 1) - (yynrhs)],
                       &(yylsp[(yyi + 1) - (yynrhs)]), endroot);
      YYFPRINTF (stderr, "\n");
    }
}

# define YY_REDUCE_PRINT(Rule)          \
do {                                    \
  if (yydebug)                          \
    yy_reduce_print (yyssp, yyvsp, yylsp, Rule, endroot); \
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
            yysymbol_kind_t yykind, YYSTYPE *yyvaluep, YYLTYPE *yylocationp, struct ast *endroot)
{
  YY_USE (yyvaluep);
  YY_USE (yylocationp);
  YY_USE (endroot);
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
yyparse (struct ast *endroot)
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

    /* The location stack: array, bottom, top.  */
    YYLTYPE yylsa[YYINITDEPTH];
    YYLTYPE *yyls = yylsa;
    YYLTYPE *yylsp = yyls;

  int yyn;
  /* The return value of yyparse.  */
  int yyresult;
  /* Lookahead symbol kind.  */
  yysymbol_kind_t yytoken = YYSYMBOL_YYEMPTY;
  /* The variables used to return semantic value and location from the
     action routines.  */
  YYSTYPE yyval;
  YYLTYPE yyloc;

  /* The locations where the error started and ended.  */
  YYLTYPE yyerror_range[3];



#define YYPOPSTACK(N)   (yyvsp -= (N), yyssp -= (N), yylsp -= (N))

  /* The number of symbols on the RHS of the reduced rule.
     Keep to zero when no symbol should be popped.  */
  int yylen = 0;

  YYDPRINTF ((stderr, "Starting parse\n"));

  yychar = YYEMPTY; /* Cause a token to be read.  */

  yylsp[0] = yylloc;
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
        YYLTYPE *yyls1 = yyls;

        /* Each stack pointer address is followed by the size of the
           data in use in that stack, in bytes.  This used to be a
           conditional around just the two extra args, but that might
           be undefined if yyoverflow is a macro.  */
        yyoverflow (YY_("memory exhausted"),
                    &yyss1, yysize * YYSIZEOF (*yyssp),
                    &yyvs1, yysize * YYSIZEOF (*yyvsp),
                    &yyls1, yysize * YYSIZEOF (*yylsp),
                    &yystacksize);
        yyss = yyss1;
        yyvs = yyvs1;
        yyls = yyls1;
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
        YYSTACK_RELOCATE (yyls_alloc, yyls);
#  undef YYSTACK_RELOCATE
        if (yyss1 != yyssa)
          YYSTACK_FREE (yyss1);
      }
# endif

      yyssp = yyss + yysize - 1;
      yyvsp = yyvs + yysize - 1;
      yylsp = yyls + yysize - 1;

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
      yyerror_range[1] = yylloc;
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
  *++yylsp = yylloc;

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

  /* Default location. */
  YYLLOC_DEFAULT (yyloc, (yylsp - yylen), yylen);
  yyerror_range[1] = yyloc;
  YY_REDUCE_PRINT (yyn);
  switch (yyn)
    {
  case 2: /* command: %empty  */
#line 90 "C:/Users/packard/Desktop/test_coml/Compiler/parser.y"
                {
        
    (yyval.a)=ast::newast({.first_column = (yylloc).first_column,.last_column =(yylloc).last_column, .type = StartLvl,});

    if((yylloc).first_column == 1){endroot->next = (yyval.a);
                            endroot->type = Error;
                            (yyval.a)->type = Root;
                            (yyval.a)->prev = endroot;
                            }

                  

}
#line 1349 "C:/Users/packard/Desktop/test_coml/Compiler/build/parser.cpp"
    break;

  case 3: /* command: command ';'  */
#line 104 "C:/Users/packard/Desktop/test_coml/Compiler/parser.y"
                        {
    (yyval.a)=ast::newast({.first_column = (yylsp[0]).first_column,.last_column = (yylsp[0]).last_column, .type = EmptyLine,.prev=(yyvsp[-1].a)});
}
#line 1357 "C:/Users/packard/Desktop/test_coml/Compiler/build/parser.cpp"
    break;

  case 4: /* command: command new_class ';'  */
#line 107 "C:/Users/packard/Desktop/test_coml/Compiler/parser.y"
                        {
    (yyval.a)=ast::newast({.first_column = (yylsp[-1]).first_column,.last_column = (yylsp[-1]).last_column,.type = Command, .left_child = (yyvsp[-1].a),.prev=(yyvsp[-2].a)});
}
#line 1365 "C:/Users/packard/Desktop/test_coml/Compiler/build/parser.cpp"
    break;

  case 5: /* command: command cr_class ';'  */
#line 110 "C:/Users/packard/Desktop/test_coml/Compiler/parser.y"
                        {
    (yyval.a)=ast::newast({.first_column = (yylsp[-1]).first_column,.last_column = (yylsp[-1]).last_column, .type = Command,.left_child = (yyvsp[-1].a),.prev=(yyvsp[-2].a)});
}
#line 1373 "C:/Users/packard/Desktop/test_coml/Compiler/build/parser.cpp"
    break;

  case 6: /* command: command cr_func ';'  */
#line 113 "C:/Users/packard/Desktop/test_coml/Compiler/parser.y"
                        {
    (yyval.a)=ast::newast({.first_column = (yylsp[-1]).first_column,.last_column = (yylsp[-1]).last_column, .type = Command,.left_child = (yyvsp[-1].a),.prev=(yyvsp[-2].a)});
}
#line 1381 "C:/Users/packard/Desktop/test_coml/Compiler/build/parser.cpp"
    break;

  case 7: /* command: command exp ';'  */
#line 116 "C:/Users/packard/Desktop/test_coml/Compiler/parser.y"
                        {
    (yyval.a)=ast::newast({.first_column = (yylsp[-1]).first_column,.last_column = (yylsp[-1]).last_column, .type = Command,.left_child = (yyvsp[-1].a),.prev=(yyvsp[-2].a)});
}
#line 1389 "C:/Users/packard/Desktop/test_coml/Compiler/build/parser.cpp"
    break;

  case 8: /* command: command return ';'  */
#line 119 "C:/Users/packard/Desktop/test_coml/Compiler/parser.y"
                           {
    (yyval.a)=ast::newast({.first_column = (yylsp[-1]).first_column,.last_column = (yylsp[-1]).last_column, .type = Command,.left_child = (yyvsp[-1].a),.prev=(yyvsp[-2].a)});
}
#line 1397 "C:/Users/packard/Desktop/test_coml/Compiler/build/parser.cpp"
    break;

  case 9: /* command: command level  */
#line 122 "C:/Users/packard/Desktop/test_coml/Compiler/parser.y"
                {
    (yyval.a)=ast::newast({.first_column = (yylsp[0]).first_column,.last_column = (yylsp[0]).last_column, .type = Command,.left_child = (yyvsp[0].a),.prev=(yyvsp[-1].a)});
}
#line 1405 "C:/Users/packard/Desktop/test_coml/Compiler/build/parser.cpp"
    break;

  case 10: /* command: command cycle  */
#line 125 "C:/Users/packard/Desktop/test_coml/Compiler/parser.y"
                { 
    (yyval.a)=ast::newast({.first_column = (yylsp[0]).first_column,.last_column = (yylsp[0]).last_column, .type = Command,.left_child = (yyvsp[0].a),.prev=(yyvsp[-1].a)});
}
#line 1413 "C:/Users/packard/Desktop/test_coml/Compiler/build/parser.cpp"
    break;

  case 11: /* command: command condition  */
#line 128 "C:/Users/packard/Desktop/test_coml/Compiler/parser.y"
                    {
    (yyval.a)=ast::newast({.first_column = (yylsp[0]).first_column,.last_column = (yylsp[0]).last_column, .type = Command,.left_child = (yyvsp[0].a),.prev=(yyvsp[-1].a)});
}
#line 1421 "C:/Users/packard/Desktop/test_coml/Compiler/build/parser.cpp"
    break;

  case 12: /* command: command EF  */
#line 131 "C:/Users/packard/Desktop/test_coml/Compiler/parser.y"
             {    
    (yylloc).first_column =1;                       
    YYACCEPT;                         
}
#line 1430 "C:/Users/packard/Desktop/test_coml/Compiler/build/parser.cpp"
    break;

  case 13: /* name: NAME  */
#line 138 "C:/Users/packard/Desktop/test_coml/Compiler/parser.y"
            {
    (yyval.a)=ast::newast({.first_column = (yyloc).first_column,.last_column = (yyloc).last_column, .type = Name,.name=(yyvsp[0].str)});
}
#line 1438 "C:/Users/packard/Desktop/test_coml/Compiler/build/parser.cpp"
    break;

  case 14: /* name: name NAME  */
#line 141 "C:/Users/packard/Desktop/test_coml/Compiler/parser.y"
            {
    (yyval.a)=ast::newast({.first_column = (yylsp[0]).first_column,.last_column = (yylsp[0]).last_column, .type = Name,.name=(yyvsp[0].str),.left_child = (yyvsp[-1].a),});
    (yyvsp[-1].a)->type = Type;
}
#line 1447 "C:/Users/packard/Desktop/test_coml/Compiler/build/parser.cpp"
    break;

  case 15: /* name: name '.' NAME  */
#line 146 "C:/Users/packard/Desktop/test_coml/Compiler/parser.y"
                  { 
    (yyval.a)=ast::newast({.first_column = (yylsp[-1]).first_column,.last_column = (yylsp[-1]).last_column, .type = Name,.name=(yyvsp[0].str),.left_child = (yyvsp[-2].a),});
}
#line 1455 "C:/Users/packard/Desktop/test_coml/Compiler/build/parser.cpp"
    break;

  case 16: /* name: NAME '[' explist ']'  */
#line 149 "C:/Users/packard/Desktop/test_coml/Compiler/parser.y"
                          {
    (yyval.a)=ast::newast({.first_column = (yyloc).first_column,.last_column = (yyloc).last_column, .type = ArrMember,.name=(yyvsp[-3].str),.args = (yyvsp[-1].a),});
}
#line 1463 "C:/Users/packard/Desktop/test_coml/Compiler/build/parser.cpp"
    break;

  case 17: /* name: NAME '[' ']'  */
#line 152 "C:/Users/packard/Desktop/test_coml/Compiler/parser.y"
                 {
    (yyval.a)=ast::newast({.first_column = (yyloc).first_column,.last_column = (yyloc).last_column, .type = Arr,.name=(yyvsp[-2].str)});
}
#line 1471 "C:/Users/packard/Desktop/test_coml/Compiler/build/parser.cpp"
    break;

  case 18: /* return: RET exp  */
#line 157 "C:/Users/packard/Desktop/test_coml/Compiler/parser.y"
                {
    (yyval.a)=ast::newast({.first_column = (yyloc).first_column,.last_column = (yyloc).last_column, .type = Return,.left_child = (yyvsp[0].a),}); 
}
#line 1479 "C:/Users/packard/Desktop/test_coml/Compiler/build/parser.cpp"
    break;

  case 19: /* new_class: name '=' NEW name '(' explist ')'  */
#line 160 "C:/Users/packard/Desktop/test_coml/Compiler/parser.y"
                                              {
    (yyval.a)=ast::newast({.first_column = (yyloc).first_column,.last_column = (yyloc).last_column, .type = Ex_of_class,.value = (yyvsp[-3].a)->name,.name=(yyvsp[-6].a)->name,.args = (yyvsp[-1].a),});
}
#line 1487 "C:/Users/packard/Desktop/test_coml/Compiler/build/parser.cpp"
    break;

  case 20: /* new_class: name '=' NEW name '(' ')'  */
#line 163 "C:/Users/packard/Desktop/test_coml/Compiler/parser.y"
                             {
    (yyval.a)=ast::newast({.first_column = (yyloc).first_column,.last_column = (yyloc).last_column, .type = Ex_of_class,.value = (yyvsp[-2].a)->name,.name=(yyvsp[-5].a)->name,});
}
#line 1495 "C:/Users/packard/Desktop/test_coml/Compiler/build/parser.cpp"
    break;

  case 21: /* cr_class: CLASS name level  */
#line 168 "C:/Users/packard/Desktop/test_coml/Compiler/parser.y"
                             {
(yyval.a)=ast::newast({.first_column = (yyloc).first_column,.last_column = (yyloc).last_column, .type = Class,.name=(yyvsp[-1].a)->name,.in_level = (yyvsp[0].a)});
}
#line 1503 "C:/Users/packard/Desktop/test_coml/Compiler/build/parser.cpp"
    break;

  case 22: /* cr_class: CLASS name '(' ')' level  */
#line 171 "C:/Users/packard/Desktop/test_coml/Compiler/parser.y"
                                        {
(yyval.a)=ast::newast({.first_column = (yyloc).first_column,.last_column = (yyloc).last_column, .type = Class,.name=(yyvsp[-3].a)->name,.in_level = (yyvsp[0].a)});
}
#line 1511 "C:/Users/packard/Desktop/test_coml/Compiler/build/parser.cpp"
    break;

  case 23: /* cr_func: DEF name '(' explist ')' level  */
#line 176 "C:/Users/packard/Desktop/test_coml/Compiler/parser.y"
                                            {
(yyval.a)=ast::newast({.first_column = (yyloc).first_column,.last_column = (yyloc).last_column, .type = Funk,.name=(yyvsp[-4].a)->name,.in_level = (yyvsp[0].a),.args = (yyvsp[-2].a),});
}
#line 1519 "C:/Users/packard/Desktop/test_coml/Compiler/build/parser.cpp"
    break;

  case 24: /* cr_func: DEF name '(' ')' level  */
#line 179 "C:/Users/packard/Desktop/test_coml/Compiler/parser.y"
                                   {
(yyval.a)=ast::newast({.first_column = (yyloc).first_column,.last_column = (yyloc).last_column, .type = Funk,.name=(yyvsp[-3].a)->name,.in_level = (yyvsp[0].a)});
}
#line 1527 "C:/Users/packard/Desktop/test_coml/Compiler/build/parser.cpp"
    break;

  case 25: /* condition: IF '(' exp ')' level  */
#line 184 "C:/Users/packard/Desktop/test_coml/Compiler/parser.y"
                                          {
                                           
    (yyval.a)=ast::newast({.first_column = (yyloc).first_column,.last_column = (yyloc).last_column, .type = ConditionIF,.in_level = (yyvsp[0].a),.cond=(yyvsp[-2].a),});
}
#line 1536 "C:/Users/packard/Desktop/test_coml/Compiler/build/parser.cpp"
    break;

  case 26: /* condition: ELSE level  */
#line 188 "C:/Users/packard/Desktop/test_coml/Compiler/parser.y"
                                               {
                                            
    (yyval.a)=ast::newast({.first_column = (yyloc).first_column,.last_column = (yyloc).last_column, .type = ConditionELSE,.in_level = (yyvsp[0].a)});
}
#line 1545 "C:/Users/packard/Desktop/test_coml/Compiler/build/parser.cpp"
    break;

  case 27: /* cycle: FOR '(' exp ';' exp ';' exp ')' level  */
#line 194 "C:/Users/packard/Desktop/test_coml/Compiler/parser.y"
                                                      { 
                                                      
    (yyval.a)=ast::newast({.first_column = (yyloc).first_column,.last_column = (yyloc).last_column, .type = For,.in_level = (yyvsp[0].a),.init = (yyvsp[-6].a),.cond=(yyvsp[-4].a),.change = (yyvsp[-2].a)});
}
#line 1554 "C:/Users/packard/Desktop/test_coml/Compiler/build/parser.cpp"
    break;

  case 28: /* cycle: FOR '(' name ':' exp ')' level  */
#line 198 "C:/Users/packard/Desktop/test_coml/Compiler/parser.y"
                                                      {
                                                       
    (yyval.a)=ast::newast({.first_column = (yyloc).first_column,.last_column = (yyloc).last_column, .type = For,.in_level = (yyvsp[0].a),.init = (yyvsp[-4].a),.cond=(yyvsp[-2].a),});
}
#line 1563 "C:/Users/packard/Desktop/test_coml/Compiler/build/parser.cpp"
    break;

  case 29: /* cycle: WHILE '(' exp ')' level  */
#line 202 "C:/Users/packard/Desktop/test_coml/Compiler/parser.y"
                                                      {
                                                        
    (yyval.a)=ast::newast({.first_column = (yyloc).first_column,.last_column = (yyloc).last_column, .type = While,.in_level = (yyvsp[0].a),.cond=(yyvsp[-2].a),});
}
#line 1572 "C:/Users/packard/Desktop/test_coml/Compiler/build/parser.cpp"
    break;

  case 30: /* level: '{' command '}'  */
#line 208 "C:/Users/packard/Desktop/test_coml/Compiler/parser.y"
                      {
 
    (yyval.a)=ast::newast({.first_column = (yyloc).first_column,.last_column = (yyloc).last_column, .type = Lvl,.left_child = (yyvsp[-1].a),});
}
#line 1581 "C:/Users/packard/Desktop/test_coml/Compiler/build/parser.cpp"
    break;

  case 31: /* exp: exp CMP exp  */
#line 214 "C:/Users/packard/Desktop/test_coml/Compiler/parser.y"
                            {
  
    (yyval.a)=ast::newast({.first_column = (yyloc).first_column,.last_column = (yyloc).last_column, .type = Cmp,.left_child = (yyvsp[-2].a),.right_child = (yyvsp[0].a)});
}
#line 1590 "C:/Users/packard/Desktop/test_coml/Compiler/build/parser.cpp"
    break;

  case 32: /* exp: exp AND exp  */
#line 218 "C:/Users/packard/Desktop/test_coml/Compiler/parser.y"
                            {
    
    (yyval.a)=ast::newast({.first_column = (yyloc).first_column,.last_column = (yyloc).last_column, .type = And,.left_child = (yyvsp[-2].a),.right_child = (yyvsp[0].a)});
}
#line 1599 "C:/Users/packard/Desktop/test_coml/Compiler/build/parser.cpp"
    break;

  case 33: /* exp: exp OR exp  */
#line 222 "C:/Users/packard/Desktop/test_coml/Compiler/parser.y"
                            {
    
    (yyval.a)=ast::newast({.first_column = (yyloc).first_column,.last_column = (yyloc).last_column, .type = Or,.left_child = (yyvsp[-2].a),.right_child = (yyvsp[0].a)});
}
#line 1608 "C:/Users/packard/Desktop/test_coml/Compiler/build/parser.cpp"
    break;

  case 34: /* exp: exp '+' exp  */
#line 226 "C:/Users/packard/Desktop/test_coml/Compiler/parser.y"
                            {
    (yyval.a)=ast::newast({.first_column = (yyloc).first_column,.last_column = (yyloc).last_column, .type = Add,.left_child = (yyvsp[-2].a),.right_child = (yyvsp[0].a)});
}
#line 1616 "C:/Users/packard/Desktop/test_coml/Compiler/build/parser.cpp"
    break;

  case 35: /* exp: exp '-' exp  */
#line 229 "C:/Users/packard/Desktop/test_coml/Compiler/parser.y"
                            {
    
    (yyval.a)=ast::newast({.first_column = (yyloc).first_column,.last_column = (yyloc).last_column, .type = Sub,.left_child = (yyvsp[-2].a),.right_child = (yyvsp[0].a)});
}
#line 1625 "C:/Users/packard/Desktop/test_coml/Compiler/build/parser.cpp"
    break;

  case 36: /* exp: exp '*' exp  */
#line 233 "C:/Users/packard/Desktop/test_coml/Compiler/parser.y"
                            {
    
    (yyval.a)=ast::newast({.first_column = (yyloc).first_column,.last_column = (yyloc).last_column, .type = Mull,.left_child = (yyvsp[-2].a),.right_child = (yyvsp[0].a)});
}
#line 1634 "C:/Users/packard/Desktop/test_coml/Compiler/build/parser.cpp"
    break;

  case 37: /* exp: exp '/' exp  */
#line 237 "C:/Users/packard/Desktop/test_coml/Compiler/parser.y"
                            {
    
    (yyval.a)=ast::newast({.first_column = (yyloc).first_column,.last_column = (yyloc).last_column, .type = Div,.left_child = (yyvsp[-2].a),.right_child = (yyvsp[0].a)});
}
#line 1643 "C:/Users/packard/Desktop/test_coml/Compiler/build/parser.cpp"
    break;

  case 38: /* exp: '(' exp ')'  */
#line 241 "C:/Users/packard/Desktop/test_coml/Compiler/parser.y"
                            { 
    
    (yyval.a) = (yyvsp[-1].a);
}
#line 1652 "C:/Users/packard/Desktop/test_coml/Compiler/build/parser.cpp"
    break;

  case 39: /* exp: '-' exp  */
#line 245 "C:/Users/packard/Desktop/test_coml/Compiler/parser.y"
                            {
    
    (yyval.a)=ast::newast({.first_column = (yyloc).first_column,.last_column = (yyloc).last_column, .type =Unminus,.left_child = (yyvsp[0].a),});
}
#line 1661 "C:/Users/packard/Desktop/test_coml/Compiler/build/parser.cpp"
    break;

  case 40: /* exp: NUMBER  */
#line 249 "C:/Users/packard/Desktop/test_coml/Compiler/parser.y"
                            {
    
    (yyval.a)=ast::newast({.first_column = (yyloc).first_column,.last_column = (yyloc).last_column, .type = Digit,.value = (yyvsp[0].str)});
}
#line 1670 "C:/Users/packard/Desktop/test_coml/Compiler/build/parser.cpp"
    break;

  case 41: /* exp: name '=' exp  */
#line 253 "C:/Users/packard/Desktop/test_coml/Compiler/parser.y"
                                {
    
    (yyval.a)=ast::newast({.first_column = (yyloc).first_column,.last_column = (yyloc).last_column, .type = Eq,.left_child = (yyvsp[-2].a),.right_child = (yyvsp[0].a)});
}
#line 1679 "C:/Users/packard/Desktop/test_coml/Compiler/build/parser.cpp"
    break;

  case 42: /* exp: STRING  */
#line 257 "C:/Users/packard/Desktop/test_coml/Compiler/parser.y"
                            { 
    
    (yyval.a)=ast::newast({.first_column = (yyloc).first_column,.last_column = (yyloc).last_column, .type = String,.value = (yyvsp[0].str)});
}
#line 1688 "C:/Users/packard/Desktop/test_coml/Compiler/build/parser.cpp"
    break;

  case 43: /* exp: name  */
#line 261 "C:/Users/packard/Desktop/test_coml/Compiler/parser.y"
                            {
                              
    (yyval.a) = (yyvsp[0].a);
}
#line 1697 "C:/Users/packard/Desktop/test_coml/Compiler/build/parser.cpp"
    break;

  case 44: /* exp: NAME '(' ')'  */
#line 265 "C:/Users/packard/Desktop/test_coml/Compiler/parser.y"
             {
    (yyval.a)=ast::newast({.first_column = (yyloc).first_column,.last_column = (yyloc).last_column, .type = Name,.name = (yyvsp[-2].str)});
}
#line 1705 "C:/Users/packard/Desktop/test_coml/Compiler/build/parser.cpp"
    break;

  case 45: /* exp: NAME '(' explist ')'  */
#line 269 "C:/Users/packard/Desktop/test_coml/Compiler/parser.y"
                        {
    (yyval.a)=ast::newast({.first_column = (yyloc).first_column,.last_column = (yyloc).last_column, .type = CallfunkName,.name = (yyvsp[-3].str),.args = (yyvsp[-1].a)});
}
#line 1713 "C:/Users/packard/Desktop/test_coml/Compiler/build/parser.cpp"
    break;

  case 46: /* explist: exp  */
#line 274 "C:/Users/packard/Desktop/test_coml/Compiler/parser.y"
             {
                
    (yyval.a)=ast::newast({.first_column = (yyloc).first_column,.last_column = (yyloc).last_column, .type = Arg,.left_child=(yyvsp[0].a)});
}
#line 1722 "C:/Users/packard/Desktop/test_coml/Compiler/build/parser.cpp"
    break;

  case 47: /* explist: explist ',' exp  */
#line 278 "C:/Users/packard/Desktop/test_coml/Compiler/parser.y"
                    {
                     
    (yyval.a)=ast::newast({.first_column = (yyloc).first_column,.last_column = (yyloc).last_column, .type = Arg,.left_child =(yyvsp[0].a),.prev = (yyvsp[-2].a),});
}
#line 1731 "C:/Users/packard/Desktop/test_coml/Compiler/build/parser.cpp"
    break;


#line 1735 "C:/Users/packard/Desktop/test_coml/Compiler/build/parser.cpp"

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
  *++yylsp = yyloc;

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
      yyerror (endroot, YY_("syntax error"));
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
                      yytoken, &yylval, &yylloc, endroot);
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

      yyerror_range[1] = *yylsp;
      yydestruct ("Error: popping",
                  YY_ACCESSING_SYMBOL (yystate), yyvsp, yylsp, endroot);
      YYPOPSTACK (1);
      yystate = *yyssp;
      YY_STACK_PRINT (yyss, yyssp);
    }

  YY_IGNORE_MAYBE_UNINITIALIZED_BEGIN
  *++yyvsp = yylval;
  YY_IGNORE_MAYBE_UNINITIALIZED_END

  yyerror_range[2] = yylloc;
  ++yylsp;
  YYLLOC_DEFAULT (*yylsp, yyerror_range, 2);

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
  yyerror (endroot, YY_("memory exhausted"));
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
                  yytoken, &yylval, &yylloc, endroot);
    }
  /* Do not reclaim the symbols of the rule whose action triggered
     this YYABORT or YYACCEPT.  */
  YYPOPSTACK (yylen);
  YY_STACK_PRINT (yyss, yyssp);
  while (yyssp != yyss)
    {
      yydestruct ("Cleanup: popping",
                  YY_ACCESSING_SYMBOL (+*yyssp), yyvsp, yylsp, endroot);
      YYPOPSTACK (1);
    }
#ifndef yyoverflow
  if (yyss != yyssa)
    YYSTACK_FREE (yyss);
#endif

  return yyresult;
}

#line 286 "C:/Users/packard/Desktop/test_coml/Compiler/parser.y"

void yyerror(struct ast *endroot,const char *s)
{
        endroot->first_column=(yylloc).first_column;
        endroot->last_column=(yylloc).last_column;
        
        (yylloc).first_column=1;
        (yylloc).last_column=1;
        yycolumn = 1;
 

}