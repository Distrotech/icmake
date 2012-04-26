#include "scanner.ih"

void Scanner::endif()
{
    d_ifdef.pop();
    d_ignore = d_ifdef.top();

    begin(d_ignore ? StartCondition__::ignore : StartCondition__::INITIAL);
}
