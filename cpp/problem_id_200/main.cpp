#include <queue>
#include <vector>

class Solution
{
public:
  int numIslands(std::vector<std::vector<char>> grid)
  {
    const unsigned i_size = grid.size();
    const unsigned j_size = grid.back().size();

    int islands = 0;
    std::queue<std::pair<unsigned, unsigned>> que;

    for(unsigned i = 0; i < i_size; i++)
    {
      for(unsigned j = 0; j < j_size; j++)
      {
        if(grid[i][j] == '1')
        {
          grid[i][j] = '0';
          islands++;

          que.emplace(i, j);
          while(!que.empty())
          {
            const auto pair = que.front();
            que.pop();

            const int up = pair.first - 1;
            const int down = pair.first + 1;
            const int left = pair.second - 1;
            const int right = pair.second + 1;

            if(up >= 0 && grid[up][pair.second] == '1')
            {
              grid[up][pair.second] = '0';
              que.emplace(up, pair.second);
            }
            if(down < i_size && grid[down][pair.second] == '1')
            {
              grid[down][pair.second] = '0';
              que.emplace(down, pair.second);
            }
            if(left >= 0 && grid[pair.first][left] == '1')
            {
              grid[pair.first][left] = '0';
              que.emplace(pair.first, left);
            }
            if(right < j_size && grid[pair.first][right] == '1')
            {
              grid[pair.first][right] = '0';
              que.emplace(pair.first, right);
            }
          }
        }
      }
    }

    return islands;
  }
};
