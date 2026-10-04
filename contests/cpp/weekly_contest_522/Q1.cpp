#include <string>

class Solution
{
public:
  int minRotations(const std::string &s)
  {
    int count = 0;

    char prev = '0';
    for(const auto &ch : s)
    {
      int fow_ct = 0;
      for(char c = prev; c != ch; c++, fow_ct++)
      {
        if(c > '9')
        {
          c = '0';
          if(c == ch)
            break;
        }
      }

      int rev_ct = 0;
      for(char c = prev; c != ch; c--, rev_ct++)
      {
        if(c < '0')
        {
          c = '9';
          if(c == ch)
            break;
        }
      }

      prev = ch;
      count += std::min(fow_ct, rev_ct);
    }

    return count;
  }
};

int main(int argc, char *argv[])
{
  Solution sol;

  const auto res_1 = sol.minRotations("0192837465");
  const auto res_2 = sol.minRotations("1200210200");

  return 0;
}
