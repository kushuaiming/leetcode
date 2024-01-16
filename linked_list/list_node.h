#ifndef LIST_NODE_H_
#define LIST_NODE_H_

struct ListNode {
  int val;
  ListNode* next;
  ListNode() : val(0), next(nullptr) {}
  ListNode(int x) : val(x), next(nullptr) {}
  ListNode(int x, ListNode* next) : val(x), next(next) {}
};

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

#endif
