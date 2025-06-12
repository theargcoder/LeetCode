#include <algorithm>
#include <climits>
#include <vector>

class Solution
{
 public:
   int
   maxProfit (std::vector<int> &prices)
   {
      const int n = prices.size ();
      int sum = 0;

      for (int i = 1; i < n; i++)
         {
            if (prices[i - 1] < prices[i])
               sum += prices[i] - prices[i - 1];
         }

      return sum;
   }
};
