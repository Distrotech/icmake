#include "rss.ih"

char gr_name[MAX_PATH_];
char gr_dir[MAX_PATH_];
char gr_fname[MAX_PATH_];
char gr_ext[MAX_PATH_];

ICMAKE_FIND_ gr_ifs;                              /* icmake find-struct */

int gr_next_option;
char *gr_beyond_optchar;
char *gr_optval;

