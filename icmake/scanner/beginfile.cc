#include "scanner.ih"

void Scanner::beginFile()
{
    cout << "beginFile\n";
    redo(1);
    d_includeFile = true;
}
