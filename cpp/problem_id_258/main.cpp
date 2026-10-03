#include <climits>
#include <iostream>

// #pragma GCC optimize("O3", "unroll-loops", "march=native")

auto init = []()
{
  std::ios::sync_with_stdio(false);
  std::cin.tie(nullptr);
  return 0;
}();

class Solution
{
public:
  int addDigits(const int &num)
  {
    const auto billy = num / 1'000'000'000;
    const auto div_10e8 = num / 100'000'000;
    const auto div_10e7 = num / 10'000'000;
    const auto div_10e6 = num / 1'000'000;
    const auto div_10e5 = num / 100'000;
    const auto div_10e4 = num / 10'000;
    const auto div_10e3 = num / 1'000;
    const auto div_10e2 = num / 100;
    const auto div_10e1 = num / 10;

    const auto hmill = div_10e8 - (billy * 10);
    const auto tmill = div_10e7 - (div_10e8 * 10);
    const auto mill = div_10e6 - (div_10e7 * 10);
    const auto htho = div_10e5 - (div_10e6 * 10);
    const auto ttho = div_10e4 - (div_10e5 * 10);
    const auto thou = div_10e3 - (div_10e4 * 10);
    const auto hund = div_10e2 - (div_10e3 * 10);
    const auto tens = div_10e1 - (div_10e2 * 10);
    const auto ones = num - (div_10e1 * 10);

    // 2 + 9*9 < 100
    const auto sum = billy + hmill + tmill + mill + htho + ttho + thou + hund + tens + ones;

    const auto sum_div_10e1 = sum / 10;
    const auto sum_ones = sum - (sum_div_10e1 * 10);

    // may be  < 20 and > 10 so once again
    const auto sum_2 = sum_div_10e1 + sum_ones;

    const auto sum2_div_10e1 = sum_2 / 10;
    const auto sum2_ones = sum_2 - (sum2_div_10e1 * 10);

    return sum2_div_10e1 + sum2_ones;
  }
};

int main(int argc, char *argv[])
{
  Solution sol;

  const auto res_1 = sol.addDigits(38);
  const auto res_2 = sol.addDigits(1'999'999'999);
  const auto res_3 = sol.addDigits(INT_MAX);

  return 0;
}
