#include <vector>

struct TreeNode
{
  int val;
  TreeNode *left;
  TreeNode *right;
  TreeNode() : val(0), left(nullptr), right(nullptr)
  {
  }
  TreeNode(int x) : val(x), left(nullptr), right(nullptr)
  {
  }
  TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right)
  {
  }
};

class Solution
{
public:
  int kthSmallest(TreeNode *root, const int &k)
  {
    int curr = 0, res;
    dfs(root, curr, k, res);

    return res;
  }

private:
  void dfs(const TreeNode *root, int &curr, const int &target, int &res)
  {
    if(!root)
    {
      return;
    }

    dfs(root->left, curr, target, res);

    curr++;

    if(curr == target)
    {
      res = root->val;
    }

    dfs(root->right, curr, target, res);
  }
};
