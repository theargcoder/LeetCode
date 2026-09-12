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
      const auto &vec = pair.second;
      const auto size_vec = vec.size();
      if(size_vec >= 3)
      {
        int diff = vec[1] - vec[0];
        size_t i = 2;
        for(; i < size_vec; i++)
        {
          if(vec[i] - vec[i - 1] != diff)
          {
            break;
          }
        }
        if(i == size_vec)
        {
          count++;
        }
      }
    }

    return count;
  }
};
