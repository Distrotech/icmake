#include "options.ih"

void Options::setConfigParameters()
{
    d_arg.option(&d_libDir, 'l');
    d_arg.option(&d_skeletons, 's');
}
