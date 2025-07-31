#include <stack>

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
   void
   reorderList (ListNode *head)
   {
      ListNode *tmp = head;

      int n = 0;
      std::stack<ListNode *> stk;
      while (tmp->next)
         {
            n++;
            tmp = tmp->next;
         }

      int mid = n / 2;
      int i = 0;
      tmp = head;

      while (tmp && i < mid)
         {
            i++;
            tmp = tmp->next;
         }

      while (tmp)
         {
            stk.push (tmp);
            tmp = tmp->next;
         }

      ListNode *hdtmp = head;

      while (hdtmp && hdtmp->next && hdtmp->next->next)
         {
            if (stk.empty ())
               return;

            ListNode *hd = stk.top (), *phd;
            stk.pop ();
            phd = stk.top ();

            phd->next = nullptr;

            hd->next = hdtmp->next;
            hdtmp->next = hd;

            hdtmp = hd->next;
         }
   }
};
