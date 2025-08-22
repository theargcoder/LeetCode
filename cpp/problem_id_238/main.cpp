#include <vector>

class Solution
{
public:
  std::vector<int>
  productExceptSelf (std::vector<int> &nums)
  {
    const int n = nums.size ();

    std::vector<int> left (n, 1), right (n, 1);

    for (int i = 1; i < n; i++)
      left[i] = left[i - 1] * nums[i - 1];
    for (int i = n - 2; i >= 0; i--)
      right[i] = right[i + 1] * nums[i + 1];

    for (int i = 0; i < n; i++)
      right[i] *= left[i];

    return right;
  }
};
