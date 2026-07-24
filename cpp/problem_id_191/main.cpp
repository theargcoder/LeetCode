
class Solution
{
public:
  int __attribute((always_inline)) hammingWeight(const int n)
  {
    return __builtin_popcount(static_cast<unsigned>(n));
  }
};
