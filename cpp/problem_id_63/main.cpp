#include <cmath>
#include <cstring>
#include <math.h>
#include <sys/types.h>
#include <vector>

///////////////////////////////////////
///////////////////////////////////////
/////// TIME LIMIT EXCEDED :( /////////
///////////////////////////////////////
///////////////////////////////////////
/*
class Solution
{
 public:
   int
   uniquePathsWithObstacles (std::vector<std::vector<int>> &obstacleGrid)
   {
      int m = obstacleGrid.size ();
      int n = obstacleGrid[0].size ();
      if (obstacleGrid[0][0] || obstacleGrid[m - 1][n - 1])
         return 0;

      int V = m * n;
      std::vector<int> obstacle (V);
      std::vector<std::vector<int>> adj (V, std::vector<int> (V, 0));

      for (int i = 0, id = 0; i < m; ++i)
         {
            for (int j = 0; j < n; ++j, ++id)
               {
                  obstacle[id] = obstacleGrid[i][j];
                  if (obstacle[id] == 0)
                     {
                        if (j + 1 < n && obstacleGrid[i][j + 1] == 0)
                           {
                              int loc = i * n + (j + 1);
                              adj[id][loc] = 1;
                           }
                        if (i + 1 < m && obstacleGrid[i + 1][j] == 0)
                           {
                              int loc = (i + 1) * n + j;
                              adj[id][loc] = 1;
                           }
                     }
               }
         }

      int Vmin = V - 1;
      const int size = adj.size ();

      return dfs (0, Vmin, adj, size, obstacle);
   }

 private:
   int
   dfs (int u, int &target, const std::vector<std::vector<int>> &adj,
        const int &size, std::vector<int> &used)
   {
      if (u == target)
         return 1;

      used[u] = 1;
      int total = 0;
      for (int v = 0; v < size; v++)
         {
            if (adj[u][v] && !used[v])
               total += dfs (v, target, adj, size, used);
         }
      used[u] = 0;
      return total;
   }
};
*/

class Solution
{
 public:
   int
   uniquePathsWithObstacles (std::vector<std::vector<int>> &obstacleGrid)
   {
      const auto &grid = obstacleGrid;

      int m = grid.size (), n = grid[0].size ();
      if (grid[0][0] || grid[m - 1][n - 1])
         return 0;

      std::vector<long> dp (n, 0);
      dp[0] = 1; // start cell

      // first row: if there's an obstacle, all to the right are 0
      for (int j = 1; j < n; ++j)
         dp[j] = (grid[0][j] ? 0 : dp[j - 1]);

      for (int i = 1; i < m; ++i)
         {
            dp[0] = grid[i][0] ? 0 : dp[0];
            for (int j = 1; j < n; ++j)
               {
                  if (grid[i][j])
                     {
                        dp[j] = 0;
                     }
                  else
                     {
                        dp[j] += dp[j - 1];
                     }
               }
         }

      return dp[n - 1];
   }
};
