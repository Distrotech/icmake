#include "rss.h"

char *strlwr_ (char *s)
{
    register char
        *cp;

    for (cp = s; *cp; ++cp)
        *cp = tolower(*cp);

    return s;
}
