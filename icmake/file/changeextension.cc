#include "file.ih"

string File::changeExtension(string const &infile, string const &ext)
{
    size_t pos = infile.rfind('.');

    return ((pos != string::npos) ? infile.substr(0, pos) : infile) +
                                                              extension(ext);
}
