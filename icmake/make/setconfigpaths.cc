#include "icmake.h"

void set_config_paths()
{
    FILE *config;

    if (g_config_name)             // not a pre-defined path
        config = fopen(g_config_name);
    else
    (
        config = fopen("r", 
                        g_config_name = makepath(homedir(), ".icmakerc", 0))
        ||
        config = fopen("r", g_config_name = "/etc/icmake.rc")
    )
        
    if (config)
        read_config_file(config);
}




