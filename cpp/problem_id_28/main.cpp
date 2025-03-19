#include <iostream>
#include <vector>

class Solution
{
  public:
    int
    strStr (std::string haystack, std::string needle)
    {
        int int_ver;
        std::size_t pos = haystack.find (needle, 0);

        if (pos == std::string::npos)
            int_ver = -1;
        else
            int_ver = (int)pos;

        return int_ver;
    }
};
