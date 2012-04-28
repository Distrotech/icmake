#include "file.ih"

string File::tryName(string const &infile, string const &ext)
{
    string ret = infile;

    return Stat(ret)? ret : changeExtension(infile, ext);
}
