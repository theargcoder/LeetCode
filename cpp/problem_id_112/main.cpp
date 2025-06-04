#include "limits.h"

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
   hasPathSum (TreeNode *root, int targetSum)
   {
      bool summed = false;
      dfs (root, summed, targetSum, 0);
      return summed;
   }

 private:
   void
   dfs (TreeNode *root, bool &summed, int &target, int sum)
   {
      if (!root || summed)
         return;

      sum += root->val;

      if (!root->right && !root->left && sum == target)
         {
            summed = true;
            return;
         }

      dfs (root->left, summed, target, sum);
      dfs (root->right, summed, target, sum);
   }
};
