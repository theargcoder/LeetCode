#include <algorithm>
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
  int countDominantNodes(TreeNode *root)
  {
    int count = 0;

    dfs(root, count);

    return count;
  }

  int dfs(TreeNode *head, int &count)
  {
    if(!head)
    {
      return 0;
    }
    else if(!head->left && !head->right)
    {
      count++;
      return head->val;
    }

    int max = std::max(dfs(head->left, count), dfs(head->right, count));

    if(head->val >= max)
    {
      count++;
      return head->val;
    }

    return max;
  }
};
