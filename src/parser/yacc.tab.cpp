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
#define YYPURE 2

/* Push parsers.  */
#define YYPUSH 0

/* Pull parsers.  */
#define YYPULL 1




/* First part of user prologue.  */
#line 1 "/mnt/d/dbcodes/rmdb-main/src/parser/yacc.y"

#include "ast.h"
#include "yacc.tab.h"
#include <cstdint>
#include <iostream>
#include <memory>

int yylex(YYSTYPE *yylval, YYLTYPE *yylloc);

void yyerror(YYLTYPE *locp, const char* s) {
    std::cerr << "Parser Error at line " << locp->first_line << " column " << locp->first_column << ": " << s << std::endl;
}

using namespace ast;

#line 87 "/mnt/d/dbcodes/rmdb-main/src/parser/yacc.tab.cpp"

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

#include "yacc.tab.h"
/* Symbol kind.  */
enum yysymbol_kind_t
{
  YYSYMBOL_YYEMPTY = -2,
  YYSYMBOL_YYEOF = 0,                      /* "end of file"  */
  YYSYMBOL_YYerror = 1,                    /* error  */
  YYSYMBOL_YYUNDEF = 2,                    /* "invalid token"  */
  YYSYMBOL_SHOW = 3,                       /* SHOW  */
  YYSYMBOL_TABLES = 4,                     /* TABLES  */
  YYSYMBOL_CREATE = 5,                     /* CREATE  */
  YYSYMBOL_TABLE = 6,                      /* TABLE  */
  YYSYMBOL_DROP = 7,                       /* DROP  */
  YYSYMBOL_DESC = 8,                       /* DESC  */
  YYSYMBOL_INSERT = 9,                     /* INSERT  */
  YYSYMBOL_INTO = 10,                      /* INTO  */
  YYSYMBOL_VALUES = 11,                    /* VALUES  */
  YYSYMBOL_DELETE = 12,                    /* DELETE  */
  YYSYMBOL_FROM = 13,                      /* FROM  */
  YYSYMBOL_ASC = 14,                       /* ASC  */
  YYSYMBOL_ORDER = 15,                     /* ORDER  */
  YYSYMBOL_BY = 16,                        /* BY  */
  YYSYMBOL_WHERE = 17,                     /* WHERE  */
  YYSYMBOL_UPDATE = 18,                    /* UPDATE  */
  YYSYMBOL_SET = 19,                       /* SET  */
  YYSYMBOL_TRANSACTION = 20,               /* TRANSACTION  */
  YYSYMBOL_ISOLATION = 21,                 /* ISOLATION  */
  YYSYMBOL_LEVEL = 22,                     /* LEVEL  */
  YYSYMBOL_SNAPSHOT = 23,                  /* SNAPSHOT  */
  YYSYMBOL_SERIALIZABLE = 24,              /* SERIALIZABLE  */
  YYSYMBOL_SELECT = 25,                    /* SELECT  */
  YYSYMBOL_INT = 26,                       /* INT  */
  YYSYMBOL_BIGINT = 27,                    /* BIGINT  */
  YYSYMBOL_CHAR = 28,                      /* CHAR  */
  YYSYMBOL_FLOAT = 29,                     /* FLOAT  */
  YYSYMBOL_INDEX = 30,                     /* INDEX  */
  YYSYMBOL_AND = 31,                       /* AND  */
  YYSYMBOL_JOIN = 32,                      /* JOIN  */
  YYSYMBOL_SEMI = 33,                      /* SEMI  */
  YYSYMBOL_ON = 34,                        /* ON  */
  YYSYMBOL_GROUP = 35,                     /* GROUP  */
  YYSYMBOL_HAVING = 36,                    /* HAVING  */
  YYSYMBOL_LIMIT = 37,                     /* LIMIT  */
  YYSYMBOL_AS = 38,                        /* AS  */
  YYSYMBOL_EXPLAIN = 39,                   /* EXPLAIN  */
  YYSYMBOL_ANALYZE = 40,                   /* ANALYZE  */
  YYSYMBOL_UNION = 41,                     /* UNION  */
  YYSYMBOL_EXIT = 42,                      /* EXIT  */
  YYSYMBOL_HELP = 43,                      /* HELP  */
  YYSYMBOL_TXN_BEGIN = 44,                 /* TXN_BEGIN  */
  YYSYMBOL_TXN_COMMIT = 45,                /* TXN_COMMIT  */
  YYSYMBOL_TXN_ABORT = 46,                 /* TXN_ABORT  */
  YYSYMBOL_TXN_ROLLBACK = 47,              /* TXN_ROLLBACK  */
  YYSYMBOL_ORDER_BY = 48,                  /* ORDER_BY  */
  YYSYMBOL_ENABLE_NESTLOOP = 49,           /* ENABLE_NESTLOOP  */
  YYSYMBOL_ENABLE_SORTMERGE = 50,          /* ENABLE_SORTMERGE  */
  YYSYMBOL_MAX = 51,                       /* MAX  */
  YYSYMBOL_MIN = 52,                       /* MIN  */
  YYSYMBOL_COUNT = 53,                     /* COUNT  */
  YYSYMBOL_SUM = 54,                       /* SUM  */
  YYSYMBOL_AVG = 55,                       /* AVG  */
  YYSYMBOL_LEQ = 56,                       /* LEQ  */
  YYSYMBOL_NEQ = 57,                       /* NEQ  */
  YYSYMBOL_GEQ = 58,                       /* GEQ  */
  YYSYMBOL_T_EOF = 59,                     /* T_EOF  */
  YYSYMBOL_IDENTIFIER = 60,                /* IDENTIFIER  */
  YYSYMBOL_VALUE_STRING = 61,              /* VALUE_STRING  */
  YYSYMBOL_VALUE_BIGINT = 62,              /* VALUE_BIGINT  */
  YYSYMBOL_VALUE_INT = 63,                 /* VALUE_INT  */
  YYSYMBOL_VALUE_FLOAT = 64,               /* VALUE_FLOAT  */
  YYSYMBOL_VALUE_BOOL = 65,                /* VALUE_BOOL  */
  YYSYMBOL_66_ = 66,                       /* ';'  */
  YYSYMBOL_67_ = 67,                       /* '='  */
  YYSYMBOL_68_ = 68,                       /* '('  */
  YYSYMBOL_69_ = 69,                       /* ')'  */
  YYSYMBOL_70_ = 70,                       /* ','  */
  YYSYMBOL_71_ = 71,                       /* '.'  */
  YYSYMBOL_72_ = 72,                       /* '<'  */
  YYSYMBOL_73_ = 73,                       /* '>'  */
  YYSYMBOL_74_ = 74,                       /* '*'  */
  YYSYMBOL_YYACCEPT = 75,                  /* $accept  */
  YYSYMBOL_start = 76,                     /* start  */
  YYSYMBOL_stmt = 77,                      /* stmt  */
  YYSYMBOL_txnStmt = 78,                   /* txnStmt  */
  YYSYMBOL_dbStmt = 79,                    /* dbStmt  */
  YYSYMBOL_setStmt = 80,                   /* setStmt  */
  YYSYMBOL_ddl = 81,                       /* ddl  */
  YYSYMBOL_dml = 82,                       /* dml  */
  YYSYMBOL_selectStmt = 83,                /* selectStmt  */
  YYSYMBOL_plainSelectStmt = 84,           /* plainSelectStmt  */
  YYSYMBOL_unionSelectList = 85,           /* unionSelectList  */
  YYSYMBOL_unionSelect = 86,               /* unionSelect  */
  YYSYMBOL_fieldList = 87,                 /* fieldList  */
  YYSYMBOL_colNameList = 88,               /* colNameList  */
  YYSYMBOL_field = 89,                     /* field  */
  YYSYMBOL_type = 90,                      /* type  */
  YYSYMBOL_valueList = 91,                 /* valueList  */
  YYSYMBOL_value = 92,                     /* value  */
  YYSYMBOL_condition = 93,                 /* condition  */
  YYSYMBOL_optWhereClause = 94,            /* optWhereClause  */
  YYSYMBOL_whereClause = 95,               /* whereClause  */
  YYSYMBOL_col = 96,                       /* col  */
  YYSYMBOL_colList = 97,                   /* colList  */
  YYSYMBOL_op = 98,                        /* op  */
  YYSYMBOL_expr = 99,                      /* expr  */
  YYSYMBOL_setClauses = 100,               /* setClauses  */
  YYSYMBOL_setClause = 101,                /* setClause  */
  YYSYMBOL_newSelector = 102,              /* newSelector  */
  YYSYMBOL_selectItemList = 103,           /* selectItemList  */
  YYSYMBOL_selectItem = 104,               /* selectItem  */
  YYSYMBOL_aggregateItem = 105,            /* aggregateItem  */
  YYSYMBOL_aggName = 106,                  /* aggName  */
  YYSYMBOL_fromList = 107,                 /* fromList  */
  YYSYMBOL_optJoinOnClause = 108,          /* optJoinOnClause  */
  YYSYMBOL_tableRef = 109,                 /* tableRef  */
  YYSYMBOL_opt_order_clause = 110,         /* opt_order_clause  */
  YYSYMBOL_order_clause = 111,             /* order_clause  */
  YYSYMBOL_order_item_list = 112,          /* order_item_list  */
  YYSYMBOL_order_item = 113,               /* order_item  */
  YYSYMBOL_opt_asc_desc = 114,             /* opt_asc_desc  */
  YYSYMBOL_optGroupClause = 115,           /* optGroupClause  */
  YYSYMBOL_optHavingClause = 116,          /* optHavingClause  */
  YYSYMBOL_havingClause = 117,             /* havingClause  */
  YYSYMBOL_havingCondition = 118,          /* havingCondition  */
  YYSYMBOL_havingLhs = 119,                /* havingLhs  */
  YYSYMBOL_optLimitClause = 120,           /* optLimitClause  */
  YYSYMBOL_set_knob_type = 121,            /* set_knob_type  */
  YYSYMBOL_tbName = 122,                   /* tbName  */
  YYSYMBOL_colName = 123                   /* colName  */
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
typedef yytype_uint8 yy_state_t;

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

#if 1

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
#endif /* 1 */

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
#define YYFINAL  59
/* YYLAST -- Last index in YYTABLE.  */
#define YYLAST   207

/* YYNTOKENS -- Number of terminals.  */
#define YYNTOKENS  75
/* YYNNTS -- Number of nonterminals.  */
#define YYNNTS  49
/* YYNRULES -- Number of rules.  */
#define YYNRULES  120
/* YYNSTATES -- Number of states.  */
#define YYNSTATES  218

/* YYMAXUTOK -- Last valid token kind.  */
#define YYMAXUTOK   320


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
      68,    69,    74,     2,    70,     2,    71,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,    66,
      72,    67,    73,     2,     2,     2,     2,     2,     2,     2,
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
      45,    46,    47,    48,    49,    50,    51,    52,    53,    54,
      55,    56,    57,    58,    59,    60,    61,    62,    63,    64,
      65
};

