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
    ArgConfig &arg = ArgConfig::initialize("ac:C:ehl:p:s:tvV",
                    longOptions, longEnd, argc, argv);

    arg.versionHelp(usage, Icmbuild::version, 
                    1 + arg.nArgs() - arg.beyondDashes());

    Options &options = Options::instance();

    cout << options.preProcess() << ' ' << options.compile() << ' ' <<
            options.execute() << '\n';

    if (options.needParser())
    {
        Parser parser;

        if (options.ppOnly())
            parser.preProcess();
        else
            parser.parse();

        if (not parser.ok())
            return 1;
        
        parser.writeFiles();
    }

    if (options.execute())
    {
//        Executor executor(options.bimStream());
//        return executor.execute();
    }
}
catch (exception const &err)
{
    cout << err.what() << '\n';
    return 1;
}
catch (...)
{
    cout << "caught exception\n";
    return 1;
}
