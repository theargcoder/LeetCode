#include <unordered_map>
#include <vector>

class Solution
{
public:
  bool
  uniqueOccurrences (std::vector<int> &arr)
  {
    const int n = arr.size ();

    std::unordered_map<int, int> map, mapmap;

    for (int i = 0; i < n; i++)
      {
        if (map.count (arr[i]))
          map[arr[i]]++;
        else
          map[arr[i]] = 1;
      }

    for (auto it = map.begin (); it != map.end (); it++)
      {
        if (mapmap.count (it->second))
          return false;

        mapmap[it->second] = 1;
      }

    return true;
  }
};
