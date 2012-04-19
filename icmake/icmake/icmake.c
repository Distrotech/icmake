/*
                         I C M A K E . C
*/

#include "icmake.ih"


int main(int argc, char **argv)         /* icmake source(txt) dest(bin) */
{
    register int  argc2 = options(argv, &argc); /* process options: argc2 is 
                                                   the index of args to 
                                                   icm-exec
                                                */

    if (!(g_flags & f_quiet))
        copyright("Make Utility");

                                            /* argv[1]: for icm-exec */
    if (!(g_flags & f_icmake) && argc2 == 1)
        usage(program_name(argv[0]));

    set_variables(argc2, argv);

                        /* no forced execution, but compilation required */
    if (!(g_flags & f_blunt) && compile_test())
    {
        register int ret = merely_compile();

        if (ret != -1)
            return ret;
    }


    if (g_flags & f_tmpbim)                     /* -t used */
    {
        argc2 -= 3;                             /* set index to start of args */
        argv[argc2 + 1] = "-t";                 /* signal temporary */
        argv[argc2 + 2] = (char *)g_dest_name;  /* store dest-name */
    }
    else
    {
        argc2 -= 2;                             /* set index to start of args */
        argv[argc2 + 1] = (char *)g_dest_name;  /* store dest-name */
    }

    argv[argc2] = (char *)g_icm_exec;           /* store executor's name */
    g_errors = execvp(g_icm_exec, &argv[argc2]);   /* make the file */

    spawn_err(g_icm_exec);                  /* shouldn't get here ... */
    cleanup();                              /* remove tempfiles etc. */
    return 1;
}