#if YYDEBUG
/* YYRLINE[YYN] -- Source line where rule number YYN was defined.  */
static const yytype_int16 yyrline[] =
{
       0,    74,    74,    79,    84,    89,    97,    98,    99,   100,
     101,   105,   109,   113,   117,   124,   128,   135,   139,   143,
     150,   154,   158,   162,   166,   173,   177,   181,   185,   192,
     196,   200,   207,   215,   219,   227,   234,   238,   245,   249,
     256,   263,   267,   271,   275,   282,   286,   293,   297,   301,
     305,   309,   316,   323,   324,   331,   335,   342,   346,   353,
     357,   364,   368,   372,   376,   380,   384,   391,   395,   402,
     406,   413,   428,   432,   436,   440,   447,   451,   455,   459,
     467,   471,   475,   482,   486,   490,   494,   516,   521,   526,
     532,   543,   547,   551,   555,   559,   563,   567,   574,   578,
     582,   589,   593,   600,   607,   608,   609,   613,   617,   621,
     625,   629,   633,   640,   647,   654,   658,   662,   663,   666,
     668
};
#endif

/** Accessing symbol of state STATE.  */
#define YY_ACCESSING_SYMBOL(State) YY_CAST (yysymbol_kind_t, yystos[State])

#if 1
/* The user-facing name of the symbol whose (internal) number is
   YYSYMBOL.  No bounds checking.  */
static const char *yysymbol_name (yysymbol_kind_t yysymbol) YY_ATTRIBUTE_UNUSED;

/* YYTNAME[SYMBOL-NUM] -- String name of the symbol SYMBOL-NUM.
   First, the terminals, then, starting at YYNTOKENS, nonterminals.  */
static const char *const yytname[] =
{
  "\"end of file\"", "error", "\"invalid token\"", "SHOW", "TABLES",
  "CREATE", "TABLE", "DROP", "DESC", "INSERT", "INTO", "VALUES", "DELETE",
  "FROM", "ASC", "ORDER", "BY", "WHERE", "UPDATE", "SET", "TRANSACTION",
  "ISOLATION", "LEVEL", "SNAPSHOT", "SERIALIZABLE", "SELECT", "INT",
  "BIGINT", "CHAR", "FLOAT", "INDEX", "AND", "JOIN", "SEMI", "ON", "GROUP",
  "HAVING", "LIMIT", "AS", "EXPLAIN", "ANALYZE", "UNION", "EXIT", "HELP",
  "TXN_BEGIN", "TXN_COMMIT", "TXN_ABORT", "TXN_ROLLBACK", "ORDER_BY",
  "ENABLE_NESTLOOP", "ENABLE_SORTMERGE", "MAX", "MIN", "COUNT", "SUM",
  "AVG", "LEQ", "NEQ", "GEQ", "T_EOF", "IDENTIFIER", "VALUE_STRING",
  "VALUE_BIGINT", "VALUE_INT", "VALUE_FLOAT", "VALUE_BOOL", "';'", "'='",
  "'('", "')'", "','", "'.'", "'<'", "'>'", "'*'", "$accept", "start",
  "stmt", "txnStmt", "dbStmt", "setStmt", "ddl", "dml", "selectStmt",
  "plainSelectStmt", "unionSelectList", "unionSelect", "fieldList",
  "colNameList", "field", "type", "valueList", "value", "condition",
  "optWhereClause", "whereClause", "col", "colList", "op", "expr",
  "setClauses", "setClause", "newSelector", "selectItemList", "selectItem",
  "aggregateItem", "aggName", "fromList", "optJoinOnClause", "tableRef",
  "opt_order_clause", "order_clause", "order_item_list", "order_item",
  "opt_asc_desc", "optGroupClause", "optHavingClause", "havingClause",
  "havingCondition", "havingLhs", "optLimitClause", "set_knob_type",
  "tbName", "colName", YY_NULLPTR
};

static const char *
yysymbol_name (yysymbol_kind_t yysymbol)
{
  return yytname[yysymbol];
}
#endif

#define YYPACT_NINF (-164)

#define yypact_value_is_default(Yyn) \
  ((Yyn) == YYPACT_NINF)

#define YYTABLE_NINF (-120)

#define yytable_value_is_error(Yyn) \
  0

/* YYPACT[STATE-NUM] -- Index in YYTABLE of the portion describing
   STATE-NUM.  */
static const yytype_int16 yypact[] =
{
      35,     1,     7,    39,    -4,    41,    58,    -4,    26,    37,
      -5,  -164,  -164,  -164,  -164,  -164,  -164,  -164,    84,    20,
    -164,  -164,  -164,  -164,  -164,  -164,  -164,  -164,    83,    -4,
      -4,    -4,    -4,  -164,  -164,    -4,    -4,    94,   125,  -164,
    -164,    80,  -164,  -164,    81,  -164,  -164,    77,  -164,   112,
     138,    82,  -164,   115,    86,    87,  -164,   130,  -164,  -164,
    -164,    -4,    89,    91,  -164,    92,   151,   146,   104,   143,
     101,   -35,   104,    25,    50,   104,   107,   104,  -164,  -164,
     104,   104,   104,   100,   107,  -164,  -164,   -11,  -164,   102,
       0,  -164,   103,   105,  -164,   130,     2,   137,    -8,  -164,
    -164,   106,  -164,    38,  -164,    90,    53,  -164,    72,    70,
    -164,   145,    42,   104,  -164,    70,   156,  -164,  -164,  -164,
    -164,   -19,  -164,    25,    25,   144,   148,    -4,  -164,  -164,
    -164,   104,  -164,  -164,   110,  -164,  -164,  -164,   104,  -164,
    -164,  -164,  -164,  -164,  -164,    74,  -164,   107,  -164,  -164,
    -164,  -164,  -164,  -164,    65,  -164,  -164,  -164,   130,    23,
     147,  -164,   166,   149,    25,  -164,  -164,   120,  -164,  -164,
      70,  -164,  -164,  -164,  -164,  -164,    -4,  -164,   107,  -164,
     107,    85,   169,   152,   118,  -164,  -164,   145,  -164,   121,
    -164,   157,  -164,    42,   174,   158,   107,  -164,   107,    85,
      70,   107,   131,  -164,  -164,  -164,  -164,  -164,    98,  -164,
     123,  -164,  -164,  -164,  -164,  -164,   107,  -164
};

/* YYDEFACT[STATE-NUM] -- Default reduction number in state STATE-NUM.
   Performed when YYTABLE does not specify something else to do.  Zero
   means the default is an error.  */
static const yytype_int8 yydefact[] =
{
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     4,     3,    11,    12,    13,    14,     5,     0,     0,
       9,     6,    10,     7,     8,    28,    29,    15,     0,     0,
       0,     0,     0,   119,    22,     0,     0,     0,     0,   117,
     118,     0,    83,    84,     0,    85,    86,   120,    72,    76,
       0,    73,    74,    78,     0,     0,    58,     0,    30,     1,
       2,     0,     0,     0,    21,     0,     0,    53,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,    31,    16,
       0,     0,     0,     0,     0,    26,   120,    53,    69,     0,
       0,    17,     0,     0,    77,     0,    53,    87,    93,    75,
      79,     0,    57,     0,    36,     0,     0,    38,     0,     0,
      55,    54,     0,     0,    27,     0,     0,    19,    82,    81,
      35,     0,    33,     0,     0,   108,     0,     0,    94,    80,
      20,     0,    41,    44,     0,    43,    40,    23,     0,    24,
      50,    49,    47,    48,    51,     0,    45,     0,    65,    64,
      66,    61,    62,    63,     0,    70,    71,    18,     0,     0,
      92,    88,     0,   110,     0,    95,    37,     0,    39,    25,
       0,    56,    67,    68,    52,    34,     0,    97,     0,    89,
       0,     0,    99,     0,     0,    46,    96,    91,    59,   107,
     114,   109,   111,     0,     0,   116,     0,    42,     0,     0,
       0,     0,     0,    32,    90,    60,   112,   113,   106,    98,
     100,   101,   115,   105,   104,   103,     0,   102
};

/* YYPGOTO[NTERM-NUM].  */
static const yytype_int16 yypgoto[] =
{
    -164,  -164,  -164,  -164,  -164,  -164,  -164,  -164,  -164,    11,
    -164,    40,  -164,   114,    66,  -164,  -164,  -113,  -133,   -32,
      21,    -9,  -164,     8,  -164,  -164,    93,  -164,  -164,   126,
    -163,  -164,  -164,  -164,  -115,  -164,  -164,  -164,   -14,  -164,
    -164,  -164,  -164,     4,  -164,  -164,  -164,    -3,   -65
};

/* YYDEFGOTO[NTERM-NUM].  */
static const yytype_uint8 yydefgoto[] =
{
       0,    18,    19,    20,    21,    22,    23,    24,    25,   120,
     121,   122,   103,   106,   104,   136,   145,   146,   110,    85,
     111,   112,   189,   154,   174,    87,    88,    50,    51,    52,
      53,    54,    96,   179,    97,   195,   209,   210,   211,   215,
     163,   182,   191,   192,   193,   203,    41,    55,    56
};

/* YYTABLE[YYPACT[STATE-NUM]] -- What to do in state STATE-NUM.  If
   positive, shift that token.  If negative, reduce the rule whose
   number is the opposite.  If YYTABLE_NINF, syntax error.  */
