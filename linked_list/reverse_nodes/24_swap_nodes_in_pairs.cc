#include <iostream>

#include "list_node.h"

// Iteration: 引入指针node1和node2, 不容易出错.
// 需要画图之后再进行编程.
ListNode* SwapPairs(ListNode* head) {
  ListNode* dummy_node = new ListNode(-1);
  ListNode* temp = dummy_node;
  temp->next = head;
  while (temp->next && temp->next->next) {
    ListNode* node1 = temp->next;
    ListNode* node2 = temp->next->next;
    temp->next = node2;
    node1->next = node2->next;
    node2->next = node1;
    temp = node1;
  }
  return dummy_node->next;
}

// 2024/01/07: 不看答案写出来了.
// Recursion
ListNode* SwapPairs2(ListNode* head) {
  if (!head || !head->next) {
    return head;
  }

  ListNode* new_head = head->next;
  head->next = SwapPairs2(new_head->next);
  new_head->next = head;
  return new_head;
}

// 2024/01/01自己实现了一个类似但不完全同的递归版本.
ListNode* SwapPairs3(ListNode* head) {
  if (head == nullptr || head->next == nullptr) {
    return head;
  }
  ListNode* prev = head;
  head = head->next;
  prev->next = SwapPairs3(head->next);
  head->next = prev;
  return head;
}
