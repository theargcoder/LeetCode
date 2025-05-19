#include <algorithm>
#include <vector>

class Solution
{
 private:
   struct dr
   {
      int down = 1, right = 1;
   };

 public:
   int
   maximalRectangle (std::vector<std::vector<char>> &matrix)
   {
      const int n = matrix.size ();
      const int m = matrix.front ().size ();

      int max = 0;

      std::vector<std::vector<dr>> tt (n, std::vector<dr> (m));

      for (int i = 0; i < n; i++)
         {
            for (int j = 0; j < m; j++)
               {
                  if (matrix[i][j] == '0')
                     continue;

                  if (max == 0)
                     max = 1;

                  dr ddrr;

                  for (int r = j + 1; r < m && matrix[i][r] == '1'; r++)
                     ddrr.right++;
                  for (int d = i + 1; d < n && matrix[d][j] == '1'; d++)
                     ddrr.down++;

                  tt[i][j] = ddrr;
               }
         }

      for (int i = 0; i < n; i++)
         {
            for (int j = 0; j < m; j++)
               {
                  if (matrix[i][j] == '0')
                     continue;

                  int minr = tt[i][j].right;
                  if (minr == 1)
                     {
                        max = std::max (max, tt[i][j].down);
                        continue;
                     }

                  for (int d = i + 1; d < n && matrix[d][j] == '1'; d++)
                     {
                        if (tt[d][j].right < minr)
                           {
                              max = std::max (max, minr * (d - i));
                              minr = tt[d][j].right;
                           }
                     }

                  max = std::max (max, tt[i][j].down * minr);
               }
         }

      return max;
   }
};
