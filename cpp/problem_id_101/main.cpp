
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
   isSymmetric (TreeNode *root)
   {
      if (!root)
         return true;
      bool simmetric = true;
      double_dfs (root->left, root->right, simmetric);
      return simmetric;
   }

 private:
   void
   double_dfs (TreeNode *froot, TreeNode *sroot, bool &ans)
   {
      if (!ans)
         return;
      if (!froot && !sroot)
         return;

      if (!froot && sroot)
         {
            ans = false;
            return;
         }
      if (froot && !sroot)
         {
            ans = false;
            return;
         }

      double_dfs (froot->left, sroot->right, ans);
      ans = ans && froot->val == sroot->val;
      double_dfs (froot->right, sroot->left, ans);
   }
};
