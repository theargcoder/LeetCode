#include <vector>

class Solution
{
 public:
   std::vector<int>
   grayCode (int n)
   {
      std::vector<int> res{ 0, 1 };

      explore (res, n, 1);

      return res;
   }

 private:
   int i = 2;
   void
   explore (std::vector<int> &res, int &n, int c)
   {
      if (c >= n)
         return;

      const int size = res.size ();

      for (int k = (1 << (c - 1)); k < size; k++)
         {
            if (i < 0)
               {
                  i++;
                  while (i < 2)
                     {
                        res.push_back ((res[k] << 1) + res[i]);
                        i++;
                     }
               }
            else
               {
                  i--;
                  while (i >= 0)
                     {
                        res.push_back ((res[k] << 1) + res[i]);
                        i--;
                     }
               }
         }

      explore (res, n, c + 1);
   }
};
