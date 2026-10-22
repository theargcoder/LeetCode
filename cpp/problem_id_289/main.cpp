#include <vector>

class Solution
{
private:
  int calculate_live_neighbors(const std::vector<std::vector<int>> &board, const int y, const int x)
  {
    const int N = static_cast<int>(board.size());
    const int M = static_cast<int>(board.back().size());

    int start_x = 0, end_x = x + 1;
    if(x - 1 >= 0)
    {
      start_x = x - 1;
    }
    if(x + 1 >= M)
    {
      end_x = M - 1;
    }

    int count = 0;
    if(y - 1 >= 0) // up one
    {
      for(int i = start_x; i <= end_x; i++)
        count += board[y - 1][i] > 0;
    }

    if(x - 1 >= 0)
    {
      count += board[y][x - 1] > 0;
    }

    if(x + 1 < M)
    {
      count += board[y][x + 1] > 0;
    }

    if(y + 1 < N) // down one
    {
      for(int i = start_x; i <= end_x; i++)
        count += board[y + 1][i] > 0;
    }

    return count;
  }

public:
  void gameOfLife(std::vector<std::vector<int>> &board)
  {
    const int N = board.size();
    const int M = board.back().size();

    for(int i = 0; i < N; i++)
    {
      for(int j = 0; j < M; j++)
      {
        const int count = calculate_live_neighbors(board, i, j);
        if(board[i][j] == 1)
        {
          if(count < 2 || count > 3)
          {
            board[i][j] = 2;
          }
        }
        else if(board[i][j] == 0 && count == 3)
        {
          board[i][j] = -1;
        }
      }
    }

    for(int i = 0; i < N; i++)
    {
      for(int j = 0; j < M; j++)
      {
        if(board[i][j] == -1)
        {
          board[i][j] = 1;
        }
        else if(board[i][j] == 2)
        {
          board[i][j] = 0;
        }
      }
    }
  }
};

int main(int argc, char *argv[])
{
  Solution sol;

  std::vector<std::vector<int>> board = { { 0, 1, 0 }, { 0, 0, 1 }, { 1, 1, 1 }, { 0, 0, 0 } };

  sol.gameOfLife(board);

  return 0;
}
