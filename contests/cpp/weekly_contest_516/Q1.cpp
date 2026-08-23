#include <string>

class Solution
{
public:
  bool isPalindromic(const std::string &s)
  {
    std::string spy;

    for(const auto &ch : s)
    {
      unsigned ch_u = static_cast<unsigned>(ch);
      for(int i = 1; i < 0b1'0000'0000; i <<= 1)
      {
        if(ch_u & i)
        {
          spy.push_back('1');
        }
        else
        {
          spy.push_back('0');
        }
      }
    }

    const unsigned size = spy.size();
    int i = 0, j = size - 1;
    while(i < j)
    {
      if(spy[i] != spy[j])
      {
        return false;
      }
      i++, j--;
    }

    return true;
  }
};

int main(int argc, char *argv[])
{
  Solution sol;

  sol.isPalindromic("ff");

  return 0;
}
