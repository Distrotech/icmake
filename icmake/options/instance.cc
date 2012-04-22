#include "options.ih"

Options &Options::instance()
{
    if (not s_options)
        s_options.reset(new Options);

    return *s_options;
}
