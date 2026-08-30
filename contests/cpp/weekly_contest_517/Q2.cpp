#include <cmath>
#include <cstdint>
#include <vector>

constexpr uint64_t MOD = 1'000'000'007;

static uint64_t modPow(uint64_t x, uint64_t y)
{
  uint64_t result = 1;

  x %= MOD;

  while(y)
  {
    if(y & 1)
      result = result * x % MOD;

    x = x * x % MOD;
    y >>= 1;
  }

  return result;
}

class Solution
{
public:
  int sumDecoded(const std::vector<long long> &nums)
  {
    uint64_t sum = 0;

    for(const auto &num : nums)
    {
      const uint64_t width = num % 10;
      const uint64_t d = num / 10;
      const uint64_t n_digits = std::log10(d) + 1;

      uint64_t x = d, y = 0;
      uint64_t mod = 1;

      int curr_d = n_digits;
      while(curr_d != width)
      {
        curr_d--;
        mod *= 10;
        x /= 10;
      }

      y = d % mod;

      sum += modPow(x, y);
      sum %= MOD;
    }

    return (int)std::fmod(sum, 1'000'000'007.0);
  }
};

int main(int argc, char *argv[])
{
  Solution sol;

  const auto res_1 = sol.sumDecoded({ 231 });
  const auto res_2 = sol.sumDecoded({ 2522, 2101 });
  const auto res_3 = sol.sumDecoded({ 59412 });

  return 0;
}
