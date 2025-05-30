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
   levelOrderBottom (TreeNode *root)
   {
      int depth = 0;
      getdepth (root, depth, 1);
      std::vector<std::vector<int>> res (depth);
      depth--;
      dfs (root, res, 0, depth);
      return res;
   }

 private:
   void
   getdepth (TreeNode *root, int &depth, int lvl)
   {
      if (!root)
         return;
      if (lvl > depth)
         depth = lvl;
      getdepth (root->left, depth, lvl + 1);
      getdepth (root->right, depth, lvl + 1);
   }

   void
   dfs (TreeNode *root, std::vector<std::vector<int>> &res, int lvl,
        const int &depth)
   {
      if (!root)
         return;

      res[depth - lvl].push_back (root->val);

      dfs (root->left, res, lvl + 1, depth);
      dfs (root->right, res, lvl + 1, depth);
   }
};
