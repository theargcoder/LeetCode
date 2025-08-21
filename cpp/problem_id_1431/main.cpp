#include <algorithm>
#include <vector>

class Solution
{
public:
  std::vector<bool>
  kidsWithCandies (std::vector<int> &candies, int extraCandies)
  {
    const int n = candies.size ();
    auto max = std::max_element (candies.begin (), candies.end ());
    std::vector<bool> res (n, false);

    for (int i = 0; i < n; i++)
      {
        if (candies[i] + extraCandies >= *max)
          res[i] = true;
      }

    return res;
  }
};
