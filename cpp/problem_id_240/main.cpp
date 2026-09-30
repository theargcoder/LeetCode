#include <algorithm>
#include <iostream>
#include <vector>
#pragma GCC optimize("O3", "unroll-loops", "fast-math")

auto init = []()
{
  std::ios::sync_with_stdio(false);
  std::cin.tie(nullptr);
  return 0;
}();

class Solution
{
public:
  bool searchMatrix(const std::vector<std::vector<int>> &matrix, const int &target)
  {
    for(const auto &vec : matrix)
    {
      if(std::ranges::binary_search(vec, target))
      {
        return true;
      }
    }

    return false;
  }
};
