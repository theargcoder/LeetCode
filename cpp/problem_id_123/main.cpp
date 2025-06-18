#include <vector>

class Solution
{
 public:
   int
   maxProfit (std::vector<int> &prices)
   {
      int n = prices.size ();
      if (n == 0)
         return 0;

      std::vector<int> left (n, 0);
      std::vector<int> right (n, 0);

      // LEFT PASS: Max profit by selling up to day i
      int minPrice = prices[0];
      for (int i = 1; i < n; ++i)
         {
            minPrice = std::min (minPrice, prices[i]);
            left[i] = std::max (left[i - 1], prices[i] - minPrice);
         }

      // RIGHT PASS: Max profit by buying from day i onward
      int maxPrice = prices[n - 1];
      for (int i = n - 2; i >= 0; --i)
         {
            maxPrice = std::max (maxPrice, prices[i]);
            right[i] = std::max (right[i + 1], maxPrice - prices[i]);
         }

      int maxProfit = 0;
      for (int i = 0; i < n; ++i)
         maxProfit = std::max (maxProfit, left[i] + right[i]);

      return maxProfit;
   }
};
