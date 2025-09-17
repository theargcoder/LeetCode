#include <algorithm>
#include <cctype>
#include <stack>
#include <string>

class Solution
{
public:
  std::string
  decodeString (std::string s)
  {
    std::stack<int> countStack;
    std::stack<std::string> strStack;
    std::string curr = "";
    int num = 0;

    for (char c : s)
      {
        if (isdigit (c))
          {
            num = num * 10 + (c - '0'); // build multi-digit numbers
          }
        else if (c == '[')
          {
            countStack.push (num);
            strStack.push (curr);
            num = 0;
            curr = "";
          }
        else if (c == ']')
          {
            int repeat = countStack.top ();
            countStack.pop ();
            std::string prev = strStack.top ();
            strStack.pop ();
            std::string temp = "";
            for (int i = 0; i < repeat; i++)
              temp += curr;
            curr = prev + temp;
          }
        else
          {
            curr += c; // just add letters
          }
      }
    return curr;
  }
};
