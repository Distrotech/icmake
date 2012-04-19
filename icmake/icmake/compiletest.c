#include "icmake.ih"

int compile_test()
{
    char buffer[100];
    BIN_HEADER_ hdr;

    if ((g_flags & (f_compiler | f_preprocessor)) || !exists(g_dest_name))
        return 1;

    if (!(g_fdest = fopen(g_dest_name, "r")))
        error("Can't read %s", g_dest_name);

    if (younger(g_source_name, g_dest_name))
        return 1;

    hdr = *read_header(g_fdest, (size_t)gr_version[0]);

    fseek(g_fdest, hdr.offset[2], SEEK_SET);  /* go to filenames area */

    while (fgets(buffer, 100, g_fdest))       /* read the next filename */
    {
        buffer[strlen(buffer) - 1] = 0;     /* remove \n */
        if (younger(buffer, g_dest_name))   /* source name is younger */
            return 1;                       /* recompilation needed */
    }

    return 0;                                /* binary file up to date */
}
