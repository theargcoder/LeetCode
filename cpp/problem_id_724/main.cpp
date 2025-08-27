#include <vector>

class Solution
{
public:
  int
  pivotIndex (std::vector<int> &nums)
  {
    const int n = nums.size ();

    std::vector<long long> lsum (n), rsum (n);

    long long sum = 0;

    for (int i = 0; i < n; i++)
      {
        lsum[i] = sum;
        sum += nums[i];
      }

    sum = 0;
    for (int i = n - 1; i >= 0; i--)
      {
        rsum[i] = sum;
        sum += nums[i];
      }

    for (int i = 0; i < n; i++)
      {
        if (lsum[i] == rsum[i])
          return i;
      }

    return -1;
  }
};
