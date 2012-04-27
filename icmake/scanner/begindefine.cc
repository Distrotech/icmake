#include "scanner.ih"

void Scanner::beginDefine()
{
    istringstream in(d_matched);
    char c;

    if (in >> c >> d_ppIdent >> d_ppIdent >> c)
        redo(1);
    else 
        begin(StartCondition__::define);
}
