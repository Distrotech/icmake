#include "scanner.ih"

void Scanner::ppBlank()
{
    if (d_ppSpace || d_ppNewline)
        return;

    d_pp << ' ';
    d_ppSpace = true;
}

