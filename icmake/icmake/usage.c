#include "icmake.ih"

void usage(char const *prog)
{
    error
    (
        "%s%s%s%s%s",

        "Icmake by Frank B. Brokken (and Karel Kubat until V 6.30).\n"
        "\n"
        "Usage: ",
            prog,
        " [flags] source[.im] [dest[.bim]] [-- [args]]\n"
        "where:\n"
        "\tflags:  optional flags:\n"
        "\t\t-a       : information about ",
            prog,
        "\n"
        "\t\t-b       : blunt execution of the destinationfile\n"
        "\t\t-c       : the destination file is compiled\n"
        "\t\t-C config: path to a configuration file (default: ~/.icmakerc,"
                                                                        "\n"
        "\t\t           /etc/icmake.rc)\n"
        "\t\t-i file  : 'file': name of source, argument processing stops\n"
        "\t\t-p       : only the preprocessor is activated\n"
        "\t\t-q       : quiet mode: copyright banner not displayed\n"
        "\t\t-t file  : 'file' is used as a temporary bim-file, to be "
                                                            "removed\n",

        "\t\t           on exit. Argument processing stops.\n"
        "\tsource     : make description source file "
                                                "(default extension: .im)\n"
        "\tdest       : binary make file         (default:    source.bim)\n"
        "\t             (not used with the -t option)\n"
        "\t--         : icmake-file arguments separator\n"
        "\targs       : arguments following -- are received by the icmake\n"
        "\t             file in its argv-list"
    );
}

