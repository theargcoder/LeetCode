#include <algorithm>
#include <unordered_map>
#include <vector>

class Solution
{
 private:
   struct hash
   {
      std::size_t
      operator() (const std::vector<int> &vec) const
      {
         std::size_t seed = 0;
         for (int i : vec)
            {
               seed ^= std::hash<int>{}(i) + 0x9e3779b9 + (seed << 6)
                       + (seed >> 2);
            }
         return seed;
      }
   };

 public:
   std::vector<std::vector<int>>
   subsetsWithDup (std::vector<int> &nums)
   {
      std::sort (nums.begin (), nums.end ());

      const int n = nums.size ();
      std::vector<std::vector<bool>> used (n, std::vector<bool> (n, false));
      std::vector<std::vector<int>> tt{ {} };
      std::unordered_map<std::vector<int>, bool, hash> vec_used;
      std::vector<int> t;

      dfs (tt, t, used, vec_used, nums, n, 0, 0);

      return tt;
   }

 private:
   void
   dfs (std::vector<std::vector<int>> &tt, std::vector<int> &t,
        std::vector<std::vector<bool>> &used,
        std::unordered_map<std::vector<int>, bool, hash> &vec_used,
        const std::vector<int> &nums, const int &n, int depth, int loc)
   {
      for (int i = loc; i < n; i++)
         {
            if (used[depth][i])
               continue;
            used[depth][i] = true;
            t.push_back (nums[i]);
            if (vec_used.count (t) == 0)
               {
                  vec_used[t] = true;
                  tt.push_back (t);
                  dfs (tt, t, used, vec_used, nums, n, depth + 1, i + 1);
               }
            t.pop_back ();
            used[depth][i] = false;
         }
   }
};
