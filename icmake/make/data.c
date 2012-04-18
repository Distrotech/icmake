/*
                                D A T A . C
*/

#include "icmake.ih"

char    const s_cant_read[] = "Can't read %s";

char   *g_temporary;
char   *g_source_name;
char   *g_dest_name;

FILE   *g_fdest;
int     g_flags;

int     g_errors;

char    const *s_icm_comp = "icm-comp";
char    const *s_icm_exec = "icm-exec";
char    const *s_icm_pp   = "icm-pp";

char    const s_bim[]   = "bim";
char    const s_pim[]   = "pim";

char const *g_libDir = "/usr/lib/icmake/";




