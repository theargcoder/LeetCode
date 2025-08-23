#include <algorithm>
#include <iterator>
#include <unordered_map>
#include <vector>

// technically working version.
// but TLE
/*
class Solution
{
public:
  int
  maxOperations (std::vector<int> &nums, int k)
  {
    const int n = nums.size ();
    std::sort (nums.begin (), nums.end ());
    std::vector<bool> used (n, false);

    int ct = 0;

    auto beg = nums.begin ();
    auto end = nums.end ();

    int miss, dis1, dis2;
    for (auto it = beg; it != end; it++)
      {
        dis1 = std::distance (beg, it);
        if (used[dis1])
          continue;
        miss = k - *it;
        auto missit = std::lower_bound (beg, end, miss);
        dis2 = std::distance (beg, missit);
        if (dis2 != n && missit != it && *missit == miss)
          {
            while (dis2 < n && used[dis2])
              {
                missit++;
                dis2++;
              }
            if (dis2 == n)
              continue;
            if (missit != it && *missit == miss)
              {
                ct++;
                used[dis1] = true;
                used[dis2] = true;
              }
          }
      }

    return ct;
  }
};
*/

class Solution
{
public:
  int
  maxOperations (std::vector<int> &nums, int k)
  {
    const int n = nums.size ();
    std::unordered_map<int, int> map;
    for (int i = 0; i < n; i++)
      {
        if (map.count (nums[i]))
          map[nums[i]]++;
        else
          map[nums[i]] = 1;
      }

    int ct = 0;

    int miss;
    for (int i = 0; i < n; i++)
      {
        if (map[nums[i]] <= 0)
          continue;

        miss = k - nums[i];

        if (!map.count (miss))
          continue;

        if (map[miss] > 0)
          {
            map[miss]--;
            if (map[nums[i]] > 0)
              {
                map[nums[i]]--;
                ct++;
              }
          }
      }

    return ct;
  }
};
