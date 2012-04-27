#include "scanner.ih"

string Scanner::ppID()
{
    istringstream in(d_matched);
    char ch;
    string id;
    in >> ch >> id >> id;

    return id;
}
