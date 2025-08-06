#include <cctype>
#include <cmath>
#include <math.h>
#include <stack>
#include <string>
#include <utility>
#include <vector>

class Solution
{
private:
  const bool
  is_digit (const std::string &c)
  {
    if (c[0] == '+' || c[0] == '/' || c[0] == '*')
      return false;
    else if (c[0] == '-' && c.size () == 1)
      return false;
    else
      return true;
  }

public:
  int
  evalRPN (std::vector<std::string> &tokens)
  {
    const int n = tokens.size ();

    std::stack<int> stk;
    for (int i = 0; i < n; i++)
      {
        if (is_digit (tokens[i]))
          stk.push (std::stoi (tokens[i]));
        else
          {

            int b = stk.top ();
            stk.pop ();
            int a = stk.top ();
            stk.pop ();

            int res;

            switch (tokens[i][0])
              {
              case '+':
                {
                  res = a + b;
                  break;
                }
              case '-':
                {
                  res = a - b;
                  break;
                }
              case '*':
                {
                  res = a * b;
                  break;
                }
              case '/':
                {
                  res = std::trunc (a / b);
                  break;
                }
              }
            stk.push (res);
            std::cout << "res = " << res << '\n';
          }
      }

    return stk.top ();
  }
};
