#include "icmake.ih"

bool empty(char *line)
{
    return strspn(line, " \t") == strlen(line);
}
