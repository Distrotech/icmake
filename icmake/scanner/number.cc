#include "scanner.ih"

int Scanner::number()
{
    istringstream in(d_matched);
    in >> d_number;
    return Parser::NUMBER;
}
