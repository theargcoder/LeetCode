#include <iostream>
#include <string>
#include <vector>

class Solution
{
  public:
    std::string
    longestCommonPrefix (std::vector<std::string> &strs)
    {
        int size = strs.size ();

        if (size == 1)
            return strs[0];

        std::string prefix = strs[0];

        for (int i = 1; i < size; i++)
            {
                if (strs[i][0] != prefix[0])
                    {
                        return "";
                    }
                int range = std::min (strs[i].size (), prefix.size ());
                bool erased = false;
                for (int j = 0; j < range; j++)
                    {
                        if (strs[i][j] != prefix[j])
                            {
                                prefix.erase (j, prefix.size () - j);
                                erased = true;
                                break;
                            }
                    }
                if (!erased)
                    {
                        prefix = (strs[i].size () < prefix.size ()) ? strs[i]
                                                                    : prefix;
                    }
            }

        return prefix;
    }
};

int
main ()
{
    Solution solution;
    std::vector<std::string> strs ({ "flower", "flow", "flight" });
    std::cout << solution.longestCommonPrefix (strs) << '\n';
    return 0;
}
