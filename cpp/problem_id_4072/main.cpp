#include <algorithm>
#include <cstdint>
#include <vector>

class Solution
{
public:
  long long maxAlternatingSum(const std::vector<int> &nums)
  {
    int64_t ans = -1e10, plus = -1e10, minus = -1e10, plusDel = -1e10, minusDel = -1e10;
    for(int64_t x : nums)
    {
      const int64_t add = std::max(x, minus + x);
      const int64_t sub = plus - x;
      const int64_t del_s = std::max(minusDel + x, plus);
      const int64_t del_m = std::max(plusDel - x, minus);
      plus = add, minus = sub, plusDel = del_s, minusDel = del_m;
      ans = std::max({ ans, plus, minus, plusDel, minusDel });
    }
    return ans;
  }
};

int main(int argc, char *argv[])
{
  Solution sol;

  const auto res_1 = sol.maxAlternatingSum({ 5, -5, 1 });
  const auto res_2 = sol.maxAlternatingSum({ 10, -5, -100 });
  const auto res_3 = sol.maxAlternatingSum({ 4, 7 });
  const auto res_4 = sol.maxAlternatingSum({ -86, -16 });
  const auto res_5 = sol.maxAlternatingSum({ 82, -21, 2, 71 });

  return 0;
}
