#include <string>
#include <unordered_map>

class Solution
{
 private:
   long
   hash (const int &a, const int &b) const
   {
      return ((long)a << 32) + b;
   }

 public:
   bool
   isInterleave (std::string s1, std::string s2, std::string s3)
   {
      if (s1.size () + s2.size () != s3.size ())
         return false;
      std::unordered_map<long, bool> memo;
      return dfs (s1, s2, s3, 0, 0, 0, memo);
   }

 private:
   bool
   dfs (const std::string &s1, const std::string &s2, const std::string &s3,
        int i, int j, int k, std::unordered_map<long, bool> &memo)
   {
      if (k == s3.size ())
         return i == s1.size () && j == s2.size ();

      long key = hash (i, j);
      if (memo.count (key))
         return memo[key];

      bool res = false;
      if (i < s1.size () && s1[i] == s3[k])
         {
            res = dfs (s1, s2, s3, i + 1, j, k + 1, memo);
         }
      if (!res && j < s2.size () && s2[j] == s3[k])
         {
            res = dfs (s1, s2, s3, i, j + 1, k + 1, memo);
         }

      return memo[key] = res;
   }
};
