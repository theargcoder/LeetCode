class Solution
{
public:
  bool canWinNim(int n)
  {
    const int div = n / 4;
    const int mod = n % 4;

    if(div > 0 && mod == 0)
    {
      return false;
    }
    else
    {
      return true;
    }
  }
};
