#include <algorithm>
#include <queue>
#include <string>
#include <unordered_map>

class Solution
{
public:
  int
  maxVowels (std::string s, int k)
  {
    const int n = s.size ();
    std::queue<char> que;
    std::unordered_map<char, bool> vowels = {
      { 'a', true }, { 'e', true }, { 'i', true }, { 'o', true }, { 'u', true }
    };

    int max = -1;
    int vowlct = 0;

    int i = 0;

    for (; i < k; i++)
      {
        que.push (s[i]);
        if (vowels.count (s[i]))
          vowlct++;
        max = std::max (vowlct, max);
      }

    for (; i < n; i++)
      {
        char ct = que.front ();
        que.pop ();
        if (vowels.count (ct))
          vowlct--;
        que.push (s[i]);
        if (vowels.count (s[i]))
          vowlct++;
        max = std::max (vowlct, max);
      }

    return max;
  }
};
