#include <climits>
#include <math.h>
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
  int
  pairSum (ListNode *head)
  {
    ListNode *r, *l;
    r = l = head;

    std::stack<ListNode *> stk;
    while (r->next)
      {
        stk.push (r);
        r = r->next;
      }

    int max = INT_MIN;

    while (r != l)
      {
        max = std::max (max, r->val + l->val);
        l = l->next;
        if (stk.empty ())
          break;
        r = stk.top ();
        stk.pop ();
      }

    return max;
  }
};
