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
  std::vector<int> rightSideView(TreeNode *root) {

    std::vector<int> res;

    level_order(root, res, 0);

    return res;
  }

private:
  void level_order(TreeNode *root, std::vector<int> &res, int lvl) {
    if (!root)
      return;

    if (res.size() <= lvl)
      res.push_back({root->val});
    else
      res[lvl] = root->val;

    level_order(root->left, res, lvl + 1);
    level_order(root->right, res, lvl + 1);
  }
};
