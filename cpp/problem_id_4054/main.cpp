#include <algorithm>
#include <vector>

class Solution
{
public:
  long long shadowPairs(const std::vector<int> &nums)
  {
    const size_t size = nums.size();
    long long count = 0;
    std::vector<int> stk;
    stk.reserve(size);

    for(const auto &i : nums)
    {
      while(!stk.empty() && stk.back() > i)
      {
        stk.pop_back();
      }

      auto low = std::ranges::lower_bound(stk, i);

      count += low - stk.begin();

      stk.push_back(i);
    }

    return count;
  }
};

int main(int argc, char *argv[])
{
  Solution sol;

  const auto res_1 = sol.shadowPairs({ 3, 1, 4, 1, 5 });
  const auto res_2 = sol.shadowPairs({ 6, 7, 6, 6, 7 });
  const auto res_3 = sol.shadowPairs({ 1, 2, 3, 4 });
  const auto res_4 = sol.shadowPairs({ 1, 2, 3, 4, 5 });
  const auto res_5 = sol.shadowPairs({ 1, 2, 3, 4, 5, 6 });
  const auto res_6 = sol.shadowPairs({ 1, 1, 1, 2, 3, 4, 5, 6 });
  const auto res_7 = sol.shadowPairs({ 1, 2, 2, 2, 3, 4, 5, 6 });

  return 0;
}
