/*                              C H E S C . C

*/

#include "rss.ih"

int chesc(char *string, int *n)
{
    register int c;

    if (!(c = *string++))
    {
        *n = 0;
        return 0;                           /* return 0 at end of string */
    }

    if (c != '\\')                          /* No escape char ? */
    {
        *n = 1;
        return c;                           /* Return the character */
    }

    *n = 2;                                 /* 1 (escape) char processed */
                                            /* count 1 extra char to follow */

    switch (c = *string++)                  /* fetch next char */
    {
        case 'n':
        return ('\n');                  /* newline */

        case 't':
        return ('\t');                  /* (etc.) */

        case 'v':
        return ('\v');

        case 'b':
        return ('\b');

        case 'r':
        return ('\r');

        case 'f':
        return ('\f');

        case 'a':
        return ('\a');

        case '\'':
        return ('\'');

        case '"':
        return ('"');

        case '\\':
        return ('\\');

        default:
            (*n)--;                         /* extra char not yet done */
        return atox(string - 1, n);
    }
}
