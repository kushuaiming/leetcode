#include <queue>
#include <vector>

struct ListNode {
  int val;
  ListNode* next;
  ListNode() : val(0), next(nullptr) {}
  ListNode(int val) : val(val), next(nullptr) {}
  ListNode(int val, ListNode* next) : val(val), next(next) {}
};

ListNode* MergeKLists(std::vector<ListNode*>& lists) {
  if (lists.empty()) {
    return nullptr;
  }
  auto cmp = [](ListNode* left, ListNode* right) {
    return left->val > right->val;
  };
  std::priority_queue<ListNode*, std::vector<ListNode*>, decltype(cmp)> q(cmp);
  for (ListNode* list : lists) {
    if (list) {
      q.push(list);
    }
  }
  ListNode* dummy = new ListNode(0);
  ListNode* cur = dummy;
  while (!q.empty()) {
    cur->next = q.top();
    q.pop();
    cur = cur->next;
    if (cur->next) {
      q.push(cur->next);
    }
  }
  return dummy->next;
}