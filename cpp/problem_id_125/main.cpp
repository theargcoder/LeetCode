#include <cctype>
#include <deque>
#include <string>

class Solution
{
 public:
   bool
   isPalindrome (std::string &s)
   {
      std::deque<char> ss;
      const int n = s.size ();

      for (int i = 0; i < n; i++)
         if (std::isalnum (s[i]))
            ss.push_back (std::tolower (s[i]));

      while (!ss.empty () && ss.size () > 1)
         {
            char cf = ss.front ();
            char cb = ss.back ();

            ss.pop_front ();
            ss.pop_back ();

            if (cf != cb)
               return false;
         }

      return ss.size () <= 1;
   }
};
