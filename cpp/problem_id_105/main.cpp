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
   TreeNode *
   buildTree (std::vector<int> &preorder, std::vector<int> &inorder)
   {
      int n = preorder.size ();

      std::unordered_map<int, int> inorderIndex;
      for (int i = 0; i < n; i++)
         inorderIndex[inorder[i]] = i;

      n--;
      int preIndex = 0;
      int ini = 0;
      return construct (preorder, inorderIndex, preIndex, ini, n);
   }

 private:
   TreeNode *
   construct (const std::vector<int> &preorder,
              const std::unordered_map<int, int> &tt, int &preIndex, int &ini,
              int &inj)
   {
      if (ini > inj)
         return nullptr;

      int rootVal = preorder[preIndex];
      TreeNode *root = new TreeNode (rootVal);

      int rootPos = tt.at (rootVal) - 1;
      preIndex++;

      root->left = construct (preorder, tt, preIndex, ini, rootPos);
      rootPos += 2;
      root->right = construct (preorder, tt, preIndex, rootPos, inj);

      return root;
   }
};
