#include "options.ih"

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

Options::Options()
:
    d_arg(ArgConfig::instance()),
    d_libDir(s_defaultLibDir),
    d_skeletons(s_defaultSkeletons),

    d_execute(d_arg.option('e')),
    d_compile(d_arg.option('c')),
    d_preProcess(d_arg.option('p'))
{
    setConfigFile();
    setOptions();
}




