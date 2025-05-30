#include <unordered_map>
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

// in order = dfs

class Solution
{
 public:
   // second vector not by reference so we can pop_back without altering input
   // vectors in case of later use of these vectors.
   TreeNode *
   buildTree (std::vector<int> &inorder, std::vector<int> postorder)
   {
      int n = inorder.size ();

      std::unordered_map<int, int> tt;
      for (int i = 0; i < n; i++)
         tt[inorder[i]] = i;

      return construct (postorder, tt, 0, n - 1);
   }

 private:
   TreeNode *
   construct (std::vector<int> &postorder,
              const std::unordered_map<int, int> &tt, int ini, int inj)
   {
      if (ini > inj || postorder.empty ())
         return nullptr;

      const int &posbackref = postorder.back ();
      TreeNode *root = new TreeNode (posbackref);
      int rootPos = tt.at (posbackref);
      postorder.pop_back ();

      root->right = construct (postorder, tt, rootPos + 1, inj);
      root->left = construct (postorder, tt, ini, rootPos - 1);

      return root;
   }
};
