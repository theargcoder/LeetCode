#include <span>
#include <vector>

struct ListNode
{
   int val;
   ListNode *next;
   ListNode () : val (0), next (nullptr) {}
   ListNode (int x) : val (x), next (nullptr) {}
   ListNode (int x, ListNode *next) : val (x), next (next) {}
};

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

class Solution
{
 public:
   TreeNode *
   sortedListToBST (ListNode *head)
   {
      std::vector<int> nums;
      ListNode *nd = head;
      while (nd)
         {
            nums.push_back (nd->val);
            nd = nd->next;
         }
      const int n = nums.size ();
      return construct (nums);
   }

 private:
   TreeNode *
   construct (std::span<int> nums)
   {
      if (nums.empty ())
         return nullptr;

      int mid = nums.size () / 2;
      TreeNode *root = new TreeNode (nums[mid]);

      root->left = construct (nums.subspan (0, mid));
      root->right = construct (nums.subspan (mid + 1));

      return root;
   }
};
