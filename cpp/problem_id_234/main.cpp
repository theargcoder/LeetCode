#include <cstddef>

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
  bool isPalindrome(ListNode *head)
  {
    size_t size = 1;
    ListNode *mid = head;
    while(mid->next != nullptr)
    {
      size++;
      mid = mid->next;
    }

    mid = head;
    size_t i = 0;
    while(i < ((size / 2) + (size & 0b01)))
    {
      mid = mid->next;
      i++;
    }

    ListNode *prev = nullptr;
    ListNode *curr = head;

    while(curr != mid)
    {
      ListNode *next = curr->next;
      curr->next = prev;
      prev = curr;
      curr = next;
    }

    curr = prev;
    if(size & 0b01)
    {
      curr = curr->next;
    }

    while(mid != nullptr)
    {
      if(curr->val != mid->val)
      {
        return false;
      }
      curr = curr->next;
      mid = mid->next;
    }

    return true;
  }
};

int main(int argc, char *argv[])
{
  Solution sol;

  ListNode *head = new ListNode(1);
  ListNode *nd = head;
  nd->next = new ListNode(2);
  nd = nd->next;
  nd->next = new ListNode(2);
  nd = nd->next;
  nd->next = new ListNode(2);
  nd = nd->next;
  nd->next = new ListNode(1);
  nd = nd->next;

  const auto res_1 = sol.isPalindrome(head);

  return 0;
}
