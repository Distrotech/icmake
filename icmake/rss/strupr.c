#ifndef MSDOS

#include <ctype.h>
#include <stdio.h>
#include "rss.ih"

char *strupr_(char *s)
{
    register char
        *cp;

    for (cp = s; *cp; ++cp)
        *cp = toupper(*cp);

    return (s);
}
#endif
