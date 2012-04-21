#include "options.ih"

void Options::setConfigFile()
{
    string configName;
    if (not d_arg.option(&configName, 'C'))
        configName = User().homedir() + s_defaultConfigLocal;

    if (not Stat(configName))
        configName = s_defaultConfigGlobal;

    if (Stat(configName))
    {
        d_arg.open(configName);
        setConfigParameters();
    }
}
