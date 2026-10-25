
class Solution
{
public:
  int calculateScore(const int &a, const int &b)
  {
    const int set_a = __builtin_popcount(static_cast<unsigned>(a));
    const int set_b = __builtin_popcount(static_cast<unsigned>(b));

    if(set_a >= set_b)
    {
      return set_a * set_b;
    }
    else
    {
      return set_b / set_a;
    }
  }
};
