#include <utility>
#include <vector>

class Solution
{
 public:
   void
   solve (std::vector<std::vector<char>> &board)
   {
      const int n = board.size ();
      const int m = board.back ().size ();

      std::vector<std::vector<bool>> xable (n, std::vector<bool> (m, true));

      for (int i = 0; i < m; i++)
         {
            if (board[0][i] == 'O')
               Xed (board, xable, 0, i, n, m);
            if (board[n - 1][i] == 'O')
               Xed (board, xable, n - 1, i, n, m);
         }
      for (int i = 0; i < n; i++)
         {
            if (board[i][0] == 'O')
               Xed (board, xable, i, 0, n, m);
            if (board[i][m - 1] == 'O')
               Xed (board, xable, i, m - 1, n, m);
         }

      for (int i = 1; i < n - 1; i++)
         {
            for (int j = 1; j < m - 1; j++)
               {
                  if (!xable[i][j])
                     continue;
                  board[i][j] = 'X';
               }
         }
   }

 private:
   void
   Xed (const std::vector<std::vector<char>> &board,
        std::vector<std::vector<bool>> &xable, int i, int j, const int &n,
        const int &m)
   {
      if (i < 0 || j < 0 || i >= n || j >= m)
         return;
      if (board[i][j] == 'X' || !xable[i][j])
         return;

      xable[i][j] = false;
      Xed (board, xable, i, j + 1, n, m);
      Xed (board, xable, i, j - 1, n, m);
      Xed (board, xable, i + 1, j, n, m);
      Xed (board, xable, i - 1, j, n, m);
   }
};
