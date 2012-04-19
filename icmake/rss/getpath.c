#include "rss.ih"

char const *get_path(char const *n)
{
    register int length;

    split(n);

    strcat(gr_name, gr_dir);
    length = strlen(gr_name);

    if (length && gr_name[length - 1] != '/')
    {
        gr_name[length] = '/';
        gr_name[length + 1] = 0;
    }

    return gr_name;
}
