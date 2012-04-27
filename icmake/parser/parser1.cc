#include "parser.ih"

Parser::Parser(istream &in, bool tokens)
:
    d_scanner(in),
    d_tokens(tokens)
{}
