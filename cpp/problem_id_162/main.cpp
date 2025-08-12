#include <vector>

class Solution
{
public:
  int
  findPeakElement (std::vector<int> &nums)
  {
    int n = nums.size ();

    if (n == 1)
      return 0;
    if (n == 2)
      return (nums[0] > nums[1]) ? 0 : 1;
    if (n == 3)
      return (nums[0] < nums[1] && nums[1] > nums[2]) ? 1
             : (nums[0] > nums[1])                    ? 0
             : (nums[1] < nums[2])                    ? 2
                                                      : -1;

    if (nums[0] > nums[1])
      return 0;
    if (nums[n - 1] > nums[n - 2])
      return n - 1;

    int l = 1, r = n - 2;

    while (l < r)
      {
        int mid = (l + r) / 2;
        if (nums[l - 1] < nums[l] && nums[l] > nums[l + 1])
          return l;
        if (nums[r - 1] < nums[r] && nums[r] > nums[r + 1])
          return r;

        if (nums[mid] < nums[mid + 1])
          l = mid;
        else
          r = mid;
      }

    return -1;
  }
};
