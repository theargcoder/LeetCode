#include <vector>

class Solution
{
public:
  std::vector<int> lastVisitedCell(std::vector<std::vector<char>> &grid)
  {
    const int M = grid.size();
    const int N = grid.back().size();

    int x = 0, y = 0;
    while(true)
    {
      const auto action = grid[y][x];
      auto prev_x = x, prev_y = y;
      switch(action)
      {
      case 'R':
        x++;
        break;
      case 'L':
        x--;
        break;
      case 'U':
        y--;
        break;
      case 'D':
        y++;
        break;
      }

      if(x < 0 || y < 0 || x >= N || y >= M || grid[y][x] == 'X')
      {
        return { prev_y, prev_x };
      }

      grid[prev_y][prev_x] = 'X'; // X markes used
    }
  }
};
