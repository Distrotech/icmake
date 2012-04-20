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

        void setConfigParameters();
};


#endif
