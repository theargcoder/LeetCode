#include <deque>
#include <string>

class Solution
{
public:
  std::string
  convertToTitle (int columnNumber)
  {
    std::string res;
    std::deque<char> resq;

    int tmp = -1;
    int n = columnNumber;

    while (n > 0)
      {
        n--;
        tmp = (n % 26);
        resq.push_front (tmp + 'A');
        n /= 26;
      }

    for (const auto &i : resq)
      res.push_back (i);

    return res;
  }
};
