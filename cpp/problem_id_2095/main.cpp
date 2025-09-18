#include <cstddef>

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
  deleteMiddle (ListNode *head)
  {
    if (head && !head->next)
      return nullptr;

    ListNode *prev = head;
    ListNode *slow = head, *fast = head;

    while (fast->next && fast->next->next)
      {
        prev = slow;
        slow = slow->next;
        fast = fast->next->next;
      }
    if (fast->next)
      slow->next = slow->next->next;
    else
      prev->next = slow->next;

    return head;
  }
};
