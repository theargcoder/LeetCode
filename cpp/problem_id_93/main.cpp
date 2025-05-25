#include <string>
#include <vector>

class Solution
{
 public:
   std::vector<std::string>
   restoreIpAddresses (std::string s)
   {
      const int n = s.size ();

      std::vector<std::string> res;
      std::vector<int> ip;

      dfs (s, n, res, ip, 0);

      return res;
   }

 private:
   void
   dfs (const std::string &s, const int &n, std::vector<std::string> &res,
        std::vector<int> &ip, int sloc)
   {
      if (ip.size () >= 4)
         {
            if (sloc < n)
               return;
            std::string tp;
            for (int &uchar : ip)
               tp += std::to_string (uchar) + ".";
            tp.pop_back ();
            res.push_back (tp);
         }

      for (int i = sloc; i < n && i < sloc + 3; i++)
         {
            int uchar = std::stoi (s.substr (sloc, i - sloc + 1));
            if (i - sloc >= 1 && s[sloc] == '0')
               break;
            if (uchar >= 256)
               break;
            ip.push_back (uchar);
            dfs (s, n, res, ip, i + 1);
            ip.pop_back ();
         }
   }
};
