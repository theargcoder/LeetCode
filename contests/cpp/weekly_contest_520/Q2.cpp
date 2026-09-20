#include <algorithm>
#include <vector>

class Solution
{
public:
  long long countIntersectingIntervals(std::vector<std::vector<int>> &intervals)
  {
    long long count = 0;

    std::sort(intervals.begin(), intervals.end());

    size_t size = intervals.size();

    for(auto it = intervals.begin(); it != intervals.end(); it++)
    {
      const int num = (*it)[1];
      const auto upper = std::upper_bound(it + 1, intervals.end(), num, [](const auto &a, const auto &b) { return a < b[0]; });
      const auto ct = static_cast<int>(upper - it) - 1;
      count += (ct < 0) ? 0 : ct;
    }

    return count;
  }
};

int main(int argc, char *argv[])
{
  Solution sol;

  std::vector<std::vector<int>> vec1{ { 1, 2 }, { 2, 3 }, { 3, 4 } };
  const auto res_1 = sol.countIntersectingIntervals(vec1);

  std::vector<std::vector<int>> vec2{ { 1, 5 }, { 2, 4 }, { 3, 6 } };
  const auto res_2 = sol.countIntersectingIntervals(vec2);

  return 0;
}
