#include <string>

class Solution
{
public:
  int
  compareVersion (std::string version1, std::string version2)
  {
    const int v1n = version1.size ();
    const int v2n = version2.size ();

    int v1 = 0, v1next;
    int v2 = 0, v2next;

    while (v1 < v1n && v2 < v2n)
      {
        v1next = v1;
        v2next = v2;
        while (v1next < v1n && version1[v1next] != '.')
          v1next++;
        while (v2next < v2n && version2[v2next] != '.')
          v2next++;

        int v1lin = std::stoi (version1.substr (v1, v1next - v1));
        int v2lin = std::stoi (version2.substr (v2, v2next - v2));

        if (v1lin < v2lin)
          return -1;
        else if (v1lin > v2lin)
          return 1;

        v1 = v1next + 1;
        v2 = v2next + 1;
      }

    if (v1 >= v1n && v2 < v2n)
      {
        v2next = v2;
        while (v2next < v2n)
          {
            if (version2[v2next] == '.')
              {
                v2next++;
                continue;
              }
            else if (version2[v2next] != '0')
              return -1;

            v2next++;
          }
        return 0;
      }
    else if (v1 < v1n && v2 >= v2n)
      {
        v1next = v1;
        while (v1next < v1n)
          {
            if (version1[v1next] == '.')
              {
                v1next++;
                continue;
              }
            else if (version1[v1next] != '0')
              return 1;
            v1next++;
          }
        return 0;
      }
    else
      return 0;
  }
};
