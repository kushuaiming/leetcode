#include <tuple>
#include <utility>

struct ListNode {
  int val;
  ListNode* next;
  ListNode() : val(0), next(nullptr) {}
  ListNode(int x) : val(x), next(nullptr) {}
  ListNode(int x, ListNode* next) : val(x), next(next) {}
};

// 2024/01/14: 直接抄答案
// 翻转一个子链表，并且返回新的头与尾
std::pair<ListNode*, ListNode*> MyReverse(ListNode* head, ListNode* tail) {
  ListNode* prev = tail->next;
  ListNode* curr = head;
  while (prev != tail) {
    ListNode* next = curr->next;
    curr->next = prev;
    prev = curr;
    curr = next;
  }
  return {tail, head};
}

ListNode* ReverseKGroup(ListNode* head, int k) {
  ListNode* dummy_node = new ListNode(0);
  dummy_node->next = head;
  ListNode* prev = dummy_node;

  while (head) {
    ListNode* tail = prev;
    // 查看剩余部分长度是否大于等于 k
    for (int i = 0; i < k; ++i) {
      tail = tail->next;
      if (!tail) {
        return dummy_node->next;
      }
    }
    ListNode* next = tail->next;
    // 这里是 C++17 的写法，也可以写成
    // std::pair<ListNode*, ListNode*> result = MyReverse(head, tail);
    // head = result.first;
    // tail = result.second;
    std::tie(head, tail) = MyReverse(head, tail);
    // 把子链表重新接回原链表
    prev->next = head;
    tail->next = next;
    prev = tail;
    head = tail->next;
  }

  return dummy_node->next;
}
