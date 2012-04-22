#include "options.ih"

std::istream &Options::preIstream()
{
    d_in.open(infile());
    return d_in;
}
