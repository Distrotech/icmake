#include "scanner.ih"

int Scanner::hexNumber()
{
    istringstream in(d_matched);
    in.ignore(2);
    in >> hex >> d_number;
    return Parser::NUMBER;
}
