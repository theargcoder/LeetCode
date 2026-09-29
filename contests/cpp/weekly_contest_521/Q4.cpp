#include <algorithm>
#include <vector>

class Solution
{
private:
  struct m_type
  {
    int left, right;
    long long rev;
  };

public:
  long long maxEarnings(const std::vector<std::vector<int>> &m)
  {
    auto meetings = m;
    const size_t size = meetings.size();
    std::sort(meetings.begin(), meetings.end(), [](const auto &a, const auto &b) { return a[0] < b[0]; });

    std::vector<m_type> stk;
    stk.push_back({ .left = meetings[0][0], .right = meetings[0][1], .rev = meetings[0][2] });

    for(size_t i = 1; i < size; i++)
    {
      while(!stk.empty() && stk.back().right > meetings[i][0] && stk.back().rev < meetings[i][2])
      {
        stk.pop_back();
      }

      if(stk.empty() || stk.back().right <= meetings[i][0])
      {
        stk.push_back({ .left = meetings[i][0], .right = meetings[i][1], .rev = meetings[i][2] });
      }
    }

    long long sum = stk[0].rev;

    for(size_t i = 1; i < stk.size(); i++)
    {
      sum += stk[i].left - stk[i - 1].right;
      sum += stk[i].rev;
    }

    return sum;
  }
};

int main(int argc, char *argv[])
{
  Solution sol;

  const auto res_1 = sol.maxEarnings({ { 7, 13, 10 }, { 4, 7, 8 } });

  return 0;
}
