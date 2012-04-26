#include "scanner.ih"

void Scanner::ifdef()
{
    if (d_ignore)
        ++d_ignore;
    else
    {
        istringstream in(d_matched);
        char ch;
        string id;
        in >> ch >> id >> id;
        d_ignore = d_defined.find(id) == d_defined.end();
    }
    
    d_ifdef.push(d_ignore);
    begin(d_ignore ? StartCondition__::ignore : StartCondition__::INITIAL);
}
