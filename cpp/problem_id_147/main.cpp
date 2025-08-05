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
  insertionSortList (ListNode *head)
  {
    if (!head || !head->next)
      return head;

    ListNode *root = head;
    ListNode *curr = head->next;
    root->next = nullptr;

    while (curr)
      {
        ListNode *next = curr->next;
        ListNode *iter = root;
        ListNode *prev = nullptr;

        while (iter && iter->val < curr->val)
          {
            prev = iter;
            iter = iter->next;
          }

        if (prev)
          {
            prev->next = curr;
          }
        else
          {
            root = curr;
          }

        curr->next = iter;
        curr = next;
      }

    return root;
  }
};
