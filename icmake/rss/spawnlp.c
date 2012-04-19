#include "rss.ih"

int spawnlp(int mode, const char *prog, const char *argv0, ...)
{
    va_list marker;
    register char *nextarg;
    char buf [MAX_PATH_ * 4];

    strcpy(buf, prog);

    va_start(marker, argv0);
    nextarg = va_arg(marker, char*);

    while (nextarg)
    {
        strcat(buf, " ");
        strcat(buf, nextarg);
        nextarg = va_arg(marker, char*);
    }

    return system(buf);
}

//int main ()
//{
//    spawnlp_ (0, "ls", "ls", "*.c", "*.h", NULL);
//
//    return 0;
//}


