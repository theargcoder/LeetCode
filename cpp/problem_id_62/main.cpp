#include <cmath>
#include <cstdint>
#include <iostream>
#include <math.h>

class Solution
{
 public:
   int
   uniquePaths (int m, int n)
   {

      long double m_n_fac = factorial (m + n - 2);
      long double m_fac = factorial (m - 1);
      long double n_fac = factorial (n - 1);

      long double div = m_fac * n_fac;

      int res = (int)std::roundl (m_n_fac / div);

      return res;
   }

 private:
   long double
   factorial (long double n)
   {
      long double res = 1;
      while (n > 1)
         {
            res *= n;
            n--;
         }
      return res;
   }
};
