#include "scanner.ih"

int Scanner::parserToken()
{
    (this->*d_ppOut)();

    auto iter = s_token.find(d_matched);
    d_token = iter->second.first;
    return iter->second.second;
}
