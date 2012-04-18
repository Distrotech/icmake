#include "icmake.ih"

char *value_of(char *value)
{
    char *cp = value + strlen(value);

    while (strchr(" \t", *--cp))
        ;

    if (++cp > value)
    {
        *cp = 0;
        return xstrdup(cp);
    }

    return NULL;
}
