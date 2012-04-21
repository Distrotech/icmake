#include "options.ih"

void Options::setOptions()
{
    string value;

    if (!d_execute))            // not merely executing: infile needed
        d_infile = d_file.fileName(d_arg[0], d_preProcess ? ".im" : ".pim");

    if (d_arg.nArgs() > 1 && d_arg[1] != "--")
}
