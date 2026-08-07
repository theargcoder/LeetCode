#include <climits>
#include <vector>

class Solution
{
public:
  int minSubArrayLen(const int target, const std::vector<int> &nums)
  {
    const int size = nums.size();
    int i = 0, j = 0;
    int sum = 0, dist = INT_MAX;

    while(j < size)
    {
      while(j < size && sum < target)
      {
        sum += nums[j++];
      }
      while(i <= j && sum >= target)
      {
        dist = std::min(dist, j - i);
        sum -= nums[i++];
      }
    }

    if(i == 0 && j >= size)
    {
      return 0;
    }
    else
    {
      return dist;
    }
  }
};
