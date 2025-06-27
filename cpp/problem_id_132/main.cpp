#include <algorithm>
#include <climits>
#include <string>
#include <string_view>
#include <unordered_map>

// slow due to hashing but works 100%
/*
class Solution
{
 public:
   int
   minCut (std::string s)
   {
      std::unordered_map<std::string_view, int> memo;
      return dfs (s, memo) - 1;
   }

 private:
   int
   dfs (std::string_view s, std::unordered_map<std::string_view, int> &memo)
   {
      if (s.empty ())
         return 0;

      if (memo.count (s))
         return memo[s];

      int res = INT_MAX;

      for (int i = 1; i <= s.size (); i++)
         {
            std::string_view ss = s.substr (0, i);

            if (is_palindrome (ss))
               {
                  std::string_view ssrem = s.substr (i);
                  int mincuts = 1 + dfs (ssrem, memo);
                  res = std::min (res, mincuts);
               }
         }

      return memo[s] = res;
   }

   bool
   is_palindrome (std::string_view s)
   {
      size_t left = 0;
      size_t right = s.size ();

      while (left < right)
         {
            if (s[left] != s[right - 1])
               return false;
            ++left;
            --right;
         }

      return true;
   }
};
*/

class Solution
{
 public:
   int
   minCut (std::string s)
   {
      std::unordered_map<int, int> memo;
      return dfs (s, memo, 0) - 1;
   }

 private:
   int
   dfs (std::string_view s, std::unordered_map<int, int> &memo, int lvl)
   {
      if (s.empty ())
         return 0;

      if (memo.count (lvl))
         return memo[lvl];

      int res = INT_MAX;

      for (int i = 1; i <= s.size (); i++)
         {
            std::string_view ss = s.substr (0, i);

            if (is_palindrome (ss))
               {
                  std::string_view ssrem = s.substr (i);
                  int mincuts = 1 + dfs (ssrem, memo, lvl + i);
                  res = std::min (res, mincuts);
               }
         }

      return memo[lvl] = res;
   }

   bool
   is_palindrome (std::string_view s)
   {
      size_t left = 0;
      size_t right = s.size ();

      while (left < right)
         {
            if (s[left] != s[right - 1])
               return false;
            ++left;
            --right;
         }

      return true;
   }
};
