#include <cmath>
#include <math.h>
#include <vector>

class Solution
{
 public:
   int
   climbStairs (int n)
   {
      if (n == 0)
         return 0;
      int count = 1;
      std::vector<int> ones (n, 1), twos;

      while (ones.size () > 2)
         {
            ones.pop_back ();
            ones.pop_back ();
            twos.push_back (2);
            count += possible (ones.size () + twos.size (), ones.size (),
                               twos.size ());
         }
      if (ones.size () == 2)
         count++;

      return count;
   }

 private:
   int
   possible (const int &max, const int &ones, const int &twos)
   {
      long double num = factorial (max);
      long double denomi = factorial (ones) * factorial (twos);
      long double res_d = num / denomi;
      int res = std::round (res_d);

      return res;
   }

   long double
   factorial (int in)
   {
      long double res = in;
      in--;
      while (in > 1)
         {
            res *= in;
            in--;
         }
      return res;
   }
};
