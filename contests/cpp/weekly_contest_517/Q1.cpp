#include <unordered_set>
#include <vector>

class Solution
{
public:
  int countSpecialIntegers(const std::vector<int> &nums)
  {
    const size_t size = nums.size();

    std::vector<bool> special(100 + 2, false);
    std::unordered_set<int> visited;

    int specials = 0;
    for(size_t i = 0; i < size; i++)
    {
      if(visited.count(nums[i]) == 0)
      {
        visited.insert(nums[i]);
        special[nums[i]] = true;
        size_t j = i;
        for(; j < size && nums[j] == nums[i]; j++)
        {
        }

        for(; j < size; j++)
        {
          if(nums[i] == nums[j])
          {
            special[nums[i]] = false;
            break;
          }
        }

        if(special[nums[i]])
        {
          specials++;
        }
      }
    }

    return specials;
  }
};
