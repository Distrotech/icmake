#include "scanner.ih"

void Scanner::beginDefine()
{
    istringstream in(d_matched);
    char c;

    if (not (in >> c >> d_ppIdent >> d_ppIdent >> c))
        define("");
    else
    {
        redo(1);
        if (c != '"')
            begin(StartCondition__::define);
    }
}
