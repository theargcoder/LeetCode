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
   maxDepth (TreeNode *root)
   {
      int max = 0;

      dfs (root, 1, max);

      return max;
   }

 private:
   void
   dfs (TreeNode *root, const int lvl, int &max)
   {
      if (!root)
         return;

      if (lvl > max)
         max = lvl;

      dfs (root->left, lvl + 1, max);
      dfs (root->right, lvl + 1, max);
   }
};
