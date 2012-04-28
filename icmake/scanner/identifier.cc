#include "scanner.ih"

void Scanner::identifier()
{
    auto defIter = d_defined.find(d_matched);
    if (defIter != d_defined.end())
    {
        push(defIter->second);
        return;
    }

    auto iter = s_identifiers.find(d_matched);

    if (iter != s_identifiers.end())
        d_token = iter->second;

    (this->*d_ppOut)();

    leave(Parser::IDENTIFIER);
}
