#include <iostream>
#include <math.h>
#include <unordered_map>
#include <unordered_set>
#include <vector>

class Solution
{
  public:
    std::vector<std::vector<int> >
    combinationSum2 (std::vector<int> &candidates, int target)
    {
        std::sort (candidates.begin (), candidates.end ());
        std::vector<std::vector<int> > result;
        std::vector<int> buffer;

        backtrack_2 (candidates, result, buffer, candidates.begin (), target);

        return result;
    }

  private:
    void
    backtrack_2 (const std::vector<int> &candidates,
                 std::vector<std::vector<int> > &result,
                 std::vector<int> &buffer,
                 std::vector<int>::const_iterator start, int remaining)
    {
        if (remaining == 0)
            {
                result.push_back (buffer);
                return;
            }
        if (remaining < 0)
            return;

        for (auto it = start; it != candidates.end ();)
            {
                buffer.push_back (*it);
                backtrack_2 (candidates, result, buffer, it + 1,
                             remaining - *it);
                buffer.pop_back ();
                it = std::upper_bound (it, candidates.end (), *it);
            }
    }
};
int
main ()
{

    return 0;
}
