struct ListNode {
  int val;
  ListNode* next;
  ListNode() : val(0), next(nullptr) {}
  ListNode(int x) : val(x), next(nullptr) {}
  ListNode(int x, ListNode* next) : val(x), next(next) {}
};

// 2024/01/08: 直接抄答案.
// O(nlogn)的排序算法中, 最适合链表的是归并排序.
// 自顶向下归并排序.
// 1. 找到链表中点, 以中点为分界, 将链表拆分成两个子链表.
// 2. 对两个子链表分别排序
// 3. 将两个排序后的子链表合并. 参考: 21. 合并两个有序链表.
ListNode* SortList1(ListNode* head) { return SortList1(head, nullptr); }

ListNode* SortList1(ListNode* head, ListNode* tail) {
  if (head == nullptr) {
    return head;
  }
  if (head->next == tail) {
    head->next = nullptr;
    return head;
  }
  ListNode *slow = head, *fast = head;
  while (fast != tail) {
    slow = slow->next;
    fast = fast->next;
    if (fast != tail) {
      fast = fast->next;
    }
  }
  ListNode* mid = slow;
  return Merge(SortList1(head, mid), SortList1(mid, tail));
}

ListNode* Merge(ListNode* head1, ListNode* head2) {
  ListNode* dummyHead = new ListNode(0);
  ListNode *temp = dummyHead, *temp1 = head1, *temp2 = head2;
  while (temp1 != nullptr && temp2 != nullptr) {
    if (temp1->val <= temp2->val) {
      temp->next = temp1;
      temp1 = temp1->next;
    } else {
      temp->next = temp2;
      temp2 = temp2->next;
    }
    temp = temp->next;
  }
  if (temp1 != nullptr) {
    temp->next = temp1;
  } else if (temp2 != nullptr) {
    temp->next = temp2;
  }
  return dummyHead->next;
}

// 2024/01/08: 直接抄答案.
// 自底向上归并排序
ListNode* SortList2(ListNode* head) {
  if (head == nullptr) {
    return head;
  }
  // 求链表的长度.
  int length = 0;
  ListNode* node = head;
  while (node != nullptr) {
    length++;
    node = node->next;
  }
  ListNode* dummy_head = new ListNode(0, head);
  // 1. sub_length 表示每次需要排序的链表长度, 初始值为1.
  // 2. 每次将链表拆分成若干个长度为 sub_length 的子链表,
  // 按照每两个子链表一组进行合并.
  // 3. 将 sub_length 的值翻倍, 重复第二步.
  for (int sub_length = 1; sub_length < length; sub_length <<= 1) {
    ListNode *prev = dummy_head, *curr = dummy_head->next;
    while (curr != nullptr) {
      ListNode* head1 = curr;
      for (int i = 1; i < sub_length && curr->next != nullptr; i++) {
        curr = curr->next;
      }
      ListNode* head2 = curr->next;
      curr->next = nullptr;
      curr = head2;
      for (int i = 1;
           i < sub_length && curr != nullptr && curr->next != nullptr; i++) {
        curr = curr->next;
      }
      ListNode* next = nullptr;
      if (curr != nullptr) {
        next = curr->next;
        curr->next = nullptr;
      }
      ListNode* merged = Merge(head1, head2);
      prev->next = merged;
      while (prev->next != nullptr) {
        prev = prev->next;
      }
      curr = next;
    }
  }
  return dummy_head->next;
}
