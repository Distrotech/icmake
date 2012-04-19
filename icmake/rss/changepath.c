#include "rss.ih"

char const *change_path(char const *n, char const *p)
{
    register char *cp;

    split(n);

    if (p)
    {
        cp = strchr(p, '/');
        strcpy(gr_dir, cp ? cp + 1 : p);
    }

    join();

    return gr_name;
}
