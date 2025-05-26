#include <cstddef>
#include <cstdint>
#include <iterator>
#include <unordered_map>
#include <vector>

// slow but functional
/*
class Solution
{
 public:
   int
   numTrees (int n)
   {
      return explore (1, n);
   }

 private:
   int
   explore (int l, int r)
   {
      if (r < l)
         return 1;

      int ct = 0;

      for (int i = l; i <= r; i++)
         {
            ct += explore (l, i - 1) * explore (i + 1, r);
         }

      return ct;
   }
};
*/

class Solution
{
 private:
   std::uint64_t
   hash (const int &one, const int &two) const
   {
      return (static_cast<std::uint64_t> (one) << 32)
             ^ static_cast<std::uint64_t> (two);
   }

 public:
   int
   numTrees (int n)
   {
      std::unordered_map<long, int> memo;
      return explore (memo, 1, n);
   }

 private:
   int
   explore (std::unordered_map<long, int> &memo, int l, int r)
   {
      if (r < l)
         return 1;

      int ct = 0;

      for (int i = l; i <= r; i++)
         {
            const std::size_t lefthash = hash (l, i - 1);
            const std::size_t righthash = hash (i + 1, r);

            if (memo.count (lefthash) == 0)
               memo[lefthash] = explore (memo, l, i - 1);
            if (memo.count (righthash) == 0)
               memo[righthash] = explore (memo, i + 1, r);

            ct += memo[lefthash] * memo[righthash];
         }

      return ct;
   }
};
