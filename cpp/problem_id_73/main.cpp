#include <utility>
#include <vector>

class Solution
{
 public:
   void
   setZeroes (std::vector<std::vector<int>> &matrix)
   {
      const int n = matrix.size ();
      const int m = matrix.front ().size (); // alegedly it is a simmetric
                                             // matrix so this should do

      std::vector<std::pair<int, int>> pos;

      for (int i = 0; i < n; i++)
         {
            for (int j = 0; j < m; j++)
               {
                  if (matrix[i][j] != 0)
                     continue;
                  pos.push_back (std::pair (i, j));
               }
         }

      for (auto &pap : pos)
         {
            for (int x = 0; x < m; x++)
               {
                  matrix[pap.first][x] = 0;
               }
            for (int x = 0; x < n; x++)
               {
                  matrix[x][pap.second] = 0;
               }
         }

      return;
   }
};
