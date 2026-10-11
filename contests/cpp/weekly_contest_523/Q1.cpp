#include <array>
#include <cstdint>

class Solution
{
public:
  bool threeFibonacciSum(const int &n)
  {
    const uint64_t input = n;
    std::array<uint64_t, 3> fibonacci;
    fibonacci[0] = 0;
    fibonacci[1] = 0;
    fibonacci[2] = 1;

    while(fibonacci[2] < n)
    {
      const auto fibonnacci_1 = fibonacci[1];
      const auto fibonnacci_2 = fibonacci[2];

      fibonacci[0] = fibonnacci_1;
      fibonacci[1] = fibonnacci_2;
      fibonacci[2] = fibonnacci_1 + fibonnacci_2;

      const auto sum = fibonacci[0] + fibonacci[1] + fibonacci[2];
      if(sum == input)
      {
        return true;
      }
    }

    return false;
  }
};
