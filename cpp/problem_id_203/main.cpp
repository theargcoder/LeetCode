
// Definition for singly-linked list.
struct ListNode
{
  int val;
  ListNode *next;
  ListNode() : val(0), next(nullptr)
  {
  }
  ListNode(int x) : val(x), next(nullptr)
  {
  }
  ListNode(int x, ListNode *next) : val(x), next(next)
  {
  }
};

class Solution
{
public:
  ListNode *removeElements(ListNode *head, const int val)
  {
    auto *st_head = head;

    while(st_head && st_head->val == val)
    {
      st_head = st_head->next;
    }

    auto *fir = st_head;
    while(fir)
    {
      auto *sec = fir;
      while(sec && sec->val != val)
      {
        fir = sec;
        sec = sec->next;
      }

      while(sec && sec->val == val)
      {
        auto *tmp = sec;
        sec = sec->next;
        delete tmp;
      }
      fir->next = sec;
      fir = fir->next;
    }

    return st_head;
  }
};
