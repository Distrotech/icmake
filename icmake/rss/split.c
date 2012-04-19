#include "rss.ih"

void split(char const *path)
{
    splitpath(path, gr_dir, gr_fname, gr_ext);
}
