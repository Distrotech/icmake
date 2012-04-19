#include "rss.ih"


char const *change_ext(char const *n, char const *e)
{
    split(n);
    *gr_ext = 0;
    if (e)
        strcpy(gr_ext, e);
    join();
    return gr_name;
}
