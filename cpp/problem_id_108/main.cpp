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
   TreeNode *
   sortedArrayToBST (std::vector<int> &nums)
   {
      const int n = nums.size ();
      return construct (nums, 0, n - 1);
   }

 private:
   TreeNode *
   construct (const std::vector<int> &nums, int i, int j)
   {
      if (i > j)
         return nullptr;

      int mid = i + ((j - i) / 2);
      TreeNode *root = new TreeNode (nums[mid]);

      root->left = construct (nums, i, mid - 1);
      root->right = construct (nums, mid + 1, j);

      return root;
   }
};
