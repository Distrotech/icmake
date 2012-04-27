#include "scanner.ih"

void Scanner::changeFile()
{
    string fName = d_matched.substr(1, d_matched.rfind('"') - 1);
    string fName2 = d_file.tryName(fName, "im");

    if (fName2.empty())
        throw Errno(1) << "Can't read `" << fName << "'\n";
    
    pushStream(fName2);
}
