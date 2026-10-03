#include <bit>
#include <iostream>
#include <vector>

#pragma GCC optimize("O3", "unroll-loops", "march=native")

auto init = []()
{
  std::ios::sync_with_stdio(false);
  std::cin.tie(nullptr);
  return 0;
}();

class Solution
{
public:
  std::vector<int> singleNumber(std::vector<int> &nums)
  {
    unsigned XOR = 0;
    for(const auto &i : nums)
    {
      XOR ^= i;
    }

    const auto i = std::countr_zero(XOR);

    int numa = 0, numb = 0;
    for(const auto &num : nums)
    {
      if(num & (1U << i))
      {
        numa ^= num;
      }
      else
      {
        numb ^= num;
      }
    }

    return { numa, numb };
  }
};
