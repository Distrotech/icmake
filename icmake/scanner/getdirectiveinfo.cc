#include "scanner.ih"

string Scanner::getDirectiveInfo(string *definition)
{
    istringstream in(d_matched);
    char c;
    string id;

    in >> c >> id >> id;

    if (definition)
    {
        string line;
        getline(in, line);
        *definition = String::trim(line);
    }
        
    return id;
}
