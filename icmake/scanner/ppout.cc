#include "scanner.ih"

void Scanner::ppOut()
{
    if (d_matched[0] != '\n')
    {
        d_ppSpace = false;
        d_ppNewline = false;
    }
    else
    {
        if (d_ppNewline)
            return;
        d_ppNewline = true;
    }
    d_pp << d_matched;
}

