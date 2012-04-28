#ifndef INCLUDED_FILE_
#define INCLUDED_FILE_

#include <string>

class File
{
    public:
        static std::string tryName(std::string const &infile, 
                                      std::string const &ext);
        static std::string changeExtension(std::string const &infile, 
                                      std::string const &ext);
    private:
        static std::string extension(std::string const &ext);

};
        
#endif
