/*
                                O P T I O N S . C
*/

#include "icmake.h"

int options(char **argv, int *argc)
{
    register int c;
    char *cp;
    char pid_string[30];                     /* used with -x */

    while ((c = getopt(argc, argv)) != -1)
    {
        switch (c)
        {
            case 'a':
                about();
            break;

            case 'b':
                g_flags |= f_blunt;
            break;

            case 'c':
                g_flags |= f_compiler;
            break;

            case 'C':
                if (!(g_config_name = getoptval(argc, argv)))
                    error("-C requires configuration file path");
                g_config_name = xstrdup(config_name);
            break;

            case 'i':
                g_flags |= f_icmake;        /* flag icmake taken literally  */
                if (!(source_name = getoptval(argc, argv)))
                    error("-i requires source-filename");
                return getoptindex();       /* and return the index of args */
                                            /* to icm-exec */
            case 'p':
                g_flags |= f_preprocessor;
            break;

            case 'q':
                g_flags |= f_quiet;         /* no banner */
            break;

            case 't':                       /* flag use temporary bimfile  */
                g_flags |= f_tmpbim | f_icmake; 

                if (!(cp = getoptval(argc, argv)))
                    error("-t requires temporary bim-filename");

                while (*cp == ' ')          /* skip initial blanks in optval*/
                    cp++;

                                            /* build pid-string */
                sprintf(pid_string, "%d", getpid());
                                            /* destination with pid-extension */
                g_dest_name = xstrdup(change_ext(cp, pid_string));
                                            
                strcat(pid_string, "a");    /* temp. pim-file extension */
                g_temporary = xstrdup(change_ext(cp, pid_string));

                g_source_name = argv[1];
            return getoptindex() + 1;       /* index of remaining args */
                                            /* + 1 for the extra arg on the */
                                            /* #!/...-x... line */

            case '-':
                return getoptindex();       /* return index of args to icm-exec
                                            */
        }
    }
    return *argc;                   /* return index of args to icm-exec */
}

/*
int g_flags;

void main(int argc, char **argv)
{
    options(argv, &argc);

    printf("g_flags: %x\n"
            "arguments:\n"
            ,
            g_flags);
    while (argc--)
        puts(*argv++);
}
*/
