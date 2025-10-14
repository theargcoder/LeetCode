#include <deque>
#include <vector>

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
  int pathSum(TreeNode *root, int targetSum) {

    long long target = static_cast<long long>(targetSum);
    int ct = 0;

    std::vector<TreeNode *> tt;

    puch(root, tt);
    for (auto &i : tt)
      dfs(i, 0, target, ct);

    return ct;
  }

private:
  void puch(TreeNode *root, std::vector<TreeNode *> &tt) {
    if (!root)
      return;

    tt.push_back(root);
    puch(root->left, tt);
    puch(root->right, tt);
  }
  void dfs(TreeNode *root, long long sum, long long &target, int &ct) {
    if (!root)
      return;

    sum += root->val;

    if (sum == target)
      ct++;

    dfs(root->left, sum, target, ct);
    dfs(root->right, sum, target, ct);
  }
};
