#include <stack>
#include <unordered_map>
struct TreeNode {
  int val;
  TreeNode *left;
  TreeNode *right;
  TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
};

class Solution {
public:
  TreeNode *lowestCommonAncestor(TreeNode *root, TreeNode *p, TreeNode *q) {

    std::stack<TreeNode *> stk;
    dfs(root, stk);

    std::unordered_map<TreeNode *, int> child_p_q;

    TreeNode *res;

    child_p_q[nullptr] = 0;

    while (!stk.empty()) {

      if (stk.top() == p || stk.top() == q)
        child_p_q[stk.top()] =
            1 + child_p_q[stk.top()->left] + child_p_q[stk.top()->right];
      else
        child_p_q[stk.top()] =
            0 + child_p_q[stk.top()->left] + child_p_q[stk.top()->right];

      if (child_p_q[stk.top()] == 2)
        return stk.top();

      stk.pop();
    }

    return nullptr;
  }

private:
  void dfs(TreeNode *root, std::stack<TreeNode *> &stk) {
    if (!root)
      return;

    stk.push(root);
    dfs(root->left, stk);
    dfs(root->right, stk);
  }
};
