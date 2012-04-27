#include "scanner.ih"

Scanner::Scanner(istream &in, std::ostream &out)
:
    ScannerBase(in, out),
    d_includeFile(false),
    d_ignore(0),
    d_matched(matched())
{
    d_ifdef.push(d_ignore);
}
