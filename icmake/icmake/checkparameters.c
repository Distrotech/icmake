#include "icmake.ih"

typedef struct
{
    char const *key;
    char const **var;
} KEY_;

static KEY_ key[] = 
{
    {"icm-comp:",    &s_icm_comp},      // path to the icmake compiler
    {"icm-exec:",    &s_icm_exec},      // path to the executor
    {"icm-pp:",      &s_icm_pp},        // path to the preprocessor
    {"skeletons:",   &s_skeletons},     // the skeletons (library) directory
    {"icmstart.rc:", &s_icmstart_rc}    // path to the icmstart.rc 
                                        // configuration file
};

void check_parameters(char *line)
{
    char *first = line + strspn(line, " \t");          /* 1st non-blank */
    KEY_ *begin = key;
    KEY_ *end   = key + sizeof(key) / sizeof(KEY_);

    for (; begin != end; ++begin)
    {
        char *cp = strstr(first, begin->key);
        if (cp == first)                            /* keyword at bol */
        {
            cp = strchr(cp, ':') + 1;               /* beyond the keyword */
            if ((cp = value_of(line, cp)))
            {
                (*begin->var) = cp;
                return;
            }
        }
    }
}



