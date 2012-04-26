#include "scanner.ih"

int Scanner::parserToken()
{
    auto iter = s_token.find(d_matched);
    d_token = iter->second.first;
    return iter->second.second;
}
