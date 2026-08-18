#include <cstring>
#include <vector>

#define MAX_NODES 100

class Solution
{
private:
  int memo[MAX_NODES][2];
  bool first_buy = false;

public:
  int rob(const std::vector<int> &nums)
  {
    const int size = nums.size();

    std::memset(&memo[0][0], -1, sizeof(memo));
    first_buy = true;
    const auto max_1 = nums[0] + dfs(nums, 1, size, true);
    std::memset(&memo[0][0], -1, sizeof(memo));
    first_buy = false;
    const auto max_2 = dfs(nums, 1, size, false);

    return std::max(max_1, max_2);
  }

private:
  int dfs(const std::vector<int> &nums, const int i, const int &size, const bool prev_stole)
  {
    if(i >= size)
    {
      return 0;
    }
    if(memo[i][prev_stole] != -1)
    {
      return memo[i][prev_stole];
    }
    if(!prev_stole && first_buy && i == size - 1)
    {
      return memo[i][prev_stole] = 0;
    }

    int max = 0;

    if(prev_stole)
    {
      max = std::max(max, dfs(nums, i + 1, size, false));
    }
    else
    {
      max = std::max(max, nums[i] + dfs(nums, i + 1, size, true));
      max = std::max(max, dfs(nums, i + 1, size, false));
    }

    return memo[i][prev_stole] = max;
  }
};
