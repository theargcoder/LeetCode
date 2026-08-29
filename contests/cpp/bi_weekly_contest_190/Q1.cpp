#include <cstdlib>
#include <vector>

// false == black
// true == white
// clang-format off
constexpr bool coors[9][9] = {
  { false, false, false, false, false, false, false, false, false }, 
  { false, true, false, true, false, true, false, true, false }, 
  { false, false, true, false, true, false, true, false, true },
  { false, true, false, true, false, true, false, true, false }, 
  { false, false, true, false, true, false, true, false, true },
  { false, true, false, true, false, true, false, true, false }, 
  { false, false, true, false, true, false, true, false, true },
  { false, true, false, true, false, true, false, true, false }, 
  { false, false, true, false, true, false, true, false, true },
};
// clang-format on

class Solution
{
public:
  int minBishopMoves(const std::vector<int> &source, const std::vector<int> &target)
  {
    if(coors[source[0]][source[1]] == coors[target[0]][target[1]])
    {
      const int x_diff = std::abs(source[0] - target[0]);
      const int y_diff = std::abs(source[1] - target[1]);

      if(x_diff == y_diff)
      {
        return 1;
      }
      else
      {
        return 2;
      }
    }
    else
    {
      return -1;
    }
  }
};
