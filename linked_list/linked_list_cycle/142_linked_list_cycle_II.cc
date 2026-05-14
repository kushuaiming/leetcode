/*
- 快慢指针: fast每次走两步, slow每次走一步. 如果有环, 那么fast和slow必定相遇
- 设入环点左侧有a个节点(不包括入环点), 那么相遇的fast和slow再走a步恰好到达入环点
*/

// 证明: 设链表共有a+b个节点, 其中链表头部到链表入口有a个节点(不计链表入口节点)
// 链表环有b个节点, 设两指针分别走了f和s步, 则有
// 1. fast 走的步数是 slow 步数的两倍, 即 f = 2s.
// 2. fast 比 slow 多走了 n 个环的长度, 即 f = s + nb.
// 两式相减得到 f = 2nb, s = nb.
// 如果让指针从链表头部一直向前走并统计步数k, 那么所有走到链表节点时的步数是 k = a + nb.
// 即先走a步到达入口节点, 之后每绕一圈(b步), 都会走到入口节点. 目前slow指针走了nb步, 只要再走a步, 就可以到达入口节点.

// 结论: 当slow和fast第一次相遇时, 我们将fast重新移动到链表开头, 并让slow和fast每次都前进一步.
// 当slow和fast第二次相遇时, 相遇的节点即为环路的开始点.

#include <iostream>

// 2024/01/07: 自己不看答案实现.

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
