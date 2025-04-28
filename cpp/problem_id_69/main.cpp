#include <climits>
#include <cstdint>
#include <math.h>
#include <vector>

class Solution
{
 public:
   int
   mySqrt (int x)
   {
      if (x == 0)
         return 0;
      if (x == 1)
         return 1;
      if (x == 2)
         return 1;
      if (x == 3)
         return 1;
      if (x == 4)
         return 2;

      std::vector<int> xx;

      std::uint64_t res = 0;
      std::uint64_t i = 2;
      for (; i < INT_MAX && res <= x; i++)
         {
            res = (std::uint64_t)i * i;
         }
      return i - 2;
   }
};
