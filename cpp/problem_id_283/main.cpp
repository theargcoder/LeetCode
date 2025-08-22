#include <utility>
#include <vector>

class Solution
{
public:
  void
  moveZeroes (std::vector<int> &nums)
  {
    const int n = nums.size ();

    int z = -1;

    for (int i = 0; i < n; i++)
      {
        if (z == -1)
          {
            if (nums[i] != 0)
              continue;
            z = i;
          }
        else if (nums[i] != 0)
          {
            std::swap (nums[i], nums[z]);
            z++;
          }
      }
  }
};
