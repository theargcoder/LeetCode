
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
   isSameTree (TreeNode *p, TreeNode *q)
   {
      bool same = true;
      double_dfs (p, q, same);
      return same;
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

      double_dfs (froot->left, sroot->left, ans);
      ans = ans && froot->val == sroot->val;
      double_dfs (froot->right, sroot->right, ans);
   }
};
