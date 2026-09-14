#include <cstdlib>

class Solution
{
public:
  bool isPowerOfTwo(int n)
  {
    return (n <= 0) ? false : __builtin_popcount(static_cast<unsigned>(n)) == 1;
  }
};
