/*
    makepath.c pwp 93 07 14
    modified fbb  2012/18/4

    Arguments:
        dir:    directory string, can be NULL or empty ("");
                if not-empty, may have a trailing DIRSEP character

        fname:  basename string, can be NULL or empty ("")

        ext:    extension string, can be NULL or empty ("");
                if not empty, can have optional leading dot

    returns:    path: static buffer to contain the combined name

*/

#include "rss.h"

static char dot[] = ".";

static path[MAX_PATH_];

char *makepath(char const *dir, char const *fname, char const *ext)
{
    path[0] = 0;                        /*  prepare for strcats */

    if (dir && dir[0])
    {
        strcat(path, dir);

        if (dir[strlen(dir) - 1] != DIRSEP)
        {
            size_t l;

            path[l = strlen(path)] = DIRSEP;
            path[++l] = 0;              /*  make it an asciiz   */
        }
    }

    if (fname && fname[0])
        strcat(path, fname);

    if (ext && ext[0])
    {
        if (ext[0] != dot[0])
            strcat(path, dot);

        strcat(path, ext);
    }

    return path;
}
