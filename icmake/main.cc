#include "main.ih"

// Room for Args initialization
namespace
{
    Arg::LongOption longOptions[] =
    {
        {"about",        'a'},
        Arg::LongOption("compile",      'c'),
        Arg::LongOption("config-file",  'C'),
        Arg::LongOption("execute",      'e'),
        Arg::LongOption("help",         'h'),
        Arg::LongOption("library",      'l'),
        
        Arg::LongOption("pre-process",  'p'),
        Arg::LongOption("version",      'v'),
        Arg::LongOption("skeletons",    's'),
        Arg::LongOption("verbose",      'V'),
    };

    Arg::LongOption const *const longEnd =
                    longOptions +
                    sizeof(longOptions) / sizeof(longOptions[0]);
}

int main(int argc, char **argv)
try
{
    ArgConfig &arg = ArgConfig::initialize("acC:ehl:ps:vV",
                    longOptions, longEnd, argc, argv);

    arg.versionHelp(usage, Icmbuild::version, 1);

    Commands commands;
    return commands.process();
}
catch (...)
{
    return 1;
}
