#include "list_node.h"

// 注意参数的设置
void AddToTail(ListNode*& head, int val) {
  ListNode* new_node = new ListNode(val);
  if (head == nullptr) {
    head = new_node;
  } else {
    ListNode* curr = head;
    while (curr->next) {
      curr = curr->next;
    }
    curr->next = new_node;
  }
}

void RemoveNode(ListNode*& head, int val) {
  if (head == nullptr) {
    return;
  }

  ListNode* to_be_deleted = nullptr;
  if (head->val == val) {
    to_be_deleted = head;
    head = head->next;
  } else {
    ListNode* curr = head;
    while (curr->next && curr->next->val != val) {
      curr = curr->next;
    }
    if (curr->next && curr->next->val == val) {
      to_be_deleted = curr->next;
      curr->next = curr->next->next;
    }
  }

  if (to_be_deleted) {
    delete to_be_deleted;
    to_be_deleted = nullptr;
  }
}
