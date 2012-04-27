#ifndef INCLUDED_FILE_
#define INCLUDED_FILE_

#include <string>

class File
{
    public:
        File();
        std::string fileName(std::string const &infile, 
                             std::string const &ext);
        std::string tryName(std::string const &infile, 
                             std::string const &ext);
    private:
        std::string extension(std::string const &ext);

};
        
#endif
