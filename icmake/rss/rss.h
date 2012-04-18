#ifndef INCLUDED_RSS_H_
#define INCLUDED_RSS_H_

#ifndef _GNU_SOURCE
#define _GNU_SOURCE
#endif

#include <stdio.h>
#include <unistd.h>
#include <ctype.h>
#include <signal.h>
#include <stdarg.h>
#include <stdlib.h>
#include <string.h>
#include <glob.h>
#include <sys/stat.h>
#include <sys/types.h>

#ifdef SUN
#include <memory.h>
#endif


/*
    header file for icmake run time support system.. generic functions
    are declared here

    structure of the binary file:

        version                             e.g., "1.00", without ascii-z
        offset of the string constant-area  (INT32)
        offset of the variable area         (INT32)
        offset of the filenames area        (INT32) (end of BIN_HEADER_)
        offset of first instr. to execute   (INT32)

        code                                (first byte is first instruction)
        ascii-z string constant area
        variables
        filenames                           '\n' terminated strings


    If a logical expression is compiled, it is evaluated using true- and
    false-lists to determine its result as quickly as possible. Then, if the
    expression is not returned to an if- or while- condition, the true-list
    backpatches to the current code position, where a push_1_jmp_end
    instruction is written. Then the falselist is backpatched to the current
    code position and a push_0 opcode is written.

    If a logical is expresion is returned to an if- or while-condition, the
    code of the if/while statement is placed beyond the truelist (possibly
    followed by the code of the 'else' part of an if-stmnt).

    The runtime stack contains elements of type VAR_. When a element is popped,
    the type of the value and its descriptor are therefor available. push
    instructions must make sure that type and descriptors are pushed

    Opcodes:

    op_jmp              int-displacement
    op_jmp_false        int-displacement    (implicit pop)
    op_jmp_true         int-displacement    (implicit pop)

    op_push_1_jmp_end   jumps 1 byte (beyond push_0)
    op_push_0
    op_push_imm         imm-value
    op_push_strconst    string-index
    op_push_var         var # (var is an int or a list, info in var[#].type)
    op_push_reg         push return register (set by function)

    op_pop_var          var # (var is an int or a list, info in var[#].type)

    op_umin             unary opcode, negating the stack[sp] value
    op_atoi             string -> int               (type casting)
    op_itoa             int -> string
    op_atol             string -> 1-element list

                        binary opcodes pop two operands from the stack,
                        perform operation and push result:

                        arithmetic opcodes:
    op_mul
    op_div
    op_mod
    op_add
    op_sub
                        bitwise:
    op_band
    op_bor
    op_bnot
    op_xor
    op_shl
    op_shr
                        logical opcodes, resulting value is always
                                         immediate 1 or 0
    op_eq               ==
    op_neq              !=
    op_sm               <
    op_gr               >
    op_smeq             <=
    op_greq             >=
    op_younger          younger
    op_older            older

    op_call funnr       funnr is a byte (see enum FUNNR_)
    op_asp  #args       #args is a byte (asp: add stack pointer, clean stack)
                        ( NOTE on function execute: see below )
    op_exit             terminate command list processing, return
                        stack[sp].intval to operating system
                        (auto generated as the last instruction)
    op_copy_var varnr   stackinfo of formerly popped stackelement to var varnr
    op_inc              increment int variable, varnr is INT16 argument
    op_dec              decrement int variable, varnr is INT16 argument
    op_call INT16       call function at offset
    op_frame INT8 ...   make function frame, for INT8 variables
                        For each variable a byte follows, denoting the type
                        of the local variable. The first byte refers to the
                        first local variable following the position to where
                        BP points (see the info about stackframes).
    op_ret              break frame and return
    op_pop_reg          pop into return register
    op_hlt              not generated instruction, used for internal testing.

    Type casts
    ----------
    --------------|----------------------------------
                  |          cast result
                  |----------------------------------
                  |    (int)   (string)    (list)
    --------------|----------------------------------
    cast operand: |
    --------------|
            int   |     ok      itoa        error
                  |
            string|     atoi    ok          atol
                  |
    --------------|----------------------------------



    Operand matrix:
    ---------------

            ------|----------------------------------
                  |     int     string      list
            ------|----------------------------------
                  |
            int   |     all
                  |
                  |
            string|             == != >
                  |             < <= >=
                  |             + += =
                  |             older
                  |             younger
            list  |                         == !=
                  |                         + -
                  |                         += -= =
            ------|----------------------------------


    Stackframes
    -----------

    Variable numbers less than 0x8000 refer to global variables.
    Local variables are numbered relative to the value 0xc000,
    indicating [BP]. Thus, the following addressing scheme is followed:

        --------------------------------------------------------------
                Frame:                  Variable numbers:
        --------------------------------------------------------------
                arg2                    0xc003
                arg1                    0xc002
                ra                              (0xc001, not used)
                old bp  <-bp                    (0xc000, not used)
                loc1                    0xbfff
                loc2                    0xbffe
        --------------------------------------------------------------

    The op_frame instruction needed for the previous example, assuming
    loc1 of type int, and loc2 of type string, is:

                op_frame    2, e_int, e_str     (opcode and three INT8's)

    Functions printf, fprintf
    -------------------------
    The variable number of arguments which are allowed for these functions
    are passed to the executor of icmake in the following manner:

    Starting with ICMAKE version 4.00 the mode flag is no longer interpreted.

    The modeflag is therefore ignored. A hidden argument, specifying the number
    of arguments, is pushed as a hidden parameter. So, the following statement
    results in the following code:

             printf("hello world\n")

        push string constant "hello world\n"    // the string itself
        push 1                                  // the number of arguments
        call funnr #x                           // call printf
        add sp, 2                               // clear two arguments

    Functions chdir, system, putenv
    -------------------------------

    Starting with version 4.00, the mode flag is no longer needed. The
    functions now expect only one string argument. For reasons of compatibility
    with previous versions, a first integer argument is ignored if present.

    Functions exec, execute
    -----------------------

    Starting with version 4.00, the mode flag no longer specifies delayed or
    immediate processing. The mode flag however still defines whether error
    checking should or should not occur.

    The argument handling is, apart from the required first mode flag, similar
    to that of the functions printf and fprintf.


    Generic definitions of the target operating systems.

    MAXCMDLEN:  the max command line length
*/
#define MAXCMDLEN   500

    /*
        P_CHECK value for implied function argument of system, chdir, etc
        P_NOCHECK when not checking
        P_CHECKMODE(int mode) is true when mode indicates checking
    */
