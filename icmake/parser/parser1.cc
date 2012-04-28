#include "parser.ih"

Parser::Parser()
:
    d_options(Options::instance()),
    d_scanner(d_options.inStream(), d_options.preProcess()),
    d_tokens(d_options.showTokens())
{}
