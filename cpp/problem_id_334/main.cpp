#include <algorithm>
#include <climits>
#include <vector>

// O(n) space version
class Solution
{
public:
  bool
  increasingTriplet (std::vector<int> &nums)
  {
    const int n = nums.size ();
    if (n < 3)
      return false;

    std::vector<int> left (n), right (n);
    left[0] = nums[0];
    left[1] = std::min (nums[0], nums[1]);
    for (int i = 2; i < n; i++)
      left[i] = std::min (left[i - 1], nums[i]);

    right[n - 1] = nums[n - 1];
    right[n - 2] = std::max (nums[n - 1], nums[n - 2]);
    for (int i = n - 3; i >= 0; i--)
      right[i] = std::max (right[i + 1], nums[i]);

    for (int i = 1; i < n - 1; i++)
      if (left[i] < nums[i] && right[i] > nums[i])
        return true;

    return false;
  }
};
