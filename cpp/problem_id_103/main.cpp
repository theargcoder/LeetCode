#include <deque>
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

class Solution
{
 public:
   std::vector<std::vector<int>>
   zigzagLevelOrder (TreeNode *root)
   {
      std::vector<std::deque<int>> pos;
      std::vector<std::vector<int>> res;

      bfs (root, pos, 0, false);
      for (int i = 0; i < pos.size (); i++)
         {
            res.push_back ({});
            for (int j = 0; j < pos[i].size (); j++)
               res.back ().push_back (pos[i][j]);
         }

      return res;
   }

 private:
   void
   bfs (TreeNode *curr, std::vector<std::deque<int>> &res, int lvl, bool odd)
   {
      if (!curr)
         return;

      if (res.size () <= lvl)
         res.push_back ({});

      if (odd)
         res[lvl].push_front (curr->val);
      else
         res[lvl].push_back (curr->val);

      bfs (curr->left, res, lvl + 1, (odd) ? false : true);
      bfs (curr->right, res, lvl + 1, (odd) ? false : true);
   }
};
