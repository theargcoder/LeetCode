#include <algorithm>

struct ListNode
{
  int val;
  ListNode *next;
  ListNode () : val (0), next (nullptr) {}
  ListNode (int x) : val (x), next (nullptr) {}
  ListNode (int x, ListNode *next) : val (x), next (next) {}
};

class Solution
{
private:
  struct TreeNode
  {
    int val;
    int height;
    int duplicates;
    TreeNode *left, *right;

    TreeNode (int x)
        : val (x), height (1), duplicates (0), left (nullptr), right (nullptr)
    {
    }
  };

public:
  ListNode *
  sortList (ListNode *head)
  {
    if (!head)
      return nullptr;

    TreeNode *tree = nullptr;

    ListNode *tmp = head;

    while (tmp)
      {
        tree = insert (tree, tmp->val);
        tmp = tmp->next;
      }

    tmp = head;

    dfs (tree, tmp);

    return head;
  }

private:
  void
  dfs (TreeNode *tree, ListNode *&ln)
  {
    if (!tree)
      return;

    dfs (tree->left, ln);
    int dups = tree->duplicates + 1;
    do
      {
        dups--;
        ln->val = tree->val;
        ln = ln->next;
      }
    while (dups > 0);

    dfs (tree->right, ln);
  }

private:
  int
  getHeight (TreeNode *node)
  {
    return node ? node->height : 0;
  }

  int
  getBalance (TreeNode *node)
  {
    return node ? getHeight (node->left) - getHeight (node->right) : 0;
  }

  void
  updateHeight (TreeNode *node)
  {
    if (node)
      node->height
          = 1 + std::max (getHeight (node->left), getHeight (node->right));
  }

  TreeNode *
  insert (TreeNode *root, const int &val)
  {
    if (!root)
      return new TreeNode (val);

    if (val < root->val)
      root->left = insert (root->left, val);
    else if (val > root->val)
      root->right = insert (root->right, val);
    else
      {
        root->duplicates++;
        return root; // No need to rebalance
      }

    updateHeight (root);
    int balance = getBalance (root);

    // Left Left Case
    if (balance > 1 && val < root->left->val)
      return rotateRight (root);

    // Right Right Case
    if (balance < -1 && val > root->right->val)
      return rotateLeft (root);

    // Left Right Case
    if (balance > 1 && val > root->left->val)
      {
        root->left = rotateLeft (root->left);
        return rotateRight (root);
      }

    // Right Left Case
    if (balance < -1 && val < root->right->val)
      {
        root->right = rotateRight (root->right);
        return rotateLeft (root);
      }

    return root;
  }

  TreeNode *
  rotateRight (TreeNode *y)
  {
    TreeNode *x = y->left;
    TreeNode *T2 = x->right;

    x->right = y;
    y->left = T2;

    updateHeight (y);
    updateHeight (x);

    return x;
  }

  TreeNode *
  rotateLeft (TreeNode *x)
  {
    TreeNode *y = x->right;
    TreeNode *T2 = y->left;

    y->left = x;
    x->right = T2;

    updateHeight (x);
    updateHeight (y);

    return y;
  }
};
