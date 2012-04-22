#ifndef INCLUDED_PREPROCESSOR_
#define INCLUDED_PREPROCESSOR_

#include <iosfwd>

class PreProcessor
{
    std::istream &d_in;
    std::ostream &d_out;

    public:
        PreProcessor();
        void generate();
    private:
};
        
#endif
