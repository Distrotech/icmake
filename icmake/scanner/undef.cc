#include "scanner.ih"

void Scanner::undef()
{
    string id = getDirectiveInfo();

    if (not d_define.erase(id))
        emsg << '`' << id << "' not defined" << endl;
}
