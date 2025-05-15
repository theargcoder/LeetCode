#include <array>
#include <climits>
#include <deque>
#include <string>
#include <unordered_map>

// working but takes O(n^2)
/*
class Solution
{
 public:
   std::string
   minWindow (std::string &s, std::string &t)
   {
      const int m = s.size ();
      const int n = t.size ();

      std::unordered_map<char, int> mapit;

      for (int j = 0; j < n; j++)
         {
            mapit[t[j]] = 0;
         }
      for (int j = 0; j < n; j++)
         {
            mapit[t[j]]++;
         }

      auto mapit_cpy = mapit;

      int count = n;
      int beg = 0, end = 0;
      int min_dis = INT_MAX;

      for (int i = 0; i < m; i++)
         {
            if (mapit.count (s[i]) == 0)
               continue;

            int j = i + 1;

            mapit_cpy[s[i]]--;
            count--;
            while (j < m && count != 0)
               {
                  if (mapit_cpy.count (s[j]) != 0 && mapit_cpy[s[j]] > 0)
                     {
                        mapit_cpy[s[j]]--;
                        count--;
                     }
                  j++;
               }
            if (count == 0)
               {
                  if ((j - i) < min_dis)
                     {
                        min_dis = j - i;
                        beg = i;
                        end = j;
                     }
               }
            else
               {
                  break; // reached end with missing shit so we are done not
                         // possible
               }

            count = n;
            mapit_cpy = mapit;
         }

      return s.substr (beg, end - beg);
   };
};
*/

// well well
class Solution
{
 public:
   std::string
   minWindow (std::string &s, std::string &t)
   {
      if (t.empty () || s.empty ())
         return "";

      std::unordered_map<char, int> need, window;
      for (char c : t)
         need[c]++;

      int left = 0, right = 0;
      int valid = 0;
      int minLen = INT_MAX;
      int start = 0;

      while (right < s.size ())
         {
            char &c = s[right];
            right++;
            if (need.count (c))
               {
                  window[c]++;
                  if (window[c] == need[c])
                     valid++;
               }

            // Try to shrink the window from the left
            while (valid == need.size ())
               {
                  if (right - left < minLen)
                     {
                        minLen = right - left;
                        start = left;
                     }
                  char &d = s[left];
                  left++;
                  if (need.count (d))
                     {
                        if (window[d] == need[d])
                           valid--;
                        window[d]--;
                     }
               }
         }

      return (minLen == INT_MAX) ? "" : s.substr (start, minLen);
   }
};
