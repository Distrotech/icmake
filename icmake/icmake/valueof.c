#include "icmake.ih"

char *value_of(char const *line, char *value)
{
    char *begin = value + strspn(value, " \t"); /* begin of the value */
    
    char *end = value + strlen(value);          /* end of the value   */

    while (strchr(" \t", *--end))        /* the first non-blank fm eoln */
        ;
    ++end;

    if (begin == end)                       /* nothing left */
        return NULL;

    *end = 0;
    return xstrdup(begin);                 /* return trimmed value */
}
