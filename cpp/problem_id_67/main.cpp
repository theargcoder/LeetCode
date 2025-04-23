#include <string>

class Solution
{
 public:
   std::string
   addBinary (std::string &a, std ::string &b)
   {

      if (a.size () < b.size ())
         {
            std::string tmp;
            for (int i = 0; i + a.size () < b.size (); i++)
               tmp.push_back ('0');
            a = tmp + a;
         }
      else if (a.size () > b.size ())
         {
            std::string tmp;
            for (int i = 0; i + b.size () < a.size (); i++)
               tmp.push_back ('0');
            b = tmp + b;
         }
      std::string res = a;

      bool carry = false;
      for (int i = a.size () - 1; i >= 0; i--)
         {
            int sum = (a[i] - '0') + (b[i] - '0') + carry;
            if (sum == 3)
               {
                  res[i] = ('1');
                  carry = true;
               }
            else if (sum == 2)
               {
                  res[i] = ('0');
                  carry = true;
               }
            else if (sum == 1)
               {
                  res[i] = ('1');
                  carry = false;
               }
            else
               {
                  res[i] = ('0');
                  carry = false;
               }
         }

      if (carry)
         res.insert (res.begin (), '1');

      return res;
   }
};
