#include <stack>

#include "list_node.h"

// 2024/01/07: 不看答案自己写出来了.

ListNode* RemoveNthFromEnd(ListNode* head, int n) {
  std::stack<ListNode*> stack;
  ListNode* curr = head;
  while (curr) {
    stack.push(curr);
    curr = curr->next;
  }
  for (int i = 0; i < n; ++i) {
    stack.pop();
  }
  if (stack.empty()) {
    return head->next;
  } else {
    stack.top()->next = stack.top()->next->next;
    return head;
  }
}
