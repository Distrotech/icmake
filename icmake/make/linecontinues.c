#include "icmake.ih"

bool line_continues(char **line, char *buf, size_t length)
{
    bool append = length && buf[length - 1] == '\\';

    if (append)
        buf[length - 1] = ' ';              /* change to ' ' */

    *line = strcat(*line, buf);
    return append;
}
