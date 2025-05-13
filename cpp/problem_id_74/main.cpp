#include <vector>

class Solution
{
 public:
   bool
   searchMatrix (std::vector<std::vector<int>> &matrix, int target)
   {
      int up = 0;
      int down = matrix.size () - 1;

      while (down - up > 1)
         {
            int mid = (up + down) / 2;
            if (matrix[mid][0] < target)
               up = mid;
            else
               down = mid;
         }

      int final;
      if (matrix[down][0] > target)
         final = up;
      else
         final = down;

      int left = 0;
      int right = matrix[final].size () - 1;

      while (right - left > 1)
         {
            int mid = (left + right) / 2;
            if (matrix[final][mid] < target)
               left = mid;
            else
               right = mid;
         }

      return ((matrix[final][left] == target)
              || (matrix[final][right] == target));
   }
};
