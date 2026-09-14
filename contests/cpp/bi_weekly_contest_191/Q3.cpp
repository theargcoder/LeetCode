#include <algorithm>
#include <array>
#include <climits>

class Solution
{
public:
  int minDays(const int n)
  {
    constexpr int INF = INT_MAX;
    constexpr int MAX = 100'000;

    static std::array<int, 2 * MAX> dp;
    static bool init = false;
    if(init)
    {
      return dp[n];
    }
    dp.fill(INF);
    init = true;

    dp[0] = 0;

    for(int k = 1, triag = 0; triag <= MAX; ++k)
    {
      triag += k;
      dp[triag] = k;
    }

    // Add additional streaks.
    for(int k = 1, triag = 0;; ++k)
    {
      triag += k;

      if(triag > MAX)
      {
        break;
      }

      for(int score = 0; score + triag <= MAX; ++score)
      {
        dp[score + triag] = std::min(dp[score + triag], dp[score] + k + 1);
      }
    }

    return dp[n];
  }
};
