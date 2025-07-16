#include <vector>

class Solution
{
 public:
   int
   canCompleteCircuit (std::vector<int> &gas, std::vector<int> &cost)
   {
      const int n = gas.size ();
      int res = -1;
      std::vector<int> gassy (2 * n), costyy (2 * n);
      int p = n;
      for (int i = 0; i < n; i++)
         {
            gassy[i] = gas[i];
            costyy[i] = cost[i];
         }
      for (int i = 0; i < n; i++, p++)
         {
            gassy[p] = gas[i];
            costyy[p] = cost[i];
            if (gas[i] == 0 || gas[i] - cost[i] < 0)
               continue;
            res = circuit_doable (gassy, costyy, i, p);
            if (res != -1)
               {
                  res = i;
                  break;
               }
         }

      return res;
   }

 private:
   int
   circuit_doable (const std::vector<int> &gas, const std::vector<int> &cost,
                   const int st, const int en)
   {
      int tmp = gas[st];
      for (int i = st; i < en - 1; i++)
         {
            tmp -= cost[i];

            if (tmp < 0)
               return -1;
            tmp += gas[i + 1];
         }

      return (tmp - cost[en - 1] >= 0) ? 1 : -1;
   }
};
