#include <algorithm>
#include <queue>
#include <set>
#include <vector>

// works but slowish
/*
class Solution
{
 public:
   int
   longestConsecutive (std::vector<int> &nums)
   {
      const int n = nums.size ();

      if (n == 0)
         return 0;
      if (n == 1)
         return 1;

      std::priority_queue<int, std::vector<int>> pq;
      std::set<int> srt;

      for (int i = 0; i < n; i++)
         srt.insert (nums[i]);

      auto it = srt.begin ();
      auto end = srt.end ();
      int prev = *it, ct = 0;
      it++;

      for (; it != end; it++)
         {
            if (*it - prev == 1)
               ct++;
            else
               {
                  ct++;
                  pq.push (ct);
                  ct = 0;
               }
            prev = *it;
         }
      ct++;
      pq.push (ct);

      return pq.top ();
   }
};
*/

class Solution
{
 public:
   int
   longestConsecutive (std::vector<int> &nums)
   {
      const int n = nums.size ();

      if (n == 0)
         return 0;
      if (n == 1)
         return 1;

      std::sort (nums.begin (), nums.end ());
      std::priority_queue<int, std::vector<int>> pq;

      auto it = nums.begin ();
      auto end = nums.end ();
      int prev = *it, ct = 0, diff;
      it++;

      for (; it != end; it++)
         {
            diff = *it - prev;
            if (!diff)
               continue;
            else if (diff == 1)
               ct++;
            else
               {
                  ct++;
                  pq.push (ct);
                  ct = 0;
               }
            prev = *it;
         }
      ct++;
      pq.push (ct);

      return pq.top ();
   }
};
