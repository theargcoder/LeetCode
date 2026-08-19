#include <array>
#include <vector>

// beats 100% (0 ms) in time and 75% in memory
// easy

constexpr int MAX_NUM = 10'000;
constexpr int MIN_NUM = -10'000;
constexpr int RANGE = 2 * MAX_NUM + 1;

class Solution
{
public:
  std::array<int, RANGE> table;

  int findKthLargest(const std::vector<int> &nums, const int &k)
  {
    const size_t size = nums.size();
    table.fill(0);

    for(size_t i = 0; i < size; i++)
    {
      table[nums[i] + MAX_NUM]++;
    }

    int i, j;
    for(i = RANGE - 1, j = 0; i > 0; i--)
    {
      j += table[i];
      if(j >= k)
      {
        break;
      }
    }

    return i - MAX_NUM;
  }
};
