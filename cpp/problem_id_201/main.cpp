
/* 0ms beats 100% */
class Solution
{
public:
  int rangeBitwiseAnd(const int &l, const int &r)
  {
    const unsigned left = l, right = r;

    unsigned i = 31;
    for(; i > 0; i--)
    {
      if((left >> i) == (right >> i))
      {
        continue;
      }
      else
      {
        break;
      }
    }

    return (int)((left >> i) << i);
  }
};