static const yytype_int16 yytable[] =
{
      49,    34,   156,    89,    37,    27,    84,    94,   160,   161,
     100,    26,   102,    29,   171,   105,   107,   107,   190,    84,
       9,    58,   158,   116,   117,    47,    62,    63,    64,    65,
     127,    28,    66,    67,   123,    57,   190,    30,     1,    92,
       2,   172,     3,     4,     5,    31,    38,     6,    89,   183,
     159,    35,    33,     7,     8,   114,    33,   185,    79,   113,
       9,   176,    93,   204,   125,    49,   105,   101,    78,    32,
      98,    36,   124,   168,    10,    39,    40,    11,    12,    13,
      14,    15,    16,    33,    59,    33,    60,   207,    42,    43,
      44,    45,    46,    95,    17,   128,    61,    47,   148,   149,
     150,    42,    43,    44,    45,    46,   213,   130,   131,   151,
      47,    48,   214,    68,   152,   153,   132,   133,   134,   135,
      98,    98,   137,   138,   165,    47,   140,   141,   142,   143,
     144,   140,   141,   142,   143,   144,    42,    43,    44,    45,
      46,   139,   138,   169,   170,   173,    69,    70,  -119,    71,
      72,    73,    74,    75,    76,     9,   177,    80,    77,    81,
      82,    98,    83,    84,    86,    90,    91,    47,   109,   115,
     126,   188,   118,   186,   119,   129,   147,   157,   167,   162,
     164,   178,   180,   184,   194,   181,   196,   197,   199,   205,
     201,   198,   208,   216,   212,   202,   108,   166,   175,   187,
      99,   200,   217,   206,     0,     0,   155,   208
};

static const yytype_int16 yycheck[] =
{
       9,     4,   115,    68,     7,     4,    17,    72,   123,   124,
      75,     0,    77,     6,   147,    80,    81,    82,   181,    17,
      25,    10,    41,    23,    24,    60,    29,    30,    31,    32,
      38,    30,    35,    36,    32,    40,   199,    30,     3,    74,
       5,   154,     7,     8,     9,     6,    20,    12,   113,   164,
      69,    10,    60,    18,    19,    87,    60,   170,    61,    70,
      25,    38,    71,   196,    96,    74,   131,    76,    57,    30,
      73,    13,    70,   138,    39,    49,    50,    42,    43,    44,
      45,    46,    47,    60,     0,    60,    66,   200,    51,    52,
      53,    54,    55,    68,    59,    98,    13,    60,    56,    57,
      58,    51,    52,    53,    54,    55,     8,    69,    70,    67,
      60,    74,    14,    19,    72,    73,    26,    27,    28,    29,
     123,   124,    69,    70,   127,    60,    61,    62,    63,    64,
      65,    61,    62,    63,    64,    65,    51,    52,    53,    54,
      55,    69,    70,    69,    70,   154,    21,    67,    71,    68,
      38,    13,    70,    38,    68,    25,   159,    68,    71,    68,
      68,   164,    11,    17,    60,    22,    65,    60,    68,    67,
      33,   180,    69,   176,    69,    69,    31,    21,    68,    35,
      32,    34,    16,    63,    15,    36,    34,    69,    31,   198,
      16,    70,   201,    70,    63,    37,    82,   131,   158,   178,
      74,   193,   216,   199,    -1,    -1,   113,   216
};

/* YYSTOS[STATE-NUM] -- The symbol kind of the accessing symbol of
   state STATE-NUM.  */
static const yytype_int8 yystos[] =
{
       0,     3,     5,     7,     8,     9,    12,    18,    19,    25,
      39,    42,    43,    44,    45,    46,    47,    59,    76,    77,
      78,    79,    80,    81,    82,    83,    84,     4,    30,     6,
      30,     6,    30,    60,   122,    10,    13,   122,    20,    49,
      50,   121,    51,    52,    53,    54,    55,    60,    74,    96,
     102,   103,   104,   105,   106,   122,   123,    40,    84,     0,
      66,    13,   122,   122,   122,   122,   122,   122,    19,    21,
      67,    68,    38,    13,    70,    38,    68,    71,    84,   122,
      68,    68,    68,    11,    17,    94,    60,   100,   101,   123,
      22,    65,    74,    96,   123,    68,   107,   109,   122,   104,
     123,    96,   123,    87,    89,   123,    88,   123,    88,    68,
      93,    95,    96,    70,    94,    67,    23,    24,    69,    69,
      84,    85,    86,    32,    70,    94,    33,    38,   122,    69,
      69,    70,    26,    27,    28,    29,    90,    69,    70,    69,
      61,    62,    63,    64,    65,    91,    92,    31,    56,    57,
      58,    67,    72,    73,    98,   101,    92,    21,    41,    69,
     109,   109,    35,   115,    32,   122,    89,    68,   123,    69,
      70,    93,    92,    96,    99,    86,    38,   122,    34,   108,
      16,    36,   116,   109,    63,    92,   122,    95,    96,    97,
     105,   117,   118,   119,    15,   110,    34,    69,    70,    31,
      98,    16,    37,   120,    93,    96,   118,    92,    96,   111,
     112,   113,    63,     8,    14,   114,    70,   113
};

/* YYR1[RULE-NUM] -- Symbol kind of the left-hand side of rule RULE-NUM.  */
static const yytype_int8 yyr1[] =
{
       0,    75,    76,    76,    76,    76,    77,    77,    77,    77,
      77,    78,    78,    78,    78,    79,    79,    80,    80,    80,
      81,    81,    81,    81,    81,    82,    82,    82,    82,    83,
      83,    83,    84,    85,    85,    86,    87,    87,    88,    88,
      89,    90,    90,    90,    90,    91,    91,    92,    92,    92,
      92,    92,    93,    94,    94,    95,    95,    96,    96,    97,
      97,    98,    98,    98,    98,    98,    98,    99,    99,   100,
     100,   101,   102,   102,   103,   103,   104,   104,   104,   104,
     105,   105,   105,   106,   106,   106,   106,   107,   107,   107,
     107,   108,   108,   109,   109,   109,   109,   109,   110,   110,
     111,   112,   112,   113,   114,   114,   114,   115,   115,   116,
     116,   117,   117,   118,   119,   120,   120,   121,   121,   122,
     123
};

/* YYR2[RULE-NUM] -- Number of symbols on the right-hand side of rule RULE-NUM.  */
static const yytype_int8 yyr2[] =
{
       0,     2,     2,     1,     1,     1,     1,     1,     1,     1,
       1,     1,     1,     1,     1,     2,     4,     4,     6,     5,
       6,     3,     2,     6,     6,     7,     4,     5,     1,     1,
       2,     3,     9,     1,     3,     1,     1,     3,     1,     3,
       2,     1,     4,     1,     1,     1,     3,     1,     1,     1,
       1,     1,     3,     0,     2,     1,     3,     3,     1,     1,
       3,     1,     1,     1,     1,     1,     1,     1,     1,     1,
       3,     3,     1,     1,     1,     3,     1,     3,     1,     3,
       4,     4,     4,     1,     1,     1,     1,     1,     3,     4,
       6,     2,     0,     1,     2,     3,     5,     4,     3,     0,
       1,     1,     3,     2,     1,     1,     0,     3,     0,     2,
       0,     1,     3,     3,     1,     2,     0,     1,     1,     1,
       1
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
        yyerror (&yylloc, YY_("syntax error: cannot back up")); \
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
                  Kind, Value, Location); \
      YYFPRINTF (stderr, "\n");                                           \
    }                                                                     \
} while (0)


/*-----------------------------------.
| Print this symbol's value on YYO.  |
`-----------------------------------*/

static void
yy_symbol_value_print (FILE *yyo,
                       yysymbol_kind_t yykind, YYSTYPE const * const yyvaluep, YYLTYPE const * const yylocationp)
{
  FILE *yyoutput = yyo;
  YY_USE (yyoutput);
  YY_USE (yylocationp);
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
                 yysymbol_kind_t yykind, YYSTYPE const * const yyvaluep, YYLTYPE const * const yylocationp)
{
  YYFPRINTF (yyo, "%s %s (",
             yykind < YYNTOKENS ? "token" : "nterm", yysymbol_name (yykind));

  YYLOCATION_PRINT (yyo, yylocationp);
  YYFPRINTF (yyo, ": ");
  yy_symbol_value_print (yyo, yykind, yyvaluep, yylocationp);
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
                       &yyvsp[(yyi + 1) - (yynrhs)],
                       &(yylsp[(yyi + 1) - (yynrhs)]));
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


/* Context of a parse error.  */
typedef struct
{
  yy_state_t *yyssp;
  yysymbol_kind_t yytoken;
  YYLTYPE *yylloc;
} yypcontext_t;

/* Put in YYARG at most YYARGN of the expected tokens given the
   current YYCTX, and return the number of tokens stored in YYARG.  If
   YYARG is null, return the number of expected tokens (guaranteed to
   be less than YYNTOKENS).  Return YYENOMEM on memory exhaustion.
   Return 0 if there are more than YYARGN expected tokens, yet fill
   YYARG up to YYARGN. */
static int
yypcontext_expected_tokens (const yypcontext_t *yyctx,
                            yysymbol_kind_t yyarg[], int yyargn)
{
  /* Actual size of YYARG. */
  int yycount = 0;
  int yyn = yypact[+*yyctx->yyssp];
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
        if (yycheck[yyx + yyn] == yyx && yyx != YYSYMBOL_YYerror
            && !yytable_value_is_error (yytable[yyx + yyn]))
          {
            if (!yyarg)
              ++yycount;
            else if (yycount == yyargn)
              return 0;
            else
              yyarg[yycount++] = YY_CAST (yysymbol_kind_t, yyx);
          }
    }
  if (yyarg && yycount == 0 && 0 < yyargn)
    yyarg[0] = YYSYMBOL_YYEMPTY;
  return yycount;
}




#ifndef yystrlen
# if defined __GLIBC__ && defined _STRING_H
#  define yystrlen(S) (YY_CAST (YYPTRDIFF_T, strlen (S)))
# else
/* Return the length of YYSTR.  */
static YYPTRDIFF_T
yystrlen (const char *yystr)
{
  YYPTRDIFF_T yylen;
  for (yylen = 0; yystr[yylen]; yylen++)
    continue;
  return yylen;
}
# endif
#endif

#ifndef yystpcpy
# if defined __GLIBC__ && defined _STRING_H && defined _GNU_SOURCE
#  define yystpcpy stpcpy
# else
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
# endif
#endif

