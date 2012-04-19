#include "rss.ih"

char *fgetz(char *buf, size_t maxlen, FILE *f)
{
    register size_t i;

    if (!maxlen)
        return NULL;

    for (i = 0, --maxlen; i != maxlen; ++i)
    {
        buf[i] = fgetc(f);
        if (!buf[i])
            break;
    }

    buf[i] = 0;
    return buf;
}
