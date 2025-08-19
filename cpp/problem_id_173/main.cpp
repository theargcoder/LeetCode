#include <stack>
#include <vector>

struct TreeNode
{
  int val;
  TreeNode *left;
  TreeNode *right;
  TreeNode () : val (0), left (nullptr), right (nullptr) {}
  TreeNode (int x) : val (x), left (nullptr), right (nullptr) {}
  TreeNode (int x, TreeNode *left, TreeNode *right)
      : val (x), left (left), right (right)
  {
  }
};

class BSTIterator
{
public:
  BSTIterator (TreeNode *root) { dfs (root); };

  int
  next ()
  {
    int ret = loc.back ();
    loc.pop_back ();
    return ret;
  }

  bool
  hasNext ()
  {
    return !loc.empty ();
  }

private:
  TreeNode *rt;

private:
  void
  dfs (TreeNode *root)
  {
    if (!root)
      return;

    dfs (root->right);
    loc.push_back (root->val);
    dfs (root->left);
  }
  std::vector<int> loc;
};

/**
 * Your BSTIterator object will be instantiated and called as such:
 * BSTIterator* obj = new BSTIterator(root);
 * int param_1 = obj->next();
 * bool param_2 = obj->hasNext();
 */
