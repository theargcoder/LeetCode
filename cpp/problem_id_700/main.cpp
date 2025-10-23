#include <queue>

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
  TreeNode *searchBST(TreeNode *root, int val) {

    std::queue<TreeNode *> que;
    que.push(root);

    while (!que.empty()) {

      TreeNode *tr;
      if (que.front()) {
        que.push(que.front()->right);
        que.push(que.front()->left);

        tr = que.front();
        if (tr->val == val)
          return tr;
      }
      que.pop();
    }

    return nullptr;
  }
};
