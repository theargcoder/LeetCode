#include <vector>

class Solution
{
 public:
   std::vector<int>
   plusOne (std::vector<int> &digits)
   {
      int i = digits.size () - 1;
      digits[i]++;
      if (digits[i] < 10)
         return digits;

      bool carry = true;
      while (i > 0 && carry)
         {
            digits[i] = 0;
            i--;
            digits[i]++;
            carry = digits[i] > 9;
         }

      if (i == 0 && carry)
         {
            digits[i] = 0;
            digits.insert (digits.begin (), 1);
         }

      return digits;
   }
};
