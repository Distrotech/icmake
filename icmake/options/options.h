#ifndef INCLUDED_OPTIONS_
#define INCLUDED_OPTIONS_

#include <string>
#include <sstream>
#include <fstream>
#include <memory>

#include <bobcat/stat>

namespace FBB
{
    class ArgConfig;
}

class Options
{
    FBB::ArgConfig &d_arg;
    size_t      d_ownArgs;
    FBB::Stat   d_stat;
    std::string d_libDir;
    std::string d_skeletons;

    std::string d_inName;
    std::string d_outName;
    std::string d_pimName;
    std::string d_bimName;

    bool d_execute;
    bool d_compile;
    bool d_preProcess;
    bool d_showTokens;

    std::ifstream d_inStream;

    static char const s_defaultLibDir[];
    static char const s_defaultConfigGlobal[];
    static char const s_defaultConfigLocal[];
    static char const s_defaultSkeletons[];

    static std::unique_ptr<Options> s_options;

    public:
        static Options &instance();

        Options(Options const &other) = delete;

        bool needParser() const;
        bool ppOnly() const;
        bool showTokens() const;
        bool compile() const;
        bool execute() const;
        bool preProcess() const;

        std::string const &pimName() const;

        std::istream &inStream();

    private:
        Options();


        void setOptions();
        void explicitOutFile();
        void setConfigFile();
        void setConfigParameters();
};

inline bool Options::showTokens() const
{
    return d_showTokens;
}

inline bool Options::ppOnly() const
{
    return d_preProcess && not d_compile && not d_execute;
}

inline bool Options::needParser() const
{
    return d_compile || d_preProcess;
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

inline std::istream &Options::inStream()
{
    return d_inStream;
}

inline std::string const &Options::pimName() const
{
    return d_pimName;
}

#endif