#ifndef yytnamerr
/* Copy to YYRES the contents of YYSTR after stripping away unnecessary
   quotes and backslashes, so that it's suitable for yyerror.  The
   heuristic is that double-quoting is unnecessary unless the string
   contains an apostrophe, a comma, or backslash (other than
   backslash-backslash).  YYSTR is taken from yytname.  If YYRES is
   null, do not copy; instead, return the length of what the result
   would have been.  */
static YYPTRDIFF_T
yytnamerr (char *yyres, const char *yystr)
{
  if (*yystr == '"')
    {
      YYPTRDIFF_T yyn = 0;
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

  if (yyres)
    return yystpcpy (yyres, yystr) - yyres;
  else
    return yystrlen (yystr);
}
#endif


static int
yy_syntax_error_arguments (const yypcontext_t *yyctx,
                           yysymbol_kind_t yyarg[], int yyargn)
{
  /* Actual size of YYARG. */
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
  if (yyctx->yytoken != YYSYMBOL_YYEMPTY)
    {
      int yyn;
      if (yyarg)
        yyarg[yycount] = yyctx->yytoken;
      ++yycount;
      yyn = yypcontext_expected_tokens (yyctx,
                                        yyarg ? yyarg + 1 : yyarg, yyargn - 1);
      if (yyn == YYENOMEM)
        return YYENOMEM;
      else
        yycount += yyn;
    }
  return yycount;
}

/* Copy into *YYMSG, which is of size *YYMSG_ALLOC, an error message
   about the unexpected token YYTOKEN for the state stack whose top is
   YYSSP.

   Return 0 if *YYMSG was successfully written.  Return -1 if *YYMSG is
   not large enough to hold the message.  In that case, also set
   *YYMSG_ALLOC to the required number of bytes.  Return YYENOMEM if the
   required number of bytes is too large to store.  */
static int
yysyntax_error (YYPTRDIFF_T *yymsg_alloc, char **yymsg,
                const yypcontext_t *yyctx)
{
  enum { YYARGS_MAX = 5 };
  /* Internationalized format string. */
  const char *yyformat = YY_NULLPTR;
  /* Arguments of yyformat: reported tokens (one for the "unexpected",
     one per "expected"). */
  yysymbol_kind_t yyarg[YYARGS_MAX];
  /* Cumulated lengths of YYARG.  */
  YYPTRDIFF_T yysize = 0;

  /* Actual size of YYARG. */
  int yycount = yy_syntax_error_arguments (yyctx, yyarg, YYARGS_MAX);
  if (yycount == YYENOMEM)
    return YYENOMEM;

  switch (yycount)
    {
#define YYCASE_(N, S)                       \
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
#undef YYCASE_
    }

  /* Compute error message size.  Don't count the "%s"s, but reserve
     room for the terminator.  */
  yysize = yystrlen (yyformat) - 2 * yycount + 1;
  {
    int yyi;
    for (yyi = 0; yyi < yycount; ++yyi)
      {
        YYPTRDIFF_T yysize1
          = yysize + yytnamerr (YY_NULLPTR, yytname[yyarg[yyi]]);
        if (yysize <= yysize1 && yysize1 <= YYSTACK_ALLOC_MAXIMUM)
          yysize = yysize1;
        else
          return YYENOMEM;
      }
  }

  if (*yymsg_alloc < yysize)
    {
      *yymsg_alloc = 2 * yysize;
      if (! (yysize <= *yymsg_alloc
             && *yymsg_alloc <= YYSTACK_ALLOC_MAXIMUM))
        *yymsg_alloc = YYSTACK_ALLOC_MAXIMUM;
      return -1;
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
          yyp += yytnamerr (yyp, yytname[yyarg[yyi++]]);
          yyformat += 2;
        }
      else
        {
          ++yyp;
          ++yyformat;
        }
  }
  return 0;
}


/*-----------------------------------------------.
| Release the memory associated to this symbol.  |
`-----------------------------------------------*/

static void
yydestruct (const char *yymsg,
            yysymbol_kind_t yykind, YYSTYPE *yyvaluep, YYLTYPE *yylocationp)
{
  YY_USE (yyvaluep);
  YY_USE (yylocationp);
  if (!yymsg)
    yymsg = "Deleting";
  YY_SYMBOL_PRINT (yymsg, yykind, yyvaluep, yylocationp);

  YY_IGNORE_MAYBE_UNINITIALIZED_BEGIN
  YY_USE (yykind);
  YY_IGNORE_MAYBE_UNINITIALIZED_END
}






/*----------.
| yyparse.  |
`----------*/

