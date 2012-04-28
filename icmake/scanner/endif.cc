#include "scanner.ih"

void Scanner::endif()
{
    d_ifdef.pop();
    d_ignore = d_ifdef.top();

    // cout << "endif ignore out: " << d_ignore << '\n';

    begin(d_ignore ? StartCondition__::ignore : StartCondition__::INITIAL);
}
