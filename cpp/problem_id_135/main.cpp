#include <numeric>
#include <vector>

class Solution
{
 public:
   int
   candy (std::vector<int> &ratings)
   {
      const int n = ratings.size ();
      std::vector<int> DP (n, 1);

      DP[0] = 1;

      for (int i = 1; i < n; i++)
         {
            if (ratings[i] > ratings[i - 1])
               DP[i] = DP[i - 1] + 1;
         }
      for (int i = n - 2; i >= 0; i--)
         {
            if (ratings[i] > ratings[i + 1])
               DP[i] = std::max (DP[i], DP[i + 1] + 1);
         }

      return std::accumulate (DP.begin (), DP.end (), 0);
   }
};
