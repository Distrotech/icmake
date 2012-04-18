typedef struct
{
    char const *key;
    char const **var;
} KEY_;

static KEY_ key[] = 
{
    {"icm-comp:",    // path to the icmake compiler
    {"icm-exec:",    // path to the executor
    {"icm-pp:",      // path to the preprocessor
    {"skeletons:",   // the skeletons (library) directory
    {"icmstart.rc:", // path to the icmstart.rc configuration file
};

void check_parameters(char *line)
{
    char *first = strspn(line, " \t"); /* 1st non-blank */
    KEY_ *begin = key;
    KEY_ end    = key + sizeof(key) / sizeof(KEY_);

    for (; begin != end; ++begin)
    {
        char *cp;
        if ((cp = strstr(line, begin->key)))
        {
            cp = strchr(cp, ':') + 1;
            if (cp = value_of(cp))
            {
                (*begin->var) = cp;
                return;
            }
        }
    }
}

