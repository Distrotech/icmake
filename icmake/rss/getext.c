#include "rss.ih"

char const *get_ext(char const *n)
{
    split(n);
    return *gr_ext == '.' ? xstrdup(gr_ext + 1) : gr_ext;
}
