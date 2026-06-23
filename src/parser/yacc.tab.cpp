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
  YYSYMBOL_DATETIME = 28,                  /* DATETIME  */
  YYSYMBOL_CHAR = 29,                      /* CHAR  */
  YYSYMBOL_FLOAT = 30,                     /* FLOAT  */
  YYSYMBOL_INDEX = 31,                     /* INDEX  */
  YYSYMBOL_AND = 32,                       /* AND  */
  YYSYMBOL_JOIN = 33,                      /* JOIN  */
  YYSYMBOL_SEMI = 34,                      /* SEMI  */
  YYSYMBOL_ON = 35,                        /* ON  */
  YYSYMBOL_GROUP = 36,                     /* GROUP  */
  YYSYMBOL_HAVING = 37,                    /* HAVING  */
  YYSYMBOL_LIMIT = 38,                     /* LIMIT  */
  YYSYMBOL_AS = 39,                        /* AS  */
  YYSYMBOL_EXPLAIN = 40,                   /* EXPLAIN  */
  YYSYMBOL_ANALYZE = 41,                   /* ANALYZE  */
  YYSYMBOL_UNION = 42,                     /* UNION  */
  YYSYMBOL_EXIT = 43,                      /* EXIT  */
  YYSYMBOL_HELP = 44,                      /* HELP  */
  YYSYMBOL_TXN_BEGIN = 45,                 /* TXN_BEGIN  */
  YYSYMBOL_TXN_COMMIT = 46,                /* TXN_COMMIT  */
  YYSYMBOL_TXN_ABORT = 47,                 /* TXN_ABORT  */
  YYSYMBOL_TXN_ROLLBACK = 48,              /* TXN_ROLLBACK  */
  YYSYMBOL_ORDER_BY = 49,                  /* ORDER_BY  */
  YYSYMBOL_ENABLE_NESTLOOP = 50,           /* ENABLE_NESTLOOP  */
  YYSYMBOL_ENABLE_SORTMERGE = 51,          /* ENABLE_SORTMERGE  */
  YYSYMBOL_MAX = 52,                       /* MAX  */
  YYSYMBOL_MIN = 53,                       /* MIN  */
  YYSYMBOL_COUNT = 54,                     /* COUNT  */
  YYSYMBOL_SUM = 55,                       /* SUM  */
  YYSYMBOL_AVG = 56,                       /* AVG  */
  YYSYMBOL_LEQ = 57,                       /* LEQ  */
  YYSYMBOL_NEQ = 58,                       /* NEQ  */
  YYSYMBOL_GEQ = 59,                       /* GEQ  */
  YYSYMBOL_T_EOF = 60,                     /* T_EOF  */
  YYSYMBOL_IDENTIFIER = 61,                /* IDENTIFIER  */
  YYSYMBOL_VALUE_STRING = 62,              /* VALUE_STRING  */
  YYSYMBOL_VALUE_BIGINT = 63,              /* VALUE_BIGINT  */
  YYSYMBOL_VALUE_INT = 64,                 /* VALUE_INT  */
  YYSYMBOL_VALUE_FLOAT = 65,               /* VALUE_FLOAT  */
  YYSYMBOL_VALUE_BOOL = 66,                /* VALUE_BOOL  */
  YYSYMBOL_67_ = 67,                       /* ';'  */
  YYSYMBOL_68_ = 68,                       /* '='  */
  YYSYMBOL_69_ = 69,                       /* '('  */
  YYSYMBOL_70_ = 70,                       /* ')'  */
  YYSYMBOL_71_ = 71,                       /* ','  */
  YYSYMBOL_72_ = 72,                       /* '.'  */
  YYSYMBOL_73_ = 73,                       /* '<'  */
  YYSYMBOL_74_ = 74,                       /* '>'  */
  YYSYMBOL_75_ = 75,                       /* '*'  */
  YYSYMBOL_YYACCEPT = 76,                  /* $accept  */
  YYSYMBOL_start = 77,                     /* start  */
  YYSYMBOL_stmt = 78,                      /* stmt  */
  YYSYMBOL_txnStmt = 79,                   /* txnStmt  */
  YYSYMBOL_dbStmt = 80,                    /* dbStmt  */
  YYSYMBOL_setStmt = 81,                   /* setStmt  */
  YYSYMBOL_ddl = 82,                       /* ddl  */
  YYSYMBOL_dml = 83,                       /* dml  */
  YYSYMBOL_selectStmt = 84,                /* selectStmt  */
  YYSYMBOL_plainSelectStmt = 85,           /* plainSelectStmt  */
  YYSYMBOL_unionSelectList = 86,           /* unionSelectList  */
  YYSYMBOL_unionSelect = 87,               /* unionSelect  */
  YYSYMBOL_fieldList = 88,                 /* fieldList  */
  YYSYMBOL_colNameList = 89,               /* colNameList  */
  YYSYMBOL_field = 90,                     /* field  */
  YYSYMBOL_type = 91,                      /* type  */
  YYSYMBOL_valueList = 92,                 /* valueList  */
  YYSYMBOL_value = 93,                     /* value  */
  YYSYMBOL_condition = 94,                 /* condition  */
  YYSYMBOL_optWhereClause = 95,            /* optWhereClause  */
  YYSYMBOL_whereClause = 96,               /* whereClause  */
  YYSYMBOL_col = 97,                       /* col  */
  YYSYMBOL_colList = 98,                   /* colList  */
  YYSYMBOL_op = 99,                        /* op  */
  YYSYMBOL_expr = 100,                     /* expr  */
  YYSYMBOL_setClauses = 101,               /* setClauses  */
  YYSYMBOL_setClause = 102,                /* setClause  */
  YYSYMBOL_newSelector = 103,              /* newSelector  */
  YYSYMBOL_selectItemList = 104,           /* selectItemList  */
  YYSYMBOL_selectItem = 105,               /* selectItem  */
  YYSYMBOL_aggregateItem = 106,            /* aggregateItem  */
  YYSYMBOL_aggName = 107,                  /* aggName  */
  YYSYMBOL_fromList = 108,                 /* fromList  */
  YYSYMBOL_optJoinOnClause = 109,          /* optJoinOnClause  */
  YYSYMBOL_tableRef = 110,                 /* tableRef  */
  YYSYMBOL_opt_order_clause = 111,         /* opt_order_clause  */
  YYSYMBOL_order_clause = 112,             /* order_clause  */
  YYSYMBOL_order_item_list = 113,          /* order_item_list  */
  YYSYMBOL_order_item = 114,               /* order_item  */
  YYSYMBOL_opt_asc_desc = 115,             /* opt_asc_desc  */
  YYSYMBOL_optGroupClause = 116,           /* optGroupClause  */
  YYSYMBOL_optHavingClause = 117,          /* optHavingClause  */
  YYSYMBOL_havingClause = 118,             /* havingClause  */
  YYSYMBOL_havingCondition = 119,          /* havingCondition  */
  YYSYMBOL_havingLhs = 120,                /* havingLhs  */
  YYSYMBOL_optLimitClause = 121,           /* optLimitClause  */
  YYSYMBOL_set_knob_type = 122,            /* set_knob_type  */
  YYSYMBOL_tbName = 123,                   /* tbName  */
  YYSYMBOL_colName = 124                   /* colName  */
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
#define YYLAST   209

/* YYNTOKENS -- Number of terminals.  */
#define YYNTOKENS  76
/* YYNNTS -- Number of nonterminals.  */
#define YYNNTS  49
/* YYNRULES -- Number of rules.  */
#define YYNRULES  121
/* YYNSTATES -- Number of states.  */
#define YYNSTATES  219

/* YYMAXUTOK -- Last valid token kind.  */
#define YYMAXUTOK   321


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
      69,    70,    75,     2,    71,     2,    72,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,    67,
      73,    68,    74,     2,     2,     2,     2,     2,     2,     2,
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
      65,    66
};

