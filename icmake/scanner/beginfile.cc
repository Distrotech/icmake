#include "scanner.ih"

void Scanner::beginFile()
{
    redo(1);
    d_includeFile = true;
}
