#include <vector>

struct ListNode {
  int val;
  ListNode* next;
  ListNode() : val(0), next(nullptr) {}
  ListNode(int x) : val(x), next(nullptr) {}
  ListNode(int x, ListNode* next) : val(x), next(next) {}
};

// 2024/01/07: 自己写出来: 将值复制到数组中后用双指针法
bool IsPalindrome(ListNode* head) {
  std::vector<int> res;
  while (head) {
    res.push_back(head->val);
    head = head->next;
  }
  int left = 0, right = res.size() - 1;
  while (left <= right) {
    if (res[left++] != res[right--]) {
      return false;
    }
  }
  return true;
}

// 2024/01/07: 抄的答案, 递归方法. 不需要记忆.
bool RecursivelyCheck(ListNode* current_node) {
  if (current_node) {
    if (!RecursivelyCheck(current_node->next)) {
      return false;
    }
    if (current_node->val != front_pointer_->val) {
      return false;
    }
    front_pointer_ = front_pointer_->next;
  }
  return true;
}
ListNode* front_pointer_;
bool isPalindrome2(ListNode* head) {
  front_pointer_ = head;
  return RecursivelyCheck(head);
}

// 找到前半部分链表的尾节点
// 反转后半部分链表
// 判断是否回文
// 恢复链表
// 返回结果
bool IsPalindrome3(ListNode* head) {
  if (head == nullptr) {
    return true;
  }

  // 找到前半部分链表的尾节点并反转后半部分链表
  ListNode* first_half_end = EndOfFirstHalf(head);
  ListNode* second_half_start = ReverseList(first_half_end->next);

  // 判断是否回文
  ListNode* p1 = head;
  ListNode* p2 = second_half_start;
  bool result = true;
  while (result && p2 != nullptr) {
    if (p1->val != p2->val) {
      result = false;
    }
    p1 = p1->next;
    p2 = p2->next;
  }

  // 还原链表并返回结果
  first_half_end->next = ReverseList(second_half_start);
  return result;
}

ListNode* ReverseList(ListNode* head) {
  ListNode* prev = nullptr;
  ListNode* curr = head;
  while (curr != nullptr) {
    ListNode* next = curr->next;
    curr->next = prev;
    prev = curr;
    curr = next;
  }
  return prev;
}

ListNode* EndOfFirstHalf(ListNode* head) {
  ListNode* fast = head;
  ListNode* slow = head;
  while (fast->next != nullptr && fast->next->next != nullptr) {
    fast = fast->next->next;
    slow = slow->next;
  }
  return slow;
}