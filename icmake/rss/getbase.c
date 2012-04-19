#include "rss.ih"

char const *get_base(char const *n)
{
    split(n);
    return gr_fname;
}
