/*
    splitpath.c pwp 93 07 14

    Parameters:
        path:   source path to be split

    The dir, fname, ext parameters are buffers provided by the
    caller; they should be large enough; this is NOT checked

        dir:    directory part of path;
                if found, contains the leading '/'
        fname:  the base file name without extensions
        ext:    the extension, if any, including the
                leading period
*/

#include "rss.ih"

void splitpath(char const *path, char *dir, char *fname, char *ext)
{
    register char const *lastDot;
    register char const *lastSep = strrchr(path, '/');

    if (lastSep == NULL)            /* no last separator */
    {
        lastSep = path;             /* point to the begin of path */
        *dir = 0;                   /* no path */
    }
    else
    {
        size_t length = ++lastSep - path;   /* index of 1st filename char */
        memcpy(dir, path, length);
        dir[length] = 0;
    }

    lastDot = strrchr(lastSep, '.');    /* find last dot-position */

    if (lastDot == NULL)
    {
        *ext = 0;                       /* no extension */
        strcpy(fname, lastSep);         /* all is filename */
    }
    else
    {
        size_t length = lastDot - lastSep;
        strcpy(ext, lastDot);           /* copy the extension */
        memcpy(fname, lastSep, length); /* copy the filename    */
        fname[length] = 0;
    }
}


