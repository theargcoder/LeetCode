#include <cmath>
#include <set>
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

////////////////////////////////////////
// working but SLOW
////////////////////////////////////////

class Solution
{
 public:
   std::vector<TreeNode *>
   generateTrees (int n)
   {
      std::vector<TreeNode *> res;
      std::set<long> memo;
      std::vector<int> tt;
      std::vector<bool> used (n + 1, false);

      int c = 0;

      expand (res, memo, used, tt, c, n);

      return res;
   }

 private:
   long
   hashTree (TreeNode *root)
   {
      if (!root)
         return 0;

      // Use prime multipliers to reduce collisions
      long leftHash = hashTree (root->left);
      long rightHash = hashTree (root->right);
      long val = static_cast<long> (root->val);

      return val + 31 * leftHash + 179 * rightHash;
   }

   void
   deleteTree (TreeNode *node)
   {
      if (!node)
         return;
      deleteTree (node->left);
      deleteTree (node->right);
      delete node;
   }

   TreeNode *
   insert (TreeNode *root, const int &val)
   {
      if (!root)
         return new TreeNode (val);

      if (val < root->val)
         root->left = insert (root->left, val);
      else
         root->right = insert (root->right, val);

      return root;
   }

   void
   expand (std::vector<TreeNode *> &res, std::set<long> &memo,
           std::vector<bool> &used, std::vector<int> &tt, int &c, const int &n)
   {
      if (c >= n)
         {

            TreeNode *tr = new TreeNode (tt.front ());

            for (int i = 1; i < tt.size (); i++)
               insert (tr, tt[i]);

            long v_hash = hashTree (tr);

            if (memo.count (v_hash) == 0)
               {
                  memo.insert (v_hash);
                  res.push_back (tr);
               }
            else
               deleteTree (tr);

            return;
         }

      for (int i = 1; i <= n; i++)
         {
            if (used[i])
               continue;

            used[i] = true;
            tt.push_back (i);
            c++;
            expand (res, memo, used, tt, c, n);
            c--;
            tt.pop_back ();
            used[i] = false;
         }
   }
};
