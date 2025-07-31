#include <vector>

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
   std::vector<int>
   preorderTraversal (TreeNode *root)
   {
      std::vector<int> res;
      dfs (root, res);

      return res;
   }

 private:
   void
   dfs (TreeNode *root, std::vector<int> &res)
   {
      if (!root)
         return;

      res.push_back (root->val);
      dfs (root->left, res);
      dfs (root->right, res);
   }
};
