#include <cstring>
#include <vector>

// working submission - 15 ms and 28.74 % beaten
class Solution
{
private:
  int cache[1001][101][2];

public:
  int maxProfit(int k, std::vector<int> &prices)
  {
    const unsigned size = prices.size();

    std::memset(&cache[0][0][false], -1, sizeof(cache));

    return dfs(prices, size, 0, k, false);
  }

private:
  int dfs(std::vector<int> &prices, const unsigned &size, const int i, const int k, const bool holding)
  {
    if(i >= size || k <= 0)
    {
      return 0;
    }
    if(cache[i][k][holding] != -1)
    {
      return cache[i][k][holding];
    }

    int max = 0;
    max = std::max(max, dfs(prices, size, i + 1, k, holding));
    if(holding)
    {
      max = std::max(max, prices[i] + dfs(prices, size, i + 1, k - 1, false));
    }
    else
    {
      max = std::max(max, dfs(prices, size, i + 1, k, true) - prices[i]);
    }

    return cache[i][k][holding] = max;
  }
};

/*
class Solution
{
public:
  int maxProfit(const int &k, std::vector<int> &prices)
  {
    const unsigned size = prices.size();
    std::array<int, 1'000> max_cache;
    max_cache.fill(-1);

    int max = 0;

    for(unsigned i = 0; i < size; i++)
    {
      max = std::max(max, dfs(prices, size, i, k, max_cache));
    }

    return max;
  }

private:
  int dfs(const std::vector<int> &prices, const unsigned &size, const unsigned st_pt, const int k, std::array<int, 1'000> &max_cache)
  {
    if(k <= 0)
    {
      return 0;
    }
    if(max_cache[st_pt] != -1)
    {
      return max_cache[st_pt];
    }

    int max = 0;

    for(unsigned i = st_pt + 1; i < size; i++)
    {
      const int curr_max = prices[i] - prices[st_pt];
      int next_max = 0;
      if(curr_max > 0)
      {
        for(unsigned j = i + 1; j < size; j++)
        {
          next_max = std::max(next_max, dfs(prices, size, j, k - 1, max_cache));
        }
        max = std::max(max, curr_max + next_max);
      }
    }

    max_cache[st_pt] = max;
    return max;
  }
};
*/

/*
class Solution
{
public:
  int maxProfit(const int &k, std::vector<int> &prices)
  {
    const unsigned size = prices.size();
    std::unordered_map<unsigned, int> max_cache;

    int max = 0;

    for(unsigned i = 0; i < size; i++)
    {
      max = std::max(max, dfs(prices, size, i, k, max_cache));
    }

    return max;
  }

private:
  int dfs(const std::vector<int> &prices, const unsigned &size, const unsigned st_pt, const int k, std::unordered_map<unsigned, int> &max_cache)
  {
    if(k <= 0)
    {
      return 0;
    }
    if(max_cache.count(st_pt) != 0)
    {
      return max_cache[st_pt];
    }

    int max = 0;

    for(unsigned i = st_pt + 1; i < size; i++)
    {
      const int curr_max = prices[i] - prices[st_pt];
      int next_max = 0;
      if(curr_max > 0)
      {
        for(unsigned j = i + 1; j < size; j++)
        {
          next_max = std::max(next_max, dfs(prices, size, j, k - 1, max_cache));
        }
        max = std::max(max, curr_max + next_max);
      }
    }

    max_cache[st_pt] = max;
    return max;
  }
};
*/

int main(int argc, char *argv[])
{
  Solution sol;
  std::vector<int> vec = { 5, 2, 3, 0, 3, 5, 6, 8, 1, 5 };
  // std::vector<int> vec = { 3, 2, 6, 5, 0, 3 };
  // std::vector<int> vec = { 2, 4, 1 };

  sol.maxProfit(2, vec);

  return 0;
}
