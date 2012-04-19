/*
                                D A T A . C
*/

#include "icmake.ih"

char const *g_config_name;
char const *g_dest_name;
char const *g_icm_comp;
char const *g_icm_exec;
char const *g_icm_pp;
char const *g_libDir        = "/usr/lib/icmake/";
char const *g_source_name;
char const *g_temporary;
char const *s_icm_comp      = "icm-comp";
char const *s_icm_exec      = "icm-exec";
char const *s_icm_pp        = "icm-pp";
char const *s_icmstart_rc   = "/etc/icmake/icmstart.rc";
char const *s_skeletons     = "/usr/lib/icmake";

FILE   *g_fdest;

int     g_flags;
int     g_errors;




