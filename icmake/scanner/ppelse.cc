#include "scanner.ih"

void Scanner::ppElse()
{
    if (d_ignore > 1)
        return;

    d_ifdef.top() = d_ignore = not d_ignore;

    begin(d_ignore ? StartCondition__::ignore : StartCondition__::INITIAL);
}
