#include <algorithm>
#include <set>
#include <vector>

// easy way

/*
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
*/

class Solution
{
public:
  int
  maximumGap (std::vector<int> &nums)
  {
    const int n = nums.size ();

    if (n == 1)
      return 0;

    int max = *std::max_element (nums.begin (), nums.end ());
    int maxdigs = 0;
    for (int t = max; t > 0; t /= 10)
      maxdigs++;

    std::vector<int> srtd (n);
    long long div = 1;

    for (long long p = 0; p < maxdigs; p++)
      {
        int count[10] = { 0 };

        for (int i = 0; i < n; i++)
          count[(nums[i] / div) % 10]++;

        for (int i = 1; i < 10; i++)
          count[i] += count[i - 1];

        for (int i = n - 1; i >= 0; i--)
          {
            int digit = (nums[i] / div) % 10;
            srtd[count[digit] - 1] = nums[i];
            count[digit]--;
          }

        nums = srtd;
        div *= 10;
      }

    int diff = -1;

    for (int i = 1; i < n; i++)
      diff = std::max (diff, srtd[i] - srtd[i - 1]);

    return diff;
  }
};
