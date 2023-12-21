#include <iostream>

struct ListNode {
  int val;
  ListNode* next;
  ListNode() : val(0), next(nullptr) {}
  ListNode(int x) : val(x), next(nullptr) {}
  ListNode(int x, ListNode* next) : val(x), next(next) {}
};

// Recursion:
ListNode* MergeTwoLists(ListNode* list1, ListNode* list2) {
  if (list1 == nullptr) {
    return list2;
  }
  if (list2 == nullptr) {
    return list1;
  }
  if (list1->val < list2->val) {
    list1->next = MergeTwoLists(list1->next, list2);
    return list1;
  } else {
    list2->next = MergeTwoLists(list1, list2->next);
    return list2;
  }
}

// Iteration:
ListNode* MergeTwoLists(ListNode* list1, ListNode* list2) {
  ListNode* dummy_node = new ListNode(-1);
  ListNode* prev = dummy_node;
  while (list1 && list2) {
    if (list1->val < list2->val) {
      prev->next = list1;
      list1 = list1->next;
    } else {
      prev->next = list2;
      list2 = list2->next;
    }
    prev = prev->next;
  }
  prev->next = list1 ? list1 : list2;
  return dummy_node->next;
}

int main(int argc, char* argv[]) {
  ListNode node3(4);
  ListNode node2(2, &node3);
  ListNode node1(1, &node2);
  ListNode* list1 = &node1;

  ListNode node6(4);
  ListNode node5(3, &node6);
  ListNode node4(1, &node5);
  ListNode* list2 = &node4;
}
