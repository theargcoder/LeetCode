
struct ListNode
{
   int val;
   ListNode *next;
   ListNode () : val (0), next (nullptr) {}
   ListNode (int x) : val (x), next (nullptr) {}
   ListNode (int x, ListNode *next) : val (x), next (next) {}
};

// forgot you got to ELIMINATE REPEATS not just have 1 ocassion of each number
/*
class Solution
{
 public:
   ListNode *
   deleteDuplicates (ListNode *head)
   {
      if (!head)
        return head;
      ListNode *curr = head;
      while (curr->next)
         {
            if (curr->next->val == curr->val)
               {
                  curr->next = curr->next->next;
               }
            else
               {
                  curr = curr->next;
               }
         }
      return head;
   }
};
*/

class Solution
{
 public:
   ListNode *
   deleteDuplicates (ListNode *head)
   {
      if (!head)
         return nullptr;
      if (!head->next)
         return head;

      bool reps = false;

      while (head->next)
         {
            if (head->val == head->next->val)
               {
                  reps = true;
                  head = head->next;
                  continue;
               }
            if (reps)
               {
                  head = head->next;
                  reps = false;
               }
            else
               break;
         }

      if (!head)
         return nullptr;
      else if (reps && !head->next)
         return nullptr;
      else
         explore (head, head->next);

      return head;
   }

 private:
   void
   explore (ListNode *prev, ListNode *next)
   {
      if (!prev || !next)
         return;
      if (!next->next)
         return;

      bool reps = false;

      while (next->next)
         {
            if (next->val == next->next->val)
               {
                  reps = true;
                  next = next->next;
                  continue;
               }
            break;
         }

      if (reps)
         {
            next = next->next;
            prev->next = next;
            explore (prev, next);
         }
      else
         {
            explore (next, next->next);
         }
   }
};
