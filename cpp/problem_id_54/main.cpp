#include <algorithm>
#include <array>
#include <climits>
#include <iostream>
#include <vector>

class Solution
{
 public:
   std::vector<int>
   spiralOrder (std::vector<std::vector<int> > &matrix)
   {
      const int m = matrix.size ();
      const int n = matrix[0].size ();

      std::vector<int> to_ret;
      to_ret.reserve (n * m);

      if (m == 1)
         return matrix.front ();
      if (n == 1)
         {
            for (int i = 0; i < m; i++)
               {
                  to_ret.push_back (matrix[i][0]);
               }
            return to_ret;
         }

      int i = 0, j = 0;
      // center
      int x = n / 2, y = m / 2;
      std::pair<bool, int> i_left, i_right;
      std::pair<bool, int> j_down, j_up;

      j_up.first = false;
      j_up.second = 0;
      i_left.first = false;
      i_left.second = 0;

      j_down.first = false;
      j_down.second = m - 1;
      i_right.first = true;
      i_right.second = n - 1;

      while (i_right.second != i_left.second && j_down.second != j_up.second)
         {
            to_ret.push_back (matrix[j][i]);
            if (i_right.first)
               {
                  if (i == i_right.second)
                     {
                        i_right.first = false;
                        j_up.second++;
                        j_down.first = true;
                        j++;
                     }
                  else
                     i++;
               }
            else if (j_down.first)
               {
                  if (j == j_down.second)
                     {
                        j_down.first = false;
                        i_right.second--;
                        i_left.first = true;
                        i--;
                     }
                  else
                     j++;
               }
            else if (i_left.first)
               {
                  if (i == i_left.second)
                     {
                        i_left.first = false;
                        j_down.second--;
                        j_up.first = true;
                        j--;
                     }
                  else
                     i--;
               }
            else if (j_up.first)
               {
                  if (j == j_up.second)
                     {
                        j_up.first = false;
                        i_left.second++;
                        i_right.first = true;
                        i++;
                     }
                  else
                     j--;
               }
         }

      if (i_right.first)
         {
            while (j <= j_down.second)
               {
                  to_ret.push_back (matrix[j][i]);
                  j++;
               }
         }
      else if (i_left.first)
         {
            while (j >= j_up.second)
               {
                  to_ret.push_back (matrix[j][i]);
                  j--;
               }
         }
      else if (j_up.first)
         {
            while (i <= i_right.second)
               {
                  to_ret.push_back (matrix[j][i]);
                  i++;
               }
         }
      else
         {
            while (i >= i_left.second)
               {
                  to_ret.push_back (matrix[j][i]);
                  i--;
               }
         }

      return to_ret;
   }
};
