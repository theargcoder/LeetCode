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
   int
   minDepth (TreeNode *root)
   {
      int min = INT_MAX;
      dfs (root, min, 1);
      if (min == INT_MAX)
         min = 0;
      return min;
   }

 private:
   void
   dfs (TreeNode *root, int &min, int minv)
   {
      if (!root)
         return;

      if (!root->right && !root->left && minv < min)
         min = minv;

      dfs (root->left, min, minv + 1);
      dfs (root->right, min, minv + 1);
   }
};
