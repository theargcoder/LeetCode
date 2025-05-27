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
   levelOrder (TreeNode *root)
   {
      std::vector<std::vector<int>> res;
      bfs (root, res, 0);
      return res;
   }

 private:
   void
   bfs (TreeNode *curr, std::vector<std::vector<int>> &res, int lvl)
   {
      if (!curr)
         return;

      if (res.size () <= lvl)
         res.push_back ({});

      res[lvl].push_back (curr->val);

      bfs (curr->left, res, lvl + 1);
      bfs (curr->right, res, lvl + 1);
   }
};
