#include <iostream>

struct ListNode {
  int val;
  ListNode* next;
  ListNode() : val(0), next(nullptr) {}
  ListNode(int x) : val(x), next(nullptr) {}
  ListNode(int x, ListNode* next) : val(x), next(next) {}
};

// Recursion: 假设链表的其于部分已经被反转, 现在应该如何反转它前面的部分?
ListNode* ReverseList(ListNode* head) {
  if (!head || !head->next) {
    return head;
  }
  ListNode* new_head = ReverseList(head->next);
  head->next->next = head;
  head->next = nullptr;
  return new_head;
}

// Iteration
ListNode* ReverseList2(ListNode* head) {
  ListNode* prev = nullptr;
  ListNode* curr = head;
  while (curr) {
    ListNode* next = curr->next;
    curr->next = prev;
    prev = curr;
    curr = next;
  }
  return prev;
}

int main(int argc, char* argv[]) {
  ListNode node5(5);
  ListNode node4(4, &node5);
  ListNode node3(3, &node4);
  ListNode node2(2, &node3);
  ListNode node1(1, &node2);
  ListNode* head = &node1;
  while (head) {
    std::cout << head->val << std::endl;
    head = head->next;
  }
  ListNode* reverse_head = ReverseList2(&node1);
  while (reverse_head) {
    std::cout << reverse_head->val << std::endl;
    reverse_head = reverse_head->next;
  }
  return 0;
}
