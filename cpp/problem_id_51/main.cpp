#include <bitset>
#include <chrono>
#include <climits>
#include <iostream>
#include <string>
#include <vector>

// 79 ms to do n = [2-9] in LeetCode
// will try to improve
/*
class Solution
{
 public:
   std::vector<std::vector<std::string> >
   solveNQueens (int n)
   {
      std::bitset<81> board; // max size (1 <= n <= 9)
      const int nn = n * n;

      for (int i = 0; i < nn; i++)
         {
            board[i] = false;
         }

      std::vector<std::vector<std::string> > res{};
      helper (res, board, n, nn, 0, 0);
      return res;
   }

   void
   helper (std::vector<std::vector<std::string> > &res, std::bitset<81> &board,
           const int &n, const int &nn, int row, int col)
   {
      if (row >= n)
         {
            res.push_back ({});
            for (int i = 0; i < n; i++)
               {
                  res.back ().push_back ("");
                  for (int j = 0; j < n; j++)
                     {
                        const int Q = i * n + j;
                        if (board[Q])
                           res.back ()[i].push_back ('Q');
                        else
                           res.back ()[i].push_back ('.');
                     }
               }
            return;
         }

      for (int i = col; i < row * n + n; i++)
         {
            if (board[i] == false)
               {
                  board[i] = true;
                  if (is_valid (board, n, nn))
                     {
                        helper (res, board, n, nn, row + 1, 0);
                     }
                  board[i] = false;
               }
         }
   }
   // they cant attack eachother
   bool
   is_valid (std::bitset<81> &board, const int &n, const int &nn)
   {
      for (int i = 0; i < n; i++)
         {
            for (int j = 0; j < n; j++)
               {
                  const int Q = i * n + j;
                  if (!board[Q])
                     continue;
                  int x, y;
                  for (x = i * n; x < (i * n + n); x++)
                     {
                        if (x != Q)
                           {
                              if (!board[x])
                                 continue;
                              return false;
                           }
                     }
                  for (y = j; y < (nn); y += n)
                     {
                        if (y != Q)
                           {
                              if (!board[y])
                                 continue;
                              return false;
                           }
                     }
                  if (!check_diagonals (board, i - 1, j - 1, n, "LU"))
                     return false;
                  if (!check_diagonals (board, i - 1, j + 1, n, "LD"))
                     return false;
                  if (!check_diagonals (board, i + 1, j - 1, n, "RU"))
                     return false;
                  if (!check_diagonals (board, i + 1, j + 1, n, "RD"))
                     return false;
               }
         }
      return true;
   }

   bool
   check_diagonals (std::bitset<81> &board, int x, int y, const int &n,
                    const char LDLURDRU[2])
   {
      if (x < 0 || x >= n)
         return true;
      if (y < 0 || y >= n)
         return true;

      bool left = (LDLURDRU[0] == 'L');
      bool up = (LDLURDRU[1] == 'U');

      while (x >= 0 && x < n && y >= 0 && y < n)
         {
            const int index = (x * n) + y;

            if (board[index])
               {
                  return false;
               }

            if (left && up)
               {
                  x--;
                  y--;
               }
            else if (left && !up)
               {
                  x--;
                  y++;
               }
            else if (!left && up)
               {
                  x++;
                  y--;
               }
            else
               {
                  x++;
                  y++;
               }
         }
      return true;
   }
};
*/

