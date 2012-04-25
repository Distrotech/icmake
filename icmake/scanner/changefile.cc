#include "scanner.ih"

void Scanner::changeFile()
{
    size_t first = d_matched.find('"') + 1;

    pushStream(imFile(d_matched.substr(first, d_matched.rfind('"') - pos)));
}
