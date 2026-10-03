#include <iostream>
#include <vector>

#pragma GCC optimize("O3", "unroll-loops", "march=native")

auto init = []()
{
  std::ios::sync_with_stdio(false);
  std::cin.tie(nullptr);
  return 0;
}();

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
  std::vector<std::string> binaryTreePaths(const TreeNode *root)
  {
    std::vector<std::string> res;
    std::string puch;
    dfs(res, puch, root);

    return res;
  }

private:
  void dfs(std::vector<std::string> &res, std::string puch, const TreeNode *root)
  {
    if(!root)
    {
      return;
    }

    if(!puch.empty())
    {
      puch.push_back('-');
      puch.push_back('>');
    }
    puch += std::to_string(root->val);

    if(!root->left && !root->right)
    {
      res.push_back(puch);
    }

    dfs(res, puch, root->left);
    dfs(res, puch, root->right);

    for(int i = (root->val < 0) + ((root->val >= 100) ? 3 : (root->val >= 10) ? 2 : 1) + 2; i > 0 && !puch.empty(); i--)
    {
      puch.pop_back();
    }
  }
};
