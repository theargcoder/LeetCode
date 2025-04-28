#include <cstddef>
#include <string>
#include <vector>

class Solution
{
 public:
   std::string
   simplifyPath (std::string path)
   {
      const int size = path.size ();

      std::vector<std::string> tt;

      for (int i = 0; i < size; i++)
         {
            if (path[i] != '/')
               continue;

            while (i < size && path[i] == '/')
               i++;
            i--;

            int i_n = i + 1;

            size_t next = path.find ('/', i_n);
            if (next == std::string::npos)
               next = size;

            if (i_n < size && path[i_n] != '.')
               {
                  tt.push_back (path.substr (i_n, next - i_n));
                  i = next - 1;
               }
            else
               {
                  int j = i_n, ct = 0;
                  for (; j < next; j++)
                     {
                        if (path[j] != '.')
                           break;
                        ct++;
                     }
                  if (j == next && ct == 2 && tt.size () != 0)
                     tt.pop_back ();
                  else if (j != next || (j == next && ct > 2))
                     tt.push_back (path.substr (i_n, next - i_n));

                  i = i_n - 1;
               }
         }

      std::string res;

      for (int i = 0; i < tt.size (); i++)
         res += '/' + tt[i];

      if (res.size () == 0)
         res = "/";

      while (res.size () > 1 && res.back () == '/')
         res.pop_back ();

      return res;
   }
};
