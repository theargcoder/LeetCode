#include <cmath>
#include <string>

struct TreeNode
{
   int val;
   TreeNode *left;
   TreeNode *right;
   TreeNode () : val (0), left (nullptr), right (nullptr) {}
   TreeNode (int x) : val (x), left (nullptr), right (nullptr) {}
   TreeNode (int x, TreeNode *left, TreeNode *right)
       : val (x), left (left), right (right)
   {
   }
};

class Solution
{
 public:
   int
   sumNumbers (TreeNode *root)
   {
      int total = 0;
      std::string tt;
      dfs (root, total, tt, 0);

      return total;
   }

 private:
   void
   dfs (TreeNode *root, int &totalsum, std::string &tt, int lvl)
   {
      if (!root)
         return;

      tt.push_back (root->val + '0');

      if (!root->left && !root->right)
         {
            totalsum += std::stoi (tt);
         }
      else
         {
            dfs (root->left, totalsum, tt, lvl + 1);
            dfs (root->right, totalsum, tt, lvl + 1);
         }
      tt.pop_back ();
   };
};
