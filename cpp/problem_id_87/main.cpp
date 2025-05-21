#include <algorithm>
#include <array>
#include <chrono>
#include <csignal>
#include <iostream>
#include <string>
#include <unordered_map>
#include <vector>

// working but Time Limit Exceeded sadly
/*
class Solution
{
 public:
   bool
   isScramble (std::string &s1, std::string &s2)
   {
      std::string tt = s1;
      return explore (tt, 0, s1.size (), s2);
   }

 private:
   bool
   explore (std::string &con, const int l, const int r, std::string &s2)
   {
      if (con == s2)
         return true;

      for (int i = l + 1; i < r; i++)
         {
            if (explore (con, i, r, s2))
               return true;

            std::string conpy = con;

            std::string swpd = con.substr (i, r - i) + con.substr (l, i - l);

            for (int j = l, c = 0; j < r; j++, c++)
               con[j] = swpd[c];

            if (explore (con, i, r, s2))
               return true;

            con = conpy;
         }

      return false;
   }
};
*/

// 2nd attempt
// BRUH Time limit Exceeded in test case 286 of 290
/*
class Solution
{
 public:
   bool
   isScramble (std::string &s1, std::string &s2)
   {
      if (s1.size () != s2.size ())
         return false;

      auto ss1 = s1, ss2 = s2;
      std::sort (ss1.begin (), ss1.end ());
      std::sort (ss2.begin (), ss2.end ());

      if (ss1 != ss2)
         return false;

      return explore (s1, 0, s1.size (), s2);
   }

 private:
   bool
   explore (std::string &con, const int l, const int r, std::string &s2)
   {
      if (con == s2)
         return true;

      for (int i = l + 1; i < r; i++)
         {
            std::string concpy = con;

            std::string left = con.substr (l, i - l);
            std::string right = con.substr (i, r - i);
            std::string fowleft = s2.substr (l, left.size ());
            std::string fowright = s2.substr (i, right.size ());
            std::string backleft = s2.substr (l, right.size ());
            std::string backright = s2.substr (r - (i - l), i - l);

            std::string swpd = right + left;

            std::sort (left.begin (), left.end ());
            std::sort (right.begin (), right.end ());
            std::sort (fowleft.begin (), fowleft.end ());
            std::sort (fowright.begin (), fowright.end ());
            std::sort (backleft.begin (), backleft.end ());
            std::sort (backright.begin (), backright.end ());

            if (left == fowleft || right == fowright)
               {
                  if (right.size () == 1 && left.size () != 1)
                     {
                        if (explore (con, l, i, s2))
                           return true;
                     }
                  else if (left.size () == 1 && right.size () != 1)
                     {
                        if (explore (con, i, r, s2))
                           return true;
                     }
                  else if (left.size () == 1 && right.size () == 1)
                     {
                        return true;
                     }
                  else
                     {
                        if (explore (con, l, i, s2) && explore (con, i, r, s2))
                           return true;
                     }

                  con = concpy;
               }

            if (left == backright && right == backleft)
               {
                  // Backward match — simulate swap
                  for (int j = l, ct = 0; j < r; ++j, ++ct)
                     con[j] = swpd[ct];

                  if (right.size () == 1 && left.size () != 1)
                     {
                        if (explore (con, l + right.size (), r, s2))
                           return true;
                     }
                  else if (left.size () == 1 && right.size () != 1)
                     {
                        if (explore (con, l, l + right.size (), s2))
                           return true;
                     }
                  else if (left.size () == 1 && right.size () == 1)
                     {
                        return true;
                     }
                  else
                     {
                        if (explore (con, l, l + right.size (), s2)
                            && explore (con, l + right.size (), r, s2))
                           return true;
                     }

                  con = concpy;
               }
         }

      return false;
   }
};
*/

