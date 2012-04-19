/*
                            C L E A N U P . C
*/


#include "icmake.ih"

void cleanup()
{
    fflush(stdout);
    fflush(stderr);

    unlink(g_temporary);

    if (g_errors)
        unlink(g_dest_name);
}
