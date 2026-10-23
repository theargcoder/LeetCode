#include <charconv>
#include <string>
#include <vector>

// Definition for a binary tree node.
struct TreeNode
{
  int val;
  TreeNode *left;
  TreeNode *right;
  TreeNode(int x) : val(x), left(nullptr), right(nullptr)
  {
  }
};

class Codec
{
public:
  // Encodes a tree to a single string.
  std::string serialize(TreeNode *root)
  {
    std::string out;

    std::vector<TreeNode *> stk;
    stk.push_back(root);

    while(!stk.empty())
    {
      auto ptr = stk.back();
      stk.pop_back();
      if(ptr == nullptr)
      {
        out += 'n';
        out += ',';
      }
      else
      {
        out += std::to_string(ptr->val);
        out += ',';
        stk.push_back(ptr->right);
        stk.push_back(ptr->left);
      }
    }

    out.pop_back();

    return out;
  }

  // Decodes your encoded data to tree.
  TreeNode *deserialize(const std::string &data)
  {
    const char *__restrict__ ptr = data.data();
    const size_t size = data.size();
    int val;
    TreeNode *head;
    std::vector<TreeNode **> stk;
    stk.push_back(&head);

    for(size_t i = 0, j; i < size; i++)
    {
      if(ptr[i] == 'n')
      {
        *stk.back() = nullptr;
        stk.pop_back();
        i++;
      }
      else
      {
        j = i;
        for(; j < size && ptr[j] != ','; j++)
        {
        }
        std::from_chars(&ptr[i], &ptr[j], val);
        auto *addition = new TreeNode(val);
        *stk.back() = addition;
        stk.pop_back();
        stk.push_back(&addition->right);
        stk.push_back(&addition->left);
        i = j;
      }
    }

    return head;
  }
};

// Your Codec object will be instantiated and called as such:
// Codec ser, deser;
// TreeNode* ans = deser.deserialize(ser.serialize(root));

int main(int argc, char *argv[])
{
  {
    auto *ptr = new TreeNode(1);
    ptr->left = new TreeNode(2);
    ptr->right = new TreeNode(3);
    ptr->right->left = new TreeNode(4);
    ptr->right->right = new TreeNode(5);

    Codec ser;

    const auto str = ser.serialize(ptr);
    const auto *new_ptr = ser.deserialize(str);
  }

  {
    /*
          -70
         /   \
      null   -111
            /    \
         -451    132
         /   \
       452  -490
       /    /
     425  -582

    */

    // -70,null,-111,-451,132,452,-490
    auto *ptr = new TreeNode(-70);
    ptr->left = nullptr;
    ptr->right = new TreeNode(-111);

    // Level 3
    ptr->right->left = new TreeNode(-451);
    ptr->right->right = new TreeNode(132);

    // Level 4
    ptr->right->left->left = new TreeNode(452);
    ptr->right->left->right = new TreeNode(-490);

    // Level 5 (Children of 452 and -490)
    ptr->right->left->left->left = new TreeNode(425);
    ptr->right->left->left->right = nullptr;
    ptr->right->left->right->left = new TreeNode(-582);

    Codec ser;

    const auto str = ser.serialize(ptr);
    const auto *new_ptr = ser.deserialize(str);
  }

  return 0;
}
