#include "scanner.ih"

void Scanner::define()
{
    string line;

    string id = getDirectiveInfo(&line);

    if (d_defined.find(id) != d_defined.end())
    {
        emsg << '`' << id << "' multiply defined" << endl;
        return;
    }

    d_defined[id] = line;
}
