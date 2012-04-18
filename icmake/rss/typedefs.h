#ifndef INCLUDED_TYPEDEFS_H_
#define INCLUDED_TYPEDEFS_H_

    /* MAXCMDLEN:  the max command line length */
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

#endif
