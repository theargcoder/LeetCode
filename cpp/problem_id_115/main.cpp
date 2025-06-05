#include <string>
#include <vector>

// Time Limit Exceeded
/*
class Solution
{
 public:
   int
   numDistinct (const std::string &s, const std::string &t)
   {
      int count = 0;
      addtocount (count, s, t, s.size (), t.size (), 0, 0);

      return count;
   }

 private:
   void
   addtocount (int &ct, const std::string &s, const std::string &t,
               const int &sn, const int &tn, int si, int ti)
   {
      if (ti >= tn)
         {
            ct++;
            return;
         }
      while (si < sn)
         {
            if (s[si] == t[ti])
               {
                  addtocount (ct, s, t, sn, tn, si + 1, ti + 1);
               }
            si++;
         }
   }
};
*/

// chatGPT solution
/*
class Solution
{
 public:
   int
   numDistinct (const std::string &s, const std::string &t)
   {
      int count = 0;

      const int n = s.size (), m = t.size ();

      std::vector<std::array<int, 'z' + 1>> ss (n + 1,
                                                std::array<int, 'z' + 1>{});
      std::vector<std::array<int, 'z' + 1>> tt (m + 1,
                                                std::array<int, 'z' + 1>{});

      for (int i = 0; i < m; i++)
         {
            for (int j = i; j < m; j++)
               {
                  tt[i][t[j]]++;
               }
         }

      for (int i = 0; i < n; i++)
         {
            for (int j = i; j < n; j++)
               {
                  ss[i][s[j]]++;
               }
         }

      addtocount (count, s, t, ss, tt, n, m, 0, 0);

      return count;
   }

 private:
   bool
   compare (const std::array<int, 'z' + 1> &ss,
            const std::array<int, 'z' + 1> &tt)
   {
      for (int i = 'a'; i <= 'z'; i++)
         if (ss[i] < tt[i])
            return false;

      return true;
   }

 private:
   void
   addtocount (int &ct, const std::string &s, const std::string &t,
               std::vector<std::array<int, 'z' + 1>> &ss,
               std::vector<std::array<int, 'z' + 1>> &tt, const int &sn,
               const int &tn, int si, int ti)
   {
      if (ti >= tn)
         {
            ct++;
            return;
         }
      while (si < sn)
         {
            if (s[si] == t[ti])
               {
                  if (compare (ss[si], tt[ti]))
                     addtocount (ct, s, t, ss, tt, sn, tn, si + 1, ti + 1);
                  else
                     return;
               }
            si++;
         }
   }
};
*/

class Solution
{
 public:
   int
   numDistinct (const std::string &s, const std::string &t)
   {
      int n = s.size (), m = t.size ();
      std::vector<std::vector<int>> memo (n + 1, std::vector<int> (m + 1, -1));
      return count (s, t, 0, 0, memo);
   }

 private:
   int
   count (const std::string &s, const std::string &t, int i, int j,
          std::vector<std::vector<int>> &memo)
   {
      if (j == t.size ())
         return 1;
      if (i == s.size ())
         return 0;

      if (memo[i][j] != -1)
         return memo[i][j];

      if (s[i] == t[j])
         {
            // match or skip
            memo[i][j] = count (s, t, i + 1, j + 1, memo)
                         + count (s, t, i + 1, j, memo);
         }
      else
         {
            // must skip s[i]
            memo[i][j] = count (s, t, i + 1, j, memo);
         }

      return memo[i][j];
   }
};