int
yyparse (void)
{
/* Lookahead token kind.  */
int yychar;


/* The semantic value of the lookahead symbol.  */
/* Default value used for initialization, for pacifying older GCCs
   or non-GCC compilers.  */
YY_INITIAL_VALUE (static YYSTYPE yyval_default;)
YYSTYPE yylval YY_INITIAL_VALUE (= yyval_default);

/* Location data for the lookahead symbol.  */
static YYLTYPE yyloc_default
# if defined YYLTYPE_IS_TRIVIAL && YYLTYPE_IS_TRIVIAL
  = { 1, 1, 1, 1 }
# endif
;
YYLTYPE yylloc = yyloc_default;

    /* Number of syntax errors so far.  */
    int yynerrs = 0;

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

  /* Buffer for error messages, and its allocated size.  */
  char yymsgbuf[128];
  char *yymsg = yymsgbuf;
  YYPTRDIFF_T yymsg_alloc = sizeof yymsgbuf;

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
      yychar = yylex (&yylval, &yylloc);
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
  case 2: /* start: stmt ';'  */
#line 75 "/mnt/d/dbcodes/rmdb-main/src/parser/yacc.y"
    {
        parse_tree = (yyvsp[-1].sv_node);
        YYACCEPT;
    }
#line 1754 "/mnt/d/dbcodes/rmdb-main/src/parser/yacc.tab.cpp"
    break;

  case 3: /* start: HELP  */
#line 80 "/mnt/d/dbcodes/rmdb-main/src/parser/yacc.y"
    {
        parse_tree = std::make_shared<Help>();
        YYACCEPT;
    }
#line 1763 "/mnt/d/dbcodes/rmdb-main/src/parser/yacc.tab.cpp"
    break;

  case 4: /* start: EXIT  */
#line 85 "/mnt/d/dbcodes/rmdb-main/src/parser/yacc.y"
    {
        parse_tree = nullptr;
        YYACCEPT;
    }
#line 1772 "/mnt/d/dbcodes/rmdb-main/src/parser/yacc.tab.cpp"
    break;

  case 5: /* start: T_EOF  */
#line 90 "/mnt/d/dbcodes/rmdb-main/src/parser/yacc.y"
    {
        parse_tree = nullptr;
        YYACCEPT;
    }
#line 1781 "/mnt/d/dbcodes/rmdb-main/src/parser/yacc.tab.cpp"
    break;

  case 11: /* txnStmt: TXN_BEGIN  */
#line 106 "/mnt/d/dbcodes/rmdb-main/src/parser/yacc.y"
    {
        (yyval.sv_node) = std::make_shared<TxnBegin>();
    }
#line 1789 "/mnt/d/dbcodes/rmdb-main/src/parser/yacc.tab.cpp"
    break;

  case 12: /* txnStmt: TXN_COMMIT  */
#line 110 "/mnt/d/dbcodes/rmdb-main/src/parser/yacc.y"
    {
        (yyval.sv_node) = std::make_shared<TxnCommit>();
    }
#line 1797 "/mnt/d/dbcodes/rmdb-main/src/parser/yacc.tab.cpp"
    break;

  case 13: /* txnStmt: TXN_ABORT  */
#line 114 "/mnt/d/dbcodes/rmdb-main/src/parser/yacc.y"
    {
        (yyval.sv_node) = std::make_shared<TxnAbort>();
    }
#line 1805 "/mnt/d/dbcodes/rmdb-main/src/parser/yacc.tab.cpp"
    break;

  case 14: /* txnStmt: TXN_ROLLBACK  */
#line 118 "/mnt/d/dbcodes/rmdb-main/src/parser/yacc.y"
    {
        (yyval.sv_node) = std::make_shared<TxnRollback>();
    }
#line 1813 "/mnt/d/dbcodes/rmdb-main/src/parser/yacc.tab.cpp"
    break;

  case 15: /* dbStmt: SHOW TABLES  */
#line 125 "/mnt/d/dbcodes/rmdb-main/src/parser/yacc.y"
    {
        (yyval.sv_node) = std::make_shared<ShowTables>();
    }
#line 1821 "/mnt/d/dbcodes/rmdb-main/src/parser/yacc.tab.cpp"
    break;

  case 16: /* dbStmt: SHOW INDEX FROM tbName  */
#line 129 "/mnt/d/dbcodes/rmdb-main/src/parser/yacc.y"
    {
        (yyval.sv_node) = std::make_shared<ShowIndex>((yyvsp[0].sv_str));
    }
#line 1829 "/mnt/d/dbcodes/rmdb-main/src/parser/yacc.tab.cpp"
    break;

  case 17: /* setStmt: SET set_knob_type '=' VALUE_BOOL  */
#line 136 "/mnt/d/dbcodes/rmdb-main/src/parser/yacc.y"
    {
        (yyval.sv_node) = std::make_shared<SetStmt>((yyvsp[-2].sv_setKnobType), (yyvsp[0].sv_bool));
    }
#line 1837 "/mnt/d/dbcodes/rmdb-main/src/parser/yacc.tab.cpp"
    break;

  case 18: /* setStmt: SET TRANSACTION ISOLATION LEVEL SNAPSHOT ISOLATION  */
#line 140 "/mnt/d/dbcodes/rmdb-main/src/parser/yacc.y"
    {
        (yyval.sv_node) = std::make_shared<SetTransactionIsolation>(false);
    }
#line 1845 "/mnt/d/dbcodes/rmdb-main/src/parser/yacc.tab.cpp"
    break;

  case 19: /* setStmt: SET TRANSACTION ISOLATION LEVEL SERIALIZABLE  */
#line 144 "/mnt/d/dbcodes/rmdb-main/src/parser/yacc.y"
    {
        (yyval.sv_node) = std::make_shared<SetTransactionIsolation>(true);
    }
#line 1853 "/mnt/d/dbcodes/rmdb-main/src/parser/yacc.tab.cpp"
    break;

  case 20: /* ddl: CREATE TABLE tbName '(' fieldList ')'  */
#line 151 "/mnt/d/dbcodes/rmdb-main/src/parser/yacc.y"
    {
        (yyval.sv_node) = std::make_shared<CreateTable>((yyvsp[-3].sv_str), (yyvsp[-1].sv_fields));
    }
#line 1861 "/mnt/d/dbcodes/rmdb-main/src/parser/yacc.tab.cpp"
    break;

  case 21: /* ddl: DROP TABLE tbName  */
#line 155 "/mnt/d/dbcodes/rmdb-main/src/parser/yacc.y"
    {
        (yyval.sv_node) = std::make_shared<DropTable>((yyvsp[0].sv_str));
    }
#line 1869 "/mnt/d/dbcodes/rmdb-main/src/parser/yacc.tab.cpp"
    break;

  case 22: /* ddl: DESC tbName  */
#line 159 "/mnt/d/dbcodes/rmdb-main/src/parser/yacc.y"
    {
        (yyval.sv_node) = std::make_shared<DescTable>((yyvsp[0].sv_str));
    }
#line 1877 "/mnt/d/dbcodes/rmdb-main/src/parser/yacc.tab.cpp"
    break;

  case 23: /* ddl: CREATE INDEX tbName '(' colNameList ')'  */
#line 163 "/mnt/d/dbcodes/rmdb-main/src/parser/yacc.y"
    {
        (yyval.sv_node) = std::make_shared<CreateIndex>((yyvsp[-3].sv_str), (yyvsp[-1].sv_strs));
    }
#line 1885 "/mnt/d/dbcodes/rmdb-main/src/parser/yacc.tab.cpp"
    break;

  case 24: /* ddl: DROP INDEX tbName '(' colNameList ')'  */
#line 167 "/mnt/d/dbcodes/rmdb-main/src/parser/yacc.y"
    {
        (yyval.sv_node) = std::make_shared<DropIndex>((yyvsp[-3].sv_str), (yyvsp[-1].sv_strs));
    }
#line 1893 "/mnt/d/dbcodes/rmdb-main/src/parser/yacc.tab.cpp"
    break;

  case 25: /* dml: INSERT INTO tbName VALUES '(' valueList ')'  */
#line 174 "/mnt/d/dbcodes/rmdb-main/src/parser/yacc.y"
    {
        (yyval.sv_node) = std::make_shared<InsertStmt>((yyvsp[-4].sv_str), (yyvsp[-1].sv_vals));
    }
#line 1901 "/mnt/d/dbcodes/rmdb-main/src/parser/yacc.tab.cpp"
    break;

  case 26: /* dml: DELETE FROM tbName optWhereClause  */
#line 178 "/mnt/d/dbcodes/rmdb-main/src/parser/yacc.y"
    {
        (yyval.sv_node) = std::make_shared<DeleteStmt>((yyvsp[-1].sv_str), (yyvsp[0].sv_conds));
    }
#line 1909 "/mnt/d/dbcodes/rmdb-main/src/parser/yacc.tab.cpp"
    break;

  case 27: /* dml: UPDATE tbName SET setClauses optWhereClause  */
#line 182 "/mnt/d/dbcodes/rmdb-main/src/parser/yacc.y"
    {
        (yyval.sv_node) = std::make_shared<UpdateStmt>((yyvsp[-3].sv_str), (yyvsp[-1].sv_set_clauses), (yyvsp[0].sv_conds));
    }
#line 1917 "/mnt/d/dbcodes/rmdb-main/src/parser/yacc.tab.cpp"
    break;

  case 28: /* dml: selectStmt  */
#line 186 "/mnt/d/dbcodes/rmdb-main/src/parser/yacc.y"
    {
        (yyval.sv_node) = (yyvsp[0].sv_node);
    }
#line 1925 "/mnt/d/dbcodes/rmdb-main/src/parser/yacc.tab.cpp"
    break;

  case 29: /* selectStmt: plainSelectStmt  */
#line 193 "/mnt/d/dbcodes/rmdb-main/src/parser/yacc.y"
    {
        (yyval.sv_node) = (yyvsp[0].sv_select_stmt);
    }
#line 1933 "/mnt/d/dbcodes/rmdb-main/src/parser/yacc.tab.cpp"
    break;

  case 30: /* selectStmt: EXPLAIN plainSelectStmt  */
#line 197 "/mnt/d/dbcodes/rmdb-main/src/parser/yacc.y"
    {
        (yyval.sv_node) = std::make_shared<ExplainStmt>((yyvsp[0].sv_select_stmt));
    }
#line 1941 "/mnt/d/dbcodes/rmdb-main/src/parser/yacc.tab.cpp"
    break;

  case 31: /* selectStmt: EXPLAIN ANALYZE plainSelectStmt  */
#line 201 "/mnt/d/dbcodes/rmdb-main/src/parser/yacc.y"
    {
        (yyval.sv_node) = std::make_shared<ExplainStmt>((yyvsp[0].sv_select_stmt));
    }
#line 1949 "/mnt/d/dbcodes/rmdb-main/src/parser/yacc.tab.cpp"
    break;

  case 32: /* plainSelectStmt: SELECT newSelector FROM fromList optWhereClause optGroupClause optHavingClause opt_order_clause optLimitClause  */
#line 208 "/mnt/d/dbcodes/rmdb-main/src/parser/yacc.y"
    {
        (yyvsp[-4].sv_conds).insert((yyvsp[-4].sv_conds).end(), (yyvsp[-5].sv_from)->join_conds.begin(), (yyvsp[-5].sv_from)->join_conds.end());
        (yyval.sv_select_stmt) = std::make_shared<SelectStmt>((yyvsp[-7].sv_select_items), (yyvsp[-5].sv_from)->table_refs, (yyvsp[-4].sv_conds), (yyvsp[-3].sv_cols), (yyvsp[-2].sv_havings), (yyvsp[-1].sv_orderby), (yyvsp[0].sv_int), (yyvsp[-5].sv_from)->is_semi_join, (yyvsp[-5].sv_from)->semi_conds);
    }
#line 1958 "/mnt/d/dbcodes/rmdb-main/src/parser/yacc.tab.cpp"
    break;

  case 33: /* unionSelectList: unionSelect  */
#line 216 "/mnt/d/dbcodes/rmdb-main/src/parser/yacc.y"
    {
        (yyval.sv_select_stmts) = std::vector<std::shared_ptr<SelectStmt>>{(yyvsp[0].sv_select_stmt)};
    }
#line 1966 "/mnt/d/dbcodes/rmdb-main/src/parser/yacc.tab.cpp"
    break;

  case 34: /* unionSelectList: unionSelectList UNION unionSelect  */
#line 220 "/mnt/d/dbcodes/rmdb-main/src/parser/yacc.y"
    {
        (yyvsp[-2].sv_select_stmts).push_back((yyvsp[0].sv_select_stmt));
        (yyval.sv_select_stmts) = (yyvsp[-2].sv_select_stmts);
    }
#line 1975 "/mnt/d/dbcodes/rmdb-main/src/parser/yacc.tab.cpp"
    break;

  case 35: /* unionSelect: plainSelectStmt  */
#line 228 "/mnt/d/dbcodes/rmdb-main/src/parser/yacc.y"
    {
        (yyval.sv_select_stmt) = (yyvsp[0].sv_select_stmt);
    }
#line 1983 "/mnt/d/dbcodes/rmdb-main/src/parser/yacc.tab.cpp"
    break;

  case 36: /* fieldList: field  */
#line 235 "/mnt/d/dbcodes/rmdb-main/src/parser/yacc.y"
    {
        (yyval.sv_fields) = std::vector<std::shared_ptr<Field>>{(yyvsp[0].sv_field)};
    }
#line 1991 "/mnt/d/dbcodes/rmdb-main/src/parser/yacc.tab.cpp"
    break;

  case 37: /* fieldList: fieldList ',' field  */
#line 239 "/mnt/d/dbcodes/rmdb-main/src/parser/yacc.y"
    {
        (yyval.sv_fields).push_back((yyvsp[0].sv_field));
    }
#line 1999 "/mnt/d/dbcodes/rmdb-main/src/parser/yacc.tab.cpp"
    break;

  case 38: /* colNameList: colName  */
#line 246 "/mnt/d/dbcodes/rmdb-main/src/parser/yacc.y"
    {
        (yyval.sv_strs) = std::vector<std::string>{(yyvsp[0].sv_str)};
    }
#line 2007 "/mnt/d/dbcodes/rmdb-main/src/parser/yacc.tab.cpp"
    break;

  case 39: /* colNameList: colNameList ',' colName  */
#line 250 "/mnt/d/dbcodes/rmdb-main/src/parser/yacc.y"
    {
        (yyval.sv_strs).push_back((yyvsp[0].sv_str));
    }
#line 2015 "/mnt/d/dbcodes/rmdb-main/src/parser/yacc.tab.cpp"
    break;

  case 40: /* field: colName type  */
#line 257 "/mnt/d/dbcodes/rmdb-main/src/parser/yacc.y"
    {
        (yyval.sv_field) = std::make_shared<ColDef>((yyvsp[-1].sv_str), (yyvsp[0].sv_type_len));
    }
#line 2023 "/mnt/d/dbcodes/rmdb-main/src/parser/yacc.tab.cpp"
    break;

  case 41: /* type: INT  */
#line 264 "/mnt/d/dbcodes/rmdb-main/src/parser/yacc.y"
    {
        (yyval.sv_type_len) = std::make_shared<TypeLen>(SV_TYPE_INT, sizeof(int));
    }
#line 2031 "/mnt/d/dbcodes/rmdb-main/src/parser/yacc.tab.cpp"
    break;

  case 42: /* type: CHAR '(' VALUE_INT ')'  */
#line 268 "/mnt/d/dbcodes/rmdb-main/src/parser/yacc.y"
    {
        (yyval.sv_type_len) = std::make_shared<TypeLen>(SV_TYPE_STRING, (yyvsp[-1].sv_int));
    }
#line 2039 "/mnt/d/dbcodes/rmdb-main/src/parser/yacc.tab.cpp"
    break;

  case 43: /* type: FLOAT  */
#line 272 "/mnt/d/dbcodes/rmdb-main/src/parser/yacc.y"
    {
        (yyval.sv_type_len) = std::make_shared<TypeLen>(SV_TYPE_FLOAT, sizeof(float));
    }
#line 2047 "/mnt/d/dbcodes/rmdb-main/src/parser/yacc.tab.cpp"
    break;

  case 44: /* type: BIGINT  */
#line 276 "/mnt/d/dbcodes/rmdb-main/src/parser/yacc.y"
    {
        (yyval.sv_type_len) = std::make_shared<TypeLen>(SV_TYPE_BIGINT, sizeof(int64_t));
    }
#line 2055 "/mnt/d/dbcodes/rmdb-main/src/parser/yacc.tab.cpp"
    break;

  case 45: /* valueList: value  */
#line 283 "/mnt/d/dbcodes/rmdb-main/src/parser/yacc.y"
    {
        (yyval.sv_vals) = std::vector<std::shared_ptr<Value>>{(yyvsp[0].sv_val)};
    }
#line 2063 "/mnt/d/dbcodes/rmdb-main/src/parser/yacc.tab.cpp"
    break;

  case 46: /* valueList: valueList ',' value  */
#line 287 "/mnt/d/dbcodes/rmdb-main/src/parser/yacc.y"
    {
        (yyval.sv_vals).push_back((yyvsp[0].sv_val));
    }
#line 2071 "/mnt/d/dbcodes/rmdb-main/src/parser/yacc.tab.cpp"
    break;

  case 47: /* value: VALUE_INT  */
#line 294 "/mnt/d/dbcodes/rmdb-main/src/parser/yacc.y"
    {
        (yyval.sv_val) = std::make_shared<IntLit>((yyvsp[0].sv_int));
    }
#line 2079 "/mnt/d/dbcodes/rmdb-main/src/parser/yacc.tab.cpp"
    break;

  case 48: /* value: VALUE_FLOAT  */
#line 298 "/mnt/d/dbcodes/rmdb-main/src/parser/yacc.y"
    {
        (yyval.sv_val) = std::make_shared<FloatLit>((yyvsp[0].sv_float));
    }
#line 2087 "/mnt/d/dbcodes/rmdb-main/src/parser/yacc.tab.cpp"
    break;

  case 49: /* value: VALUE_BIGINT  */
#line 302 "/mnt/d/dbcodes/rmdb-main/src/parser/yacc.y"
    {
        (yyval.sv_val) = std::make_shared<BigIntLit>((yyvsp[0].sv_str));
    }
#line 2095 "/mnt/d/dbcodes/rmdb-main/src/parser/yacc.tab.cpp"
    break;

  case 50: /* value: VALUE_STRING  */
#line 306 "/mnt/d/dbcodes/rmdb-main/src/parser/yacc.y"
    {
        (yyval.sv_val) = std::make_shared<StringLit>((yyvsp[0].sv_str));
    }
#line 2103 "/mnt/d/dbcodes/rmdb-main/src/parser/yacc.tab.cpp"
    break;

  case 51: /* value: VALUE_BOOL  */
#line 310 "/mnt/d/dbcodes/rmdb-main/src/parser/yacc.y"
    {
        (yyval.sv_val) = std::make_shared<BoolLit>((yyvsp[0].sv_bool));
    }
#line 2111 "/mnt/d/dbcodes/rmdb-main/src/parser/yacc.tab.cpp"
    break;

  case 52: /* condition: col op expr  */
#line 317 "/mnt/d/dbcodes/rmdb-main/src/parser/yacc.y"
    {
        (yyval.sv_cond) = std::make_shared<BinaryExpr>((yyvsp[-2].sv_col), (yyvsp[-1].sv_comp_op), (yyvsp[0].sv_expr));
    }
#line 2119 "/mnt/d/dbcodes/rmdb-main/src/parser/yacc.tab.cpp"
    break;

  case 53: /* optWhereClause: %empty  */
#line 323 "/mnt/d/dbcodes/rmdb-main/src/parser/yacc.y"
                      { (yyval.sv_conds) = {}; }
#line 2125 "/mnt/d/dbcodes/rmdb-main/src/parser/yacc.tab.cpp"
    break;

  case 54: /* optWhereClause: WHERE whereClause  */
#line 325 "/mnt/d/dbcodes/rmdb-main/src/parser/yacc.y"
    {
        (yyval.sv_conds) = (yyvsp[0].sv_conds);
    }
#line 2133 "/mnt/d/dbcodes/rmdb-main/src/parser/yacc.tab.cpp"
    break;

  case 55: /* whereClause: condition  */
#line 332 "/mnt/d/dbcodes/rmdb-main/src/parser/yacc.y"
    {
        (yyval.sv_conds) = std::vector<std::shared_ptr<BinaryExpr>>{(yyvsp[0].sv_cond)};
    }
#line 2141 "/mnt/d/dbcodes/rmdb-main/src/parser/yacc.tab.cpp"
    break;

  case 56: /* whereClause: whereClause AND condition  */
#line 336 "/mnt/d/dbcodes/rmdb-main/src/parser/yacc.y"
    {
        (yyval.sv_conds).push_back((yyvsp[0].sv_cond));
    }
#line 2149 "/mnt/d/dbcodes/rmdb-main/src/parser/yacc.tab.cpp"
    break;

  case 57: /* col: tbName '.' colName  */
#line 343 "/mnt/d/dbcodes/rmdb-main/src/parser/yacc.y"
    {
        (yyval.sv_col) = std::make_shared<Col>((yyvsp[-2].sv_str), (yyvsp[0].sv_str));
    }
#line 2157 "/mnt/d/dbcodes/rmdb-main/src/parser/yacc.tab.cpp"
    break;

  case 58: /* col: colName  */
#line 347 "/mnt/d/dbcodes/rmdb-main/src/parser/yacc.y"
    {
        (yyval.sv_col) = std::make_shared<Col>("", (yyvsp[0].sv_str));
    }
#line 2165 "/mnt/d/dbcodes/rmdb-main/src/parser/yacc.tab.cpp"
    break;

  case 59: /* colList: col  */
#line 354 "/mnt/d/dbcodes/rmdb-main/src/parser/yacc.y"
    {
        (yyval.sv_cols) = std::vector<std::shared_ptr<Col>>{(yyvsp[0].sv_col)};
    }
#line 2173 "/mnt/d/dbcodes/rmdb-main/src/parser/yacc.tab.cpp"
    break;

  case 60: /* colList: colList ',' col  */
#line 358 "/mnt/d/dbcodes/rmdb-main/src/parser/yacc.y"
    {
        (yyval.sv_cols).push_back((yyvsp[0].sv_col));
    }
#line 2181 "/mnt/d/dbcodes/rmdb-main/src/parser/yacc.tab.cpp"
    break;

  case 61: /* op: '='  */
#line 365 "/mnt/d/dbcodes/rmdb-main/src/parser/yacc.y"
    {
        (yyval.sv_comp_op) = SV_OP_EQ;
    }
#line 2189 "/mnt/d/dbcodes/rmdb-main/src/parser/yacc.tab.cpp"
    break;

  case 62: /* op: '<'  */
#line 369 "/mnt/d/dbcodes/rmdb-main/src/parser/yacc.y"
    {
        (yyval.sv_comp_op) = SV_OP_LT;
    }
#line 2197 "/mnt/d/dbcodes/rmdb-main/src/parser/yacc.tab.cpp"
    break;

  case 63: /* op: '>'  */
#line 373 "/mnt/d/dbcodes/rmdb-main/src/parser/yacc.y"
    {
        (yyval.sv_comp_op) = SV_OP_GT;
    }
#line 2205 "/mnt/d/dbcodes/rmdb-main/src/parser/yacc.tab.cpp"
    break;

  case 64: /* op: NEQ  */
#line 377 "/mnt/d/dbcodes/rmdb-main/src/parser/yacc.y"
    {
        (yyval.sv_comp_op) = SV_OP_NE;
    }
#line 2213 "/mnt/d/dbcodes/rmdb-main/src/parser/yacc.tab.cpp"
    break;

  case 65: /* op: LEQ  */
#line 381 "/mnt/d/dbcodes/rmdb-main/src/parser/yacc.y"
    {
        (yyval.sv_comp_op) = SV_OP_LE;
    }
#line 2221 "/mnt/d/dbcodes/rmdb-main/src/parser/yacc.tab.cpp"
    break;

  case 66: /* op: GEQ  */
#line 385 "/mnt/d/dbcodes/rmdb-main/src/parser/yacc.y"
    {
        (yyval.sv_comp_op) = SV_OP_GE;
    }
#line 2229 "/mnt/d/dbcodes/rmdb-main/src/parser/yacc.tab.cpp"
    break;

  case 67: /* expr: value  */
#line 392 "/mnt/d/dbcodes/rmdb-main/src/parser/yacc.y"
    {
        (yyval.sv_expr) = std::static_pointer_cast<Expr>((yyvsp[0].sv_val));
    }
#line 2237 "/mnt/d/dbcodes/rmdb-main/src/parser/yacc.tab.cpp"
    break;

  case 68: /* expr: col  */
#line 396 "/mnt/d/dbcodes/rmdb-main/src/parser/yacc.y"
    {
        (yyval.sv_expr) = std::static_pointer_cast<Expr>((yyvsp[0].sv_col));
    }
#line 2245 "/mnt/d/dbcodes/rmdb-main/src/parser/yacc.tab.cpp"
    break;

  case 69: /* setClauses: setClause  */
#line 403 "/mnt/d/dbcodes/rmdb-main/src/parser/yacc.y"
    {
        (yyval.sv_set_clauses) = std::vector<std::shared_ptr<SetClause>>{(yyvsp[0].sv_set_clause)};
    }
#line 2253 "/mnt/d/dbcodes/rmdb-main/src/parser/yacc.tab.cpp"
    break;

  case 70: /* setClauses: setClauses ',' setClause  */
#line 407 "/mnt/d/dbcodes/rmdb-main/src/parser/yacc.y"
    {
        (yyval.sv_set_clauses).push_back((yyvsp[0].sv_set_clause));
    }
#line 2261 "/mnt/d/dbcodes/rmdb-main/src/parser/yacc.tab.cpp"
    break;

  case 71: /* setClause: colName '=' value  */
#line 414 "/mnt/d/dbcodes/rmdb-main/src/parser/yacc.y"
    {
        (yyval.sv_set_clause) = std::make_shared<SetClause>((yyvsp[-2].sv_str), (yyvsp[0].sv_val));
    }
#line 2269 "/mnt/d/dbcodes/rmdb-main/src/parser/yacc.tab.cpp"
    break;

  case 72: /* newSelector: '*'  */
#line 429 "/mnt/d/dbcodes/rmdb-main/src/parser/yacc.y"
    {
        (yyval.sv_select_items) = {};
    }
#line 2277 "/mnt/d/dbcodes/rmdb-main/src/parser/yacc.tab.cpp"
    break;

  case 74: /* selectItemList: selectItem  */
#line 437 "/mnt/d/dbcodes/rmdb-main/src/parser/yacc.y"
    {
        (yyval.sv_select_items) = std::vector<std::shared_ptr<SelectItem>>{(yyvsp[0].sv_select_item)};
    }
#line 2285 "/mnt/d/dbcodes/rmdb-main/src/parser/yacc.tab.cpp"
    break;

  case 75: /* selectItemList: selectItemList ',' selectItem  */
#line 441 "/mnt/d/dbcodes/rmdb-main/src/parser/yacc.y"
    {
        (yyval.sv_select_items).push_back((yyvsp[0].sv_select_item));
    }
#line 2293 "/mnt/d/dbcodes/rmdb-main/src/parser/yacc.tab.cpp"
    break;

  case 76: /* selectItem: col  */
#line 448 "/mnt/d/dbcodes/rmdb-main/src/parser/yacc.y"
    {
        (yyval.sv_select_item) = std::make_shared<SelectItem>((yyvsp[0].sv_col));
    }
#line 2301 "/mnt/d/dbcodes/rmdb-main/src/parser/yacc.tab.cpp"
    break;

  case 77: /* selectItem: col AS colName  */
#line 452 "/mnt/d/dbcodes/rmdb-main/src/parser/yacc.y"
    {
        (yyval.sv_select_item) = std::make_shared<SelectItem>((yyvsp[-2].sv_col), (yyvsp[0].sv_str));
    }
#line 2309 "/mnt/d/dbcodes/rmdb-main/src/parser/yacc.tab.cpp"
    break;

  case 78: /* selectItem: aggregateItem  */
#line 456 "/mnt/d/dbcodes/rmdb-main/src/parser/yacc.y"
    {
        (yyval.sv_select_item) = (yyvsp[0].sv_select_item);
    }
#line 2317 "/mnt/d/dbcodes/rmdb-main/src/parser/yacc.tab.cpp"
    break;

  case 79: /* selectItem: aggregateItem AS colName  */
#line 460 "/mnt/d/dbcodes/rmdb-main/src/parser/yacc.y"
    {
        (yyvsp[-2].sv_select_item)->alias = (yyvsp[0].sv_str);
        (yyval.sv_select_item) = (yyvsp[-2].sv_select_item);
    }
#line 2326 "/mnt/d/dbcodes/rmdb-main/src/parser/yacc.tab.cpp"
    break;

  case 80: /* aggregateItem: aggName '(' col ')'  */
#line 468 "/mnt/d/dbcodes/rmdb-main/src/parser/yacc.y"
    {
        (yyval.sv_select_item) = std::make_shared<SelectItem>((yyvsp[-3].sv_agg_type), (yyvsp[-1].sv_col), false);
    }
#line 2334 "/mnt/d/dbcodes/rmdb-main/src/parser/yacc.tab.cpp"
    break;

  case 81: /* aggregateItem: COUNT '(' col ')'  */
#line 472 "/mnt/d/dbcodes/rmdb-main/src/parser/yacc.y"
    {
        (yyval.sv_select_item) = std::make_shared<SelectItem>(AGG_COUNT, (yyvsp[-1].sv_col), false);
    }
#line 2342 "/mnt/d/dbcodes/rmdb-main/src/parser/yacc.tab.cpp"
    break;

  case 82: /* aggregateItem: COUNT '(' '*' ')'  */
#line 476 "/mnt/d/dbcodes/rmdb-main/src/parser/yacc.y"
    {
        (yyval.sv_select_item) = std::make_shared<SelectItem>(AGG_COUNT, nullptr, true);
    }
#line 2350 "/mnt/d/dbcodes/rmdb-main/src/parser/yacc.tab.cpp"
    break;

  case 83: /* aggName: MAX  */
#line 483 "/mnt/d/dbcodes/rmdb-main/src/parser/yacc.y"
    {
        (yyval.sv_agg_type) = AGG_MAX;
    }
#line 2358 "/mnt/d/dbcodes/rmdb-main/src/parser/yacc.tab.cpp"
    break;

  case 84: /* aggName: MIN  */
#line 487 "/mnt/d/dbcodes/rmdb-main/src/parser/yacc.y"
    {
        (yyval.sv_agg_type) = AGG_MIN;
    }
#line 2366 "/mnt/d/dbcodes/rmdb-main/src/parser/yacc.tab.cpp"
    break;

  case 85: /* aggName: SUM  */
#line 491 "/mnt/d/dbcodes/rmdb-main/src/parser/yacc.y"
    {
        (yyval.sv_agg_type) = AGG_SUM;
    }
#line 2374 "/mnt/d/dbcodes/rmdb-main/src/parser/yacc.tab.cpp"
    break;

  case 86: /* aggName: AVG  */
#line 495 "/mnt/d/dbcodes/rmdb-main/src/parser/yacc.y"
    {
        (yyval.sv_agg_type) = AGG_AVG;
    }
#line 2382 "/mnt/d/dbcodes/rmdb-main/src/parser/yacc.tab.cpp"
    break;

  case 87: /* fromList: tableRef  */
#line 517 "/mnt/d/dbcodes/rmdb-main/src/parser/yacc.y"
    {
        (yyval.sv_from) = std::make_shared<FromClause>();
        (yyval.sv_from)->table_refs.push_back((yyvsp[0].sv_table_ref));
    }
#line 2391 "/mnt/d/dbcodes/rmdb-main/src/parser/yacc.tab.cpp"
    break;

  case 88: /* fromList: fromList ',' tableRef  */
#line 522 "/mnt/d/dbcodes/rmdb-main/src/parser/yacc.y"
    {
        (yyval.sv_from) = (yyvsp[-2].sv_from);
        (yyval.sv_from)->table_refs.push_back((yyvsp[0].sv_table_ref));
    }
#line 2400 "/mnt/d/dbcodes/rmdb-main/src/parser/yacc.tab.cpp"
    break;

  case 89: /* fromList: fromList JOIN tableRef optJoinOnClause  */
#line 527 "/mnt/d/dbcodes/rmdb-main/src/parser/yacc.y"
    {
        (yyval.sv_from) = (yyvsp[-3].sv_from);
        (yyval.sv_from)->table_refs.push_back((yyvsp[-1].sv_table_ref));
        (yyval.sv_from)->join_conds.insert((yyval.sv_from)->join_conds.end(), (yyvsp[0].sv_join_conds).begin(), (yyvsp[0].sv_join_conds).end());
    }
#line 2410 "/mnt/d/dbcodes/rmdb-main/src/parser/yacc.tab.cpp"
    break;

  case 90: /* fromList: tableRef SEMI JOIN tableRef ON condition  */
#line 533 "/mnt/d/dbcodes/rmdb-main/src/parser/yacc.y"
    {
        (yyval.sv_from) = std::make_shared<FromClause>();
        (yyval.sv_from)->table_refs.push_back((yyvsp[-5].sv_table_ref));
        (yyval.sv_from)->table_refs.push_back((yyvsp[-2].sv_table_ref));
        (yyval.sv_from)->is_semi_join = true;
        (yyval.sv_from)->semi_conds.push_back((yyvsp[0].sv_cond));
    }
#line 2422 "/mnt/d/dbcodes/rmdb-main/src/parser/yacc.tab.cpp"
    break;

  case 91: /* optJoinOnClause: ON whereClause  */
#line 544 "/mnt/d/dbcodes/rmdb-main/src/parser/yacc.y"
    {
        (yyval.sv_join_conds) = (yyvsp[0].sv_conds);
    }
#line 2430 "/mnt/d/dbcodes/rmdb-main/src/parser/yacc.tab.cpp"
    break;

  case 92: /* optJoinOnClause: %empty  */
#line 547 "/mnt/d/dbcodes/rmdb-main/src/parser/yacc.y"
                      { (yyval.sv_join_conds) = {}; }
#line 2436 "/mnt/d/dbcodes/rmdb-main/src/parser/yacc.tab.cpp"
    break;

  case 93: /* tableRef: tbName  */
#line 552 "/mnt/d/dbcodes/rmdb-main/src/parser/yacc.y"
    {
        (yyval.sv_table_ref) = std::make_shared<TableRef>((yyvsp[0].sv_str), "");
    }
#line 2444 "/mnt/d/dbcodes/rmdb-main/src/parser/yacc.tab.cpp"
    break;

  case 94: /* tableRef: tbName tbName  */
#line 556 "/mnt/d/dbcodes/rmdb-main/src/parser/yacc.y"
    {
        (yyval.sv_table_ref) = std::make_shared<TableRef>((yyvsp[-1].sv_str), (yyvsp[0].sv_str));
    }
#line 2452 "/mnt/d/dbcodes/rmdb-main/src/parser/yacc.tab.cpp"
    break;

  case 95: /* tableRef: tbName AS tbName  */
#line 560 "/mnt/d/dbcodes/rmdb-main/src/parser/yacc.y"
    {
        (yyval.sv_table_ref) = std::make_shared<TableRef>((yyvsp[-2].sv_str), (yyvsp[0].sv_str));
    }
#line 2460 "/mnt/d/dbcodes/rmdb-main/src/parser/yacc.tab.cpp"
    break;

  case 96: /* tableRef: '(' unionSelectList ')' AS tbName  */
#line 564 "/mnt/d/dbcodes/rmdb-main/src/parser/yacc.y"
    {
        (yyval.sv_table_ref) = std::make_shared<TableRef>((yyvsp[-3].sv_select_stmts), (yyvsp[0].sv_str));
    }
#line 2468 "/mnt/d/dbcodes/rmdb-main/src/parser/yacc.tab.cpp"
    break;

  case 97: /* tableRef: '(' unionSelectList ')' tbName  */
#line 568 "/mnt/d/dbcodes/rmdb-main/src/parser/yacc.y"
    {
        (yyval.sv_table_ref) = std::make_shared<TableRef>((yyvsp[-2].sv_select_stmts), (yyvsp[0].sv_str));
    }
#line 2476 "/mnt/d/dbcodes/rmdb-main/src/parser/yacc.tab.cpp"
    break;

  case 98: /* opt_order_clause: ORDER BY order_clause  */
#line 575 "/mnt/d/dbcodes/rmdb-main/src/parser/yacc.y"
    { 
        (yyval.sv_orderby) = (yyvsp[0].sv_orderby); 
    }
#line 2484 "/mnt/d/dbcodes/rmdb-main/src/parser/yacc.tab.cpp"
    break;

  case 99: /* opt_order_clause: %empty  */
#line 578 "/mnt/d/dbcodes/rmdb-main/src/parser/yacc.y"
                      { (yyval.sv_orderby) = nullptr; }
#line 2490 "/mnt/d/dbcodes/rmdb-main/src/parser/yacc.tab.cpp"
    break;

  case 100: /* order_clause: order_item_list  */
#line 583 "/mnt/d/dbcodes/rmdb-main/src/parser/yacc.y"
    { 
        (yyval.sv_orderby) = std::make_shared<OrderBy>((yyvsp[0].sv_orderby_items));
    }
#line 2498 "/mnt/d/dbcodes/rmdb-main/src/parser/yacc.tab.cpp"
    break;

  case 101: /* order_item_list: order_item  */
#line 590 "/mnt/d/dbcodes/rmdb-main/src/parser/yacc.y"
    {
        (yyval.sv_orderby_items) = std::vector<std::shared_ptr<OrderByItem>>{(yyvsp[0].sv_orderby_item)};
    }
#line 2506 "/mnt/d/dbcodes/rmdb-main/src/parser/yacc.tab.cpp"
    break;

  case 102: /* order_item_list: order_item_list ',' order_item  */
#line 594 "/mnt/d/dbcodes/rmdb-main/src/parser/yacc.y"
    {
        (yyval.sv_orderby_items).push_back((yyvsp[0].sv_orderby_item));
    }
#line 2514 "/mnt/d/dbcodes/rmdb-main/src/parser/yacc.tab.cpp"
    break;

  case 103: /* order_item: col opt_asc_desc  */
#line 601 "/mnt/d/dbcodes/rmdb-main/src/parser/yacc.y"
    {
        (yyval.sv_orderby_item) = std::make_shared<OrderByItem>((yyvsp[-1].sv_col), (yyvsp[0].sv_orderby_dir));
    }
#line 2522 "/mnt/d/dbcodes/rmdb-main/src/parser/yacc.tab.cpp"
    break;

  case 104: /* opt_asc_desc: ASC  */
#line 607 "/mnt/d/dbcodes/rmdb-main/src/parser/yacc.y"
                 { (yyval.sv_orderby_dir) = OrderBy_ASC;     }
#line 2528 "/mnt/d/dbcodes/rmdb-main/src/parser/yacc.tab.cpp"
    break;

  case 105: /* opt_asc_desc: DESC  */
#line 608 "/mnt/d/dbcodes/rmdb-main/src/parser/yacc.y"
                 { (yyval.sv_orderby_dir) = OrderBy_DESC;    }
#line 2534 "/mnt/d/dbcodes/rmdb-main/src/parser/yacc.tab.cpp"
    break;

  case 106: /* opt_asc_desc: %empty  */
#line 609 "/mnt/d/dbcodes/rmdb-main/src/parser/yacc.y"
            { (yyval.sv_orderby_dir) = OrderBy_DEFAULT; }
#line 2540 "/mnt/d/dbcodes/rmdb-main/src/parser/yacc.tab.cpp"
    break;

  case 107: /* optGroupClause: GROUP BY colList  */
#line 614 "/mnt/d/dbcodes/rmdb-main/src/parser/yacc.y"
    {
        (yyval.sv_cols) = (yyvsp[0].sv_cols);
    }
#line 2548 "/mnt/d/dbcodes/rmdb-main/src/parser/yacc.tab.cpp"
    break;

  case 108: /* optGroupClause: %empty  */
#line 617 "/mnt/d/dbcodes/rmdb-main/src/parser/yacc.y"
                      { (yyval.sv_cols) = {}; }
#line 2554 "/mnt/d/dbcodes/rmdb-main/src/parser/yacc.tab.cpp"
    break;

  case 109: /* optHavingClause: HAVING havingClause  */
#line 622 "/mnt/d/dbcodes/rmdb-main/src/parser/yacc.y"
    {
        (yyval.sv_havings) = (yyvsp[0].sv_havings);
    }
#line 2562 "/mnt/d/dbcodes/rmdb-main/src/parser/yacc.tab.cpp"
    break;

  case 110: /* optHavingClause: %empty  */
#line 625 "/mnt/d/dbcodes/rmdb-main/src/parser/yacc.y"
                      { (yyval.sv_havings) = {}; }
#line 2568 "/mnt/d/dbcodes/rmdb-main/src/parser/yacc.tab.cpp"
    break;

  case 111: /* havingClause: havingCondition  */
#line 630 "/mnt/d/dbcodes/rmdb-main/src/parser/yacc.y"
    {
        (yyval.sv_havings) = std::vector<std::shared_ptr<HavingExpr>>{(yyvsp[0].sv_having)};
    }
#line 2576 "/mnt/d/dbcodes/rmdb-main/src/parser/yacc.tab.cpp"
    break;

  case 112: /* havingClause: havingClause AND havingCondition  */
#line 634 "/mnt/d/dbcodes/rmdb-main/src/parser/yacc.y"
    {
        (yyval.sv_havings).push_back((yyvsp[0].sv_having));
    }
#line 2584 "/mnt/d/dbcodes/rmdb-main/src/parser/yacc.tab.cpp"
    break;

  case 113: /* havingCondition: havingLhs op value  */
#line 641 "/mnt/d/dbcodes/rmdb-main/src/parser/yacc.y"
    {
        (yyval.sv_having) = std::make_shared<HavingExpr>((yyvsp[-2].sv_select_item), (yyvsp[-1].sv_comp_op), (yyvsp[0].sv_val));
    }
#line 2592 "/mnt/d/dbcodes/rmdb-main/src/parser/yacc.tab.cpp"
    break;

  case 114: /* havingLhs: aggregateItem  */
#line 648 "/mnt/d/dbcodes/rmdb-main/src/parser/yacc.y"
    {
        (yyval.sv_select_item) = (yyvsp[0].sv_select_item);
    }
#line 2600 "/mnt/d/dbcodes/rmdb-main/src/parser/yacc.tab.cpp"
    break;

  case 115: /* optLimitClause: LIMIT VALUE_INT  */
#line 655 "/mnt/d/dbcodes/rmdb-main/src/parser/yacc.y"
    {
        (yyval.sv_int) = (yyvsp[0].sv_int);
    }
#line 2608 "/mnt/d/dbcodes/rmdb-main/src/parser/yacc.tab.cpp"
    break;

  case 116: /* optLimitClause: %empty  */
#line 658 "/mnt/d/dbcodes/rmdb-main/src/parser/yacc.y"
                      { (yyval.sv_int) = -1; }
#line 2614 "/mnt/d/dbcodes/rmdb-main/src/parser/yacc.tab.cpp"
    break;

  case 117: /* set_knob_type: ENABLE_NESTLOOP  */
#line 662 "/mnt/d/dbcodes/rmdb-main/src/parser/yacc.y"
                    { (yyval.sv_setKnobType) = EnableNestLoop; }
#line 2620 "/mnt/d/dbcodes/rmdb-main/src/parser/yacc.tab.cpp"
    break;

  case 118: /* set_knob_type: ENABLE_SORTMERGE  */
#line 663 "/mnt/d/dbcodes/rmdb-main/src/parser/yacc.y"
                         { (yyval.sv_setKnobType) = EnableSortMerge; }
#line 2626 "/mnt/d/dbcodes/rmdb-main/src/parser/yacc.tab.cpp"
    break;


#line 2630 "/mnt/d/dbcodes/rmdb-main/src/parser/yacc.tab.cpp"

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
      {
        yypcontext_t yyctx
          = {yyssp, yytoken, &yylloc};
        char const *yymsgp = YY_("syntax error");
        int yysyntax_error_status;
        yysyntax_error_status = yysyntax_error (&yymsg_alloc, &yymsg, &yyctx);
        if (yysyntax_error_status == 0)
          yymsgp = yymsg;
        else if (yysyntax_error_status == -1)
          {
            if (yymsg != yymsgbuf)
              YYSTACK_FREE (yymsg);
            yymsg = YY_CAST (char *,
                             YYSTACK_ALLOC (YY_CAST (YYSIZE_T, yymsg_alloc)));
            if (yymsg)
              {
                yysyntax_error_status
                  = yysyntax_error (&yymsg_alloc, &yymsg, &yyctx);
                yymsgp = yymsg;
              }
            else
              {
                yymsg = yymsgbuf;
                yymsg_alloc = sizeof yymsgbuf;
                yysyntax_error_status = YYENOMEM;
              }
          }
        yyerror (&yylloc, yymsgp);
        if (yysyntax_error_status == YYENOMEM)
          YYNOMEM;
      }
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
                  YY_ACCESSING_SYMBOL (yystate), yyvsp, yylsp);
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
  yyerror (&yylloc, YY_("memory exhausted"));
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
                  yytoken, &yylval, &yylloc);
    }
  /* Do not reclaim the symbols of the rule whose action triggered
     this YYABORT or YYACCEPT.  */
  YYPOPSTACK (yylen);
  YY_STACK_PRINT (yyss, yyssp);
  while (yyssp != yyss)
    {
      yydestruct ("Cleanup: popping",
                  YY_ACCESSING_SYMBOL (+*yyssp), yyvsp, yylsp);
      YYPOPSTACK (1);
    }
#ifndef yyoverflow
  if (yyss != yyssa)
    YYSTACK_FREE (yyss);
#endif
  if (yymsg != yymsgbuf)
    YYSTACK_FREE (yymsg);
  return yyresult;
}

#line 669 "/mnt/d/dbcodes/rmdb-main/src/parser/yacc.y"

