#include <climits>

struct TreeNode {
  int val;
  TreeNode *left;
  TreeNode *right;
  TreeNode() : val(0), left(nullptr), right(nullptr) {}
  TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
  TreeNode(int x, TreeNode *left, TreeNode *right)
      : val(x), left(left), right(right) {}
};

class Solution {
public:
  int goodNodes(TreeNode *root) {
    int max = INT_MIN;
    int ct = 0;

    dfs(root, max, ct);

    return ct;
  }

private:
  void dfs(TreeNode *root, int &max, int &ct) {
    if (!root)
      return;

    if (root->val >= max)
      max = root->val, ct++;

    int max_l = max;
    int max_r = max;
    dfs(root->left, max_l, ct);
    dfs(root->right, max_r, ct);
  }
};
