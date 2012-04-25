#include "scanner.ih"

void Scanner::changeImFile()
{
    size_t first = d_matched.find('<') + 1;
    string fileName = d_matched.substr(first, d_matched.rfind('>') - pos);

    if (fileName.empty() || fileName[0] != '/')     // an empty filename is 
    {                                               // caught beyond
        vector<string> words;
        if (char *im = getenv("IM"))
            String::split(&words, im, ":");
    
        for(auto &dir: words)
        {
            if (Stat(dir + '/' + fileName))
            {
                
        
    pushStream(d_matched.substr(first, d_matched.rfind('"') - pos));
}
