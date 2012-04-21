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
    std::string d_outfile;

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

        bool compile() const;
        bool execute() const;
        bool preProcess() const;

        std::string const &infile() const;
        std::string const &outfile() const;
        
    private:
        Options();

//        void setAccessorVariables();

        void setConfigFile();
        void setConfigParameters();
};

inline bool preProcess() const
{
    return d_preProcess;
}

inline bool compile() const
{
    return d_compile;
}

inline bool execute() const
{
    return d_execute;
}

inline std::string const &infile() const
{
    return d_infile;
}

inline std::string const &outfile() const
{
    return d_outfile;
}

#endif

