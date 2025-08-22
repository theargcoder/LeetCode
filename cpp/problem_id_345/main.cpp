#include <string>
#include <unordered_map>

class Solution
{
public:
  std::string
  reverseVowels (std::string s)
  {
    const int n = s.size ();
    std::unordered_map<char, bool> vowel{ { 'a', true }, { 'e', true },
                                          { 'i', true }, { 'o', true },
                                          { 'u', true }, { 'A', true },
                                          { 'E', true }, { 'I', true },
                                          { 'O', true }, { 'U', true } };

    std::string sv;
    s.reserve (n); // worst case

    for (int i = 0; i < n; i++)
      {
        if (vowel.count (s[i]))
          sv.push_back (s[i]);
      }
    for (int i = 0; i < n; i++)
      {
        if (vowel.count (s[i]))
          {
            s[i] = sv.back ();
            sv.pop_back ();
          }
      }

    return s;
  }
};
