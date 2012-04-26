#include "scanner.ih"

string Scanner::imfile(string const &fname) const
{
    string ret = String::trim(fname);

    if (Stat(ret))
        return ret;

    size_t pos = ret.rfind('.');
    if (pos != string::npos)
        ret.resize(pos);

    ret += ".im";
    if (!Stat(ret))
        ret.clear();

    return ret;
}
