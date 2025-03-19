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
    removeNthFromEnd (ListNode *head, int n)
    {
        if (head->next == nullptr)
            return nullptr;

        int end = 1;
        ListNode *node = head;
        while (node->next != nullptr)
            {
                node = node->next;
                end++;
            }

        int distance = end - n;

        int i = 0;
        ListNode *prev = head, *curr = head;
        while (i < distance)
            {
                prev = curr;
                curr = curr->next;
                i++;
            }
        prev->next = curr->next;
        if (curr != head)
            return head;
        else
            return head->next;
        ;
    }
};
