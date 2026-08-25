// Definition for a binary tree node.
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
  int countNodes(TreeNode *root)
  {
    if(!root)
    {
      return 0;
    }

    int left_height = 0, right_height = 0;

    auto *leftest = root;
    while(leftest)
    {
      left_height++;
      leftest = leftest->left;
    }

    auto *rightest = root;
    while(rightest)
    {
      right_height++;
      rightest = rightest->right;
    }

    if(left_height == right_height)
    {
      return (int)((1U << (unsigned)left_height) - 1);
    }
    else
    {
      return 1 + countNodes(root->left) + countNodes(root->right);
    }
  }
};
