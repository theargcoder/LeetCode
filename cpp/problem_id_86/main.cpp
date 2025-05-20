#include <climits>

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
 public:
   ListNode *
   partition (ListNode *head, int x)
   {
      if (!head)
         return head;

      ListNode *newhead;
      ListNode *less = new ListNode (INT_MAX), *prevl = new ListNode (INT_MAX);
      ListNode *begl = less;
      ListNode *more = new ListNode (INT_MAX), *prevm = new ListNode (INT_MAX);
      ListNode *begm = more;

      while (head)
         {
            if (head->val < x)
               {
                  prevl = less;
                  less->val = head->val;
                  less->next = new ListNode ();
                  less = less->next;
               }
            else
               {
                  prevm = more;
                  more->val = head->val;
                  more->next = new ListNode ();
                  more = more->next;
               }

            head = head->next;
         }

      newhead = begl;

      if (less->val == INT_MAX)
         newhead = begm;

      if (prevm->val == INT_MAX)
         {
            prevl->next = nullptr;
         }
      else
         {
            prevl->next = begm;
            prevm->next = nullptr;
         }

      return newhead;
   }
};
