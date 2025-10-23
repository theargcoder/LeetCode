#include <unordered_map>
struct TreeNode {
  int val;
  TreeNode *left;
  TreeNode *right;
  TreeNode() : val(0), left(nullptr), right(nullptr) {}
  TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
  TreeNode(int x, TreeNode *left, TreeNode *right)
      : val(x), left(left), right(right) {}
};

#include <math.h>

class Solution {
public:
  int longestZigZag(TreeNode *root) {

    int max = 0;

    std::unordered_map<TreeNode *, int> memo;

    dfs(root, memo, max, false, 0);
    dfs(root, memo, max, true, 0);

    return max;
  }

private:
  int dfs(TreeNode *root, std::unordered_map<TreeNode *, int> &memo, int &max,
          bool right, int sum) {
    if (!root)
      return 0;
    if (memo.count(root))
      return memo[root];

    max = std::max(max, sum);

    if (right && root->left)
      if (memo.count(root->left)) {
        sum += memo[root->left];
        max = std::max(max, sum);
      } else {
        memo[root->left] = dfs(root->left, memo, max, false, ++sum);
      }
    else if (!right && root->right) {
      if (memo.count(root->right)) {
        sum += memo[root->right];
        max = std::max(max, sum);
      } else {
        memo[root->right] = dfs(root->right, memo, max, true, ++sum);
      }
    }

    memo[root->left] = dfs(root->left, memo, max, false, 1);
    memo[root->right] = dfs(root->right, memo, max, true, 1);

    return memo[root] = sum;
  }
};
