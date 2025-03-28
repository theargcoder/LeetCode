#include <bitset>
#include <chrono>
#include <climits>
#include <iostream>
#include <string>
#include <vector>

// literally returning the size of vector of problem 51.......
// I am not going to even think about solving this any other way lol.
class Solution
{
 public:
   int
   totalNQueens (int n)
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

      return res.size ();
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
