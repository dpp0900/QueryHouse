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

/* Substitute the type names.  */
#define YYSTYPE         HSQL_STYPE
#define YYLTYPE         HSQL_LTYPE
/* Substitute the variable and function names.  */
#define yyparse         hsql_parse
#define yylex           hsql_lex
#define yyerror         hsql_error
#define yydebug         hsql_debug
#define yynerrs         hsql_nerrs

/* First part of user prologue.  */
#line 1 "bison_parser.y"

/**
 * bison_parser.y
 * defines bison_parser.h
 * outputs bison_parser.c
 *
 * Grammar File Spec: http://dinosaur.compilertools.net/bison/bison_6.html
 *
 */
/*********************************
 ** Section 1: C Declarations
 *********************************/

#include "bison_parser.h"
#include "flex_lexer.h"

#include <stdio.h>
#include <string.h>


int yyerror(YYLTYPE* llocp, Program * result, yyscan_t scanner, const char *msg);


#line 102 "bison_parser.cpp"

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

#include "bison_parser.h"
/* Symbol kind.  */
enum yysymbol_kind_t
{
  YYSYMBOL_YYEMPTY = -2,
  YYSYMBOL_YYEOF = 0,                      /* "end of file"  */
  YYSYMBOL_YYerror = 1,                    /* error  */
  YYSYMBOL_YYUNDEF = 2,                    /* "invalid token"  */
  YYSYMBOL_STRING = 3,                     /* STRING  */
  YYSYMBOL_IDENTIFIER = 4,                 /* IDENTIFIER  */
  YYSYMBOL_FLOATVAL = 5,                   /* FLOATVAL  */
  YYSYMBOL_INTVAL = 6,                     /* INTVAL  */
  YYSYMBOL_DEALLOCATE = 7,                 /* DEALLOCATE  */
  YYSYMBOL_PARAMETERS = 8,                 /* PARAMETERS  */
  YYSYMBOL_INTERSECT = 9,                  /* INTERSECT  */
  YYSYMBOL_TEMPORARY = 10,                 /* TEMPORARY  */
  YYSYMBOL_TIMESTAMP = 11,                 /* TIMESTAMP  */
  YYSYMBOL_DISTINCT = 12,                  /* DISTINCT  */
  YYSYMBOL_NVARCHAR = 13,                  /* NVARCHAR  */
  YYSYMBOL_RESTRICT = 14,                  /* RESTRICT  */
  YYSYMBOL_TRUNCATE = 15,                  /* TRUNCATE  */
  YYSYMBOL_ANALYZE = 16,                   /* ANALYZE  */
  YYSYMBOL_BETWEEN = 17,                   /* BETWEEN  */
  YYSYMBOL_CASCADE = 18,                   /* CASCADE  */
  YYSYMBOL_COLUMNS = 19,                   /* COLUMNS  */
  YYSYMBOL_CONTROL = 20,                   /* CONTROL  */
  YYSYMBOL_DEFAULT = 21,                   /* DEFAULT  */
  YYSYMBOL_EXECUTE = 22,                   /* EXECUTE  */
  YYSYMBOL_EXPLAIN = 23,                   /* EXPLAIN  */
  YYSYMBOL_INTEGER = 24,                   /* INTEGER  */
  YYSYMBOL_NATURAL = 25,                   /* NATURAL  */
  YYSYMBOL_PREPARE = 26,                   /* PREPARE  */
  YYSYMBOL_PRIMARY = 27,                   /* PRIMARY  */
  YYSYMBOL_SCHEMAS = 28,                   /* SCHEMAS  */
  YYSYMBOL_SPATIAL = 29,                   /* SPATIAL  */
  YYSYMBOL_VARCHAR = 30,                   /* VARCHAR  */
  YYSYMBOL_VIRTUAL = 31,                   /* VIRTUAL  */
  YYSYMBOL_DESCRIBE = 32,                  /* DESCRIBE  */
  YYSYMBOL_BEFORE = 33,                    /* BEFORE  */
  YYSYMBOL_COLUMN = 34,                    /* COLUMN  */
  YYSYMBOL_CREATE = 35,                    /* CREATE  */
  YYSYMBOL_DELETE = 36,                    /* DELETE  */
  YYSYMBOL_DIRECT = 37,                    /* DIRECT  */
  YYSYMBOL_DOUBLE = 38,                    /* DOUBLE  */
  YYSYMBOL_ESCAPE = 39,                    /* ESCAPE  */
  YYSYMBOL_EXCEPT = 40,                    /* EXCEPT  */
  YYSYMBOL_EXISTS = 41,                    /* EXISTS  */
  YYSYMBOL_EXTRACT = 42,                   /* EXTRACT  */
  YYSYMBOL_GLOBAL = 43,                    /* GLOBAL  */
  YYSYMBOL_HAVING = 44,                    /* HAVING  */
  YYSYMBOL_IMPORT = 45,                    /* IMPORT  */
  YYSYMBOL_INSERT = 46,                    /* INSERT  */
  YYSYMBOL_ISNULL = 47,                    /* ISNULL  */
  YYSYMBOL_OFFSET = 48,                    /* OFFSET  */
  YYSYMBOL_RENAME = 49,                    /* RENAME  */
  YYSYMBOL_SCHEMA = 50,                    /* SCHEMA  */
  YYSYMBOL_SELECT = 51,                    /* SELECT  */
  YYSYMBOL_SORTED = 52,                    /* SORTED  */
  YYSYMBOL_TABLES = 53,                    /* TABLES  */
  YYSYMBOL_UNIQUE = 54,                    /* UNIQUE  */
  YYSYMBOL_UNLOAD = 55,                    /* UNLOAD  */
  YYSYMBOL_UPDATE = 56,                    /* UPDATE  */
  YYSYMBOL_VALUES = 57,                    /* VALUES  */
  YYSYMBOL_AFTER = 58,                     /* AFTER  */
  YYSYMBOL_ALTER = 59,                     /* ALTER  */
  YYSYMBOL_CROSS = 60,                     /* CROSS  */
  YYSYMBOL_DELTA = 61,                     /* DELTA  */
  YYSYMBOL_FLOAT = 62,                     /* FLOAT  */
  YYSYMBOL_GROUP = 63,                     /* GROUP  */
  YYSYMBOL_INDEX = 64,                     /* INDEX  */
  YYSYMBOL_INNER = 65,                     /* INNER  */
  YYSYMBOL_LIMIT = 66,                     /* LIMIT  */
  YYSYMBOL_LOCAL = 67,                     /* LOCAL  */
  YYSYMBOL_MERGE = 68,                     /* MERGE  */
  YYSYMBOL_MINUS = 69,                     /* MINUS  */
  YYSYMBOL_ORDER = 70,                     /* ORDER  */
  YYSYMBOL_OUTER = 71,                     /* OUTER  */
  YYSYMBOL_RIGHT = 72,                     /* RIGHT  */
  YYSYMBOL_TABLE = 73,                     /* TABLE  */
  YYSYMBOL_UNION = 74,                     /* UNION  */
  YYSYMBOL_USING = 75,                     /* USING  */
  YYSYMBOL_WHERE = 76,                     /* WHERE  */
  YYSYMBOL_CALL = 77,                      /* CALL  */
  YYSYMBOL_CASE = 78,                      /* CASE  */
  YYSYMBOL_CHAR = 79,                      /* CHAR  */
  YYSYMBOL_DATE = 80,                      /* DATE  */
  YYSYMBOL_DESC = 81,                      /* DESC  */
  YYSYMBOL_DROP = 82,                      /* DROP  */
  YYSYMBOL_ELSE = 83,                      /* ELSE  */
  YYSYMBOL_FILE = 84,                      /* FILE  */
  YYSYMBOL_FROM = 85,                      /* FROM  */
  YYSYMBOL_FULL = 86,                      /* FULL  */
  YYSYMBOL_HASH = 87,                      /* HASH  */
  YYSYMBOL_HINT = 88,                      /* HINT  */
  YYSYMBOL_INTO = 89,                      /* INTO  */
  YYSYMBOL_JOIN = 90,                      /* JOIN  */
  YYSYMBOL_LEFT = 91,                      /* LEFT  */
  YYSYMBOL_LIKE = 92,                      /* LIKE  */
  YYSYMBOL_LOAD = 93,                      /* LOAD  */
  YYSYMBOL_LONG = 94,                      /* LONG  */
  YYSYMBOL_NULL = 95,                      /* NULL  */
  YYSYMBOL_PLAN = 96,                      /* PLAN  */
  YYSYMBOL_SHOW = 97,                      /* SHOW  */
  YYSYMBOL_TEXT = 98,                      /* TEXT  */
  YYSYMBOL_THEN = 99,                      /* THEN  */
  YYSYMBOL_TIME = 100,                     /* TIME  */
  YYSYMBOL_VIEW = 101,                     /* VIEW  */
  YYSYMBOL_WHEN = 102,                     /* WHEN  */
  YYSYMBOL_WITH = 103,                     /* WITH  */
  YYSYMBOL_ADD = 104,                      /* ADD  */
  YYSYMBOL_ALL = 105,                      /* ALL  */
  YYSYMBOL_AND = 106,                      /* AND  */
  YYSYMBOL_ASC = 107,                      /* ASC  */
  YYSYMBOL_CSV = 108,                      /* CSV  */
  YYSYMBOL_END = 109,                      /* END  */
  YYSYMBOL_FOR = 110,                      /* FOR  */
  YYSYMBOL_INT = 111,                      /* INT  */
  YYSYMBOL_KEY = 112,                      /* KEY  */
  YYSYMBOL_NOT = 113,                      /* NOT  */
  YYSYMBOL_OFF = 114,                      /* OFF  */
  YYSYMBOL_SET = 115,                      /* SET  */
  YYSYMBOL_TBL = 116,                      /* TBL  */
  YYSYMBOL_TOP = 117,                      /* TOP  */
  YYSYMBOL_AS = 118,                       /* AS  */
  YYSYMBOL_BY = 119,                       /* BY  */
  YYSYMBOL_IF = 120,                       /* IF  */
  YYSYMBOL_IN = 121,                       /* IN  */
  YYSYMBOL_IS = 122,                       /* IS  */
  YYSYMBOL_OF = 123,                       /* OF  */
  YYSYMBOL_ON = 124,                       /* ON  */
  YYSYMBOL_OR = 125,                       /* OR  */
  YYSYMBOL_TO = 126,                       /* TO  */
  YYSYMBOL_ARRAY = 127,                    /* ARRAY  */
  YYSYMBOL_CONCAT = 128,                   /* CONCAT  */
  YYSYMBOL_ILIKE = 129,                    /* ILIKE  */
  YYSYMBOL_SECOND = 130,                   /* SECOND  */
  YYSYMBOL_MINUTE = 131,                   /* MINUTE  */
  YYSYMBOL_HOUR = 132,                     /* HOUR  */
  YYSYMBOL_DAY = 133,                      /* DAY  */
  YYSYMBOL_MONTH = 134,                    /* MONTH  */
  YYSYMBOL_YEAR = 135,                     /* YEAR  */
  YYSYMBOL_TRUE = 136,                     /* TRUE  */
  YYSYMBOL_FALSE = 137,                    /* FALSE  */
  YYSYMBOL_FOREIGN = 138,                  /* FOREIGN  */
  YYSYMBOL_REFERENCES = 139,               /* REFERENCES  */
  YYSYMBOL_ACTION = 140,                   /* ACTION  */
  YYSYMBOL_JSON = 141,                     /* JSON  */
  YYSYMBOL_PRAGMA = 142,                   /* PRAGMA  */
  YYSYMBOL_REINDEX = 143,                  /* REINDEX  */
  YYSYMBOL_GENERATED = 144,                /* GENERATED  */
  YYSYMBOL_ALWAYS = 145,                   /* ALWAYS  */
  YYSYMBOL_CHECK = 146,                    /* CHECK  */
  YYSYMBOL_CONFLICT = 147,                 /* CONFLICT  */
  YYSYMBOL_IGNORE = 148,                   /* IGNORE  */
  YYSYMBOL_REPLACE = 149,                  /* REPLACE  */
  YYSYMBOL_ROLLBACK = 150,                 /* ROLLBACK  */
  YYSYMBOL_ABORT = 151,                    /* ABORT  */
  YYSYMBOL_FAIL = 152,                     /* FAIL  */
  YYSYMBOL_AUTOINCR = 153,                 /* AUTOINCR  */
  YYSYMBOL_BEGIN = 154,                    /* BEGIN  */
  YYSYMBOL_TRIGGER = 155,                  /* TRIGGER  */
  YYSYMBOL_TEMP = 156,                     /* TEMP  */
  YYSYMBOL_INSTEAD = 157,                  /* INSTEAD  */
  YYSYMBOL_EACH = 158,                     /* EACH  */
  YYSYMBOL_ROW = 159,                      /* ROW  */
  YYSYMBOL_OVER = 160,                     /* OVER  */
  YYSYMBOL_FILTER = 161,                   /* FILTER  */
  YYSYMBOL_PARTITION = 162,                /* PARTITION  */
  YYSYMBOL_CURRENT = 163,                  /* CURRENT  */
  YYSYMBOL_EXCLUDE = 164,                  /* EXCLUDE  */
  YYSYMBOL_FOLLOWING = 165,                /* FOLLOWING  */
  YYSYMBOL_GROUPS = 166,                   /* GROUPS  */
  YYSYMBOL_NO = 167,                       /* NO  */
  YYSYMBOL_OTHERS = 168,                   /* OTHERS  */
  YYSYMBOL_PRECEDING = 169,                /* PRECEDING  */
  YYSYMBOL_RANGE = 170,                    /* RANGE  */
  YYSYMBOL_ROWS = 171,                     /* ROWS  */
  YYSYMBOL_TIES = 172,                     /* TIES  */
  YYSYMBOL_UNBOUNDED = 173,                /* UNBOUNDED  */
  YYSYMBOL_WINDOW = 174,                   /* WINDOW  */
  YYSYMBOL_ATTACH = 175,                   /* ATTACH  */
  YYSYMBOL_DETACH = 176,                   /* DETACH  */
  YYSYMBOL_DATABASE = 177,                 /* DATABASE  */
  YYSYMBOL_INDEXED = 178,                  /* INDEXED  */
  YYSYMBOL_CAST = 179,                     /* CAST  */
  YYSYMBOL_SAVEPOINT = 180,                /* SAVEPOINT  */
  YYSYMBOL_RELEASE = 181,                  /* RELEASE  */
  YYSYMBOL_VACUUM = 182,                   /* VACUUM  */
  YYSYMBOL_TRANSACTION = 183,              /* TRANSACTION  */
  YYSYMBOL_DEFFERED = 184,                 /* DEFFERED  */
  YYSYMBOL_EXCLUSIVE = 185,                /* EXCLUSIVE  */
  YYSYMBOL_IMEDIATE = 186,                 /* IMEDIATE  */
  YYSYMBOL_COMMIT = 187,                   /* COMMIT  */
  YYSYMBOL_GLOB = 188,                     /* GLOB  */
  YYSYMBOL_MATCH = 189,                    /* MATCH  */
  YYSYMBOL_REGEX = 190,                    /* REGEX  */
  YYSYMBOL_NOTHING = 191,                  /* NOTHING  */
  YYSYMBOL_NULLS = 192,                    /* NULLS  */
  YYSYMBOL_LAST = 193,                     /* LAST  */
  YYSYMBOL_FIRST = 194,                    /* FIRST  */
  YYSYMBOL_DO = 195,                       /* DO  */
  YYSYMBOL_COLLATE = 196,                  /* COLLATE  */
  YYSYMBOL_197_ = 197,                     /* '='  */
  YYSYMBOL_EQUALS = 198,                   /* EQUALS  */
  YYSYMBOL_NOTEQUALS = 199,                /* NOTEQUALS  */
  YYSYMBOL_200_ = 200,                     /* '<'  */
  YYSYMBOL_201_ = 201,                     /* '>'  */
  YYSYMBOL_LESS = 202,                     /* LESS  */
  YYSYMBOL_GREATER = 203,                  /* GREATER  */
  YYSYMBOL_LESSEQ = 204,                   /* LESSEQ  */
  YYSYMBOL_GREATEREQ = 205,                /* GREATEREQ  */
  YYSYMBOL_NOTNULL = 206,                  /* NOTNULL  */
  YYSYMBOL_207_ = 207,                     /* '+'  */
  YYSYMBOL_208_ = 208,                     /* '-'  */
  YYSYMBOL_209_ = 209,                     /* '*'  */
  YYSYMBOL_210_ = 210,                     /* '/'  */
  YYSYMBOL_211_ = 211,                     /* '%'  */
  YYSYMBOL_212_ = 212,                     /* '^'  */
  YYSYMBOL_UMINUS = 213,                   /* UMINUS  */
  YYSYMBOL_214_ = 214,                     /* '['  */
  YYSYMBOL_215_ = 215,                     /* ']'  */
  YYSYMBOL_216_ = 216,                     /* '('  */
  YYSYMBOL_217_ = 217,                     /* ')'  */
  YYSYMBOL_218_ = 218,                     /* '.'  */
  YYSYMBOL_219_ = 219,                     /* ';'  */
  YYSYMBOL_220_ = 220,                     /* ','  */
  YYSYMBOL_221_ = 221,                     /* '?'  */
  YYSYMBOL_YYACCEPT = 222,                 /* $accept  */
  YYSYMBOL_input = 223,                    /* input  */
  YYSYMBOL_statement_list = 224,           /* statement_list  */
  YYSYMBOL_statement = 225,                /* statement  */
  YYSYMBOL_cmd = 226,                      /* cmd  */
  YYSYMBOL_cmd_release = 227,              /* cmd_release  */
  YYSYMBOL_savepoint_name = 228,           /* savepoint_name  */
  YYSYMBOL_cmd_pragma = 229,               /* cmd_pragma  */
  YYSYMBOL_cmd_reindex = 230,              /* cmd_reindex  */
  YYSYMBOL_cmd_analyze = 231,              /* cmd_analyze  */
  YYSYMBOL_cmd_attach = 232,               /* cmd_attach  */
  YYSYMBOL_cmd_detach = 233,               /* cmd_detach  */
  YYSYMBOL_pragma_key = 234,               /* pragma_key  */
  YYSYMBOL_pragma_value = 235,             /* pragma_value  */
  YYSYMBOL_schema_name = 236,              /* schema_name  */
  YYSYMBOL_pragma_name = 237,              /* pragma_name  */
  YYSYMBOL_preparable_statement = 238,     /* preparable_statement  */
  YYSYMBOL_rollback_statement = 239,       /* rollback_statement  */
  YYSYMBOL_opt_transaction = 240,          /* opt_transaction  */
  YYSYMBOL_opt_to_savepoint = 241,         /* opt_to_savepoint  */
  YYSYMBOL_vacuum_statement = 242,         /* vacuum_statement  */
  YYSYMBOL_opt_schema_name = 243,          /* opt_schema_name  */
  YYSYMBOL_begin_statement = 244,          /* begin_statement  */
  YYSYMBOL_commit_statement = 245,         /* commit_statement  */
  YYSYMBOL_opt_upsert_clause = 246,        /* opt_upsert_clause  */
  YYSYMBOL_upsert_clause = 247,            /* upsert_clause  */
  YYSYMBOL_indexed_column_list = 248,      /* indexed_column_list  */
  YYSYMBOL_indexed_column = 249,           /* indexed_column  */
  YYSYMBOL_opt_collate = 250,              /* opt_collate  */
  YYSYMBOL_assign_list = 251,              /* assign_list  */
  YYSYMBOL_opt_null = 252,                 /* opt_null  */
  YYSYMBOL_assign_clause = 253,            /* assign_clause  */
  YYSYMBOL_column_name_list = 254,         /* column_name_list  */
  YYSYMBOL_collation_name = 255,           /* collation_name  */
  YYSYMBOL_opt_hints = 256,                /* opt_hints  */
  YYSYMBOL_hint_list = 257,                /* hint_list  */
  YYSYMBOL_hint = 258,                     /* hint  */
  YYSYMBOL_prepare_statement = 259,        /* prepare_statement  */
  YYSYMBOL_prepare_target_query = 260,     /* prepare_target_query  */
  YYSYMBOL_execute_statement = 261,        /* execute_statement  */
  YYSYMBOL_import_statement = 262,         /* import_statement  */
  YYSYMBOL_import_file_type = 263,         /* import_file_type  */
  YYSYMBOL_file_path = 264,                /* file_path  */
  YYSYMBOL_show_statement = 265,           /* show_statement  */
  YYSYMBOL_alter_statement = 266,          /* alter_statement  */
  YYSYMBOL_opt_column = 267,               /* opt_column  */
  YYSYMBOL_create_statement = 268,         /* create_statement  */
  YYSYMBOL_CreateInparan = 269,            /* CreateInparan  */
  YYSYMBOL_opt_ForeignKeylist = 270,       /* opt_ForeignKeylist  */
  YYSYMBOL_ForeignKeylist = 271,           /* ForeignKeylist  */
  YYSYMBOL_ForeignKey = 272,               /* ForeignKey  */
  YYSYMBOL_FkNoOptstmt = 273,              /* FkNoOptstmt  */
  YYSYMBOL_ForeignKeyColumn = 274,         /* ForeignKeyColumn  */
  YYSYMBOL_ForeignKeyRef = 275,            /* ForeignKeyRef  */
  YYSYMBOL_opt_Actiontypelist = 276,       /* opt_Actiontypelist  */
  YYSYMBOL_Action_typelist = 277,          /* Action_typelist  */
  YYSYMBOL_Action_type = 278,              /* Action_type  */
  YYSYMBOL_ColumnInParen = 279,            /* ColumnInParen  */
  YYSYMBOL_opt_unique = 280,               /* opt_unique  */
  YYSYMBOL_index_name = 281,               /* index_name  */
  YYSYMBOL_trigger_declare = 282,          /* trigger_declare  */
  YYSYMBOL_opt_tmp = 283,                  /* opt_tmp  */
  YYSYMBOL_trigger_name = 284,             /* trigger_name  */
  YYSYMBOL_opt_trigger_time = 285,         /* opt_trigger_time  */
  YYSYMBOL_trigger_event = 286,            /* trigger_event  */
  YYSYMBOL_opt_of_column_list = 287,       /* opt_of_column_list  */
  YYSYMBOL_opt_for_each = 288,             /* opt_for_each  */
  YYSYMBOL_opt_when = 289,                 /* opt_when  */
  YYSYMBOL_trigger_cmd_list = 290,         /* trigger_cmd_list  */
  YYSYMBOL_trigger_cmd = 291,              /* trigger_cmd  */
  YYSYMBOL_module_name = 292,              /* module_name  */
  YYSYMBOL_opt_not_exists = 293,           /* opt_not_exists  */
  YYSYMBOL_column_def_commalist = 294,     /* column_def_commalist  */
  YYSYMBOL_column_def = 295,               /* column_def  */
  YYSYMBOL_opt_column_arglist = 296,       /* opt_column_arglist  */
  YYSYMBOL_column_arglist = 297,           /* column_arglist  */
  YYSYMBOL_column_arg = 298,               /* column_arg  */
  YYSYMBOL_opt_on_conflict = 299,          /* opt_on_conflict  */
  YYSYMBOL_resolve_type = 300,             /* resolve_type  */
  YYSYMBOL_opt_autoinc = 301,              /* opt_autoinc  */
  YYSYMBOL_column_type = 302,              /* column_type  */
  YYSYMBOL_drop_statement = 303,           /* drop_statement  */
  YYSYMBOL_opt_exists = 304,               /* opt_exists  */
  YYSYMBOL_delete_statement = 305,         /* delete_statement  */
  YYSYMBOL_truncate_statement = 306,       /* truncate_statement  */
  YYSYMBOL_insert_statement = 307,         /* insert_statement  */
  YYSYMBOL_super_list = 308,               /* super_list  */
  YYSYMBOL_insert_type = 309,              /* insert_type  */
  YYSYMBOL_opt_column_list = 310,          /* opt_column_list  */
  YYSYMBOL_update_statement = 311,         /* update_statement  */
  YYSYMBOL_update_clause_commalist = 312,  /* update_clause_commalist  */
  YYSYMBOL_update_clause = 313,            /* update_clause  */
  YYSYMBOL_select_statement = 314,         /* select_statement  */
  YYSYMBOL_select_with_paren = 315,        /* select_with_paren  */
  YYSYMBOL_select_paren_or_clause = 316,   /* select_paren_or_clause  */
  YYSYMBOL_select_no_paren = 317,          /* select_no_paren  */
  YYSYMBOL_set_operator = 318,             /* set_operator  */
  YYSYMBOL_set_type = 319,                 /* set_type  */
  YYSYMBOL_opt_all = 320,                  /* opt_all  */
  YYSYMBOL_select_clause = 321,            /* select_clause  */
  YYSYMBOL_window_clause = 322,            /* window_clause  */
  YYSYMBOL_windowdefn_list = 323,          /* windowdefn_list  */
  YYSYMBOL_windowdefn = 324,               /* windowdefn  */
  YYSYMBOL_window = 325,                   /* window  */
  YYSYMBOL_opt_base_window_name = 326,     /* opt_base_window_name  */
  YYSYMBOL_opt_frame = 327,                /* opt_frame  */
  YYSYMBOL_range_or_rows = 328,            /* range_or_rows  */
  YYSYMBOL_frame_bound_s = 329,            /* frame_bound_s  */
  YYSYMBOL_frame_bound_e = 330,            /* frame_bound_e  */
  YYSYMBOL_frame_bound = 331,              /* frame_bound  */
  YYSYMBOL_opt_frame_exclude = 332,        /* opt_frame_exclude  */
  YYSYMBOL_frame_exclude = 333,            /* frame_exclude  */
  YYSYMBOL_opt_distinct = 334,             /* opt_distinct  */
  YYSYMBOL_select_list = 335,              /* select_list  */
  YYSYMBOL_opt_from_clause = 336,          /* opt_from_clause  */
  YYSYMBOL_from_clause = 337,              /* from_clause  */
  YYSYMBOL_opt_where = 338,                /* opt_where  */
  YYSYMBOL_opt_group = 339,                /* opt_group  */
  YYSYMBOL_opt_having = 340,               /* opt_having  */
  YYSYMBOL_opt_order = 341,                /* opt_order  */
  YYSYMBOL_order_list = 342,               /* order_list  */
  YYSYMBOL_order_desc = 343,               /* order_desc  */
  YYSYMBOL_opt_order_type = 344,           /* opt_order_type  */
  YYSYMBOL_opt_top = 345,                  /* opt_top  */
  YYSYMBOL_opt_limit = 346,                /* opt_limit  */
  YYSYMBOL_expr_list = 347,                /* expr_list  */
  YYSYMBOL_opt_literal_list = 348,         /* opt_literal_list  */
  YYSYMBOL_literal_list = 349,             /* literal_list  */
  YYSYMBOL_expr_alias = 350,               /* expr_alias  */
  YYSYMBOL_expr = 351,                     /* expr  */
  YYSYMBOL_operand = 352,                  /* operand  */
  YYSYMBOL_cast_expr = 353,                /* cast_expr  */
  YYSYMBOL_scalar_expr = 354,              /* scalar_expr  */
  YYSYMBOL_unary_expr = 355,               /* unary_expr  */
  YYSYMBOL_binary_expr = 356,              /* binary_expr  */
  YYSYMBOL_logic_expr = 357,               /* logic_expr  */
  YYSYMBOL_in_expr = 358,                  /* in_expr  */
  YYSYMBOL_case_expr = 359,                /* case_expr  */
  YYSYMBOL_case_list = 360,                /* case_list  */
  YYSYMBOL_exists_expr = 361,              /* exists_expr  */
  YYSYMBOL_comp_expr = 362,                /* comp_expr  */
  YYSYMBOL_function_expr = 363,            /* function_expr  */
  YYSYMBOL_opt_over_clause = 364,          /* opt_over_clause  */
  YYSYMBOL_opt_filter_clause = 365,        /* opt_filter_clause  */
  YYSYMBOL_extract_expr = 366,             /* extract_expr  */
  YYSYMBOL_datetime_field = 367,           /* datetime_field  */
  YYSYMBOL_array_expr = 368,               /* array_expr  */
  YYSYMBOL_array_index = 369,              /* array_index  */
  YYSYMBOL_between_expr = 370,             /* between_expr  */
  YYSYMBOL_column_name = 371,              /* column_name  */
  YYSYMBOL_literal = 372,                  /* literal  */
  YYSYMBOL_string_literal = 373,           /* string_literal  */
  YYSYMBOL_bool_literal = 374,             /* bool_literal  */
  YYSYMBOL_num_literal = 375,              /* num_literal  */
  YYSYMBOL_int_literal = 376,              /* int_literal  */
  YYSYMBOL_null_literal = 377,             /* null_literal  */
  YYSYMBOL_param_expr = 378,               /* param_expr  */
  YYSYMBOL_table_ref = 379,                /* table_ref  */
  YYSYMBOL_table_prefix = 380,             /* table_prefix  */
  YYSYMBOL_join_op = 381,                  /* join_op  */
  YYSYMBOL_opt_index = 382,                /* opt_index  */
  YYSYMBOL_opt_on = 383,                   /* opt_on  */
  YYSYMBOL_opt_using = 384,                /* opt_using  */
  YYSYMBOL_table_ref_name_no_alias = 385,  /* table_ref_name_no_alias  */
  YYSYMBOL_table_name = 386,               /* table_name  */
  YYSYMBOL_alias = 387,                    /* alias  */
  YYSYMBOL_opt_alias = 388,                /* opt_alias  */
  YYSYMBOL_opt_with_clause = 389,          /* opt_with_clause  */
  YYSYMBOL_with_clause = 390,              /* with_clause  */
  YYSYMBOL_with_description_list = 391,    /* with_description_list  */
  YYSYMBOL_with_description = 392,         /* with_description  */
  YYSYMBOL_join_kw = 393,                  /* join_kw  */
  YYSYMBOL_opt_semicolon = 394,            /* opt_semicolon  */
  YYSYMBOL_ident_commalist = 395           /* ident_commalist  */
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
typedef yytype_int16 yy_state_t;

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
         || (defined HSQL_LTYPE_IS_TRIVIAL && HSQL_LTYPE_IS_TRIVIAL \
             && defined HSQL_STYPE_IS_TRIVIAL && HSQL_STYPE_IS_TRIVIAL)))

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
#define YYFINAL  149
/* YYLAST -- Last index in YYTABLE.  */
#define YYLAST   1174

/* YYNTOKENS -- Number of terminals.  */
#define YYNTOKENS  222
/* YYNNTS -- Number of nonterminals.  */
#define YYNNTS  174
/* YYNRULES -- Number of rules.  */
#define YYNRULES  438
/* YYNSTATES -- Number of states.  */
#define YYNSTATES  814

/* YYMAXUTOK -- Last valid token kind.  */
#define YYMAXUTOK   459


/* YYTRANSLATE(TOKEN-NUM) -- Symbol number corresponding to TOKEN-NUM
   as returned by yylex, with out-of-bounds checking.  */
#define YYTRANSLATE(YYX)                                \
  (0 <= (YYX) && (YYX) <= YYMAXUTOK                     \
   ? YY_CAST (yysymbol_kind_t, yytranslate[YYX])        \
   : YYSYMBOL_YYUNDEF)

/* YYTRANSLATE[TOKEN-NUM] -- Symbol number corresponding to TOKEN-NUM
   as returned by yylex.  */
static const yytype_uint8 yytranslate[] =
{
       0,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,   211,     2,     2,
     216,   217,   209,   207,   220,   208,   218,   210,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,   219,
     200,   197,   201,   221,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,   214,     2,   215,   212,     2,     2,     2,     2,     2,
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
      65,    66,    67,    68,    69,    70,    71,    72,    73,    74,
      75,    76,    77,    78,    79,    80,    81,    82,    83,    84,
      85,    86,    87,    88,    89,    90,    91,    92,    93,    94,
      95,    96,    97,    98,    99,   100,   101,   102,   103,   104,
     105,   106,   107,   108,   109,   110,   111,   112,   113,   114,
     115,   116,   117,   118,   119,   120,   121,   122,   123,   124,
     125,   126,   127,   128,   129,   130,   131,   132,   133,   134,
     135,   136,   137,   138,   139,   140,   141,   142,   143,   144,
     145,   146,   147,   148,   149,   150,   151,   152,   153,   154,
     155,   156,   157,   158,   159,   160,   161,   162,   163,   164,
     165,   166,   167,   168,   169,   170,   171,   172,   173,   174,
     175,   176,   177,   178,   179,   180,   181,   182,   183,   184,
     185,   186,   187,   188,   189,   190,   191,   192,   193,   194,
     195,   196,   198,   199,   202,   203,   204,   205,   206,   213
};

#if HSQL_DEBUG
/* YYRLINE[YYN] -- Source line where rule number YYN was defined.  */
static const yytype_int16 yyrline[] =
{
       0,   601,   601,   610,   615,   622,   628,   634,   640,   649,
     650,   651,   652,   653,   654,   655,   656,   657,   658,   662,
     667,   675,   683,   688,   694,   703,   704,   708,   709,   713,
     719,   728,   733,   741,   742,   746,   747,   748,   749,   750,
     751,   755,   761,   767,   768,   769,   770,   771,   772,   773,
     774,   775,   776,   780,   788,   793,   801,   806,   811,   819,
     825,   833,   838,   845,   850,   855,   860,   868,   873,   882,
     883,   886,   890,   896,   902,   914,   918,   925,   934,   939,
     948,   953,   961,   965,   969,   976,   984,   988,   995,  1007,
    1012,  1017,  1021,  1025,  1031,  1045,  1053,  1062,  1068,  1082,
    1091,  1095,  1109,  1113,  1119,  1134,  1140,  1148,  1158,  1163,
    1177,  1185,  1194,  1202,  1217,  1231,  1239,  1248,  1257,  1262,
    1263,  1267,  1271,  1278,  1286,  1294,  1301,  1309,  1310,  1314,
    1318,  1325,  1329,  1333,  1337,  1341,  1345,  1349,  1353,  1361,
    1370,  1371,  1375,  1379,  1393,  1394,  1398,  1402,  1403,  1404,
    1405,  1409,  1410,  1411,  1415,  1416,  1420,  1421,  1425,  1426,
    1430,  1431,  1435,  1436,  1437,  1438,  1442,  1447,  1448,  1452,
    1456,  1463,  1474,  1475,  1479,  1483,  1490,  1491,  1492,  1499,
    1500,  1501,  1502,  1506,  1507,  1511,  1512,  1513,  1514,  1515,
    1519,  1520,  1525,  1526,  1527,  1528,  1529,  1530,  1534,  1537,
    1538,  1548,  1556,  1564,  1570,  1578,  1587,  1588,  1597,  1607,
    1622,  1637,  1655,  1658,  1665,  1666,  1667,  1671,  1672,  1682,
    1691,  1695,  1701,  1715,  1721,  1727,  1741,  1742,  1746,  1747,
    1751,  1758,  1770,  1778,  1779,  1780,  1784,  1785,  1789,  1800,
    1814,  1818,  1819,  1823,  1827,  1835,  1845,  1846,  1850,  1857,
    1865,  1869,  1870,  1871,  1875,  1876,  1880,  1881,  1885,  1886,
    1887,  1891,  1892,  1896,  1897,  1898,  1899,  1904,  1905,  1909,
    1916,  1917,  1921,  1926,  1927,  1931,  1937,  1941,  1942,  1945,
    1946,  1950,  1951,  1955,  1959,  1960,  1961,  1966,  1971,  1978,
    1979,  1980,  1981,  1982,  1983,  1990,  1994,  2000,  2005,  2011,
    2015,  2022,  2030,  2031,  2032,  2033,  2034,  2035,  2039,  2040,
    2041,  2042,  2043,  2044,  2045,  2046,  2047,  2048,  2052,  2060,
    2061,  2065,  2071,  2077,  2083,  2089,  2098,  2099,  2100,  2101,
    2102,  2103,  2104,  2105,  2106,  2107,  2108,  2109,  2110,  2111,
    2115,  2116,  2120,  2121,  2122,  2123,  2129,  2130,  2131,  2132,
    2136,  2137,  2141,  2142,  2146,  2147,  2148,  2149,  2150,  2151,
    2152,  2156,  2164,  2177,  2178,  2184,  2188,  2189,  2194,  2203,
    2204,  2205,  2206,  2207,  2208,  2212,  2216,  2220,  2224,  2225,
    2226,  2227,  2231,  2232,  2233,  2234,  2235,  2239,  2243,  2244,
    2248,  2249,  2253,  2257,  2261,  2273,  2284,  2295,  2304,  2316,
    2322,  2328,  2329,  2330,  2331,  2337,  2349,  2350,  2351,  2355,
    2356,  2360,  2361,  2366,  2373,  2374,  2385,  2390,  2391,  2399,
    2400,  2404,  2408,  2412,  2419,  2433,  2434,  2435,  2436,  2437,
    2438,  2439,  2440,  2441,  2442,  2457,  2458,  2463,  2464
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
  "\"end of file\"", "error", "\"invalid token\"", "STRING", "IDENTIFIER",
  "FLOATVAL", "INTVAL", "DEALLOCATE", "PARAMETERS", "INTERSECT",
  "TEMPORARY", "TIMESTAMP", "DISTINCT", "NVARCHAR", "RESTRICT", "TRUNCATE",
  "ANALYZE", "BETWEEN", "CASCADE", "COLUMNS", "CONTROL", "DEFAULT",
  "EXECUTE", "EXPLAIN", "INTEGER", "NATURAL", "PREPARE", "PRIMARY",
  "SCHEMAS", "SPATIAL", "VARCHAR", "VIRTUAL", "DESCRIBE", "BEFORE",
  "COLUMN", "CREATE", "DELETE", "DIRECT", "DOUBLE", "ESCAPE", "EXCEPT",
  "EXISTS", "EXTRACT", "GLOBAL", "HAVING", "IMPORT", "INSERT", "ISNULL",
  "OFFSET", "RENAME", "SCHEMA", "SELECT", "SORTED", "TABLES", "UNIQUE",
  "UNLOAD", "UPDATE", "VALUES", "AFTER", "ALTER", "CROSS", "DELTA",
  "FLOAT", "GROUP", "INDEX", "INNER", "LIMIT", "LOCAL", "MERGE", "MINUS",
  "ORDER", "OUTER", "RIGHT", "TABLE", "UNION", "USING", "WHERE", "CALL",
  "CASE", "CHAR", "DATE", "DESC", "DROP", "ELSE", "FILE", "FROM", "FULL",
  "HASH", "HINT", "INTO", "JOIN", "LEFT", "LIKE", "LOAD", "LONG", "NULL",
  "PLAN", "SHOW", "TEXT", "THEN", "TIME", "VIEW", "WHEN", "WITH", "ADD",
  "ALL", "AND", "ASC", "CSV", "END", "FOR", "INT", "KEY", "NOT", "OFF",
  "SET", "TBL", "TOP", "AS", "BY", "IF", "IN", "IS", "OF", "ON", "OR",
  "TO", "ARRAY", "CONCAT", "ILIKE", "SECOND", "MINUTE", "HOUR", "DAY",
  "MONTH", "YEAR", "TRUE", "FALSE", "FOREIGN", "REFERENCES", "ACTION",
  "JSON", "PRAGMA", "REINDEX", "GENERATED", "ALWAYS", "CHECK", "CONFLICT",
  "IGNORE", "REPLACE", "ROLLBACK", "ABORT", "FAIL", "AUTOINCR", "BEGIN",
  "TRIGGER", "TEMP", "INSTEAD", "EACH", "ROW", "OVER", "FILTER",
  "PARTITION", "CURRENT", "EXCLUDE", "FOLLOWING", "GROUPS", "NO", "OTHERS",
  "PRECEDING", "RANGE", "ROWS", "TIES", "UNBOUNDED", "WINDOW", "ATTACH",
  "DETACH", "DATABASE", "INDEXED", "CAST", "SAVEPOINT", "RELEASE",
  "VACUUM", "TRANSACTION", "DEFFERED", "EXCLUSIVE", "IMEDIATE", "COMMIT",
  "GLOB", "MATCH", "REGEX", "NOTHING", "NULLS", "LAST", "FIRST", "DO",
  "COLLATE", "'='", "EQUALS", "NOTEQUALS", "'<'", "'>'", "LESS", "GREATER",
  "LESSEQ", "GREATEREQ", "NOTNULL", "'+'", "'-'", "'*'", "'/'", "'%'",
  "'^'", "UMINUS", "'['", "']'", "'('", "')'", "'.'", "';'", "','", "'?'",
  "$accept", "input", "statement_list", "statement", "cmd", "cmd_release",
  "savepoint_name", "cmd_pragma", "cmd_reindex", "cmd_analyze",
  "cmd_attach", "cmd_detach", "pragma_key", "pragma_value", "schema_name",
  "pragma_name", "preparable_statement", "rollback_statement",
  "opt_transaction", "opt_to_savepoint", "vacuum_statement",
  "opt_schema_name", "begin_statement", "commit_statement",
  "opt_upsert_clause", "upsert_clause", "indexed_column_list",
  "indexed_column", "opt_collate", "assign_list", "opt_null",
  "assign_clause", "column_name_list", "collation_name", "opt_hints",
  "hint_list", "hint", "prepare_statement", "prepare_target_query",
  "execute_statement", "import_statement", "import_file_type", "file_path",
  "show_statement", "alter_statement", "opt_column", "create_statement",
  "CreateInparan", "opt_ForeignKeylist", "ForeignKeylist", "ForeignKey",
  "FkNoOptstmt", "ForeignKeyColumn", "ForeignKeyRef", "opt_Actiontypelist",
  "Action_typelist", "Action_type", "ColumnInParen", "opt_unique",
  "index_name", "trigger_declare", "opt_tmp", "trigger_name",
  "opt_trigger_time", "trigger_event", "opt_of_column_list",
  "opt_for_each", "opt_when", "trigger_cmd_list", "trigger_cmd",
  "module_name", "opt_not_exists", "column_def_commalist", "column_def",
  "opt_column_arglist", "column_arglist", "column_arg", "opt_on_conflict",
  "resolve_type", "opt_autoinc", "column_type", "drop_statement",
  "opt_exists", "delete_statement", "truncate_statement",
  "insert_statement", "super_list", "insert_type", "opt_column_list",
  "update_statement", "update_clause_commalist", "update_clause",
  "select_statement", "select_with_paren", "select_paren_or_clause",
  "select_no_paren", "set_operator", "set_type", "opt_all",
  "select_clause", "window_clause", "windowdefn_list", "windowdefn",
  "window", "opt_base_window_name", "opt_frame", "range_or_rows",
  "frame_bound_s", "frame_bound_e", "frame_bound", "opt_frame_exclude",
  "frame_exclude", "opt_distinct", "select_list", "opt_from_clause",
  "from_clause", "opt_where", "opt_group", "opt_having", "opt_order",
  "order_list", "order_desc", "opt_order_type", "opt_top", "opt_limit",
  "expr_list", "opt_literal_list", "literal_list", "expr_alias", "expr",
  "operand", "cast_expr", "scalar_expr", "unary_expr", "binary_expr",
  "logic_expr", "in_expr", "case_expr", "case_list", "exists_expr",
  "comp_expr", "function_expr", "opt_over_clause", "opt_filter_clause",
  "extract_expr", "datetime_field", "array_expr", "array_index",
  "between_expr", "column_name", "literal", "string_literal",
  "bool_literal", "num_literal", "int_literal", "null_literal",
  "param_expr", "table_ref", "table_prefix", "join_op", "opt_index",
  "opt_on", "opt_using", "table_ref_name_no_alias", "table_name", "alias",
  "opt_alias", "opt_with_clause", "with_clause", "with_description_list",
  "with_description", "join_kw", "opt_semicolon", "ident_commalist", YY_NULLPTR
};

static const char *
yysymbol_name (yysymbol_kind_t yysymbol)
{
  return yytname[yysymbol];
}
#endif

#define YYPACT_NINF (-707)

#define yypact_value_is_default(Yyn) \
  ((Yyn) == YYPACT_NINF)

#define YYTABLE_NINF (-436)

#define yytable_value_is_error(Yyn) \
  ((Yyn) == YYTABLE_NINF)

/* YYPACT[STATE-NUM] -- Index in YYTABLE of the portion describing
   STATE-NUM.  */
static const yytype_int16 yypact[] =
{
     891,    34,    91,    91,   108,   133,    91,   211,   137,   187,
      -5,    91,   213,   181,    43,   338,   172,   383,    91,  -707,
     172,   386,   430,    41,    35,   403,   172,   363,   160,  -707,
    -707,  -707,  -707,  -707,  -707,  -707,  -707,   296,  -707,  -707,
    -707,  -707,   296,  -707,  -707,  -707,  -707,  -707,  -707,  -707,
    -707,  -707,   334,  -707,  -707,   -30,  -707,   428,   222,  -707,
    -707,   237,   408,  -707,   422,  -707,   362,   362,  -707,   425,
     314,   364,    91,   420,   505,   423,  -707,    91,   424,   424,
     424,    91,  -707,   440,   354,  -707,  -707,  -707,   346,    62,
     366,  -707,  -707,   464,   172,   172,   172,  -707,  -707,   260,
    -707,  -707,   382,   392,   498,  -707,    31,   388,  -707,  -707,
     644,   406,   574,  -707,   545,  -707,   196,   685,  -707,  -707,
    -707,  -707,  -707,  -707,  -707,  -707,  -707,  -707,  -707,  -707,
    -707,  -707,  -707,  -707,  -707,  -707,  -707,  -707,  -707,  -707,
    -707,   403,  -707,  -707,   593,  -707,  -707,   531,  -707,  -707,
     822,  -707,   539,  -707,  -707,    91,   511,   -30,   365,  -707,
     356,  -707,   628,    20,   633,   362,   524,    91,    91,   362,
     234,   362,   567,  -707,   560,  -707,  -707,  -707,  -707,  -707,
    -707,   641,   226,   618,    91,    91,   658,  -707,   448,   338,
      96,    96,   662,    36,  -707,  -707,  -707,  -707,    15,    25,
     616,   558,   644,   276,     4,   452,   574,   914,   644,   361,
     644,   210,   453,   -57,   644,   403,   644,   574,  -707,   574,
     -38,   455,   218,   574,   574,   574,   574,   574,   574,   574,
     574,   574,   574,   574,   574,   574,   574,   574,   574,   574,
     574,   667,  -707,  -707,   671,  -707,   459,   460,   667,   668,
     462,   467,  -707,  -707,  -707,   -30,   589,   577,   -30,   396,
    -707,   481,   479,  -707,  -707,  -707,    91,   663,   -32,   460,
     699,   231,   489,  -707,  -707,  -707,  -707,   705,   644,  -707,
     671,   515,   -45,  -707,    17,   681,  -707,  -707,  -707,   346,
     499,  -707,  -707,  -707,  -707,  -707,  -707,  -707,  -707,  -707,
    -707,   501,  -707,  -707,   593,  -707,  -707,   555,   644,  -707,
    -707,   503,  -707,  -707,  -707,  -707,  -707,  -707,   640,   350,
     209,   644,   644,  -707,   616,   634,  -135,  -707,   411,   403,
     416,  -707,  -707,  -707,  -707,   622,   886,   960,   574,   513,
     545,  -707,   635,   517,   960,   960,   960,   960,   960,   960,
     960,   115,   115,   115,   115,   210,   210,    95,    95,    95,
       7,   518,  -707,  -707,   730,   731,   200,  -707,   644,  -707,
    -707,  -707,   670,  -707,  -707,  -707,   644,   670,   644,   600,
    -707,  -707,    20,   666,  -707,   626,   642,   734,   625,  -707,
     620,  -707,   527,  -707,  -707,    81,   287,   659,   644,   641,
    -707,  -707,    91,    26,   734,   705,  -707,  -707,   533,   590,
    -110,  -707,   644,   644,   644,  -707,   436,   381,   534,  -707,
     644,   748,  -707,  -707,  -707,   379,   574,   960,   545,   538,
     301,  -707,  -707,   540,   307,  -707,  -707,   313,   542,   636,
     674,   543,   396,   544,  -707,   304,   396,   287,   717,    16,
    -707,   763,   684,  -707,   379,   552,   550,  -707,   642,    91,
    -707,  -707,  -707,   649,   409,    91,   287,  -707,  -707,   556,
     647,  -707,  -707,   700,     9,  -707,   555,   -56,   287,   456,
    -707,   644,  -707,  -707,  -707,  -707,   559,  -707,  -707,   562,
    -707,  -707,  -707,   568,   914,   569,   315,  -707,  -707,    20,
    -707,   730,  -707,   780,    20,   -48,   645,  -707,  -707,  -707,
     567,  -707,  -707,   644,  -707,  -707,   595,  -707,   644,   644,
    -707,   572,   671,   348,  -707,    38,  -707,  -707,   573,  -707,
    -707,  -707,   673,   669,  -707,    26,   644,  -707,   787,   590,
    -707,  -707,   287,   788,   791,  -707,  -707,  -707,   368,  -707,
    -707,   374,   583,  -707,  -105,    56,    10,   737,  -707,   359,
    -707,   287,   287,   734,  -707,   689,   678,   678,   708,   588,
     660,   594,  -707,   348,  -707,   703,   591,  -707,   688,   679,
    -707,   731,   731,  -707,    91,  -707,    44,  -707,   602,    66,
    -707,   603,   607,  -707,  -707,    20,   -18,   644,  -707,  -707,
    -707,  -707,   746,   754,  -707,   755,  -707,  -707,   245,   616,
     -62,   709,   653,  -707,  -707,   375,    -4,   683,  -707,  -707,
     678,   644,   713,   644,  -707,   617,   694,   328,  -707,   688,
    -707,    91,  -707,   393,   614,   725,  -707,  -707,   720,   345,
    -707,  -707,   395,   721,  -707,   397,  -707,   -51,  -707,  -707,
    -707,   254,  -707,   623,    33,   644,   193,   644,   837,  -707,
    -707,   734,   678,   505,  -707,    45,   627,    46,    26,  -707,
    -707,    14,   116,  -707,   617,   567,   687,   740,   644,  -707,
    -707,  -707,  -707,   291,  -707,    26,   567,   644,   842,    -4,
     757,  -707,   732,   732,   404,   677,   742,   727,    -3,   738,
     629,  -707,   706,  -707,  -707,   644,  -707,   646,  -707,  -707,
     767,   724,  -707,  -707,   771,   729,  -707,  -707,   711,   644,
    -707,    24,   347,   712,   707,   715,  -707,   344,   -43,  -707,
      84,  -707,   682,  -707,  -707,  -707,  -707,  -707,   727,   727,
     732,  -707,    26,   644,   797,   644,  -707,   664,   837,  -707,
    -707,    49,  -707,  -707,  -707,  -707,  -707,  -707,   287,   345,
     781,  -707,  -707,   205,  -707,  -707,  -707,    26,  -707,   644,
      26,   -12,   797,   797,   727,  -707,   287,   672,  -707,   287,
     787,  -707,  -707,  -707,   410,  -707,   741,   723,  -707,  -707,
    -707,   287,  -707,   786,  -707,  -707,  -707,   797,   731,   686,
     743,   715,  -707,  -707,  -707,    26,  -707,   413,  -707,  -707,
    -707,   -43,  -707,  -707
};

/* YYDEFACT[STATE-NUM] -- Default reduction number in state STATE-NUM.
   Performed when YYTABLE does not specify something else to do.  Zero
   means the default is an error.  */
static const yytype_int16 yydefact[] =
{
     420,     0,     0,    27,     0,     0,     0,   141,     0,     0,
     214,     0,     0,     0,     0,     0,    55,     0,    25,   215,
      55,    55,     0,     0,     0,    62,    55,     0,   436,     3,
       8,    14,     9,    10,    11,    12,    13,    90,    15,    16,
      17,    18,    90,    51,    44,     7,    52,    45,    50,    47,
      48,    46,     0,    49,    43,     0,   419,     0,   414,   209,
      28,    97,     0,   104,     0,   140,   168,   168,   144,     0,
       0,     0,     0,     0,     0,     0,   413,     0,   207,   207,
     207,     0,   102,     0,   421,   422,    54,    68,    42,    22,
       0,    33,    26,    58,    55,    55,    55,    63,   387,   378,
     390,   392,     0,     0,     0,   393,     0,     0,   388,   389,
       0,     0,     0,   380,     0,   394,     0,   302,   307,   310,
     311,   312,   304,   306,   313,   305,   326,   314,   315,   316,
     309,   303,   319,   320,   382,   383,   384,   391,   385,   386,
      41,     0,    31,    21,     0,    20,    61,    60,    67,     1,
     420,     2,     0,     6,     5,     0,   288,     0,   223,   224,
     280,   203,     0,   298,     0,   168,     0,     0,     0,   168,
     420,   168,   274,   100,     0,   185,   186,   187,   188,   189,
     216,     0,     0,     0,     0,     0,     0,   103,     0,     0,
       0,     0,     0,     0,    53,    64,    66,    65,   268,     0,
       0,     0,     0,     0,     0,     0,     0,   322,     0,     0,
       0,   321,     0,     0,     0,     0,     0,     0,   323,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,    32,    19,     0,     4,     0,   218,     0,   268,
       0,     0,   234,   235,   233,     0,   237,     0,     0,   294,
     415,     0,   297,   299,    96,    95,     0,     0,     0,   218,
       0,   420,     0,   165,   164,   163,   162,     0,     0,   208,
       0,     0,   274,   220,   109,   109,   206,   201,   202,   146,
       0,   205,   424,   423,    37,    40,    39,    38,    23,    36,
      35,     0,    42,    34,     0,    56,   267,   367,     0,   379,
     381,     0,   369,   370,   371,   372,   373,   374,     0,     0,
       0,     0,     0,   348,     0,     0,     0,   295,   418,     0,
       0,   317,   308,   340,    29,   341,     0,   333,     0,     0,
       0,   324,     0,   336,   335,   337,   338,   339,   354,   355,
     356,   357,   358,   359,   360,   328,   327,   330,   329,   331,
     332,     0,    59,   101,     0,     0,     0,   287,     0,   227,
     226,   228,   280,   229,   236,   232,     0,   280,     0,     0,
     230,    98,     0,     0,   167,     0,   420,     0,     0,   142,
       0,   117,     0,   160,   146,   150,   273,     0,     0,     0,
     219,   108,     0,     0,     0,     0,    24,    57,     0,   365,
       0,   352,     0,     0,     0,   346,     0,     0,     0,   375,
       0,     0,   417,   301,    30,   200,     0,   334,     0,     0,
       0,   325,   376,    93,     0,    91,   437,     0,     0,    70,
     271,   269,   294,   279,   281,   286,   294,   290,   292,   289,
     300,     0,     0,   112,   200,     0,   120,   169,   420,     0,
     161,   147,   148,     0,     0,     0,   222,   221,   105,   378,
       0,   107,   204,     0,     0,   361,   367,     0,   350,     0,
     349,     0,   353,   296,   416,   193,     0,   196,   195,     0,
     194,   199,   192,     0,   377,     0,     0,   344,   342,     0,
      89,     0,   217,     0,     0,    70,     0,   211,    69,   400,
     274,   270,   225,     0,   285,   284,    84,   231,     0,     0,
     166,   115,     0,   173,   111,     0,   118,   113,     0,   149,
     151,   152,   155,     0,    99,     0,     0,   364,   247,   365,
     368,   347,   351,     0,     0,   318,   345,   343,     0,    92,
     438,     0,     0,   210,     0,   272,     0,   276,   282,     0,
     283,   293,   291,     0,   110,     0,   184,   184,     0,     0,
       0,     0,   171,   172,   175,     0,   119,   122,   128,     0,
     170,     0,     0,   153,     0,   106,     0,   246,     0,   280,
     362,     0,     0,    94,   212,     0,     0,     0,   434,   433,
     425,   431,   429,   432,   402,   427,   401,   399,     0,   400,
     418,     0,   238,    83,    82,     0,   286,     0,   179,   176,
     184,     0,     0,     0,   174,     0,     0,     0,   123,   127,
     130,     0,   124,     0,   154,   157,   366,   363,     0,   250,
     197,   198,     0,     0,    71,     0,    75,    79,   428,   430,
     426,     0,   403,     0,     0,     0,   408,     0,     0,   239,
     116,     0,   184,     0,   177,     0,     0,     0,     0,   125,
     121,     0,     0,   129,     0,   274,     0,   159,     0,   253,
     251,   252,   245,     0,   213,     0,   274,     0,     0,   286,
       0,   404,   418,   418,     0,     0,     0,   410,   278,     0,
     240,   241,   191,   183,   181,     0,   182,     0,   133,   131,
       0,     0,   137,   135,     0,     0,   126,   114,     0,     0,
     143,   280,     0,     0,     0,   262,   254,     0,   274,    80,
       0,    86,     0,    76,    88,    78,    77,   405,   410,   410,
     418,   407,     0,     0,   412,     0,   275,     0,     0,   190,
     178,     0,   139,   132,   134,   136,   138,   156,   158,   250,
       0,   260,   255,     0,   248,   259,   258,     0,    72,     0,
       0,     0,   412,   412,   410,   406,   409,     0,   395,   277,
     247,   242,   180,   244,     0,   265,     0,     0,   266,   261,
      81,    85,    87,     0,    73,   397,   398,   412,     0,     0,
       0,   262,   256,   264,   263,     0,   396,     0,   243,   257,
     249,   274,   411,    74
};

/* YYPGOTO[NTERM-NUM].  */
static const yytype_int16 yypgoto[] =
{
    -707,  -707,  -707,   752,  -707,  -707,   -85,  -707,  -707,  -707,
    -707,  -707,  -707,   714,    -1,   718,  -707,  -707,   253,  -707,
    -707,  -707,  -707,  -707,   407,  -707,  -707,   224,  -707,   104,
    -707,   147,  -707,  -707,   873,  -707,   415,  -707,  -707,  -707,
    -707,  -707,  -262,  -707,  -707,   637,  -707,  -707,  -707,  -707,
     292,  -707,  -707,  -707,  -707,  -707,   295,   246,  -707,  -707,
    -707,  -707,  -212,  -707,  -707,  -707,  -707,  -707,  -707,   650,
    -707,   120,   371,  -392,  -707,  -707,   355,  -319,   266,  -707,
     476,  -707,   367,  -123,  -707,  -122,  -707,  -707,   675,  -107,
    -707,   536,  -153,     2,   680,  -111,   772,  -707,  -707,   405,
    -707,  -707,   191,   161,  -707,   183,  -707,   221,  -707,   156,
     144,  -707,   697,  -707,  -707,  -707,  -280,  -707,  -707,  -362,
    -707,   435,  -564,  -707,    39,  -297,  -707,  -201,   529,   -22,
     -28,  -707,  -707,  -707,  -707,  -707,  -707,  -707,   749,  -707,
    -707,  -707,   412,   477,  -707,  -707,  -707,  -707,  -707,  -397,
    -158,  -183,  -707,   369,   190,  -707,  -707,   349,  -707,  -707,
    -707,  -377,  -706,  -707,    -2,  -707,  -447,  -707,  -707,  -707,
     765,  -707,  -707,  -562
};

/* YYDEFGOTO[NTERM-NUM].  */
static const yytype_int16 yydefgoto[] =
{
       0,    27,    28,    29,    30,    31,   145,    32,    33,    34,
      35,    36,    89,   298,    90,    91,    37,    38,    87,   194,
      39,   147,    40,    41,   507,   508,   645,   646,   689,   728,
     560,   729,   730,   735,   153,   434,   435,    42,   265,    43,
      44,   174,   362,    45,    46,   403,    47,   455,   526,   576,
     577,   578,   579,   632,   628,   629,   630,   669,    69,   390,
      70,    71,   291,   464,   533,   583,   677,   720,   271,   272,
     521,   167,   456,   457,   572,   573,   574,   618,   180,   750,
     493,    48,   184,    49,    50,    51,   505,    52,   366,    53,
     282,   283,    54,   371,   372,   159,   255,   256,   375,   160,
     659,   700,   701,   588,   589,   682,   683,   725,   801,   726,
     764,   789,   308,   440,   510,   511,   279,   612,   746,   259,
     443,   444,   516,   249,   380,   326,   261,   262,   327,   328,
     117,   118,   119,   120,   121,   122,   123,   124,   204,   125,
     126,   127,   475,   409,   128,   318,   129,   130,   131,   132,
     133,   134,   135,   136,   137,   138,   139,   555,   556,   607,
     697,   744,   778,    75,    59,   422,   423,    55,    56,    84,
      85,   608,   151,   437
};

/* YYTABLE[YYPACT[STATE-NUM]] -- What to do in state STATE-NUM.  If
   positive, shift that token.  If negative, reduce the rule whose
   number is the opposite.  If YYTABLE_NINF, syntax error.  */
static const yytype_int16 yytable[] =
{
     116,    60,   400,   212,    63,   263,   470,   299,   299,    76,
     442,   410,   471,   537,    58,   446,    92,   276,   397,   633,
     634,   156,   142,    98,   146,   100,   101,   306,   708,   309,
     469,   278,   709,   278,    98,    99,   100,   101,   643,   143,
     143,   745,   454,   430,   793,   140,   251,   273,   274,   214,
     214,   401,   662,   385,   338,   214,   421,   158,   598,   243,
      57,   363,    81,   275,   519,   395,   795,   796,   216,   216,
     172,   441,   205,   103,   216,   182,   506,   514,   207,   187,
     419,   598,   203,   339,   211,   420,   386,   321,   209,   311,
     596,   806,   213,   599,   257,    58,    82,   363,   600,    98,
     294,   100,   101,   515,   601,   602,   322,   476,   305,   104,
     420,   597,    61,   323,   461,   105,   599,   295,   276,   603,
      74,   600,   214,   604,   605,   736,   105,   601,   602,   710,
     712,   496,   296,   580,   713,   223,   257,    62,   585,   462,
     242,   216,   603,   402,   206,   688,   604,   605,   273,   274,
     214,   214,   214,   247,   655,   214,   108,   109,   107,   250,
     332,   540,   218,   656,   275,   268,   269,   108,   109,   216,
     216,   216,   552,   644,   216,   399,   575,   767,   207,   794,
     319,   711,   287,   288,   387,   290,   157,   168,   330,   336,
     292,   337,   333,   472,   335,   343,   344,   345,   346,   347,
     348,   349,   350,   351,   352,   353,   354,   355,   356,   357,
     358,   359,   360,   418,   334,   144,   304,   420,   141,   407,
     297,   241,    72,   223,   450,   538,   609,   639,   638,   429,
     557,   714,   307,   453,   310,   113,   807,   222,   463,   112,
     113,   115,    64,   223,   420,   738,   739,   114,   619,   651,
     693,   156,   115,   606,    78,   439,   396,   438,   690,   190,
     564,   636,   704,   706,   383,    65,   782,     8,   785,   580,
       8,   707,    73,    93,    97,   284,   606,    10,   191,   148,
      10,   769,    79,   715,    66,   266,    77,    11,   731,   270,
      11,   277,   414,   774,    98,    99,   100,   101,   548,   416,
     417,   664,   214,   551,   770,   527,   695,   240,   722,   241,
     427,   322,    67,   341,   215,  -436,  -436,   495,   415,  -436,
    -436,   216,   235,   236,   237,   238,   239,   240,   424,   241,
     285,   342,   102,   103,    15,   652,    80,    15,   223,   363,
     391,   263,    83,   702,   691,   775,   263,   195,   196,   197,
      98,    99,   100,   101,   445,    86,   447,   449,   694,   759,
     698,   772,   773,   149,   671,   252,  -145,    68,   786,   104,
     731,   696,   787,   792,   252,   565,   466,   788,   202,   150,
      19,   721,   214,    19,   672,   514,   105,    88,   102,   103,
     477,   478,   479,   214,   642,   717,   253,   797,   494,   152,
     468,   216,   566,   485,   106,   253,   732,   140,   731,   486,
     214,   515,   216,    98,    99,   100,   101,   487,   107,   237,
     238,   239,   240,   155,   241,   104,   257,   108,   109,   216,
     254,   361,   161,    98,    99,   100,   101,   263,   367,   254,
     162,   488,   105,   567,   378,   530,   185,   186,   768,   413,
     214,   102,   103,   163,   723,   531,   214,   528,   489,   542,
     106,   568,   379,   534,   724,   532,   569,   214,   170,   216,
     111,   102,   103,   490,   107,   216,   198,   491,   199,   329,
     481,   512,   166,   108,   109,   517,   216,   214,   104,   169,
     492,   445,   570,   164,   571,   165,   561,   562,   653,   112,
     113,    98,    99,   100,   101,   105,   216,   114,   104,   765,
     723,   679,   115,   766,   586,   680,   681,   214,   498,   171,
     724,   420,   214,   106,   500,   105,   111,   501,   173,   421,
     502,   813,   547,   503,   425,   420,   216,   107,   181,   102,
     103,   216,   214,   106,   183,   480,   108,   109,    98,    99,
     100,   101,   613,   614,   610,   112,   113,   107,   188,   300,
     300,   216,   214,   114,   -41,   541,   108,   109,   115,    86,
      94,    95,    96,   723,   189,   647,   104,    98,    99,   100,
     101,   216,   635,   800,   192,   593,   102,   103,   382,   111,
     193,   594,   660,   105,   382,   661,   156,   143,   200,   665,
     202,   667,   208,    98,    99,   100,   101,   110,   201,   111,
     675,   106,   684,   503,   686,   382,   103,   687,   112,   113,
     244,   740,   210,   104,   420,   107,   114,   246,   248,   674,
     812,   115,   260,   503,   108,   109,   264,   267,   112,   113,
     105,   102,   103,   278,   280,   281,   114,    98,    99,   100,
     101,   115,   104,   175,   176,   177,   178,   179,   106,   286,
     373,   727,   289,   373,   157,   647,   302,   156,   324,   105,
     331,   340,   107,   101,    98,   364,   365,   111,   104,   369,
     306,   108,   109,   751,   370,   102,   103,   206,   312,   313,
     314,   315,   316,   317,   374,   105,   376,   758,   381,   382,
     727,   107,   217,   389,   384,   448,   112,   113,   393,   394,
     108,   109,   398,   106,   114,   401,   408,   405,   406,   115,
     411,   776,   104,   779,   111,   412,   338,   107,   214,   428,
     431,   241,   218,   432,   433,   436,   108,   109,   454,   105,
     257,   451,   452,   458,   459,    15,   460,   791,   465,   473,
     474,   482,   484,   112,   113,   497,   499,   106,   504,   509,
     506,   114,   727,   420,   513,   518,   115,   520,   522,   524,
     525,   107,   529,   535,   199,   543,   536,   219,   544,   111,
     108,   109,   112,   113,   550,   545,   546,   559,   563,   581,
     114,   587,   554,   584,   591,   115,   582,   592,   220,   595,
     611,   616,   617,   620,   621,   622,   221,   222,   112,   113,
     623,   626,   627,   223,   224,   625,   114,   648,   631,   637,
     640,   115,  -435,   111,   641,   649,   650,   658,   657,     1,
     663,   666,   575,   668,   503,   676,   685,     2,     3,   678,
     692,   699,   719,   705,     4,   718,   734,   737,     5,   748,
     421,   743,   112,   113,     6,   741,   747,     7,     8,   749,
     114,   742,   753,   752,   754,   115,   755,     9,    10,   756,
     757,   761,   777,   225,   226,   227,   762,   771,    11,   763,
     780,    12,   228,   229,   230,   231,   232,   784,   798,   233,
     234,   804,   235,   236,   237,   238,   239,   240,     1,   241,
     803,   805,   245,   808,    13,   301,     2,     3,   809,   811,
     303,   733,   553,     4,   790,   154,   549,     5,   670,    14,
     716,   392,   404,     6,   673,    15,     7,     8,   624,   703,
     523,    16,   258,   218,   615,   467,     9,    10,   377,   781,
     802,   799,   783,   760,   388,   810,   368,    11,   558,   483,
      12,   590,   320,   539,   293,     0,     0,     0,   654,     0,
       0,   218,     0,     0,    17,    18,     0,     0,     0,     0,
       0,    19,    20,    13,     0,     0,    21,     0,   219,     0,
       0,     0,     0,     0,     0,     0,     0,     0,    14,     0,
       0,     0,   426,     0,    15,     0,     0,    22,    23,   325,
      16,     0,     0,    24,    25,     0,   219,   218,   222,    26,
       0,     0,     0,     0,   223,   224,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,   325,     0,     0,
       0,     0,     0,    17,    18,     0,   222,     0,     0,     0,
      19,    20,   223,   224,     0,    21,     0,     0,     0,     0,
       0,     0,  -436,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,    22,    23,     0,     0,
       0,     0,    24,    25,   225,   226,   227,     0,    26,     0,
       0,     0,   222,   228,   229,   230,   231,   232,   223,  -436,
     233,   234,     0,   235,   236,   237,   238,   239,   240,     0,
     241,     0,   225,   226,   227,     0,     0,     0,     0,     0,
       0,   228,   229,   230,   231,   232,     0,     0,   233,   234,
       0,   235,   236,   237,   238,   239,   240,     0,   241,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,  -436,  -436,
    -436,     0,     0,     0,     0,     0,     0,  -436,  -436,  -436,
     231,   232,     0,     0,   233,   234,     0,   235,   236,   237,
     238,   239,   240,     0,   241
};

static const yytype_int16 yycheck[] =
{
      22,     3,   282,   114,     6,   163,   403,   190,   191,    11,
     372,   308,   404,     4,     4,   377,    18,   170,   280,   581,
     582,    51,    23,     3,    25,     5,     6,    12,    14,     4,
       4,    76,    18,    76,     3,     4,     5,     6,    56,     4,
       4,    44,     4,   340,    56,     4,   157,   170,   170,   106,
     106,    34,   616,    85,    92,   106,   118,    55,    25,   144,
      26,   244,    19,   170,    48,   277,   772,   773,   125,   125,
      72,   368,    41,    42,   125,    77,   124,    81,   106,    81,
     215,    25,   104,   121,   112,   220,   118,    83,   110,   200,
     195,   797,   114,    60,    70,     4,    53,   280,    65,     3,
       4,     5,     6,   107,    71,    72,   102,   217,   193,    78,
     220,   216,     4,   109,    33,    95,    60,    21,   271,    86,
     125,    65,   106,    90,    91,   689,    95,    71,    72,   115,
      14,   428,    36,   525,    18,   128,    70,     4,   535,    58,
     141,   125,    86,   126,   113,   196,    90,    91,   271,   271,
     106,   106,   106,   155,   216,   106,   136,   137,   127,   157,
     217,   217,    47,   610,   271,   167,   168,   136,   137,   125,
     125,   125,   220,   191,   125,   220,   138,   220,   206,   191,
     202,   167,   184,   185,   216,   186,   216,    67,   210,   217,
     188,   219,   214,   405,   216,   223,   224,   225,   226,   227,
     228,   229,   230,   231,   232,   233,   234,   235,   236,   237,
     238,   239,   240,   324,   215,   180,   180,   220,   177,   304,
     124,   214,    85,   128,   382,   216,   216,   589,   162,   340,
     510,   115,   217,   386,   209,   209,   798,   122,   157,   208,
     209,   221,    31,   128,   220,   692,   693,   216,   567,     4,
     217,    51,   221,   220,    73,   366,   278,    57,     4,   197,
     522,   217,   217,   217,   266,    54,   217,    36,    63,   661,
      36,   668,    85,    20,    21,    49,   220,    46,   216,    26,
      46,   197,   101,   167,    73,   165,    73,    56,   685,   169,
      56,   171,    83,   740,     3,     4,     5,     6,   499,   321,
     322,   620,   106,   504,   220,   458,   113,   212,    17,   214,
     338,   102,   101,    95,   118,   200,   201,   428,   109,   204,
     205,   125,   207,   208,   209,   210,   211,   212,   329,   214,
     104,   113,    41,    42,   103,    90,   155,   103,   128,   522,
     109,   499,     4,   662,    90,   742,   504,    94,    95,    96,
       3,     4,     5,     6,   376,   183,   378,   379,   655,   721,
     657,   738,   739,     0,    36,     9,   155,   156,   163,    78,
     767,   178,   167,   770,     9,    27,   398,   172,   102,   219,
     149,   678,   106,   149,    56,    81,    95,     4,    41,    42,
     412,   413,   414,   106,   595,   675,    40,   774,   426,   103,
     402,   125,    54,    24,   113,    40,   686,     4,   805,    30,
     106,   107,   125,     3,     4,     5,     6,    38,   127,   209,
     210,   211,   212,    89,   214,    78,    70,   136,   137,   125,
      74,   241,     4,     3,     4,     5,     6,   595,   248,    74,
     218,    62,    95,    95,    48,    36,    79,    80,   728,    99,
     106,    41,    42,   216,   163,    46,   106,   459,    79,   481,
     113,   113,    66,   465,   173,    56,   118,   106,   154,   125,
     179,    41,    42,    94,   127,   125,   216,    98,   218,   118,
      99,   442,   120,   136,   137,   446,   125,   106,    78,    64,
     111,   513,   144,    85,   146,    73,   518,   519,   609,   208,
     209,     3,     4,     5,     6,    95,   125,   216,    78,   165,
     163,   166,   221,   169,   536,   170,   171,   106,   217,   155,
     173,   220,   106,   113,   217,    95,   179,   220,   108,   118,
     217,   811,   217,   220,   118,   220,   125,   127,   115,    41,
      42,   125,   106,   113,   120,   109,   136,   137,     3,     4,
       5,     6,   193,   194,   556,   208,   209,   127,   118,   190,
     191,   125,   106,   216,   218,   109,   136,   137,   221,   183,
     184,   185,   186,   163,   220,   597,    78,     3,     4,     5,
       6,   125,   584,   173,   218,   217,    41,    42,   220,   179,
     126,   217,   217,    95,   220,   220,    51,     4,   216,   621,
     102,   623,   214,     3,     4,     5,     6,   177,   216,   179,
     217,   113,   217,   220,   217,   220,    42,   220,   208,   209,
      89,   217,   216,    78,   220,   127,   216,    88,   117,   631,
     217,   221,     4,   220,   136,   137,     3,   113,   208,   209,
      95,    41,    42,    76,    84,     4,   216,     3,     4,     5,
       6,   221,    78,   148,   149,   150,   151,   152,   113,    41,
     255,   683,     4,   258,   216,   687,     4,    51,   216,    95,
     217,   216,   127,     6,     3,   216,   216,   179,    78,   217,
      12,   136,   137,   705,   217,    41,    42,   113,   130,   131,
     132,   133,   134,   135,   105,    95,   119,   719,   217,   220,
     722,   127,    17,     4,    41,   105,   208,   209,   219,     4,
     136,   137,   197,   113,   216,    34,   161,   218,   217,   221,
     217,   743,    78,   745,   179,    85,    92,   127,   106,   216,
      95,   214,    47,   215,     4,     4,   136,   137,     4,    95,
      70,    75,   116,   118,   124,   103,   219,   769,    89,   216,
     160,   217,     4,   208,   209,   217,   216,   113,   216,    85,
     124,   216,   784,   220,   220,    48,   221,     4,    84,   217,
     220,   127,   123,   126,   218,   216,    76,    92,   216,   179,
     136,   137,   208,   209,     4,   217,   217,   192,   216,   216,
     216,     4,   147,   124,     6,   221,   123,     6,   113,   216,
      63,   112,   124,    95,   216,   145,   121,   122,   208,   209,
     216,   220,   124,   128,   129,   112,   216,    71,   139,   217,
     217,   221,     0,   179,   217,    71,    71,   174,   119,     7,
     147,   118,   138,   216,   220,   110,   115,    15,    16,   119,
     217,     4,   102,   216,    22,   158,     4,    90,    26,   220,
     118,   124,   208,   209,    32,   178,   118,    35,    36,   153,
     216,   119,    95,   217,   140,   221,    95,    45,    46,   140,
     159,   159,    75,   188,   189,   190,   169,   195,    56,   164,
     216,    59,   197,   198,   199,   200,   201,   106,   216,   204,
     205,   168,   207,   208,   209,   210,   211,   212,     7,   214,
     159,   115,   150,   217,    82,   191,    15,    16,   165,   805,
     192,   687,   505,    22,   767,    42,   501,    26,   626,    97,
     674,   271,   285,    32,   629,   103,    35,    36,   573,   663,
     454,   109,   160,    47,   563,   399,    45,    46,   258,   748,
     784,   780,   759,   722,   269,   801,   249,    56,   513,   420,
      59,   539,   203,   476,   189,    -1,    -1,    -1,   609,    -1,
      -1,    47,    -1,    -1,   142,   143,    -1,    -1,    -1,    -1,
      -1,   149,   150,    82,    -1,    -1,   154,    -1,    92,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    97,    -1,
      -1,    -1,   106,    -1,   103,    -1,    -1,   175,   176,   113,
     109,    -1,    -1,   181,   182,    -1,    92,    47,   122,   187,
      -1,    -1,    -1,    -1,   128,   129,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,   113,    -1,    -1,
      -1,    -1,    -1,   142,   143,    -1,   122,    -1,    -1,    -1,
     149,   150,   128,   129,    -1,   154,    -1,    -1,    -1,    -1,
      -1,    -1,    92,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,   175,   176,    -1,    -1,
      -1,    -1,   181,   182,   188,   189,   190,    -1,   187,    -1,
      -1,    -1,   122,   197,   198,   199,   200,   201,   128,   129,
     204,   205,    -1,   207,   208,   209,   210,   211,   212,    -1,
     214,    -1,   188,   189,   190,    -1,    -1,    -1,    -1,    -1,
      -1,   197,   198,   199,   200,   201,    -1,    -1,   204,   205,
      -1,   207,   208,   209,   210,   211,   212,    -1,   214,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,   188,   189,
     190,    -1,    -1,    -1,    -1,    -1,    -1,   197,   198,   199,
     200,   201,    -1,    -1,   204,   205,    -1,   207,   208,   209,
     210,   211,   212,    -1,   214
};

/* YYSTOS[STATE-NUM] -- The symbol kind of the accessing symbol of
   state STATE-NUM.  */
static const yytype_int16 yystos[] =
{
       0,     7,    15,    16,    22,    26,    32,    35,    36,    45,
      46,    56,    59,    82,    97,   103,   109,   142,   143,   149,
     150,   154,   175,   176,   181,   182,   187,   223,   224,   225,
     226,   227,   229,   230,   231,   232,   233,   238,   239,   242,
     244,   245,   259,   261,   262,   265,   266,   268,   303,   305,
     306,   307,   309,   311,   314,   389,   390,    26,     4,   386,
     386,     4,     4,   386,    31,    54,    73,   101,   156,   280,
     282,   283,    85,    85,   125,   385,   386,    73,    73,   101,
     155,    19,    53,     4,   391,   392,   183,   240,     4,   234,
     236,   237,   386,   240,   184,   185,   186,   240,     3,     4,
       5,     6,    41,    42,    78,    95,   113,   127,   136,   137,
     177,   179,   208,   209,   216,   221,   351,   352,   353,   354,
     355,   356,   357,   358,   359,   361,   362,   363,   366,   368,
     369,   370,   371,   372,   373,   374,   375,   376,   377,   378,
       4,   177,   236,     4,   180,   228,   236,   243,   240,     0,
     219,   394,   103,   256,   256,    89,    51,   216,   315,   317,
     321,     4,   218,   216,    85,    73,   120,   293,   293,    64,
     154,   155,   386,   108,   263,   148,   149,   150,   151,   152,
     300,   115,   386,   120,   304,   304,   304,   386,   118,   220,
     197,   216,   218,   126,   241,   240,   240,   240,   216,   218,
     216,   216,   102,   351,   360,    41,   113,   352,   214,   351,
     216,   352,   317,   351,   106,   118,   125,    17,    47,    92,
     113,   121,   122,   128,   129,   188,   189,   190,   197,   198,
     199,   200,   201,   204,   205,   207,   208,   209,   210,   211,
     212,   214,   236,   228,    89,   225,    88,   386,   117,   345,
     315,   317,     9,    40,    74,   318,   319,    70,   318,   341,
       4,   348,   349,   372,     3,   260,   293,   113,   386,   386,
     293,   290,   291,   305,   307,   311,   314,   293,    76,   338,
      84,     4,   312,   313,    49,   104,    41,   386,   386,     4,
     236,   284,   315,   392,     4,    21,    36,   124,   235,   373,
     375,   235,     4,   237,   180,   228,    12,   217,   334,     4,
     209,   317,   130,   131,   132,   133,   134,   135,   367,   351,
     360,    83,   102,   109,   216,   113,   347,   350,   351,   118,
     351,   217,   217,   351,   236,   351,   352,   352,    92,   121,
     216,    95,   113,   352,   352,   352,   352,   352,   352,   352,
     352,   352,   352,   352,   352,   352,   352,   352,   352,   352,
     352,   376,   264,   373,   216,   216,   310,   376,   334,   217,
     217,   315,   316,   321,   105,   320,   119,   316,    48,    66,
     346,   217,   220,   386,    41,    85,   118,   216,   310,     4,
     281,   109,   291,   219,     4,   284,   351,   264,   197,   220,
     338,    34,   126,   267,   267,   218,   217,   228,   161,   365,
     347,   217,    85,    99,    83,   109,   351,   351,   317,   215,
     220,   118,   387,   388,   236,   118,   106,   352,   216,   317,
     347,    95,   215,     4,   257,   258,     4,   395,    57,   317,
     335,   347,   341,   342,   343,   351,   341,   351,   105,   351,
     372,    75,   116,   314,     4,   269,   294,   295,   118,   124,
     219,    33,    58,   157,   285,    89,   351,   313,   386,     4,
     371,   295,   284,   216,   160,   364,   217,   351,   351,   351,
     109,    99,   217,   350,     4,    24,    30,    38,    62,    79,
      94,    98,   111,   302,   352,   317,   347,   217,   217,   216,
     217,   220,   217,   220,   216,   308,   124,   246,   247,    85,
     336,   337,   346,   220,    81,   107,   344,   346,    48,    48,
       4,   292,    84,   302,   217,   220,   270,   314,   386,   123,
      36,    46,    56,   286,   386,   126,    76,     4,   216,   365,
     217,   109,   351,   216,   216,   217,   217,   217,   349,   258,
       4,   349,   220,   246,   147,   379,   380,   338,   343,   192,
     252,   351,   351,   216,   264,    27,    54,    95,   113,   118,
     144,   146,   296,   297,   298,   138,   271,   272,   273,   274,
     295,   216,   123,   287,   124,   371,   351,     4,   325,   326,
     364,     6,     6,   217,   217,   216,   195,   216,    25,    60,
      65,    71,    72,    86,    90,    91,   220,   381,   393,   216,
     386,    63,   339,   193,   194,   294,   112,   124,   299,   299,
      95,   216,   145,   216,   298,   112,   220,   124,   276,   277,
     278,   139,   275,   395,   395,   386,   217,   217,   162,   341,
     217,   217,   349,    56,   191,   248,   249,   351,    71,    71,
      71,     4,    90,   317,   379,   216,   388,   119,   174,   322,
     217,   220,   344,   147,   299,   351,   118,   351,   216,   279,
     272,    36,    56,   278,   386,   217,   110,   288,   119,   166,
     170,   171,   327,   328,   217,   115,   217,   220,   196,   250,
       4,    90,   217,   217,   347,   113,   178,   382,   347,     4,
     323,   324,   299,   300,   217,   216,   217,   371,    14,    18,
     115,   167,    14,    18,   115,   167,   279,   338,   158,   102,
     289,   347,    17,   163,   173,   329,   331,   351,   251,   253,
     254,   371,   338,   249,     4,   255,   344,    90,   388,   388,
     217,   178,   119,   124,   383,    44,   340,   118,   220,   153,
     301,   351,   217,    95,   140,    95,   140,   159,   351,   341,
     329,   159,   169,   164,   332,   165,   169,   220,   338,   197,
     220,   195,   383,   383,   388,   371,   351,    75,   384,   351,
     216,   324,   217,   327,   106,    63,   163,   167,   172,   333,
     253,   351,   371,    56,   191,   384,   384,   383,   216,   325,
     173,   330,   331,   159,   168,   115,   384,   395,   217,   165,
     332,   251,   217,   338
};

/* YYR1[RULE-NUM] -- Symbol kind of the left-hand side of rule RULE-NUM.  */
static const yytype_int16 yyr1[] =
{
       0,   222,   223,   224,   224,   225,   225,   225,   225,   226,
     226,   226,   226,   226,   226,   226,   226,   226,   226,   227,
     227,   228,   229,   229,   229,   230,   230,   231,   231,   232,
     232,   233,   233,   234,   234,   235,   235,   235,   235,   235,
     235,   236,   237,   238,   238,   238,   238,   238,   238,   238,
     238,   238,   238,   239,   240,   240,   241,   241,   241,   242,
     242,   243,   243,   244,   244,   244,   244,   245,   245,   246,
     246,   247,   247,   247,   247,   248,   248,   249,   250,   250,
     251,   251,   252,   252,   252,   253,   254,   254,   255,   256,
     256,   257,   257,   258,   258,   259,   260,   261,   261,   262,
     263,   264,   265,   265,   265,   266,   266,   266,   267,   267,
     268,   268,   268,   268,   268,   268,   268,   268,   269,   270,
     270,   271,   271,   272,   273,   274,   275,   276,   276,   277,
     277,   278,   278,   278,   278,   278,   278,   278,   278,   279,
     280,   280,   281,   282,   283,   283,   284,   285,   285,   285,
     285,   286,   286,   286,   287,   287,   288,   288,   289,   289,
     290,   290,   291,   291,   291,   291,   292,   293,   293,   294,
     294,   295,   296,   296,   297,   297,   298,   298,   298,   298,
     298,   298,   298,   299,   299,   300,   300,   300,   300,   300,
     301,   301,   302,   302,   302,   302,   302,   302,   302,   302,
     302,   303,   303,   303,   303,   303,   304,   304,   305,   306,
     307,   307,   308,   308,   309,   309,   309,   310,   310,   311,
     312,   312,   313,   314,   314,   314,   315,   315,   316,   316,
     317,   317,   318,   319,   319,   319,   320,   320,   321,   321,
     322,   323,   323,   324,   325,   325,   326,   326,   327,   327,
     327,   328,   328,   328,   329,   329,   330,   330,   331,   331,
     331,   332,   332,   333,   333,   333,   333,   334,   334,   335,
     336,   336,   337,   338,   338,   339,   339,   340,   340,   341,
     341,   342,   342,   343,   344,   344,   344,   345,   345,   346,
     346,   346,   346,   346,   346,   347,   347,   348,   348,   349,
     349,   350,   351,   351,   351,   351,   351,   351,   352,   352,
     352,   352,   352,   352,   352,   352,   352,   352,   353,   354,
     354,   355,   355,   355,   355,   355,   356,   356,   356,   356,
     356,   356,   356,   356,   356,   356,   356,   356,   356,   356,
     357,   357,   358,   358,   358,   358,   359,   359,   359,   359,
     360,   360,   361,   361,   362,   362,   362,   362,   362,   362,
     362,   363,   363,   364,   364,   364,   365,   365,   366,   367,
     367,   367,   367,   367,   367,   368,   369,   370,   371,   371,
     371,   371,   372,   372,   372,   372,   372,   373,   374,   374,
     375,   375,   376,   377,   378,   379,   379,   379,   379,   380,
     380,   381,   381,   381,   381,   381,   382,   382,   382,   383,
     383,   384,   384,   385,   386,   386,   387,   388,   388,   389,
     389,   390,   391,   391,   392,   393,   393,   393,   393,   393,
     393,   393,   393,   393,   393,   394,   394,   395,   395
};

/* YYR2[RULE-NUM] -- Number of symbols on the right-hand side of rule RULE-NUM.  */
static const yytype_int8 yyr2[] =
{
       0,     2,     2,     1,     3,     2,     2,     1,     1,     1,
       1,     1,     1,     1,     1,     1,     1,     1,     1,     3,
       2,     1,     2,     4,     5,     1,     2,     1,     2,     4,
       5,     2,     3,     1,     3,     1,     1,     1,     1,     1,
       1,     1,     1,     1,     1,     1,     1,     1,     1,     1,
       1,     1,     1,     3,     1,     0,     2,     3,     0,     4,
       2,     1,     0,     2,     3,     3,     3,     2,     2,     1,
       0,     4,     7,     8,    11,     1,     3,     3,     2,     0,
       1,     3,     2,     2,     0,     3,     1,     3,     1,     5,
       0,     1,     3,     1,     4,     4,     1,     2,     5,     7,
       1,     1,     2,     3,     2,     6,     8,     6,     1,     0,
       8,     7,     6,     7,    11,     7,    10,     5,     2,     2,
       0,     3,     1,     2,     2,     3,     3,     1,     0,     2,
       1,     3,     4,     3,     4,     3,     4,     3,     4,     3,
       1,     0,     1,    10,     1,     0,     1,     1,     1,     2,
       0,     1,     1,     2,     2,     0,     3,     0,     2,     0,
       2,     3,     1,     1,     1,     1,     1,     3,     0,     1,
       3,     3,     1,     0,     2,     1,     2,     3,     5,     2,
       6,     4,     4,     3,     0,     1,     1,     1,     1,     1,
       1,     0,     1,     1,     1,     1,     1,     4,     4,     1,
       0,     4,     4,     3,     6,     4,     2,     0,     4,     2,
       7,     6,     3,     5,     1,     1,     3,     3,     0,     5,
       1,     3,     3,     2,     2,     6,     3,     3,     1,     1,
       3,     5,     2,     1,     1,     1,     1,     0,     7,     8,
       2,     1,     3,     5,     6,     3,     1,     0,     3,     6,
       0,     1,     1,     1,     1,     2,     1,     2,     2,     2,
       2,     2,     0,     2,     2,     1,     1,     1,     0,     1,
       1,     0,     2,     2,     0,     4,     0,     2,     0,     3,
       0,     1,     3,     3,     1,     1,     0,     2,     0,     2,
       2,     4,     2,     4,     0,     1,     3,     1,     0,     1,
       3,     2,     1,     1,     1,     1,     1,     1,     3,     1,
       1,     1,     1,     1,     1,     1,     1,     3,     6,     1,
       1,     2,     2,     2,     3,     4,     1,     3,     3,     3,
       3,     3,     3,     3,     4,     3,     3,     3,     3,     3,
       3,     3,     5,     6,     5,     6,     4,     6,     3,     5,
       4,     5,     4,     5,     3,     3,     3,     3,     3,     3,
       3,     5,     7,     4,     2,     0,     5,     0,     6,     1,
       1,     1,     1,     1,     1,     4,     4,     5,     1,     3,
       1,     3,     1,     1,     1,     1,     1,     1,     1,     1,
       1,     1,     1,     1,     1,     6,     8,     7,     7,     2,
       0,     1,     1,     2,     3,     4,     3,     2,     0,     2,
       0,     4,     0,     1,     1,     3,     2,     1,     0,     1,
       0,     2,     1,     3,     3,     1,     2,     1,     2,     1,
       2,     1,     1,     1,     1,     1,     0,     1,     3
};


enum { YYENOMEM = -2 };

#define yyerrok         (yyerrstatus = 0)
#define yyclearin       (yychar = SQL_HSQL_EMPTY)

#define YYACCEPT        goto yyacceptlab
#define YYABORT         goto yyabortlab
#define YYERROR         goto yyerrorlab
#define YYNOMEM         goto yyexhaustedlab


#define YYRECOVERING()  (!!yyerrstatus)

#define YYBACKUP(Token, Value)                                    \
  do                                                              \
    if (yychar == SQL_HSQL_EMPTY)                                        \
      {                                                           \
        yychar = (Token);                                         \
        yylval = (Value);                                         \
        YYPOPSTACK (yylen);                                       \
        yystate = *yyssp;                                         \
        goto yybackup;                                            \
      }                                                           \
    else                                                          \
      {                                                           \
        yyerror (&yylloc, result, scanner, YY_("syntax error: cannot back up")); \
        YYERROR;                                                  \
      }                                                           \
  while (0)

/* Backward compatibility with an undocumented macro.
   Use SQL_HSQL_error or SQL_HSQL_UNDEF. */
#define YYERRCODE SQL_HSQL_UNDEF

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
#if HSQL_DEBUG

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

#  elif defined HSQL_LTYPE_IS_TRIVIAL && HSQL_LTYPE_IS_TRIVIAL

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
                  Kind, Value, Location, result, scanner); \
      YYFPRINTF (stderr, "\n");                                           \
    }                                                                     \
} while (0)


/*-----------------------------------.
| Print this symbol's value on YYO.  |
`-----------------------------------*/

static void
yy_symbol_value_print (FILE *yyo,
                       yysymbol_kind_t yykind, YYSTYPE const * const yyvaluep, YYLTYPE const * const yylocationp, Program * result, yyscan_t scanner)
{
  FILE *yyoutput = yyo;
  YY_USE (yyoutput);
  YY_USE (yylocationp);
  YY_USE (result);
  YY_USE (scanner);
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
                 yysymbol_kind_t yykind, YYSTYPE const * const yyvaluep, YYLTYPE const * const yylocationp, Program * result, yyscan_t scanner)
{
  YYFPRINTF (yyo, "%s %s (",
             yykind < YYNTOKENS ? "token" : "nterm", yysymbol_name (yykind));

  YYLOCATION_PRINT (yyo, yylocationp);
  YYFPRINTF (yyo, ": ");
  yy_symbol_value_print (yyo, yykind, yyvaluep, yylocationp, result, scanner);
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
                 int yyrule, Program * result, yyscan_t scanner)
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
                       &(yylsp[(yyi + 1) - (yynrhs)]), result, scanner);
      YYFPRINTF (stderr, "\n");
    }
}

# define YY_REDUCE_PRINT(Rule)          \
do {                                    \
  if (yydebug)                          \
    yy_reduce_print (yyssp, yyvsp, yylsp, Rule, result, scanner); \
} while (0)

/* Nonzero means print parse trace.  It is left uninitialized so that
   multiple parsers can coexist.  */
int yydebug;
#else /* !HSQL_DEBUG */
# define YYDPRINTF(Args) ((void) 0)
# define YY_SYMBOL_PRINT(Title, Kind, Value, Location)
# define YY_STACK_PRINT(Bottom, Top)
# define YY_REDUCE_PRINT(Rule)
#endif /* !HSQL_DEBUG */


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
            yysymbol_kind_t yykind, YYSTYPE *yyvaluep, YYLTYPE *yylocationp, Program * result, yyscan_t scanner)
{
  YY_USE (yyvaluep);
  YY_USE (yylocationp);
  YY_USE (result);
  YY_USE (scanner);
  if (!yymsg)
    yymsg = "Deleting";
  YY_SYMBOL_PRINT (yymsg, yykind, yyvaluep, yylocationp);

  YY_IGNORE_MAYBE_UNINITIALIZED_BEGIN
  switch (yykind)
    {
    case YYSYMBOL_STRING: /* STRING  */
#line 525 "bison_parser.y"
            { free( (((*yyvaluep).sval)) ); }
#line 2304 "bison_parser.cpp"
        break;

    case YYSYMBOL_IDENTIFIER: /* IDENTIFIER  */
#line 525 "bison_parser.y"
            { free( (((*yyvaluep).sval)) ); }
#line 2310 "bison_parser.cpp"
        break;

    case YYSYMBOL_FLOATVAL: /* FLOATVAL  */
#line 524 "bison_parser.y"
            { }
#line 2316 "bison_parser.cpp"
        break;

    case YYSYMBOL_INTVAL: /* INTVAL  */
#line 524 "bison_parser.y"
            { }
#line 2322 "bison_parser.cpp"
        break;

    case YYSYMBOL_input: /* input  */
#line 524 "bison_parser.y"
            { }
#line 2328 "bison_parser.cpp"
        break;

    case YYSYMBOL_statement_list: /* statement_list  */
#line 564 "bison_parser.y"
            { if(((*yyvaluep).statement_list_t)!=NULL)((*yyvaluep).statement_list_t)->deep_delete(); }
#line 2334 "bison_parser.cpp"
        break;

    case YYSYMBOL_statement: /* statement  */
#line 564 "bison_parser.y"
            { if(((*yyvaluep).statement_t)!=NULL)((*yyvaluep).statement_t)->deep_delete(); }
#line 2340 "bison_parser.cpp"
        break;

    case YYSYMBOL_cmd: /* cmd  */
#line 564 "bison_parser.y"
            { if(((*yyvaluep).cmd_t)!=NULL)((*yyvaluep).cmd_t)->deep_delete(); }
#line 2346 "bison_parser.cpp"
        break;

    case YYSYMBOL_cmd_release: /* cmd_release  */
#line 564 "bison_parser.y"
            { if(((*yyvaluep).cmd_release_t)!=NULL)((*yyvaluep).cmd_release_t)->deep_delete(); }
#line 2352 "bison_parser.cpp"
        break;

    case YYSYMBOL_savepoint_name: /* savepoint_name  */
#line 564 "bison_parser.y"
            { if(((*yyvaluep).savepoint_name_t)!=NULL)((*yyvaluep).savepoint_name_t)->deep_delete(); }
#line 2358 "bison_parser.cpp"
        break;

    case YYSYMBOL_cmd_pragma: /* cmd_pragma  */
#line 564 "bison_parser.y"
            { if(((*yyvaluep).cmd_pragma_t)!=NULL)((*yyvaluep).cmd_pragma_t)->deep_delete(); }
#line 2364 "bison_parser.cpp"
        break;

    case YYSYMBOL_cmd_reindex: /* cmd_reindex  */
#line 564 "bison_parser.y"
            { if(((*yyvaluep).cmd_reindex_t)!=NULL)((*yyvaluep).cmd_reindex_t)->deep_delete(); }
#line 2370 "bison_parser.cpp"
        break;

    case YYSYMBOL_cmd_analyze: /* cmd_analyze  */
#line 564 "bison_parser.y"
            { if(((*yyvaluep).cmd_analyze_t)!=NULL)((*yyvaluep).cmd_analyze_t)->deep_delete(); }
#line 2376 "bison_parser.cpp"
        break;

    case YYSYMBOL_cmd_attach: /* cmd_attach  */
#line 564 "bison_parser.y"
            { if(((*yyvaluep).cmd_attach_t)!=NULL)((*yyvaluep).cmd_attach_t)->deep_delete(); }
#line 2382 "bison_parser.cpp"
        break;

    case YYSYMBOL_cmd_detach: /* cmd_detach  */
#line 564 "bison_parser.y"
            { if(((*yyvaluep).cmd_detach_t)!=NULL)((*yyvaluep).cmd_detach_t)->deep_delete(); }
#line 2388 "bison_parser.cpp"
        break;

    case YYSYMBOL_pragma_key: /* pragma_key  */
#line 564 "bison_parser.y"
            { if(((*yyvaluep).pragma_key_t)!=NULL)((*yyvaluep).pragma_key_t)->deep_delete(); }
#line 2394 "bison_parser.cpp"
        break;

    case YYSYMBOL_pragma_value: /* pragma_value  */
#line 564 "bison_parser.y"
            { if(((*yyvaluep).pragma_value_t)!=NULL)((*yyvaluep).pragma_value_t)->deep_delete(); }
#line 2400 "bison_parser.cpp"
        break;

    case YYSYMBOL_schema_name: /* schema_name  */
#line 564 "bison_parser.y"
            { if(((*yyvaluep).schema_name_t)!=NULL)((*yyvaluep).schema_name_t)->deep_delete(); }
#line 2406 "bison_parser.cpp"
        break;

    case YYSYMBOL_pragma_name: /* pragma_name  */
#line 564 "bison_parser.y"
            { if(((*yyvaluep).pragma_name_t)!=NULL)((*yyvaluep).pragma_name_t)->deep_delete(); }
#line 2412 "bison_parser.cpp"
        break;

    case YYSYMBOL_preparable_statement: /* preparable_statement  */
#line 564 "bison_parser.y"
            { if(((*yyvaluep).preparable_statement_t)!=NULL)((*yyvaluep).preparable_statement_t)->deep_delete(); }
#line 2418 "bison_parser.cpp"
        break;

    case YYSYMBOL_rollback_statement: /* rollback_statement  */
#line 564 "bison_parser.y"
            { if(((*yyvaluep).rollback_statement_t)!=NULL)((*yyvaluep).rollback_statement_t)->deep_delete(); }
#line 2424 "bison_parser.cpp"
        break;

    case YYSYMBOL_opt_transaction: /* opt_transaction  */
#line 564 "bison_parser.y"
            { if(((*yyvaluep).opt_transaction_t)!=NULL)((*yyvaluep).opt_transaction_t)->deep_delete(); }
#line 2430 "bison_parser.cpp"
        break;

    case YYSYMBOL_opt_to_savepoint: /* opt_to_savepoint  */
#line 564 "bison_parser.y"
            { if(((*yyvaluep).opt_to_savepoint_t)!=NULL)((*yyvaluep).opt_to_savepoint_t)->deep_delete(); }
#line 2436 "bison_parser.cpp"
        break;

    case YYSYMBOL_vacuum_statement: /* vacuum_statement  */
#line 564 "bison_parser.y"
            { if(((*yyvaluep).vacuum_statement_t)!=NULL)((*yyvaluep).vacuum_statement_t)->deep_delete(); }
#line 2442 "bison_parser.cpp"
        break;

    case YYSYMBOL_opt_schema_name: /* opt_schema_name  */
#line 564 "bison_parser.y"
            { if(((*yyvaluep).opt_schema_name_t)!=NULL)((*yyvaluep).opt_schema_name_t)->deep_delete(); }
#line 2448 "bison_parser.cpp"
        break;

    case YYSYMBOL_begin_statement: /* begin_statement  */
#line 564 "bison_parser.y"
            { if(((*yyvaluep).begin_statement_t)!=NULL)((*yyvaluep).begin_statement_t)->deep_delete(); }
#line 2454 "bison_parser.cpp"
        break;

    case YYSYMBOL_commit_statement: /* commit_statement  */
#line 564 "bison_parser.y"
            { if(((*yyvaluep).commit_statement_t)!=NULL)((*yyvaluep).commit_statement_t)->deep_delete(); }
#line 2460 "bison_parser.cpp"
        break;

    case YYSYMBOL_opt_upsert_clause: /* opt_upsert_clause  */
#line 564 "bison_parser.y"
            { if(((*yyvaluep).opt_upsert_clause_t)!=NULL)((*yyvaluep).opt_upsert_clause_t)->deep_delete(); }
#line 2466 "bison_parser.cpp"
        break;

    case YYSYMBOL_upsert_clause: /* upsert_clause  */
#line 564 "bison_parser.y"
            { if(((*yyvaluep).upsert_clause_t)!=NULL)((*yyvaluep).upsert_clause_t)->deep_delete(); }
#line 2472 "bison_parser.cpp"
        break;

    case YYSYMBOL_indexed_column_list: /* indexed_column_list  */
#line 564 "bison_parser.y"
            { if(((*yyvaluep).indexed_column_list_t)!=NULL)((*yyvaluep).indexed_column_list_t)->deep_delete(); }
#line 2478 "bison_parser.cpp"
        break;

    case YYSYMBOL_indexed_column: /* indexed_column  */
#line 564 "bison_parser.y"
            { if(((*yyvaluep).indexed_column_t)!=NULL)((*yyvaluep).indexed_column_t)->deep_delete(); }
#line 2484 "bison_parser.cpp"
        break;

    case YYSYMBOL_opt_collate: /* opt_collate  */
#line 564 "bison_parser.y"
            { if(((*yyvaluep).opt_collate_t)!=NULL)((*yyvaluep).opt_collate_t)->deep_delete(); }
#line 2490 "bison_parser.cpp"
        break;

    case YYSYMBOL_assign_list: /* assign_list  */
#line 564 "bison_parser.y"
            { if(((*yyvaluep).assign_list_t)!=NULL)((*yyvaluep).assign_list_t)->deep_delete(); }
#line 2496 "bison_parser.cpp"
        break;

    case YYSYMBOL_opt_null: /* opt_null  */
#line 564 "bison_parser.y"
            { if(((*yyvaluep).opt_null_t)!=NULL)((*yyvaluep).opt_null_t)->deep_delete(); }
#line 2502 "bison_parser.cpp"
        break;

    case YYSYMBOL_assign_clause: /* assign_clause  */
#line 564 "bison_parser.y"
            { if(((*yyvaluep).assign_clause_t)!=NULL)((*yyvaluep).assign_clause_t)->deep_delete(); }
#line 2508 "bison_parser.cpp"
        break;

    case YYSYMBOL_column_name_list: /* column_name_list  */
#line 564 "bison_parser.y"
            { if(((*yyvaluep).column_name_list_t)!=NULL)((*yyvaluep).column_name_list_t)->deep_delete(); }
#line 2514 "bison_parser.cpp"
        break;

    case YYSYMBOL_collation_name: /* collation_name  */
#line 564 "bison_parser.y"
            { if(((*yyvaluep).collation_name_t)!=NULL)((*yyvaluep).collation_name_t)->deep_delete(); }
#line 2520 "bison_parser.cpp"
        break;

    case YYSYMBOL_opt_hints: /* opt_hints  */
#line 564 "bison_parser.y"
            { if(((*yyvaluep).optional_hints_t)!=NULL)((*yyvaluep).optional_hints_t)->deep_delete(); }
#line 2526 "bison_parser.cpp"
        break;

    case YYSYMBOL_hint_list: /* hint_list  */
#line 564 "bison_parser.y"
            { if(((*yyvaluep).hint_list_t)!=NULL)((*yyvaluep).hint_list_t)->deep_delete(); }
#line 2532 "bison_parser.cpp"
        break;

    case YYSYMBOL_hint: /* hint  */
#line 564 "bison_parser.y"
            { if(((*yyvaluep).hint_t)!=NULL)((*yyvaluep).hint_t)->deep_delete(); }
#line 2538 "bison_parser.cpp"
        break;

    case YYSYMBOL_prepare_statement: /* prepare_statement  */
#line 564 "bison_parser.y"
            { if(((*yyvaluep).prepare_statement_t)!=NULL)((*yyvaluep).prepare_statement_t)->deep_delete(); }
#line 2544 "bison_parser.cpp"
        break;

    case YYSYMBOL_prepare_target_query: /* prepare_target_query  */
#line 564 "bison_parser.y"
            { if(((*yyvaluep).prepare_target_query_t)!=NULL)((*yyvaluep).prepare_target_query_t)->deep_delete(); }
#line 2550 "bison_parser.cpp"
        break;

    case YYSYMBOL_execute_statement: /* execute_statement  */
#line 564 "bison_parser.y"
            { if(((*yyvaluep).execute_statement_t)!=NULL)((*yyvaluep).execute_statement_t)->deep_delete(); }
#line 2556 "bison_parser.cpp"
        break;

    case YYSYMBOL_import_statement: /* import_statement  */
#line 564 "bison_parser.y"
            { if(((*yyvaluep).import_statement_t)!=NULL)((*yyvaluep).import_statement_t)->deep_delete(); }
#line 2562 "bison_parser.cpp"
        break;

    case YYSYMBOL_import_file_type: /* import_file_type  */
#line 564 "bison_parser.y"
            { if(((*yyvaluep).import_file_type_t)!=NULL)((*yyvaluep).import_file_type_t)->deep_delete(); }
#line 2568 "bison_parser.cpp"
        break;

    case YYSYMBOL_file_path: /* file_path  */
#line 564 "bison_parser.y"
            { if(((*yyvaluep).file_path_t)!=NULL)((*yyvaluep).file_path_t)->deep_delete(); }
#line 2574 "bison_parser.cpp"
        break;

    case YYSYMBOL_show_statement: /* show_statement  */
#line 564 "bison_parser.y"
            { if(((*yyvaluep).show_statement_t)!=NULL)((*yyvaluep).show_statement_t)->deep_delete(); }
#line 2580 "bison_parser.cpp"
        break;

    case YYSYMBOL_alter_statement: /* alter_statement  */
#line 564 "bison_parser.y"
            { if(((*yyvaluep).alter_statement_t)!=NULL)((*yyvaluep).alter_statement_t)->deep_delete(); }
#line 2586 "bison_parser.cpp"
        break;

    case YYSYMBOL_opt_column: /* opt_column  */
#line 564 "bison_parser.y"
            { if(((*yyvaluep).opt_column_t)!=NULL)((*yyvaluep).opt_column_t)->deep_delete(); }
#line 2592 "bison_parser.cpp"
        break;

    case YYSYMBOL_create_statement: /* create_statement  */
#line 564 "bison_parser.y"
            { if(((*yyvaluep).create_statement_t)!=NULL)((*yyvaluep).create_statement_t)->deep_delete(); }
#line 2598 "bison_parser.cpp"
        break;

    case YYSYMBOL_CreateInparan: /* CreateInparan  */
#line 564 "bison_parser.y"
            { if(((*yyvaluep).CreateInparan_t)!=NULL)((*yyvaluep).CreateInparan_t)->deep_delete(); }
#line 2604 "bison_parser.cpp"
        break;

    case YYSYMBOL_opt_ForeignKeylist: /* opt_ForeignKeylist  */
#line 564 "bison_parser.y"
            { if(((*yyvaluep).opt_ForeignKeylist_t)!=NULL)((*yyvaluep).opt_ForeignKeylist_t)->deep_delete(); }
#line 2610 "bison_parser.cpp"
        break;

    case YYSYMBOL_ForeignKeylist: /* ForeignKeylist  */
#line 564 "bison_parser.y"
            { if(((*yyvaluep).ForeignKeylist_t)!=NULL)((*yyvaluep).ForeignKeylist_t)->deep_delete(); }
#line 2616 "bison_parser.cpp"
        break;

    case YYSYMBOL_ForeignKey: /* ForeignKey  */
#line 564 "bison_parser.y"
            { if(((*yyvaluep).ForeignKey_t)!=NULL)((*yyvaluep).ForeignKey_t)->deep_delete(); }
#line 2622 "bison_parser.cpp"
        break;

    case YYSYMBOL_FkNoOptstmt: /* FkNoOptstmt  */
#line 564 "bison_parser.y"
            { if(((*yyvaluep).FkNoOptstmt_t)!=NULL)((*yyvaluep).FkNoOptstmt_t)->deep_delete(); }
#line 2628 "bison_parser.cpp"
        break;

    case YYSYMBOL_ForeignKeyColumn: /* ForeignKeyColumn  */
#line 564 "bison_parser.y"
            { if(((*yyvaluep).ForeignKeyColumn_t)!=NULL)((*yyvaluep).ForeignKeyColumn_t)->deep_delete(); }
#line 2634 "bison_parser.cpp"
        break;

    case YYSYMBOL_ForeignKeyRef: /* ForeignKeyRef  */
#line 564 "bison_parser.y"
            { if(((*yyvaluep).ForeignKeyRef_t)!=NULL)((*yyvaluep).ForeignKeyRef_t)->deep_delete(); }
#line 2640 "bison_parser.cpp"
        break;

    case YYSYMBOL_opt_Actiontypelist: /* opt_Actiontypelist  */
#line 564 "bison_parser.y"
            { if(((*yyvaluep).opt_Actiontypelist_t)!=NULL)((*yyvaluep).opt_Actiontypelist_t)->deep_delete(); }
#line 2646 "bison_parser.cpp"
        break;

    case YYSYMBOL_Action_typelist: /* Action_typelist  */
#line 564 "bison_parser.y"
            { if(((*yyvaluep).Action_typelist_t)!=NULL)((*yyvaluep).Action_typelist_t)->deep_delete(); }
#line 2652 "bison_parser.cpp"
        break;

    case YYSYMBOL_Action_type: /* Action_type  */
#line 564 "bison_parser.y"
            { if(((*yyvaluep).Action_type_t)!=NULL)((*yyvaluep).Action_type_t)->deep_delete(); }
#line 2658 "bison_parser.cpp"
        break;

    case YYSYMBOL_ColumnInParen: /* ColumnInParen  */
#line 564 "bison_parser.y"
            { if(((*yyvaluep).Column_In_Paren_t)!=NULL)((*yyvaluep).Column_In_Paren_t)->deep_delete(); }
#line 2664 "bison_parser.cpp"
        break;

    case YYSYMBOL_opt_unique: /* opt_unique  */
#line 564 "bison_parser.y"
            { if(((*yyvaluep).opt_unique_t)!=NULL)((*yyvaluep).opt_unique_t)->deep_delete(); }
#line 2670 "bison_parser.cpp"
        break;

    case YYSYMBOL_index_name: /* index_name  */
#line 564 "bison_parser.y"
            { if(((*yyvaluep).index_name_t)!=NULL)((*yyvaluep).index_name_t)->deep_delete(); }
#line 2676 "bison_parser.cpp"
        break;

    case YYSYMBOL_trigger_declare: /* trigger_declare  */
#line 564 "bison_parser.y"
            { if(((*yyvaluep).trigger_declare_t)!=NULL)((*yyvaluep).trigger_declare_t)->deep_delete(); }
#line 2682 "bison_parser.cpp"
        break;

    case YYSYMBOL_opt_tmp: /* opt_tmp  */
#line 564 "bison_parser.y"
            { if(((*yyvaluep).opt_tmp_t)!=NULL)((*yyvaluep).opt_tmp_t)->deep_delete(); }
#line 2688 "bison_parser.cpp"
        break;

    case YYSYMBOL_trigger_name: /* trigger_name  */
#line 564 "bison_parser.y"
            { if(((*yyvaluep).trigger_name_t)!=NULL)((*yyvaluep).trigger_name_t)->deep_delete(); }
#line 2694 "bison_parser.cpp"
        break;

    case YYSYMBOL_opt_trigger_time: /* opt_trigger_time  */
#line 564 "bison_parser.y"
            { if(((*yyvaluep).opt_trigger_time_t)!=NULL)((*yyvaluep).opt_trigger_time_t)->deep_delete(); }
#line 2700 "bison_parser.cpp"
        break;

    case YYSYMBOL_trigger_event: /* trigger_event  */
#line 564 "bison_parser.y"
            { if(((*yyvaluep).trigger_event_t)!=NULL)((*yyvaluep).trigger_event_t)->deep_delete(); }
#line 2706 "bison_parser.cpp"
        break;

    case YYSYMBOL_opt_of_column_list: /* opt_of_column_list  */
#line 564 "bison_parser.y"
            { if(((*yyvaluep).opt_of_column_list_t)!=NULL)((*yyvaluep).opt_of_column_list_t)->deep_delete(); }
#line 2712 "bison_parser.cpp"
        break;

    case YYSYMBOL_opt_for_each: /* opt_for_each  */
#line 564 "bison_parser.y"
            { if(((*yyvaluep).opt_for_each_t)!=NULL)((*yyvaluep).opt_for_each_t)->deep_delete(); }
#line 2718 "bison_parser.cpp"
        break;

    case YYSYMBOL_opt_when: /* opt_when  */
#line 564 "bison_parser.y"
            { if(((*yyvaluep).opt_when_t)!=NULL)((*yyvaluep).opt_when_t)->deep_delete(); }
#line 2724 "bison_parser.cpp"
        break;

    case YYSYMBOL_trigger_cmd_list: /* trigger_cmd_list  */
#line 564 "bison_parser.y"
            { if(((*yyvaluep).trigger_cmd_list_t)!=NULL)((*yyvaluep).trigger_cmd_list_t)->deep_delete(); }
#line 2730 "bison_parser.cpp"
        break;

    case YYSYMBOL_trigger_cmd: /* trigger_cmd  */
#line 564 "bison_parser.y"
            { if(((*yyvaluep).trigger_cmd_t)!=NULL)((*yyvaluep).trigger_cmd_t)->deep_delete(); }
#line 2736 "bison_parser.cpp"
        break;

    case YYSYMBOL_module_name: /* module_name  */
#line 564 "bison_parser.y"
            { if(((*yyvaluep).module_name_t)!=NULL)((*yyvaluep).module_name_t)->deep_delete(); }
#line 2742 "bison_parser.cpp"
        break;

    case YYSYMBOL_opt_not_exists: /* opt_not_exists  */
#line 564 "bison_parser.y"
            { if(((*yyvaluep).opt_not_exists_t)!=NULL)((*yyvaluep).opt_not_exists_t)->deep_delete(); }
#line 2748 "bison_parser.cpp"
        break;

    case YYSYMBOL_column_def_commalist: /* column_def_commalist  */
#line 564 "bison_parser.y"
            { if(((*yyvaluep).column_def_comma_list_t)!=NULL)((*yyvaluep).column_def_comma_list_t)->deep_delete(); }
#line 2754 "bison_parser.cpp"
        break;

    case YYSYMBOL_column_def: /* column_def  */
#line 564 "bison_parser.y"
            { if(((*yyvaluep).column_def_t)!=NULL)((*yyvaluep).column_def_t)->deep_delete(); }
#line 2760 "bison_parser.cpp"
        break;

    case YYSYMBOL_opt_column_arglist: /* opt_column_arglist  */
#line 564 "bison_parser.y"
            { if(((*yyvaluep).opt_column_arglist_t)!=NULL)((*yyvaluep).opt_column_arglist_t)->deep_delete(); }
#line 2766 "bison_parser.cpp"
        break;

    case YYSYMBOL_column_arglist: /* column_arglist  */
#line 564 "bison_parser.y"
            { if(((*yyvaluep).column_arglist_t)!=NULL)((*yyvaluep).column_arglist_t)->deep_delete(); }
#line 2772 "bison_parser.cpp"
        break;

    case YYSYMBOL_column_arg: /* column_arg  */
#line 564 "bison_parser.y"
            { if(((*yyvaluep).column_arg_t)!=NULL)((*yyvaluep).column_arg_t)->deep_delete(); }
#line 2778 "bison_parser.cpp"
        break;

    case YYSYMBOL_opt_on_conflict: /* opt_on_conflict  */
#line 564 "bison_parser.y"
            { if(((*yyvaluep).opt_on_conflict_t)!=NULL)((*yyvaluep).opt_on_conflict_t)->deep_delete(); }
#line 2784 "bison_parser.cpp"
        break;

    case YYSYMBOL_resolve_type: /* resolve_type  */
#line 564 "bison_parser.y"
            { if(((*yyvaluep).resolve_type_t)!=NULL)((*yyvaluep).resolve_type_t)->deep_delete(); }
#line 2790 "bison_parser.cpp"
        break;

    case YYSYMBOL_opt_autoinc: /* opt_autoinc  */
#line 564 "bison_parser.y"
            { if(((*yyvaluep).opt_autoinc_t)!=NULL)((*yyvaluep).opt_autoinc_t)->deep_delete(); }
#line 2796 "bison_parser.cpp"
        break;

    case YYSYMBOL_column_type: /* column_type  */
#line 564 "bison_parser.y"
            { if(((*yyvaluep).column_type_t)!=NULL)((*yyvaluep).column_type_t)->deep_delete(); }
#line 2802 "bison_parser.cpp"
        break;

    case YYSYMBOL_drop_statement: /* drop_statement  */
#line 564 "bison_parser.y"
            { if(((*yyvaluep).drop_statement_t)!=NULL)((*yyvaluep).drop_statement_t)->deep_delete(); }
#line 2808 "bison_parser.cpp"
        break;

    case YYSYMBOL_opt_exists: /* opt_exists  */
#line 564 "bison_parser.y"
            { if(((*yyvaluep).opt_exists_t)!=NULL)((*yyvaluep).opt_exists_t)->deep_delete(); }
#line 2814 "bison_parser.cpp"
        break;

    case YYSYMBOL_delete_statement: /* delete_statement  */
#line 564 "bison_parser.y"
            { if(((*yyvaluep).delete_statement_t)!=NULL)((*yyvaluep).delete_statement_t)->deep_delete(); }
#line 2820 "bison_parser.cpp"
        break;

    case YYSYMBOL_truncate_statement: /* truncate_statement  */
#line 564 "bison_parser.y"
            { if(((*yyvaluep).delete_statement_t)!=NULL)((*yyvaluep).delete_statement_t)->deep_delete(); }
#line 2826 "bison_parser.cpp"
        break;

    case YYSYMBOL_insert_statement: /* insert_statement  */
#line 564 "bison_parser.y"
            { if(((*yyvaluep).insert_statement_t)!=NULL)((*yyvaluep).insert_statement_t)->deep_delete(); }
#line 2832 "bison_parser.cpp"
        break;

    case YYSYMBOL_super_list: /* super_list  */
#line 564 "bison_parser.y"
            { if(((*yyvaluep).super_list_t)!=NULL)((*yyvaluep).super_list_t)->deep_delete(); }
#line 2838 "bison_parser.cpp"
        break;

    case YYSYMBOL_insert_type: /* insert_type  */
#line 564 "bison_parser.y"
            { if(((*yyvaluep).insert_type_t)!=NULL)((*yyvaluep).insert_type_t)->deep_delete(); }
#line 2844 "bison_parser.cpp"
        break;

    case YYSYMBOL_opt_column_list: /* opt_column_list  */
#line 564 "bison_parser.y"
            { if(((*yyvaluep).opt_column_list_t)!=NULL)((*yyvaluep).opt_column_list_t)->deep_delete(); }
#line 2850 "bison_parser.cpp"
        break;

    case YYSYMBOL_update_statement: /* update_statement  */
#line 564 "bison_parser.y"
            { if(((*yyvaluep).update_statement_t)!=NULL)((*yyvaluep).update_statement_t)->deep_delete(); }
#line 2856 "bison_parser.cpp"
        break;

    case YYSYMBOL_update_clause_commalist: /* update_clause_commalist  */
#line 564 "bison_parser.y"
            { if(((*yyvaluep).update_clause_commalist_t)!=NULL)((*yyvaluep).update_clause_commalist_t)->deep_delete(); }
#line 2862 "bison_parser.cpp"
        break;

    case YYSYMBOL_update_clause: /* update_clause  */
#line 564 "bison_parser.y"
            { if(((*yyvaluep).update_clause_t)!=NULL)((*yyvaluep).update_clause_t)->deep_delete(); }
#line 2868 "bison_parser.cpp"
        break;

    case YYSYMBOL_select_statement: /* select_statement  */
#line 564 "bison_parser.y"
            { if(((*yyvaluep).select_statement_t)!=NULL)((*yyvaluep).select_statement_t)->deep_delete(); }
#line 2874 "bison_parser.cpp"
        break;

    case YYSYMBOL_select_with_paren: /* select_with_paren  */
#line 564 "bison_parser.y"
            { if(((*yyvaluep).select_with_paren_t)!=NULL)((*yyvaluep).select_with_paren_t)->deep_delete(); }
#line 2880 "bison_parser.cpp"
        break;

    case YYSYMBOL_select_paren_or_clause: /* select_paren_or_clause  */
#line 564 "bison_parser.y"
            { if(((*yyvaluep).select_paren_or_clause_t)!=NULL)((*yyvaluep).select_paren_or_clause_t)->deep_delete(); }
#line 2886 "bison_parser.cpp"
        break;

    case YYSYMBOL_select_no_paren: /* select_no_paren  */
#line 564 "bison_parser.y"
            { if(((*yyvaluep).select_no_paren_t)!=NULL)((*yyvaluep).select_no_paren_t)->deep_delete(); }
#line 2892 "bison_parser.cpp"
        break;

    case YYSYMBOL_set_operator: /* set_operator  */
#line 564 "bison_parser.y"
            { if(((*yyvaluep).set_operator_t)!=NULL)((*yyvaluep).set_operator_t)->deep_delete(); }
#line 2898 "bison_parser.cpp"
        break;

    case YYSYMBOL_set_type: /* set_type  */
#line 564 "bison_parser.y"
            { if(((*yyvaluep).set_type_t)!=NULL)((*yyvaluep).set_type_t)->deep_delete(); }
#line 2904 "bison_parser.cpp"
        break;

    case YYSYMBOL_opt_all: /* opt_all  */
#line 564 "bison_parser.y"
            { if(((*yyvaluep).opt_all_t)!=NULL)((*yyvaluep).opt_all_t)->deep_delete(); }
#line 2910 "bison_parser.cpp"
        break;

    case YYSYMBOL_select_clause: /* select_clause  */
#line 564 "bison_parser.y"
            { if(((*yyvaluep).select_clause_t)!=NULL)((*yyvaluep).select_clause_t)->deep_delete(); }
#line 2916 "bison_parser.cpp"
        break;

    case YYSYMBOL_window_clause: /* window_clause  */
#line 564 "bison_parser.y"
            { if(((*yyvaluep).window_clause_t)!=NULL)((*yyvaluep).window_clause_t)->deep_delete(); }
#line 2922 "bison_parser.cpp"
        break;

    case YYSYMBOL_windowdefn_list: /* windowdefn_list  */
#line 564 "bison_parser.y"
            { if(((*yyvaluep).window_defn_list_t)!=NULL)((*yyvaluep).window_defn_list_t)->deep_delete(); }
#line 2928 "bison_parser.cpp"
        break;

    case YYSYMBOL_windowdefn: /* windowdefn  */
#line 564 "bison_parser.y"
            { if(((*yyvaluep).window_defn_t)!=NULL)((*yyvaluep).window_defn_t)->deep_delete(); }
#line 2934 "bison_parser.cpp"
        break;

    case YYSYMBOL_window: /* window  */
#line 564 "bison_parser.y"
            { if(((*yyvaluep).window_t)!=NULL)((*yyvaluep).window_t)->deep_delete(); }
#line 2940 "bison_parser.cpp"
        break;

    case YYSYMBOL_opt_base_window_name: /* opt_base_window_name  */
#line 564 "bison_parser.y"
            { if(((*yyvaluep).opt_base_window_name_t)!=NULL)((*yyvaluep).opt_base_window_name_t)->deep_delete(); }
#line 2946 "bison_parser.cpp"
        break;

    case YYSYMBOL_opt_frame: /* opt_frame  */
#line 564 "bison_parser.y"
            { if(((*yyvaluep).opt_frame_t)!=NULL)((*yyvaluep).opt_frame_t)->deep_delete(); }
#line 2952 "bison_parser.cpp"
        break;

    case YYSYMBOL_range_or_rows: /* range_or_rows  */
#line 564 "bison_parser.y"
            { if(((*yyvaluep).range_or_rows_t)!=NULL)((*yyvaluep).range_or_rows_t)->deep_delete(); }
#line 2958 "bison_parser.cpp"
        break;

    case YYSYMBOL_frame_bound_s: /* frame_bound_s  */
#line 564 "bison_parser.y"
            { if(((*yyvaluep).frame_bound_s_t)!=NULL)((*yyvaluep).frame_bound_s_t)->deep_delete(); }
#line 2964 "bison_parser.cpp"
        break;

    case YYSYMBOL_frame_bound_e: /* frame_bound_e  */
#line 564 "bison_parser.y"
            { if(((*yyvaluep).frame_bound_e_t)!=NULL)((*yyvaluep).frame_bound_e_t)->deep_delete(); }
#line 2970 "bison_parser.cpp"
        break;

    case YYSYMBOL_frame_bound: /* frame_bound  */
#line 564 "bison_parser.y"
            { if(((*yyvaluep).frame_bound_t)!=NULL)((*yyvaluep).frame_bound_t)->deep_delete(); }
#line 2976 "bison_parser.cpp"
        break;

    case YYSYMBOL_opt_frame_exclude: /* opt_frame_exclude  */
#line 564 "bison_parser.y"
            { if(((*yyvaluep).opt_frame_exclude_t)!=NULL)((*yyvaluep).opt_frame_exclude_t)->deep_delete(); }
#line 2982 "bison_parser.cpp"
        break;

    case YYSYMBOL_frame_exclude: /* frame_exclude  */
#line 564 "bison_parser.y"
            { if(((*yyvaluep).frame_exclude_t)!=NULL)((*yyvaluep).frame_exclude_t)->deep_delete(); }
#line 2988 "bison_parser.cpp"
        break;

    case YYSYMBOL_opt_distinct: /* opt_distinct  */
#line 564 "bison_parser.y"
            { if(((*yyvaluep).opt_distinct_t)!=NULL)((*yyvaluep).opt_distinct_t)->deep_delete(); }
#line 2994 "bison_parser.cpp"
        break;

    case YYSYMBOL_select_list: /* select_list  */
#line 564 "bison_parser.y"
            { if(((*yyvaluep).select_list_t)!=NULL)((*yyvaluep).select_list_t)->deep_delete(); }
#line 3000 "bison_parser.cpp"
        break;

    case YYSYMBOL_opt_from_clause: /* opt_from_clause  */
#line 564 "bison_parser.y"
            { if(((*yyvaluep).opt_from_clause_t)!=NULL)((*yyvaluep).opt_from_clause_t)->deep_delete(); }
#line 3006 "bison_parser.cpp"
        break;

    case YYSYMBOL_from_clause: /* from_clause  */
#line 564 "bison_parser.y"
            { if(((*yyvaluep).from_clause_t)!=NULL)((*yyvaluep).from_clause_t)->deep_delete(); }
#line 3012 "bison_parser.cpp"
        break;

    case YYSYMBOL_opt_where: /* opt_where  */
#line 564 "bison_parser.y"
            { if(((*yyvaluep).opt_where_t)!=NULL)((*yyvaluep).opt_where_t)->deep_delete(); }
#line 3018 "bison_parser.cpp"
        break;

    case YYSYMBOL_opt_group: /* opt_group  */
#line 564 "bison_parser.y"
            { if(((*yyvaluep).opt_group_t)!=NULL)((*yyvaluep).opt_group_t)->deep_delete(); }
#line 3024 "bison_parser.cpp"
        break;

    case YYSYMBOL_opt_having: /* opt_having  */
#line 564 "bison_parser.y"
            { if(((*yyvaluep).opt_having_t)!=NULL)((*yyvaluep).opt_having_t)->deep_delete(); }
#line 3030 "bison_parser.cpp"
        break;

    case YYSYMBOL_opt_order: /* opt_order  */
#line 564 "bison_parser.y"
            { if(((*yyvaluep).opt_order_t)!=NULL)((*yyvaluep).opt_order_t)->deep_delete(); }
#line 3036 "bison_parser.cpp"
        break;

    case YYSYMBOL_order_list: /* order_list  */
#line 564 "bison_parser.y"
            { if(((*yyvaluep).order_list_t)!=NULL)((*yyvaluep).order_list_t)->deep_delete(); }
#line 3042 "bison_parser.cpp"
        break;

    case YYSYMBOL_order_desc: /* order_desc  */
#line 564 "bison_parser.y"
            { if(((*yyvaluep).order_desc_t)!=NULL)((*yyvaluep).order_desc_t)->deep_delete(); }
#line 3048 "bison_parser.cpp"
        break;

    case YYSYMBOL_opt_order_type: /* opt_order_type  */
#line 564 "bison_parser.y"
            { if(((*yyvaluep).opt_order_type_t)!=NULL)((*yyvaluep).opt_order_type_t)->deep_delete(); }
#line 3054 "bison_parser.cpp"
        break;

    case YYSYMBOL_opt_top: /* opt_top  */
#line 564 "bison_parser.y"
            { if(((*yyvaluep).opt_top_t)!=NULL)((*yyvaluep).opt_top_t)->deep_delete(); }
#line 3060 "bison_parser.cpp"
        break;

    case YYSYMBOL_opt_limit: /* opt_limit  */
#line 564 "bison_parser.y"
            { if(((*yyvaluep).opt_limit_t)!=NULL)((*yyvaluep).opt_limit_t)->deep_delete(); }
#line 3066 "bison_parser.cpp"
        break;

    case YYSYMBOL_expr_list: /* expr_list  */
#line 564 "bison_parser.y"
            { if(((*yyvaluep).expr_list_t)!=NULL)((*yyvaluep).expr_list_t)->deep_delete(); }
#line 3072 "bison_parser.cpp"
        break;

    case YYSYMBOL_opt_literal_list: /* opt_literal_list  */
#line 564 "bison_parser.y"
            { if(((*yyvaluep).opt_literal_list_t)!=NULL)((*yyvaluep).opt_literal_list_t)->deep_delete(); }
#line 3078 "bison_parser.cpp"
        break;

    case YYSYMBOL_literal_list: /* literal_list  */
#line 564 "bison_parser.y"
            { if(((*yyvaluep).literal_list_t)!=NULL)((*yyvaluep).literal_list_t)->deep_delete(); }
#line 3084 "bison_parser.cpp"
        break;

    case YYSYMBOL_expr_alias: /* expr_alias  */
#line 564 "bison_parser.y"
            { if(((*yyvaluep).expr_alias_t)!=NULL)((*yyvaluep).expr_alias_t)->deep_delete(); }
#line 3090 "bison_parser.cpp"
        break;

    case YYSYMBOL_expr: /* expr  */
#line 564 "bison_parser.y"
            { if(((*yyvaluep).expr_t)!=NULL)((*yyvaluep).expr_t)->deep_delete(); }
#line 3096 "bison_parser.cpp"
        break;

    case YYSYMBOL_operand: /* operand  */
#line 564 "bison_parser.y"
            { if(((*yyvaluep).operand_t)!=NULL)((*yyvaluep).operand_t)->deep_delete(); }
#line 3102 "bison_parser.cpp"
        break;

    case YYSYMBOL_cast_expr: /* cast_expr  */
#line 564 "bison_parser.y"
            { if(((*yyvaluep).cast_expr_t)!=NULL)((*yyvaluep).cast_expr_t)->deep_delete(); }
#line 3108 "bison_parser.cpp"
        break;

    case YYSYMBOL_scalar_expr: /* scalar_expr  */
#line 564 "bison_parser.y"
            { if(((*yyvaluep).scalar_expr_t)!=NULL)((*yyvaluep).scalar_expr_t)->deep_delete(); }
#line 3114 "bison_parser.cpp"
        break;

    case YYSYMBOL_unary_expr: /* unary_expr  */
#line 564 "bison_parser.y"
            { if(((*yyvaluep).unary_expr_t)!=NULL)((*yyvaluep).unary_expr_t)->deep_delete(); }
#line 3120 "bison_parser.cpp"
        break;

    case YYSYMBOL_binary_expr: /* binary_expr  */
#line 564 "bison_parser.y"
            { if(((*yyvaluep).binary_expr_t)!=NULL)((*yyvaluep).binary_expr_t)->deep_delete(); }
#line 3126 "bison_parser.cpp"
        break;

    case YYSYMBOL_logic_expr: /* logic_expr  */
#line 564 "bison_parser.y"
            { if(((*yyvaluep).logic_expr_t)!=NULL)((*yyvaluep).logic_expr_t)->deep_delete(); }
#line 3132 "bison_parser.cpp"
        break;

    case YYSYMBOL_in_expr: /* in_expr  */
#line 564 "bison_parser.y"
            { if(((*yyvaluep).in_expr_t)!=NULL)((*yyvaluep).in_expr_t)->deep_delete(); }
#line 3138 "bison_parser.cpp"
        break;

    case YYSYMBOL_case_expr: /* case_expr  */
#line 564 "bison_parser.y"
            { if(((*yyvaluep).case_expr_t)!=NULL)((*yyvaluep).case_expr_t)->deep_delete(); }
#line 3144 "bison_parser.cpp"
        break;

    case YYSYMBOL_case_list: /* case_list  */
#line 564 "bison_parser.y"
            { if(((*yyvaluep).case_list_t)!=NULL)((*yyvaluep).case_list_t)->deep_delete(); }
#line 3150 "bison_parser.cpp"
        break;

    case YYSYMBOL_exists_expr: /* exists_expr  */
#line 564 "bison_parser.y"
            { if(((*yyvaluep).exists_expr_t)!=NULL)((*yyvaluep).exists_expr_t)->deep_delete(); }
#line 3156 "bison_parser.cpp"
        break;

    case YYSYMBOL_comp_expr: /* comp_expr  */
#line 564 "bison_parser.y"
            { if(((*yyvaluep).comp_expr_t)!=NULL)((*yyvaluep).comp_expr_t)->deep_delete(); }
#line 3162 "bison_parser.cpp"
        break;

    case YYSYMBOL_function_expr: /* function_expr  */
#line 564 "bison_parser.y"
            { if(((*yyvaluep).function_expr_t)!=NULL)((*yyvaluep).function_expr_t)->deep_delete(); }
#line 3168 "bison_parser.cpp"
        break;

    case YYSYMBOL_opt_over_clause: /* opt_over_clause  */
#line 564 "bison_parser.y"
            { if(((*yyvaluep).opt_over_clause_t)!=NULL)((*yyvaluep).opt_over_clause_t)->deep_delete(); }
#line 3174 "bison_parser.cpp"
        break;

    case YYSYMBOL_opt_filter_clause: /* opt_filter_clause  */
#line 564 "bison_parser.y"
            { if(((*yyvaluep).opt_filter_clause_t)!=NULL)((*yyvaluep).opt_filter_clause_t)->deep_delete(); }
#line 3180 "bison_parser.cpp"
        break;

    case YYSYMBOL_extract_expr: /* extract_expr  */
#line 564 "bison_parser.y"
            { if(((*yyvaluep).extract_expr_t)!=NULL)((*yyvaluep).extract_expr_t)->deep_delete(); }
#line 3186 "bison_parser.cpp"
        break;

    case YYSYMBOL_datetime_field: /* datetime_field  */
#line 564 "bison_parser.y"
            { if(((*yyvaluep).datetime_field_t)!=NULL)((*yyvaluep).datetime_field_t)->deep_delete(); }
#line 3192 "bison_parser.cpp"
        break;

    case YYSYMBOL_array_expr: /* array_expr  */
#line 564 "bison_parser.y"
            { if(((*yyvaluep).array_expr_t)!=NULL)((*yyvaluep).array_expr_t)->deep_delete(); }
#line 3198 "bison_parser.cpp"
        break;

    case YYSYMBOL_array_index: /* array_index  */
#line 564 "bison_parser.y"
            { if(((*yyvaluep).array_index_t)!=NULL)((*yyvaluep).array_index_t)->deep_delete(); }
#line 3204 "bison_parser.cpp"
        break;

    case YYSYMBOL_between_expr: /* between_expr  */
#line 564 "bison_parser.y"
            { if(((*yyvaluep).between_expr_t)!=NULL)((*yyvaluep).between_expr_t)->deep_delete(); }
#line 3210 "bison_parser.cpp"
        break;

    case YYSYMBOL_column_name: /* column_name  */
#line 564 "bison_parser.y"
            { if(((*yyvaluep).column_name_t)!=NULL)((*yyvaluep).column_name_t)->deep_delete(); }
#line 3216 "bison_parser.cpp"
        break;

    case YYSYMBOL_literal: /* literal  */
#line 564 "bison_parser.y"
            { if(((*yyvaluep).literal_t)!=NULL)((*yyvaluep).literal_t)->deep_delete(); }
#line 3222 "bison_parser.cpp"
        break;

    case YYSYMBOL_string_literal: /* string_literal  */
#line 564 "bison_parser.y"
            { if(((*yyvaluep).string_literal_t)!=NULL)((*yyvaluep).string_literal_t)->deep_delete(); }
#line 3228 "bison_parser.cpp"
        break;

    case YYSYMBOL_bool_literal: /* bool_literal  */
#line 564 "bison_parser.y"
            { if(((*yyvaluep).bool_literal_t)!=NULL)((*yyvaluep).bool_literal_t)->deep_delete(); }
#line 3234 "bison_parser.cpp"
        break;

    case YYSYMBOL_num_literal: /* num_literal  */
#line 564 "bison_parser.y"
            { if(((*yyvaluep).num_literal_t)!=NULL)((*yyvaluep).num_literal_t)->deep_delete(); }
#line 3240 "bison_parser.cpp"
        break;

    case YYSYMBOL_int_literal: /* int_literal  */
#line 564 "bison_parser.y"
            { if(((*yyvaluep).int_literal_t)!=NULL)((*yyvaluep).int_literal_t)->deep_delete(); }
#line 3246 "bison_parser.cpp"
        break;

    case YYSYMBOL_null_literal: /* null_literal  */
#line 564 "bison_parser.y"
            { if(((*yyvaluep).null_literal_t)!=NULL)((*yyvaluep).null_literal_t)->deep_delete(); }
#line 3252 "bison_parser.cpp"
        break;

    case YYSYMBOL_param_expr: /* param_expr  */
#line 564 "bison_parser.y"
            { if(((*yyvaluep).param_expr_t)!=NULL)((*yyvaluep).param_expr_t)->deep_delete(); }
#line 3258 "bison_parser.cpp"
        break;

    case YYSYMBOL_table_ref: /* table_ref  */
#line 564 "bison_parser.y"
            { if(((*yyvaluep).table_ref_t)!=NULL)((*yyvaluep).table_ref_t)->deep_delete(); }
#line 3264 "bison_parser.cpp"
        break;

    case YYSYMBOL_table_prefix: /* table_prefix  */
#line 564 "bison_parser.y"
            { if(((*yyvaluep).table_prefix_t)!=NULL)((*yyvaluep).table_prefix_t)->deep_delete(); }
#line 3270 "bison_parser.cpp"
        break;

    case YYSYMBOL_join_op: /* join_op  */
#line 564 "bison_parser.y"
            { if(((*yyvaluep).join_op_t)!=NULL)((*yyvaluep).join_op_t)->deep_delete(); }
#line 3276 "bison_parser.cpp"
        break;

    case YYSYMBOL_opt_index: /* opt_index  */
#line 564 "bison_parser.y"
            { if(((*yyvaluep).opt_index_t)!=NULL)((*yyvaluep).opt_index_t)->deep_delete(); }
#line 3282 "bison_parser.cpp"
        break;

    case YYSYMBOL_opt_on: /* opt_on  */
#line 564 "bison_parser.y"
            { if(((*yyvaluep).opt_on_t)!=NULL)((*yyvaluep).opt_on_t)->deep_delete(); }
#line 3288 "bison_parser.cpp"
        break;

    case YYSYMBOL_opt_using: /* opt_using  */
#line 564 "bison_parser.y"
            { if(((*yyvaluep).opt_using_t)!=NULL)((*yyvaluep).opt_using_t)->deep_delete(); }
#line 3294 "bison_parser.cpp"
        break;

    case YYSYMBOL_table_ref_name_no_alias: /* table_ref_name_no_alias  */
#line 564 "bison_parser.y"
            { if(((*yyvaluep).table_ref_name_no_alias_t)!=NULL)((*yyvaluep).table_ref_name_no_alias_t)->deep_delete(); }
#line 3300 "bison_parser.cpp"
        break;

    case YYSYMBOL_table_name: /* table_name  */
#line 564 "bison_parser.y"
            { if(((*yyvaluep).table_name_t)!=NULL)((*yyvaluep).table_name_t)->deep_delete(); }
#line 3306 "bison_parser.cpp"
        break;

    case YYSYMBOL_alias: /* alias  */
#line 564 "bison_parser.y"
            { if(((*yyvaluep).alias_t)!=NULL)((*yyvaluep).alias_t)->deep_delete(); }
#line 3312 "bison_parser.cpp"
        break;

    case YYSYMBOL_opt_alias: /* opt_alias  */
#line 564 "bison_parser.y"
            { if(((*yyvaluep).opt_alias_t)!=NULL)((*yyvaluep).opt_alias_t)->deep_delete(); }
#line 3318 "bison_parser.cpp"
        break;

    case YYSYMBOL_opt_with_clause: /* opt_with_clause  */
#line 564 "bison_parser.y"
            { if(((*yyvaluep).opt_with_clause_t)!=NULL)((*yyvaluep).opt_with_clause_t)->deep_delete(); }
#line 3324 "bison_parser.cpp"
        break;

    case YYSYMBOL_with_clause: /* with_clause  */
#line 564 "bison_parser.y"
            { if(((*yyvaluep).with_clause_t)!=NULL)((*yyvaluep).with_clause_t)->deep_delete(); }
#line 3330 "bison_parser.cpp"
        break;

    case YYSYMBOL_with_description_list: /* with_description_list  */
#line 564 "bison_parser.y"
            { if(((*yyvaluep).with_description_list_t)!=NULL)((*yyvaluep).with_description_list_t)->deep_delete(); }
#line 3336 "bison_parser.cpp"
        break;

    case YYSYMBOL_with_description: /* with_description  */
#line 564 "bison_parser.y"
            { if(((*yyvaluep).with_description_t)!=NULL)((*yyvaluep).with_description_t)->deep_delete(); }
#line 3342 "bison_parser.cpp"
        break;

    case YYSYMBOL_join_kw: /* join_kw  */
#line 564 "bison_parser.y"
            { if(((*yyvaluep).join_kw_t)!=NULL)((*yyvaluep).join_kw_t)->deep_delete(); }
#line 3348 "bison_parser.cpp"
        break;

    case YYSYMBOL_opt_semicolon: /* opt_semicolon  */
#line 564 "bison_parser.y"
            { if(((*yyvaluep).opt_semicolon_t)!=NULL)((*yyvaluep).opt_semicolon_t)->deep_delete(); }
#line 3354 "bison_parser.cpp"
        break;

    case YYSYMBOL_ident_commalist: /* ident_commalist  */
#line 564 "bison_parser.y"
            { if(((*yyvaluep).ident_commalist_t)!=NULL)((*yyvaluep).ident_commalist_t)->deep_delete(); }
#line 3360 "bison_parser.cpp"
        break;

      default:
        break;
    }
  YY_IGNORE_MAYBE_UNINITIALIZED_END
}






/*----------.
| yyparse.  |
`----------*/

int
yyparse (Program * result, yyscan_t scanner)
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
# if defined HSQL_LTYPE_IS_TRIVIAL && HSQL_LTYPE_IS_TRIVIAL
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

  yychar = SQL_HSQL_EMPTY; /* Cause a token to be read.  */


/* User initialization code.  */
#line 70 "bison_parser.y"
{
    // Initialize
    yylloc.first_column = 0;
    yylloc.last_column = 0;
    yylloc.first_line = 0;
    yylloc.last_line = 0;
    yylloc.total_column = 0;
    yylloc.string_length = 0;
}

#line 3468 "bison_parser.cpp"

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
  if (yychar == SQL_HSQL_EMPTY)
    {
      YYDPRINTF ((stderr, "Reading a token\n"));
      yychar = yylex (&yylval, &yylloc, scanner);
    }

  if (yychar <= SQL_YYEOF)
    {
      yychar = SQL_YYEOF;
      yytoken = YYSYMBOL_YYEOF;
      YYDPRINTF ((stderr, "Now at end of input.\n"));
    }
  else if (yychar == SQL_HSQL_error)
    {
      /* The scanner already issued an error message, process directly
         to error recovery.  But do not keep the error token as
         lookahead, it is too special and may lead us to an endless
         loop in error recovery. */
      yychar = SQL_HSQL_UNDEF;
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
  yychar = SQL_HSQL_EMPTY;
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
  case 2: /* input: statement_list opt_semicolon  */
#line 601 "bison_parser.y"
                                     {
            (yyval.program_t) = NULL;
            result->statement_list_ = (yyvsp[-1].statement_list_t);
            result->opt_semicolon_ = (yyvsp[0].opt_semicolon_t);
        }
#line 3685 "bison_parser.cpp"
    break;

  case 3: /* statement_list: statement  */
#line 610 "bison_parser.y"
                  {
            (yyval.statement_list_t) = new StatementList();
            (yyval.statement_list_t)->v_statement_list_.push_back((yyvsp[0].statement_t));
            
        }
#line 3695 "bison_parser.cpp"
    break;

  case 4: /* statement_list: statement_list ';' statement  */
#line 615 "bison_parser.y"
                                     {
            (yyvsp[-2].statement_list_t)->v_statement_list_.push_back((yyvsp[0].statement_t));
            (yyval.statement_list_t) = (yyvsp[-2].statement_list_t);
        }
#line 3704 "bison_parser.cpp"
    break;

  case 5: /* statement: prepare_statement opt_hints  */
#line 622 "bison_parser.y"
                                    {
            (yyval.statement_t) = new Statement();
            (yyval.statement_t)->sub_type_ = CASE1;
            (yyval.statement_t)->prepare_statement_ = (yyvsp[-1].prepare_statement_t);
            (yyval.statement_t)->optional_hints_ = (yyvsp[0].optional_hints_t);
        }
#line 3715 "bison_parser.cpp"
    break;

  case 6: /* statement: preparable_statement opt_hints  */
#line 628 "bison_parser.y"
                                       {
            (yyval.statement_t) = new Statement();
            (yyval.statement_t)->sub_type_ = CASE0;
            (yyval.statement_t)->preparable_statement_ = (yyvsp[-1].preparable_statement_t);
            (yyval.statement_t)->optional_hints_ = (yyvsp[0].optional_hints_t);
        }
#line 3726 "bison_parser.cpp"
    break;

  case 7: /* statement: show_statement  */
#line 634 "bison_parser.y"
                       {
            (yyval.statement_t) = new Statement();
            (yyval.statement_t)->sub_type_ = CASE2;
            (yyval.statement_t)->show_statement_ = (yyvsp[0].show_statement_t);
        }
#line 3736 "bison_parser.cpp"
    break;

  case 8: /* statement: cmd  */
#line 640 "bison_parser.y"
            {
            (yyval.statement_t) = new Statement();
            (yyval.statement_t)->sub_type_ = CASE3;
            (yyval.statement_t)->cmd_ = (yyvsp[0].cmd_t);
    }
#line 3746 "bison_parser.cpp"
    break;

  case 9: /* cmd: cmd_pragma  */
#line 649 "bison_parser.y"
                   {(yyval.cmd_t) = (yyvsp[0].cmd_pragma_t);}
#line 3752 "bison_parser.cpp"
    break;

  case 10: /* cmd: cmd_reindex  */
#line 650 "bison_parser.y"
                    {(yyval.cmd_t) = (yyvsp[0].cmd_reindex_t);}
#line 3758 "bison_parser.cpp"
    break;

  case 11: /* cmd: cmd_analyze  */
#line 651 "bison_parser.y"
                    {(yyval.cmd_t) = (yyvsp[0].cmd_analyze_t);}
#line 3764 "bison_parser.cpp"
    break;

  case 12: /* cmd: cmd_attach  */
#line 652 "bison_parser.y"
                    {(yyval.cmd_t) = (yyvsp[0].cmd_attach_t);}
#line 3770 "bison_parser.cpp"
    break;

  case 13: /* cmd: cmd_detach  */
#line 653 "bison_parser.y"
                    {(yyval.cmd_t) = (yyvsp[0].cmd_detach_t);}
#line 3776 "bison_parser.cpp"
    break;

  case 14: /* cmd: cmd_release  */
#line 654 "bison_parser.y"
                    {(yyval.cmd_t) = (yyvsp[0].cmd_release_t);}
#line 3782 "bison_parser.cpp"
    break;

  case 15: /* cmd: rollback_statement  */
#line 655 "bison_parser.y"
                           {(yyval.cmd_t) = (yyvsp[0].rollback_statement_t);}
#line 3788 "bison_parser.cpp"
    break;

  case 16: /* cmd: vacuum_statement  */
#line 656 "bison_parser.y"
                         {(yyval.cmd_t) = (yyvsp[0].vacuum_statement_t);}
#line 3794 "bison_parser.cpp"
    break;

  case 17: /* cmd: begin_statement  */
#line 657 "bison_parser.y"
                        {(yyval.cmd_t) = (yyvsp[0].begin_statement_t);}
#line 3800 "bison_parser.cpp"
    break;

  case 18: /* cmd: commit_statement  */
#line 658 "bison_parser.y"
                         {(yyval.cmd_t) = (yyvsp[0].commit_statement_t);}
#line 3806 "bison_parser.cpp"
    break;

  case 19: /* cmd_release: RELEASE SAVEPOINT savepoint_name  */
#line 662 "bison_parser.y"
                                         {
            (yyval.cmd_release_t) = new CmdRelease();
            (yyval.cmd_release_t)->sub_type_ = CASE0;
            (yyval.cmd_release_t)->savepoint_name_ = (yyvsp[0].savepoint_name_t);
        }
#line 3816 "bison_parser.cpp"
    break;

  case 20: /* cmd_release: RELEASE savepoint_name  */
#line 667 "bison_parser.y"
                               {
            (yyval.cmd_release_t) = new CmdRelease();
            (yyval.cmd_release_t)->sub_type_ = CASE1;
            (yyval.cmd_release_t)->savepoint_name_ = (yyvsp[0].savepoint_name_t);
        }
#line 3826 "bison_parser.cpp"
    break;

  case 21: /* savepoint_name: IDENTIFIER  */
#line 675 "bison_parser.y"
                   {
            (yyval.savepoint_name_t) = new SavepointName();
            (yyval.savepoint_name_t)->id_ = new Identifier((yyvsp[0].sval), id_savepoint_name);
            free((yyvsp[0].sval));
        }
#line 3836 "bison_parser.cpp"
    break;

  case 22: /* cmd_pragma: PRAGMA pragma_key  */
#line 683 "bison_parser.y"
                         {
            (yyval.cmd_pragma_t) = new CmdPragma();
            (yyval.cmd_pragma_t)->sub_type_ = CASE0;
            (yyval.cmd_pragma_t)->pragma_key_ = (yyvsp[0].pragma_key_t);
        }
#line 3846 "bison_parser.cpp"
    break;

  case 23: /* cmd_pragma: PRAGMA pragma_key '=' pragma_value  */
#line 688 "bison_parser.y"
                                           {
            (yyval.cmd_pragma_t) = new CmdPragma();
            (yyval.cmd_pragma_t)->sub_type_ = CASE1;
            (yyval.cmd_pragma_t)->pragma_key_ = (yyvsp[-2].pragma_key_t);
            (yyval.cmd_pragma_t)->pragma_value_ = (yyvsp[0].pragma_value_t);
    }
#line 3857 "bison_parser.cpp"
    break;

  case 24: /* cmd_pragma: PRAGMA pragma_key '(' pragma_value ')'  */
#line 694 "bison_parser.y"
                                               {
            (yyval.cmd_pragma_t) = new CmdPragma();
            (yyval.cmd_pragma_t)->sub_type_ = CASE2;
            (yyval.cmd_pragma_t)->pragma_key_ = (yyvsp[-3].pragma_key_t);
            (yyval.cmd_pragma_t)->pragma_value_ = (yyvsp[-1].pragma_value_t);
    }
#line 3868 "bison_parser.cpp"
    break;

  case 25: /* cmd_reindex: REINDEX  */
#line 703 "bison_parser.y"
               {(yyval.cmd_reindex_t) = new CmdReindex(); (yyval.cmd_reindex_t)->sub_type_ = CASE0;}
#line 3874 "bison_parser.cpp"
    break;

  case 26: /* cmd_reindex: REINDEX table_name  */
#line 704 "bison_parser.y"
                           {(yyval.cmd_reindex_t) = new CmdReindex(); (yyval.cmd_reindex_t)->sub_type_ = CASE1; (yyval.cmd_reindex_t)->table_name_ = (yyvsp[0].table_name_t); (yyval.cmd_reindex_t)->table_name_->table_name_->id_type_ = id_top_table_name;}
#line 3880 "bison_parser.cpp"
    break;

  case 27: /* cmd_analyze: ANALYZE  */
#line 708 "bison_parser.y"
               {(yyval.cmd_analyze_t) = new CmdAnalyze(); (yyval.cmd_analyze_t)->sub_type_ = CASE0;}
#line 3886 "bison_parser.cpp"
    break;

  case 28: /* cmd_analyze: ANALYZE table_name  */
#line 709 "bison_parser.y"
                           {(yyval.cmd_analyze_t) = new CmdAnalyze(); (yyval.cmd_analyze_t)->sub_type_ = CASE1; (yyval.cmd_analyze_t)->table_name_ = (yyvsp[0].table_name_t); (yyval.cmd_analyze_t)->table_name_->table_name_->id_type_ = id_top_table_name;}
#line 3892 "bison_parser.cpp"
    break;

  case 29: /* cmd_attach: ATTACH expr AS schema_name  */
#line 713 "bison_parser.y"
                                  {
            (yyval.cmd_attach_t) = new CmdAttach();
            (yyval.cmd_attach_t)->sub_type_ = CASE0;
            (yyval.cmd_attach_t)->expr_ = (yyvsp[-2].expr_t);
            (yyval.cmd_attach_t)->schema_name_ = (yyvsp[0].schema_name_t);
        }
#line 3903 "bison_parser.cpp"
    break;

  case 30: /* cmd_attach: ATTACH DATABASE expr AS schema_name  */
#line 719 "bison_parser.y"
                                           {
            (yyval.cmd_attach_t) = new CmdAttach();
            (yyval.cmd_attach_t)->sub_type_ = CASE1;
            (yyval.cmd_attach_t)->expr_ = (yyvsp[-2].expr_t);
            (yyval.cmd_attach_t)->schema_name_ = (yyvsp[0].schema_name_t);
        }
#line 3914 "bison_parser.cpp"
    break;

  case 31: /* cmd_detach: DETACH schema_name  */
#line 728 "bison_parser.y"
                           {
            (yyval.cmd_detach_t) = new CmdDetach();
            (yyval.cmd_detach_t)->sub_type_ = CASE0;
            (yyval.cmd_detach_t)->schema_name_ = (yyvsp[0].schema_name_t);
        }
#line 3924 "bison_parser.cpp"
    break;

  case 32: /* cmd_detach: DETACH DATABASE schema_name  */
#line 733 "bison_parser.y"
                                   {
            (yyval.cmd_detach_t) = new CmdDetach();
            (yyval.cmd_detach_t)->sub_type_ = CASE1;
            (yyval.cmd_detach_t)->schema_name_ = (yyvsp[0].schema_name_t);
    }
#line 3934 "bison_parser.cpp"
    break;

  case 33: /* pragma_key: pragma_name  */
#line 741 "bison_parser.y"
                    {(yyval.pragma_key_t) = new PragmaKey(); (yyval.pragma_key_t)->sub_type_ = CASE0; (yyval.pragma_key_t)->pragma_name_ = (yyvsp[0].pragma_name_t);}
#line 3940 "bison_parser.cpp"
    break;

  case 34: /* pragma_key: schema_name '.' pragma_name  */
#line 742 "bison_parser.y"
                                    { (yyval.pragma_key_t) = new PragmaKey(); (yyval.pragma_key_t)->sub_type_ = CASE1; (yyval.pragma_key_t)->schema_name_ = (yyvsp[-2].schema_name_t); (yyval.pragma_key_t)->pragma_name_ = (yyvsp[0].pragma_name_t);}
#line 3946 "bison_parser.cpp"
    break;

  case 35: /* pragma_value: num_literal  */
#line 746 "bison_parser.y"
                    {(yyval.pragma_value_t) = new PragmaValue(); (yyval.pragma_value_t)->sub_type_ = CASE0; (yyval.pragma_value_t)->num_literal_ = (yyvsp[0].num_literal_t);}
#line 3952 "bison_parser.cpp"
    break;

  case 36: /* pragma_value: string_literal  */
#line 747 "bison_parser.y"
                       {(yyval.pragma_value_t) = new PragmaValue(); (yyval.pragma_value_t)->sub_type_ = CASE1; (yyval.pragma_value_t)->string_literal_ = (yyvsp[0].string_literal_t);}
#line 3958 "bison_parser.cpp"
    break;

  case 37: /* pragma_value: IDENTIFIER  */
#line 748 "bison_parser.y"
                   {(yyval.pragma_value_t) = new PragmaValue(); (yyval.pragma_value_t)->sub_type_ = CASE2; (yyval.pragma_value_t)->id_ = new Identifier((yyvsp[0].sval), id_pragma_value); free((yyvsp[0].sval));}
#line 3964 "bison_parser.cpp"
    break;

  case 38: /* pragma_value: ON  */
#line 749 "bison_parser.y"
           {(yyval.pragma_value_t) = new PragmaValue(); (yyval.pragma_value_t)->sub_type_ = CASE2; (yyval.pragma_value_t)->id_ = new Identifier("ON", id_pragma_value); }
#line 3970 "bison_parser.cpp"
    break;

  case 39: /* pragma_value: DELETE  */
#line 750 "bison_parser.y"
               {(yyval.pragma_value_t) = new PragmaValue(); (yyval.pragma_value_t)->sub_type_ = CASE2; (yyval.pragma_value_t)->id_ = new Identifier("DELETE", id_pragma_value); }
#line 3976 "bison_parser.cpp"
    break;

  case 40: /* pragma_value: DEFAULT  */
#line 751 "bison_parser.y"
                {(yyval.pragma_value_t) = new PragmaValue(); (yyval.pragma_value_t)->sub_type_ = CASE2; (yyval.pragma_value_t)->id_ = new Identifier("DEFAULT", id_pragma_value); }
#line 3982 "bison_parser.cpp"
    break;

  case 41: /* schema_name: IDENTIFIER  */
#line 755 "bison_parser.y"
                   {
            (yyval.schema_name_t) = new SchemaName(); (yyval.schema_name_t)->id_ = new Identifier((yyvsp[0].sval), id_schema_name); free((yyvsp[0].sval));
            }
#line 3990 "bison_parser.cpp"
    break;

  case 42: /* pragma_name: IDENTIFIER  */
#line 761 "bison_parser.y"
                   {(yyval.pragma_name_t) = new PragmaName(); (yyval.pragma_name_t)->id_ = new Identifier((yyvsp[0].sval), id_pragma_name); free((yyvsp[0].sval));}
#line 3996 "bison_parser.cpp"
    break;

  case 43: /* preparable_statement: select_statement  */
#line 767 "bison_parser.y"
                         { (yyval.preparable_statement_t) = (yyvsp[0].select_statement_t); }
#line 4002 "bison_parser.cpp"
    break;

  case 44: /* preparable_statement: import_statement  */
#line 768 "bison_parser.y"
                         { (yyval.preparable_statement_t) = (yyvsp[0].import_statement_t); }
#line 4008 "bison_parser.cpp"
    break;

  case 45: /* preparable_statement: create_statement  */
#line 769 "bison_parser.y"
                         { (yyval.preparable_statement_t) = (yyvsp[0].create_statement_t); }
#line 4014 "bison_parser.cpp"
    break;

  case 46: /* preparable_statement: insert_statement  */
#line 770 "bison_parser.y"
                         { (yyval.preparable_statement_t) = (yyvsp[0].insert_statement_t); }
#line 4020 "bison_parser.cpp"
    break;

  case 47: /* preparable_statement: delete_statement  */
#line 771 "bison_parser.y"
                         { (yyval.preparable_statement_t) = (yyvsp[0].delete_statement_t); }
#line 4026 "bison_parser.cpp"
    break;

  case 48: /* preparable_statement: truncate_statement  */
#line 772 "bison_parser.y"
                           { (yyval.preparable_statement_t) = (yyvsp[0].delete_statement_t); }
#line 4032 "bison_parser.cpp"
    break;

  case 49: /* preparable_statement: update_statement  */
#line 773 "bison_parser.y"
                         { (yyval.preparable_statement_t) = (yyvsp[0].update_statement_t); }
#line 4038 "bison_parser.cpp"
    break;

  case 50: /* preparable_statement: drop_statement  */
#line 774 "bison_parser.y"
                       { (yyval.preparable_statement_t) = (yyvsp[0].drop_statement_t); }
#line 4044 "bison_parser.cpp"
    break;

  case 51: /* preparable_statement: execute_statement  */
#line 775 "bison_parser.y"
                          { (yyval.preparable_statement_t) = (yyvsp[0].execute_statement_t); }
#line 4050 "bison_parser.cpp"
    break;

  case 52: /* preparable_statement: alter_statement  */
#line 776 "bison_parser.y"
                        {(yyval.preparable_statement_t) = (yyvsp[0].alter_statement_t);}
#line 4056 "bison_parser.cpp"
    break;

  case 53: /* rollback_statement: ROLLBACK opt_transaction opt_to_savepoint  */
#line 780 "bison_parser.y"
                                                  {
            (yyval.rollback_statement_t) = new RollbackStatement();
            (yyval.rollback_statement_t)->opt_transaction_ = (yyvsp[-1].opt_transaction_t);
            (yyval.rollback_statement_t)->opt_to_savepoint_ = (yyvsp[0].opt_to_savepoint_t);
        }
#line 4066 "bison_parser.cpp"
    break;

  case 54: /* opt_transaction: TRANSACTION  */
#line 788 "bison_parser.y"
                    {
            (yyval.opt_transaction_t) = new OptTransaction();
            (yyval.opt_transaction_t)->sub_type_ = CASE0;
            (yyval.opt_transaction_t)->str_val_ = string("TRANSACTION");
        }
#line 4076 "bison_parser.cpp"
    break;

  case 55: /* opt_transaction: %empty  */
#line 793 "bison_parser.y"
                   {
            (yyval.opt_transaction_t) = new OptTransaction();
            (yyval.opt_transaction_t)->sub_type_ = CASE1;
            (yyval.opt_transaction_t)->str_val_ = string("");
        }
#line 4086 "bison_parser.cpp"
    break;

  case 56: /* opt_to_savepoint: TO savepoint_name  */
#line 801 "bison_parser.y"
                          {
            (yyval.opt_to_savepoint_t) = new OptToSavepoint();
            (yyval.opt_to_savepoint_t)->sub_type_ = CASE0;
            (yyval.opt_to_savepoint_t)->savepoint_name_ = (yyvsp[0].savepoint_name_t);
        }
#line 4096 "bison_parser.cpp"
    break;

  case 57: /* opt_to_savepoint: TO SAVEPOINT savepoint_name  */
#line 806 "bison_parser.y"
                                    {
            (yyval.opt_to_savepoint_t) = new OptToSavepoint();
            (yyval.opt_to_savepoint_t)->sub_type_ = CASE1;
            (yyval.opt_to_savepoint_t)->savepoint_name_ = (yyvsp[0].savepoint_name_t);
        }
#line 4106 "bison_parser.cpp"
    break;

  case 58: /* opt_to_savepoint: %empty  */
#line 811 "bison_parser.y"
                   {
            (yyval.opt_to_savepoint_t) = new OptToSavepoint();
            (yyval.opt_to_savepoint_t)->sub_type_ = CASE2;
        }
#line 4115 "bison_parser.cpp"
    break;

  case 59: /* vacuum_statement: VACUUM opt_schema_name INTO file_path  */
#line 819 "bison_parser.y"
                                             {
            (yyval.vacuum_statement_t) = new VacuumStatement();
            (yyval.vacuum_statement_t)->sub_type_ = CASE0;
            (yyval.vacuum_statement_t)->opt_schema_name_ = (yyvsp[-2].opt_schema_name_t);
            (yyval.vacuum_statement_t)->file_path_ = (yyvsp[0].file_path_t);
        }
#line 4126 "bison_parser.cpp"
    break;

  case 60: /* vacuum_statement: VACUUM opt_schema_name  */
#line 825 "bison_parser.y"
                              {
            (yyval.vacuum_statement_t) = new VacuumStatement();
            (yyval.vacuum_statement_t)->sub_type_ = CASE1;
            (yyval.vacuum_statement_t)->opt_schema_name_ = (yyvsp[0].opt_schema_name_t);
        }
#line 4136 "bison_parser.cpp"
    break;

  case 61: /* opt_schema_name: schema_name  */
#line 833 "bison_parser.y"
                    {
            (yyval.opt_schema_name_t) = new OptSchemaName();
            (yyval.opt_schema_name_t)->sub_type_ = CASE0;
            (yyval.opt_schema_name_t)->schema_name_ = (yyvsp[0].schema_name_t);
        }
#line 4146 "bison_parser.cpp"
    break;

  case 62: /* opt_schema_name: %empty  */
#line 838 "bison_parser.y"
                  {
            (yyval.opt_schema_name_t) = new OptSchemaName();
            (yyval.opt_schema_name_t)->sub_type_ = CASE1;
        }
#line 4155 "bison_parser.cpp"
    break;

  case 63: /* begin_statement: BEGIN opt_transaction  */
#line 845 "bison_parser.y"
                              {
            (yyval.begin_statement_t) = new BeginStatement();
            (yyval.begin_statement_t)->sub_type_ = CASE0;
            (yyval.begin_statement_t)->opt_transaction_ = (yyvsp[0].opt_transaction_t);
        }
#line 4165 "bison_parser.cpp"
    break;

  case 64: /* begin_statement: BEGIN DEFFERED opt_transaction  */
#line 850 "bison_parser.y"
                                       {
            (yyval.begin_statement_t) = new BeginStatement();
            (yyval.begin_statement_t)->sub_type_ = CASE1;
            (yyval.begin_statement_t)->opt_transaction_ = (yyvsp[0].opt_transaction_t);
        }
#line 4175 "bison_parser.cpp"
    break;

  case 65: /* begin_statement: BEGIN IMEDIATE opt_transaction  */
#line 855 "bison_parser.y"
                                       {
            (yyval.begin_statement_t) = new BeginStatement();
            (yyval.begin_statement_t)->sub_type_ = CASE2;
            (yyval.begin_statement_t)->opt_transaction_ = (yyvsp[0].opt_transaction_t);
        }
#line 4185 "bison_parser.cpp"
    break;

  case 66: /* begin_statement: BEGIN EXCLUSIVE opt_transaction  */
#line 860 "bison_parser.y"
                                        {
            (yyval.begin_statement_t) = new BeginStatement();
            (yyval.begin_statement_t)->sub_type_ = CASE3;
            (yyval.begin_statement_t)->opt_transaction_ = (yyvsp[0].opt_transaction_t);
        }
#line 4195 "bison_parser.cpp"
    break;

  case 67: /* commit_statement: COMMIT opt_transaction  */
#line 868 "bison_parser.y"
                               {
            (yyval.commit_statement_t) = new CommitStatement();
            (yyval.commit_statement_t)->sub_type_ = CASE0;
            (yyval.commit_statement_t)->opt_transaction_ = (yyvsp[0].opt_transaction_t);
        }
#line 4205 "bison_parser.cpp"
    break;

  case 68: /* commit_statement: END opt_transaction  */
#line 873 "bison_parser.y"
                            {
            (yyval.commit_statement_t) = new CommitStatement();
            (yyval.commit_statement_t)->sub_type_ = CASE1;
            (yyval.commit_statement_t)->opt_transaction_ = (yyvsp[0].opt_transaction_t);
        }
#line 4215 "bison_parser.cpp"
    break;

  case 69: /* opt_upsert_clause: upsert_clause  */
#line 882 "bison_parser.y"
                      {(yyval.opt_upsert_clause_t) = new OptUpsertClause(); (yyval.opt_upsert_clause_t)->sub_type_ = CASE0; (yyval.opt_upsert_clause_t)->upsert_clause_ = (yyvsp[0].upsert_clause_t);}
#line 4221 "bison_parser.cpp"
    break;

  case 70: /* opt_upsert_clause: %empty  */
#line 883 "bison_parser.y"
                    {(yyval.opt_upsert_clause_t) = new OptUpsertClause(); (yyval.opt_upsert_clause_t)->sub_type_ = CASE1;}
#line 4227 "bison_parser.cpp"
    break;

  case 71: /* upsert_clause: ON CONFLICT DO NOTHING  */
#line 886 "bison_parser.y"
                               {
            (yyval.upsert_clause_t) = new UpsertClause();
            (yyval.upsert_clause_t)->sub_type_ = CASE0;
        }
#line 4236 "bison_parser.cpp"
    break;

  case 72: /* upsert_clause: ON CONFLICT DO UPDATE SET assign_list opt_where  */
#line 890 "bison_parser.y"
                                                        {
            (yyval.upsert_clause_t) = new UpsertClause();
            (yyval.upsert_clause_t)->sub_type_ = CASE1;
            (yyval.upsert_clause_t)->assign_list_ = (yyvsp[-1].assign_list_t);
            (yyval.upsert_clause_t)->opt_where1_ = (yyvsp[0].opt_where_t);
        }
#line 4247 "bison_parser.cpp"
    break;

  case 73: /* upsert_clause: ON CONFLICT '(' indexed_column_list ')' opt_where DO NOTHING  */
#line 896 "bison_parser.y"
                                                                     {
            (yyval.upsert_clause_t) = new UpsertClause();
            (yyval.upsert_clause_t)->sub_type_ = CASE2;
            (yyval.upsert_clause_t)->indexed_column_list_ = (yyvsp[-4].indexed_column_list_t);
            (yyval.upsert_clause_t)->opt_where1_ = (yyvsp[-2].opt_where_t);
        }
#line 4258 "bison_parser.cpp"
    break;

  case 74: /* upsert_clause: ON CONFLICT '(' indexed_column_list ')' opt_where DO UPDATE SET assign_list opt_where  */
#line 902 "bison_parser.y"
                                                                                              {
            (yyval.upsert_clause_t) = new UpsertClause();
            (yyval.upsert_clause_t)->sub_type_ = CASE3;
            (yyval.upsert_clause_t)->indexed_column_list_ = (yyvsp[-7].indexed_column_list_t);
            (yyval.upsert_clause_t)->opt_where1_ = (yyvsp[-5].opt_where_t);
            (yyval.upsert_clause_t)->assign_list_ = (yyvsp[-1].assign_list_t);
            (yyval.upsert_clause_t)->opt_where2_ = (yyvsp[0].opt_where_t);
        }
#line 4271 "bison_parser.cpp"
    break;

  case 75: /* indexed_column_list: indexed_column  */
#line 914 "bison_parser.y"
                       {
            (yyval.indexed_column_list_t) = new IndexedColumnList();
            (yyval.indexed_column_list_t)->v_indexed_column_list_.push_back((yyvsp[0].indexed_column_t));
        }
#line 4280 "bison_parser.cpp"
    break;

  case 76: /* indexed_column_list: indexed_column_list ',' indexed_column  */
#line 918 "bison_parser.y"
                                               {
            (yyvsp[-2].indexed_column_list_t)->v_indexed_column_list_.push_back((yyvsp[0].indexed_column_t));
            (yyval.indexed_column_list_t) = (yyvsp[-2].indexed_column_list_t);
        }
#line 4289 "bison_parser.cpp"
    break;

  case 77: /* indexed_column: expr opt_collate opt_order_type  */
#line 925 "bison_parser.y"
                                        {
            (yyval.indexed_column_t) = new IndexedColumn();
            (yyval.indexed_column_t)->expr_ = (yyvsp[-2].expr_t);
            (yyval.indexed_column_t)->opt_collate_ = (yyvsp[-1].opt_collate_t);
            (yyval.indexed_column_t)->opt_order_type_ = (yyvsp[0].opt_order_type_t);
        }
#line 4300 "bison_parser.cpp"
    break;

  case 78: /* opt_collate: COLLATE collation_name  */
#line 934 "bison_parser.y"
                               {
            (yyval.opt_collate_t) = new OptCollate();
            (yyval.opt_collate_t)->sub_type_ = CASE0;
            (yyval.opt_collate_t)->collation_name_ = (yyvsp[0].collation_name_t);
        }
#line 4310 "bison_parser.cpp"
    break;

  case 79: /* opt_collate: %empty  */
#line 939 "bison_parser.y"
                   {
            (yyval.opt_collate_t) = new OptCollate();
            (yyval.opt_collate_t)->sub_type_ = CASE1;
            (yyval.opt_collate_t)->str_val_ = string("");
        }
#line 4320 "bison_parser.cpp"
    break;

  case 80: /* assign_list: assign_clause  */
#line 948 "bison_parser.y"
                      {
            (yyval.assign_list_t) = new AssignList();
            (yyval.assign_list_t)->v_assign_list_.push_back((yyvsp[0].assign_clause_t));

        }
#line 4330 "bison_parser.cpp"
    break;

  case 81: /* assign_list: assign_list ',' assign_clause  */
#line 953 "bison_parser.y"
                                      {
            (yyvsp[-2].assign_list_t)->v_assign_list_.push_back((yyvsp[0].assign_clause_t));
            (yyval.assign_list_t) = (yyvsp[-2].assign_list_t);
        }
#line 4339 "bison_parser.cpp"
    break;

  case 82: /* opt_null: NULLS FIRST  */
#line 961 "bison_parser.y"
                    {
            (yyval.opt_null_t) = new OptNull();
            (yyval.opt_null_t)->str_val_ = string("NULLS FIRST");
        }
#line 4348 "bison_parser.cpp"
    break;

  case 83: /* opt_null: NULLS LAST  */
#line 965 "bison_parser.y"
                   {
            (yyval.opt_null_t) = new OptNull();
            (yyval.opt_null_t)->str_val_ = string("NULLS LAST");
        }
#line 4357 "bison_parser.cpp"
    break;

  case 84: /* opt_null: %empty  */
#line 969 "bison_parser.y"
        {
            (yyval.opt_null_t) = new OptNull();
            (yyval.opt_null_t)->str_val_ = string("");
        }
#line 4366 "bison_parser.cpp"
    break;

  case 85: /* assign_clause: column_name_list '=' expr  */
#line 976 "bison_parser.y"
                                  {
            (yyval.assign_clause_t) = new AssignClause();
            (yyval.assign_clause_t)->column_name_list_ = (yyvsp[-2].column_name_list_t);
            (yyval.assign_clause_t)->expr_ = (yyvsp[0].expr_t);
        }
#line 4376 "bison_parser.cpp"
    break;

  case 86: /* column_name_list: column_name  */
#line 984 "bison_parser.y"
                    {
            (yyval.column_name_list_t) = new ColumnNameList();
            (yyval.column_name_list_t)->v_column_name_list_.push_back((yyvsp[0].column_name_t));
        }
#line 4385 "bison_parser.cpp"
    break;

  case 87: /* column_name_list: column_name_list ',' column_name  */
#line 988 "bison_parser.y"
                                         {
            (yyvsp[-2].column_name_list_t)->v_column_name_list_.push_back((yyvsp[0].column_name_t));
            (yyval.column_name_list_t) = (yyvsp[-2].column_name_list_t);
        }
#line 4394 "bison_parser.cpp"
    break;

  case 88: /* collation_name: IDENTIFIER  */
#line 995 "bison_parser.y"
                   {
            (yyval.collation_name_t) = new CollationName(); 
            (yyval.collation_name_t)->id_ = new Identifier((yyvsp[0].sval), id_collation_name); 
            free((yyvsp[0].sval));
        }
#line 4404 "bison_parser.cpp"
    break;

  case 89: /* opt_hints: WITH HINT '(' hint_list ')'  */
#line 1007 "bison_parser.y"
                                { 
        (yyval.optional_hints_t) = new OptionalHints();
        (yyval.optional_hints_t)->sub_type_ = CASE0;
        (yyval.optional_hints_t)->hint_list_ = (yyvsp[-1].hint_list_t); 
        }
#line 4414 "bison_parser.cpp"
    break;

  case 90: /* opt_hints: %empty  */
#line 1012 "bison_parser.y"
                { (yyval.optional_hints_t) = new OptionalHints(); (yyval.optional_hints_t)->sub_type_ = CASE1;}
#line 4420 "bison_parser.cpp"
    break;

  case 91: /* hint_list: hint  */
#line 1017 "bison_parser.y"
           { 
          (yyval.hint_list_t) = new HintList();
          (yyval.hint_list_t)->v_hint_list_.push_back((yyvsp[0].hint_t)); 
          }
#line 4429 "bison_parser.cpp"
    break;

  case 92: /* hint_list: hint_list ',' hint  */
#line 1021 "bison_parser.y"
                         { (yyvsp[-2].hint_list_t)->v_hint_list_.push_back((yyvsp[0].hint_t)); (yyval.hint_list_t) = (yyvsp[-2].hint_list_t); }
#line 4435 "bison_parser.cpp"
    break;

  case 93: /* hint: IDENTIFIER  */
#line 1025 "bison_parser.y"
                   {
            (yyval.hint_t) = new Hint();
            (yyval.hint_t)->sub_type_ = CASE1;
            (yyval.hint_t)->id_ = new Identifier((yyvsp[0].sval));
            free((yyvsp[0].sval));
        }
#line 4446 "bison_parser.cpp"
    break;

  case 94: /* hint: IDENTIFIER '(' literal_list ')'  */
#line 1031 "bison_parser.y"
                                      {
            (yyval.hint_t) = new Hint();
            (yyval.hint_t)->sub_type_ = CASE0;
            (yyval.hint_t)->id_ = new Identifier((yyvsp[-3].sval));
            (yyval.hint_t)->literal_list_ = (yyvsp[-1].literal_list_t);
            free((yyvsp[-3].sval));
        }
#line 4458 "bison_parser.cpp"
    break;

  case 95: /* prepare_statement: PREPARE IDENTIFIER FROM prepare_target_query  */
#line 1045 "bison_parser.y"
                                                     {
            (yyval.prepare_statement_t) = new PrepareStatement();
            (yyval.prepare_statement_t)->id_ = new Identifier((yyvsp[-2].sval));
            (yyval.prepare_statement_t)->prep_target_que_ = (yyvsp[0].prepare_target_query_t);
            free((yyvsp[-2].sval));
        }
#line 4469 "bison_parser.cpp"
    break;

  case 96: /* prepare_target_query: STRING  */
#line 1054 "bison_parser.y"
        {
            (yyval.prepare_target_query_t) = new PrepareTargetQuery();
            (yyval.prepare_target_query_t)->prep_target_que_ = "'" + string((yyvsp[0].sval)) + "'";
            free((yyvsp[0].sval));
        }
#line 4479 "bison_parser.cpp"
    break;

  case 97: /* execute_statement: EXECUTE IDENTIFIER  */
#line 1062 "bison_parser.y"
                           {
            (yyval.execute_statement_t) = new ExecuteStatement();
            (yyval.execute_statement_t)->sub_type_ = CASE0;
            (yyval.execute_statement_t)->id_ = new Identifier((yyvsp[0].sval));
            free((yyvsp[0].sval));
        }
#line 4490 "bison_parser.cpp"
    break;

  case 98: /* execute_statement: EXECUTE IDENTIFIER '(' opt_literal_list ')'  */
#line 1068 "bison_parser.y"
                                                    {
            (yyval.execute_statement_t) = new ExecuteStatement();
            (yyval.execute_statement_t)->sub_type_ = CASE1;
            (yyval.execute_statement_t)->id_ = new Identifier((yyvsp[-3].sval));
            (yyval.execute_statement_t)->opt_literal_list_ = (yyvsp[-1].opt_literal_list_t);
            free((yyvsp[-3].sval));
        }
#line 4502 "bison_parser.cpp"
    break;

  case 99: /* import_statement: IMPORT FROM import_file_type FILE file_path INTO table_name  */
#line 1082 "bison_parser.y"
                                                                    {
            (yyval.import_statement_t) = new ImportStatement();
            (yyval.import_statement_t)->import_file_type_ = (yyvsp[-4].import_file_type_t);
            (yyval.import_statement_t)->file_path_ = (yyvsp[-2].file_path_t);
            (yyval.import_statement_t)->table_name_ = (yyvsp[0].table_name_t);
        }
#line 4513 "bison_parser.cpp"
    break;

  case 100: /* import_file_type: CSV  */
#line 1091 "bison_parser.y"
            { (yyval.import_file_type_t) = new ImportFileType(); (yyval.import_file_type_t)->str_val_ = "CSV"; }
#line 4519 "bison_parser.cpp"
    break;

  case 101: /* file_path: string_literal  */
#line 1095 "bison_parser.y"
                       { 
            (yyval.file_path_t) = new FilePath();
            (yyval.file_path_t)->str_val_ = (yyvsp[0].string_literal_t)->str_val_;
            delete((yyvsp[0].string_literal_t));
         }
#line 4529 "bison_parser.cpp"
    break;

  case 102: /* show_statement: SHOW TABLES  */
#line 1109 "bison_parser.y"
                    {
            (yyval.show_statement_t) = new ShowStatement();
            (yyval.show_statement_t)->sub_type_ = CASE0;
        }
#line 4538 "bison_parser.cpp"
    break;

  case 103: /* show_statement: SHOW COLUMNS table_name  */
#line 1113 "bison_parser.y"
                                {
            (yyval.show_statement_t) = new ShowStatement();
            (yyval.show_statement_t)->sub_type_ = CASE1;
            (yyval.show_statement_t)->table_name_ = (yyvsp[0].table_name_t);
            (yyval.show_statement_t)->table_name_->table_name_->id_type_ = id_top_table_name;
        }
#line 4549 "bison_parser.cpp"
    break;

  case 104: /* show_statement: DESCRIBE table_name  */
#line 1119 "bison_parser.y"
                            {
            (yyval.show_statement_t) = new ShowStatement();
            (yyval.show_statement_t)->sub_type_ = CASE2;
            (yyval.show_statement_t)->table_name_ = (yyvsp[0].table_name_t);
            (yyval.show_statement_t)->table_name_->table_name_->id_type_ = id_top_table_name;
        }
#line 4560 "bison_parser.cpp"
    break;

  case 105: /* alter_statement: ALTER TABLE table_name RENAME TO table_name  */
#line 1134 "bison_parser.y"
                                                    {
		(yyval.alter_statement_t) = new AlterStatement();
		(yyval.alter_statement_t)->sub_type_ = CASE0;
        (yyval.alter_statement_t)->table_name1_ = (yyvsp[-3].table_name_t);
        (yyval.alter_statement_t)->table_name2_ = (yyvsp[0].table_name_t);
	}
#line 4571 "bison_parser.cpp"
    break;

  case 106: /* alter_statement: ALTER TABLE table_name RENAME opt_column column_name TO column_name  */
#line 1140 "bison_parser.y"
                                                                            {
		(yyval.alter_statement_t) = new AlterStatement();
		(yyval.alter_statement_t)->sub_type_ = CASE1;
        (yyval.alter_statement_t)->table_name1_ = (yyvsp[-5].table_name_t);
        (yyval.alter_statement_t)->opt_column_ = (yyvsp[-3].opt_column_t);
        (yyval.alter_statement_t)->column_name1_ = (yyvsp[-2].column_name_t);
        (yyval.alter_statement_t)->column_name2_ = (yyvsp[0].column_name_t);
	}
#line 4584 "bison_parser.cpp"
    break;

  case 107: /* alter_statement: ALTER TABLE table_name ADD opt_column column_def  */
#line 1148 "bison_parser.y"
                                                         {
		(yyval.alter_statement_t) = new AlterStatement();
		(yyval.alter_statement_t)->sub_type_ = CASE2;
        (yyval.alter_statement_t)->table_name1_ = (yyvsp[-3].table_name_t);
        (yyval.alter_statement_t)->opt_column_ = (yyvsp[-1].opt_column_t);
        (yyval.alter_statement_t)->column_def_ = (yyvsp[0].column_def_t);
	}
#line 4596 "bison_parser.cpp"
    break;

  case 108: /* opt_column: COLUMN  */
#line 1158 "bison_parser.y"
               {
		(yyval.opt_column_t) = new OptColumn();
		(yyval.opt_column_t)->sub_type_ = CASE0;
        (yyval.opt_column_t)->str_val_ = string("COLUMN");
	}
#line 4606 "bison_parser.cpp"
    break;

  case 109: /* opt_column: %empty  */
#line 1163 "bison_parser.y"
                   {
		(yyval.opt_column_t) = new OptColumn();
		(yyval.opt_column_t)->sub_type_ = CASE1;
        (yyval.opt_column_t)->str_val_ = string("");
	}
#line 4616 "bison_parser.cpp"
    break;

  case 110: /* create_statement: CREATE TABLE opt_not_exists table_name FROM TBL FILE file_path  */
#line 1177 "bison_parser.y"
                                                                       {
            (yyval.create_statement_t) = new CreateStatement();
            (yyval.create_statement_t)->sub_type_ = CASE0;
            (yyval.create_statement_t)->opt_not_exists_ = (yyvsp[-5].opt_not_exists_t);
            (yyval.create_statement_t)->table_name_ = (yyvsp[-4].table_name_t);
            (yyval.create_statement_t)->file_path_ = (yyvsp[0].file_path_t);
            (yyval.create_statement_t)->table_name_->table_name_->id_type_ = id_create_table_name;
        }
#line 4629 "bison_parser.cpp"
    break;

  case 111: /* create_statement: CREATE TABLE opt_not_exists table_name '(' CreateInparan ')'  */
#line 1185 "bison_parser.y"
                                                                     {
            (yyval.create_statement_t) = new CreateStatement();
            (yyval.create_statement_t)->sub_type_ = CASE1;
            (yyval.create_statement_t)->opt_not_exists_ = (yyvsp[-4].opt_not_exists_t);
            (yyval.create_statement_t)->table_name_ = (yyvsp[-3].table_name_t);
            (yyval.create_statement_t)->CreateInparan_ = (yyvsp[-1].CreateInparan_t);
            (yyval.create_statement_t)->table_name_->table_name_->id_type_ = id_create_table_name;
            
        }
#line 4643 "bison_parser.cpp"
    break;

  case 112: /* create_statement: CREATE TABLE opt_not_exists table_name AS select_statement  */
#line 1194 "bison_parser.y"
                                                                   {
            (yyval.create_statement_t) = new CreateStatement();
            (yyval.create_statement_t)->sub_type_ = CASE2;
            (yyval.create_statement_t)->opt_not_exists_ = (yyvsp[-3].opt_not_exists_t);
            (yyval.create_statement_t)->table_name_ = (yyvsp[-2].table_name_t);
            (yyval.create_statement_t)->select_statement_ = (yyvsp[0].select_statement_t);
            (yyval.create_statement_t)->table_name_->table_name_->id_type_ = id_create_table_name;
        }
#line 4656 "bison_parser.cpp"
    break;

  case 113: /* create_statement: CREATE VIEW opt_not_exists table_name opt_column_list AS select_statement  */
#line 1202 "bison_parser.y"
                                                                                  {
            (yyval.create_statement_t) = new CreateStatement();
            (yyval.create_statement_t)->sub_type_ = CASE3;
            (yyval.create_statement_t)->opt_not_exists_ = (yyvsp[-4].opt_not_exists_t);
            (yyval.create_statement_t)->table_name_ = (yyvsp[-3].table_name_t);
            (yyval.create_statement_t)->table_name_->table_name_->id_type_ = id_create_table_name;
            (yyval.create_statement_t)->opt_column_list_ = (yyvsp[-2].opt_column_list_t);
            if((yyval.create_statement_t)->opt_column_list_->sub_type_ == CASE0)
                for(auto &i: (yyval.create_statement_t)->opt_column_list_->ident_comma_list_->v_iden_comma_list_){
                    i->id_type_ = id_create_column_name;
                }
            (yyval.create_statement_t)->select_statement_ = (yyvsp[0].select_statement_t);
            (yyval.create_statement_t)->table_name_->table_name_->id_type_ = id_create_table_name;
        }
#line 4675 "bison_parser.cpp"
    break;

  case 114: /* create_statement: CREATE opt_unique INDEX opt_not_exists index_name ON table_name '(' ident_commalist ')' opt_where  */
#line 1217 "bison_parser.y"
                                                                                                          {
            (yyval.create_statement_t) = new CreateStatement();
            (yyval.create_statement_t)->sub_type_ = CASE4;
            (yyval.create_statement_t)->opt_unique_ = (yyvsp[-9].opt_unique_t);
            (yyval.create_statement_t)->opt_not_exists_ = (yyvsp[-7].opt_not_exists_t);
            (yyval.create_statement_t)->index_name_ = (yyvsp[-6].index_name_t);   
            (yyval.create_statement_t)->table_name_ = (yyvsp[-4].table_name_t);
            (yyval.create_statement_t)->table_name_->table_name_->id_type_ = id_top_table_name;
            (yyval.create_statement_t)->ident_commalist_ = (yyvsp[-2].ident_commalist_t);
            for(auto &i: (yyval.create_statement_t)->ident_commalist_->v_iden_comma_list_){
                i->id_type_ = id_column_name;
            }
            (yyval.create_statement_t)->opt_where_ = (yyvsp[0].opt_where_t);
        }
#line 4694 "bison_parser.cpp"
    break;

  case 115: /* create_statement: CREATE VIRTUAL TABLE opt_not_exists table_name USING module_name  */
#line 1231 "bison_parser.y"
                                                                          {
            (yyval.create_statement_t) = new CreateStatement();
            (yyval.create_statement_t)->sub_type_ = CASE5;
            (yyval.create_statement_t)->opt_not_exists_ = (yyvsp[-3].opt_not_exists_t);
            (yyval.create_statement_t)->table_name_ = (yyvsp[-2].table_name_t);
            (yyval.create_statement_t)->module_name_ = (yyvsp[0].module_name_t);
            (yyval.create_statement_t)->table_name_->table_name_->id_type_ = id_create_table_name;
        }
#line 4707 "bison_parser.cpp"
    break;

  case 116: /* create_statement: CREATE VIRTUAL TABLE opt_not_exists table_name USING module_name '(' column_def_commalist ')'  */
#line 1239 "bison_parser.y"
                                                                                                       {
            (yyval.create_statement_t) = new CreateStatement();
            (yyval.create_statement_t)->sub_type_ = CASE6;
            (yyval.create_statement_t)->opt_not_exists_ = (yyvsp[-6].opt_not_exists_t);
            (yyval.create_statement_t)->table_name_ = (yyvsp[-5].table_name_t);
            (yyval.create_statement_t)->module_name_ = (yyvsp[-3].module_name_t);
            (yyval.create_statement_t)->table_name_->table_name_->id_type_ = id_create_table_name;
            (yyval.create_statement_t)->column_def_comma_list_ = (yyvsp[-1].column_def_comma_list_t);
        }
#line 4721 "bison_parser.cpp"
    break;

  case 117: /* create_statement: CREATE trigger_declare BEGIN trigger_cmd_list END  */
#line 1248 "bison_parser.y"
                                                          {
            (yyval.create_statement_t) = new CreateStatement();
            (yyval.create_statement_t)->sub_type_ = CASE7;
            (yyval.create_statement_t)->trigger_declare_ = (yyvsp[-3].trigger_declare_t);
            (yyval.create_statement_t)->trigger_cmd_list_ = (yyvsp[-1].trigger_cmd_list_t);
        }
#line 4732 "bison_parser.cpp"
    break;

  case 118: /* CreateInparan: column_def_commalist opt_ForeignKeylist  */
#line 1257 "bison_parser.y"
                                            {
        (yyval.CreateInparan_t) = new CreateInparan(); (yyval.CreateInparan_t)->column_def_commalist_ = (yyvsp[-1].column_def_comma_list_t); (yyval.CreateInparan_t)->opt_ForeignKeylist_ = (yyvsp[0].opt_ForeignKeylist_t); }
#line 4739 "bison_parser.cpp"
    break;

  case 119: /* opt_ForeignKeylist: ',' ForeignKeylist  */
#line 1262 "bison_parser.y"
                           {(yyval.opt_ForeignKeylist_t) = new opt_ForeignKeylist(); (yyval.opt_ForeignKeylist_t)->sub_type_ = CASE0; (yyval.opt_ForeignKeylist_t)->ForeignKeylist_ = (yyvsp[0].ForeignKeylist_t);}
#line 4745 "bison_parser.cpp"
    break;

  case 120: /* opt_ForeignKeylist: %empty  */
#line 1263 "bison_parser.y"
                    {(yyval.opt_ForeignKeylist_t) = new opt_ForeignKeylist(); (yyval.opt_ForeignKeylist_t)->sub_type_ = CASE1;}
#line 4751 "bison_parser.cpp"
    break;

  case 121: /* ForeignKeylist: ForeignKeylist ',' ForeignKey  */
#line 1267 "bison_parser.y"
                                      {
            (yyvsp[-2].ForeignKeylist_t)->v_ForeignKey.push_back((yyvsp[0].ForeignKey_t)); 
            (yyval.ForeignKeylist_t) = (yyvsp[-2].ForeignKeylist_t);
        }
#line 4760 "bison_parser.cpp"
    break;

  case 122: /* ForeignKeylist: ForeignKey  */
#line 1271 "bison_parser.y"
                   {
        (yyval.ForeignKeylist_t) = new ForeignKeylist(); 
        (yyval.ForeignKeylist_t)->v_ForeignKey.push_back((yyvsp[0].ForeignKey_t));
        }
#line 4769 "bison_parser.cpp"
    break;

  case 123: /* ForeignKey: FkNoOptstmt opt_Actiontypelist  */
#line 1278 "bison_parser.y"
                                      {
            (yyval.ForeignKey_t) = new ForeignKey();
            (yyval.ForeignKey_t)->FkNoOptstmt_ = (yyvsp[-1].FkNoOptstmt_t);
            (yyval.ForeignKey_t)->opt_Actiontypelist_ = (yyvsp[0].opt_Actiontypelist_t);
    }
#line 4779 "bison_parser.cpp"
    break;

  case 124: /* FkNoOptstmt: ForeignKeyColumn ForeignKeyRef  */
#line 1286 "bison_parser.y"
                                   {
        (yyval.FkNoOptstmt_t) = new FkNoOptstmt();
        (yyval.FkNoOptstmt_t)->ForeignKeyColumn_ = (yyvsp[-1].ForeignKeyColumn_t);
        (yyval.FkNoOptstmt_t)->ForeignKeyRef_ = (yyvsp[0].ForeignKeyRef_t);
    }
#line 4789 "bison_parser.cpp"
    break;

  case 125: /* ForeignKeyColumn: FOREIGN KEY ColumnInParen  */
#line 1294 "bison_parser.y"
                              {
        (yyval.ForeignKeyColumn_t) = new ForeignKeyColumn();
        (yyval.ForeignKeyColumn_t)->column_name_ = (yyvsp[0].Column_In_Paren_t);
    }
#line 4798 "bison_parser.cpp"
    break;

  case 126: /* ForeignKeyRef: REFERENCES table_name ColumnInParen  */
#line 1301 "bison_parser.y"
                                        {
        (yyval.ForeignKeyRef_t) = new ForeignKeyRef();
        (yyval.ForeignKeyRef_t)->table_name_ = (yyvsp[-1].table_name_t);
        (yyval.ForeignKeyRef_t)->column_name_ = (yyvsp[0].Column_In_Paren_t);
    }
#line 4808 "bison_parser.cpp"
    break;

  case 127: /* opt_Actiontypelist: Action_typelist  */
#line 1309 "bison_parser.y"
                        {(yyval.opt_Actiontypelist_t) = new opt_Actiontypelist(); (yyval.opt_Actiontypelist_t)->sub_type_ = CASE0; (yyval.opt_Actiontypelist_t)->Action_typelist_ = (yyvsp[0].Action_typelist_t);}
#line 4814 "bison_parser.cpp"
    break;

  case 128: /* opt_Actiontypelist: %empty  */
#line 1310 "bison_parser.y"
                    {(yyval.opt_Actiontypelist_t) = new opt_Actiontypelist(); (yyval.opt_Actiontypelist_t)->sub_type_ = CASE1;}
#line 4820 "bison_parser.cpp"
    break;

  case 129: /* Action_typelist: Action_typelist Action_type  */
#line 1314 "bison_parser.y"
                                     {
            (yyvsp[-1].Action_typelist_t)->v_Action_type.push_back((yyvsp[0].Action_type_t)); 
            (yyval.Action_typelist_t) = (yyvsp[-1].Action_typelist_t);
            }
#line 4829 "bison_parser.cpp"
    break;

  case 130: /* Action_typelist: Action_type  */
#line 1318 "bison_parser.y"
                    {
        (yyval.Action_typelist_t) = new Action_typelist(); 
        (yyval.Action_typelist_t)->v_Action_type.push_back((yyvsp[0].Action_type_t));
        }
#line 4838 "bison_parser.cpp"
    break;

  case 131: /* Action_type: ON DELETE CASCADE  */
#line 1325 "bison_parser.y"
                      { 
        (yyval.Action_type_t) = new Action_type(); 
        (yyval.Action_type_t)->str_val_ = string("ON DELETE CASCADE"); 
    }
#line 4847 "bison_parser.cpp"
    break;

  case 132: /* Action_type: ON DELETE SET NULL  */
#line 1329 "bison_parser.y"
                         { 
        (yyval.Action_type_t) = new Action_type(); 
        (yyval.Action_type_t)->str_val_ = string("ON DELETE SET NULL"); 
    }
#line 4856 "bison_parser.cpp"
    break;

  case 133: /* Action_type: ON DELETE RESTRICT  */
#line 1333 "bison_parser.y"
                         { 
        (yyval.Action_type_t) = new Action_type(); 
        (yyval.Action_type_t)->str_val_ = string("ON DELETE RESTRICT"); 
    }
#line 4865 "bison_parser.cpp"
    break;

  case 134: /* Action_type: ON DELETE NO ACTION  */
#line 1337 "bison_parser.y"
                          { 
        (yyval.Action_type_t) = new Action_type(); 
        (yyval.Action_type_t)->str_val_ = string("ON DELETE NO ACTION"); 
    }
#line 4874 "bison_parser.cpp"
    break;

  case 135: /* Action_type: ON UPDATE CASCADE  */
#line 1341 "bison_parser.y"
                        { 
        (yyval.Action_type_t) = new Action_type(); 
        (yyval.Action_type_t)->str_val_ = string("ON UPDATE CASCADE"); 
    }
#line 4883 "bison_parser.cpp"
    break;

  case 136: /* Action_type: ON UPDATE SET NULL  */
#line 1345 "bison_parser.y"
                         { 
        (yyval.Action_type_t) = new Action_type(); 
        (yyval.Action_type_t)->str_val_ = string("ON UPDATE SET NULL"); 
    }
#line 4892 "bison_parser.cpp"
    break;

  case 137: /* Action_type: ON UPDATE RESTRICT  */
#line 1349 "bison_parser.y"
                         { 
        (yyval.Action_type_t) = new Action_type(); 
        (yyval.Action_type_t)->str_val_ = string("ON UPDATE RESTRICT"); 
    }
#line 4901 "bison_parser.cpp"
    break;

  case 138: /* Action_type: ON UPDATE NO ACTION  */
#line 1353 "bison_parser.y"
                          { 
        (yyval.Action_type_t) = new Action_type(); 
        (yyval.Action_type_t)->str_val_ = string("ON UPDATE NO ACTION"); 
    }
#line 4910 "bison_parser.cpp"
    break;

  case 139: /* ColumnInParen: '(' column_name ')'  */
#line 1361 "bison_parser.y"
                           {
        (yyval.Column_In_Paren_t) = new ColumnInParen();
        (yyval.Column_In_Paren_t)->column_name_ = (yyvsp[-1].column_name_t);
    }
#line 4919 "bison_parser.cpp"
    break;

  case 140: /* opt_unique: UNIQUE  */
#line 1370 "bison_parser.y"
               {(yyval.opt_unique_t) = new OptUnique(); (yyval.opt_unique_t)->str_val_ = string("UNIQUE");}
#line 4925 "bison_parser.cpp"
    break;

  case 141: /* opt_unique: %empty  */
#line 1371 "bison_parser.y"
                  {(yyval.opt_unique_t) = new OptUnique(); (yyval.opt_unique_t)->str_val_ = string("");}
#line 4931 "bison_parser.cpp"
    break;

  case 142: /* index_name: IDENTIFIER  */
#line 1375 "bison_parser.y"
                   {(yyval.index_name_t) = new IndexName(); (yyval.index_name_t)->id_ = new Identifier((yyvsp[0].sval), id_index_name); free((yyvsp[0].sval));}
#line 4937 "bison_parser.cpp"
    break;

  case 143: /* trigger_declare: opt_tmp TRIGGER opt_not_exists trigger_name opt_trigger_time trigger_event ON table_name opt_for_each opt_when  */
#line 1379 "bison_parser.y"
                                                                                                                       {
            (yyval.trigger_declare_t) = new TriggerDeclare();
            (yyval.trigger_declare_t)->opt_tmp_ = (yyvsp[-9].opt_tmp_t);
            (yyval.trigger_declare_t)->opt_not_exists_ = (yyvsp[-7].opt_not_exists_t);
            (yyval.trigger_declare_t)->trigger_name_ = (yyvsp[-6].trigger_name_t);
            (yyval.trigger_declare_t)->opt_trigger_time_ = (yyvsp[-5].opt_trigger_time_t);
            (yyval.trigger_declare_t)->trigger_event_ = (yyvsp[-4].trigger_event_t);
            (yyval.trigger_declare_t)->table_name_ = (yyvsp[-2].table_name_t);
            (yyval.trigger_declare_t)->opt_for_each_ = (yyvsp[-1].opt_for_each_t);
            (yyval.trigger_declare_t)->opt_when_ = (yyvsp[0].opt_when_t);
        }
#line 4953 "bison_parser.cpp"
    break;

  case 144: /* opt_tmp: TEMP  */
#line 1393 "bison_parser.y"
             {(yyval.opt_tmp_t) = new OptTmp(); (yyval.opt_tmp_t)->str_val_ = string("TEMP");}
#line 4959 "bison_parser.cpp"
    break;

  case 145: /* opt_tmp: %empty  */
#line 1394 "bison_parser.y"
                     {(yyval.opt_tmp_t) = new OptTmp(); (yyval.opt_tmp_t)->str_val_ = string("");}
#line 4965 "bison_parser.cpp"
    break;

  case 146: /* trigger_name: IDENTIFIER  */
#line 1398 "bison_parser.y"
                   {(yyval.trigger_name_t) = new TriggerName(); (yyval.trigger_name_t)->id_ = new Identifier((yyvsp[0].sval), id_trigger_name); free((yyvsp[0].sval));}
#line 4971 "bison_parser.cpp"
    break;

  case 147: /* opt_trigger_time: BEFORE  */
#line 1402 "bison_parser.y"
               {(yyval.opt_trigger_time_t) = new OptTriggerTime(); (yyval.opt_trigger_time_t)->str_val_ = string("BEFORE");}
#line 4977 "bison_parser.cpp"
    break;

  case 148: /* opt_trigger_time: AFTER  */
#line 1403 "bison_parser.y"
              {(yyval.opt_trigger_time_t) = new OptTriggerTime(); (yyval.opt_trigger_time_t)->str_val_ = string("AFTER");}
#line 4983 "bison_parser.cpp"
    break;

  case 149: /* opt_trigger_time: INSTEAD OF  */
#line 1404 "bison_parser.y"
                   {(yyval.opt_trigger_time_t) = new OptTriggerTime(); (yyval.opt_trigger_time_t)->str_val_ = string("INSTEAD OF");}
#line 4989 "bison_parser.cpp"
    break;

  case 150: /* opt_trigger_time: %empty  */
#line 1405 "bison_parser.y"
                    {(yyval.opt_trigger_time_t) = new OptTriggerTime(); (yyval.opt_trigger_time_t)->str_val_ = string("");}
#line 4995 "bison_parser.cpp"
    break;

  case 151: /* trigger_event: DELETE  */
#line 1409 "bison_parser.y"
               {(yyval.trigger_event_t) = new TriggerEvent(); (yyval.trigger_event_t)->sub_type_ = CASE0;}
#line 5001 "bison_parser.cpp"
    break;

  case 152: /* trigger_event: INSERT  */
#line 1410 "bison_parser.y"
               {(yyval.trigger_event_t) = new TriggerEvent(); (yyval.trigger_event_t)->sub_type_ = CASE1;}
#line 5007 "bison_parser.cpp"
    break;

  case 153: /* trigger_event: UPDATE opt_of_column_list  */
#line 1411 "bison_parser.y"
                                  {(yyval.trigger_event_t) = new TriggerEvent(); (yyval.trigger_event_t)->sub_type_ = CASE2; (yyval.trigger_event_t)->opt_of_column_list_ = (yyvsp[0].opt_of_column_list_t);}
#line 5013 "bison_parser.cpp"
    break;

  case 154: /* opt_of_column_list: OF ident_commalist  */
#line 1415 "bison_parser.y"
                           {(yyval.opt_of_column_list_t) = new OptOfColumnList(); (yyval.opt_of_column_list_t)->sub_type_ = CASE0; (yyval.opt_of_column_list_t)->ident_commalist_ = (yyvsp[0].ident_commalist_t);}
#line 5019 "bison_parser.cpp"
    break;

  case 155: /* opt_of_column_list: %empty  */
#line 1416 "bison_parser.y"
                    {(yyval.opt_of_column_list_t) = new OptOfColumnList(); (yyval.opt_of_column_list_t)->sub_type_ = CASE1;}
#line 5025 "bison_parser.cpp"
    break;

  case 156: /* opt_for_each: FOR EACH ROW  */
#line 1420 "bison_parser.y"
                     {(yyval.opt_for_each_t) = new OptForEach(); (yyval.opt_for_each_t)->str_val_ = string("FOR EACH ROW");}
#line 5031 "bison_parser.cpp"
    break;

  case 157: /* opt_for_each: %empty  */
#line 1421 "bison_parser.y"
                    {(yyval.opt_for_each_t) = new OptForEach(); (yyval.opt_for_each_t)->str_val_ = string("");}
#line 5037 "bison_parser.cpp"
    break;

  case 158: /* opt_when: WHEN expr  */
#line 1425 "bison_parser.y"
                  {(yyval.opt_when_t) = new OptWhen(); (yyval.opt_when_t)->sub_type_ = CASE0; (yyval.opt_when_t)->expr_ = (yyvsp[0].expr_t);}
#line 5043 "bison_parser.cpp"
    break;

  case 159: /* opt_when: %empty  */
#line 1426 "bison_parser.y"
                    {(yyval.opt_when_t) = new OptWhen(); (yyval.opt_when_t)->sub_type_ = CASE1;}
#line 5049 "bison_parser.cpp"
    break;

  case 160: /* trigger_cmd_list: trigger_cmd ';'  */
#line 1430 "bison_parser.y"
                        {(yyval.trigger_cmd_list_t) = new TriggerCmdList(); (yyval.trigger_cmd_list_t)->v_trigger_cmd_list_.push_back((yyvsp[-1].trigger_cmd_t));}
#line 5055 "bison_parser.cpp"
    break;

  case 161: /* trigger_cmd_list: trigger_cmd_list trigger_cmd ';'  */
#line 1431 "bison_parser.y"
                                         {(yyvsp[-2].trigger_cmd_list_t)->v_trigger_cmd_list_.push_back((yyvsp[-1].trigger_cmd_t)); (yyval.trigger_cmd_list_t) = (yyvsp[-2].trigger_cmd_list_t);}
#line 5061 "bison_parser.cpp"
    break;

  case 162: /* trigger_cmd: select_statement  */
#line 1435 "bison_parser.y"
                         {(yyval.trigger_cmd_t) = new TriggerCmd(); (yyval.trigger_cmd_t)->stmt_ = (yyvsp[0].select_statement_t);}
#line 5067 "bison_parser.cpp"
    break;

  case 163: /* trigger_cmd: update_statement  */
#line 1436 "bison_parser.y"
                         {(yyval.trigger_cmd_t) = new TriggerCmd(); (yyval.trigger_cmd_t)->stmt_ = (yyvsp[0].update_statement_t);}
#line 5073 "bison_parser.cpp"
    break;

  case 164: /* trigger_cmd: insert_statement  */
#line 1437 "bison_parser.y"
                         {(yyval.trigger_cmd_t) = new TriggerCmd(); (yyval.trigger_cmd_t)->stmt_ = (yyvsp[0].insert_statement_t);}
#line 5079 "bison_parser.cpp"
    break;

  case 165: /* trigger_cmd: delete_statement  */
#line 1438 "bison_parser.y"
                         {(yyval.trigger_cmd_t) = new TriggerCmd(); (yyval.trigger_cmd_t)->stmt_ = (yyvsp[0].delete_statement_t);}
#line 5085 "bison_parser.cpp"
    break;

  case 166: /* module_name: IDENTIFIER  */
#line 1442 "bison_parser.y"
                   {(yyval.module_name_t) = new ModuleName(); (yyval.module_name_t)->id_ = new Identifier((yyvsp[0].sval)); free((yyvsp[0].sval));}
#line 5091 "bison_parser.cpp"
    break;

  case 167: /* opt_not_exists: IF NOT EXISTS  */
#line 1447 "bison_parser.y"
                      { (yyval.opt_not_exists_t) = new OptNotExists(); (yyval.opt_not_exists_t)->sub_type_ = CASE0; }
#line 5097 "bison_parser.cpp"
    break;

  case 168: /* opt_not_exists: %empty  */
#line 1448 "bison_parser.y"
                    { (yyval.opt_not_exists_t) = new OptNotExists(); (yyval.opt_not_exists_t)->sub_type_ = CASE1; }
#line 5103 "bison_parser.cpp"
    break;

  case 169: /* column_def_commalist: column_def  */
#line 1452 "bison_parser.y"
                   { 
            (yyval.column_def_comma_list_t) = new ColumnDefCommaList(); 
            (yyval.column_def_comma_list_t)->v_column_def_comma_list_.push_back((yyvsp[0].column_def_t));
        }
#line 5112 "bison_parser.cpp"
    break;

  case 170: /* column_def_commalist: column_def_commalist ',' column_def  */
#line 1456 "bison_parser.y"
                                            { 
            (yyvsp[-2].column_def_comma_list_t)->v_column_def_comma_list_.push_back((yyvsp[0].column_def_t));
            (yyval.column_def_comma_list_t) = (yyvsp[-2].column_def_comma_list_t);
        }
#line 5121 "bison_parser.cpp"
    break;

  case 171: /* column_def: IDENTIFIER column_type opt_column_arglist  */
#line 1463 "bison_parser.y"
                                                  {
            (yyval.column_def_t) = new ColumnDef();
			(yyval.column_def_t)->id_ = new Identifier((yyvsp[-2].sval), id_create_column_name);
            (yyval.column_def_t)->column_type_ = (yyvsp[-1].column_type_t);
            (yyval.column_def_t)->opt_column_arglist_ = (yyvsp[0].opt_column_arglist_t);
            free((yyvsp[-2].sval)); 
        }
#line 5133 "bison_parser.cpp"
    break;

  case 172: /* opt_column_arglist: column_arglist  */
#line 1474 "bison_parser.y"
                       {(yyval.opt_column_arglist_t) = new OptColumnArglist(); (yyval.opt_column_arglist_t)->sub_type_ = CASE0; (yyval.opt_column_arglist_t)->column_arglist_ = (yyvsp[0].column_arglist_t);}
#line 5139 "bison_parser.cpp"
    break;

  case 173: /* opt_column_arglist: %empty  */
#line 1475 "bison_parser.y"
                    {(yyval.opt_column_arglist_t) = new OptColumnArglist(); (yyval.opt_column_arglist_t)->sub_type_ = CASE1;}
#line 5145 "bison_parser.cpp"
    break;

  case 174: /* column_arglist: column_arglist column_arg  */
#line 1479 "bison_parser.y"
                                  {
            (yyvsp[-1].column_arglist_t)->v_column_arg_.push_back((yyvsp[0].column_arg_t)); 
            (yyval.column_arglist_t) = (yyvsp[-1].column_arglist_t);
            }
#line 5154 "bison_parser.cpp"
    break;

  case 175: /* column_arglist: column_arg  */
#line 1483 "bison_parser.y"
                   {
        (yyval.column_arglist_t) = new ColumnArglist(); 
        (yyval.column_arglist_t)->v_column_arg_.push_back((yyvsp[0].column_arg_t));
        }
#line 5163 "bison_parser.cpp"
    break;

  case 176: /* column_arg: NULL opt_on_conflict  */
#line 1490 "bison_parser.y"
                             {(yyval.column_arg_t) = new ColumnArg(); (yyval.column_arg_t)->sub_type_ = CASE0; (yyval.column_arg_t)->opt_on_conflict_ = (yyvsp[0].opt_on_conflict_t);}
#line 5169 "bison_parser.cpp"
    break;

  case 177: /* column_arg: NOT NULL opt_on_conflict  */
#line 1491 "bison_parser.y"
                                 {(yyval.column_arg_t) = new ColumnArg(); (yyval.column_arg_t)->sub_type_ = CASE1; (yyval.column_arg_t)->opt_on_conflict_ = (yyvsp[0].opt_on_conflict_t);}
#line 5175 "bison_parser.cpp"
    break;

  case 178: /* column_arg: PRIMARY KEY opt_order_type opt_on_conflict opt_autoinc  */
#line 1492 "bison_parser.y"
                                                               {
                (yyval.column_arg_t) = new ColumnArg(); 
                (yyval.column_arg_t)->sub_type_ = CASE2; 
                (yyval.column_arg_t)->opt_order_type_ = (yyvsp[-2].opt_order_type_t);
                (yyval.column_arg_t)->opt_on_conflict_ = (yyvsp[-1].opt_on_conflict_t);
                (yyval.column_arg_t)->opt_autoinc_ = (yyvsp[0].opt_autoinc_t);
        }
#line 5187 "bison_parser.cpp"
    break;

  case 179: /* column_arg: UNIQUE opt_on_conflict  */
#line 1499 "bison_parser.y"
                               {(yyval.column_arg_t) = new ColumnArg(); (yyval.column_arg_t)->sub_type_ = CASE3; (yyval.column_arg_t)->opt_on_conflict_ = (yyvsp[0].opt_on_conflict_t);}
#line 5193 "bison_parser.cpp"
    break;

  case 180: /* column_arg: GENERATED ALWAYS AS '(' expr ')'  */
#line 1500 "bison_parser.y"
                                         {(yyval.column_arg_t) = new ColumnArg(); (yyval.column_arg_t)->sub_type_ = CASE4; (yyval.column_arg_t)->expr_ = (yyvsp[-1].expr_t);}
#line 5199 "bison_parser.cpp"
    break;

  case 181: /* column_arg: AS '(' expr ')'  */
#line 1501 "bison_parser.y"
                        {(yyval.column_arg_t) = new ColumnArg(); (yyval.column_arg_t)->sub_type_ = CASE5; (yyval.column_arg_t)->expr_ = (yyvsp[-1].expr_t);}
#line 5205 "bison_parser.cpp"
    break;

  case 182: /* column_arg: CHECK '(' expr ')'  */
#line 1502 "bison_parser.y"
                           {(yyval.column_arg_t) = new ColumnArg(); (yyval.column_arg_t)->sub_type_ = CASE6; (yyval.column_arg_t)->expr_ = (yyvsp[-1].expr_t);}
#line 5211 "bison_parser.cpp"
    break;

  case 183: /* opt_on_conflict: ON CONFLICT resolve_type  */
#line 1506 "bison_parser.y"
                                 {(yyval.opt_on_conflict_t) = new OptOnConflict(); (yyval.opt_on_conflict_t)->sub_type_ = CASE0; (yyval.opt_on_conflict_t)->resolve_type_ = (yyvsp[0].resolve_type_t);}
#line 5217 "bison_parser.cpp"
    break;

  case 184: /* opt_on_conflict: %empty  */
#line 1507 "bison_parser.y"
                    {(yyval.opt_on_conflict_t) = new OptOnConflict(); (yyval.opt_on_conflict_t)->sub_type_ = CASE1;}
#line 5223 "bison_parser.cpp"
    break;

  case 185: /* resolve_type: IGNORE  */
#line 1511 "bison_parser.y"
               {(yyval.resolve_type_t) = new ResolveType(); (yyval.resolve_type_t)->str_val_ = string("IGNORE");}
#line 5229 "bison_parser.cpp"
    break;

  case 186: /* resolve_type: REPLACE  */
#line 1512 "bison_parser.y"
                {(yyval.resolve_type_t) = new ResolveType(); (yyval.resolve_type_t)->str_val_ = string("REPLACE");}
#line 5235 "bison_parser.cpp"
    break;

  case 187: /* resolve_type: ROLLBACK  */
#line 1513 "bison_parser.y"
                 {(yyval.resolve_type_t) = new ResolveType(); (yyval.resolve_type_t)->str_val_ = string("ROLLBACK");}
#line 5241 "bison_parser.cpp"
    break;

  case 188: /* resolve_type: ABORT  */
#line 1514 "bison_parser.y"
              {(yyval.resolve_type_t) = new ResolveType(); (yyval.resolve_type_t)->str_val_ = string("ABORT");}
#line 5247 "bison_parser.cpp"
    break;

  case 189: /* resolve_type: FAIL  */
#line 1515 "bison_parser.y"
             {(yyval.resolve_type_t) = new ResolveType(); (yyval.resolve_type_t)->str_val_ = string("FAIL");}
#line 5253 "bison_parser.cpp"
    break;

  case 190: /* opt_autoinc: AUTOINCR  */
#line 1519 "bison_parser.y"
                 {(yyval.opt_autoinc_t) = new OptAutoinc(); (yyval.opt_autoinc_t)->str_val_ = string("AUTOINCR");}
#line 5259 "bison_parser.cpp"
    break;

  case 191: /* opt_autoinc: %empty  */
#line 1520 "bison_parser.y"
                    {(yyval.opt_autoinc_t) = new OptAutoinc(); (yyval.opt_autoinc_t)->str_val_ = string("");}
#line 5265 "bison_parser.cpp"
    break;

  case 192: /* column_type: INT  */
#line 1525 "bison_parser.y"
            { (yyval.column_type_t) = new ColumnType(); (yyval.column_type_t)->str_val_ = string("INT"); }
#line 5271 "bison_parser.cpp"
    break;

  case 193: /* column_type: INTEGER  */
#line 1526 "bison_parser.y"
                { (yyval.column_type_t) = new ColumnType(); (yyval.column_type_t)->str_val_ = string("INTEGER"); }
#line 5277 "bison_parser.cpp"
    break;

  case 194: /* column_type: LONG  */
#line 1527 "bison_parser.y"
             { (yyval.column_type_t) = new ColumnType(); (yyval.column_type_t)->str_val_ = string("LONG"); }
#line 5283 "bison_parser.cpp"
    break;

  case 195: /* column_type: FLOAT  */
#line 1528 "bison_parser.y"
              { (yyval.column_type_t) = new ColumnType(); (yyval.column_type_t)->str_val_ = string("FLOAT"); }
#line 5289 "bison_parser.cpp"
    break;

  case 196: /* column_type: DOUBLE  */
#line 1529 "bison_parser.y"
               { (yyval.column_type_t) = new ColumnType(); (yyval.column_type_t)->str_val_ = string("DOUBLE"); }
#line 5295 "bison_parser.cpp"
    break;

  case 197: /* column_type: VARCHAR '(' INTVAL ')'  */
#line 1530 "bison_parser.y"
                               { 
            (yyval.column_type_t) = new ColumnType();
            (yyval.column_type_t)->str_val_ = string("VARCHAR(") + to_string((yyvsp[-1].ival)) + ")"; 
            }
#line 5304 "bison_parser.cpp"
    break;

  case 198: /* column_type: CHAR '(' INTVAL ')'  */
#line 1534 "bison_parser.y"
                            { (yyval.column_type_t) = new ColumnType(); 
            (yyval.column_type_t)->str_val_ = string("CHAR(") + to_string((yyvsp[-1].ival)) + ")"; 
            }
#line 5312 "bison_parser.cpp"
    break;

  case 199: /* column_type: TEXT  */
#line 1537 "bison_parser.y"
             { (yyval.column_type_t) = new ColumnType(); (yyval.column_type_t)->str_val_ = string("TEXT"); }
#line 5318 "bison_parser.cpp"
    break;

  case 200: /* column_type: %empty  */
#line 1538 "bison_parser.y"
                   { (yyval.column_type_t) = new ColumnType(); (yyval.column_type_t)->str_val_ = string(""); }
#line 5324 "bison_parser.cpp"
    break;

  case 201: /* drop_statement: DROP TABLE opt_exists table_name  */
#line 1548 "bison_parser.y"
                                         {
            (yyval.drop_statement_t) = new DropStatement();
            (yyval.drop_statement_t)->sub_type_ = CASE0;
            (yyval.drop_statement_t)->opt_exists_ = (yyvsp[-1].opt_exists_t);
            (yyval.drop_statement_t)->table_name_ = (yyvsp[0].table_name_t);
            (yyval.drop_statement_t)->table_name_->table_name_->id_type_ = id_top_table_name;
            (yyval.drop_statement_t)->id_ = NULL;
        }
#line 5337 "bison_parser.cpp"
    break;

  case 202: /* drop_statement: DROP VIEW opt_exists table_name  */
#line 1556 "bison_parser.y"
                                        {
            (yyval.drop_statement_t) = new DropStatement();
            (yyval.drop_statement_t)->sub_type_ = CASE1;
            (yyval.drop_statement_t)->opt_exists_ = (yyvsp[-1].opt_exists_t);
            (yyval.drop_statement_t)->table_name_ = (yyvsp[0].table_name_t);
            (yyval.drop_statement_t)->table_name_->table_name_->id_type_ = id_top_table_name;
            (yyval.drop_statement_t)->id_ = NULL;
        }
#line 5350 "bison_parser.cpp"
    break;

  case 203: /* drop_statement: DEALLOCATE PREPARE IDENTIFIER  */
#line 1564 "bison_parser.y"
                                      {
            (yyval.drop_statement_t) = new DropStatement();
            (yyval.drop_statement_t)->sub_type_ = CASE2;
            (yyval.drop_statement_t)->id_ = new Identifier((yyvsp[0].sval));
            free((yyvsp[0].sval));
        }
#line 5361 "bison_parser.cpp"
    break;

  case 204: /* drop_statement: DROP TRIGGER opt_exists schema_name '.' trigger_name  */
#line 1570 "bison_parser.y"
                                                           {
            (yyval.drop_statement_t) = new DropStatement();
            (yyval.drop_statement_t)->sub_type_ = CASE3;
            (yyval.drop_statement_t)->opt_exists_ = (yyvsp[-3].opt_exists_t);
            (yyval.drop_statement_t)->schema_name_ = (yyvsp[-2].schema_name_t);
            (yyval.drop_statement_t)->trigger_name_ = (yyvsp[0].trigger_name_t);
    }
#line 5373 "bison_parser.cpp"
    break;

  case 205: /* drop_statement: DROP TRIGGER opt_exists trigger_name  */
#line 1578 "bison_parser.y"
                                           {
            (yyval.drop_statement_t) = new DropStatement();
            (yyval.drop_statement_t)->sub_type_ = CASE4;
            (yyval.drop_statement_t)->opt_exists_ = (yyvsp[-1].opt_exists_t);
            (yyval.drop_statement_t)->trigger_name_ = (yyvsp[0].trigger_name_t);
    }
#line 5384 "bison_parser.cpp"
    break;

  case 206: /* opt_exists: IF EXISTS  */
#line 1587 "bison_parser.y"
                    { (yyval.opt_exists_t) = new OptExists(); (yyval.opt_exists_t)->str_val_=string("IF EXISTS"); }
#line 5390 "bison_parser.cpp"
    break;

  case 207: /* opt_exists: %empty  */
#line 1588 "bison_parser.y"
                    { (yyval.opt_exists_t) = new OptExists(); (yyval.opt_exists_t)->str_val_=string(""); }
#line 5396 "bison_parser.cpp"
    break;

  case 208: /* delete_statement: DELETE FROM table_name opt_where  */
#line 1597 "bison_parser.y"
                                         {
            (yyval.delete_statement_t) = new DeleteStatement();
            (yyval.delete_statement_t)->sub_type_ = CASE0;
            (yyval.delete_statement_t)->table_name_ = (yyvsp[-1].table_name_t);
            (yyval.delete_statement_t)->table_name_->table_name_->id_type_ = id_top_table_name;
            (yyval.delete_statement_t)->opt_where_ = (yyvsp[0].opt_where_t);
        }
#line 5408 "bison_parser.cpp"
    break;

  case 209: /* truncate_statement: TRUNCATE table_name  */
#line 1607 "bison_parser.y"
                            {
            (yyval.delete_statement_t) = new DeleteStatement();
            (yyval.delete_statement_t)->sub_type_ = CASE1;
            (yyval.delete_statement_t)->table_name_ = (yyvsp[0].table_name_t);
            (yyval.delete_statement_t)->table_name_->table_name_->id_type_ = id_top_table_name;

        }
#line 5420 "bison_parser.cpp"
    break;

  case 210: /* insert_statement: insert_type INTO table_name opt_column_list VALUES super_list opt_upsert_clause  */
#line 1622 "bison_parser.y"
                                                                                       {
            (yyval.insert_statement_t) = new InsertStatement();
            (yyval.insert_statement_t)->sub_type_ = CASE0;
            (yyval.insert_statement_t)->insert_type_ = (yyvsp[-6].insert_type_t);
            (yyval.insert_statement_t)->table_name_ = (yyvsp[-4].table_name_t);
            (yyval.insert_statement_t)->table_name_->table_name_->id_type_ = id_top_table_name;
            (yyval.insert_statement_t)->opt_column_list_ = (yyvsp[-3].opt_column_list_t);
            (yyval.insert_statement_t)->super_list_ = (yyvsp[-1].super_list_t);
            (yyval.insert_statement_t)->opt_upsert_clause_ = (yyvsp[0].opt_upsert_clause_t);
            if((yyval.insert_statement_t)->opt_column_list_->sub_type_ == CASE0){
                for(auto &cname: (yyval.insert_statement_t)->opt_column_list_->ident_comma_list_->v_iden_comma_list_){
                    cname->id_type_ = id_column_name;
                }    
            }
        }
#line 5440 "bison_parser.cpp"
    break;

  case 211: /* insert_statement: insert_type INTO table_name opt_column_list select_no_paren opt_upsert_clause  */
#line 1637 "bison_parser.y"
                                                                                     {
            (yyval.insert_statement_t) = new InsertStatement();
            (yyval.insert_statement_t)->sub_type_ = CASE1;
            (yyval.insert_statement_t)->insert_type_ = (yyvsp[-5].insert_type_t);
            (yyval.insert_statement_t)->table_name_ = (yyvsp[-3].table_name_t);
            (yyval.insert_statement_t)->table_name_->table_name_->id_type_ = id_top_table_name;
            (yyval.insert_statement_t)->opt_column_list_ = (yyvsp[-2].opt_column_list_t);
            (yyval.insert_statement_t)->select_no_paren_ = (yyvsp[-1].select_no_paren_t);
            (yyval.insert_statement_t)->opt_upsert_clause_ = (yyvsp[0].opt_upsert_clause_t);
            if((yyval.insert_statement_t)->opt_column_list_->sub_type_ == CASE0){
                for(auto &cname: (yyval.insert_statement_t)->opt_column_list_->ident_comma_list_->v_iden_comma_list_){
                    cname->id_type_ = id_column_name;
                }    
            }
        }
#line 5460 "bison_parser.cpp"
    break;

  case 212: /* super_list: '(' literal_list ')'  */
#line 1655 "bison_parser.y"
                            {
            (yyval.super_list_t) = new SuperList(); (yyval.super_list_t)->v_super_list_.push_back((yyvsp[-1].literal_list_t));
        }
#line 5468 "bison_parser.cpp"
    break;

  case 213: /* super_list: super_list ',' '(' literal_list ')'  */
#line 1658 "bison_parser.y"
                                           {
            (yyvsp[-4].super_list_t)->v_super_list_.push_back((yyvsp[-1].literal_list_t));
            (yyval.super_list_t) = (yyvsp[-4].super_list_t);
        }
#line 5477 "bison_parser.cpp"
    break;

  case 214: /* insert_type: INSERT  */
#line 1665 "bison_parser.y"
               { (yyval.insert_type_t) = new InsertType(); (yyval.insert_type_t)->sub_type_ = CASE0; (yyval.insert_type_t)->str_val_ = string("INSERT"); }
#line 5483 "bison_parser.cpp"
    break;

  case 215: /* insert_type: REPLACE  */
#line 1666 "bison_parser.y"
                  {(yyval.insert_type_t) = new InsertType(); (yyval.insert_type_t)->sub_type_ = CASE1; (yyval.insert_type_t)->str_val_  = string("REPLACE");}
#line 5489 "bison_parser.cpp"
    break;

  case 216: /* insert_type: INSERT OR resolve_type  */
#line 1667 "bison_parser.y"
                                 {(yyval.insert_type_t) = new InsertType(); (yyval.insert_type_t)->sub_type_ = CASE2; (yyval.insert_type_t)->resolve_type_ = (yyvsp[0].resolve_type_t);}
#line 5495 "bison_parser.cpp"
    break;

  case 217: /* opt_column_list: '(' ident_commalist ')'  */
#line 1671 "bison_parser.y"
                                { (yyval.opt_column_list_t) = new OptColumnList(); (yyval.opt_column_list_t)->sub_type_ = CASE0; (yyval.opt_column_list_t)->ident_comma_list_ = (yyvsp[-1].ident_commalist_t); }
#line 5501 "bison_parser.cpp"
    break;

  case 218: /* opt_column_list: %empty  */
#line 1672 "bison_parser.y"
                    { (yyval.opt_column_list_t) = new OptColumnList(); (yyval.opt_column_list_t)->sub_type_ = CASE1; }
#line 5507 "bison_parser.cpp"
    break;

  case 219: /* update_statement: UPDATE table_ref_name_no_alias SET update_clause_commalist opt_where  */
#line 1682 "bison_parser.y"
                                                                         {
        (yyval.update_statement_t) = new UpdateStatement();
        (yyval.update_statement_t)->table_ref_name_no_alias_ = (yyvsp[-3].table_ref_name_no_alias_t); //had set id_top_table_name in table_ref_name_no_alias
        (yyval.update_statement_t)->update_clause_comma_list_ = (yyvsp[-1].update_clause_commalist_t);
        (yyval.update_statement_t)->opt_where_ = (yyvsp[0].opt_where_t);
    }
#line 5518 "bison_parser.cpp"
    break;

  case 220: /* update_clause_commalist: update_clause  */
#line 1691 "bison_parser.y"
                      { 
            (yyval.update_clause_commalist_t) = new UpdateClauseCommalist(); 
            (yyval.update_clause_commalist_t)->v_update_clause_list_.push_back((yyvsp[0].update_clause_t)); 
            }
#line 5527 "bison_parser.cpp"
    break;

  case 221: /* update_clause_commalist: update_clause_commalist ',' update_clause  */
#line 1695 "bison_parser.y"
                                                  { 
        (yyvsp[-2].update_clause_commalist_t)->v_update_clause_list_.push_back((yyvsp[0].update_clause_t)); 
        (yyval.update_clause_commalist_t) = (yyvsp[-2].update_clause_commalist_t); }
#line 5535 "bison_parser.cpp"
    break;

  case 222: /* update_clause: IDENTIFIER '=' expr  */
#line 1701 "bison_parser.y"
                            {
            (yyval.update_clause_t) = new UpdateClause();
            (yyval.update_clause_t)->id_ = new Identifier((yyvsp[-2].sval), id_column_name);
            (yyval.update_clause_t)->expr_ = (yyvsp[0].expr_t);
            free((yyvsp[-2].sval));
        }
#line 5546 "bison_parser.cpp"
    break;

  case 223: /* select_statement: opt_with_clause select_with_paren  */
#line 1715 "bison_parser.y"
                                          {
            (yyval.select_statement_t) = new SelectStatement();
            (yyval.select_statement_t)->sub_type_ = CASE0;
            (yyval.select_statement_t)->opt_with_clause_ = (yyvsp[-1].opt_with_clause_t);
            (yyval.select_statement_t)->select_with_paren_ = (yyvsp[0].select_with_paren_t);
        }
#line 5557 "bison_parser.cpp"
    break;

  case 224: /* select_statement: opt_with_clause select_no_paren  */
#line 1721 "bison_parser.y"
                                        {
            (yyval.select_statement_t) = new SelectStatement();
            (yyval.select_statement_t)->sub_type_ = CASE1;
            (yyval.select_statement_t)->opt_with_clause_ = (yyvsp[-1].opt_with_clause_t);
            (yyval.select_statement_t)->select_no_paren_ = (yyvsp[0].select_no_paren_t);
        }
#line 5568 "bison_parser.cpp"
    break;

  case 225: /* select_statement: opt_with_clause select_with_paren set_operator select_paren_or_clause opt_order opt_limit  */
#line 1727 "bison_parser.y"
                                                                                                  {
            (yyval.select_statement_t) = new SelectStatement();
            (yyval.select_statement_t)->sub_type_ = CASE2;
            (yyval.select_statement_t)->opt_with_clause_ = (yyvsp[-5].opt_with_clause_t);
            (yyval.select_statement_t)->select_with_paren_ = (yyvsp[-4].select_with_paren_t);
            (yyval.select_statement_t)->set_operator_ = (yyvsp[-3].set_operator_t);
            (yyval.select_statement_t)->select_paren_or_clause_ = (yyvsp[-2].select_paren_or_clause_t);
            (yyval.select_statement_t)->opt_order_ = (yyvsp[-1].opt_order_t);
            (yyval.select_statement_t)->opt_limit_ = (yyvsp[0].opt_limit_t);
            
        }
#line 5584 "bison_parser.cpp"
    break;

  case 226: /* select_with_paren: '(' select_no_paren ')'  */
#line 1741 "bison_parser.y"
                                { (yyval.select_with_paren_t) = new SelectWithParen(); (yyval.select_with_paren_t)->sub_type_ = CASE0; (yyval.select_with_paren_t)->select_no_paren_=(yyvsp[-1].select_no_paren_t);}
#line 5590 "bison_parser.cpp"
    break;

  case 227: /* select_with_paren: '(' select_with_paren ')'  */
#line 1742 "bison_parser.y"
                                  { (yyval.select_with_paren_t) = new SelectWithParen(); (yyval.select_with_paren_t)->sub_type_ = CASE1; (yyval.select_with_paren_t)->select_with_paren_=(yyvsp[-1].select_with_paren_t);}
#line 5596 "bison_parser.cpp"
    break;

  case 228: /* select_paren_or_clause: select_with_paren  */
#line 1746 "bison_parser.y"
                          {(yyval.select_paren_or_clause_t) = new SelectParenOrClause(); (yyval.select_paren_or_clause_t)->sub_type_=CASE0; (yyval.select_paren_or_clause_t)->select_with_paren_=(yyvsp[0].select_with_paren_t);}
#line 5602 "bison_parser.cpp"
    break;

  case 229: /* select_paren_or_clause: select_clause  */
#line 1747 "bison_parser.y"
                      {(yyval.select_paren_or_clause_t)=new SelectParenOrClause(); (yyval.select_paren_or_clause_t)->sub_type_=CASE1; (yyval.select_paren_or_clause_t)->select_clause_=(yyvsp[0].select_clause_t);}
#line 5608 "bison_parser.cpp"
    break;

  case 230: /* select_no_paren: select_clause opt_order opt_limit  */
#line 1751 "bison_parser.y"
                                          {
            (yyval.select_no_paren_t) = new SelectNoParen();
            (yyval.select_no_paren_t)->sub_type_ = CASE0;
            (yyval.select_no_paren_t)->select_clause_ = (yyvsp[-2].select_clause_t);
            (yyval.select_no_paren_t)->opt_order_ = (yyvsp[-1].opt_order_t);
            (yyval.select_no_paren_t)->opt_limit_ = (yyvsp[0].opt_limit_t);
        }
#line 5620 "bison_parser.cpp"
    break;

  case 231: /* select_no_paren: select_clause set_operator select_paren_or_clause opt_order opt_limit  */
#line 1758 "bison_parser.y"
                                                                              {
            (yyval.select_no_paren_t) = new SelectNoParen();
            (yyval.select_no_paren_t)->sub_type_ = CASE1;
            (yyval.select_no_paren_t)->select_clause_ = (yyvsp[-4].select_clause_t);
            (yyval.select_no_paren_t)->set_operator_ = (yyvsp[-3].set_operator_t);
            (yyval.select_no_paren_t)->select_paren_or_clause_ = (yyvsp[-2].select_paren_or_clause_t);
            (yyval.select_no_paren_t)->opt_order_ = (yyvsp[-1].opt_order_t);
            (yyval.select_no_paren_t)->opt_limit_ = (yyvsp[0].opt_limit_t);    
        }
#line 5634 "bison_parser.cpp"
    break;

  case 232: /* set_operator: set_type opt_all  */
#line 1770 "bison_parser.y"
                         {
            (yyval.set_operator_t) = new SetOperator();
            (yyval.set_operator_t)->set_type_ = (yyvsp[-1].set_type_t);
            (yyval.set_operator_t)->opt_all_ = (yyvsp[0].opt_all_t);
            }
#line 5644 "bison_parser.cpp"
    break;

  case 233: /* set_type: UNION  */
#line 1778 "bison_parser.y"
              {(yyval.set_type_t) = new SetType(); (yyval.set_type_t)->str_val_ = string("UNION");}
#line 5650 "bison_parser.cpp"
    break;

  case 234: /* set_type: INTERSECT  */
#line 1779 "bison_parser.y"
                  {(yyval.set_type_t) = new SetType(); (yyval.set_type_t)->str_val_ = string("INTERSECT");}
#line 5656 "bison_parser.cpp"
    break;

  case 235: /* set_type: EXCEPT  */
#line 1780 "bison_parser.y"
                {(yyval.set_type_t) = new SetType(); (yyval.set_type_t)->str_val_ = string("EXCEPT");}
#line 5662 "bison_parser.cpp"
    break;

  case 236: /* opt_all: ALL  */
#line 1784 "bison_parser.y"
            {(yyval.opt_all_t) = new OptAll(); (yyval.opt_all_t)->str_val_ = string("ALL");}
#line 5668 "bison_parser.cpp"
    break;

  case 237: /* opt_all: %empty  */
#line 1785 "bison_parser.y"
                    {(yyval.opt_all_t) = new OptAll(); (yyval.opt_all_t)->str_val_ = string("");}
#line 5674 "bison_parser.cpp"
    break;

  case 238: /* select_clause: SELECT opt_top opt_distinct select_list opt_from_clause opt_where opt_group  */
#line 1789 "bison_parser.y"
                                                                                    {
            (yyval.select_clause_t) = new SelectClause();
            (yyval.select_clause_t)->sub_type_ = CASE0;
            (yyval.select_clause_t)->opt_top_ = (yyvsp[-5].opt_top_t);
            (yyval.select_clause_t)->opt_distinct_ = (yyvsp[-4].opt_distinct_t);
            (yyval.select_clause_t)->select_list_ = (yyvsp[-3].select_list_t);
            (yyval.select_clause_t)->opt_from_clause_ = (yyvsp[-2].opt_from_clause_t);
            (yyval.select_clause_t)->opt_where_ = (yyvsp[-1].opt_where_t);
            (yyval.select_clause_t)->opt_group_ = (yyvsp[0].opt_group_t);
        }
#line 5689 "bison_parser.cpp"
    break;

  case 239: /* select_clause: SELECT opt_top opt_distinct select_list opt_from_clause opt_where opt_group window_clause  */
#line 1800 "bison_parser.y"
                                                                                                  {
            (yyval.select_clause_t) = new SelectClause();
            (yyval.select_clause_t)->sub_type_ = CASE1;
            (yyval.select_clause_t)->opt_top_ = (yyvsp[-6].opt_top_t);
            (yyval.select_clause_t)->opt_distinct_ = (yyvsp[-5].opt_distinct_t);
            (yyval.select_clause_t)->select_list_ = (yyvsp[-4].select_list_t);
            (yyval.select_clause_t)->opt_from_clause_ = (yyvsp[-3].opt_from_clause_t);
            (yyval.select_clause_t)->opt_where_ = (yyvsp[-2].opt_where_t);
            (yyval.select_clause_t)->opt_group_ = (yyvsp[-1].opt_group_t);
            (yyval.select_clause_t)->window_clause_ = (yyvsp[0].window_clause_t);
        }
#line 5705 "bison_parser.cpp"
    break;

  case 240: /* window_clause: WINDOW windowdefn_list  */
#line 1814 "bison_parser.y"
                               {(yyval.window_clause_t) = new WindowClause(); (yyval.window_clause_t)->windowdefn_list_ = (yyvsp[0].window_defn_list_t);}
#line 5711 "bison_parser.cpp"
    break;

  case 241: /* windowdefn_list: windowdefn  */
#line 1818 "bison_parser.y"
                   {(yyval.window_defn_list_t) = new WindowDefnList(); (yyval.window_defn_list_t)->v_windowdefn_list_.push_back((yyvsp[0].window_defn_t));}
#line 5717 "bison_parser.cpp"
    break;

  case 242: /* windowdefn_list: windowdefn_list ',' windowdefn  */
#line 1819 "bison_parser.y"
                                       {(yyvsp[-2].window_defn_list_t)->v_windowdefn_list_.push_back((yyvsp[0].window_defn_t)); (yyval.window_defn_list_t) = (yyvsp[-2].window_defn_list_t);}
#line 5723 "bison_parser.cpp"
    break;

  case 243: /* windowdefn: IDENTIFIER AS '(' window ')'  */
#line 1823 "bison_parser.y"
                                     {(yyval.window_defn_t) = new WindowDefn(); (yyval.window_defn_t)->id_ = new Identifier((yyvsp[-4].sval)); (yyval.window_defn_t)->window_ = (yyvsp[-1].window_t); free((yyvsp[-4].sval));}
#line 5729 "bison_parser.cpp"
    break;

  case 244: /* window: opt_base_window_name PARTITION BY expr_list opt_order opt_frame  */
#line 1827 "bison_parser.y"
                                                                        {
            (yyval.window_t) = new Window();
            (yyval.window_t)->sub_type_ = CASE0;
            (yyval.window_t)->opt_base_window_name_ = (yyvsp[-5].opt_base_window_name_t);
            (yyval.window_t)->expr_list_ = (yyvsp[-2].expr_list_t);
            (yyval.window_t)->opt_order_ = (yyvsp[-1].opt_order_t);
            (yyval.window_t)->opt_frame_ = (yyvsp[0].opt_frame_t);
        }
#line 5742 "bison_parser.cpp"
    break;

  case 245: /* window: opt_base_window_name opt_order opt_frame  */
#line 1835 "bison_parser.y"
                                                 {
            (yyval.window_t) = new Window();
            (yyval.window_t)->sub_type_ = CASE1;
            (yyval.window_t)->opt_base_window_name_ = (yyvsp[-2].opt_base_window_name_t);
            (yyval.window_t)->opt_order_ = (yyvsp[-1].opt_order_t);
            (yyval.window_t)->opt_frame_ = (yyvsp[0].opt_frame_t);
        }
#line 5754 "bison_parser.cpp"
    break;

  case 246: /* opt_base_window_name: IDENTIFIER  */
#line 1845 "bison_parser.y"
                   {(yyval.opt_base_window_name_t) = new OptBaseWindowName(); (yyval.opt_base_window_name_t)->sub_type_ = CASE0; (yyval.opt_base_window_name_t)->id_ = new Identifier((yyvsp[0].sval)); free((yyvsp[0].sval));}
#line 5760 "bison_parser.cpp"
    break;

  case 247: /* opt_base_window_name: %empty  */
#line 1846 "bison_parser.y"
                  {(yyval.opt_base_window_name_t) = new OptBaseWindowName(); (yyval.opt_base_window_name_t)->sub_type_ = CASE1;}
#line 5766 "bison_parser.cpp"
    break;

  case 248: /* opt_frame: range_or_rows frame_bound_s opt_frame_exclude  */
#line 1850 "bison_parser.y"
                                                      {
            (yyval.opt_frame_t) = new OptFrame(); 
            (yyval.opt_frame_t)->sub_type_ = CASE0; 
            (yyval.opt_frame_t)->range_or_rows_ = (yyvsp[-2].range_or_rows_t);
            (yyval.opt_frame_t)->frame_bound_s_ = (yyvsp[-1].frame_bound_s_t);
            (yyval.opt_frame_t)->opt_frame_exclude_ = (yyvsp[0].opt_frame_exclude_t);
        }
#line 5778 "bison_parser.cpp"
    break;

  case 249: /* opt_frame: range_or_rows BETWEEN frame_bound_s AND frame_bound_e opt_frame_exclude  */
#line 1857 "bison_parser.y"
                                                                                {
            (yyval.opt_frame_t) = new OptFrame();
            (yyval.opt_frame_t)->sub_type_ = CASE1;
            (yyval.opt_frame_t)->range_or_rows_ = (yyvsp[-5].range_or_rows_t);
            (yyval.opt_frame_t)->frame_bound_s_ = (yyvsp[-3].frame_bound_s_t);
            (yyval.opt_frame_t)->frame_bound_e_ = (yyvsp[-1].frame_bound_e_t);
            (yyval.opt_frame_t)->opt_frame_exclude_ = (yyvsp[0].opt_frame_exclude_t);
        }
#line 5791 "bison_parser.cpp"
    break;

  case 250: /* opt_frame: %empty  */
#line 1865 "bison_parser.y"
                  {(yyval.opt_frame_t) = new OptFrame(); (yyval.opt_frame_t)->sub_type_ = CASE2;}
#line 5797 "bison_parser.cpp"
    break;

  case 251: /* range_or_rows: RANGE  */
#line 1869 "bison_parser.y"
              {(yyval.range_or_rows_t) = new RangeOrRows(); (yyval.range_or_rows_t)->str_val_ = string("RANGE");}
#line 5803 "bison_parser.cpp"
    break;

  case 252: /* range_or_rows: ROWS  */
#line 1870 "bison_parser.y"
             {(yyval.range_or_rows_t) = new RangeOrRows(); (yyval.range_or_rows_t)->str_val_ = string("ROWS");}
#line 5809 "bison_parser.cpp"
    break;

  case 253: /* range_or_rows: GROUPS  */
#line 1871 "bison_parser.y"
               {(yyval.range_or_rows_t) = new RangeOrRows(); (yyval.range_or_rows_t)->str_val_ = string("GROUPS");}
#line 5815 "bison_parser.cpp"
    break;

  case 254: /* frame_bound_s: frame_bound  */
#line 1875 "bison_parser.y"
                    {(yyval.frame_bound_s_t) = new FrameBoundS(); (yyval.frame_bound_s_t)->sub_type_ = CASE0; (yyval.frame_bound_s_t)->frame_bound_ = (yyvsp[0].frame_bound_t);}
#line 5821 "bison_parser.cpp"
    break;

  case 255: /* frame_bound_s: UNBOUNDED PRECEDING  */
#line 1876 "bison_parser.y"
                            {(yyval.frame_bound_s_t) = new FrameBoundS(); (yyval.frame_bound_s_t)->sub_type_ = CASE1;}
#line 5827 "bison_parser.cpp"
    break;

  case 256: /* frame_bound_e: frame_bound  */
#line 1880 "bison_parser.y"
                    {(yyval.frame_bound_e_t) = new FrameBoundE(); (yyval.frame_bound_e_t)->sub_type_ = CASE0; (yyval.frame_bound_e_t)->frame_bound_ = (yyvsp[0].frame_bound_t);}
#line 5833 "bison_parser.cpp"
    break;

  case 257: /* frame_bound_e: UNBOUNDED FOLLOWING  */
#line 1881 "bison_parser.y"
                            {(yyval.frame_bound_e_t) = new FrameBoundE(); (yyval.frame_bound_e_t)->sub_type_ = CASE1;}
#line 5839 "bison_parser.cpp"
    break;

  case 258: /* frame_bound: expr PRECEDING  */
#line 1885 "bison_parser.y"
                       {(yyval.frame_bound_t) = new FrameBound(); (yyval.frame_bound_t)->sub_type_ = CASE0; (yyval.frame_bound_t)->expr_ = (yyvsp[-1].expr_t);}
#line 5845 "bison_parser.cpp"
    break;

  case 259: /* frame_bound: expr FOLLOWING  */
#line 1886 "bison_parser.y"
                       {(yyval.frame_bound_t) = new FrameBound(); (yyval.frame_bound_t)->sub_type_ = CASE1; (yyval.frame_bound_t)->expr_ = (yyvsp[-1].expr_t);}
#line 5851 "bison_parser.cpp"
    break;

  case 260: /* frame_bound: CURRENT ROW  */
#line 1887 "bison_parser.y"
                    {(yyval.frame_bound_t) = new FrameBound(); (yyval.frame_bound_t)->sub_type_ = CASE2;}
#line 5857 "bison_parser.cpp"
    break;

  case 261: /* opt_frame_exclude: EXCLUDE frame_exclude  */
#line 1891 "bison_parser.y"
                              {(yyval.opt_frame_exclude_t) = new OptFrameExclude(); (yyval.opt_frame_exclude_t)->sub_type_ = CASE0; (yyval.opt_frame_exclude_t)->frame_exclude_ = (yyvsp[0].frame_exclude_t);}
#line 5863 "bison_parser.cpp"
    break;

  case 262: /* opt_frame_exclude: %empty  */
#line 1892 "bison_parser.y"
                    {(yyval.opt_frame_exclude_t) = new OptFrameExclude(); (yyval.opt_frame_exclude_t)->sub_type_ = CASE1; }
#line 5869 "bison_parser.cpp"
    break;

  case 263: /* frame_exclude: NO OTHERS  */
#line 1896 "bison_parser.y"
                  {(yyval.frame_exclude_t) = new FrameExclude(); (yyval.frame_exclude_t)->str_val_ = string("NO OTHERS");}
#line 5875 "bison_parser.cpp"
    break;

  case 264: /* frame_exclude: CURRENT ROW  */
#line 1897 "bison_parser.y"
                    {(yyval.frame_exclude_t) = new FrameExclude(); (yyval.frame_exclude_t)->str_val_ = string("CURRENT ROW");}
#line 5881 "bison_parser.cpp"
    break;

  case 265: /* frame_exclude: GROUP  */
#line 1898 "bison_parser.y"
              {(yyval.frame_exclude_t) = new FrameExclude(); (yyval.frame_exclude_t)->str_val_ = string("GROUP");}
#line 5887 "bison_parser.cpp"
    break;

  case 266: /* frame_exclude: TIES  */
#line 1899 "bison_parser.y"
             {(yyval.frame_exclude_t) = new FrameExclude(); (yyval.frame_exclude_t)->str_val_ = string("TIES");}
#line 5893 "bison_parser.cpp"
    break;

  case 267: /* opt_distinct: DISTINCT  */
#line 1904 "bison_parser.y"
                 { (yyval.opt_distinct_t) = new OptDistinct();  (yyval.opt_distinct_t)->str_val_ = string("DISTINCT");}
#line 5899 "bison_parser.cpp"
    break;

  case 268: /* opt_distinct: %empty  */
#line 1905 "bison_parser.y"
                    { (yyval.opt_distinct_t) = new OptDistinct();  (yyval.opt_distinct_t)->str_val_ = string("");}
#line 5905 "bison_parser.cpp"
    break;

  case 269: /* select_list: expr_list  */
#line 1909 "bison_parser.y"
                  {
            (yyval.select_list_t) = new SelectList();
            (yyval.select_list_t)->expr_list_ = (yyvsp[0].expr_list_t);
        }
#line 5914 "bison_parser.cpp"
    break;

  case 270: /* opt_from_clause: from_clause  */
#line 1916 "bison_parser.y"
                     { (yyval.opt_from_clause_t) = new OptFromClause(); (yyval.opt_from_clause_t)->sub_type_ = CASE0; (yyval.opt_from_clause_t)->from_clause_ = (yyvsp[0].from_clause_t);}
#line 5920 "bison_parser.cpp"
    break;

  case 271: /* opt_from_clause: %empty  */
#line 1917 "bison_parser.y"
                     { (yyval.opt_from_clause_t) = new OptFromClause(); (yyval.opt_from_clause_t)->sub_type_ = CASE1;}
#line 5926 "bison_parser.cpp"
    break;

  case 272: /* from_clause: FROM table_ref  */
#line 1921 "bison_parser.y"
                       { (yyval.from_clause_t) = new FromClause(); (yyval.from_clause_t)->table_ref_ = (yyvsp[0].table_ref_t);}
#line 5932 "bison_parser.cpp"
    break;

  case 273: /* opt_where: WHERE expr  */
#line 1926 "bison_parser.y"
                   { (yyval.opt_where_t) = new OptWhere(); (yyval.opt_where_t)->sub_type_ = CASE0; (yyval.opt_where_t)->expr_ = (yyvsp[0].expr_t); }
#line 5938 "bison_parser.cpp"
    break;

  case 274: /* opt_where: %empty  */
#line 1927 "bison_parser.y"
                    { (yyval.opt_where_t) = new OptWhere(); (yyval.opt_where_t)->sub_type_ = CASE1;}
#line 5944 "bison_parser.cpp"
    break;

  case 275: /* opt_group: GROUP BY expr_list opt_having  */
#line 1931 "bison_parser.y"
                                      {
            (yyval.opt_group_t) = new OptGroup();
            (yyval.opt_group_t)->sub_type_ = CASE0;
            (yyval.opt_group_t)->expr_list_ = (yyvsp[-1].expr_list_t);
            (yyval.opt_group_t)->opt_having_ = (yyvsp[0].opt_having_t);
        }
#line 5955 "bison_parser.cpp"
    break;

  case 276: /* opt_group: %empty  */
#line 1937 "bison_parser.y"
                    { (yyval.opt_group_t) = new OptGroup(); (yyval.opt_group_t)->sub_type_ = CASE1;}
#line 5961 "bison_parser.cpp"
    break;

  case 277: /* opt_having: HAVING expr  */
#line 1941 "bison_parser.y"
                    { (yyval.opt_having_t) = new OptHaving(); (yyval.opt_having_t)->sub_type_ = CASE0; (yyval.opt_having_t)->expr_ = (yyvsp[0].expr_t); }
#line 5967 "bison_parser.cpp"
    break;

  case 278: /* opt_having: %empty  */
#line 1942 "bison_parser.y"
                    { (yyval.opt_having_t) = new OptHaving(); (yyval.opt_having_t)->sub_type_ = CASE1;}
#line 5973 "bison_parser.cpp"
    break;

  case 279: /* opt_order: ORDER BY order_list  */
#line 1945 "bison_parser.y"
                            { (yyval.opt_order_t) = new OptOrder(); (yyval.opt_order_t)->sub_type_ = CASE0; (yyval.opt_order_t)->order_list_ = (yyvsp[0].order_list_t); }
#line 5979 "bison_parser.cpp"
    break;

  case 280: /* opt_order: %empty  */
#line 1946 "bison_parser.y"
                    {  (yyval.opt_order_t) = new OptOrder(); (yyval.opt_order_t)->sub_type_ = CASE1;}
#line 5985 "bison_parser.cpp"
    break;

  case 281: /* order_list: order_desc  */
#line 1950 "bison_parser.y"
                   { (yyval.order_list_t) = new OrderList(); (yyval.order_list_t)->v_order_desc_.push_back((yyvsp[0].order_desc_t)); }
#line 5991 "bison_parser.cpp"
    break;

  case 282: /* order_list: order_list ',' order_desc  */
#line 1951 "bison_parser.y"
                                  { (yyvsp[-2].order_list_t)->v_order_desc_.push_back((yyvsp[0].order_desc_t)); (yyval.order_list_t) = (yyvsp[-2].order_list_t); }
#line 5997 "bison_parser.cpp"
    break;

  case 283: /* order_desc: expr opt_order_type opt_null  */
#line 1955 "bison_parser.y"
                                    { (yyval.order_desc_t) = new OrderDesc(); (yyval.order_desc_t)->expr_ = (yyvsp[-2].expr_t); (yyval.order_desc_t)->opt_order_type_ = (yyvsp[-1].opt_order_type_t); (yyval.order_desc_t)->opt_null_ = (yyvsp[0].opt_null_t);}
#line 6003 "bison_parser.cpp"
    break;

  case 284: /* opt_order_type: ASC  */
#line 1959 "bison_parser.y"
            { (yyval.opt_order_type_t) = new OptOrderType(); (yyval.opt_order_type_t)->str_val_ = string("ASC"); }
#line 6009 "bison_parser.cpp"
    break;

  case 285: /* opt_order_type: DESC  */
#line 1960 "bison_parser.y"
             { (yyval.opt_order_type_t) = new OptOrderType(); (yyval.opt_order_type_t)->str_val_ = string("DESC"); }
#line 6015 "bison_parser.cpp"
    break;

  case 286: /* opt_order_type: %empty  */
#line 1961 "bison_parser.y"
                    { (yyval.opt_order_type_t) = new OptOrderType(); (yyval.opt_order_type_t)->str_val_ = string(""); }
#line 6021 "bison_parser.cpp"
    break;

  case 287: /* opt_top: TOP int_literal  */
#line 1966 "bison_parser.y"
                        { 
            (yyval.opt_top_t) = new OptTop(); 
            (yyval.opt_top_t)->sub_type_ = CASE0;
            (yyval.opt_top_t)->int_literal_ = (yyvsp[0].int_literal_t);
            }
#line 6031 "bison_parser.cpp"
    break;

  case 288: /* opt_top: %empty  */
#line 1971 "bison_parser.y"
                    { 
            (yyval.opt_top_t) = new OptTop(); 
            (yyval.opt_top_t)->sub_type_ = CASE1;
            }
#line 6040 "bison_parser.cpp"
    break;

  case 289: /* opt_limit: LIMIT expr  */
#line 1978 "bison_parser.y"
                   { (yyval.opt_limit_t) = new OptLimit(); (yyval.opt_limit_t)->sub_type_ = CASE0; (yyval.opt_limit_t)->expr1_ = (yyvsp[0].expr_t);}
#line 6046 "bison_parser.cpp"
    break;

  case 290: /* opt_limit: OFFSET expr  */
#line 1979 "bison_parser.y"
                    { (yyval.opt_limit_t) = new OptLimit(); (yyval.opt_limit_t)->sub_type_ = CASE1; (yyval.opt_limit_t)->expr1_ = (yyvsp[0].expr_t);}
#line 6052 "bison_parser.cpp"
    break;

  case 291: /* opt_limit: LIMIT expr OFFSET expr  */
#line 1980 "bison_parser.y"
                               { (yyval.opt_limit_t) = new OptLimit(); (yyval.opt_limit_t)->sub_type_ = CASE2; (yyval.opt_limit_t)->expr1_ = (yyvsp[-2].expr_t); (yyval.opt_limit_t)->expr2_ = (yyvsp[0].expr_t);}
#line 6058 "bison_parser.cpp"
    break;

  case 292: /* opt_limit: LIMIT ALL  */
#line 1981 "bison_parser.y"
                  { (yyval.opt_limit_t) = new OptLimit(); (yyval.opt_limit_t)->sub_type_ = CASE3;}
#line 6064 "bison_parser.cpp"
    break;

  case 293: /* opt_limit: LIMIT ALL OFFSET expr  */
#line 1982 "bison_parser.y"
                              { (yyval.opt_limit_t) = new OptLimit(); (yyval.opt_limit_t)->sub_type_ = CASE4; (yyval.opt_limit_t)->expr1_ = (yyvsp[0].expr_t);}
#line 6070 "bison_parser.cpp"
    break;

  case 294: /* opt_limit: %empty  */
#line 1983 "bison_parser.y"
                    { (yyval.opt_limit_t) = nullptr; }
#line 6076 "bison_parser.cpp"
    break;

  case 295: /* expr_list: expr_alias  */
#line 1990 "bison_parser.y"
                   { 
            (yyval.expr_list_t) = new ExprList(); 
            (yyval.expr_list_t)->v_expr_list_.push_back((yyvsp[0].expr_alias_t)); 
            }
#line 6085 "bison_parser.cpp"
    break;

  case 296: /* expr_list: expr_list ',' expr_alias  */
#line 1994 "bison_parser.y"
                                 { 
        (yyvsp[-2].expr_list_t)->v_expr_list_.push_back((yyvsp[0].expr_alias_t)); 
        (yyval.expr_list_t) = (yyvsp[-2].expr_list_t); }
#line 6093 "bison_parser.cpp"
    break;

  case 297: /* opt_literal_list: literal_list  */
#line 2000 "bison_parser.y"
                     { 
            (yyval.opt_literal_list_t) = new OptLiteralList();
            (yyval.opt_literal_list_t)->sub_type_ = CASE0;
            (yyval.opt_literal_list_t)->literal_list_ = (yyvsp[0].literal_list_t);
            }
#line 6103 "bison_parser.cpp"
    break;

  case 298: /* opt_literal_list: %empty  */
#line 2005 "bison_parser.y"
                    { 
            (yyval.opt_literal_list_t) = new OptLiteralList();
            (yyval.opt_literal_list_t)->sub_type_ = CASE1; }
#line 6111 "bison_parser.cpp"
    break;

  case 299: /* literal_list: literal  */
#line 2011 "bison_parser.y"
                { 
            (yyval.literal_list_t) = new LiteralList(); 
            (yyval.literal_list_t)->v_literal_list_.push_back((yyvsp[0].literal_t)); 
            }
#line 6120 "bison_parser.cpp"
    break;

  case 300: /* literal_list: literal_list ',' literal  */
#line 2015 "bison_parser.y"
                                 { 
        (yyvsp[-2].literal_list_t)->v_literal_list_.push_back((yyvsp[0].literal_t)); 
        (yyval.literal_list_t) = (yyvsp[-2].literal_list_t); 
        }
#line 6129 "bison_parser.cpp"
    break;

  case 301: /* expr_alias: expr opt_alias  */
#line 2022 "bison_parser.y"
                       {
            (yyval.expr_alias_t) = new ExprAlias();
            (yyval.expr_alias_t)->expr_ = (yyvsp[-1].expr_t);
            (yyval.expr_alias_t)->opt_alias_ = (yyvsp[0].opt_alias_t);
        }
#line 6139 "bison_parser.cpp"
    break;

  case 302: /* expr: operand  */
#line 2030 "bison_parser.y"
                {(yyval.expr_t) = (yyvsp[0].operand_t);}
#line 6145 "bison_parser.cpp"
    break;

  case 303: /* expr: between_expr  */
#line 2031 "bison_parser.y"
                     {(yyval.expr_t) = (yyvsp[0].between_expr_t);}
#line 6151 "bison_parser.cpp"
    break;

  case 304: /* expr: logic_expr  */
#line 2032 "bison_parser.y"
                   {(yyval.expr_t) = (yyvsp[0].logic_expr_t);}
#line 6157 "bison_parser.cpp"
    break;

  case 305: /* expr: exists_expr  */
#line 2033 "bison_parser.y"
                    {(yyval.expr_t) = (yyvsp[0].exists_expr_t);}
#line 6163 "bison_parser.cpp"
    break;

  case 306: /* expr: in_expr  */
#line 2034 "bison_parser.y"
                {(yyval.expr_t) = (yyvsp[0].in_expr_t);}
#line 6169 "bison_parser.cpp"
    break;

  case 307: /* expr: cast_expr  */
#line 2035 "bison_parser.y"
                  {(yyval.expr_t) = (yyvsp[0].cast_expr_t);}
#line 6175 "bison_parser.cpp"
    break;

  case 308: /* operand: '(' expr ')'  */
#line 2039 "bison_parser.y"
                     { (yyval.operand_t) = new Operand(); (yyval.operand_t)->sub_type_ = CASE0; (yyval.operand_t)->expr_ = (yyvsp[-1].expr_t); }
#line 6181 "bison_parser.cpp"
    break;

  case 309: /* operand: array_index  */
#line 2040 "bison_parser.y"
                    { (yyval.operand_t) = new Operand(); (yyval.operand_t)->sub_type_ = CASE1; (yyval.operand_t)->expr_ = (yyvsp[0].array_index_t); }
#line 6187 "bison_parser.cpp"
    break;

  case 310: /* operand: scalar_expr  */
#line 2041 "bison_parser.y"
                    { (yyval.operand_t) = new Operand(); (yyval.operand_t)->sub_type_ = CASE1; (yyval.operand_t)->expr_ = (yyvsp[0].scalar_expr_t); }
#line 6193 "bison_parser.cpp"
    break;

  case 311: /* operand: unary_expr  */
#line 2042 "bison_parser.y"
                    { (yyval.operand_t) = new Operand(); (yyval.operand_t)->sub_type_ = CASE1; (yyval.operand_t)->expr_ = (yyvsp[0].unary_expr_t); }
#line 6199 "bison_parser.cpp"
    break;

  case 312: /* operand: binary_expr  */
#line 2043 "bison_parser.y"
                    { (yyval.operand_t) = new Operand(); (yyval.operand_t)->sub_type_ = CASE1; (yyval.operand_t)->expr_ = (yyvsp[0].binary_expr_t); }
#line 6205 "bison_parser.cpp"
    break;

  case 313: /* operand: case_expr  */
#line 2044 "bison_parser.y"
                    { (yyval.operand_t) = new Operand(); (yyval.operand_t)->sub_type_ = CASE1; (yyval.operand_t)->expr_ = (yyvsp[0].case_expr_t); }
#line 6211 "bison_parser.cpp"
    break;

  case 314: /* operand: function_expr  */
#line 2045 "bison_parser.y"
                        { (yyval.operand_t) = new Operand(); (yyval.operand_t)->sub_type_ = CASE1; (yyval.operand_t)->expr_ = (yyvsp[0].function_expr_t); }
#line 6217 "bison_parser.cpp"
    break;

  case 315: /* operand: extract_expr  */
#line 2046 "bison_parser.y"
                        { (yyval.operand_t) = new Operand(); (yyval.operand_t)->sub_type_ = CASE1; (yyval.operand_t)->expr_ = (yyvsp[0].extract_expr_t); }
#line 6223 "bison_parser.cpp"
    break;

  case 316: /* operand: array_expr  */
#line 2047 "bison_parser.y"
                    { (yyval.operand_t) = new Operand(); (yyval.operand_t)->sub_type_ = CASE1; (yyval.operand_t)->expr_ = (yyvsp[0].array_expr_t); }
#line 6229 "bison_parser.cpp"
    break;

  case 317: /* operand: '(' select_no_paren ')'  */
#line 2048 "bison_parser.y"
                                { (yyval.operand_t) = new Operand(); (yyval.operand_t)->sub_type_ = CASE2; (yyval.operand_t)->select_no_paren_ = (yyvsp[-1].select_no_paren_t); }
#line 6235 "bison_parser.cpp"
    break;

  case 318: /* cast_expr: CAST '(' expr AS column_type ')'  */
#line 2052 "bison_parser.y"
                                             {
		    (yyval.cast_expr_t) = new CastExpr();
		    (yyval.cast_expr_t)->expr_ = (yyvsp[-3].expr_t);
            (yyval.cast_expr_t)->column_type_ = (yyvsp[-1].column_type_t);
	    }
#line 6245 "bison_parser.cpp"
    break;

  case 319: /* scalar_expr: column_name  */
#line 2060 "bison_parser.y"
                    {(yyval.scalar_expr_t) = new ScalarExpr(); (yyval.scalar_expr_t)->sub_type_=CASE0; (yyval.scalar_expr_t)->column_name_ = (yyvsp[0].column_name_t);}
#line 6251 "bison_parser.cpp"
    break;

  case 320: /* scalar_expr: literal  */
#line 2061 "bison_parser.y"
                {(yyval.scalar_expr_t) = new ScalarExpr(); (yyval.scalar_expr_t)->sub_type_=CASE1; (yyval.scalar_expr_t)->literal_ = (yyvsp[0].literal_t);}
#line 6257 "bison_parser.cpp"
    break;

  case 321: /* unary_expr: '-' operand  */
#line 2065 "bison_parser.y"
                    { 
            (yyval.unary_expr_t) =new UnaryExpr(); 
            (yyval.unary_expr_t)->sub_type_ = CASE0;
            (yyval.unary_expr_t)->operand_ = (yyvsp[0].operand_t);
            (yyval.unary_expr_t)->operator_ = string("-");
            }
#line 6268 "bison_parser.cpp"
    break;

  case 322: /* unary_expr: NOT operand  */
#line 2071 "bison_parser.y"
                    { 
        (yyval.unary_expr_t) =new UnaryExpr(); 
            (yyval.unary_expr_t)->sub_type_ = CASE1;
            (yyval.unary_expr_t)->operand_ = (yyvsp[0].operand_t);
            (yyval.unary_expr_t)->operator_ = string("NOT");
        }
#line 6279 "bison_parser.cpp"
    break;

  case 323: /* unary_expr: operand ISNULL  */
#line 2077 "bison_parser.y"
                       { 
            (yyval.unary_expr_t) =new UnaryExpr(); 
            (yyval.unary_expr_t)->sub_type_ = CASE2;
            (yyval.unary_expr_t)->operand_ = (yyvsp[-1].operand_t);
            (yyval.unary_expr_t)->operator_ = string("ISNULL");
        }
#line 6290 "bison_parser.cpp"
    break;

  case 324: /* unary_expr: operand IS NULL  */
#line 2083 "bison_parser.y"
                        { 
            (yyval.unary_expr_t) =new UnaryExpr(); 
            (yyval.unary_expr_t)->sub_type_ = CASE3;
            (yyval.unary_expr_t)->operand_ = (yyvsp[-2].operand_t);
            (yyval.unary_expr_t)->operator_ = string("IS NULL");
        }
#line 6301 "bison_parser.cpp"
    break;

  case 325: /* unary_expr: operand IS NOT NULL  */
#line 2089 "bison_parser.y"
                            { 
            (yyval.unary_expr_t) =new UnaryExpr(); 
            (yyval.unary_expr_t)->sub_type_ = CASE4;
            (yyval.unary_expr_t)->operand_ = (yyvsp[-3].operand_t);
            (yyval.unary_expr_t)->operator_ = string("IS NOT NULL");
        }
#line 6312 "bison_parser.cpp"
    break;

  case 326: /* binary_expr: comp_expr  */
#line 2098 "bison_parser.y"
                  {(yyval.binary_expr_t) = new BinaryExpr(); (yyval.binary_expr_t)->sub_type_ = CASE0; (yyval.binary_expr_t)->comp_expr_ = (yyvsp[0].comp_expr_t);}
#line 6318 "bison_parser.cpp"
    break;

  case 327: /* binary_expr: operand '-' operand  */
#line 2099 "bison_parser.y"
                                    { (yyval.binary_expr_t) = new BinaryExpr(); (yyval.binary_expr_t)->sub_type_ = CASE1; (yyval.binary_expr_t)->operand1_ = (yyvsp[-2].operand_t); (yyval.binary_expr_t)->operand2_ = (yyvsp[0].operand_t); (yyval.binary_expr_t)->operator_ = string("-");}
#line 6324 "bison_parser.cpp"
    break;

  case 328: /* binary_expr: operand '+' operand  */
#line 2100 "bison_parser.y"
                                    { (yyval.binary_expr_t) = new BinaryExpr(); (yyval.binary_expr_t)->sub_type_ = CASE1; (yyval.binary_expr_t)->operand1_ = (yyvsp[-2].operand_t); (yyval.binary_expr_t)->operand2_ = (yyvsp[0].operand_t); (yyval.binary_expr_t)->operator_ = string("+");}
#line 6330 "bison_parser.cpp"
    break;

  case 329: /* binary_expr: operand '/' operand  */
#line 2101 "bison_parser.y"
                                    { (yyval.binary_expr_t) = new BinaryExpr(); (yyval.binary_expr_t)->sub_type_ = CASE1; (yyval.binary_expr_t)->operand1_ = (yyvsp[-2].operand_t); (yyval.binary_expr_t)->operand2_ = (yyvsp[0].operand_t); (yyval.binary_expr_t)->operator_ = string("/");}
#line 6336 "bison_parser.cpp"
    break;

  case 330: /* binary_expr: operand '*' operand  */
#line 2102 "bison_parser.y"
                                    { (yyval.binary_expr_t) = new BinaryExpr(); (yyval.binary_expr_t)->sub_type_ = CASE1; (yyval.binary_expr_t)->operand1_ = (yyvsp[-2].operand_t); (yyval.binary_expr_t)->operand2_ = (yyvsp[0].operand_t); (yyval.binary_expr_t)->operator_ = string("*");}
#line 6342 "bison_parser.cpp"
    break;

  case 331: /* binary_expr: operand '%' operand  */
#line 2103 "bison_parser.y"
                                    { (yyval.binary_expr_t) = new BinaryExpr(); (yyval.binary_expr_t)->sub_type_ = CASE1; (yyval.binary_expr_t)->operand1_ = (yyvsp[-2].operand_t); (yyval.binary_expr_t)->operand2_ = (yyvsp[0].operand_t); (yyval.binary_expr_t)->operator_ = string("%");}
#line 6348 "bison_parser.cpp"
    break;

  case 332: /* binary_expr: operand '^' operand  */
#line 2104 "bison_parser.y"
                                    { (yyval.binary_expr_t) = new BinaryExpr(); (yyval.binary_expr_t)->sub_type_ = CASE1; (yyval.binary_expr_t)->operand1_ = (yyvsp[-2].operand_t); (yyval.binary_expr_t)->operand2_ = (yyvsp[0].operand_t); (yyval.binary_expr_t)->operator_ = string("^");}
#line 6354 "bison_parser.cpp"
    break;

  case 333: /* binary_expr: operand LIKE operand  */
#line 2105 "bison_parser.y"
                                    { (yyval.binary_expr_t) = new BinaryExpr(); (yyval.binary_expr_t)->sub_type_ = CASE1; (yyval.binary_expr_t)->operand1_ = (yyvsp[-2].operand_t); (yyval.binary_expr_t)->operand2_ = (yyvsp[0].operand_t); (yyval.binary_expr_t)->operator_ = string("LIKE");}
#line 6360 "bison_parser.cpp"
    break;

  case 334: /* binary_expr: operand NOT LIKE operand  */
#line 2106 "bison_parser.y"
                                    { (yyval.binary_expr_t) = new BinaryExpr(); (yyval.binary_expr_t)->sub_type_ = CASE1; (yyval.binary_expr_t)->operand1_ = (yyvsp[-3].operand_t); (yyval.binary_expr_t)->operand2_ = (yyvsp[0].operand_t); (yyval.binary_expr_t)->operator_ = string("NOT LIKE");}
#line 6366 "bison_parser.cpp"
    break;

  case 335: /* binary_expr: operand ILIKE operand  */
#line 2107 "bison_parser.y"
                                    { (yyval.binary_expr_t) = new BinaryExpr(); (yyval.binary_expr_t)->sub_type_ = CASE1; (yyval.binary_expr_t)->operand1_ = (yyvsp[-2].operand_t); (yyval.binary_expr_t)->operand2_ = (yyvsp[0].operand_t); (yyval.binary_expr_t)->operator_ = string("ILIKE");}
#line 6372 "bison_parser.cpp"
    break;

  case 336: /* binary_expr: operand CONCAT operand  */
#line 2108 "bison_parser.y"
                                { (yyval.binary_expr_t) = new BinaryExpr(); (yyval.binary_expr_t)->sub_type_ = CASE1; (yyval.binary_expr_t)->operand1_ = (yyvsp[-2].operand_t); (yyval.binary_expr_t)->operand2_ = (yyvsp[0].operand_t); (yyval.binary_expr_t)->operator_ = string("CONCAT");}
#line 6378 "bison_parser.cpp"
    break;

  case 337: /* binary_expr: operand GLOB operand  */
#line 2109 "bison_parser.y"
                                { (yyval.binary_expr_t) = new BinaryExpr(); (yyval.binary_expr_t)->sub_type_ = CASE1; (yyval.binary_expr_t)->operand1_ = (yyvsp[-2].operand_t); (yyval.binary_expr_t)->operand2_ = (yyvsp[0].operand_t); (yyval.binary_expr_t)->operator_ = string("GLOB");}
#line 6384 "bison_parser.cpp"
    break;

  case 338: /* binary_expr: operand MATCH operand  */
#line 2110 "bison_parser.y"
                                { (yyval.binary_expr_t) = new BinaryExpr(); (yyval.binary_expr_t)->sub_type_ = CASE1; (yyval.binary_expr_t)->operand1_ = (yyvsp[-2].operand_t); (yyval.binary_expr_t)->operand2_ = (yyvsp[0].operand_t); (yyval.binary_expr_t)->operator_ = string("MATCH");}
#line 6390 "bison_parser.cpp"
    break;

  case 339: /* binary_expr: operand REGEX operand  */
#line 2111 "bison_parser.y"
                               { (yyval.binary_expr_t) = new BinaryExpr(); (yyval.binary_expr_t)->sub_type_ = CASE1; (yyval.binary_expr_t)->operand1_ = (yyvsp[-2].operand_t); (yyval.binary_expr_t)->operand2_ = (yyvsp[0].operand_t); (yyval.binary_expr_t)->operator_ = string("REGEX");}
#line 6396 "bison_parser.cpp"
    break;

  case 340: /* logic_expr: expr AND expr  */
#line 2115 "bison_parser.y"
                        { (yyval.logic_expr_t) = new LogicExpr(); (yyval.logic_expr_t)->expr1_=(yyvsp[-2].expr_t); (yyval.logic_expr_t)->expr2_=(yyvsp[0].expr_t); (yyval.logic_expr_t)->operator_=string("AND"); }
#line 6402 "bison_parser.cpp"
    break;

  case 341: /* logic_expr: expr OR expr  */
#line 2116 "bison_parser.y"
                        { (yyval.logic_expr_t) = new LogicExpr(); (yyval.logic_expr_t)->expr1_=(yyvsp[-2].expr_t); (yyval.logic_expr_t)->expr2_=(yyvsp[0].expr_t); (yyval.logic_expr_t)->operator_=string("OR"); }
#line 6408 "bison_parser.cpp"
    break;

  case 342: /* in_expr: operand IN '(' expr_list ')'  */
#line 2120 "bison_parser.y"
                                                { (yyval.in_expr_t) = new InExpr(); (yyval.in_expr_t)->sub_type_=CASE0; (yyval.in_expr_t)->operand_=(yyvsp[-4].operand_t); (yyval.in_expr_t)->expr_list_=(yyvsp[-1].expr_list_t);}
#line 6414 "bison_parser.cpp"
    break;

  case 343: /* in_expr: operand NOT IN '(' expr_list ')'  */
#line 2121 "bison_parser.y"
                                                { (yyval.in_expr_t) = new InExpr(); (yyval.in_expr_t)->sub_type_=CASE1; (yyval.in_expr_t)->operand_=(yyvsp[-5].operand_t); (yyval.in_expr_t)->expr_list_=(yyvsp[-1].expr_list_t);}
#line 6420 "bison_parser.cpp"
    break;

  case 344: /* in_expr: operand IN '(' select_no_paren ')'  */
#line 2122 "bison_parser.y"
                                                { (yyval.in_expr_t) = new InExpr(); (yyval.in_expr_t)->sub_type_=CASE2; (yyval.in_expr_t)->operand_=(yyvsp[-4].operand_t); (yyval.in_expr_t)->select_no_paren_=(yyvsp[-1].select_no_paren_t);}
#line 6426 "bison_parser.cpp"
    break;

  case 345: /* in_expr: operand NOT IN '(' select_no_paren ')'  */
#line 2123 "bison_parser.y"
                                                { (yyval.in_expr_t) = new InExpr(); (yyval.in_expr_t)->sub_type_=CASE3; (yyval.in_expr_t)->operand_=(yyvsp[-5].operand_t); (yyval.in_expr_t)->select_no_paren_=(yyvsp[-1].select_no_paren_t);}
#line 6432 "bison_parser.cpp"
    break;

  case 346: /* case_expr: CASE expr case_list END  */
#line 2129 "bison_parser.y"
                                            { (yyval.case_expr_t) = new CaseExpr(); (yyval.case_expr_t)->sub_type_=CASE0; (yyval.case_expr_t)->case_expr_=(yyvsp[-2].expr_t); (yyval.case_expr_t)->case_list_=(yyvsp[-1].case_list_t); }
#line 6438 "bison_parser.cpp"
    break;

  case 347: /* case_expr: CASE expr case_list ELSE expr END  */
#line 2130 "bison_parser.y"
                                            { (yyval.case_expr_t) = new CaseExpr(); (yyval.case_expr_t)->sub_type_=CASE1; (yyval.case_expr_t)->case_expr_=(yyvsp[-4].expr_t); (yyval.case_expr_t)->case_list_=(yyvsp[-3].case_list_t); (yyval.case_expr_t)->else_expr_=(yyvsp[-1].expr_t);}
#line 6444 "bison_parser.cpp"
    break;

  case 348: /* case_expr: CASE case_list END  */
#line 2131 "bison_parser.y"
                                            { (yyval.case_expr_t) = new CaseExpr(); (yyval.case_expr_t)->sub_type_=CASE2; (yyval.case_expr_t)->case_list_=(yyvsp[-1].case_list_t); }
#line 6450 "bison_parser.cpp"
    break;

  case 349: /* case_expr: CASE case_list ELSE expr END  */
#line 2132 "bison_parser.y"
                                            { (yyval.case_expr_t) = new CaseExpr(); (yyval.case_expr_t)->sub_type_=CASE3; (yyval.case_expr_t)->else_expr_=(yyvsp[-1].expr_t); (yyval.case_expr_t)->case_list_=(yyvsp[-3].case_list_t); }
#line 6456 "bison_parser.cpp"
    break;

  case 350: /* case_list: WHEN expr THEN expr  */
#line 2136 "bison_parser.y"
                                         { (yyval.case_list_t) = new CaseList(); (yyval.case_list_t)->v_case_list_.push_back(new CaseClause((yyvsp[-2].expr_t),(yyvsp[0].expr_t))); }
#line 6462 "bison_parser.cpp"
    break;

  case 351: /* case_list: case_list WHEN expr THEN expr  */
#line 2137 "bison_parser.y"
                                         { (yyval.case_list_t)->v_case_list_.push_back(new CaseClause((yyvsp[-2].expr_t), (yyvsp[0].expr_t))); (yyval.case_list_t) = (yyvsp[-4].case_list_t); }
#line 6468 "bison_parser.cpp"
    break;

  case 352: /* exists_expr: EXISTS '(' select_no_paren ')'  */
#line 2141 "bison_parser.y"
                                       { (yyval.exists_expr_t) = new ExistsExpr(); (yyval.exists_expr_t)->sub_type_=CASE0; (yyval.exists_expr_t)->select_no_paren_=(yyvsp[-1].select_no_paren_t);}
#line 6474 "bison_parser.cpp"
    break;

  case 353: /* exists_expr: NOT EXISTS '(' select_no_paren ')'  */
#line 2142 "bison_parser.y"
                                           { (yyval.exists_expr_t) = new ExistsExpr(); (yyval.exists_expr_t)->sub_type_=CASE1; (yyval.exists_expr_t)->select_no_paren_=(yyvsp[-1].select_no_paren_t);}
#line 6480 "bison_parser.cpp"
    break;

  case 354: /* comp_expr: operand '=' operand  */
#line 2146 "bison_parser.y"
                                    {(yyval.comp_expr_t) = new CompExpr(); (yyval.comp_expr_t)->operand1_ = (yyvsp[-2].operand_t); (yyval.comp_expr_t)->operand2_ = (yyvsp[0].operand_t); (yyval.comp_expr_t)->operator_ = string("="); }
#line 6486 "bison_parser.cpp"
    break;

  case 355: /* comp_expr: operand EQUALS operand  */
#line 2147 "bison_parser.y"
                                        { (yyval.comp_expr_t) = new CompExpr(); (yyval.comp_expr_t)->operand1_ = (yyvsp[-2].operand_t); (yyval.comp_expr_t)->operand2_ = (yyvsp[0].operand_t); (yyval.comp_expr_t)->operator_ = string("=="); }
#line 6492 "bison_parser.cpp"
    break;

  case 356: /* comp_expr: operand NOTEQUALS operand  */
#line 2148 "bison_parser.y"
                                    { (yyval.comp_expr_t) = new CompExpr(); (yyval.comp_expr_t)->operand1_ = (yyvsp[-2].operand_t); (yyval.comp_expr_t)->operand2_ = (yyvsp[0].operand_t); (yyval.comp_expr_t)->operator_ = string("!="); }
#line 6498 "bison_parser.cpp"
    break;

  case 357: /* comp_expr: operand '<' operand  */
#line 2149 "bison_parser.y"
                                    { (yyval.comp_expr_t) = new CompExpr(); (yyval.comp_expr_t)->operand1_ = (yyvsp[-2].operand_t); (yyval.comp_expr_t)->operand2_ = (yyvsp[0].operand_t); (yyval.comp_expr_t)->operator_ = string("<"); }
#line 6504 "bison_parser.cpp"
    break;

  case 358: /* comp_expr: operand '>' operand  */
#line 2150 "bison_parser.y"
                                    { (yyval.comp_expr_t) = new CompExpr(); (yyval.comp_expr_t)->operand1_ = (yyvsp[-2].operand_t); (yyval.comp_expr_t)->operand2_ = (yyvsp[0].operand_t); (yyval.comp_expr_t)->operator_ = string(">"); }
#line 6510 "bison_parser.cpp"
    break;

  case 359: /* comp_expr: operand LESSEQ operand  */
#line 2151 "bison_parser.y"
                                    { (yyval.comp_expr_t) = new CompExpr(); (yyval.comp_expr_t)->operand1_ = (yyvsp[-2].operand_t); (yyval.comp_expr_t)->operand2_ = (yyvsp[0].operand_t); (yyval.comp_expr_t)->operator_ = string("<="); }
#line 6516 "bison_parser.cpp"
    break;

  case 360: /* comp_expr: operand GREATEREQ operand  */
#line 2152 "bison_parser.y"
                                    { (yyval.comp_expr_t) = new CompExpr(); (yyval.comp_expr_t)->operand1_ = (yyvsp[-2].operand_t); (yyval.comp_expr_t)->operand2_ = (yyvsp[0].operand_t); (yyval.comp_expr_t)->operator_ = string(">="); }
#line 6522 "bison_parser.cpp"
    break;

  case 361: /* function_expr: IDENTIFIER '(' ')' opt_filter_clause opt_over_clause  */
#line 2156 "bison_parser.y"
                                                                   { 
                   (yyval.function_expr_t) = new FunctionExpr(); 
                   (yyval.function_expr_t)->sub_type_ = CASE0; 
                   (yyval.function_expr_t)->id_ = new Identifier((yyvsp[-4].sval)); 
                   (yyval.function_expr_t)->opt_filter_clause_ = (yyvsp[-1].opt_filter_clause_t);
                   (yyval.function_expr_t)->opt_over_clause_ = (yyvsp[0].opt_over_clause_t);
                   free((yyvsp[-4].sval));
                   }
#line 6535 "bison_parser.cpp"
    break;

  case 362: /* function_expr: IDENTIFIER '(' opt_distinct expr_list ')' opt_filter_clause opt_over_clause  */
#line 2164 "bison_parser.y"
                                                                                          { 
                   (yyval.function_expr_t) = new FunctionExpr(); 
                   (yyval.function_expr_t)->sub_type_ = CASE1; 
                   (yyval.function_expr_t)->id_ = new Identifier((yyvsp[-6].sval)); 
                   (yyval.function_expr_t)->opt_distinct_ = (yyvsp[-4].opt_distinct_t);
                   (yyval.function_expr_t)->expr_list_ = (yyvsp[-3].expr_list_t);
                   (yyval.function_expr_t)->opt_filter_clause_ = (yyvsp[-1].opt_filter_clause_t);
                   (yyval.function_expr_t)->opt_over_clause_ = (yyvsp[0].opt_over_clause_t);
                   free((yyvsp[-6].sval));
                   }
#line 6550 "bison_parser.cpp"
    break;

  case 363: /* opt_over_clause: OVER '(' window ')'  */
#line 2177 "bison_parser.y"
                            {(yyval.opt_over_clause_t) = new OptOverClause(); (yyval.opt_over_clause_t)->sub_type_ = CASE0; (yyval.opt_over_clause_t)->window_ = (yyvsp[-1].window_t);}
#line 6556 "bison_parser.cpp"
    break;

  case 364: /* opt_over_clause: OVER IDENTIFIER  */
#line 2178 "bison_parser.y"
                                                {
        (yyval.opt_over_clause_t) = new OptOverClause(); 
        (yyval.opt_over_clause_t)->sub_type_ = CASE1; 
        (yyval.opt_over_clause_t)->id_ = new Identifier((yyvsp[0].sval), id_window_name);
        free((yyvsp[0].sval));
    }
#line 6567 "bison_parser.cpp"
    break;

  case 365: /* opt_over_clause: %empty  */
#line 2184 "bison_parser.y"
                  {(yyval.opt_over_clause_t) = new OptOverClause(); (yyval.opt_over_clause_t)->sub_type_ = CASE2;}
#line 6573 "bison_parser.cpp"
    break;

  case 366: /* opt_filter_clause: FILTER '(' WHERE expr ')'  */
#line 2188 "bison_parser.y"
                                  {(yyval.opt_filter_clause_t) = new OptFilterClause(); (yyval.opt_filter_clause_t)->sub_type_ = CASE0; (yyval.opt_filter_clause_t)->expr_ = (yyvsp[-1].expr_t);}
#line 6579 "bison_parser.cpp"
    break;

  case 367: /* opt_filter_clause: %empty  */
#line 2189 "bison_parser.y"
                  {(yyval.opt_filter_clause_t) = new OptFilterClause(); (yyval.opt_filter_clause_t)->sub_type_ = CASE1;}
#line 6585 "bison_parser.cpp"
    break;

  case 368: /* extract_expr: EXTRACT '(' datetime_field FROM expr ')'  */
#line 2194 "bison_parser.y"
                                                     { 
             (yyval.extract_expr_t) = new ExtractExpr();
             (yyval.extract_expr_t)->datetime_field_ = (yyvsp[-3].datetime_field_t);
             (yyval.extract_expr_t)->expr_ = (yyvsp[-1].expr_t); 
             (yyval.extract_expr_t)->sub_type_ = CASE0;
             }
#line 6596 "bison_parser.cpp"
    break;

  case 369: /* datetime_field: SECOND  */
#line 2203 "bison_parser.y"
               { (yyval.datetime_field_t) = new DatetimeField(); (yyval.datetime_field_t)->str_val_ = string("SECOND"); }
#line 6602 "bison_parser.cpp"
    break;

  case 370: /* datetime_field: MINUTE  */
#line 2204 "bison_parser.y"
               { (yyval.datetime_field_t) = new DatetimeField(); (yyval.datetime_field_t)->str_val_ = string("MINUTE"); }
#line 6608 "bison_parser.cpp"
    break;

  case 371: /* datetime_field: HOUR  */
#line 2205 "bison_parser.y"
             { (yyval.datetime_field_t) = new DatetimeField(); (yyval.datetime_field_t)->str_val_ = string("HOUR"); }
#line 6614 "bison_parser.cpp"
    break;

  case 372: /* datetime_field: DAY  */
#line 2206 "bison_parser.y"
            { (yyval.datetime_field_t) = new DatetimeField(); (yyval.datetime_field_t)->str_val_ = string("DAY"); }
#line 6620 "bison_parser.cpp"
    break;

  case 373: /* datetime_field: MONTH  */
#line 2207 "bison_parser.y"
              { (yyval.datetime_field_t) = new DatetimeField(); (yyval.datetime_field_t)->str_val_ = string("MONTH"); }
#line 6626 "bison_parser.cpp"
    break;

  case 374: /* datetime_field: YEAR  */
#line 2208 "bison_parser.y"
             { (yyval.datetime_field_t) = new DatetimeField(); (yyval.datetime_field_t)->str_val_ = string("YEAR"); }
#line 6632 "bison_parser.cpp"
    break;

  case 375: /* array_expr: ARRAY '[' expr_list ']'  */
#line 2212 "bison_parser.y"
                                { (yyval.array_expr_t) = new ArrayExpr(); (yyval.array_expr_t)->expr_list_=(yyvsp[-1].expr_list_t); }
#line 6638 "bison_parser.cpp"
    break;

  case 376: /* array_index: operand '[' int_literal ']'  */
#line 2216 "bison_parser.y"
                                    { (yyval.array_index_t) = new ArrayIndex(); (yyval.array_index_t)->operand_ = (yyvsp[-3].operand_t); (yyval.array_index_t)->int_literal_ = (yyvsp[-1].int_literal_t);}
#line 6644 "bison_parser.cpp"
    break;

  case 377: /* between_expr: operand BETWEEN operand AND operand  */
#line 2220 "bison_parser.y"
                                            { (yyval.between_expr_t) = new BetweenExpr(); (yyval.between_expr_t)->operand1_=(yyvsp[-4].operand_t); (yyval.between_expr_t)->operand2_=(yyvsp[-2].operand_t); (yyval.between_expr_t)->operand3_=(yyvsp[0].operand_t);}
#line 6650 "bison_parser.cpp"
    break;

  case 378: /* column_name: IDENTIFIER  */
#line 2224 "bison_parser.y"
                   { (yyval.column_name_t) = new ColumnName(); (yyval.column_name_t)->sub_type_=CASE0; (yyval.column_name_t)->identifier1_=new Identifier((yyvsp[0].sval), id_column_name); free((yyvsp[0].sval));}
#line 6656 "bison_parser.cpp"
    break;

  case 379: /* column_name: IDENTIFIER '.' IDENTIFIER  */
#line 2225 "bison_parser.y"
                                  { (yyval.column_name_t) = new ColumnName(); (yyval.column_name_t)->sub_type_=CASE1; (yyval.column_name_t)->identifier1_=new Identifier((yyvsp[-2].sval), id_table_name); (yyval.column_name_t)->identifier2_=new Identifier((yyvsp[0].sval), id_column_name); free((yyvsp[-2].sval)); free((yyvsp[0].sval));}
#line 6662 "bison_parser.cpp"
    break;

  case 380: /* column_name: '*'  */
#line 2226 "bison_parser.y"
            { (yyval.column_name_t) = new ColumnName(); (yyval.column_name_t)->sub_type_=CASE2; }
#line 6668 "bison_parser.cpp"
    break;

  case 381: /* column_name: IDENTIFIER '.' '*'  */
#line 2227 "bison_parser.y"
                           { (yyval.column_name_t) = new ColumnName(); (yyval.column_name_t)->sub_type_=CASE3; (yyval.column_name_t)->identifier1_=new Identifier((yyvsp[-2].sval), id_table_name); free((yyvsp[-2].sval));}
#line 6674 "bison_parser.cpp"
    break;

  case 382: /* literal: string_literal  */
#line 2231 "bison_parser.y"
                        {(yyval.literal_t)=(yyvsp[0].string_literal_t);}
#line 6680 "bison_parser.cpp"
    break;

  case 383: /* literal: bool_literal  */
#line 2232 "bison_parser.y"
                      {(yyval.literal_t)=(yyvsp[0].bool_literal_t);}
#line 6686 "bison_parser.cpp"
    break;

  case 384: /* literal: num_literal  */
#line 2233 "bison_parser.y"
                     {(yyval.literal_t)=(yyvsp[0].num_literal_t);}
#line 6692 "bison_parser.cpp"
    break;

  case 385: /* literal: null_literal  */
#line 2234 "bison_parser.y"
                      {(yyval.literal_t)=(yyvsp[0].null_literal_t);}
#line 6698 "bison_parser.cpp"
    break;

  case 386: /* literal: param_expr  */
#line 2235 "bison_parser.y"
                    {(yyval.literal_t)=(yyvsp[0].param_expr_t);}
#line 6704 "bison_parser.cpp"
    break;

  case 387: /* string_literal: STRING  */
#line 2239 "bison_parser.y"
               { (yyval.string_literal_t) = new StringLiteral(); (yyval.string_literal_t)->str_val_ = (yyvsp[0].sval); free((yyvsp[0].sval));}
#line 6710 "bison_parser.cpp"
    break;

  case 388: /* bool_literal: TRUE  */
#line 2243 "bison_parser.y"
             { (yyval.bool_literal_t) = new BoolLiteral(); (yyval.bool_literal_t)->b_val_=true; }
#line 6716 "bison_parser.cpp"
    break;

  case 389: /* bool_literal: FALSE  */
#line 2244 "bison_parser.y"
              { (yyval.bool_literal_t) = new BoolLiteral(); (yyval.bool_literal_t)->b_val_=false; }
#line 6722 "bison_parser.cpp"
    break;

  case 390: /* num_literal: FLOATVAL  */
#line 2248 "bison_parser.y"
                 { (yyval.num_literal_t) = new NumLiteral(); (yyval.num_literal_t)->sub_type_=CASE0; (yyval.num_literal_t)->f_val_ = (yyvsp[0].fval); }
#line 6728 "bison_parser.cpp"
    break;

  case 391: /* num_literal: int_literal  */
#line 2249 "bison_parser.y"
                    {(yyval.num_literal_t) = new NumLiteral(); (yyval.num_literal_t)->sub_type_=CASE1; (yyval.num_literal_t)->int_literal_ = (yyvsp[0].int_literal_t);}
#line 6734 "bison_parser.cpp"
    break;

  case 392: /* int_literal: INTVAL  */
#line 2253 "bison_parser.y"
               {(yyval.int_literal_t) = new IntLiteral(); (yyval.int_literal_t)->int_val_=(yyvsp[0].ival); }
#line 6740 "bison_parser.cpp"
    break;

  case 393: /* null_literal: NULL  */
#line 2257 "bison_parser.y"
                 { (yyval.null_literal_t) = new NullLiteral(); }
#line 6746 "bison_parser.cpp"
    break;

  case 394: /* param_expr: '?'  */
#line 2261 "bison_parser.y"
            {
            (yyval.param_expr_t) = new ParamExpr();
        }
#line 6754 "bison_parser.cpp"
    break;

  case 395: /* table_ref: table_prefix table_name opt_alias opt_index opt_on opt_using  */
#line 2273 "bison_parser.y"
                                                                    {
            (yyval.table_ref_t) = new TableRef();
            (yyval.table_ref_t)->sub_type_ = CASE0;
            (yyval.table_ref_t)->table_prefix_ = (yyvsp[-5].table_prefix_t);
            (yyval.table_ref_t)->table_name_ = (yyvsp[-4].table_name_t);
            (yyval.table_ref_t)->opt_alias_ = (yyvsp[-3].opt_alias_t);
            (yyval.table_ref_t)->opt_index_ = (yyvsp[-2].opt_index_t);
            (yyval.table_ref_t)->opt_on_ = (yyvsp[-1].opt_on_t);
            (yyval.table_ref_t)->opt_using_ = (yyvsp[0].opt_using_t);
            (yyval.table_ref_t)->table_name_->table_name_->id_type_ = id_top_table_name;
        }
#line 6770 "bison_parser.cpp"
    break;

  case 396: /* table_ref: table_prefix table_name '(' expr_list ')' opt_alias opt_on opt_using  */
#line 2284 "bison_parser.y"
                                                                            {
            (yyval.table_ref_t) = new TableRef();
            (yyval.table_ref_t)->sub_type_ = CASE1;
            (yyval.table_ref_t)->table_prefix_ = (yyvsp[-7].table_prefix_t);
            (yyval.table_ref_t)->table_name_ = (yyvsp[-6].table_name_t);
            (yyval.table_ref_t)->expr_list_ = (yyvsp[-4].expr_list_t);
            (yyval.table_ref_t)->opt_alias_  = (yyvsp[-2].opt_alias_t);
            (yyval.table_ref_t)->opt_on_ = (yyvsp[-1].opt_on_t);
            (yyval.table_ref_t)->opt_using_ = (yyvsp[0].opt_using_t);
            (yyval.table_ref_t)->table_name_->table_name_->id_type_ = id_top_table_name;
    }
#line 6786 "bison_parser.cpp"
    break;

  case 397: /* table_ref: table_prefix '(' select_no_paren ')' opt_alias opt_on opt_using  */
#line 2295 "bison_parser.y"
                                                                        {
            (yyval.table_ref_t) = new TableRef();
            (yyval.table_ref_t)->sub_type_ = CASE2;
            (yyval.table_ref_t)->table_prefix_ = (yyvsp[-6].table_prefix_t);
            (yyval.table_ref_t)->select_no_paren_ = (yyvsp[-4].select_no_paren_t);
            (yyval.table_ref_t)->opt_alias_ = (yyvsp[-2].opt_alias_t);
            (yyval.table_ref_t)->opt_on_ = (yyvsp[-1].opt_on_t);
            (yyval.table_ref_t)->opt_using_ = (yyvsp[0].opt_using_t);
    }
#line 6800 "bison_parser.cpp"
    break;

  case 398: /* table_ref: table_prefix '(' table_ref ')' opt_alias opt_on opt_using  */
#line 2304 "bison_parser.y"
                                                                 {
            (yyval.table_ref_t) = new TableRef();
            (yyval.table_ref_t)->sub_type_ = CASE3;
            (yyval.table_ref_t)->table_prefix_ = (yyvsp[-6].table_prefix_t);
            (yyval.table_ref_t)->table_ref_ = (yyvsp[-4].table_ref_t);
            (yyval.table_ref_t)->opt_alias_ = (yyvsp[-2].opt_alias_t);
            (yyval.table_ref_t)->opt_on_ = (yyvsp[-1].opt_on_t);
            (yyval.table_ref_t)->opt_using_ = (yyvsp[0].opt_using_t);
    }
#line 6814 "bison_parser.cpp"
    break;

  case 399: /* table_prefix: table_ref join_op  */
#line 2316 "bison_parser.y"
                         {
            (yyval.table_prefix_t) = new TablePrefix();
            (yyval.table_prefix_t)->sub_type_ = CASE0;
            (yyval.table_prefix_t)->table_ref_ = (yyvsp[-1].table_ref_t);
            (yyval.table_prefix_t)->join_op_ = (yyvsp[0].join_op_t);
        }
#line 6825 "bison_parser.cpp"
    break;

  case 400: /* table_prefix: %empty  */
#line 2322 "bison_parser.y"
                  {
            (yyval.table_prefix_t) = new TablePrefix();
            (yyval.table_prefix_t)->sub_type_ = CASE1;
        }
#line 6834 "bison_parser.cpp"
    break;

  case 401: /* join_op: ','  */
#line 2328 "bison_parser.y"
            {(yyval.join_op_t) = new JoinOp(); (yyval.join_op_t)->sub_type_ = CASE0; }
#line 6840 "bison_parser.cpp"
    break;

  case 402: /* join_op: JOIN  */
#line 2329 "bison_parser.y"
             {(yyval.join_op_t) = new JoinOp(); (yyval.join_op_t)->sub_type_ = CASE1; }
#line 6846 "bison_parser.cpp"
    break;

  case 403: /* join_op: join_kw JOIN  */
#line 2330 "bison_parser.y"
                     {(yyval.join_op_t) = new JoinOp(); (yyval.join_op_t)->sub_type_ = CASE2; (yyval.join_op_t)->join_kw_ = (yyvsp[-1].join_kw_t);}
#line 6852 "bison_parser.cpp"
    break;

  case 404: /* join_op: join_kw IDENTIFIER JOIN  */
#line 2331 "bison_parser.y"
                                {
            (yyval.join_op_t) = new JoinOp(); 
            (yyval.join_op_t)->sub_type_ = CASE3; 
            (yyval.join_op_t)->id1_ = new Identifier((yyvsp[-1].sval), id_top_table_name); 
            (yyval.join_op_t)->join_kw_ = (yyvsp[-2].join_kw_t); 
            free((yyvsp[-1].sval));}
#line 6863 "bison_parser.cpp"
    break;

  case 405: /* join_op: join_kw IDENTIFIER IDENTIFIER JOIN  */
#line 2337 "bison_parser.y"
                                           {
            (yyval.join_op_t) = new JoinOp(); 
            (yyval.join_op_t)->sub_type_ = CASE4; 
            (yyval.join_op_t)->id1_ = new Identifier((yyvsp[-2].sval));
            (yyval.join_op_t)->id2_ = new Identifier((yyvsp[-1].sval));
            (yyval.join_op_t)->join_kw_ = (yyvsp[-3].join_kw_t);
            free((yyvsp[-2].sval));
            free((yyvsp[-1].sval));
        }
#line 6877 "bison_parser.cpp"
    break;

  case 406: /* opt_index: INDEXED BY column_name  */
#line 2349 "bison_parser.y"
                               {(yyval.opt_index_t) = new OptIndex(); (yyval.opt_index_t)->sub_type_ = CASE0; (yyval.opt_index_t)->column_name_ = (yyvsp[0].column_name_t); }
#line 6883 "bison_parser.cpp"
    break;

  case 407: /* opt_index: NOT INDEXED  */
#line 2350 "bison_parser.y"
                    {(yyval.opt_index_t) = new OptIndex(); (yyval.opt_index_t)->sub_type_ = CASE1; }
#line 6889 "bison_parser.cpp"
    break;

  case 408: /* opt_index: %empty  */
#line 2351 "bison_parser.y"
                  {(yyval.opt_index_t) = new OptIndex(); (yyval.opt_index_t)->sub_type_ = CASE2; }
#line 6895 "bison_parser.cpp"
    break;

  case 409: /* opt_on: ON expr  */
#line 2355 "bison_parser.y"
               {(yyval.opt_on_t) = new OptOn(); (yyval.opt_on_t)->sub_type_ = CASE0; (yyval.opt_on_t)->expr_ = (yyvsp[0].expr_t); }
#line 6901 "bison_parser.cpp"
    break;

  case 410: /* opt_on: %empty  */
#line 2356 "bison_parser.y"
                  {(yyval.opt_on_t) = new OptOn(); (yyval.opt_on_t)->sub_type_ = CASE1; }
#line 6907 "bison_parser.cpp"
    break;

  case 411: /* opt_using: USING '(' ident_commalist ')'  */
#line 2360 "bison_parser.y"
                                      {(yyval.opt_using_t) = new OptUsing(); (yyval.opt_using_t)->sub_type_ = CASE0; (yyval.opt_using_t)->ident_commalist_ = (yyvsp[-1].ident_commalist_t); }
#line 6913 "bison_parser.cpp"
    break;

  case 412: /* opt_using: %empty  */
#line 2361 "bison_parser.y"
                  {(yyval.opt_using_t) = new OptUsing(); (yyval.opt_using_t)->sub_type_ = CASE1; }
#line 6919 "bison_parser.cpp"
    break;

  case 413: /* table_ref_name_no_alias: table_name  */
#line 2366 "bison_parser.y"
                   {
            (yyval.table_ref_name_no_alias_t) = new TableRefNameNoAlias();
            (yyval.table_ref_name_no_alias_t)->table_name_ = (yyvsp[0].table_name_t);
            (yyval.table_ref_name_no_alias_t)->table_name_->table_name_->id_type_ = id_top_table_name;
        }
#line 6929 "bison_parser.cpp"
    break;

  case 414: /* table_name: IDENTIFIER  */
#line 2373 "bison_parser.y"
                                  { (yyval.table_name_t) = new TableName(); (yyval.table_name_t)->sub_type_ = CASE0; (yyval.table_name_t)->table_name_ = new Identifier((yyvsp[0].sval), id_table_name); (yyval.table_name_t)->database_name_ = NULL; free((yyvsp[0].sval));}
#line 6935 "bison_parser.cpp"
    break;

  case 415: /* table_name: IDENTIFIER '.' IDENTIFIER  */
#line 2374 "bison_parser.y"
                                  { 
			(yyval.table_name_t) = new TableName(); 
			(yyval.table_name_t)->sub_type_ = CASE1; 
			(yyval.table_name_t)->database_name_ = new Identifier((yyvsp[-2].sval),id_database_name); 
			(yyval.table_name_t)->table_name_ = new Identifier((yyvsp[0].sval), id_table_name);
            free((yyvsp[-2].sval));
            free((yyvsp[0].sval));
		}
#line 6948 "bison_parser.cpp"
    break;

  case 416: /* alias: AS IDENTIFIER  */
#line 2385 "bison_parser.y"
                      { (yyval.alias_t) = new Alias(); (yyval.alias_t)->sub_type_ = CASE0; (yyval.alias_t)->id_ = new Identifier((yyvsp[0].sval)); free((yyvsp[0].sval)); }
#line 6954 "bison_parser.cpp"
    break;

  case 417: /* opt_alias: alias  */
#line 2390 "bison_parser.y"
              { (yyval.opt_alias_t) = new OptAlias(); (yyval.opt_alias_t)->sub_type_ = CASE0; (yyval.opt_alias_t)->alias_=(yyvsp[0].alias_t);}
#line 6960 "bison_parser.cpp"
    break;

  case 418: /* opt_alias: %empty  */
#line 2391 "bison_parser.y"
                    { (yyval.opt_alias_t) = new OptAlias(); (yyval.opt_alias_t)->sub_type_ = CASE1; }
#line 6966 "bison_parser.cpp"
    break;

  case 419: /* opt_with_clause: with_clause  */
#line 2399 "bison_parser.y"
                    { (yyval.opt_with_clause_t) = new OptWithClause(); (yyval.opt_with_clause_t)->sub_type_ = CASE0; (yyval.opt_with_clause_t)->with_clause_=(yyvsp[0].with_clause_t);}
#line 6972 "bison_parser.cpp"
    break;

  case 420: /* opt_with_clause: %empty  */
#line 2400 "bison_parser.y"
                    { (yyval.opt_with_clause_t) = new OptWithClause(); (yyval.opt_with_clause_t)->sub_type_ = CASE1; }
#line 6978 "bison_parser.cpp"
    break;

  case 421: /* with_clause: WITH with_description_list  */
#line 2404 "bison_parser.y"
                                   { (yyval.with_clause_t) = new WithClause(); (yyval.with_clause_t)->with_description_list_ = (yyvsp[0].with_description_list_t); }
#line 6984 "bison_parser.cpp"
    break;

  case 422: /* with_description_list: with_description  */
#line 2408 "bison_parser.y"
                         {
            (yyval.with_description_list_t) = new WithDescriptionList();
            (yyval.with_description_list_t)->v_with_description_list_.push_back((yyvsp[0].with_description_t));
        }
#line 6993 "bison_parser.cpp"
    break;

  case 423: /* with_description_list: with_description_list ',' with_description  */
#line 2412 "bison_parser.y"
                                                   {
            (yyvsp[-2].with_description_list_t)->v_with_description_list_.push_back((yyvsp[0].with_description_t));
            (yyval.with_description_list_t) = (yyvsp[-2].with_description_list_t);
        }
#line 7002 "bison_parser.cpp"
    break;

  case 424: /* with_description: IDENTIFIER AS select_with_paren  */
#line 2419 "bison_parser.y"
                                        {
            (yyval.with_description_t) = new WithDescription();
            (yyval.with_description_t)->id_ = new Identifier((yyvsp[-2].sval));
            (yyval.with_description_t)->select_with_paren_ = (yyvsp[0].select_with_paren_t);
            free((yyvsp[-2].sval));
        }
#line 7013 "bison_parser.cpp"
    break;

  case 425: /* join_kw: INNER  */
#line 2433 "bison_parser.y"
                    { (yyval.join_kw_t) = new JoinKw(); (yyval.join_kw_t)->str_val_ = string("INNER"); }
#line 7019 "bison_parser.cpp"
    break;

  case 426: /* join_kw: LEFT OUTER  */
#line 2434 "bison_parser.y"
                    { (yyval.join_kw_t) = new JoinKw(); (yyval.join_kw_t)->str_val_ = string("LEFT OUTER"); }
#line 7025 "bison_parser.cpp"
    break;

  case 427: /* join_kw: LEFT  */
#line 2435 "bison_parser.y"
                    { (yyval.join_kw_t) = new JoinKw(); (yyval.join_kw_t)->str_val_ = string("LEFT"); }
#line 7031 "bison_parser.cpp"
    break;

  case 428: /* join_kw: RIGHT OUTER  */
#line 2436 "bison_parser.y"
                    { (yyval.join_kw_t) = new JoinKw(); (yyval.join_kw_t)->str_val_ = string("RIGHT OUTER"); }
#line 7037 "bison_parser.cpp"
    break;

  case 429: /* join_kw: RIGHT  */
#line 2437 "bison_parser.y"
                    { (yyval.join_kw_t) = new JoinKw(); (yyval.join_kw_t)->str_val_ = string("RIGHT"); }
#line 7043 "bison_parser.cpp"
    break;

  case 430: /* join_kw: FULL OUTER  */
#line 2438 "bison_parser.y"
                    { (yyval.join_kw_t) = new JoinKw(); (yyval.join_kw_t)->str_val_ = string("FULL OUTER"); }
#line 7049 "bison_parser.cpp"
    break;

  case 431: /* join_kw: OUTER  */
#line 2439 "bison_parser.y"
                    { (yyval.join_kw_t) = new JoinKw(); (yyval.join_kw_t)->str_val_ = string("OUTER"); }
#line 7055 "bison_parser.cpp"
    break;

  case 432: /* join_kw: FULL  */
#line 2440 "bison_parser.y"
                    { (yyval.join_kw_t) = new JoinKw(); (yyval.join_kw_t)->str_val_ = string("FULL"); }
#line 7061 "bison_parser.cpp"
    break;

  case 433: /* join_kw: CROSS  */
#line 2441 "bison_parser.y"
                    { (yyval.join_kw_t) = new JoinKw(); (yyval.join_kw_t)->str_val_ = string("CROSS"); }
#line 7067 "bison_parser.cpp"
    break;

  case 434: /* join_kw: NATURAL  */
#line 2442 "bison_parser.y"
                    {(yyval.join_kw_t) = new JoinKw(); (yyval.join_kw_t)->str_val_ = string("NATURAL");}
#line 7073 "bison_parser.cpp"
    break;

  case 435: /* opt_semicolon: ';'  */
#line 2457 "bison_parser.y"
            {(yyval.opt_semicolon_t) = new OptSemicolon(); (yyval.opt_semicolon_t)->str_val_ = string(";");}
#line 7079 "bison_parser.cpp"
    break;

  case 436: /* opt_semicolon: %empty  */
#line 2458 "bison_parser.y"
                   {(yyval.opt_semicolon_t) = new OptSemicolon(); (yyval.opt_semicolon_t)->str_val_ = string("");}
#line 7085 "bison_parser.cpp"
    break;

  case 437: /* ident_commalist: IDENTIFIER  */
#line 2463 "bison_parser.y"
                   { (yyval.ident_commalist_t) = new IdentCommaList(); (yyval.ident_commalist_t)->v_iden_comma_list_.push_back(new Identifier((yyvsp[0].sval))); free((yyvsp[0].sval));}
#line 7091 "bison_parser.cpp"
    break;

  case 438: /* ident_commalist: ident_commalist ',' IDENTIFIER  */
#line 2464 "bison_parser.y"
                                       { (yyvsp[-2].ident_commalist_t)->v_iden_comma_list_.push_back(new Identifier((yyvsp[0].sval))); (yyval.ident_commalist_t) = (yyvsp[-2].ident_commalist_t); free((yyvsp[0].sval));}
#line 7097 "bison_parser.cpp"
    break;


#line 7101 "bison_parser.cpp"

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
  yytoken = yychar == SQL_HSQL_EMPTY ? YYSYMBOL_YYEMPTY : YYTRANSLATE (yychar);
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
        yyerror (&yylloc, result, scanner, yymsgp);
        if (yysyntax_error_status == YYENOMEM)
          YYNOMEM;
      }
    }

  yyerror_range[1] = yylloc;
  if (yyerrstatus == 3)
    {
      /* If just tried and failed to reuse lookahead token after an
         error, discard it.  */

      if (yychar <= SQL_YYEOF)
        {
          /* Return failure if at end of input.  */
          if (yychar == SQL_YYEOF)
            YYABORT;
        }
      else
        {
          yydestruct ("Error: discarding",
                      yytoken, &yylval, &yylloc, result, scanner);
          yychar = SQL_HSQL_EMPTY;
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
                  YY_ACCESSING_SYMBOL (yystate), yyvsp, yylsp, result, scanner);
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
  yyerror (&yylloc, result, scanner, YY_("memory exhausted"));
  yyresult = 2;
  goto yyreturnlab;


/*----------------------------------------------------------.
| yyreturnlab -- parsing is finished, clean up and return.  |
`----------------------------------------------------------*/
yyreturnlab:
  if (yychar != SQL_HSQL_EMPTY)
    {
      /* Make sure we have latest lookahead translation.  See comments at
         user semantic actions for why this is necessary.  */
      yytoken = YYTRANSLATE (yychar);
      yydestruct ("Cleanup: discarding lookahead",
                  yytoken, &yylval, &yylloc, result, scanner);
    }
  /* Do not reclaim the symbols of the rule whose action triggered
     this YYABORT or YYACCEPT.  */
  YYPOPSTACK (yylen);
  YY_STACK_PRINT (yyss, yyssp);
  while (yyssp != yyss)
    {
      yydestruct ("Cleanup: popping",
                  YY_ACCESSING_SYMBOL (+*yyssp), yyvsp, yylsp, result, scanner);
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

#line 2467 "bison_parser.y"

/*********************************
 ** Section 4: Additional C code
 *********************************/

 /* empty */
 int yyerror(YYLTYPE* llocp, Program* result, yyscan_t scanner, const char* msg) {
    std::cerr << "[Bison Error] " << msg << std::endl;
    if (llocp) {
        std::cerr << "At line " << llocp->first_line << ", column " << llocp->first_column << std::endl;
    }
    return 1;
}
