#include <climits>
#include <math.h>
#include <utility>
#include <vector>

class Solution
{
public:
  int
  maxProduct (std::vector<int> &nums)
  {
    const int n = nums.size ();

    if (n == 1)
      return nums[0];

    int max = INT_MIN, min = INT_MAX;
    int tmpmax = 1, tmpmin = 1;

    double abs = 1.0;

    for (int i = 0; i < n; i++)
      {
        if (nums[i] < 0)
          std::swap (tmpmax, tmpmin);

        tmpmax = std::max (nums[i], tmpmax * nums[i]);
        max = std::max (max, tmpmax);

        tmpmin = std::min (nums[i], tmpmin * nums[i]);
        min = std::min (min, tmpmin);

        abs *= nums[i];
      }

    if (abs > 0)
      return (int)abs;

    return max;
  }
};
