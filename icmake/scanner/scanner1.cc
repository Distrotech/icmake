#include "scanner.ih"

Scanner::Scanner(istream &in, bool preProcess)
:
    ScannerBase(in, cout),
    d_includeFile(false),
    d_ppSpace(true),
    d_ppNewline(true),
    d_ignore(0),
    d_matched(matched())
{
    if (preProcess)
    {
        d_ppOut =   &Scanner::ppOut;
        d_ppBlank = &Scanner::ppBlank;
    }
    else
    {
        d_ppOut =   &Scanner::noPP;
        d_ppBlank = &Scanner::noPP;
    }

    d_ifdef.push(d_ignore);
}
