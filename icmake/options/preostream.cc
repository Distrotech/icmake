#include "options.ih"

std::ostream &Options::preOstream()
{
    if (d_preProcess)
    {
cerr << "Preprocess ostream: " << outfile() << '\n';
        d_out.open(outfile());
        return d_out;
    }

    d_tmp1.reset(new TempStream);

cerr << "Preprocess ostream: " << d_tmp1->fileName() << '\n';
    return *d_tmp1;
}
