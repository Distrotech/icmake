#include "scanner.ih"

void Scanner::define()
{
    if (d_defined.find(d_ppIdent) != d_defined.end())
        emsg << '`' << d_ppIdent << "' multiply defined" << endl;
    else
        d_defined[d_ppIdent] = d_matched;

    d_ppIdent.clear();
}
