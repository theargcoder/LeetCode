#include <string>
#include <string_view>
#include <unordered_map>
#include <vector>

class Solution
{
 public:
   bool
   wordBreak (std::string s, std::vector<std::string> &wordDict)
   {
      const int n = wordDict.size ();
      const int s_size = s.size ();

      std::unordered_map<std::string_view, bool> mapit;

      for (int i = 0; i < n; i++)
         mapit[wordDict[i]] = true;

      std::unordered_map<int, bool> memo;

      return brickbybrick (s, mapit, 0, s_size, memo);
   }

 private:
   bool
   brickbybrick (std::string_view s,
                 std::unordered_map<std::string_view, bool> &mapit, int lvl,
                 const int &s_size, std::unordered_map<int, bool> &memo)
   {
      if (lvl >= s_size)
         return true;

      if (memo.count (lvl))
         return memo[lvl];

      for (int i = 1; i <= s_size - lvl; i++)
         {
            std::string_view substr = s.substr (lvl, i);
            if (mapit.count (substr)
                && brickbybrick (s, mapit, lvl + i, s_size, memo))
               return memo[lvl] = true;
         }

      return memo[lvl] = false;
   }
};
