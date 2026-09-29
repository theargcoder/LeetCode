//  Definition for a binary tree node.
namespace
{
  struct TreeNode
  {
    int val;
    TreeNode *left;
    TreeNode *right;

    TreeNode() = default;
    TreeNode(int x) : val(x), left(nullptr), right(nullptr) {};
  };
} // namespace

#include <iostream>
#pragma GCC optimize("O3", "unroll-loops", "fast-math")

auto init = []()
{
  std::ios::sync_with_stdio(false);
  std::cin.tie(nullptr);
  return 0;
}();

class Solution
{
public:
  TreeNode *lowestCommonAncestor(TreeNode *root, TreeNode *p, TreeNode *q)
  {
    auto *curr = root;
    while(curr)
    {
      const auto equal = p->val == curr->val || q->val == curr->val;
      const auto p_greater = p->val > curr->val;
      const auto q_greater = q->val > curr->val;

      if(equal || p_greater == !q_greater)
      {
        return curr;
      }
      else if(p_greater && q_greater) // both > then go right
      {
        curr = curr->right;
      }
      else // both < go left
      {
        curr = curr->left;
      }
    }

    return nullptr;
  }
};
