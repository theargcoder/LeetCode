#include <cstdlib>

// 2026-07-23 20:39 this should wourk in C++29 ... thats in like 5 years but whatever
/*&
#include <bit>
class Solution
{
public:
  int reverseBits(const int n)
  {
    return std::bit_reverse(static_cast<unsigned>(n), 31);
  }
};
*/

// beats 100% 0ms 32 * 9 ops
class Solution
{
public:
  int reverseBits(const int n)
  {
    unsigned n_n = n, res = 0;
    unsigned unsigned_c, temp1, temp2, temp3;
    int signed_c;

    for(unsigned i = 0; i < 32U; i++)
    {
      unsigned_c = 31U - i;
      temp1 = 1U << unsigned_c;
      temp2 = n_n & (1U << i);
      signed_c = static_cast<int>(unsigned_c) - i;
      if(signed_c > 0)
      {
        temp3 = temp2 << signed_c;
      }
      else
      {
        temp3 = temp2 >> std::abs(signed_c);
      }
      res |= temp1 & temp3;
    }

    return res;
  }
};
