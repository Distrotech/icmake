#include "preprocessor.ih"

PreProcessor::PreProcessor()
:
    d_in(Options::instance().preIstream()),
    d_out(Options::instance().preOstream())
{}
