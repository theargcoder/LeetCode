#include <vector>

class Solution
{
public:
  std::vector<std::vector<int>> combinationSum3(const int &k, const int &n)
  {
    std::vector<std::vector<int>> to_ret;
    std::vector<int> comb;
    int sum = 0;

    dfs(to_ret, comb, k, n, 0, 1, sum);

    return to_ret;
  }

private:
  void dfs(std::vector<std::vector<int>> &to_ret, std::vector<int> &comb, const int &k, const int &n, const int level, const int st_pt, int &sum)
  {
    if(level >= k)
    {
      return;
    }

    for(int i = st_pt; i <= 9; i++)
    {
      comb.push_back(i);
      sum += i;
      if(sum == n && comb.size() == k)
      {
        to_ret.push_back(comb);
        comb.pop_back();
        sum -= i;
        return;
      }
      else
      {
        dfs(to_ret, comb, k, n, level + 1, i + 1, sum);
      }
      sum -= i;
      comb.pop_back();
    }
  }
};
