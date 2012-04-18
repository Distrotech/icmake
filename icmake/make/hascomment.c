#include "icmake.ih"

bool has_comment(size_t *length, char *buf)
{
    char *cp = strchr(buf, '#');

    if (cp == NULL)
        return false;

    buf[*length = (cp - buf)] = 0;             /* remove the comment */
    return true;
}
