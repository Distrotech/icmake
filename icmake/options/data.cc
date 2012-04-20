#include "options.ih"

char const Options::s_defaultLibDir[]       = "/usr/lib/icmake";
char const Options::s_defaultConfigGlobal[] = "/etc/icmake/icmstart.rc";
char const Options::s_defaultConfigLocal[]  = "/.icmstartrc";
char const Options::s_defaultSkeletons[]    = "/usr/lib/icmake";

Options *Options::s_options = 0;

