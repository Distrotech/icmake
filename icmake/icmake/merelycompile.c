#include "icmake.ih"

int merely_compile()
{
    register int ret;
                                        /* preprocessor filename */
    if (!(g_flags & f_tmpbim))          /* use .pim unless -t given */
        g_temporary = xstrdup(change_ext(g_source_name, "pim"));

    if (!preprocess())
        return 1;


//    signal(SIGINT, abnormal_exit);      /* abnormal exits process */
//                                        /* do the preprocessing */
//    ret = spawnlp(P_WAIT, g_icm_pp, g_icm_pp, g_source_name, 
//                          g_temporary, NULL);
//    if (ret)
//    {
//        if (ret == -1)
//            spawn_err(g_icm_pp);
//      cleanup();
//        return 1;
//    }

    if (g_flags & f_preprocessor)
        return 0;

                                        /* do the compilation */
    g_errors = spawnlp(P_WAIT, g_icm_comp, g_icm_comp,
                               g_temporary, g_dest_name, NULL);
    cleanup();

    if (g_errors)
    {
        if (g_errors == -1)
            spawn_err(g_icm_comp);
        return 1;
    }

    return g_flags & f_compiler ?  0 : -1;
}
