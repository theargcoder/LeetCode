#include <vector>

class Solution
{
public:
  int
  longestOnes (std::vector<int> &nums, int k)
  {
    const int n = nums.size ();

    int max = -1;
    int kp;

    int i = 0;
    while (i < n)
      {
        kp = k;
        int f0 = (k) ? n : i;
        int j = i, ct = 0;
        while (j < n && kp > 0)
          {
            if (nums[j] == 0)
              {
                kp--;
                if (f0 == n)
                  f0 = j;
              }
            ct++;
            j++;
          }
        while (j < n && nums[j] == 1)
          {
            ct++;
            j++;
          }
        max = std::max (ct, max);
        i = f0 + 1;
      }

    return max;
  }
};
