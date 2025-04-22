#include <climits>
#include <cstring>
#include <queue>
#include <vector>

//////////////////////////////////////////
//////////////////////////////////////////
///// works but time limit exceeded  /////
//////////////////////////////////////////
//////////////////////////////////////////
/*
class Solution
{
 private:
   std::vector<std::vector<int>> adj;
   std::vector<long long> used, paths;

 public:
   int
   minPathSum (std::vector<std::vector<int>> &grid)
   {
      const int m = grid.size ();
      const int n = grid[0].size ();
      const int vertices = n * m;

      if (!adj.empty ())
         {
            paths.clear ();
            used.clear ();
            adj.clear ();
         }

      for (int i = 0, ct = 0; i < m; i++)
         {
            for (int j = 0; j < n; j++, ct++)
               {
                  adj.emplace_back (vertices, INT_MAX);
                  used.push_back (0);

                  if (i + 1 < m)
                     {
                        int loc = (i + 1) * n + j;
                        adj[ct][loc] = grid[i + 1][j];
                     }
                  if (j + 1 < n)
                     {
                        int loc = i * n + (j + 1);
                        adj[ct][loc] = grid[i][j + 1];
                     }
               }
         }

      long long sum = grid[0][0];
      dfs (0, sum, vertices);
      auto bd = std::min_element (paths.begin (), paths.end ());
      if (bd != paths.end ())
         return (int)*bd;
      else
         return 0; // ERROR
   }

 private:
   void
   dfs (int u, long long &sum, const int &vertices)
   {
      if (u == vertices - 1)
         {
            paths.push_back ((long long)sum);
            return;
         }

      used[u] = 1;
      for (int v = 0; v < vertices; v++)
         {
            if (adj[u][v] != INT_MAX && !used[v])
               {
                  sum += adj[u][v];
                  dfs (v, sum, vertices);
                  sum -= adj[u][v];
               }
         }
      used[u] = 0;
      return;
   }
};
*/

//////////////////////
//////////////////////
// working but slow //
//////////////////////
//////////////////////

/*
class Solution
{
 public:
   int
   minPathSum (std::vector<std::vector<int>> &grid)
   {
      int m = grid.size (), n = grid[0].size ();
      std::vector<std::vector<int>> dist (m, std::vector<int> (n, INT_MAX));
      using P = std::pair<int, std::pair<int, int>>; // {cost, {x, y}}
      std::priority_queue<P, std::vector<P>, std::greater<>> pq;

      dist[0][0] = grid[0][0];
      pq.push ({ grid[0][0], { 0, 0 } });

      while (!pq.empty ())
         {
            auto [cost, pos] = pq.top ();
            pq.pop ();
            int x = pos.first, y = pos.second;

            int nx = x + 1;
            int ny = y + 1;

            if (ny < n)
               {
                  int next_cost = cost + grid[x][ny];
                  if (next_cost < dist[x][ny])
                     {
                        dist[x][ny] = next_cost;
                        pq.push ({ next_cost, { x, ny } });
                     }
               }
            if (nx < m)
               {
                  int next_cost = cost + grid[nx][y];
                  if (next_cost < dist[nx][y])
                     {
                        dist[nx][y] = next_cost;
                        pq.push ({ next_cost, { nx, y } });
                     }
               }
         }

      return dist[m - 1][n - 1];
   }
};
*/

class Solution
{
 public:
   int
   minPathSum (std::vector<std::vector<int>> &grid)
   {
      int m = grid.size (), n = grid[0].size ();
      using P = std::pair<int, std::pair<int, int>>; // {cost, {x, y}}
      std::priority_queue<P, std::vector<P>, std::greater<>> pq;

      dist[0][0] = grid[0][0];
      pq.push ({ grid[0][0], { 0, 0 } });

      while (!pq.empty ())
         {
            auto [cost, pos] = pq.top ();
            pq.pop ();
            int x = pos.first, y = pos.second;

            int nx = x + 1;
            int ny = y + 1;

            if (ny < n)
               {
                  int next_cost = cost + grid[x][ny];
                  if (next_cost < dist[x][ny])
                     {
                        dist[x][ny] = next_cost;
                        pq.push ({ next_cost, { x, ny } });
                     }
               }
            if (nx < m)
               {
                  int next_cost = cost + grid[nx][y];
                  if (next_cost < dist[nx][y])
                     {
                        dist[nx][y] = next_cost;
                        pq.push ({ next_cost, { nx, y } });
                     }
               }
         }

      return dist[m - 1][n - 1];
   }
};
