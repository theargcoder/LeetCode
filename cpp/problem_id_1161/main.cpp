#include <limits.h>
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
  int maxLevelSum(TreeNode *root) {
    std::vector<std::vector<int>> dd;

    level_order(root, dd, 0);

    int max = INT_MIN;
    int sum;
    size_t res;
    const size_t n = dd.size();
    for (size_t i = 0; i < n; i++) {
      sum = 0;
      for (const auto &i : dd[i])
        sum += i;

      if (sum > max) {
        max = sum;
        res = static_cast<int>(i) + 1;
      }
    }

    return res;
  }

private:
  void level_order(TreeNode *root, std::vector<std::vector<int>> &dd, int lvl) {
    if (!root)
      return;

    if (dd.size() <= lvl)
      dd.push_back({root->val});
    else
      dd[lvl].push_back(root->val);

    level_order(root->left, dd, lvl + 1);
    level_order(root->right, dd, lvl + 1);
  }
};
