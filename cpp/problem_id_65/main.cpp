#include <string>

class Solution
{
 public:
   bool
   isNumber (std::string s)
   {
      const uint size = s.size ();
      bool pused = false, eused = false;

      bool digit = false;

      for (int i = 0; i < size; i++)
         {
            if (s[i] >= '0' && s[i] <= '9')
               {
                  digit = true;
                  continue;
               }

            if (s[i] == '.')
               {
                  if (pused)
                     return false;
                  if (eused)
                     return false;
                  else
                     {
                        pused = true;
                     }
               }
            else if (s[i] == '+' || s[i] == '-')
               {
                  if (i == 0)
                     continue;
                  if (s[i - 1] != 'e' && s[i - 1] != 'E')
                     return false;
               }
            else if (s[i] == 'e' || s[i] == 'E')
               {
                  if (eused)
                     return false;
                  if (i == 0)
                     return false;

                  digit = false;

                  char prev = s[i - 1];
                  bool digitBefore = std::isdigit (prev);
                  bool dotThenDigit
                      = (prev == '.' && i >= 2 && std::isdigit (s[i - 2]));

                  if (!(digitBefore || dotThenDigit))
                     return false;

                  eused = true;
               }
            else
               {
                  return false;
               }
         }

      return digit;
   }
};
