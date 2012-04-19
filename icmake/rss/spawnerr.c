/*
\funcref{spawn\_err}{void spawn\_err (\params)}
    {
        {char}{*progname}{program name}
    }
    {}
    {error()}
    {}
    {spawnerr.c}
    {

        This function can be called when an {\em exec()} or {\em spawn()} call
        indicates failure (by returning -1). Argument {\em progname} should
        indicate the program which should have been executed.

        An appropriate error message is printed and the program is halted.

    }
*/

#include "rss.ih"

void spawn_err(char const *progname)
{
    char const *msg;

    switch (errno)
    {
        case E2BIG:
            msg = "command line too big";
        break;

        case EACCES:
            msg = "access denied";
        break;

        case EMFILE:
            msg = "too many open files";
        break;

        case ENOENT:
            msg = "no such file";
        break;

        case ENOEXEC:
            msg = "exec file format";
        break;

        case ENOMEM:
            msg = "out of memory";
        break;

        default:
            msg = "unknown error";
        break;
    }

    error("Can't exec %s: %s", progname, msg);
}
