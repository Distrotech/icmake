#include "scanner.ih"

int Scanner::charToken()
{
    (this->*d_ppOut)();

    return d_matched[0];
}
