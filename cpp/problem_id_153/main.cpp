#include <vector>

class Solution
{
public:
  int
  findMin (std::vector<int> &nums)
  {
    const int n = nums.size ();

    if (n == 1)
      return nums[0];

    if (nums[0] < nums[n - 1])
      return nums[0];

    int l = 0;
    int r = n - 1;
    int mid = 1;

    while (l < r && r - l > 1)
      {
        mid = l + ((r - l) / 2);

        if (nums[mid] > nums[l])
          l = mid;
        else
          r = mid;
      }

    return nums[r];
  }
};
