#include <vector>

enum COORD : int
{
  X = 0,
  Y = 1
};

class Solution
{
  // black = true, white false
  // clang-format off
  static constexpr bool board[8][8] = {
    { true, false, true, false, true, false, true, false },
    { false, true, false, true, false, true, false, true },
    { true, false, true, false, true, false, true, false },
    { false, true, false, true, false, true, false, true },
    { true, false, true, false, true, false, true, false },
    { false, true, false, true, false, true, false, true },
    { true, false, true, false, true, false, true, false },
    { false, true, false, true, false, true, false, true }
  };
  // clang-format on

public:
  bool canReach(const std::vector<int> &start, const std::vector<int> &target)
  {
    if(start == target)
      return true;

    const int st_x = start[X];
    const int st_y = start[Y];
    const int en_x = target[X];
    const int en_y = target[Y];

    const bool is_st_black = board[st_x][st_y];
    const bool is_en_black = board[en_x][en_y];

    return is_st_black == is_en_black;
  }
};
