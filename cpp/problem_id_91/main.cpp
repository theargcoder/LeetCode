#include <array>
#include <string>
#include <vector>

class Solution
{
 public:
   int
   numDecodings (std::string s)
   {
      const int n = s.size ();

      if (n == 1)
         return (s[0] == '0') ? 0 : 1;
      if (s[0] == '0')
         return 0;

      int su = 0;
      std::vector<int> suss;
      std::array<int, 3> comb = { 0, 1, 1 };

      for (int i = 0; i < n; i++)
         {
            if (i > 0 && s[i - 1] == '0' && s[i] == '0')
               return 0;

            if (s[i] == '0')
               {
                  if (i > 0 && s[i - 1] >= '3')
                     return 0;
                  if (s[i] >= '3' && i > 0 && s[i - 1] >= '3')
                     return 0;
                  su = 0;

                  suss.push_back (comb[1]);
                  comb = { 0, 1, 1 };
               }
            else if (s[i] > '0' && s[i] <= '2')
               {
                  if (su == 0)
                     {
                        su++;
                        continue;
                     }
                  su++;
                  comb[0] = comb[1];
                  comb[1] = comb[2];
                  comb[2] = comb[0] + comb[1];
               }
            else if (su != 0)
               {
                  su = 0;

                  if (i > 0 && s[i - 1] == '2' && s[i] > '6')
                     {
                        suss.push_back (comb[2]);
                        comb = { 0, 1, 1 };
                     }
                  else
                     {
                        comb[0] = comb[1];
                        comb[1] = comb[2];
                        comb[2] = comb[0] + comb[1];
                        suss.push_back (comb[2]);
                        comb = { 0, 1, 1 };
                     }
               }
         }

      if (comb[0] != 0)
         suss.push_back (comb[2]);
      su = 1;

      for (auto &i : suss)
         su *= i;

      return su;
   }
};
