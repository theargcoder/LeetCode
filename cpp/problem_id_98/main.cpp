#include <algorithm>
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
   bool
   isValidBST (TreeNode *root)
   {
      if (!root)
         return true;

      std::vector<int> tt;
      dfs (root, tt);
      bool sorted = std::is_sorted (tt.begin (), tt.end ());
      if (sorted)
         {
            for (int i = 1; i < tt.size (); i++)
               if (tt[i] == tt[i - 1])
                  return false;

            return true;
         }
      else
         return false;
   }

 private:
   void
   dfs (TreeNode *curr, std::vector<int> &tt)
   {
      if (!curr)
         return;

      dfs (curr->left, tt);
      tt.push_back (curr->val);
      dfs (curr->right, tt);
   }
};
