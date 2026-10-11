#include <cstdint>
#include <vector>

constexpr auto LIMIT_N = 1'000'000;
constexpr auto MAX_SIZE = LIMIT_N + 1;

static std::vector<bool> is_prime(MAX_SIZE, true);
static std::vector<int> primes_till_10e6;
static bool done = false;

void build_primes_upto_10e6()
{
  if(done)
    return;

  done = true;

  for(int p = 2; p * p <= LIMIT_N; p++)
  {
    if(is_prime[p] == true)
    {
      for(int i = p * p; i <= LIMIT_N; i += p)
      {
        is_prime[i] = false;
      }
    }
  }

  for(int i = 2; i <= LIMIT_N; i++)
  {
    if(is_prime[i])
    {
      primes_till_10e6.push_back(i);
    }
  }
}

class Solution
{
public:
  std::vector<int> maxPrimes(const int &n, const int &s)
  {
    build_primes_upto_10e6();

    std::vector<int> nums;

    uint64_t accum = 0;
    const uint64_t target = s;
    for(const auto &prime : primes_till_10e6)
    {
      if(prime > n)
        break;

      accum += prime;

      if(accum > target)
        break;

      nums.push_back(prime);
    }

    return nums;
  }
};

int main(int argc, char *argv[])
{
  Solution sol;

  const auto res_1 = sol.maxPrimes(7, 20);

  return 0;
}
