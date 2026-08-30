#include <climits>
#include <vector>

class Solution
{
public:
  int minOperations(const std::vector<int> &nums, const int &sum)
  {
    const size_t size = nums.size();
    int min = INT_MAX;

    dfs(nums, sum, 0, 0, 0, min);

    return (min == INT_MAX) ? -1 : min;
  }

private:
  void dfs(const std::vector<int> &nums, const int &sum, const int idx, const int ops, const int trail_sum, int &min)
  {
    if(trail_sum == sum)
    {
      min = std::min(ops, min);
      return;
    }
    else if(trail_sum > sum || ops >= min)
    {
      return;
    }

    if(idx >= nums.size())
    {
      return;
    }

    int curr = nums[idx];

    dfs(nums, sum, idx + 1, ops, trail_sum, min);
    dfs(nums, sum, idx + 1, ops, trail_sum + curr, min);

    for(int it_ops = 1; curr < sum; it_ops++)
    {
      curr <<= 1U; // aka div by 2
      dfs(nums, sum, idx + 1, ops + it_ops, trail_sum + curr, min);
    }

    curr = nums[idx];
    for(int it_ops = 1; curr != 0; it_ops++)
    {
      curr >>= 1U; // aka div by 2
      dfs(nums, sum, idx + 1, ops + it_ops, trail_sum + curr, min);
    }

    return;
  }
};

int main(int argc, char *argv[])
{
  Solution sol;

  const auto res_1 = sol.minOperations({ 5, 6, 10 }, 4);
  const auto res_2 = sol.minOperations({ 10, 2 }, 13);
  const auto res_3 = sol.minOperations({ 1, 4 }, 6);
  const auto res_4 = sol.minOperations({ 8, 7 }, 1);

  return 0;
}
