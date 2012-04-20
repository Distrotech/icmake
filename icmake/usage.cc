//                     usage.cc

#include "main.ih"

void usage(std::string const &progname)
{
    cout << "\n" <<
    progname << " by " << Icmbuild::author << "\n" <<
    progname << " V" << Icmbuild::version << " " << Icmbuild::years << "\n"
    "\n"
    "Usage: " << progname << " [options] infile [outfile] [-- [...]]\n"
    "Where:\n"
    "   [options] - optional arguments (short options between parentheses):\n"
    "      --about (-a)     - about Icmake\n"
    "      --compile (-c)   - only compile the input file, no execution\n"
    "      --config-file (-C) path-name - use 'path-name' as configuration "
                                                                    "file\n"
    "                         (defaults: ~/.icmakerc, "
                                                    "/etc/icmake/icmake.rc)\n"
    "      --execute (-e)   - infile is the name of a previously compiled\n"
    "                         .bim file, which is merely executed, or\n"
    "                         compile and execute if --pre-process was also\n"
    "                         specified\n"
    "      --help (-h)      - provide this help\n"
    "      --pre-process (-p) path-name  - the pre-processed file is "
                                                                "written\n"
    "                         on 'path-name'\n"
    "      --verbose (-V)   - produce more verbose output on stdout\n"
    "      --version (-v)   - show version information and terminate\n"
    "\n"
    "   infile - the Icmake source file (default extension .im)\n"
    "            (or, with --execute, a binary icmake file (default "
                                                                "extension)\n"
    "            .bim)\n"
    "   outfile - if provided: the name of the generated binary Icmake "
                                                                    "file\n"
    "            (default filename: infile, default extension .bim)\n"
    "   ... -    ...: optional arguments passed to the binary Icmake file\n"
    "\n";
}

