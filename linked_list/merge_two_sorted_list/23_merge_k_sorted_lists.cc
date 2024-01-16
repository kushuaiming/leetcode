#include <queue>
#include <vector>

#include "list_node.h"

// 2024/01/14 自己实现, 注意优先队列的定义. TODO: 学习顺序合并和分治合并.
// 2023/12/30 可以想出思路, 但是实现有细节上的错误.
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