#if YYDEBUG
/* YYRLINE[YYN] -- Source line where rule number YYN was defined.  */
static const yytype_int16 yyrline[] =
{
       0,    74,    74,    79,    84,    89,    97,    98,    99,   100,
     101,   105,   109,   113,   117,   124,   128,   135,   139,   143,
     150,   154,   158,   162,   166,   173,   177,   181,   185,   192,
     196,   200,   207,   215,   219,   227,   234,   238,   245,   249,
     256,   263,   267,   271,   275,   279,   286,   290,   297,   301,
     305,   309,   313,   320,   327,   328,   335,   339,   346,   350,
     357,   361,   368,   372,   376,   380,   384,   388,   395,   399,
     406,   410,   417,   432,   436,   440,   444,   451,   455,   459,
     463,   471,   475,   479,   486,   490,   494,   498,   520,   525,
     530,   536,   547,   551,   555,   559,   563,   567,   571,   578,
     582,   586,   593,   597,   604,   611,   612,   613,   617,   621,
     625,   629,   633,   637,   644,   651,   658,   662,   666,   667,
     670,   672
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
  "BIGINT", "DATETIME", "CHAR", "FLOAT", "INDEX", "AND", "JOIN", "SEMI",
  "ON", "GROUP", "HAVING", "LIMIT", "AS", "EXPLAIN", "ANALYZE", "UNION",
  "EXIT", "HELP", "TXN_BEGIN", "TXN_COMMIT", "TXN_ABORT", "TXN_ROLLBACK",
  "ORDER_BY", "ENABLE_NESTLOOP", "ENABLE_SORTMERGE", "MAX", "MIN", "COUNT",
  "SUM", "AVG", "LEQ", "NEQ", "GEQ", "T_EOF", "IDENTIFIER", "VALUE_STRING",
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

#define YYPACT_NINF (-162)

#define yypact_value_is_default(Yyn) \
  ((Yyn) == YYPACT_NINF)

#define YYTABLE_NINF (-121)

#define yytable_value_is_error(Yyn) \
  0

/* YYPACT[STATE-NUM] -- Index in YYTABLE of the portion describing
   STATE-NUM.  */
static const yytype_int16 yypact[] =
{
      66,    16,    18,    24,   -36,    30,    41,   -36,    -5,    27,
      10,  -162,  -162,  -162,  -162,  -162,  -162,  -162,    60,    -1,
    -162,  -162,  -162,  -162,  -162,  -162,  -162,  -162,    64,   -36,
     -36,   -36,   -36,  -162,  -162,   -36,   -36,    67,    69,  -162,
    -162,    19,  -162,  -162,    46,  -162,  -162,    47,  -162,    86,
     115,    58,  -162,    91,    62,    87,  -162,   120,  -162,  -162,
    -162,   -36,    89,    92,  -162,    94,   149,   147,   104,   144,
     101,   -27,   104,     3,    44,   104,   107,   104,  -162,  -162,
     104,   104,   104,   102,   107,  -162,  -162,   -15,  -162,   105,
      14,  -162,    99,   106,  -162,   120,   -10,   136,   -17,  -162,
    -162,   108,  -162,    23,  -162,   114,    33,  -162,    37,    85,
    -162,   143,    59,   104,  -162,    85,   156,  -162,  -162,  -162,
    -162,   -29,  -162,     3,     3,   145,   146,   -36,  -162,  -162,
    -162,   104,  -162,  -162,  -162,   111,  -162,  -162,  -162,   104,
    -162,  -162,  -162,  -162,  -162,  -162,    52,  -162,   107,  -162,
    -162,  -162,  -162,  -162,  -162,    73,  -162,  -162,  -162,   120,
      -8,   148,  -162,   166,   150,     3,  -162,  -162,   121,  -162,
    -162,    85,  -162,  -162,  -162,  -162,  -162,   -36,  -162,   107,
    -162,   107,   100,   169,   151,   118,  -162,  -162,   143,  -162,
     123,  -162,   157,  -162,    59,   175,   154,   107,  -162,   107,
     100,    85,   107,   131,  -162,  -162,  -162,  -162,  -162,    28,
    -162,   125,  -162,  -162,  -162,  -162,  -162,   107,  -162
};

/* YYDEFACT[STATE-NUM] -- Default reduction number in state STATE-NUM.
   Performed when YYTABLE does not specify something else to do.  Zero
   means the default is an error.  */
static const yytype_int8 yydefact[] =
{
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     4,     3,    11,    12,    13,    14,     5,     0,     0,
       9,     6,    10,     7,     8,    28,    29,    15,     0,     0,
       0,     0,     0,   120,    22,     0,     0,     0,     0,   118,
     119,     0,    84,    85,     0,    86,    87,   121,    73,    77,
       0,    74,    75,    79,     0,     0,    59,     0,    30,     1,
       2,     0,     0,     0,    21,     0,     0,    54,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,    31,    16,
       0,     0,     0,     0,     0,    26,   121,    54,    70,     0,
       0,    17,     0,     0,    78,     0,    54,    88,    94,    76,
      80,     0,    58,     0,    36,     0,     0,    38,     0,     0,
      56,    55,     0,     0,    27,     0,     0,    19,    83,    82,
      35,     0,    33,     0,     0,   109,     0,     0,    95,    81,
      20,     0,    41,    44,    45,     0,    43,    40,    23,     0,
      24,    51,    50,    48,    49,    52,     0,    46,     0,    66,
      65,    67,    62,    63,    64,     0,    71,    72,    18,     0,
       0,    93,    89,     0,   111,     0,    96,    37,     0,    39,
      25,     0,    57,    68,    69,    53,    34,     0,    98,     0,
      90,     0,     0,   100,     0,     0,    47,    97,    92,    60,
     108,   115,   110,   112,     0,     0,   117,     0,    42,     0,
       0,     0,     0,     0,    32,    91,    61,   113,   114,   107,
      99,   101,   102,   116,   106,   105,   104,     0,   103
};

/* YYPGOTO[NTERM-NUM].  */
static const yytype_int16 yypgoto[] =
{
    -162,  -162,  -162,  -162,  -162,  -162,  -162,  -162,  -162,     6,
    -162,    38,  -162,   116,    68,  -162,  -162,  -112,  -140,     5,
      21,    -9,  -162,     7,  -162,  -162,    90,  -162,  -162,   128,
    -161,  -162,  -162,  -162,  -113,  -162,  -162,  -162,   -13,  -162,
    -162,  -162,  -162,     9,  -162,  -162,  -162,    -3,   -63
};

/* YYDEFGOTO[NTERM-NUM].  */
static const yytype_uint8 yydefgoto[] =
{
       0,    18,    19,    20,    21,    22,    23,    24,    25,   120,
     121,   122,   103,   106,   104,   137,   146,   147,   110,    85,
     111,   112,   190,   155,   175,    87,    88,    50,    51,    52,
      53,    54,    96,   180,    97,   196,   210,   211,   212,   216,
     164,   183,   192,   193,   194,   204,    41,    55,    56
};

/* YYTABLE[YYPACT[STATE-NUM]] -- What to do in state STATE-NUM.  If
   positive, shift that token.  If negative, reduce the rule whose
   number is the opposite.  If YYTABLE_NINF, syntax error.  */
static const yytype_int16 yytable[] =
{
      49,    34,    84,   157,    37,    89,    26,    84,   172,    94,
     161,   162,   100,   159,   102,    38,    58,   105,   107,   107,
      27,   191,   127,   123,    29,    33,    62,    63,    64,    65,
      31,   177,    66,    67,    47,     9,   214,   116,   117,   191,
      35,   160,   215,   173,    33,    39,    40,    28,    92,    30,
      89,    57,   184,    33,    36,    32,   113,   205,    79,   186,
      59,   124,    93,    78,    33,    49,    60,   101,   105,     1,
      98,     2,    95,     3,     4,     5,   169,    61,     6,    42,
      43,    44,    45,    46,     7,     8,    68,    70,    47,   208,
      69,     9,   114,   130,   131,   128,    42,    43,    44,    45,
      46,   125,    48,   138,   139,    47,    10,   140,   139,    11,
      12,    13,    14,    15,    16,    71,   149,   150,   151,  -120,
      98,    98,   170,   171,   166,    72,    17,   152,    73,    74,
      75,    76,   153,   154,    47,   141,   142,   143,   144,   145,
     132,   133,   134,   135,   136,     9,   174,   141,   142,   143,
     144,   145,    42,    43,    44,    45,    46,   178,    80,    77,
      83,    81,    98,    82,    84,    86,    90,    91,    47,   118,
     126,   109,   189,   115,   187,   148,   119,   158,   129,   165,
     168,   163,   181,   179,   195,   185,   197,   182,   198,   200,
     206,   202,   203,   209,   199,   213,   217,   176,   108,   167,
     188,   201,    99,   156,   218,     0,     0,     0,   209,   207
};

static const yytype_int16 yycheck[] =
{
       9,     4,    17,   115,     7,    68,     0,    17,   148,    72,
     123,   124,    75,    42,    77,    20,    10,    80,    81,    82,
       4,   182,    39,    33,     6,    61,    29,    30,    31,    32,
       6,    39,    35,    36,    61,    25,     8,    23,    24,   200,
      10,    70,    14,   155,    61,    50,    51,    31,    75,    31,
     113,    41,   165,    61,    13,    31,    71,   197,    61,   171,
       0,    71,    71,    57,    61,    74,    67,    76,   131,     3,
      73,     5,    69,     7,     8,     9,   139,    13,    12,    52,
      53,    54,    55,    56,    18,    19,    19,    68,    61,   201,
      21,    25,    87,    70,    71,    98,    52,    53,    54,    55,
      56,    96,    75,    70,    71,    61,    40,    70,    71,    43,
      44,    45,    46,    47,    48,    69,    57,    58,    59,    72,
     123,   124,    70,    71,   127,    39,    60,    68,    13,    71,
      39,    69,    73,    74,    61,    62,    63,    64,    65,    66,
      26,    27,    28,    29,    30,    25,   155,    62,    63,    64,
      65,    66,    52,    53,    54,    55,    56,   160,    69,    72,
      11,    69,   165,    69,    17,    61,    22,    66,    61,    70,
      34,    69,   181,    68,   177,    32,    70,    21,    70,    33,
      69,    36,    16,    35,    15,    64,    35,    37,    70,    32,
     199,    16,    38,   202,    71,    64,    71,   159,    82,   131,
     179,   194,    74,   113,   217,    -1,    -1,    -1,   217,   200
};

/* YYSTOS[STATE-NUM] -- The symbol kind of the accessing symbol of
   state STATE-NUM.  */
static const yytype_int8 yystos[] =
{
       0,     3,     5,     7,     8,     9,    12,    18,    19,    25,
      40,    43,    44,    45,    46,    47,    48,    60,    77,    78,
      79,    80,    81,    82,    83,    84,    85,     4,    31,     6,
      31,     6,    31,    61,   123,    10,    13,   123,    20,    50,
      51,   122,    52,    53,    54,    55,    56,    61,    75,    97,
     103,   104,   105,   106,   107,   123,   124,    41,    85,     0,
      67,    13,   123,   123,   123,   123,   123,   123,    19,    21,
      68,    69,    39,    13,    71,    39,    69,    72,    85,   123,
      69,    69,    69,    11,    17,    95,    61,   101,   102,   124,
      22,    66,    75,    97,   124,    69,   108,   110,   123,   105,
     124,    97,   124,    88,    90,   124,    89,   124,    89,    69,
      94,    96,    97,    71,    95,    68,    23,    24,    70,    70,
      85,    86,    87,    33,    71,    95,    34,    39,   123,    70,
      70,    71,    26,    27,    28,    29,    30,    91,    70,    71,
      70,    62,    63,    64,    65,    66,    92,    93,    32,    57,
      58,    59,    68,    73,    74,    99,   102,    93,    21,    42,
      70,   110,   110,    36,   116,    33,   123,    90,    69,   124,
      70,    71,    94,    93,    97,   100,    87,    39,   123,    35,
     109,    16,    37,   117,   110,    64,    93,   123,    96,    97,
      98,   106,   118,   119,   120,    15,   111,    35,    70,    71,
      32,    99,    16,    38,   121,    94,    97,   119,    93,    97,
     112,   113,   114,    64,     8,    14,   115,    71,   114
};

/* YYR1[RULE-NUM] -- Symbol kind of the left-hand side of rule RULE-NUM.  */
static const yytype_int8 yyr1[] =
{
       0,    76,    77,    77,    77,    77,    78,    78,    78,    78,
      78,    79,    79,    79,    79,    80,    80,    81,    81,    81,
      82,    82,    82,    82,    82,    83,    83,    83,    83,    84,
      84,    84,    85,    86,    86,    87,    88,    88,    89,    89,
      90,    91,    91,    91,    91,    91,    92,    92,    93,    93,
      93,    93,    93,    94,    95,    95,    96,    96,    97,    97,
      98,    98,    99,    99,    99,    99,    99,    99,   100,   100,
     101,   101,   102,   103,   103,   104,   104,   105,   105,   105,
     105,   106,   106,   106,   107,   107,   107,   107,   108,   108,
     108,   108,   109,   109,   110,   110,   110,   110,   110,   111,
     111,   112,   113,   113,   114,   115,   115,   115,   116,   116,
     117,   117,   118,   118,   119,   120,   121,   121,   122,   122,
     123,   124
};

/* YYR2[RULE-NUM] -- Number of symbols on the right-hand side of rule RULE-NUM.  */
static const yytype_int8 yyr2[] =
{
       0,     2,     2,     1,     1,     1,     1,     1,     1,     1,
       1,     1,     1,     1,     1,     2,     4,     4,     6,     5,
       6,     3,     2,     6,     6,     7,     4,     5,     1,     1,
       2,     3,     9,     1,     3,     1,     1,     3,     1,     3,
       2,     1,     4,     1,     1,     1,     1,     3,     1,     1,
       1,     1,     1,     3,     0,     2,     1,     3,     3,     1,
       1,     3,     1,     1,     1,     1,     1,     1,     1,     1,
       1,     3,     3,     1,     1,     1,     3,     1,     3,     1,
       3,     4,     4,     4,     1,     1,     1,     1,     1,     3,
       4,     6,     2,     0,     1,     2,     3,     5,     4,     3,
       0,     1,     1,     3,     2,     1,     1,     0,     3,     0,
       2,     0,     1,     3,     3,     1,     2,     0,     1,     1,
       1,     1
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
#line 1755 "/mnt/d/dbcodes/rmdb-main/src/parser/yacc.tab.cpp"
    break;

  case 3: /* start: HELP  */
#line 80 "/mnt/d/dbcodes/rmdb-main/src/parser/yacc.y"
    {
        parse_tree = std::make_shared<Help>();
        YYACCEPT;
    }
#line 1764 "/mnt/d/dbcodes/rmdb-main/src/parser/yacc.tab.cpp"
    break;

  case 4: /* start: EXIT  */
#line 85 "/mnt/d/dbcodes/rmdb-main/src/parser/yacc.y"
    {
        parse_tree = nullptr;
        YYACCEPT;
    }
#line 1773 "/mnt/d/dbcodes/rmdb-main/src/parser/yacc.tab.cpp"
    break;

  case 5: /* start: T_EOF  */
#line 90 "/mnt/d/dbcodes/rmdb-main/src/parser/yacc.y"
    {
        parse_tree = nullptr;
        YYACCEPT;
    }
#line 1782 "/mnt/d/dbcodes/rmdb-main/src/parser/yacc.tab.cpp"
    break;

  case 11: /* txnStmt: TXN_BEGIN  */
#line 106 "/mnt/d/dbcodes/rmdb-main/src/parser/yacc.y"
    {
        (yyval.sv_node) = std::make_shared<TxnBegin>();
    }
#line 1790 "/mnt/d/dbcodes/rmdb-main/src/parser/yacc.tab.cpp"
    break;

  case 12: /* txnStmt: TXN_COMMIT  */
#line 110 "/mnt/d/dbcodes/rmdb-main/src/parser/yacc.y"
    {
        (yyval.sv_node) = std::make_shared<TxnCommit>();
    }
#line 1798 "/mnt/d/dbcodes/rmdb-main/src/parser/yacc.tab.cpp"
    break;

  case 13: /* txnStmt: TXN_ABORT  */
#line 114 "/mnt/d/dbcodes/rmdb-main/src/parser/yacc.y"
    {
        (yyval.sv_node) = std::make_shared<TxnAbort>();
    }
#line 1806 "/mnt/d/dbcodes/rmdb-main/src/parser/yacc.tab.cpp"
    break;

  case 14: /* txnStmt: TXN_ROLLBACK  */
#line 118 "/mnt/d/dbcodes/rmdb-main/src/parser/yacc.y"
    {
        (yyval.sv_node) = std::make_shared<TxnRollback>();
    }
#line 1814 "/mnt/d/dbcodes/rmdb-main/src/parser/yacc.tab.cpp"
    break;

  case 15: /* dbStmt: SHOW TABLES  */
#line 125 "/mnt/d/dbcodes/rmdb-main/src/parser/yacc.y"
    {
        (yyval.sv_node) = std::make_shared<ShowTables>();
    }
#line 1822 "/mnt/d/dbcodes/rmdb-main/src/parser/yacc.tab.cpp"
    break;

  case 16: /* dbStmt: SHOW INDEX FROM tbName  */
#line 129 "/mnt/d/dbcodes/rmdb-main/src/parser/yacc.y"
    {
        (yyval.sv_node) = std::make_shared<ShowIndex>((yyvsp[0].sv_str));
    }
#line 1830 "/mnt/d/dbcodes/rmdb-main/src/parser/yacc.tab.cpp"
    break;

  case 17: /* setStmt: SET set_knob_type '=' VALUE_BOOL  */
#line 136 "/mnt/d/dbcodes/rmdb-main/src/parser/yacc.y"
    {
        (yyval.sv_node) = std::make_shared<SetStmt>((yyvsp[-2].sv_setKnobType), (yyvsp[0].sv_bool));
    }
#line 1838 "/mnt/d/dbcodes/rmdb-main/src/parser/yacc.tab.cpp"
    break;

  case 18: /* setStmt: SET TRANSACTION ISOLATION LEVEL SNAPSHOT ISOLATION  */
#line 140 "/mnt/d/dbcodes/rmdb-main/src/parser/yacc.y"
    {
        (yyval.sv_node) = std::make_shared<SetTransactionIsolation>(false);
    }
#line 1846 "/mnt/d/dbcodes/rmdb-main/src/parser/yacc.tab.cpp"
    break;

  case 19: /* setStmt: SET TRANSACTION ISOLATION LEVEL SERIALIZABLE  */
#line 144 "/mnt/d/dbcodes/rmdb-main/src/parser/yacc.y"
    {
        (yyval.sv_node) = std::make_shared<SetTransactionIsolation>(true);
    }
#line 1854 "/mnt/d/dbcodes/rmdb-main/src/parser/yacc.tab.cpp"
    break;

  case 20: /* ddl: CREATE TABLE tbName '(' fieldList ')'  */
#line 151 "/mnt/d/dbcodes/rmdb-main/src/parser/yacc.y"
    {
        (yyval.sv_node) = std::make_shared<CreateTable>((yyvsp[-3].sv_str), (yyvsp[-1].sv_fields));
    }
#line 1862 "/mnt/d/dbcodes/rmdb-main/src/parser/yacc.tab.cpp"
    break;

  case 21: /* ddl: DROP TABLE tbName  */
#line 155 "/mnt/d/dbcodes/rmdb-main/src/parser/yacc.y"
    {
        (yyval.sv_node) = std::make_shared<DropTable>((yyvsp[0].sv_str));
    }
#line 1870 "/mnt/d/dbcodes/rmdb-main/src/parser/yacc.tab.cpp"
    break;

  case 22: /* ddl: DESC tbName  */
#line 159 "/mnt/d/dbcodes/rmdb-main/src/parser/yacc.y"
    {
        (yyval.sv_node) = std::make_shared<DescTable>((yyvsp[0].sv_str));
    }
#line 1878 "/mnt/d/dbcodes/rmdb-main/src/parser/yacc.tab.cpp"
    break;

  case 23: /* ddl: CREATE INDEX tbName '(' colNameList ')'  */
#line 163 "/mnt/d/dbcodes/rmdb-main/src/parser/yacc.y"
    {
        (yyval.sv_node) = std::make_shared<CreateIndex>((yyvsp[-3].sv_str), (yyvsp[-1].sv_strs));
    }
#line 1886 "/mnt/d/dbcodes/rmdb-main/src/parser/yacc.tab.cpp"
    break;

  case 24: /* ddl: DROP INDEX tbName '(' colNameList ')'  */
#line 167 "/mnt/d/dbcodes/rmdb-main/src/parser/yacc.y"
    {
        (yyval.sv_node) = std::make_shared<DropIndex>((yyvsp[-3].sv_str), (yyvsp[-1].sv_strs));
    }
#line 1894 "/mnt/d/dbcodes/rmdb-main/src/parser/yacc.tab.cpp"
    break;

  case 25: /* dml: INSERT INTO tbName VALUES '(' valueList ')'  */
#line 174 "/mnt/d/dbcodes/rmdb-main/src/parser/yacc.y"
    {
        (yyval.sv_node) = std::make_shared<InsertStmt>((yyvsp[-4].sv_str), (yyvsp[-1].sv_vals));
    }
#line 1902 "/mnt/d/dbcodes/rmdb-main/src/parser/yacc.tab.cpp"
    break;

  case 26: /* dml: DELETE FROM tbName optWhereClause  */
#line 178 "/mnt/d/dbcodes/rmdb-main/src/parser/yacc.y"
    {
        (yyval.sv_node) = std::make_shared<DeleteStmt>((yyvsp[-1].sv_str), (yyvsp[0].sv_conds));
    }
#line 1910 "/mnt/d/dbcodes/rmdb-main/src/parser/yacc.tab.cpp"
    break;

  case 27: /* dml: UPDATE tbName SET setClauses optWhereClause  */
#line 182 "/mnt/d/dbcodes/rmdb-main/src/parser/yacc.y"
    {
        (yyval.sv_node) = std::make_shared<UpdateStmt>((yyvsp[-3].sv_str), (yyvsp[-1].sv_set_clauses), (yyvsp[0].sv_conds));
    }
#line 1918 "/mnt/d/dbcodes/rmdb-main/src/parser/yacc.tab.cpp"
    break;

  case 28: /* dml: selectStmt  */
#line 186 "/mnt/d/dbcodes/rmdb-main/src/parser/yacc.y"
    {
        (yyval.sv_node) = (yyvsp[0].sv_node);
    }
#line 1926 "/mnt/d/dbcodes/rmdb-main/src/parser/yacc.tab.cpp"
    break;

  case 29: /* selectStmt: plainSelectStmt  */
#line 193 "/mnt/d/dbcodes/rmdb-main/src/parser/yacc.y"
    {
        (yyval.sv_node) = (yyvsp[0].sv_select_stmt);
    }
#line 1934 "/mnt/d/dbcodes/rmdb-main/src/parser/yacc.tab.cpp"
    break;

  case 30: /* selectStmt: EXPLAIN plainSelectStmt  */
#line 197 "/mnt/d/dbcodes/rmdb-main/src/parser/yacc.y"
    {
        (yyval.sv_node) = std::make_shared<ExplainStmt>((yyvsp[0].sv_select_stmt));
    }
#line 1942 "/mnt/d/dbcodes/rmdb-main/src/parser/yacc.tab.cpp"
    break;

  case 31: /* selectStmt: EXPLAIN ANALYZE plainSelectStmt  */
#line 201 "/mnt/d/dbcodes/rmdb-main/src/parser/yacc.y"
    {
        (yyval.sv_node) = std::make_shared<ExplainStmt>((yyvsp[0].sv_select_stmt));
    }
#line 1950 "/mnt/d/dbcodes/rmdb-main/src/parser/yacc.tab.cpp"
    break;

  case 32: /* plainSelectStmt: SELECT newSelector FROM fromList optWhereClause optGroupClause optHavingClause opt_order_clause optLimitClause  */
#line 208 "/mnt/d/dbcodes/rmdb-main/src/parser/yacc.y"
    {
        (yyvsp[-4].sv_conds).insert((yyvsp[-4].sv_conds).end(), (yyvsp[-5].sv_from)->join_conds.begin(), (yyvsp[-5].sv_from)->join_conds.end());
        (yyval.sv_select_stmt) = std::make_shared<SelectStmt>((yyvsp[-7].sv_select_items), (yyvsp[-5].sv_from)->table_refs, (yyvsp[-4].sv_conds), (yyvsp[-3].sv_cols), (yyvsp[-2].sv_havings), (yyvsp[-1].sv_orderby), (yyvsp[0].sv_int), (yyvsp[-5].sv_from)->is_semi_join, (yyvsp[-5].sv_from)->semi_conds);
    }
#line 1959 "/mnt/d/dbcodes/rmdb-main/src/parser/yacc.tab.cpp"
    break;

  case 33: /* unionSelectList: unionSelect  */
#line 216 "/mnt/d/dbcodes/rmdb-main/src/parser/yacc.y"
    {
        (yyval.sv_select_stmts) = std::vector<std::shared_ptr<SelectStmt>>{(yyvsp[0].sv_select_stmt)};
    }
#line 1967 "/mnt/d/dbcodes/rmdb-main/src/parser/yacc.tab.cpp"
    break;

  case 34: /* unionSelectList: unionSelectList UNION unionSelect  */
#line 220 "/mnt/d/dbcodes/rmdb-main/src/parser/yacc.y"
    {
        (yyvsp[-2].sv_select_stmts).push_back((yyvsp[0].sv_select_stmt));
        (yyval.sv_select_stmts) = (yyvsp[-2].sv_select_stmts);
    }
#line 1976 "/mnt/d/dbcodes/rmdb-main/src/parser/yacc.tab.cpp"
    break;

  case 35: /* unionSelect: plainSelectStmt  */
#line 228 "/mnt/d/dbcodes/rmdb-main/src/parser/yacc.y"
    {
        (yyval.sv_select_stmt) = (yyvsp[0].sv_select_stmt);
    }
#line 1984 "/mnt/d/dbcodes/rmdb-main/src/parser/yacc.tab.cpp"
    break;

  case 36: /* fieldList: field  */
#line 235 "/mnt/d/dbcodes/rmdb-main/src/parser/yacc.y"
    {
        (yyval.sv_fields) = std::vector<std::shared_ptr<Field>>{(yyvsp[0].sv_field)};
    }
#line 1992 "/mnt/d/dbcodes/rmdb-main/src/parser/yacc.tab.cpp"
    break;

  case 37: /* fieldList: fieldList ',' field  */
#line 239 "/mnt/d/dbcodes/rmdb-main/src/parser/yacc.y"
    {
        (yyval.sv_fields).push_back((yyvsp[0].sv_field));
    }
#line 2000 "/mnt/d/dbcodes/rmdb-main/src/parser/yacc.tab.cpp"
    break;

  case 38: /* colNameList: colName  */
#line 246 "/mnt/d/dbcodes/rmdb-main/src/parser/yacc.y"
    {
        (yyval.sv_strs) = std::vector<std::string>{(yyvsp[0].sv_str)};
    }
#line 2008 "/mnt/d/dbcodes/rmdb-main/src/parser/yacc.tab.cpp"
    break;

  case 39: /* colNameList: colNameList ',' colName  */
#line 250 "/mnt/d/dbcodes/rmdb-main/src/parser/yacc.y"
    {
        (yyval.sv_strs).push_back((yyvsp[0].sv_str));
    }
#line 2016 "/mnt/d/dbcodes/rmdb-main/src/parser/yacc.tab.cpp"
    break;

  case 40: /* field: colName type  */
#line 257 "/mnt/d/dbcodes/rmdb-main/src/parser/yacc.y"
    {
        (yyval.sv_field) = std::make_shared<ColDef>((yyvsp[-1].sv_str), (yyvsp[0].sv_type_len));
    }
#line 2024 "/mnt/d/dbcodes/rmdb-main/src/parser/yacc.tab.cpp"
    break;

  case 41: /* type: INT  */
#line 264 "/mnt/d/dbcodes/rmdb-main/src/parser/yacc.y"
    {
        (yyval.sv_type_len) = std::make_shared<TypeLen>(SV_TYPE_INT, sizeof(int));
    }
#line 2032 "/mnt/d/dbcodes/rmdb-main/src/parser/yacc.tab.cpp"
    break;

  case 42: /* type: CHAR '(' VALUE_INT ')'  */
#line 268 "/mnt/d/dbcodes/rmdb-main/src/parser/yacc.y"
    {
        (yyval.sv_type_len) = std::make_shared<TypeLen>(SV_TYPE_STRING, (yyvsp[-1].sv_int));
    }
#line 2040 "/mnt/d/dbcodes/rmdb-main/src/parser/yacc.tab.cpp"
    break;

  case 43: /* type: FLOAT  */
#line 272 "/mnt/d/dbcodes/rmdb-main/src/parser/yacc.y"
    {
        (yyval.sv_type_len) = std::make_shared<TypeLen>(SV_TYPE_FLOAT, sizeof(float));
    }
#line 2048 "/mnt/d/dbcodes/rmdb-main/src/parser/yacc.tab.cpp"
    break;

  case 44: /* type: BIGINT  */
#line 276 "/mnt/d/dbcodes/rmdb-main/src/parser/yacc.y"
    {
        (yyval.sv_type_len) = std::make_shared<TypeLen>(SV_TYPE_BIGINT, sizeof(int64_t));
    }
#line 2056 "/mnt/d/dbcodes/rmdb-main/src/parser/yacc.tab.cpp"
    break;

  case 45: /* type: DATETIME  */
#line 280 "/mnt/d/dbcodes/rmdb-main/src/parser/yacc.y"
    {
        (yyval.sv_type_len) = std::make_shared<TypeLen>(SV_TYPE_DATETIME, sizeof(int64_t));
    }
#line 2064 "/mnt/d/dbcodes/rmdb-main/src/parser/yacc.tab.cpp"
    break;

  case 46: /* valueList: value  */
#line 287 "/mnt/d/dbcodes/rmdb-main/src/parser/yacc.y"
    {
        (yyval.sv_vals) = std::vector<std::shared_ptr<Value>>{(yyvsp[0].sv_val)};
    }
#line 2072 "/mnt/d/dbcodes/rmdb-main/src/parser/yacc.tab.cpp"
    break;

  case 47: /* valueList: valueList ',' value  */
#line 291 "/mnt/d/dbcodes/rmdb-main/src/parser/yacc.y"
    {
        (yyval.sv_vals).push_back((yyvsp[0].sv_val));
    }
#line 2080 "/mnt/d/dbcodes/rmdb-main/src/parser/yacc.tab.cpp"
    break;

  case 48: /* value: VALUE_INT  */
#line 298 "/mnt/d/dbcodes/rmdb-main/src/parser/yacc.y"
    {
        (yyval.sv_val) = std::make_shared<IntLit>((yyvsp[0].sv_int));
    }
#line 2088 "/mnt/d/dbcodes/rmdb-main/src/parser/yacc.tab.cpp"
    break;

  case 49: /* value: VALUE_FLOAT  */
#line 302 "/mnt/d/dbcodes/rmdb-main/src/parser/yacc.y"
    {
        (yyval.sv_val) = std::make_shared<FloatLit>((yyvsp[0].sv_float));
    }
#line 2096 "/mnt/d/dbcodes/rmdb-main/src/parser/yacc.tab.cpp"
    break;

  case 50: /* value: VALUE_BIGINT  */
#line 306 "/mnt/d/dbcodes/rmdb-main/src/parser/yacc.y"
    {
        (yyval.sv_val) = std::make_shared<BigIntLit>((yyvsp[0].sv_str));
    }
#line 2104 "/mnt/d/dbcodes/rmdb-main/src/parser/yacc.tab.cpp"
    break;

  case 51: /* value: VALUE_STRING  */
#line 310 "/mnt/d/dbcodes/rmdb-main/src/parser/yacc.y"
    {
        (yyval.sv_val) = std::make_shared<StringLit>((yyvsp[0].sv_str));
    }
#line 2112 "/mnt/d/dbcodes/rmdb-main/src/parser/yacc.tab.cpp"
    break;

  case 52: /* value: VALUE_BOOL  */
#line 314 "/mnt/d/dbcodes/rmdb-main/src/parser/yacc.y"
    {
        (yyval.sv_val) = std::make_shared<BoolLit>((yyvsp[0].sv_bool));
    }
#line 2120 "/mnt/d/dbcodes/rmdb-main/src/parser/yacc.tab.cpp"
    break;

  case 53: /* condition: col op expr  */
#line 321 "/mnt/d/dbcodes/rmdb-main/src/parser/yacc.y"
    {
        (yyval.sv_cond) = std::make_shared<BinaryExpr>((yyvsp[-2].sv_col), (yyvsp[-1].sv_comp_op), (yyvsp[0].sv_expr));
    }
#line 2128 "/mnt/d/dbcodes/rmdb-main/src/parser/yacc.tab.cpp"
    break;

  case 54: /* optWhereClause: %empty  */
#line 327 "/mnt/d/dbcodes/rmdb-main/src/parser/yacc.y"
                      { (yyval.sv_conds) = {}; }
#line 2134 "/mnt/d/dbcodes/rmdb-main/src/parser/yacc.tab.cpp"
    break;

  case 55: /* optWhereClause: WHERE whereClause  */
#line 329 "/mnt/d/dbcodes/rmdb-main/src/parser/yacc.y"
    {
        (yyval.sv_conds) = (yyvsp[0].sv_conds);
    }
#line 2142 "/mnt/d/dbcodes/rmdb-main/src/parser/yacc.tab.cpp"
    break;

  case 56: /* whereClause: condition  */
#line 336 "/mnt/d/dbcodes/rmdb-main/src/parser/yacc.y"
    {
        (yyval.sv_conds) = std::vector<std::shared_ptr<BinaryExpr>>{(yyvsp[0].sv_cond)};
    }
#line 2150 "/mnt/d/dbcodes/rmdb-main/src/parser/yacc.tab.cpp"
    break;

  case 57: /* whereClause: whereClause AND condition  */
#line 340 "/mnt/d/dbcodes/rmdb-main/src/parser/yacc.y"
    {
        (yyval.sv_conds).push_back((yyvsp[0].sv_cond));
    }
#line 2158 "/mnt/d/dbcodes/rmdb-main/src/parser/yacc.tab.cpp"
    break;

  case 58: /* col: tbName '.' colName  */
#line 347 "/mnt/d/dbcodes/rmdb-main/src/parser/yacc.y"
    {
        (yyval.sv_col) = std::make_shared<Col>((yyvsp[-2].sv_str), (yyvsp[0].sv_str));
    }
#line 2166 "/mnt/d/dbcodes/rmdb-main/src/parser/yacc.tab.cpp"
    break;

  case 59: /* col: colName  */
#line 351 "/mnt/d/dbcodes/rmdb-main/src/parser/yacc.y"
    {
        (yyval.sv_col) = std::make_shared<Col>("", (yyvsp[0].sv_str));
    }
#line 2174 "/mnt/d/dbcodes/rmdb-main/src/parser/yacc.tab.cpp"
    break;

  case 60: /* colList: col  */
#line 358 "/mnt/d/dbcodes/rmdb-main/src/parser/yacc.y"
    {
        (yyval.sv_cols) = std::vector<std::shared_ptr<Col>>{(yyvsp[0].sv_col)};
    }
#line 2182 "/mnt/d/dbcodes/rmdb-main/src/parser/yacc.tab.cpp"
    break;

  case 61: /* colList: colList ',' col  */
#line 362 "/mnt/d/dbcodes/rmdb-main/src/parser/yacc.y"
    {
        (yyval.sv_cols).push_back((yyvsp[0].sv_col));
    }
#line 2190 "/mnt/d/dbcodes/rmdb-main/src/parser/yacc.tab.cpp"
    break;

  case 62: /* op: '='  */
#line 369 "/mnt/d/dbcodes/rmdb-main/src/parser/yacc.y"
    {
        (yyval.sv_comp_op) = SV_OP_EQ;
    }
#line 2198 "/mnt/d/dbcodes/rmdb-main/src/parser/yacc.tab.cpp"
    break;

  case 63: /* op: '<'  */
#line 373 "/mnt/d/dbcodes/rmdb-main/src/parser/yacc.y"
    {
        (yyval.sv_comp_op) = SV_OP_LT;
    }
#line 2206 "/mnt/d/dbcodes/rmdb-main/src/parser/yacc.tab.cpp"
    break;

  case 64: /* op: '>'  */
#line 377 "/mnt/d/dbcodes/rmdb-main/src/parser/yacc.y"
    {
        (yyval.sv_comp_op) = SV_OP_GT;
    }
#line 2214 "/mnt/d/dbcodes/rmdb-main/src/parser/yacc.tab.cpp"
    break;

  case 65: /* op: NEQ  */
#line 381 "/mnt/d/dbcodes/rmdb-main/src/parser/yacc.y"
    {
        (yyval.sv_comp_op) = SV_OP_NE;
    }
#line 2222 "/mnt/d/dbcodes/rmdb-main/src/parser/yacc.tab.cpp"
    break;

  case 66: /* op: LEQ  */
#line 385 "/mnt/d/dbcodes/rmdb-main/src/parser/yacc.y"
    {
        (yyval.sv_comp_op) = SV_OP_LE;
    }
#line 2230 "/mnt/d/dbcodes/rmdb-main/src/parser/yacc.tab.cpp"
    break;

  case 67: /* op: GEQ  */
#line 389 "/mnt/d/dbcodes/rmdb-main/src/parser/yacc.y"
    {
        (yyval.sv_comp_op) = SV_OP_GE;
    }
#line 2238 "/mnt/d/dbcodes/rmdb-main/src/parser/yacc.tab.cpp"
    break;

  case 68: /* expr: value  */
#line 396 "/mnt/d/dbcodes/rmdb-main/src/parser/yacc.y"
    {
        (yyval.sv_expr) = std::static_pointer_cast<Expr>((yyvsp[0].sv_val));
    }
#line 2246 "/mnt/d/dbcodes/rmdb-main/src/parser/yacc.tab.cpp"
    break;

  case 69: /* expr: col  */
#line 400 "/mnt/d/dbcodes/rmdb-main/src/parser/yacc.y"
    {
        (yyval.sv_expr) = std::static_pointer_cast<Expr>((yyvsp[0].sv_col));
    }
#line 2254 "/mnt/d/dbcodes/rmdb-main/src/parser/yacc.tab.cpp"
    break;

  case 70: /* setClauses: setClause  */
#line 407 "/mnt/d/dbcodes/rmdb-main/src/parser/yacc.y"
    {
        (yyval.sv_set_clauses) = std::vector<std::shared_ptr<SetClause>>{(yyvsp[0].sv_set_clause)};
    }
#line 2262 "/mnt/d/dbcodes/rmdb-main/src/parser/yacc.tab.cpp"
    break;

  case 71: /* setClauses: setClauses ',' setClause  */
#line 411 "/mnt/d/dbcodes/rmdb-main/src/parser/yacc.y"
    {
        (yyval.sv_set_clauses).push_back((yyvsp[0].sv_set_clause));
    }
#line 2270 "/mnt/d/dbcodes/rmdb-main/src/parser/yacc.tab.cpp"
    break;

  case 72: /* setClause: colName '=' value  */
#line 418 "/mnt/d/dbcodes/rmdb-main/src/parser/yacc.y"
    {
        (yyval.sv_set_clause) = std::make_shared<SetClause>((yyvsp[-2].sv_str), (yyvsp[0].sv_val));
    }
#line 2278 "/mnt/d/dbcodes/rmdb-main/src/parser/yacc.tab.cpp"
    break;

  case 73: /* newSelector: '*'  */
#line 433 "/mnt/d/dbcodes/rmdb-main/src/parser/yacc.y"
    {
        (yyval.sv_select_items) = {};
    }
#line 2286 "/mnt/d/dbcodes/rmdb-main/src/parser/yacc.tab.cpp"
    break;

  case 75: /* selectItemList: selectItem  */
#line 441 "/mnt/d/dbcodes/rmdb-main/src/parser/yacc.y"
    {
        (yyval.sv_select_items) = std::vector<std::shared_ptr<SelectItem>>{(yyvsp[0].sv_select_item)};
    }
#line 2294 "/mnt/d/dbcodes/rmdb-main/src/parser/yacc.tab.cpp"
    break;

  case 76: /* selectItemList: selectItemList ',' selectItem  */
#line 445 "/mnt/d/dbcodes/rmdb-main/src/parser/yacc.y"
    {
        (yyval.sv_select_items).push_back((yyvsp[0].sv_select_item));
    }
#line 2302 "/mnt/d/dbcodes/rmdb-main/src/parser/yacc.tab.cpp"
    break;

  case 77: /* selectItem: col  */
#line 452 "/mnt/d/dbcodes/rmdb-main/src/parser/yacc.y"
    {
        (yyval.sv_select_item) = std::make_shared<SelectItem>((yyvsp[0].sv_col));
    }
#line 2310 "/mnt/d/dbcodes/rmdb-main/src/parser/yacc.tab.cpp"
    break;

  case 78: /* selectItem: col AS colName  */
#line 456 "/mnt/d/dbcodes/rmdb-main/src/parser/yacc.y"
    {
        (yyval.sv_select_item) = std::make_shared<SelectItem>((yyvsp[-2].sv_col), (yyvsp[0].sv_str));
    }
#line 2318 "/mnt/d/dbcodes/rmdb-main/src/parser/yacc.tab.cpp"
    break;

  case 79: /* selectItem: aggregateItem  */
#line 460 "/mnt/d/dbcodes/rmdb-main/src/parser/yacc.y"
    {
        (yyval.sv_select_item) = (yyvsp[0].sv_select_item);
    }
#line 2326 "/mnt/d/dbcodes/rmdb-main/src/parser/yacc.tab.cpp"
    break;

  case 80: /* selectItem: aggregateItem AS colName  */
#line 464 "/mnt/d/dbcodes/rmdb-main/src/parser/yacc.y"
    {
        (yyvsp[-2].sv_select_item)->alias = (yyvsp[0].sv_str);
        (yyval.sv_select_item) = (yyvsp[-2].sv_select_item);
    }
#line 2335 "/mnt/d/dbcodes/rmdb-main/src/parser/yacc.tab.cpp"
    break;

  case 81: /* aggregateItem: aggName '(' col ')'  */
#line 472 "/mnt/d/dbcodes/rmdb-main/src/parser/yacc.y"
    {
        (yyval.sv_select_item) = std::make_shared<SelectItem>((yyvsp[-3].sv_agg_type), (yyvsp[-1].sv_col), false);
    }
#line 2343 "/mnt/d/dbcodes/rmdb-main/src/parser/yacc.tab.cpp"
    break;

  case 82: /* aggregateItem: COUNT '(' col ')'  */
#line 476 "/mnt/d/dbcodes/rmdb-main/src/parser/yacc.y"
    {
        (yyval.sv_select_item) = std::make_shared<SelectItem>(AGG_COUNT, (yyvsp[-1].sv_col), false);
    }
#line 2351 "/mnt/d/dbcodes/rmdb-main/src/parser/yacc.tab.cpp"
    break;

  case 83: /* aggregateItem: COUNT '(' '*' ')'  */
#line 480 "/mnt/d/dbcodes/rmdb-main/src/parser/yacc.y"
    {
        (yyval.sv_select_item) = std::make_shared<SelectItem>(AGG_COUNT, nullptr, true);
    }
#line 2359 "/mnt/d/dbcodes/rmdb-main/src/parser/yacc.tab.cpp"
    break;

  case 84: /* aggName: MAX  */
#line 487 "/mnt/d/dbcodes/rmdb-main/src/parser/yacc.y"
    {
        (yyval.sv_agg_type) = AGG_MAX;
    }
#line 2367 "/mnt/d/dbcodes/rmdb-main/src/parser/yacc.tab.cpp"
    break;

  case 85: /* aggName: MIN  */
#line 491 "/mnt/d/dbcodes/rmdb-main/src/parser/yacc.y"
    {
        (yyval.sv_agg_type) = AGG_MIN;
    }
#line 2375 "/mnt/d/dbcodes/rmdb-main/src/parser/yacc.tab.cpp"
    break;

  case 86: /* aggName: SUM  */
#line 495 "/mnt/d/dbcodes/rmdb-main/src/parser/yacc.y"
    {
        (yyval.sv_agg_type) = AGG_SUM;
    }
#line 2383 "/mnt/d/dbcodes/rmdb-main/src/parser/yacc.tab.cpp"
    break;

  case 87: /* aggName: AVG  */
#line 499 "/mnt/d/dbcodes/rmdb-main/src/parser/yacc.y"
    {
        (yyval.sv_agg_type) = AGG_AVG;
    }
#line 2391 "/mnt/d/dbcodes/rmdb-main/src/parser/yacc.tab.cpp"
    break;

  case 88: /* fromList: tableRef  */
#line 521 "/mnt/d/dbcodes/rmdb-main/src/parser/yacc.y"
    {
        (yyval.sv_from) = std::make_shared<FromClause>();
        (yyval.sv_from)->table_refs.push_back((yyvsp[0].sv_table_ref));
    }
#line 2400 "/mnt/d/dbcodes/rmdb-main/src/parser/yacc.tab.cpp"
    break;

  case 89: /* fromList: fromList ',' tableRef  */
#line 526 "/mnt/d/dbcodes/rmdb-main/src/parser/yacc.y"
    {
        (yyval.sv_from) = (yyvsp[-2].sv_from);
        (yyval.sv_from)->table_refs.push_back((yyvsp[0].sv_table_ref));
    }
#line 2409 "/mnt/d/dbcodes/rmdb-main/src/parser/yacc.tab.cpp"
    break;

  case 90: /* fromList: fromList JOIN tableRef optJoinOnClause  */
#line 531 "/mnt/d/dbcodes/rmdb-main/src/parser/yacc.y"
    {
        (yyval.sv_from) = (yyvsp[-3].sv_from);
        (yyval.sv_from)->table_refs.push_back((yyvsp[-1].sv_table_ref));
        (yyval.sv_from)->join_conds.insert((yyval.sv_from)->join_conds.end(), (yyvsp[0].sv_join_conds).begin(), (yyvsp[0].sv_join_conds).end());
    }
#line 2419 "/mnt/d/dbcodes/rmdb-main/src/parser/yacc.tab.cpp"
    break;

  case 91: /* fromList: tableRef SEMI JOIN tableRef ON condition  */
#line 537 "/mnt/d/dbcodes/rmdb-main/src/parser/yacc.y"
    {
        (yyval.sv_from) = std::make_shared<FromClause>();
        (yyval.sv_from)->table_refs.push_back((yyvsp[-5].sv_table_ref));
        (yyval.sv_from)->table_refs.push_back((yyvsp[-2].sv_table_ref));
        (yyval.sv_from)->is_semi_join = true;
        (yyval.sv_from)->semi_conds.push_back((yyvsp[0].sv_cond));
    }
#line 2431 "/mnt/d/dbcodes/rmdb-main/src/parser/yacc.tab.cpp"
    break;

  case 92: /* optJoinOnClause: ON whereClause  */
#line 548 "/mnt/d/dbcodes/rmdb-main/src/parser/yacc.y"
    {
        (yyval.sv_join_conds) = (yyvsp[0].sv_conds);
    }
#line 2439 "/mnt/d/dbcodes/rmdb-main/src/parser/yacc.tab.cpp"
    break;

  case 93: /* optJoinOnClause: %empty  */
#line 551 "/mnt/d/dbcodes/rmdb-main/src/parser/yacc.y"
                      { (yyval.sv_join_conds) = {}; }
#line 2445 "/mnt/d/dbcodes/rmdb-main/src/parser/yacc.tab.cpp"
    break;

  case 94: /* tableRef: tbName  */
#line 556 "/mnt/d/dbcodes/rmdb-main/src/parser/yacc.y"
    {
        (yyval.sv_table_ref) = std::make_shared<TableRef>((yyvsp[0].sv_str), "");
    }
#line 2453 "/mnt/d/dbcodes/rmdb-main/src/parser/yacc.tab.cpp"
    break;

  case 95: /* tableRef: tbName tbName  */
#line 560 "/mnt/d/dbcodes/rmdb-main/src/parser/yacc.y"
    {
        (yyval.sv_table_ref) = std::make_shared<TableRef>((yyvsp[-1].sv_str), (yyvsp[0].sv_str));
    }
#line 2461 "/mnt/d/dbcodes/rmdb-main/src/parser/yacc.tab.cpp"
    break;

  case 96: /* tableRef: tbName AS tbName  */
#line 564 "/mnt/d/dbcodes/rmdb-main/src/parser/yacc.y"
    {
        (yyval.sv_table_ref) = std::make_shared<TableRef>((yyvsp[-2].sv_str), (yyvsp[0].sv_str));
    }
#line 2469 "/mnt/d/dbcodes/rmdb-main/src/parser/yacc.tab.cpp"
    break;

  case 97: /* tableRef: '(' unionSelectList ')' AS tbName  */
#line 568 "/mnt/d/dbcodes/rmdb-main/src/parser/yacc.y"
    {
        (yyval.sv_table_ref) = std::make_shared<TableRef>((yyvsp[-3].sv_select_stmts), (yyvsp[0].sv_str));
    }
#line 2477 "/mnt/d/dbcodes/rmdb-main/src/parser/yacc.tab.cpp"
    break;

  case 98: /* tableRef: '(' unionSelectList ')' tbName  */
#line 572 "/mnt/d/dbcodes/rmdb-main/src/parser/yacc.y"
    {
        (yyval.sv_table_ref) = std::make_shared<TableRef>((yyvsp[-2].sv_select_stmts), (yyvsp[0].sv_str));
    }
#line 2485 "/mnt/d/dbcodes/rmdb-main/src/parser/yacc.tab.cpp"
    break;

  case 99: /* opt_order_clause: ORDER BY order_clause  */
#line 579 "/mnt/d/dbcodes/rmdb-main/src/parser/yacc.y"
    { 
        (yyval.sv_orderby) = (yyvsp[0].sv_orderby); 
    }
#line 2493 "/mnt/d/dbcodes/rmdb-main/src/parser/yacc.tab.cpp"
    break;

  case 100: /* opt_order_clause: %empty  */
#line 582 "/mnt/d/dbcodes/rmdb-main/src/parser/yacc.y"
                      { (yyval.sv_orderby) = nullptr; }
#line 2499 "/mnt/d/dbcodes/rmdb-main/src/parser/yacc.tab.cpp"
    break;

  case 101: /* order_clause: order_item_list  */
#line 587 "/mnt/d/dbcodes/rmdb-main/src/parser/yacc.y"
    { 
        (yyval.sv_orderby) = std::make_shared<OrderBy>((yyvsp[0].sv_orderby_items));
    }
#line 2507 "/mnt/d/dbcodes/rmdb-main/src/parser/yacc.tab.cpp"
    break;

  case 102: /* order_item_list: order_item  */
#line 594 "/mnt/d/dbcodes/rmdb-main/src/parser/yacc.y"
    {
        (yyval.sv_orderby_items) = std::vector<std::shared_ptr<OrderByItem>>{(yyvsp[0].sv_orderby_item)};
    }
#line 2515 "/mnt/d/dbcodes/rmdb-main/src/parser/yacc.tab.cpp"
    break;

  case 103: /* order_item_list: order_item_list ',' order_item  */
#line 598 "/mnt/d/dbcodes/rmdb-main/src/parser/yacc.y"
    {
        (yyval.sv_orderby_items).push_back((yyvsp[0].sv_orderby_item));
    }
#line 2523 "/mnt/d/dbcodes/rmdb-main/src/parser/yacc.tab.cpp"
    break;

  case 104: /* order_item: col opt_asc_desc  */
#line 605 "/mnt/d/dbcodes/rmdb-main/src/parser/yacc.y"
    {
        (yyval.sv_orderby_item) = std::make_shared<OrderByItem>((yyvsp[-1].sv_col), (yyvsp[0].sv_orderby_dir));
    }
#line 2531 "/mnt/d/dbcodes/rmdb-main/src/parser/yacc.tab.cpp"
    break;

  case 105: /* opt_asc_desc: ASC  */
#line 611 "/mnt/d/dbcodes/rmdb-main/src/parser/yacc.y"
                 { (yyval.sv_orderby_dir) = OrderBy_ASC;     }
#line 2537 "/mnt/d/dbcodes/rmdb-main/src/parser/yacc.tab.cpp"
    break;

  case 106: /* opt_asc_desc: DESC  */
#line 612 "/mnt/d/dbcodes/rmdb-main/src/parser/yacc.y"
                 { (yyval.sv_orderby_dir) = OrderBy_DESC;    }
#line 2543 "/mnt/d/dbcodes/rmdb-main/src/parser/yacc.tab.cpp"
    break;

  case 107: /* opt_asc_desc: %empty  */
#line 613 "/mnt/d/dbcodes/rmdb-main/src/parser/yacc.y"
            { (yyval.sv_orderby_dir) = OrderBy_DEFAULT; }
#line 2549 "/mnt/d/dbcodes/rmdb-main/src/parser/yacc.tab.cpp"
    break;

  case 108: /* optGroupClause: GROUP BY colList  */
#line 618 "/mnt/d/dbcodes/rmdb-main/src/parser/yacc.y"
    {
        (yyval.sv_cols) = (yyvsp[0].sv_cols);
    }
#line 2557 "/mnt/d/dbcodes/rmdb-main/src/parser/yacc.tab.cpp"
    break;

  case 109: /* optGroupClause: %empty  */
#line 621 "/mnt/d/dbcodes/rmdb-main/src/parser/yacc.y"
                      { (yyval.sv_cols) = {}; }
#line 2563 "/mnt/d/dbcodes/rmdb-main/src/parser/yacc.tab.cpp"
    break;

  case 110: /* optHavingClause: HAVING havingClause  */
#line 626 "/mnt/d/dbcodes/rmdb-main/src/parser/yacc.y"
    {
        (yyval.sv_havings) = (yyvsp[0].sv_havings);
    }
#line 2571 "/mnt/d/dbcodes/rmdb-main/src/parser/yacc.tab.cpp"
    break;

  case 111: /* optHavingClause: %empty  */
#line 629 "/mnt/d/dbcodes/rmdb-main/src/parser/yacc.y"
                      { (yyval.sv_havings) = {}; }
#line 2577 "/mnt/d/dbcodes/rmdb-main/src/parser/yacc.tab.cpp"
    break;

  case 112: /* havingClause: havingCondition  */
#line 634 "/mnt/d/dbcodes/rmdb-main/src/parser/yacc.y"
    {
        (yyval.sv_havings) = std::vector<std::shared_ptr<HavingExpr>>{(yyvsp[0].sv_having)};
    }
#line 2585 "/mnt/d/dbcodes/rmdb-main/src/parser/yacc.tab.cpp"
    break;

  case 113: /* havingClause: havingClause AND havingCondition  */
#line 638 "/mnt/d/dbcodes/rmdb-main/src/parser/yacc.y"
    {
        (yyval.sv_havings).push_back((yyvsp[0].sv_having));
    }
#line 2593 "/mnt/d/dbcodes/rmdb-main/src/parser/yacc.tab.cpp"
    break;

  case 114: /* havingCondition: havingLhs op value  */
#line 645 "/mnt/d/dbcodes/rmdb-main/src/parser/yacc.y"
    {
        (yyval.sv_having) = std::make_shared<HavingExpr>((yyvsp[-2].sv_select_item), (yyvsp[-1].sv_comp_op), (yyvsp[0].sv_val));
    }
#line 2601 "/mnt/d/dbcodes/rmdb-main/src/parser/yacc.tab.cpp"
    break;

  case 115: /* havingLhs: aggregateItem  */
#line 652 "/mnt/d/dbcodes/rmdb-main/src/parser/yacc.y"
    {
        (yyval.sv_select_item) = (yyvsp[0].sv_select_item);
    }
#line 2609 "/mnt/d/dbcodes/rmdb-main/src/parser/yacc.tab.cpp"
    break;

  case 116: /* optLimitClause: LIMIT VALUE_INT  */
#line 659 "/mnt/d/dbcodes/rmdb-main/src/parser/yacc.y"
    {
        (yyval.sv_int) = (yyvsp[0].sv_int);
    }
#line 2617 "/mnt/d/dbcodes/rmdb-main/src/parser/yacc.tab.cpp"
    break;

  case 117: /* optLimitClause: %empty  */
#line 662 "/mnt/d/dbcodes/rmdb-main/src/parser/yacc.y"
                      { (yyval.sv_int) = -1; }
#line 2623 "/mnt/d/dbcodes/rmdb-main/src/parser/yacc.tab.cpp"
    break;

  case 118: /* set_knob_type: ENABLE_NESTLOOP  */
#line 666 "/mnt/d/dbcodes/rmdb-main/src/parser/yacc.y"
                    { (yyval.sv_setKnobType) = EnableNestLoop; }
#line 2629 "/mnt/d/dbcodes/rmdb-main/src/parser/yacc.tab.cpp"
    break;

  case 119: /* set_knob_type: ENABLE_SORTMERGE  */
#line 667 "/mnt/d/dbcodes/rmdb-main/src/parser/yacc.y"
                         { (yyval.sv_setKnobType) = EnableSortMerge; }
#line 2635 "/mnt/d/dbcodes/rmdb-main/src/parser/yacc.tab.cpp"
    break;


#line 2639 "/mnt/d/dbcodes/rmdb-main/src/parser/yacc.tab.cpp"

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

#line 673 "/mnt/d/dbcodes/rmdb-main/src/parser/yacc.y"

