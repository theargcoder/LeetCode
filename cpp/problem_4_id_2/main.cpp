#include <iostream>

// Definition for singly-linked list.
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
    addTwoNumbers (ListNode *l1, ListNode *l2)
    {
        ListNode *l_first = new ListNode ();
        int carry = 0;
        add_two_recursive (l1, l2, l_first, carry);

        return l_first;
    }

  private:
    void
    add_two_recursive (ListNode *l_first, ListNode *l_second,
                       ListNode *l_current, int &carry)
    {
        l_current->val = l_first->val + l_second->val + carry;
        carry = 0;
        if (l_current->val >= 10)
            {
                l_current->val = l_current->val - 10;
                carry = 1;
            }
        if (l_first->next != nullptr && l_second->next != nullptr)
            {
                l_current->next = new ListNode (0);
                add_two_recursive (l_first->next, l_second->next,
                                   l_current->next, carry);
            }
        if (l_first->next != nullptr && l_second->next == nullptr)
            {
                l_current->next = new ListNode (0);
                add_single_recursive (l_first->next, l_current->next, carry);
            }
        if (l_second->next != nullptr && l_first->next == nullptr)
            {
                l_current->next = new ListNode (0);
                add_single_recursive (l_second->next, l_current->next, carry);
            }
        if (l_first->next == nullptr && l_second->next == nullptr
            && carry == 1)
            {
                l_current->next = new ListNode (carry);
            }
    }

    void
    add_single_recursive (ListNode *l_first, ListNode *l_current, int &carry)
    {
        l_current->val = l_first->val + carry;
        carry = 0;

        if (l_current->val >= 10)
            {
                l_current->val = l_current->val - 10;
                carry = 1;
            }
        if (l_first->next != nullptr)
            {
                l_current->next = new ListNode (0);
                add_single_recursive (l_first->next, l_current->next, carry);
            }
        if (l_first->next == nullptr && carry == 1)
            {
                l_current->next = new ListNode (carry);
            }
    }
};

void
print_list (ListNode *curr)
{
    std::cout << curr->val << '\n';
    if (curr->next != nullptr)
        print_list (curr->next);
};

int
main ()
{
    ListNode *lt1 = new ListNode (2, new ListNode (4, new ListNode (3)));
    ListNode *lt2 = new ListNode (5, new ListNode (6, new ListNode (4)));

    Solution solution;

    ListNode *result = solution.addTwoNumbers (lt1, lt2);
    std::cout << "here comes goodby " << '\n';
    print_list (result);

    lt1 = new ListNode (0);
    lt2 = new ListNode (0);
    std::cout << "here comes goodby " << '\n';
    result = solution.addTwoNumbers (lt1, lt2);
    print_list (result);

    lt1 = new ListNode (
        9, new ListNode (
               9, new ListNode (
                      9, new ListNode (
                             9, new ListNode (
                                    9, new ListNode (
                                           9, new ListNode (
                                                  9, new ListNode ())))))));
    lt2 = new ListNode (9,
                        new ListNode (9, new ListNode (9, new ListNode (9))));
    std::cout << "here comes goodby " << '\n';
    result = solution.addTwoNumbers (lt1, lt2);
    print_list (result);

    return 0;
}
