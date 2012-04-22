#include "options.ih"

std::ostream &Options::preOstream()
{
    if (d_preProcess)
    {
        d_out.open(outfile());
        return d_out;
    }

    d_tmp1.reset(new TempStream);
    return *d_tmp1;
}
