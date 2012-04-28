#include "scanner.ih"

void Scanner::blanks()
{
    (this->*d_ppBlank)();
}
