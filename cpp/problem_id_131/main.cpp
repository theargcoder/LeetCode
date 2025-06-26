#include <string>
#include <string_view>
#include <vector>

class Solution
{
 public:
   std::vector<std::vector<std::string>>
   partition (std::string s)
   {
      std::vector<std::vector<std::string>> res;

      const int n = s.size ();

      std::vector<std::string> tt;

      dfs (s, res, tt);

      return res;
   }

 private:
   void
   dfs (std::string_view s, std::vector<std::vector<std::string>> &res,
        std::vector<std::string> &tt)
   {
      if (s.size () == 0)
         {
            res.push_back (tt);
            return;
         }

      for (int i = 1; i <= s.size (); i++)
         {
            std::string_view ss = s.substr (0, i);
            if (ss.size () == 1 || is_palindrome (ss))
               {
                  tt.push_back (std::string (ss));
                  int rem = s.size () - i;
                  if (rem)
                     dfs (s.substr (i, rem), res, tt);
                  else
                     dfs ("", res, tt);
                  tt.pop_back ();
               }
         }
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
