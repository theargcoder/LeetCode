#include <array>
#include <cstdint>
#include <iostream>
#include <string>

#pragma GCC optimize("O3", "unroll-loops", "march=native")

auto init = []()
{
  std::ios::sync_with_stdio(false);
  std::cin.tie(nullptr);
  return 0;
}();

class Solution
{
public:
  bool isAnagram(const std::string &s, const std::string &t)
  {
    if(s.size() != t.size())
      return false;

    static std::array<uint16_t, 'z' + 1> chars_s, chars_t;
    chars_s.fill(0);
    chars_t.fill(0);

    for(const char *ptr = &s[0]; ptr != &s[0] + s.size(); ptr++)
    {
      chars_s[*ptr]++;
    }
    for(const char *ptr = &t[0]; ptr != &t[0] + t.size(); ptr++)
    {
      chars_t[*ptr]++;
    }

    return chars_s == chars_t;
  }
};
