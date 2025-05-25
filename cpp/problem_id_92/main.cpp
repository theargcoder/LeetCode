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
   reverseBetween (ListNode *head, int left, int right)
   {
      if (right == left)
         return head;

      ListNode *l = head, *r = head, *bl = head, *nr = head->next;

      int i = 1;
      while (i < left)
         {
            bl = l;
            l = l->next;
            r = nr;
            nr = nr->next;
            i++;
         }
      r = nr;
      if (!nr)
         return head;
      nr = nr->next;

      if (left == 1)
         bl = new ListNode (INT_MIN, l);

      ListNode *blncp;

      while (r && i < right)
         {
            i++;
            blncp = bl->next;
            bl->next = r;
            l->next = r->next;
            r->next = blncp;
            r = nr;
            if (nr)
               nr = nr->next;
         }

      if (left != 1)
         return head;
      else
         {
            ListNode *ret = bl->next;
            delete bl;
            return ret;
         }
   }
};
