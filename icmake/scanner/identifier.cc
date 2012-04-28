#include "scanner.ih"

int Scanner::identifier()
{
    (this->*d_ppOut)();

    auto iter = s_identifiers.find(d_matched);

    if (iter != s_identifiers.end())
        d_token = iter->second;

    return Parser::IDENTIFIER;
}
