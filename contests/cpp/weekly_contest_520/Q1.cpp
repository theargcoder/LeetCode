#include <algorithm>
#include <vector>

class Solution
{
public:
  int countIntersectingIntervals(std::vector<std::vector<int>> &intervals)
  {
    int count = 0;

    std::ranges::sort(intervals);

    size_t size = intervals.size();

    for(size_t i = 0; i < size; i++)
    {
      for(size_t j = i + 1; j < size; j++)
      {
        if(intervals[i][1] >= intervals[j][0])
        {
          count++;
        }
      }
    }

    return count;
  }
};
