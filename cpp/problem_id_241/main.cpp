#include <string>
#include <string_view>
#include <unordered_map>
#include <vector>

int do_op(const int &A, const char &op, const int &B)
{
  switch(op)
  {
  case '+':
    return A + B;
    break;
  case '-':
    return A - B;
    break;
  case '*':
    return A * B;
  default:
    return 0;
  }
}

class Solution
{
private:
  std::unordered_map<std::string_view, std::vector<int>> memo;

public:
  std::vector<int> diffWaysToCompute(const std::string &expression)
  {
    memo.clear();
    return dfs(expression);
  }

private:
  std::vector<int> dfs(std::string_view str)
  {
    if(memo.contains(str))
    {
      return memo[str];
    }

    for(size_t i = 0; i < str.size(); i++)
    {
      if(str[i] == '*' || str[i] == '-' || str[i] == '+')
      {
        const auto l_vals = dfs(std::string_view(str.begin(), str.begin() + i));
        const auto r_vals = dfs(std::string_view(str.begin() + i + 1, str.end()));

        for(const auto &a : l_vals)
        {
          for(const auto &b : r_vals)
          {
            memo[str].push_back(do_op(a, str[i], b));
          }
        }
      }
    }

    if(memo[str].empty())
    {
      int num = 0;
      for(const char &ch : str)
      {
        num = (num * 10) + (ch - '0');
      }
      memo[str].push_back(num);
    }

    return memo[str];
  }
};

int main(int argc, char *argv[])
{
  Solution sol;

  const auto res_1 = sol.diffWaysToCompute("2-1-1");
  const auto res_2 = sol.diffWaysToCompute("2*3-4*5");

  return 0;
}
