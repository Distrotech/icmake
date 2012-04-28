#include "options.ih"

void Options::setOptions()
{
    d_inName = File::tryName(d_arg[0], "im");

    d_preProcess = d_arg.option(&d_pimName, 'p');
    d_compile = d_arg.option(&d_bimName, 'c');

    if (d_ownArgs > 1)
        explicitOutFile();
    else 
    {
        if (not d_preProcess && not d_compile)
        {
            if (d_execute)
            {
                d_inName.clear();
                d_bimName = File::tryName(d_arg[0], "bim");
            }
            else
            {
                d_compile = true;            
                d_execute = true;
            }
        }
    }

    if (d_inName.length())
        Errno::open(d_inStream, d_inName);
}


