#include "scanner.ih"

void Scanner::changeImFile()
{
    string fileName = d_matched.substr(0, length() - 1);

    if (fileName.length() && fileName[0] == '/')
        pushStream(imfile(fileName));
    else
    {   
        vector<string> words;
        if (char *im = getenv("IM"))
            String::split(&words, im, ":");
    
        for(auto &dir: words)
        {
            string fname = imfile(dir + '/' + fileName);
            if (fname.length())
            {
                pushStream(fname);
                return;
            }
        }
    }
}
