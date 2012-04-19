#include "icmake.ih"

void set_variables(int argc, char **argv)
{
    set_config_paths();

    if (!(g_flags & f_icmake))          /* do not take source literally */
    {
        g_source_name = try_source_im(argv[1]);  /* determine source */

        if (!(g_flags & f_tmpbim))      /* unless it's a temp. bimfile */
            g_dest_name = argc >= 3 ? argv[2] : argv[1];
    }
    else if (!(g_flags & f_tmpbim))     /* unless it's a temp. bimfile */
        g_dest_name = g_source_name;

    if (!(g_flags & f_tmpbim))          /* adapt extension of destination */
        g_dest_name = xstrdup(change_ext(g_dest_name, "bim")); 
                                        /* if not tmp. bimfile */
}

