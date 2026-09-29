#include <map>
#include <vector>

class Solution
{
public:
  std::vector<int> rearrangeArray(const std::vector<int> &nums)
  {
    std::map<int, int> count;
    std::vector<int> res;

    for(const auto &i : nums)
    {
      count[i]++;
    }

    while(!count.empty())
    {
      std::vector<int> to_erase;
      for(auto &pair : count)
      {
        res.push_back(pair.first);
        pair.second--;
        if(pair.second == 0)
        {
          to_erase.push_back(pair.first);
        }
      }
      for(const auto &i : to_erase)
      {
        count.erase(count.find(i));
      }
    }

    return res;
  }
};
