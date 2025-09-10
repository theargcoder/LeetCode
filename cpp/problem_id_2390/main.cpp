#include <string>

// USING EXTRA MEMORY (O(n)).
/*
class Solution
{
public:
  std::string
  removeStars (std::string s)
  {
    const int n = s.size ();

    std::string res;
    res.reserve (n);

    for (int i = 0; i < n; i++)
      {
        if (s[i] == '*')
          res.pop_back ();
        else
          res.push_back (s[i]);
      }

    return res;
  }
};
*/

// O(1) SPACE
class Solution
{
public:
  std::string
  removeStars (std::string s)
  {
    const int n = s.size ();

    int pt = 0;

    for (int i = 0; i < n; i++)
      {
        if (s[i] != '*')
          std::swap (s[pt++], s[i]);
        else
          pt--;
      }

    s.erase (pt, n - pt);

    return s;
  }
};
