#include "scanner.ih"

void Scanner::comment()
{
    begin(StartCondition__::comment);
    (this->*d_ppBlank)();
}
