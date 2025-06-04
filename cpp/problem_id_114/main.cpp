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
   void
   flatten (TreeNode *root)
   {
      std::vector<TreeNode *> tt;
      dfs (root, tt);
      TreeNode *tmp = root;
      for (int i = 1; i < tt.size (); i++)
         {
            tmp->right = tt[i];
            tmp->left = nullptr;
            tmp = tmp->right;
         }
   }

 private:
   void
   dfs (TreeNode *root, std::vector<TreeNode *> &tt)
   {
      if (!root)
         return;

      tt.push_back (root);

      dfs (root->left, tt);
      dfs (root->right, tt);
   }
};
