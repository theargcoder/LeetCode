#include <unordered_map>

struct ListNode
{
   int val;
   ListNode *next;
   ListNode (int x) : val (x), next (nullptr) {}
};

// O(n) space solution
class Solution
{
 public:
   ListNode *
   detectCycle (ListNode *head)
   {
      ListNode *hd = head;

      std::unordered_map<long, bool> visited;

      while (hd)
         {
            if (visited.count ((long)hd))
               return hd;

            visited[(long)hd] = true;

            hd = hd->next;
         }

      return nullptr;
   }
};
