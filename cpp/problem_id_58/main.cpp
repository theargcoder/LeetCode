
#include <cstddef>
#include <string>

class Solution
{
 public:
   int
   lengthOfLastWord (std::string s)
   {

      std::size_t en = s.size () - 1;
      while (s[en] == ' ')
         {
            en--;
         }

      return en - s.rfind (' ', en);
   }
};
