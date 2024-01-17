#include "list_node.h"

// 2024/01/17: 不看答案自己实现.
ListNode* DeleteDuplicates(ListNode* head) {
  ListNode* curr = head;
  while (curr && curr->next) {
    if (curr->val == curr->next->val) {
      curr->next = curr->next->next;
    } else {
      curr = curr->next;
    }
  }

  return head;
}
