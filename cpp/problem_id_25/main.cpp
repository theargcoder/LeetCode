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
    reverseKGroup (ListNode *head, int k)
    {
        if (head == nullptr)
            return nullptr;
        if (head->next == nullptr)
            return head;
        if (k == 0 || k == 1)
            return head;

        int count = 0;
        std::vector<ListNode *> nodes;
        nodes.push_back (head);

        while (count < k)
            {
                if (nodes[count] == nullptr)
                    {
                        int size = nodes.size ();
                        ListNode *temp = nodes[0]->next;
                        head = nodes[0];
                        head->next = temp;

                        for (int i = 1; i < size; i++)
                            {
                                temp->next = nodes[i];
                                temp = nodes[i];
                            }

                        return head;
                    }
                nodes.push_back (nodes[count]->next);
                count++;
            }

        ListNode *temp = nodes[k - 1];
        ListNode *nexty = nodes[k - 1]->next;
        head = temp;

        for (int i = k - 2; i >= 0; i--)
            {
                temp->next = nodes[i];
                temp = nodes[i];
            }

        temp->next = reverseKGroup (nexty, k);

        return head;
    }
};
