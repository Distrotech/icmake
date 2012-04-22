#include "options.ih"

std::istream &Options::preIstream()
{
cerr << "Preprocess istream: " << infile() << '\n';

    d_in.open(infile());
    return d_in;
}
