
// Definition for a Node.
#include <unordered_map>
#include <vector>
class Node
{
 public:
   int val;
   Node *next;
   Node *random;

   Node (int val)
   {
      this->val = val;
      next = nullptr;
      random = nullptr;
   }
};

class Solution
{
 public:
   Node *
   copyRandomList (Node *head)
   {
      if (!head)
         return nullptr;

      Node *hd;

      int mxt = 0;
      std::unordered_map<long, long> map_rand, map_idx, map_hd;
      cpy (hd, head, map_rand, map_idx, map_hd, 0);

      return hd;
   }

 private:
   void
   cpy (Node *&head, Node *original_head,
        std::unordered_map<long, long> &map_rand,
        std::unordered_map<long, long> &map_idx,
        std::unordered_map<long, long> &map_hd, int ct)
   {
      if (!original_head)
         return;

      head = new Node (original_head->val);
      map_rand[(long)original_head] = (long)original_head->random;
      map_idx[(long)original_head] = ct;
      map_hd[ct] = (long)head;

      cpy (head->next, original_head->next, map_rand, map_idx, map_hd, ct + 1);

      if (original_head->random)
         {
            head->random
                = (Node *)map_hd[map_idx[map_rand[(long)original_head]]];
         }
   }
};
