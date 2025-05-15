#include <algorithm>
#include <unordered_set>
#include <vector>

// working but Time Limit Exceeded
/*
class Solution
{
 private:
   struct VectorHash
   {
      std::size_t
      operator() (const std::vector<int> &vec) const
      {
         std::size_t seed = vec.size ();
         for (auto &i : vec)
            {
               seed ^= std::hash<int> () (i) + 0x9e3779b9 + (seed << 6)
                       + (seed >> 2);
            }
         return seed;
      }
   };

 public:
   std::vector<std::vector<int>>
   subsets (std::vector<int> &nums)
   {
      const int n = nums.size ();
      std::unordered_set<std::vector<int>, VectorHash> tt{ {} };
      std::vector<bool> used (n, false);
      std::vector<int> t;

      do_em (t, tt, used, nums, n);

      std::vector<std::vector<int>> res;

      for (auto &vec : tt)
         {
            res.push_back (vec);
         }

      return res;
   }

 private:
   void
   do_em (std::vector<int> &t,
          std::unordered_set<std::vector<int>, VectorHash> &tt,
          std::vector<bool> &used, const std::vector<int> &nums, const int &n)
   {
      for (int i = 0; i < n; i++)
         {
            if (used[i])
               continue;
            used[i] = true;
            t.push_back (nums[i]);
            auto t_py = t;
            std::sort (t_py.begin (), t_py.end ());
            tt.insert (t_py);
            do_em (t, tt, used, nums, n);
            t.pop_back ();
            used[i] = false;
         }
   }
};
*/

class Solution
{
 public:
   std::vector<std::vector<int>>
   subsets (std::vector<int> &nums)
   {
      const int n = nums.size ();
      std::vector<std::vector<bool>> used (n, std::vector<bool> (n, false));
      std::vector<std::vector<int>> tt{ {} };
      std::vector<int> t;

      dfs (tt, t, used, nums, n, 0, 0);

      return tt;
   }

 private:
   void
   dfs (std::vector<std::vector<int>> &tt, std::vector<int> &t,
        std::vector<std::vector<bool>> &used, const std::vector<int> &nums,
        const int &n, int depth, int loc)
   {
      for (int i = loc; i < n; i++)
         {
            if (used[depth][i])
               continue;
            used[depth][i] = true;
            t.push_back (nums[i]);
            tt.push_back (t);
            dfs (tt, t, used, nums, n, depth + 1, i + 1);
            used[depth][i] = false;
            t.pop_back ();
         }
   }
};
