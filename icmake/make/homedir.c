#include "icmake.h"

char const *homedir()
{
    uid_t uid = getuid();
    struct passwd *pw = getpwuid(uid);

    return pw == NULL ? NULL : pw->pw_dir;
}
