#include <cstdlib>
#include <iostream>
#include <limits>

// talk about inefficient shit
/*
class Solution
{
 public:
   constexpr double
   myPow (double x, int n)
   {
      if (n == 0.0)
         return 1;
      if (x == 0.0)
         return 0.0;
      if (x == 1.0)
         return 1.0;
      if (x == -1.0 && n < 0)
         return 1.0;
      if (x == -1.0 && n > 0)
         return -1.0;
      double to_ret = 1;
      if (n > 0)
         {
            if (x >= 2.0 && n > 1024)
               { // max exponent of a double is 1023 (2^11)
                  // so its pointless to compute anything with higher exponent
                  // jsut make it zero
                  return 0.0;
               }
            while (n > 0)
               {
                  to_ret *= x;
                  n--;
               }
            return to_ret;
         }
      else
         {
            long n1 = ((long)n);
            n1 = std::abs (n1);
            if (x >= 2.0 && n1 > 1024)
               { // max exponent of a double is 1023 (2^11)
                  // so its pointless to compute anything with higher exponent
                  // jsut make it zero
                  return 0.0;
               }
            // faster beacuse multiplication is faster
            while (n1 > 0)
               {
                  to_ret *= x;
                  n1--;
               }
            return 1.0 / to_ret;
         }
   }
};
*/

// well wikepedia had the answer.....
// but i did make it a little faster using
// bitwise divide by 2 (just shift the number by 1 bit to the right)
// also with checking if the LSB is 1 we do
// AND with a 0x1 (aka BINARY 0000000000000000000000000.....1)

class Solution
{
 public:
   constexpr double
   myPow (double x, int n)
   {
      if (n == 0)
         return 1.0;
      if (x == 1.0)
         return 1.0;
      if (x == -1.0)
         return (n % 2 == 0) ? 1.0 : -1.0;

      double result = 1.0;
      long exp = n;
      if (n < 0)
         {
            x = 1.0 / x;
            exp = -exp;
         }

      while (exp > 0)
         {
            if ((exp & 0x1) == 1)
               result *= x; // Multiply when the current bit is 1
            x *= x;         // Square the base
            exp >>= 1;      // Move to the next bit
         }

      return result;
   }
};
