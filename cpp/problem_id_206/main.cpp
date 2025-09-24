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
  ListNode *
  reverseList (ListNode *head)
  {
    if (!head)
      return nullptr;
    std::stack<ListNode *> stk;

    ListNode *tmp = head;

    while (tmp)
      {
        stk.push (tmp);
        tmp = tmp->next;
      }

    ListNode *tmphd = stk.top ();

    while (!stk.empty ())
      {
        tmp = stk.top ();
        stk.pop ();
        if (!tmp)
          break;
        if (!stk.empty ())
          tmp->next = stk.top ();
        else
          tmp->next = nullptr;
      }

    return tmphd;
  }
};
