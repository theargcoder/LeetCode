#include <unordered_map>
#include <vector>

class Solution
{
public:
  int countSpecialIntegers(const std::vector<int> &nums)
  {
    std::unordered_map<int, std::vector<int>> map;

    const size_t size = nums.size();
    for(size_t i = 0; i < size; i++)
    {
      map[nums[i]].push_back(static_cast<int>(i));
    }

    int count = 0;
    for(const auto &pair : map)
    {
      if(pair.second.size() == 3)
      {
        const auto diff_1 = pair.second[1] - pair.second[0];
        const auto diff_2 = pair.second[2] - pair.second[1];
        if(diff_1 == diff_2)
        {
          count++;
        }
      }
    }

    return count;
  }
};
