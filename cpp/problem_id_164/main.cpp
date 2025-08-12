#include <algorithm>
#include <set>
#include <vector>

// easy way

class Solution
{
public:
  int
  maximumGap (std::vector<int> &nums)
  {
    const int n = nums.size ();

    if (n == 1)
      return 0;

    std::sort (nums.begin (), nums.end ());

    int diff = -1;

    for (int i = 0; i < n - 1; i++)
      {
        diff = std::max (diff, nums[i + 1] - nums[i]);
      }

    return diff;
  }
};
