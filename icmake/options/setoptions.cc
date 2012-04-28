#include "options.ih"

void Options::setOptions()
{
    d_inName = File::tryName(d_arg[0], "im");

    d_preProcess = d_arg.option(&d_pimName, 'p');
    d_compile = d_arg.option(&d_bimName, 'c');

    if (d_ownArgs > 1)
        explicitOutFile();
    else if (d_execute)
        d_outName = File::changeExtension(d_arg[0], "bim");

    Errno::open(d_inStream, d_inName);
}


