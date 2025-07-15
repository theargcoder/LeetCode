#include <array>
#include <unordered_map>
#include <vector>

// Definition for a Node.
class Node
{
 public:
   int val;
   std::vector<Node *> neighbors;
   Node ()
   {
      val = 0;
      neighbors = std::vector<Node *> ();
   }
   Node (int val)
   {
      this->val = val;
      neighbors = std::vector<Node *> ();
   }
   Node (int val, std::vector<Node *> neighbors)
   {
      this->val = val;
      this->neighbors = neighbors;
   }
};

// FULLY functional but not the fastest for some reason...
/*
class Solution
{
 public:
   Node *
   cloneGraph (Node *node)
   {
      if (!node)
         return nullptr;
      std::unordered_map<int, Node *> memo;
      Node *root;
      dfs (node, root, memo);
      return root;
   }

 private:
   void
   dfs (Node *node, Node *&root, std::unordered_map<int, Node *> &memo)
   {
      root = new Node (node->val);
      memo[node->val] = root;
      for (int i = 0; i < node->neighbors.size (); i++)
         {
            auto &loc = node->neighbors[i];
            int val = loc->val;
            if (memo.count (val))
               {
                  root->neighbors.push_back (memo[val]);
               }
            else
               {
                  root->neighbors.push_back (nullptr);
                  dfs (loc, root->neighbors.back (), memo);
               }
         }
   }
};
*/

#define MAX_NODES 100

class Solution
{
 public:
   Node *
   cloneGraph (Node *node)
   {
      if (!node)
         return nullptr;
      std::array<bool, MAX_NODES + 1> used;
      used.fill (false);
      std::array<Node *, MAX_NODES + 1> nodes;

      Node *root;
      dfs (node, root, used, nodes);
      return root;
   }

 private:
   void
   dfs (Node *node, Node *&root, std::array<bool, MAX_NODES + 1> &used,
        std::array<Node *, MAX_NODES + 1> &nodes)
   {
      root = new Node (node->val);
      used[node->val] = true;
      nodes[node->val] = root;
      for (int i = 0; i < node->neighbors.size (); i++)
         {
            int val = node->neighbors[i]->val;
            if (used[val])
               {
                  root->neighbors.push_back (nodes[val]);
               }
            else
               {
                  dfs (node->neighbors[i], nodes[val], used, nodes);
                  root->neighbors.push_back (nodes[val]);
               }
         }
   }
};
