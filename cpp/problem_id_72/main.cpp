#include <algorithm>
#include <csignal>
#include <string>
#include <vector>

class Solution
{
 public:
   int
   minDistance (std::string word1, std::string word2)
   {
      const int n = word1.size ();
      const int m = word2.size ();

      std::vector<std::vector<int>> dp (n + 1, std::vector<int> (m + 1));

      // Base cases
      for (int i = 0; i <= n; i++)
         dp[i][0] = i;
      for (int j = 0; j <= m; j++)
         dp[0][j] = j;

      for (int i = 1; i <= n; i++)
         {
            for (int j = 1; j <= m; j++)
               {
                  if (word1[i - 1] == word2[j - 1])
                     dp[i][j] = dp[i - 1][j - 1];
                  else
                     dp[i][j] = std::min ({ dp[i - 1][j] + 1, dp[i][j - 1] + 1,
                                            dp[i - 1][j - 1] + 1 });
               }
         }

      return dp[n][m];
   }
};
