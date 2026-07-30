#include <vector>

class Solution
{
  std::vector<int> primes;

public:
  int countPrimes(const int n)
  {
    std::vector<bool> is_prime(n + 1, true);

    if(n >= 0)
    {
      is_prime[0] = false;
    }
    if(n >= 1)
    {
      is_prime[1] = false;
    }

    for(int p = 2; p * p <= n; p++)
    {
      if(is_prime[p])
      {
        for(int i = p * p; i <= n; i += p)
        {
          is_prime[i] = false;
        }
      }
    }

    int count = 0;
    for(int p = 0; p < n; p++)
    {
      if(is_prime[p])
      {
        count++;
      }
    }

    return count;
  }
};
