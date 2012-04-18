#include "icmake.h"

bool empty(char *line)
{
    return strspn(line, " \t") == strlen(line);
}
