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
{
//    if (not d_opt.execute())
//        preProcess();    

    cerr << "Commands::process\n";

    Parser parser(d_opt.preIstream(), d_opt.showTokens());
    cerr << "parsing...\n";    
    cout << "Parse returns " << parser.parse() << '\n';
    return 0;                   // return value for the operating system
}

