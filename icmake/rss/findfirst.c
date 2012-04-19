/*
                            F I N D F I R S . C
*/

#include "rss.ih"

char *findfirst(char const *fspec, size_t attrib)
{
    char *cp;                               /* pointer to matched filename */

    gr_ifs.attrib = attrib;                    /* initialize gr_ifs */

                                            /* find all entries */
    if (icm_findfirst(fspec, (size_t)-1, &gr_ifs.find))
        return NULL;                        /* failed already: return NULL */

    return
        (cp = filefound()) ?                /* attrib/pattern ok: return */
            cp
        :
            findnext();                     /* or retry a match */
}

