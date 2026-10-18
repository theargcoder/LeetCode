#include <vector>

class Solution
{
public:
  int minDeletions(std::vector<int> &nums)
  {
    const size_t size = nums.size();

    int del = 0;
    for(size_t i = 1; i < size; i++)
    {
      unsigned XOR = nums[i - 1] ^ nums[i];
      if(XOR == 0)
      {
        del++;
      }
    }

    return del;
  }
};
