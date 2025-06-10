#include <vector>

class Solution
{
 public:
   std::vector<int>
   getRow (int rowIndex)
   {
      if (rowIndex == 0)
         return { 1 };
      else if (rowIndex == 1)
         return { 1, 1 };

      rowIndex++;

      std::vector<int> res (rowIndex), swp (rowIndex);
      res[0] = swp[0] = 1;
      swp[1] = 1;

      dfs (res, swp, rowIndex, 2);

      return res;
   }

 private:
   void
   dfs (std::vector<int> &res, std::vector<int> &swp, int &rowIndex, int lvl)
   {
      if (lvl >= rowIndex)
         return;

      for (int i = 1; i < lvl; i++)
         {
            res[i] = swp[i - 1] + swp[i];
         }
      res[lvl] = 1;
      swp = res;

      dfs (res, swp, rowIndex, lvl + 1);
   }
};