#ifndef P_CHECK
#    define P_CHECK                 0
#endif
#ifndef P_NOCHECK
#    define P_NOCHECK               2
#endif
#ifndef P_CHECKMODE
#    define P_CHECKMODE(x)          (! ((x) & P_NOCHECK) )
#endif

    /* directory objects */
#define O_FILE                      1
#define O_DIR                       2
#define O_SUBDIR                    4
#define O_ALL                       8

    /* IS_ attributes */
#define IS_IFDIR                    1
#define IS_IFCHR                    2
#define IS_IFREG                    4
#define IS_IREAD                    8
#define IS_IWRITE                   16
#define IS_IEXEC                    32

    /* file attributes */
#ifndef A_NORMAL
#    define A_NORMAL                0x00
#endif

#ifndef A_RDONLY
#    define A_RDONLY                0x01
#endif

#ifndef A_HIDDEN
#    define A_HIDDEN                0x02
#endif

#ifndef A_SYSTEM
#    define A_SYSTEM                0x04
#endif

#ifndef A_VOLID
#    define A_VOLID                 0x08
#endif

#ifndef A_SUBDIR
#    define A_SUBDIR                0x10
#endif

#ifndef A_ARCH
#    define A_ARCH                  0x20
#endif

    /* UNIX specific macros */