// FAILING IDK why
/*
class Solution
{
 public:
   bool
   isScramble (std::string &s1, std::string &s2)
   {
      if (s1.size () != s2.size ())
         return false;

      return explore (s1, 0, s1.size (), s2);
   }

 private:
   std::unordered_map<std::string, bool> memo;
   bool
   explore (std::string &con, const int l, const int r, std::string &s2)
   {
      if (con == s2)
         return true;
      std::string key = con + "#" + s2;
      if (memo.count (key))
         return memo[key];

      for (int i = l + 1; i < r; i++)
         {
            std::string concpy = con;

            std::string left = con.substr (l, i - l);
            std::string right = con.substr (i, r - i);
            std::string fowleft = s2.substr (l, left.size ());
            std::string fowright = s2.substr (i, right.size ());
            std::string backleft = s2.substr (l, right.size ());
            std::string backright = s2.substr (r - (i - l), i - l);

            std::string swpd = right + left;

            std::sort (left.begin (), left.end ());
            std::sort (right.begin (), right.end ());
            std::sort (fowleft.begin (), fowleft.end ());
            std::sort (fowright.begin (), fowright.end ());
            std::sort (backleft.begin (), backleft.end ());
            std::sort (backright.begin (), backright.end ());

            if (left == fowleft || right == fowright)
               {
                  if (right.size () == 1 && left.size () != 1)
                     {
                        if (explore (con, l, i, s2))
                           return true;
                     }
                  else if (left.size () == 1 && right.size () != 1)
                     {
                        if (explore (con, i, r, s2))
                           return true;
                     }
                  else if (left.size () == 1 && right.size () == 1)
                     {
                        return true;
                     }
                  else
                     {
                        if (explore (con, l, i, s2) && explore (con, i, r, s2))
                           return true;
                     }

                  con = concpy;
               }

            if (left == backright && right == backleft)
               {
                  // Backward match — simulate swap
                  for (int j = l, ct = 0; j < r; ++j, ++ct)
                     con[j] = swpd[ct];

                  if (right.size () == 1 && left.size () != 1)
                     {
                        if (explore (con, l + right.size (), r, s2))
                           return true;
                     }
                  else if (left.size () == 1 && right.size () != 1)
                     {
                        if (explore (con, l, l + right.size (), s2))
                           return true;
                     }
                  else if (left.size () == 1 && right.size () == 1)
                     {
                        return true;
                     }
                  else
                     {
                        if (explore (con, l, l + right.size (), s2)
                            && explore (con, l + right.size (), r, s2))
                           return true;
                     }

                  con = concpy;
               }
         }

      return memo[key] = false;
   }
};
*/

// DFS with memorization
class Solution
{
 public:
   bool
   isScramble (std::string s1, std::string s2)
   {
      if (s1 == s2)
         return true;
      if (s1.length () != s2.length ())
         return false;
      memo.clear ();
      return dfs (s1, s2);
   }

 private:
   std::unordered_map<std::string, bool> memo;

   bool
   dfs (const std::string &s1, const std::string &s2)
   {
      std::string key = s1 + "#" + s2;
      if (memo.count (key))
         return memo[key];

      if (s1 == s2)
         return memo[key] = true;

      // Quick check: if they don't have the same multiset of characters
      std::array<int, 26> count{};
      for (int i = 0; i < s1.size (); ++i)
         {
            count[s1[i] - 'a']++;
            count[s2[i] - 'a']--;
         }
      for (int c : count)
         {
            if (c != 0)
               return memo[key] = false;
         }

      int n = s1.size ();
      for (int i = 1; i < n; ++i)
         {
            // Case 1: No swap
            if (dfs (s1.substr (0, i), s2.substr (0, i))
                && dfs (s1.substr (i), s2.substr (i)))
               return memo[key] = true;

            // Case 2: Swap
            if (dfs (s1.substr (0, i), s2.substr (n - i))
                && dfs (s1.substr (i), s2.substr (0, n - i)))
               return memo[key] = true;
         }

      return memo[key] = false;
   }
};

int
main ()
{
   std::vector<std::vector<std::string>> tests{
      { "great", "rgeat" },
      { "abcde", "caebd" },
      { "a"
        "a" },
      { "ikkcfnqdgjv", "vfnikckjgqd" },
      { "clamsgezsenrisxfwlbefb", "brilbexfwfsalcsnesegzm" },
      { "rqeotslendlmahxhzhhohpqwhdgkmx", "oerqtslamxhedlndgqwhpkmxzhhhho" },
      { "hwgmdxywrpe", "pdwmrgheyxw" },
      { "pjnqigpraynplzfcwagfxvczchajxe", "azwjacglizyvnjappqcfgxhrefcnpx" },
      { "eebaacbcbcadaaedceaaacadccd", "eadcaacabaddaceacbceaabeccd" }
   };

   Solution ss;

   auto st = std::chrono::high_resolution_clock::now ();

   for (int i = 0; i < tests.size (); i++)
      {
         ss.isScramble (tests[i][0], tests[i][1]);
      }
   auto en = std::chrono::high_resolution_clock::now ();

   auto dur = std::chrono::duration_cast<std::chrono::milliseconds> (en - st);

   std::cout << "shit took " << dur.count () << " ms" << '\n';
}
