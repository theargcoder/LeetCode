#include <vector>

class Solution
{
 public:
   int
   minimumTotal (std::vector<std::vector<int>> &triangle)
   {
      std::vector<std::vector<int>> memo (
          triangle.size (), std::vector<int> (triangle.back ().size ()));

      const int maxsize = triangle.size () - 1;
      for (int i = 0; i < triangle.back ().size (); i++)
         memo[maxsize][i] = triangle.back ()[i];

      for (int i = maxsize - 1; i >= 0; i--)
         {
            int size = triangle[i].size ();

            for (int j = 0; j < size; j++)
               memo[i][j] = triangle[i][j]
                            + std::min (memo[i + 1][j], memo[i + 1][j + 1]);
         }

      return memo[0][0];
   }
};
