#include <math.h>
#include <string>

class Solution
{
public:
  std::string
  reverseWords (std::string s)
  {
    if (s.empty ())
      return s;

    const int n = s.size ();

    std::string res;

    std::string wd;

    res.reserve (std::pow (10, 4));
    wd.reserve (std::pow (10, 4));

    for (int r = n - 1; r >= 0; r--)
      {
        if (s[r] == ' ')
          continue;

        int pr = r;
        while (r > 0 && s[r] != ' ')
          r--;
        int br = r + ((s[r] == ' ') ? 1 : 0);
        while (br <= pr)
          {
            wd.push_back (s[br]);
            br++;
          }

        res += wd + ' ';
        wd.clear ();
      }
    res.pop_back ();

    return res;
  }
};
