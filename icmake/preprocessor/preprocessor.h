#ifndef INCLUDED_PREPROCESSOR_
#define INCLUDED_PREPROCESSOR_

#include <string>

class PreProcessor
{
    public:
        PreProcessor(std::string const &infile);
        void generate(std::string const &outfile);
    private:
};
        
#endif
