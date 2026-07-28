#include <cstring>
#include <vector>

class Solution
{
private:
  int memo[401][2];

public:
  int rob(std::vector<int> &nums)
  {
    std::memset(&memo[0][0], -1, sizeof(memo));
    const unsigned size = nums.size();

    return dfs(nums, size, 0, false);
  }

private:
  int dfs(const std::vector<int> &nums, const unsigned &size, const int i, const bool stole)
  {
    if(i >= size)
    {
      return 0;
    }

    if(memo[i][stole] != -1)
    {
      return memo[i][stole];
    }

    if(stole)
    {
      memo[i][stole] = dfs(nums, size, i + 1, false);
      return memo[i][stole];
    }
    else
    {
      memo[i][stole] = std::max(dfs(nums, size, i + 1, false), nums[i] + dfs(nums, size, i + 1, true));
      return memo[i][stole];
    }
  }
};
