#include <array>
#include <deque>
#include <string>
#include <vector>

// almost there
/*
class Solution
{
 public:
   bool
   exist (std::vector<std::vector<char>> &board, std::string word)
   {
      const int n = board.size ();
      const int m = board.front ().size ();

      if (n == 1 && m == 1)
         {
            if (word.size () == 1)
               return board[0][0] == word[0];
            else
               return false;
         }

      std::array<std::array<bool, 6>, 6> used;

      std::deque<char> wd;
      for (int i = 0; i < word.size (); i++)
         wd.push_back (word[i]);

      for (int i = 0; i < n; i++)
         for (int j = 0; j < m; j++)
            used[i][j] = false;

      bool jumping = false;
      auto wd_cpy = wd;
      auto used_cpy = used;
      int i = 0, j = 0;
      int ipy = 0, jpy = 0;

      while (i < n)
         {
            while (j < m)
               {
                  if (wd.empty ())
                     return true;

                  bool something = false;
                  if (i > 0 && board[i - 1][j] == wd.front ()
                      && !used[i - 1][j])
                     {
                        wd.pop_front ();
                        used[i - 1][j] = true;
                        something = true;
                        i--;
                     }
                  else if (i < n - 1 && board[i + 1][j] == wd.front ()
                           && !used[i + 1][j])
                     {
                        wd.pop_front ();
                        used[i + 1][j] = true;
                        something = true;
                        i++;
                     }
                  else if (j > 0 && board[i][j - 1] == wd.front ()
                           && !used[i][j - 1])
                     {
                        wd.pop_front ();
                        used[i][j - 1] = true;
                        something = true;
                        j--;
                     }
                  else if (j < m - 1 && board[i][j + 1] == wd.front ()
                           && !used[i][j + 1])
                     {
                        wd.pop_front ();
                        used[i][j + 1] = true;
                        something = true;
                        j++;
                     }
                  if (!something && !jumping)
                     j++;
                  else if (!something && jumping)
                     {
                        i = ipy;
                        j = jpy;
                        wd = wd_cpy;
                        used = used_cpy;
                        jumping = false;
                     }
                  else if (something && !jumping)
                     {
                        ipy = i;
                        jpy = j;
                        wd_cpy = wd;
                        used_cpy = used;
                        jumping = true;
                     }
               }
            i++;
         }

      return false;
   }
};
*/

class Solution
{
 public:
   bool
   exist (std::vector<std::vector<char>> &board, std::string word)
   {
      const int n = board.size ();
      const int m = board.front ().size ();

      std::vector<std::vector<bool>> used (n, std::vector<bool> (m, false));

      for (int i = 0; i < n; i++)
         {
            for (int j = 0; j < m; j++)
               {
                  if (board[i][j] != word[0])
                     continue;
                  used[i][j] = true;
                  if (explore (i, j, 1, board, used, word, n, m))
                     return true;
                  used[i][j] = false;
               }
         }

      return false;
   }

 private:
   bool
   explore (int i, int j, int w, const std::vector<std::vector<char>> &board,
            std::vector<std::vector<bool>> &used, const std::string &word,
            const int &n, const int &m)
   {
      if (w == word.size ())
         return true;

      if (j > 0 && !used[i][j - 1] && board[i][j - 1] == word[w])
         {
            used[i][j - 1] = true;
            if (explore (i, j - 1, w + 1, board, used, word, n, m))
               return true;
            used[i][j - 1] = false;
         }
      if (j < m - 1 && !used[i][j + 1] && board[i][j + 1] == word[w])
         {
            used[i][j + 1] = true;
            if (explore (i, j + 1, w + 1, board, used, word, n, m))
               return true;
            used[i][j + 1] = false;
         }
      if (i > 0 && !used[i - 1][j] && board[i - 1][j] == word[w])
         {
            used[i - 1][j] = true;
            if (explore (i - 1, j, w + 1, board, used, word, n, m))
               return true;
            used[i - 1][j] = false;
         }
      if (i < n - 1 && !used[i + 1][j] && board[i + 1][j] == word[w])
         {
            used[i + 1][j] = true;
            if (explore (i + 1, j, w + 1, board, used, word, n, m))
               return true;
            used[i + 1][j] = false; // fuck this line
         }

      return false;
   }
};
