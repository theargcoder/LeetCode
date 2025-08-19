class Solution
{
public:
  int
  trailingZeroes (int n)
  {
    if (n < 5)
      return 0;

    int base = n;
    int ct = 1;
    while (base)
      {
        base /= 5;
        ct += base;
      }

    return ct;
  }
};
