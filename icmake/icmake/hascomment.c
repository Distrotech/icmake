#include "icmake.ih"

int has_comment(size_t *length, char *buf)
{
    char *cp = strchr(buf, '#');

    if (cp == NULL)
        return 0;

    buf[*length = (cp - buf)] = 0;             /* remove the comment */
    return 1;
}
