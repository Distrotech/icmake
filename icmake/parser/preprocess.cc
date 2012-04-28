#include "parser.ih"

void Parser::preProcess()
{
    while (d_scanner.lex())
        ;

    if (d_scanner.ifdefStackSize() != 1)
        fmsg << "#ifdef - #endif mismatch" << endl;
}
