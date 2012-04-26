#include "scanner.ih"

int Scanner::str()
{
    setMatched(String::unescape(d_matched.substr(1, length() - 2)));
    return Parser::STRING;
}
