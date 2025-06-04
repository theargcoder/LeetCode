#include <algorithm>

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
   bool
   isBalanced (TreeNode *root)
   {

      bool balance = true;
      int ldp = 0;
      figure (root, ldp, balance);
      return balance;
   }

 private:
   void
   figure (const TreeNode *root, int &dp, bool &res)
   {
      if (!root)
         return;

      dp++;
      int ldp = 0, rdp = 0;
      figure (root->left, ldp, res);
      figure (root->right, rdp, res);

      if (!res)
         return;

      if (std::abs (rdp - ldp) > 1)
         {
            res = false;
            return;
         }
      else
         dp += std::max (ldp, rdp);
   }
};
