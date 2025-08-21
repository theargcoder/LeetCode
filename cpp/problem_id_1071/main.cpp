#include <string>
#include <string_view>

class Solution
{
public:
  std::string
  gcdOfStrings (std::string str1, std::string str2)
  {
    const std::string_view s1 = std::string_view (str1);
    const std::string_view s2 = std::string_view (str2);

    std::string res;

    for (int i = 1; i <= s2.size (); i++)
      {
        if (s2.size () % i)
          continue;
        std::string_view ss = s2.substr (0, i);
        bool v1 = valid (s1, ss);
        bool v2 = valid (s2, ss);
        if (v1 && v2)
          res = ss;
      }

    return res;
  }

private:
  bool
  valid (const std::string_view &s, const std::string_view &ss)
  {
    if (ss.empty () || s.size () % ss.size () != 0)
      return false;

    for (size_t i = 0; i < s.size (); i++)
      {
        if (s[i] != ss[i % ss.size ()])
          return false;
      }
    return true;
  }
};
