#include "scanner.ih"

void Scanner::changeImFile()
{
    size_t first = d_matched.find('<') + 1;
    string fileName = d_matched.substr(first, d_matched.rfind('>') - pos);

    if (fileName.length() && fileName[0] == '/')
        pushStream(imFile(fileName));
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
