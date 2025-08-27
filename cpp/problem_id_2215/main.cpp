#include <unordered_map>
#include <vector>

class Solution
{
public:
  std::vector<std::vector<int>>
  findDifference (std::vector<int> &nums1, std::vector<int> &nums2)
  {
    const int n = nums1.size ();
    const int m = nums2.size ();

    std::vector<std::vector<int>> res{ {}, {} };

    std::unordered_map<int, bool> mp1, mp2;

    for (int i = 0; i < n; i++)
      mp1[nums1[i]] = true;

    for (int j = 0; j < m; j++)
      mp2[nums2[j]] = true;

    for (auto it = mp1.begin (); it != mp1.end (); it++)
      {
        if (mp2.count (it->first) == 0)
          res[0].push_back (it->first);
      }

    for (auto it = mp2.begin (); it != mp2.end (); it++)
      {
        if (mp1.count (it->first) == 0)
          res[1].push_back (it->first);
      }

    return res;
  }
};
