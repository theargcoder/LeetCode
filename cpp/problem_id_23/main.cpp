#include <vector>

struct ListNode
{
    int val;
    ListNode *next;
    ListNode () : val (0), next (nullptr) {}
    ListNode (int x) : val (x), next (nullptr) {}
    ListNode (int x, ListNode *next) : val (x), next (next) {}
};

// worked like magic did it in lierally 10 seconds (using the problem id 21
// solution)
// fairly slow tho... 195 ms
// could explore other possiblilities.....
// ill see

class Solution
{
  public:
    ListNode *
    mergeKLists (std::vector<ListNode *> &lists)
    {
        int size = lists.size ();
        if (size == 0)
            return nullptr;
        if (size == 1)
            return lists[0];

        ListNode *combined = merge2Lists (lists[0], lists[1]);

        if (size == 2)
            return combined;

        for (int i = 2; i < size; i++)
            {
                combined = merge2Lists (combined, lists[i]);
            }
        return combined;
    }

    ListNode *
    merge2Lists (ListNode *list1, ListNode *list2)
    {
        if (list1 == nullptr || list2 == nullptr)
            return list1 ? list1 : list2;
        if (list1->val > list2->val)
            std::swap (list1, list2);
        list1->next = merge2Lists (list1->next, list2);

        return list1;
    }
};
