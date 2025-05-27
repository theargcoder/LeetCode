#include <algorithm>
#include <climits>
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
   recoverTree (TreeNode *root)
   {
      std::vector<int> tt;
      sendlocation (root, tt);
      std::sort (tt.begin (), tt.end ());
      assemble (root, tt);
   }

 private:
   void
   assemble (TreeNode *root, std::vector<int> &tt)
   {
      if (!root)
         return;

      assemble (root->right, tt);
      root->val = tt.back ();
      tt.pop_back ();
      assemble (root->left, tt);
   }

 private:
   void
   sendlocation (TreeNode *root, std::vector<int> &tt)
   {
      if (!root)
         return;

      sendlocation (root->left, tt);
      tt.push_back (root->val);
      sendlocation (root->right, tt);
   }
};

//* O(1) ???
/*
class Solution
{
 public:
   void
   recoverTree (TreeNode *root)
   {
      homeroot = root;
      TreeNode *a = nullptr, *b = nullptr, *nully = nullptr;
      sendlocation (root, LONG_MIN, LONG_MAX, a, nully);
      sendlocation (root, LONG_MIN, LONG_MAX, b, a);
      if (a)
         std::cout << "a = " << a->val << '\n';
      if (b)
         std::cout << "b = " << b->val << '\n';
      if (a && b)
         {
            std::swap (a->val, b->val);
            bool valid = true;
            validate (homeroot, LONG_MIN, LONG_MAX, valid);
            if (valid)
               return;
            else
               std::cout << "shit didnt work \n";
         }
   }

 private:
   TreeNode *homeroot;

   void
   validate (TreeNode *root, long mini, long maxi, bool &ans)
   {
      if (!root)
         return;

      validate (root->left, mini, root->val, ans);
      if (root->val <= mini || root->val >= maxi)
         {
            ans = false;
            return;
         }
      validate (root->right, root->val, maxi, ans);
   }

 private:
   void
   sendlocation (TreeNode *root, long mini, long maxi, TreeNode *&ans,
                 TreeNode *&ignore)
   {
      if (!root)
         return;

      if ((root->val <= mini || root->val >= maxi) && ignore != root)
         {
            ans = root;
            return;
         }

      if (ignore != root)
         {
            sendlocation (root->left, mini, root->val, ans, ignore);
            sendlocation (root->right, root->val, maxi, ans, ignore);
         }
      else
         {
            sendlocation (root->left, mini, maxi, ans, ignore);
            sendlocation (root->right, mini, maxi, ans, ignore);
         }
   }
};
*/
