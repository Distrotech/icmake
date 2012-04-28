#include "scanner.ih"

void Scanner::ifdef()
{
    if (d_ignore)
        ++d_ignore;
    else
        d_ignore = d_defined.find(ppID()) == d_defined.end();

//    cout << "ifdef: ignore = " << d_ignore << '\n';

    d_ifdef.push(d_ignore);
    begin(d_ignore ? StartCondition__::ignore : StartCondition__::INITIAL);
}
