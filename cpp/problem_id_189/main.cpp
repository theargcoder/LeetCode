#include <cstring>
#include <vector>

class Solution
{
public:
  void rotate(std::vector<int> &nums, const int k)
  {
    const unsigned size = nums.size();

    const int k_k = (k >= size) ? k % size : k;

    std::vector<int> cpy(size, 0);

    const unsigned comp = size - k_k;

    std::memcpy(&cpy[k_k], &nums[0], sizeof(int) * comp);
    std::memcpy(&cpy[0], &nums[comp], sizeof(int) * k_k);

    nums = cpy;
  }
};
