#include <climits>
#include <vector>

class Solution
{
public:
  int
  longestSubarray (std::vector<int> &nums)
  {
    const int n = nums.size ();
    int max = INT_MIN;

    int i = 0, j = 0;
    int k = 0, ct = 0;
    bool clean = true;
    while (i < n)
      {
        if (nums[i] == 1)
          i++, k++;
        else
          {
            clean = false;
            j = i + 1;
            while (j < n && nums[j] == 1)
              j++, k++;
            max = std::max (k, max);
            k = 0;
            i++;
          }
      }
    max = std::max (k, max);
    if (clean)
      max--;

    return max;
  }
};
