#include "commands.ih"


//  -------------------------------------------------------------------
//                  action:                                 default
//  options:        preprocess       compile     execute    outfile:
//  -------------------------------------------------------------------
//   none           infile[.im]         +           +          -
//
//   -p             infile[.im]                             infile.pim
//
//   -c             infile[.im]         +           -       infile.bim
//
//   -e                 -               -        infile[.bim]   -
//
//   -p && -e           -            infile[.pim]   +           -
//  -------------------------------------------------------------------

int Commands::process()
try
{
    if (not d_opt.execute())
        preprocess();    

    return 0;                   // return value for the operating system
}
catch (...)
{
    return 1;
}

