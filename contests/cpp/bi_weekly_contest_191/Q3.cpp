#include <algorithm>
#include <climits>
#include <vector>

class Solution
{
public:
  int minDays(const int n)
  {
    constexpr int INF = INT_MAX / 2;

    std::vector<int> dp(n + 1, INF);
    dp[0] = 0;

    for(int k = 1; k * (k + 1) / 2 <= n; ++k)
    {
      const int points = k * (k + 1) / 2;
      const int cost = k + 1;

      for(int score = points; score <= n; ++score)
      {
        dp[score] = std::min(dp[score], dp[score - points] + cost);
      }
    }

    return dp[n] - 1;
  }
};

int main(int argc, char *argv[])
{
  Solution sol;

  const auto res_1 = sol.minDays(2);
  const auto res_2 = sol.minDays(9);
  const auto res_3 = sol.minDays(12);
  const auto res_4 = sol.minDays(10'000);
  const auto res_5 = sol.minDays(53);

  return 0;
}
