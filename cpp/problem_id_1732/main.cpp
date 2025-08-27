#include <algorithm>
#include <climits>
#include <vector>

class Solution
{
public:
  int
  largestAltitude (std::vector<int> &gain)
  {
    const int n = gain.size ();
    int alt = 0;
    int max = INT_MIN;

    for (int i = 0; i < n; i++)
      alt += gain[i], max = std::max (max, alt);

    return max;
  }
};
