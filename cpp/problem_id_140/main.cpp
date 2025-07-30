#include <string>
#include <string_view>
#include <unordered_map>
#include <vector>

// working SLOW but no TLE
class Solution
{
 public:
   std::vector<std::string>
   wordBreak (std::string s, std::vector<std::string> &wordDict)
   {
      const int n = wordDict.size ();
      const int s_size = s.size ();

      std::unordered_map<std::string_view, bool> mapit;

      for (int i = 0; i < n; i++)
         mapit[wordDict[i]] = true;

      std::vector<std::string> res, str;

      brickbybrick (s, str, mapit, 0, s_size, res);

      return res;
   }

 private:
   void
   brickbybrick (std::string_view s, std::vector<std::string> &str,
                 std::unordered_map<std::string_view, bool> &mapit, int lvl,
                 const int &s_size, std::vector<std::string> &res)
   {
      if (lvl >= s_size)
         {
            std::string ss;
            for (const auto &stw : str)
               ss += stw + ' ';

            ss.pop_back ();

            res.push_back (ss);
            return;
         }

      for (int i = 1; i <= s_size - lvl; i++)
         {
            std::string_view substr = s.substr (lvl, i);
            if (!mapit.count (substr))
               continue;

            str.push_back (std::string (substr));
            brickbybrick (s, str, mapit, lvl + i, s_size, res);
            str.pop_back ();
         }
   }
};
