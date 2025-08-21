#include <climits>
#include <cstdlib>
#include <vector>

class Solution
{
public:
  int
  calculateMinimumHP (std::vector<std::vector<int>> &dungeon)
  {
    const int m = dungeon.size ();
    const int n = dungeon.back ().size ();

    int sum = 0;

    std::vector<std::vector<int>> DP (m + 1, std::vector<int> (n + 1, 0));

    DP[m][n - 1] = 1;
    DP[m - 1][n] = 1;

    for (int i = m - 1; i >= 0; --i)
      {
        for (int j = n - 1; j >= 0; --j)
          {
            int need = std::min (DP[i + 1][j], DP[i][j + 1]) - dungeon[i][j];
            DP[i][j] = std::max (1, need);
          }
      }

    return DP[0][0];
  }
};
