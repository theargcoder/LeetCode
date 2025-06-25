#include <algorithm>
#include <climits>

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
   maxPathSum (TreeNode *root)
   {
      int mmax = INT_MIN;
      dfs (root, mmax);
      return mmax;
   }

 private:
   int
   dfs (TreeNode *node, int &mmax)
   {
      if (!node)
         return 0;

      int left = std::max (0, dfs (node->left, mmax));
      int right = std::max (0, dfs (node->right, mmax));
      int comb = node->val + left + right;

      mmax = std::max (mmax, comb);

      return node->val + std::max (left, right);
   }
};
