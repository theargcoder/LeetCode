#include <algorithm>
#include <iterator>
#include <vector>

class Solution
{
public:
  std::vector<int>
  twoSum (std::vector<int> &numbers, int target)
  {
    const int n = numbers.size ();

    std::vector res (2, 0);
    int miss = 0;

    for (int i = 0; i < n; i++)
      {
        res[0] = i + 1;
        miss = target - numbers[i];
        auto it = std::lower_bound (numbers.begin () + i + 1, numbers.end (),
                                    miss);
        if (it != numbers.end ())
          {
            if (*it == miss)
              {
                res[1] = std::distance (numbers.begin (), it) + 1;
                return res;
              }
          }
      }

    return res;
  }
};
