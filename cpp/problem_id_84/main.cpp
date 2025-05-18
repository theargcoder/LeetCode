#include <algorithm>
#include <climits>
#include <cstdint>
#include <deque>
#include <functional>
#include <queue>
#include <stack>
#include <utility>
#include <vector>

// works like money just stack overflow :(
/*
class Solution
{
 public:
   int
   largestRectangleArea (std::vector<int> &heights)
   {
      const int n = heights.size ();

      const int maxh = *std::max_element (heights.begin (), heights.end ());

      return explore (heights, n, maxh, 0, 0);
   }

 private:
   int
   explore (const std::vector<int> &heights, const int &n, const int &maxh,
            int bar, int i)
   {
      if (bar >= maxh)
         return 0;

      int min = bar, max = 0;
      for (; i < n; i++)
         {
            if (heights[i] < bar)
               {
                  max = std::max (max, explore (heights, n, maxh, bar, i + 1));
                  break;
               }
            min = std::min (min, heights[i]);
            max = std::max (max, max + min);
         }

      return std::max (max, explore (heights, n, maxh, bar + 1, 0));
   }
};
*/

// working but bearly scraping by in time
/*
class Solution
{
 public:
   int
   largestRectangleArea (std::vector<int> &heights)
   {
      const int n = heights.size ();

      int min = INT_MAX, max = 0;

      std::vector<int> arrymins (n, INT_MAX);

      for (int i = 0; i < n; i++)
         {
            for (int j = 0; j <= i; j++)
               {
                  if (arrymins[j] != 0)
                     {
                        arrymins[j] = std::min (arrymins[j], heights[i]);
                        max = std::max (max, arrymins[j] * (i - j + 1));
                     }
               }
         }

      return max;
   }
};
*/

// MAYBE
class Solution
{
 public:
   int
   largestRectangleArea (std::vector<int> &heights)
   {
      int n = heights.size ();
      std::stack<int> stk;
      int maxArea = 0;

      // Add a sentinel value (0 height) at the end to flush the stack
      heights.push_back (0);

      for (int i = 0; i < heights.size (); i++)
         {
            while (!stk.empty () && heights[i] < heights[stk.top ()])
               {
                  int h = heights[stk.top ()];
                  stk.pop ();
                  int width = stk.empty () ? i : i - stk.top () - 1;
                  maxArea = std::max (maxArea, h * width);
               }
            stk.push (i);
         }

      return maxArea;
   }
};
