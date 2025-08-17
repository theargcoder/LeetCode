#include <algorithm>
#include <unordered_map>
#include <vector>

class Solution
{
public:
  int
  majorityElement (std::vector<int> &nums)
  {
    const int n = nums.size ();

    std::unordered_map<int, int> mapit;

    for (int i = 0; i < n; i++)
      {
        if (mapit.count (nums[i]))
          mapit[nums[i]]++;
        else
          mapit[nums[i]] = 1;
      }

    auto max_it = std::max_element (
        mapit.begin (), mapit.end (),
        [] (const auto &a, const auto &b) { return a.second < b.second; });

    return max_it->first;
  }
};
