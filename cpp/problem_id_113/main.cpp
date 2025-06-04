#include "limits.h"
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
   std::vector<std::vector<int>>
   pathSum (TreeNode *root, int targetSum)
   {
      std::vector<std::vector<int>> res;

      std::vector<int> var;

      dfs (root, targetSum, 0, res, var);

      return res;
   }

 private:
   void
   dfs (TreeNode *root, int &target, int sum,
        std::vector<std::vector<int>> &res, std::vector<int> &var)
   {
      if (!root)
         return;

      sum += root->val;
      var.push_back (root->val);

      if (!root->right && !root->left && sum == target)
         {
            res.push_back (var);
            var.pop_back ();
            return;
         }

      dfs (root->left, target, sum, res, var);
      dfs (root->right, target, sum, res, var);

      var.pop_back ();
   }
};
