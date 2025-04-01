#include <vector>

class Solution
{
 public:
   std::vector<std::vector<int>>
   generateMatrix (int n)
   {
      int nn = n * n;

      std::vector<std::vector<int>> matrix;

      int i = 0, j = 0;

      for (i = 0; i < n; i++)
         {
            matrix.push_back ({});
            for (j = 0; j < n; j++)
               {
                  matrix.back ().push_back (0);
               }
         }

      i = 0, j = 0;

      // center
      int x = n / 2, y = x;
      std::pair<bool, int> i_left, i_right;
      std::pair<bool, int> j_down, j_up;

      j_up.first = false;
      j_up.second = 0;
      i_left.first = false;
      i_left.second = 0;

      j_down.first = false;
      j_down.second = n - 1;
      i_right.first = true;
      i_right.second = n - 1;

      int counter = 1;

      while (i_right.second != i_left.second && j_down.second != j_up.second)
         {
            matrix[j][i] = counter;
            counter++;
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
                  matrix[j][i] = counter;
                  counter++;
                  j++;
               }
         }
      else if (i_left.first)
         {
            while (j >= j_up.second)
               {
                  matrix[j][i] = counter;
                  counter++;
                  j--;
               }
         }
      else if (j_up.first)
         {
            while (i <= i_right.second)
               {
                  matrix[j][i] = counter;
                  counter++;
                  i++;
               }
         }
      else
         {
            while (i >= i_left.second)
               {
                  matrix[j][i] = counter;
                  counter++;
                  i--;
               }
         }

      return matrix;
   }
};
