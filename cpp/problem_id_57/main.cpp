#include <algorithm>
#include <vector>

class Solution
{
 public:
   std::vector<std::vector<int>>
   insert (std::vector<std::vector<int>> &intervals,
           std::vector<int> &newInterval)
   {
      auto up_bd = std::upper_bound (
          intervals.begin (), intervals.end (), newInterval[0],
          [] (const auto &a, const auto &b) { return a < b[0]; });

      intervals.insert (up_bd, newInterval);

      std::vector<std::vector<int>> vect = { intervals[0] };

      int i, j = 0;

      for (i = 1; i < intervals.size (); i++)
         {
            if (vect[j][1] >= intervals[i][0])
               {
                  vect[j][1] = std::max (intervals[i][1], vect[j][1]);
               }
            else
               {
                  vect.push_back (intervals[i]);
                  j++;
               }
         }

      return vect;
   }
};
