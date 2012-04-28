#include "scanner.ih"

void Scanner::changeFile()
{
    string fName = d_matched.substr(1, d_matched.rfind('"') - 1);

    if (fName.empty())
        fmsg << "#include \"\": file name missing" << endl;
    
    pushStream(fName);
    d_includeFile = false;
}
