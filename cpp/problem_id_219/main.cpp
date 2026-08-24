#include <algorithm>
#include <array>
#include <utility>
#include <vector>

class Solution
{
public:
  bool containsNearbyDuplicate(const std::vector<int> &nums, const int &k)
  {
    if(k == 0)
    {
      return false;
    }

    const int size = nums.size();

    std::array<std::pair<int, int>, 100'001> freq;
    for(int i = 0; i < size; i++)
    {
      freq[i] = std::make_pair(nums[i], i);
    }

    std::sort(freq.begin(), freq.begin() + size);

    for(int i = 1; i < size; i++)
    {
      const auto &prev = freq[i - 1];
      const auto &curr = freq[i];
      if(prev.first == curr.first && curr.second - prev.second <= k)
      {
        return true;
      }
    }

    return false;
  }
};
