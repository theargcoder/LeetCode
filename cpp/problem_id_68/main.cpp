#include <math.h>
#include <string>
#include <vector>

class Solution
{
 public:
   std::vector<std::string>
   fullJustify (std::vector<std::string> &words, const int maxWidth)
   {
      const int size = words.size ();

      std::vector<std::string> res, buff;

      int sum = 0;

      for (int i = 0; i < size; i++)
         {
            sum += words[i].size ();
            if (sum <= maxWidth)
               {
                  sum += 1;
                  buff.push_back (words[i]);
                  continue;
               }

            int cumm = 0, count = buff.size () - 1;
            for (int j = 0; j <= count; j++)
               {
                  cumm += buff[j].size ();
               }
            int missing = maxWidth - cumm;

            if (count == 0)
               {
                  std::string puch = buff[count];

                  for (int k = 0; k < missing; k++)
                     {
                        puch.push_back (' ');
                     }
                  res.push_back (puch);
               }
            else
               {
                  int rem = missing % count;
                  if (rem == 0)
                     {
                        int jump = missing / count;

                        std::string puch;

                        for (int j = 0; j < count; j++)
                           {
                              puch += buff[j];
                              for (int k = 0; k < jump; k++)
                                 {
                                    puch.push_back (' ');
                                 }
                           }

                        puch += buff[count];

                        res.push_back (puch);
                     }
                  else
                     {
                        int div = missing / count;

                        std::string puch;

                        for (int j = 0; j < count; j++)
                           {
                              puch += buff[j];
                              int lim = div;
                              if (rem > 0)
                                 {
                                    rem--;
                                    lim++;
                                 }
                              for (int k = 0; k < lim; k++)
                                 {
                                    puch.push_back (' ');
                                 }
                           }

                        puch += buff[count];

                        res.push_back (puch);
                     }
               }

            i--;
            sum = 0;
            buff.clear ();
         }

      std::string puch;

      for (int j = 0; j < buff.size (); j++)
         {
            puch += buff[j] + ' ';
         }
      puch.pop_back ();

      int missing = maxWidth - puch.size ();

      for (int j = 0; j < missing; j++)
         {
            puch += ' ';
         }

      res.push_back (puch);

      return res;
   }
};
