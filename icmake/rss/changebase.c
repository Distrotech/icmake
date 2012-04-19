#include "rss.ih"

char const *change_base(char const *n, char const *b)
{
    split(n);
    *gr_fname = 0;
    if (b)
        strcpy(gr_fname, b);
    join();
    return gr_name;
}
