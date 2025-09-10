#include <vector>

class Solution
{
public:
  int
  equalPairs (std::vector<std::vector<int>> &grid)
  {
    const int n = grid.size ();

    int res = 0;
    std::vector<std::vector<int>> col (n, std::vector<int> (n));

    for (int i = 0; i < n; i++)
      for (int j = 0; j < n; j++)
        col[i][j] = grid[j][i];

    for (int i = 0; i < n; i++)
      for (int j = 0; j < n; j++)
        if (col[i] == grid[j])
          res++;

    return res;
  }
};
