/*
                            F I N D F I R S . C
*/

#include "rss.ih"

char *findfirst(char const *fspec, size_t attrib)
{
    char *cp;                               /* pointer to matched filename */

    ifs.attrib = attrib;                    /* initialize ifs */

                                            /* find all entries */
    if (findfirst(fspec, (size_t)-1, &ifs.find))
        return NULL;                        /* failed already: return NULL */

    return
        (cp = filefound()) ?                /* attrib/pattern ok: return */
            cp
        :
            findnext();                     /* or retry a match */
}

