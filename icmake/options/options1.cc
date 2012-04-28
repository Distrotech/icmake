#include "options.ih"

Options::Options()
:
    d_arg(ArgConfig::instance()),
    d_ownArgs(d_arg.beyondDashes()),
    d_libDir(s_defaultLibDir),
    d_skeletons(s_defaultSkeletons),
    d_execute(d_arg.option('e')),
    d_showTokens(d_arg.option('t'))
{
    setConfigFile();
    setOptions();
}





