#include "icmake.ih"

size_t cut_off_nl(char *buf)
{
    size_t length = strlen(buf);

    if (length && buf[length - 1] == '\n')  /* got \n ?                 */
         buf[--length] = 0;                 /* cut it off and reduce length */

    return length;
}
    
