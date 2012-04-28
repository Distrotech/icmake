#include "parser.ih"

void Parser::writeFiles()
{
    if (d_options.preProcess())
    {
        ofstream out;
        Errno::open(out, d_options.pimName());
        out << d_scanner.pp().rdbuf();
    }
}
