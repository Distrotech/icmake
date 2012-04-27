#include "scanner.ih"

void Scanner::define(string const &value)
{
    if (d_defined.find(d_ppIdent) != d_defined.end())
        emsg << '`' << d_ppIdent << "' multiply defined" << endl;
    else
        d_defined[d_ppIdent] = value;

    d_ppIdent.clear();
    begin(StartCondition__::INITIAL);

}
