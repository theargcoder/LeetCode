#include <iostream>
#include <set>
#include <vector>
#pragma GCC optimize("O3", "unroll-loops", "fast-math")

auto init = []()
{
  std::ios::sync_with_stdio(false);
  std::cin.tie(nullptr);
  return 0;
}();

class Solution
{
public:
  std::vector<int> maxSlidingWindow(const std::vector<int> &nums, const int &k)
  {
    std::vector<int> res;
    std::multiset<int> window;

    const size_t size = nums.size();

    for(int i = 0; i < k; i++)
    {
      window.insert(nums[i]);
    }

    res.push_back(*window.rbegin());

    for(size_t left = 0, right = k; right < size; left++, right++)
    {
      window.erase(window.find(nums[left]));
      window.insert(nums[right]);
      res.push_back(*window.rbegin());
    }

    return res;
  }
};
