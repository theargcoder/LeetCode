#include <string>
#include <vector>

class Solution
{
public:
  int
  compress (std::vector<char> &chars)
  {
    const int n = chars.size ();
    if (n == 1)
      return 1;

    char curr = chars[0];
    int ct = 1;
    int ptr = 0;

    for (int i = 1; i < n; i++)
      {
        if (curr == chars[i])
          ct++;
        else if (curr != chars[i])
          {
            if (ct > 1)
              {
                chars[ptr] = curr;
                ptr++;
                std::string num = std::to_string (ct);
                for (int j = 0; j < num.size (); j++, ptr++)
                  chars[ptr] = num[j];
              }
            else
              {
                chars[ptr] = curr;
                ptr++;
              }
            curr = chars[i];
            ct = 1;
          }
      }
    chars[ptr] = curr;
    ptr++;
    if (ct > 1)
      {
        std::string num = std::to_string (ct);
        for (int j = 0; j < num.size (); j++, ptr++)
          chars[ptr] = num[j];
      }

    return ptr;
  }
};
