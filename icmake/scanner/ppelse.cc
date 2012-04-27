#include "scanner.ih"

void Scanner::ppElse()
{
    cout << "ppElse ignore in: " << d_ignore << '\n';

    if (d_ignore > 1)
        return;

    d_ifdef.top() = d_ignore = not d_ignore;

    begin(d_ignore ? StartCondition__::ignore : StartCondition__::INITIAL);

    cout << "ppElse ignore out: " << d_ignore << '\n';
}
