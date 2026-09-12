#include <climits>
#include <unordered_map>
#include <vector>

class Solution
{
public:
  std::vector<int> majorityElement(const std::vector<int> &nums)
  {
    std::vector<int> to_ret;
    const int size = nums.size();
    const int freq = size / 3;

    std::unordered_map<int, int> map;

    int insert1 = INT_MIN;
    for(const auto &i : nums)
    {
      map[i]++;
      if(map[i] > freq)
      {
        if(i != insert1)
        {
          to_ret.push_back(i);
          insert1 = i;
          if(to_ret.size() == 2)
          {
            return to_ret;
          }
        }
      }
    }

    return to_ret;
  }
};
