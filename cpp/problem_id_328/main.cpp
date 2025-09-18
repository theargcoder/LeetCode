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
  oddEvenList (ListNode *head)
  {
    if (!head)
      return nullptr;

    ListNode *odd = head, *even = head->next;
    ListNode *evor = even;

    while (odd->next && even->next)
      {
        odd->next = even->next;
        even->next = even->next->next;
        odd = odd->next;
        even = even->next;
      }
    odd->next = evor;

    return head;
  }
};
