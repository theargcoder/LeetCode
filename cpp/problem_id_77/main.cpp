#include <vector>

class Solution
{
 private:
   std::vector<int> t;
   std::vector<std::vector<int>> tt;

 private:
   void
   backtrack (int &n, int &k, int i)
   {
      if (t.size () == k)
         {
            tt.push_back (t);
            return;
         }

      for (; i <= n; i++)
         {
            t.push_back (i);
            backtrack (n, k, i + 1);
            t.pop_back ();
         }
   }

 public:
   std::vector<std::vector<int>>
   combine (int n, int k)
   {
      if (n == 1 && k == 1)
         return { { 1 } };

      backtrack (n, k, 1);

      return tt;
   }
};
