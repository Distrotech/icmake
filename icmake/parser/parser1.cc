#include "parser.ih"

#include <bobcat/argconfig>

Parser::Parser()
:
    d_options(Options::instance()),
    d_scanner(d_options.inStream(), d_options.preProcess()),
    d_tokens(d_options.showTokens())
{
    d_scanner.setDebug(ArgConfig::instance().option('D'));
}
