#include "scanner.ih"

void Scanner::define()
{
    istringstream in(d_matched);
    char c;
    string id;

    in >> c >> id;

    if (d_define.find(id) != d_defined.end())
    {
        emsg << '`' << id << "' multiply defined" << endl;
        return;
    }

    string def;
    getline(in, def);
    d_matched[id] = String::strip(def);
}
