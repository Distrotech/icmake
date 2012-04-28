#include "scanner.ih"

void Scanner::changeImFile()
{
    string fileName = d_matched.substr(0, length() - 1);

    if (char const *im = getenv("IM"))
        d_stat.set(fileName, im);
    else
        d_stat.set(fileName);

    if (not d_stat)
        fmsg << "#include <" << fileName << 
                ">: not found in IM environment" << endl;

    pushStream(d_stat.name());
}



