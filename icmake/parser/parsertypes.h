#ifndef INCLUDED_PARSERTYPES_H_
#define INCLUDED_PARSERTYPES_H_

enum RSS                                // names of rss-functions
{
    ARG_HEAD,
    ARG_TAIL,
    ASCII_INT,                          // return int 
    ASCII_STR,                          // return str 

    CHANGE_BASE,
    CHDIR,
    CHANGE_EXT,
    CMD_HEAD,
    CMD_TAIL,
    CHANGE_PATH,

    ECHO,
    ELEMENT,
    EXEC,
    EXECUTE,                              // only used by the compiler 
    EXISTS,

    FIELDS,
    FGETS,
    FPRINTF,

    GET_BASE,
    GETCH,
    GETS,
    GET_EXT,
    GET_PATH,

    MAKELIST,

    PRINTF,
    PUTENV,

    SIZEOF,
    STAT,
    STR_EL,
    STRLWR,                               // only used by the compiler 
    STRUPR,                               // only used by the compiler 
    SYSTEM,

                    // reserved rss function opcodes for subreleases 
    STRLEN,                               // new: only for the compiler 
    STRFIND,                              // idem 
    GETPID,                               // used by several programs       

    SUBSTR,
    GETENV,

    BACKTICK,

    SPARE1_,
    SPARE2_,
    SPARE3_,
    SPARE4_,

    HLT = SYSTEM    + 10                   // dummy marker for non-existing 
};

#endif
