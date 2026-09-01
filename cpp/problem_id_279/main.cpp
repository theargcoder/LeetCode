#include <algorithm>
#include <array>
#include <climits>

class Solution
{
private:
  void setup()
  {
    static bool done = false;
    if(done)
    {
      return;
    }
    done = true;

    int n = 1;
    while(n * n <= 10'000)
    {
      DP[n] = (n * n);
      n++;
    }
  }

public:
  static std::array<int, 101> DP;

public:
  int numSquares(const int &n)
  {
    setup();

    int min = INT_MAX;
    const auto range = std::ranges::lower_bound(DP, n);
    dfs(n, 0, min, range);
    return min;
  }

  void dfs(int rem, const int ops, int &min, const auto &range)
  {
    if(rem == 0)
    {
      min = std::min(min, ops);
      return;
    }
    else if(ops > 4 || ops >= min)
    {
      return;
    }

    auto it = std::lower_bound(DP.begin(), range, rem);
    if(*it > rem)
    {
      it--;
    }
    for(; it != DP.begin(); it--)
    {
      dfs(rem - *it, ops + 1, min, it);
    }
  }
};

std::array<int, 101> Solution::DP{};

int main(int argc, char *argv[])
{
  Solution sol;

  const auto res_1 = sol.numSquares(12);
  const auto res_2 = sol.numSquares(48);
  const auto res_3 = sol.numSquares(999);
  const auto res_4 = sol.numSquares(9999);

  return 0;
}
