#include "scanner.ih"

int Scanner::plain(int token)
{
    (this->*d_ppOut)();
    return token;
}
