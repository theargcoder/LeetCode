#include <string>
#include <unordered_map>

class Solution
{
public:
  std::string
  fractionToDecimal (int numerator, int denominator)
  {
    if (!numerator)
      return "0";
    std::unordered_map<std::string, int> used;
    std::string res;

    long long n = numerator;
    long long d = denominator;
    if (n < 0 && d > 0 || n > 0 && d < 0)
      {
        res.push_back ('-');
      }
    n = std::llabs (numerator);
    d = std::llabs (denominator);
    if (n < d)
      {
        n *= 10;
        res.push_back ('0');
        res.push_back ('.');
      }
    else
      {
        long long nu = n / d;
        long long rem = n % d;
        res += std::to_string (nu);
        if (rem)
          res.push_back ('.');
        n = rem * 10;
      }

    while (n)
      {
        std::string key = std::to_string (n) + '+' + std::to_string (d);
        if (used.count (key))

          {
            long long loc = used[key];
            res.insert (res.begin () + loc, '(');
            res.push_back (')');
            break;
          }
        else
          used[key] = res.size ();

        if (n < d)
          {
            n *= 10;
            res.push_back ('0');
          }
        else
          {
            long long nu = n / d;
            long long rem = n % d;
            res += std::to_string (nu);
            n = rem * 10;
          }
      }

    return res;
  }
};
