#include <stack>

// 2024/01/07: 不看答案自己写出来了.
struct ListNode {
  int val;
  ListNode* next;
  ListNode() : val(0), next(nullptr) {}
  ListNode(int x) : val(x), next(nullptr) {}
  ListNode(int x, ListNode* next) : val(x), next(next) {}
};

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
