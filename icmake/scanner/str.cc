#include "scanner.ih"

void Scanner::str()
{
    setMatched(String::unescape(d_matched));

    begin(StartCondition__::INITIAL);

    if (d_ppIdent.length())
        define();
    else if (d_includeFile)
        changeFile();
    else
        leave(Parser::STRING);
}
