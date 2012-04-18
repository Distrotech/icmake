/*
                                D A T A . C
*/

#include "icmake.h"

char    const cant_read[] = "Can't read %s",
char    const r[]  = "r",
char    const rb[] = "rb";

char    *temporary;
char    *source_name;
char    *dest_name;

FILE    *fdest;
FLAGS_  flags;

int     errors;

char    const *s_icm_comp = "icm-comp";
char    const *s_icm_exec = "icm-exec";
char    const *s_icm_pp   = "icm-pp";

char    const s_bim[]   = "bim";
char    const s_pim[]   = "pim";

char const *g_libDir = "/usr/lib/icmake/";




