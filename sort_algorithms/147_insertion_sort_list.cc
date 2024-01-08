struct ListNode {
  int val;
  ListNode* next;
  ListNode() : val(0), next(nullptr) {}
  ListNode(int x) : val(x), next(nullptr) {}
  ListNode(int x, ListNode* next) : val(x), next(next) {}
};

// 2024/01/08: 直接抄答案.
ListNode* InsertionSortList(ListNode* head) {
  if (head == nullptr) {
    return head;
  }
  // 引入哑节点是为了便于在 head 之前插入节点.
  ListNode* dummy_head = new ListNode();
  dummy_head->next = head;
  // 链表已排序部分的最后一个节点.
  ListNode* last_sorted = head;
  // 待插入的元素.
  ListNode* curr = head->next;
  while (curr != nullptr) {
    if (last_sorted->val <= curr->val) {
      last_sorted = last_sorted->next;
    } else {
      ListNode* prev = dummy_head;
      while (prev->next->val <= curr->val) {
        prev = prev->next;
      }
      last_sorted->next = curr->next;
      curr->next = prev->next;
      prev->next = curr;
    }
    curr = last_sorted->next;
  }
  return dummy_head->next;
}
