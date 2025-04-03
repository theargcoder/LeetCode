#include <filesystem>
#include <iostream>

//  Definition for singly-linked list.

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
   int limit, halt;
   bool first = true;

 public:
   ListNode *
   rotateRight (ListNode *head, int k)
   {
      if (k == 0)
         return head;
      if (!head)
         return head;
      if (!head->next)
         return head;

      limit = 1;
      ListNode *curr = head, *prev;
      while (curr->next != nullptr)
         {
            limit++;
            prev = curr;
            curr = curr->next;
         }
      halt = ((k) % limit);

      if (halt == 0)
         return head;

      prev->next = nullptr;
      curr->next = head;
      head = curr;

      return helper (head);
   }

 private:
   ListNode *
   helper (ListNode *head)
   {
      halt--;
      if (halt == 0)
         return head;
      ListNode *curr = head, *prev;
      while (curr->next != nullptr)
         {
            prev = curr;
            curr = curr->next;
         }
      prev->next = nullptr;
      curr->next = head;
      head = curr;

      return helper (head);
   }
};
