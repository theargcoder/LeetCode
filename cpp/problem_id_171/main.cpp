#include <cmath>
#include <string>

class Solution
{
public:
  int
  titleToNumber (std::string columnTitle)
  {
    int res = 0;
    int ct = 0;
    while (!columnTitle.empty ())
      {
        res += std::pow (26, ct) * ((columnTitle.back () - 'A') + 1);
        ct++;
        columnTitle.pop_back ();
      }

    return res;
  }
};
