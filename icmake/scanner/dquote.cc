#include "scanner.ih"

void Scanner::dQuote()
{
    more();
    begin(StartCondition__::str);
}
