#include <cstddef>
#include <vector>

class Node
{
 public:
   int val;
   Node *left;
   Node *right;
   Node *next;

   Node () : val (0), left (NULL), right (NULL), next (NULL) {}

   Node (int _val) : val (_val), left (NULL), right (NULL), next (NULL) {}

   Node (int _val, Node *_left, Node *_right, Node *_next)
       : val (_val), left (_left), right (_right), next (_next)
   {
   }
};

class Solution
{
 public:
   Node *
   connect (Node *root)
   {
      std::vector<Node *> level;
      dfs (root, level, 0);
      return root;
   }

 private:
   void
   dfs (Node *root, std::vector<Node *> &level, int lvl)
   {
      if (!root)
         return;
      if (level.size () <= lvl)
         level.push_back (root);
      else
         {
            level[lvl]->next = root;
            level[lvl] = root;
         }
      dfs (root->left, level, lvl + 1);
      dfs (root->right, level, lvl + 1);
      return;
   }
};
