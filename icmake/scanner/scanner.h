#ifndef INCLUDED_SCANNER_
#define INCLUDED_SCANNER_

#include <unordered_map>
#include <string>

class Scanner
{
    std::unordered_map<std::string, std::string> d_define;
    public:
        Scanner();

    private:
        void blanks();
        void comment();

        void changeFile();
        void changeImFile()
        std::string imfile(std::string const &fname) const;
        void define();


};
        
#endif
