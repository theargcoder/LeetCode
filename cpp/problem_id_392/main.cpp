#include <string>

class Solution
{
public:
  bool
  isSubsequence (std::string s, std::string t)
  {
    const int m = s.size ();
    const int n = t.size ();

    int j = 0;

    for (int i = 0; i < n; i++)
      {
        if (j >= m)
          return true;
        if (t[i] == s[j])
          j++;
      }

    return j >= m;
  }
};
