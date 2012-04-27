#ifndef INCLUDED_OPTIONS_
#define INCLUDED_OPTIONS_

#include <string>
#include <sstream>
#include <fstream>
#include <memory>

#include "../file/file.h"

namespace FBB
{
    class ArgConfig;
    class TempStream;
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
    bool d_preProcess;
    bool d_showTokens;

    std::ifstream d_in;
    std::stringstream d_tmp1;
    std::stringstream d_tmp2;
    std::ofstream d_out;

    static char const s_defaultLibDir[];
    static char const s_defaultConfigGlobal[];
    static char const s_defaultConfigLocal[];
    static char const s_defaultSkeletons[];

    static std::unique_ptr<Options> s_options;

    public:
        static Options &instance();

        Options(Options const &other) = delete;

        bool showTokens() const;
        bool compile() const;
        bool execute() const;
        bool preProcess() const;

        std::istream &preIstream();
        std::ostream &preOstream();

        std::string const &infile() const;
        std::string const &outfile() const;
        
    private:
        Options();

//        void setAccessorVariables();

        void setOptions();

        void setConfigFile();
        void setConfigParameters();

};

inline bool Options::showTokens() const
{
    return d_showTokens;
}

inline bool Options::preProcess() const
{
    return d_preProcess;
}

inline bool Options::compile() const
{
    return d_compile;
}

inline bool Options::execute() const
{
    return d_execute;
}

inline std::string const &Options::infile() const
{
    return d_infile;
}

inline std::string const &Options::outfile() const
{
    return d_outfile;
}

#endif

