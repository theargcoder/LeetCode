#include <cstring>
#include <string>

class Solution
{
public:
  bool isIsomorphic(const std::string &A, const std::string &B)
  {
    char map_a[128 + 1];
    char map_b[128 + 1];

    const unsigned s_size = A.size();
    const unsigned t_size = B.size();

    std::memset(&map_a[0], 0, sizeof(map_a));
    std::memset(&map_b[0], 0, sizeof(map_b));

    for(unsigned i = 0; i < s_size; i++)
    {
      if(map_a[A[i]] == 0 && map_b[B[i]] == 0)
      {
        map_a[A[i]] = B[i];
        map_b[B[i]] = A[i];
      }

      if(map_a[A[i]] != B[i] || map_b[B[i]] != A[i])
      {
        return false;
      }
    }

    return true;
  }
};
