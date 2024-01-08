// 2024/01/07: 不看答案自己写出来了.
struct ListNode {
  int val;
  ListNode* next;
  ListNode() : val(0), next(nullptr) {}
  ListNode(int x) : val(x), next(nullptr) {}
  ListNode(int x, ListNode* next) : val(x), next(next) {}
};

ListNode* addTwoNumbers(ListNode* l1, ListNode* l2) {
  int carry = 0;
  ListNode* dummy = new ListNode();
  ListNode* curr = dummy;
  while (l1 || l2) {
    int sum = (l1 ? l1->val : 0) + (l2 ? l2->val : 0) + carry;
    carry = sum / 10;
    sum = sum % 10;
    curr->next = new ListNode(sum);
    curr = curr->next;
    if (l1) {
      l1 = l1->next;
    }
    if (l2) {
      l2 = l2->next;
    }
  }
  if (carry == 1) {
    curr->next = new ListNode(carry);
  }
  return dummy->next;
}