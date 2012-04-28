#include "scanner.ih"

void Scanner::newline()
{
    (this->*d_ppOut)();
}
