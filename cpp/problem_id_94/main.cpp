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
   inorderTraversal (TreeNode *root)
   {
      std::vector<int> res;

      bfs (res, root);

      return res;
   }

 private:
   void
   bfs (std::vector<int> &res, const TreeNode *curr)
   {
      if (!curr)
         return;

      bfs (res, curr->left);
      res.push_back (curr->val);
      bfs (res, curr->right);
   };
};
