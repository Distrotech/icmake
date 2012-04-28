#include "options.ih"

void Options::explicitOutFile()
{
    if (d_compile)
        fmsg << "`-c " << d_bimName << "' conflicts with argument `" << 
                    d_arg[1] << '\'' << endl;

    d_outName = d_arg[1];
    d_compile = true;
}
