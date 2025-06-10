#include <climits>
#include <vector>

class Solution
{
 public:
   int
   maxProfit (std::vector<int> &prices)
   {
      const int size = prices.size ();

      int max = INT_MIN;
      int maymin = prices[0], maymax = prices[0];

      for (int i = 0; i < size; i++)
         {
            if (prices[i] < maymin)
               maymax = maymin = prices[i];
            else if (prices[i] > maymax)
               maymax = prices[i];

            max = std::max (max, maymax - maymin);
         }

      return max;
   }
};
