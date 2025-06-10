#include <vector>

class Solution
{
 public:
   std::vector<std::vector<int>>
   generate (int numRows)
   {
      std::vector<std::vector<int>> res{ { 1 } };
      dfs (res, -1, numRows);

      return res;
   }

 private:
   void
   dfs (std::vector<std::vector<int>> &res, int lvl, int &numRows)
   {
      if (lvl >= numRows)
         return;

      std::vector<int> puch = { 1 };
      for (int i = 1; i < res.back ().size (); i++)
         {
            puch.push_back (res.back ()[i - 1] + res.back ()[i]);
         }
      puch.push_back (1);
      res.push_back (puch);

      dfs (res, lvl + 1, numRows);
   }
};
