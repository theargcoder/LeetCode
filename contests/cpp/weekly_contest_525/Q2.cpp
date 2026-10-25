#include <algorithm>
#include <charconv>
#include <cstdint>
#include <numeric>
#include <set>
#include <vector>

class Solution
{
public:
  long long maximizeSum(const std::vector<int> &nums, const int &k)
  {
    // reordered vs original
    std::vector<std::pair<int64_t, int64_t>> cpy;
    cpy.reserve(k + 1);

    int64_t number;
    char buff[16];
    for(const auto &num : nums)
    {
      const auto &[ptr, err] = std::to_chars(&buff[0], &buff[16], num);
      std::sort(&buff[0], ptr, [](const auto &a, const auto &b) { return a > b; });
      std::from_chars(&buff[0], ptr, number);
      cpy.emplace_back(number, num);
    }

    std::sort(cpy.begin(), cpy.end(), [](const auto &a, const auto &b) { return (a.first - a.second) > (b.first - b.second); });

    int64_t result = 0;
    size_t i = 0;
    for(size_t ct = 0; i < nums.size() && ct < k; i++)
    {
      result += cpy[i].first;
      if(cpy[i].first != cpy[i].second)
      {
        ct++;
      }
    }

    for(; i < nums.size(); i++)
    {
      result += cpy[i].second;
    }

    return result;
  }
};

int main(int argc, char *argv[])
{
  Solution sol;

  const auto res_1 = sol.maximizeSum({ 123, 45 }, 2);
  const auto res_2 = sol.maximizeSum({ 19, 20, 16, 6 }, 1);
  const auto res_3 = sol.maximizeSum({ 26, 6, 37, 41, 27, 29 }, 2);

  return 0;
}
