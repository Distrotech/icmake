#include "scanner.ih"

void Scanner::undef()
{
    string id = ppID();

    if (not d_defined.erase(id))
        emsg << '`' << id << "' not defined" << endl;
}
