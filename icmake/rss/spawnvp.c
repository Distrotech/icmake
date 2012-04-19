#include "rss.ih"

int spawnvp(int mode, const char *prog, const char **argv)
{
    char buf[MAX_PATH_ * 4];

    strcpy(buf, prog);
    ++argv;

    while (*argv)
    {
        strcat(buf, " ");
        strcat(buf, *argv);
        ++argv;
    }

    return system(buf);
}

//int main ()
//{
//    static char
//        *args [] = { "ls", "*.c", "*.h", NULL };
//
//    spawnvp_ (0, "ls", (const char **) args);
//
//    return (0);
//}

