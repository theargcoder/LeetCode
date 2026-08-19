#include <algorithm>
#include <string>
#include <vector>

class Solution
{
private:
  std::vector<int> p;

public:
  std::string shortestPalindrome(const std::string &s)
  {
    const size_t size = s.size();
    std::string ms, to_ret;

    ms.push_back('@');
    for(size_t i = 0; i < size; i++)
    {
      ms.push_back('#');
      ms.push_back(s[i]);
    }
    ms.push_back('#');
    ms.push_back('$');

    const int n = ms.size();
    p.assign(n, 0);
    int l = 0, r = 0;

    for(int i = 1; i < n - 1; ++i)
    {
      int mirror = l + r - i;

      if(i < r)
      {
        p[i] = std::min(r - i, p[mirror]);
      }

      while(ms[i + 1 + p[i]] == ms[i - 1 - p[i]])
      {
        ++p[i];
      }

      if(i + p[i] > r)
      {
        l = i - p[i];
        r = i + p[i];
      }
    }

    int longest = 0;
    for(int i = size - 1; i > 0; i--)
    {
      if(check(i))
      {
        longest = i;
        break;
      }
    }

    for(int i = size - 1; i > longest; i--)
    {
      to_ret.push_back(s[i]);
    }
    to_ret += s;

    return to_ret;
  }

private:
  __attribute__((always_inline)) int getLongest(const int &cen, const bool &even)
  {
    int pos = 2 * cen + 2 + even;
    return p[pos];
  }

  bool check(const int &r)
  {
    const int len = r + 1;
    const int cen = r >> 1U;
    const int longest = getLongest(cen, (len & 0b1) == 0);
    return len <= longest;
  }
};

/* TLE :(
class Solution
{
public:
  std::string shortestPalindrome(const std::string &s)
  {
    const size_t size = s.size();
    std::string res;
    res.reserve(2 * size + 1);
    int i = 0, j = static_cast<int>(size);
    int k, l;

    bool is_odd = (j - i) % 2 != 0;

    while((is_odd && i != j) || (!is_odd && j - i >= 1))
    {
      is_odd = (j - i) % 2 != 0;
      j--;
      k = i, l = j;
      while(((is_odd && k != l) || (!is_odd && l - k >= 1)) && (s[k] == s[l]))
      {
        k++, l--;
      }
      if(k >= l)
      {
        break;
      }
    }

    for(k = size - 1; k > j; k--)
    {
      res.push_back(s[k]);
    }
    res += s;

    return res;
  }
};
*/