#ifndef P_WAIT
#define P_WAIT                      0
#endif

#define MAX_PATH_               260
#define MAX_DIR_                MAX_PATH_
#define MAX_FNAME_              MAX_PATH_
#define MAX_EXT_                MAX_PATH_
#define INT32                   signed int
#define UNS32                   unsigned int
// #define READBINARY              "r"
// #define WRITEBINARY             "w"
// #define execvp_                 execvp

#define INT8  signed char
#define INT16 signed short
#define UNS16 unsigned short

/*
                    The compiler uses E_TYPE 0 to indicate
                    the void type.
*/
typedef enum
{
    /* rss + compiler: */
    e_int           = (1 << 0),             /* int-type    expression */
    e_str           = (1 << 1),             /* string-type expression */
    e_list          = (1 << 2),             /* list-type   expression */

    /* compiler only: */
    e_bool          = (1 << 3),             /* bool-type   expression */

    e_const         = (1 << 4),             /* immediate value */
    e_var           = (1 << 5),             /* variable */
    e_reg           = (1 << 6),             /* register */
    e_code          = (1 << 7),             /* code */

    e_pre_inc_dec   = (1 << 8),             /* pre-inc or pre-dec        */
    e_post_inc_dec  = (1 << 9)              /* post-inc or post-dec      */
} E_TYPE_;

typedef enum                                /* names of rss-functions */
{
    f_arg_head,
    f_arg_tail,
    f_ascii_int,                            /* return int */
    f_ascii_str,                            /* return str */

    f_c_base,
    f_chdir,
    f_c_ext,
    f_cmd_head,
    f_cmd_tail,
    f_c_path,

    f_echo,
    f_element,
    f_exec,
    f_execute,                              /* only used by the compiler */
    f_exists,

    f_fields,
    f_fgets,
    f_fprintf,

    f_g_base,
    f_getch,
    f_gets,
    f_g_ext,
    f_g_path,

    f_makelist,

    f_printf,
    f_putenv,

    f_sizeoflist,
    f_stat,
    f_str_el,
    f_strlwr,                               /* only used by the compiler */
    f_strupr,                               /* only used by the compiler */
    f_system,

                      /* reserved rss function opcodes for subreleases */
    f_strlen,                               /* NEW: only for the compiler */
    f_strfind,                              /* IDEM */
    f_getpid,                               /* used by several programs  */

    f_substr,
    f_getenv,

    f_backtick,                             /* 4 left until f_hlt */

    f_hlt = f_system + 10                   /* dummy marker for non-existing */
} FUNNR_;

typedef enum
{                       /* hexnr:     */
    op_jmp,             /*     00     */
    op_jmp_false,       /*     01     */
    op_jmp_true,        /*     02     */
    op_push_1_jmp_end,  /*     03     */
    op_push_0,          /*     04     */
    op_push_imm,        /*     05     */
    op_push_strconst,   /*     06     */
    op_push_var,        /*     07     */
    op_push_reg,        /*     08     */
    op_pop_var,         /*     09     */
    op_umin,            /*     0a     */
    op_atoi,            /*     0b     */
    op_itoa,            /*     0c     */
    op_atol,            /*     0d     */
    op_mul,             /*     0e     */
    op_div,             /*     0f     */
    op_mod,             /*     10     */
    op_add,             /*     11     */
    op_sub,             /*     12     */
    op_eq,              /*     13     */
    op_neq,             /*     14     */
    op_sm,              /*     15     */
    op_gr,              /*     16     */
    op_younger,         /*     17     */
    op_older,           /*     18     */
    op_smeq,            /*     19     */
    op_greq,            /*     1a     */
    op_call_rss,        /*     1b     */
    op_asp,             /*     1c     */
    op_exit,            /*     1d     */
    op_copy_var,        /*     1e     */
    op_inc,             /*     1f     */
    op_dec,             /*     20     */
    op_call,            /*     21     */
    op_frame,           /*     22     */
    op_ret,             /*     23     */
    op_pop_reg,         /*     24     */
    op_band,            /*     25     */
    op_bor,             /*     26     */
    op_bnot,            /*     27     */
    op_xor,             /*     28     */
    op_shl,             /*     29     */
    op_shr,             /*     2a     */
    op_hlt = op_shr + 10/*     ..     */
} OPCODE_;

