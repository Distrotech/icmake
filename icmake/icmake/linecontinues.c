#include "icmake.ih"

int line_continues(char **line, char *buf, size_t length)
{
    int append = length && buf[length - 1] == '\\';

    if (append)
        buf[length - 1] = ' ';              /* change to ' ' */

    *line = xstrcat(*line, buf);
    return append;
}
