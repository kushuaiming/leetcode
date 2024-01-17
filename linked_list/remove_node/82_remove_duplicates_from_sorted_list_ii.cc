#include "list_node.h"

// 2024/01/17: 直接看答案
ListNode* DeleteDuplicates(ListNode* head) {
  // 因为head本身可能被删除, 所以需要哑节点.
  ListNode* dummy_node = new ListNode();
  dummy_node->next = head;

  ListNode* curr = dummy_node;
  while (curr->next && curr->next->next) {
    if (curr->next->val == curr->next->next->val) {
      int x = curr->next->val;
      while (curr->next && curr->next->val == x) {
        curr->next = curr->next->next;
      }
    } else {
      curr = curr->next;
    }
  }

  return dummy_node->next;
}