typedef struct
{
    char    version[4];
    INT32   offset[4];
} BIN_HEADER_;                              /* see header structure at BOF */

typedef struct
{
    UNS16   size;
    char    **element;                      /* used as (char *) by icmcomp */
} LIST_;

typedef union
{
    char    *str;                           /* address of allocated string */
    LIST_   list;                           /* list info of a list */
} LS_UNION_;

typedef struct
{
    UNS16 count;                            /* allocation count */
    LS_UNION_ ls;
} INTER_;

typedef union
{
    INT16   intval;                     /* value of an int */
    INTER_  *i;                         /* intermediate alloc. structure */
} VAR_UNION_;

typedef struct                          /* defined variable */
{
    E_TYPE_     type;                   /* maybe stringconst, int, list */
    VAR_UNION_  vu;                     /* value of the element */
} VAR_;

struct find_t_                          /* abbreviated variant */
{
    char name[MAX_PATH_];
    unsigned attrib;                    /* returned attribute */
};

typedef struct
{
    unsigned        attrib;             /* requested attribute */
    struct find_t_  find;               /* icm_find...()'s struct  */
} ICMAKE_FIND_;


BIN_HEADER_ *readheader (FILE *, size_t);

extern ICMAKE_FIND_ ifs;                /* in: ./rss/findnext.c */


char const *makepath(char const *path, char const *file, char const *ext);

void        splitpath_(char const *, char *, char *, char *, char *);
size_t      icm_findfirst(char const *, size_t, struct find_t_ *);
size_t      icm_findnext(struct find_t_ *);

int         spawnlp_(int, char const *, char const *, ...);
int         spawnvp_(int, char const *, char const **);    
char        *strlwr_(char *);                              
char        *strupr_(char *);

char const *change_ext (char const *, char const *);
char const *change_base (char const *, char const *);
char const *change_path (char const *, char const *);

int      chesc(char *, int *);
void     copyright(char *, char *, char *); /* copyright message */
char     *filefound(void);                  /* test attrib/pattern  */
char     *findfirst(char const *, size_t);  /* first entry matching pattern */
char     *findnext(void);                   /* remaining matching entries   */
char     *fgetz (char *, size_t, FILE *);

char const *get_ext(char const *);
char const *get_base(char const *);
char const *get_path (char const *);

int      ic_getoptindex(void);          /*  ICCE getopt functions   */
int      ic_getopt(int *, char **);
char     *ic_getoptval(int *, char **);

#define  getoptindex ic_getoptindex     /*  and their mappings      */
#define  getopt      ic_getopt
#define  getoptval   ic_getoptval

char     *getstring (FILE *, INT32, size_t);

char     *hexstring (size_t, size_t);

char     *program_name(char *);         /* make programname from argv[0] */

char     *stresc(char *);

char     *try_source_im(char const *);  /* return allocated source[.im] */
char     *xstrdup(char const *);
char     *xstrcat (char *, char const *);

void     error (char *, ...);
void     spawn_err (char *);

void     *xrealloc (void *, size_t);

int      exists  (char const *);
int      older   (char const *, char const *);
int      younger (char const *, char const *);

INT16    getint16 (FILE *);

OPCODE_  getopcode (FILE *);

UNS16    getvar(FILE *, BIN_HEADER_ *, VAR_ **);

void     initvar(VAR_ *);


extern char const version[];
extern char const release[];


#endif







