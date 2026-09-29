//  Definition for a binary tree node.
namespace
{
  struct ListNode
  {
    int val;
    ListNode *next;
    ListNode() = default;
    ListNode(int x) : val(x), next(nullptr) {};
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
  void deleteNode(ListNode *node)
  {
    node->val = node->next->val;
    node->next = node->next->next;
  }
};
