#include "scanner.ih"

int Scanner::identifier()
{
    auto iter = s_identifiers.find(d_matched);

    if (iter != s_identifiers.end())
        d_token = iter->second;

    return Parser::IDENTIFIER;
}
