#include <algorithm>
#include <string>
#include <unordered_map>
#include <vector>

class Solution
{
public:
  bool
  closeStrings (std::string word1, std::string word2)
  {
    const int n1 = word1.size ();
    const int n2 = word2.size ();

    if (n1 != n2)
      return false;
    if (n1 == 0)
      return word1[0] == word2[0];

    std::unordered_map<char, bool> map1, map2;

    for (int i = 0; i < n1; i++)
      {
        if (!map1.count (word1[i]))
          map1[word1[i]] = true;

        if (!map2.count (word2[i]))
          map2[word2[i]] = true;
      }

    if (map1 != map2)
      return false;

    std::sort (word1.begin (), word1.end ());
    std::sort (word2.begin (), word2.end ());
    std::vector<int> s1, s2;

    int f1 = 1, f2 = 1;
    char a = word1[0], b = word2[0];
    for (int i = 1; i < n1; i++)
      {
        if (a == word1[i])
          f1++;
        else
          s1.push_back (f1), f1 = 1, a = word1[i];

        if (b == word2[i])
          f2++;
        else
          s2.push_back (f2), f2 = 1, b = word2[i];
      }
    s1.push_back (f1);
    s2.push_back (f2);

    std::sort (s1.begin (), s1.end ());
    std::sort (s2.begin (), s2.end ());

    return s1 == s2;
  }
};
