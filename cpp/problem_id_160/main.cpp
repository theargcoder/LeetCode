#include <unordered_map>

struct ListNode
{
  int val;
  ListNode *next;
  ListNode (int x) : val (x), next (nullptr) {}
};

class Solution
{
public:
  ListNode *
  getIntersectionNode (ListNode *headA, ListNode *headB)
  {
    if (!headA || !headB)
      return nullptr;

    std::unordered_map<long, char> TA;

    ListNode *tt = headA;

    while (tt)
      {
        TA[(long)tt] = 'a';
        tt = tt->next;
      }

    tt = headB;

    while (tt)
      {
        if (TA.count ((long)tt))
          return tt;

        tt = tt->next;
      }

    return nullptr;
  }
};
