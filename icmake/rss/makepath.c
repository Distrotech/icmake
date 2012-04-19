/*
    makepath.c pwp 93 07 14
    modified fbb  2012/18/4

    Arguments:
        dir:    directory string, can be NULL or empty ("");
                if not-empty, may have a trailing '/' character

        fname:  basename string, can be NULL or empty ("")

        ext:    extension string, can be NULL or empty ("");
                if not empty, can have optional leading dot

    returns:    gr_name: static buffer to contain the combined name

*/

#include "rss.ih"

char *makepath(char const *dir, char const *fname, char const *ext)
{
    gr_name[0] = 0;                        /*  prepare for strcats */

    if (dir && dir[0])
    {
        strcat(gr_name, dir);

        if (dir[strlen(dir) - 1] != '/')
        {
            size_t l;

            gr_name[l = strlen(gr_name)] = '/';
            gr_name[++l] = 0;              /*  make it an asciiz   */
        }
    }

    if (fname && fname[0])
        strcat(gr_name, fname);

    if (ext && ext[0])
    {
        if (ext[0] != '.')
            strcat(gr_name, ".");

        strcat(gr_name, ext);
    }

    return gr_name;
}
