#include "file.ih"

string File::extension(string const &ext)
{
    string ret;

    if (!ext.length())
        return ret;

    if (ext[0] != '.')
        ret += '.';

    ret += ext;

    return ret;
}
