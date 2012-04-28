#include "scanner.ih"

int Scanner::number()
{
    (this->*d_ppOut)();

    istringstream in(d_matched);
    in >> d_number;
    return Parser::NUMBER;
}