// 12 ms solution
/*
class Solution
{
 public:
   std::vector<std::vector<std::string> >
   solveNQueens (int n)
   {
      unsigned short BASE = 1;
      for (int i = 0; i < 16 - n; i++)
         BASE = (BASE << 1) | (0x1);
      for (int i = 0; i < n; i++)
         BASE = (BASE << 1);
      unsigned short board[9];
      unsigned short options[9];
      bool used[9];

      for (int i = 0; i < n; i++)
         {
            unsigned short tmp = BASE | (1 << i);
            options[i] = tmp;
            used[i] = false;
            board[i] = BASE;
         }

      std::vector<std::vector<std::string> > res{};
      helper (res, &board[0], n, 0, BASE, &used[0], &options[0]);
      return res;
   }
   void
   helper (std::vector<std::vector<std::string> > &res, unsigned short *board,
           const int &n, const int row, const unsigned short &BASE, bool *used,
           unsigned short *options)
   {
      if (row >= n)
         {
            if (is_valid (board, n, BASE))
               {
                  res.push_back ({});
                  for (int i = 0; i < n; i++)
                     {
                        res.back ().push_back ("");
                        for (int j = 0; j < n; j++)
                           {
                              if ((board[i] >> j) & 0b1)
                                 res.back ()[i].push_back ('Q');
                              else
                                 res.back ()[i].push_back ('.');
                           }
                     }
               }

            return;
         }

      // Use row as the limit (number of rows filled so far) in the partial
      // check.
      for (int i = 0; i < n; i++)
         {
            board[row] = options[i];
            if (!used[i] && diagonal (board, n, BASE, row))
               {
                  used[i] = true;
                  helper (res, board, n, row + 1, BASE, used, options);
                  used[i] = false;
               }
         }
      board[row] = BASE;
      return;
   }
   bool
   diagonal (unsigned short *board, const int n, const unsigned short &BASE,
             int idx)
   {
      // Isolate the queen's bit from the current row.
      unsigned short queenPos = board[idx] & ~BASE;

      // Check the row above (if any)
      if (idx > 0)
         {
            unsigned short queenAbove = board[idx - 1] & ~BASE;
            // If shifting queenAbove left or right gives queenPos, they share
            // a diagonal.
            if ((queenAbove << 1) == queenPos || (queenAbove >> 1) == queenPos)
               return false;
         }

      // Check the row below (if any)
      if (idx < n - 1)
         {
            unsigned short queenBelow = board[idx + 1] & ~BASE;
            if ((queenBelow << 1) == queenPos || (queenBelow >> 1) == queenPos)
               return false;
         }

      return true;
   }
   // they cant attack eachother
   bool
   is_valid (unsigned short *board, const int &n, const unsigned short &BASE)
   {
      for (int i = 0; i < n; i++)
         {
            short count = 0, count_cpy;
            unsigned short tmp = board[i];
            while (!(tmp & 0b1))
               {
                  count++;
                  tmp >>= 1;
               }
            // UPPER LEFT DIAGONAL
            count_cpy = count + 1;
            for (int j = i - 1; j >= 0; j--)
               {
                  tmp = board[j];

                  if (count_cpy >= n)
                     break;

                  tmp >>= count_cpy;

                  if (tmp & 0b1)
                     {
                        return false;
                     }

                  count_cpy++;
               }
            // UPPER RIGHT DIAGONAL
            count_cpy = count - 1;
            for (int j = i - 1; j >= 0; j--)
               {
                  tmp = board[j];

                  if (count_cpy < 0)
                     break;

                  tmp >>= count_cpy;

                  if (tmp & 0b1)
                     {
                        return false;
                     }

                  count_cpy--;
               }
            // LOWER RIGHT DIAGONAL
            count_cpy = count - 1;
            for (int j = i + 1; j < n; j++)
               {
                  tmp = board[j];

                  if (count_cpy < 0)
                     break;

                  tmp >>= count_cpy;

                  if (tmp & 0b1)
                     {
                        return false;
                     }

                  count_cpy--;
               }
            // LOWER LEFT DIAGONAL
            count_cpy = count + 1;
            for (int j = i + 1; j < n; j++)
               {
                  tmp = board[j];

                  if (count_cpy >= n)
                     break;

                  tmp >>= count_cpy;

                  if (tmp & 0b1)
                     {
                        return false;
                     }

                  count_cpy++;
               }
         }
      return true;
   }
};
*/

