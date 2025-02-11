#include <iostream>
#include <vector>

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
    swapPairs (ListNode *head)
    {
        if (head == nullptr)
            return nullptr;
        if (head->next == nullptr)
            return head;

        ListNode *curr = head;
        ListNode *next = head->next;
        ListNode *next_next = head->next->next;

        head->next = next_next;
        head = next;
        head->next = curr;

        head->next->next = swapPairs (head->next->next);

        return head;
    }
};
