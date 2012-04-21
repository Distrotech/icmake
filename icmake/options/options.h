#ifndef INCLUDED_OPTIONS_
#define INCLUDED_OPTIONS_

#include <string>
#include <bobcat/a2x>

namespace FBB
{
    class ArgConfig;
}

class Options
{
    FBB::ArgConfig &d_arg;

    std::string d_libDir;
    std::string d_skeletons;
    std::string d_infile;

    File d_file;

    bool d_execute;
    bool d_compile;
    bool d_preprocess;

	static char const s_defaultLibDir[];
	static char const s_defaultConfigGlobal[];
	static char const s_defaultConfigLocal[];
	static char const s_defaultSkeletons[];

    static Options *s_options;

    public:
        static Options &instance();

        Options(Options const &other) = delete;

        void setAccessorVariables();
        
    private:
        Options();

        void setConfigFile();
        void setConfigParameters();
};

inline std::string const &infile()
{
    return d_infile;
}

#endif