// 0 ms solution beats 100% of solutions i am a genious
/*
class Solution
{
 public:
   std::vector<std::vector<std::string> >
   solveNQueens (int n)
   {
      unsigned short BASE = 1;
      for (int i = 0; i < 16 - n; i++)
         BASE = (BASE << 1) | (0x1);
      for (int i = 0; i < n; i++)
         BASE = (BASE << 1);
      unsigned short board[9];
      unsigned short options[9];
      unsigned short prev_mask[9];
      bool used[9];

      for (int i = 0; i < n; i++)
         {
            unsigned short tmp = BASE | (1 << i);
            options[i] = tmp;
            used[i] = false;
            board[i] = BASE;
         }

      std::vector<std::vector<std::string> > res{};
      helper (res, &board[0], n, 0, BASE, &used[0], &options[0],
              &prev_mask[0]);
      return res;
   }
   void
   helper (std::vector<std::vector<std::string> > &res, unsigned short *board,
           const int &n, const int row, const unsigned short &BASE, bool *used,
           unsigned short *options, unsigned short *prev_mask)
   {
      if (row >= n)
         {
            res.push_back ({});
            for (int i = 0; i < n; i++)
               {
                  res.back ().push_back ("");
                  for (int j = 0; j < n; j++)
                     {
                        if ((board[i] >> j) & 0b1)
                           res.back ()[i].push_back ('Q');
                        else
                           res.back ()[i].push_back ('.');
                     }
               }

            return;
         }

      // Use row as the limit (number of rows filled so far) in the partial
      // check.
      for (int i = 0; i < n; i++)
         {
            board[row] = options[i];
            if (!used[i] && diagonal_cmpnd (board, n, BASE, row, prev_mask))
               {
                  used[i] = true;
                  helper (res, board, n, row + 1, BASE, used, options,
                          prev_mask);
                  used[i] = false;
               }
         }
      board[row] = BASE;
      return;
   }
   bool
   diagonal_cmpnd (unsigned short *board, const int n,
                   const unsigned short &BASE, int idx,
                   unsigned short *prev_mask)
   {
      // Isolate the queen's bit from the current row.
      unsigned short queenPos = board[idx] & ~BASE;

      for (int i = 0; i < idx; i++)
         {
            // If shifting queenAbove left or right gives queenPos, they share
            // a diagonal.
            if ((prev_mask[i] >> (idx - i)) == queenPos
                || (prev_mask[i] << (idx - i)) == queenPos)
               return false;
         }
      prev_mask[idx] = queenPos;

      return true;
   }
};
*/

// FINAL indebatable 0ms
// HYPER OPTIMIZED IDK even where it can be better
class Solution
{
 public:
   std::vector<std::vector<std::string> >
   solveNQueens (int n)
   {
      const unsigned short BASE
          = 0b1111111111111111 & (0b1111111111111111 << n);
      const unsigned short NBASE = ~BASE;
      unsigned short board[9];
      unsigned short options[9];
      unsigned short prev_mask[9];
      bool used[9];

      for (int i = 0; i < n; i++)
         {
            options[i] = BASE | (1 << i);
            used[i] = false;
            board[i] = BASE;
         }

      int row = 0;

      std::vector<std::vector<std::string> > res{};
      res.reserve (353);
      helper (res, board, n, row, NBASE, used, options, prev_mask);
      return res;
   }

 private:
   void
   helper (std::vector<std::vector<std::string> > &res,
           unsigned short (&board)[9], const int &n, int &row,
           const unsigned short &NBASE, bool (&used)[9],
           unsigned short (&options)[9], unsigned short (&prev_mask)[9])
   {
      if (row >= n)
         {
            res.push_back ({});
            for (int i = 0; i < n; i++)
               {
                  res.back ().push_back ("");
                  for (int j = 0; j < n; j++)
                     {
                        if ((board[i] >> j) & 0b1)
                           res.back ()[i].push_back ('Q');
                        else
                           res.back ()[i].push_back ('.');
                     }
               }

            return;
         }

      // Use row as the limit (number of rows filled so far) in the partial
      // check.
      for (int i = 0; i < n; i++)
         {
            if (!used[i])
               {
                  used[i] = true;
                  board[row] = options[i];
                  if (diagonal_cmpnd (board, n, NBASE, row, prev_mask))
                     {
                        row++;
                        helper (res, board, n, row, NBASE, used, options,
                                prev_mask);
                        row--;
                     }
                  used[i] = false;
               }
         }
      return;
   }
   inline bool
   diagonal_cmpnd (unsigned short (&board)[9], const int &n,
                   const unsigned short &NBASE, int &idx,
                   unsigned short (&prev_mask)[9])
   {
      // Isolate the queen's bit from the current row.
      unsigned short queenPos = board[idx] & NBASE;

      for (unsigned char i = 0; i < idx; i++)
         {
            // If shifting queenAbove left or right gives queenPos, they share
            // a diagonal.
            if ((prev_mask[i] >> (idx - i)) == queenPos
                || (prev_mask[i] << (idx - i)) == queenPos)
               return false;
         }
      prev_mask[idx] = queenPos;

      return true;
   }
};

int
main ()
{
   Solution sol;

   auto st = std::chrono::high_resolution_clock::now ();
   auto solito = sol.solveNQueens (9);
   auto en = std::chrono::high_resolution_clock::now ();

   for (auto &soi : solito)
      {
         std::cout << "[ ";
         for (auto &str : soi)
            {
               std::cout << '\'' << str << "', ";
            }
         std::cout << "]\n";
      }

   auto dur = std::chrono::duration_cast<std::chrono::milliseconds> (en - st);
   std::cout << "\n\n IT TOOK : " << dur.count () << " ms \n\n";

   return 0;
}
