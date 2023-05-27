/*
- 快慢指针: fast每次走两步, slow每次走一步. 如果有环, 那么fast和slow必定相遇
- 设入环点左侧有a个节点(不包括入环点), 那么相遇的fast和slow再走a步恰好到达入环点
*/

#include <iostream>

struct ListNode {
  ListNode(int val) : val(val), next(nullptr) {}
  int val;
  ListNode* next;
};

ListNode* DetectCycle(ListNode* head) {
  ListNode* fast = head;
  ListNode* slow = head;
  while (1) {
    if (fast == nullptr || fast->next == nullptr) {
      return nullptr;
    }
    fast = fast->next->next;
    slow = slow->next;
    if (fast == slow) {
      break;
    }
  }
  fast = head;
  while (fast != slow) {
    fast = fast->next;
    slow = slow->next;
  }
  return fast;
}

int main(int argc, char* argv[]) {
  ListNode* head = new ListNode(3);
  ListNode* node1 = new ListNode(2);
  ListNode* node2 = new ListNode(0);
  ListNode* node3 = new ListNode(-4);
  head->next = node1;
  node1->next = node2;
  node2->next = node3;
  node3->next = node1;
  ListNode* pos = DetectCycle(head);
  if (pos == nullptr) {
    std::cout << "there is no cycle." << std::endl;
  } else {
    std::cout << pos->val << std::endl;
  }
  delete head;
  delete node1;
  delete node2;
  delete node3;
  return 0;
}