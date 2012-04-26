#include "scanner.ih"

// At most 100 times: look for ${id} and if found look up ${id}. This must
// succeed. If found, replace ${id} by its definition.
// At the end, insert the replacement text in an istringstream en push that
// stream, switching the scan to the new istringstream.

void Scanner::replaceDefine()
{
    string destination = d_matched;

    for (size_t step = 0; step != 100; ++step)
    {
        size_t left = destination.find("${");
        size_t right = destination.find('}', left);
        if (left == string::npos || right == string::npos)  // no more ${...}
            break;

        string id = destination.substr(left + 2, right - left - 3);
        auto iter = d_define.find(id);

        if (iter == d_define.end())
        {
            emsg << "No `#define " << id << "' found" << endl;
            return;
        }

        destination.replace(left, right - left + 1, iter->second);
    }

    d_defineStream.str(destination);
    pushStream(d_defineStream);
}

