#include "icmake.ih"

int empty(char *line)
{
    return strspn(line, " \t") == strlen(line);
}
