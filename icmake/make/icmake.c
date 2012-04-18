/*
                         I C M A K E . C
*/

#include "icmake.ih"


int main(int argc, char **argv)         /* icmake source(txt) dest(bin) */
{
    register int  argc2;
    register int  ret;
    char *prog;

    argc2 = options(argv, &argc);           /* process options */
                                            /* argc2 is index of args to
                                               icm-exec
                                            */

    if (!(g_flags & f_quiet))
        copyright("Make Utility", version, release);

    prog = program_name(argv[0]);

    if (!(g_flags & f_icmake) && argc2 == 1)/* argv[1]: already for icm-exec */
        usage(program_name(argv[0]));


    set_variables(argc2, argv);


    if
    (
        !(flags & f_blunt)                  /* no forced execution */
        &&
        compile_test()                      /* compilation needed */
    )
    {
                                            /* preprocessor filename */
        if (!(flags & f_tmpbim))            /* use .pim unless -t given */
            temporary = xstrdup(change_ext(source_name, pim));

        signal(SIGINT, abnormal_exit);      /* abnormal exits process */
                                            /* do the preprocessing */
        ret = _spawnlp(P_WAIT, icm_pp, icm_pp, source_name, temporary, NULL);
        if (ret)
        {
            if (ret == -1)
                spawn_err(icm_pp);
            cleanup();
            return 1;
        }

        if (flags & f_preprocessor)
            return 0;

                                            /* do the compilation */
        errors = _spawnlp(P_WAIT, icm_comp, icm_comp,
                                  temporary, dest_name, NULL);
        cleanup();

        if (errors)
        {
            if (errors == -1)
                spawn_err(icm_comp);
            return 1;
        }

        if (flags & f_compiler)
            return 0;
    }

    if (flags & f_tmpbim)                       /* -t used */
    {
        argc2 -= 3;                             /* set index to start of args */
        argv[argc2 + 1] = "-t";                 /* signal temporary */
        argv[argc2 + 2] = (char *)dest_name;    /* store dest-name */
    }
    else
    {
        argc2 -= 2;                             /* set index to start of args */
        argv[argc2 + 1] = (char *)dest_name;    /* store dest-name */
    }
    argv[argc2] = icm_exec;                     /* store executor's name */

                                            /* do the making of the file */
    errors = _execvp(icm_exec, &argv[argc2]);

    spawn_err(icm_exec);                    /* shouldn't get here ... */

    cleanup();                              /* remove tempfiles etc. */
    return 1;
}
