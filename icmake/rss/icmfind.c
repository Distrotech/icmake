
#include "rss.ih"

static glob_t gdata;                            /* globbing struct */
static size_t nextglob;                         /* next name in list */

static char *filename (char *fname)             /* return pointer into */
{                                               /* fname, just beyond */
    register char *cp;                         /* directory name */

    return (cp = strrchr(fname, '/')) && *(cp + 1) ? cp + 1 : fname;
}

static int make_attrib(char *fname)            /* make attribs */
{
    register int ret = 0;                      /* returned attribute */
    struct stat statbuf;                       /* stat() buffer */

    if (stat(fname, &statbuf) == -1)           /* if not stat-able .. */
        return 0xdead;                          /* dead flag return */

    if (S_ISDIR(statbuf.st_mode))               /* directory entry */
        ret |= A_SUBDIR;

    if (!(statbuf.st_mode & S_IWUSR))           /* S_IWRITE: not POSIX */
        ret |= A_RDONLY;                        /* non-writable entry */

                                               /* .file */
    if (*fname == '.' && strcmp(fname, ".") && strcmp(fname, ".."))
        ret |= A_HIDDEN;

    return ret;                                 /* return attrib */
}

/* glob() error handler returns 0: signal for glob to ignore the error */
static int globerr(char const *path, int errnr)
{
    return 0;
}
                                                /* dos_findfirst emulator */
                                                /* ignores attribute! */
size_t icm_findfirst(char const *fspec, size_t attrib, find_t_ *fileinfo)
{
    nextglob = 1;                               /* next globbed name */
                                                /* expand file spec */
    glob(fspec, GLOB_NOCHECK, globerr, &gdata);

    if (!gdata.gl_pathc)                       /* no files: -1 return */
        return (size_t)-1;

    strcpy(fileinfo->name, filename(gdata.gl_pathv[0]));
                                                /* synthetise attribute */
    return
        (fileinfo->attrib = make_attrib(gdata.gl_pathv[0])) == 0xdead ?
            (size_t)-1
        : 
            0;
}

size_t icm_findnext(find_t_ * fileinfo)
{
    if (nextglob >= gdata.gl_pathc)             /* done with list ? */
    {
        globfree(&gdata);                      /* yes.. free data */
        return (size_t)-1;
    }

    strcpy(fileinfo->name,                     /* make next name available */
           filename(gdata.gl_pathv [nextglob]));
                                                /* make attribute */
    fileinfo->attrib = make_attrib(gdata.gl_pathv[nextglob]);
    ++nextglob;                                 /* set next name index */
    return 0;
}

