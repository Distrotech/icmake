#include "scanner.ih"

void Scanner::str()
{
    setMatched(String::unescape(d_matched));

    if (d_ppIdent.length())
    {
        define(d_matched);
        return;
    }

    begin(StartCondition__::INITIAL);

    if (d_includeFile)
        changeFile();
    else
    {
        (this->*d_ppOut)();
        leave(Parser::STRING);
    }
}
