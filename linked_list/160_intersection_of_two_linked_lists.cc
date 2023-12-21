#include <iostream>
#include <set>

struct ListNode {
  int val;
  ListNode* next;
  ListNode() : val(0), next(nullptr) {}
  ListNode(int x) : val(x), next(nullptr) {}
  ListNode(int x, ListNode* next) : val(x), next(next) {}
};

// 双指针
ListNode* GetIntersectionNode(ListNode* headA, ListNode* headB) {
  ListNode* head_a = headA;
  ListNode* head_b = headB;
  while (head_a != head_b) {
    if (head_a) {
      head_a = head_a->next;
    } else {
      head_a = headB;
    }
    if (head_b) {
      head_b = head_b->next;
    } else {
      head_b = headA;
    }
  }
  return head_a;
}

// 哈希表
ListNode* GetIntersectionNode(ListNode* headA, ListNode* headB) {
  std::set<ListNode*> hash_map;
  ListNode* head_a = headA;
  ListNode* head_b = headB;
  while (head_a) {
    hash_map.insert(head_a);
    head_a = head_a->next;
  }
  while (head_b) {
    if (hash_map.count(head_b)) {
      return head_b;
    }
    head_b = head_b->next;
  }
  return nullptr;
}
