#include "options.ih"

void Options::setConfigFile()
{
    string configName;

    if (not d_arg.option(&configName, 'C'))
        configName = User().homedir() + s_defaultConfigLocal;

    if (not d_stat.set(configName))
        configName = s_defaultConfigGlobal;

    if (d_stat.set(configName))
    {
        d_arg.open(configName);
        setConfigParameters();
    }
}
