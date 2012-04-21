#include "commands.ih"

void Commands::preProcess()
{
    PreProcessor preProcessor(d_opt.infile());

    preProcessor.generate(d_opt.pimFile());
}
