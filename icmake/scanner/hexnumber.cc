#include "scanner.ih"

int Scanner::hexNumber()
{
    (this->*d_ppOut)();

    istringstream in(d_matched);
    in.ignore(2);
    in >> hex >> d_number;
    return Parser::NUMBER;
}
