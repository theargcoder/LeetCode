#include <string>

class Solution
{
public:
  std::string
  mergeAlternately (std::string word1, std::string word2)
  {
    const int n1 = word1.size ();
    const int n2 = word2.size ();
    std::string res;
    res.reserve (n1 + n2);

    int min = std::min (n1, n2);

    for (int i = 0; i < min; i++)
      {
        res.push_back (word1[i]);
        res.push_back (word2[i]);
      }

    if (n1 > n2)
      {
        for (int i = min; i < n1; i++)
          res.push_back (word1[i]);
      }
    else if (n1 < n2)
      {
        for (int i = min; i < n2; i++)
          res.push_back (word2[i]);
      }

    return res;
  }
};
