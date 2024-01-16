#include <iostream>
#include <stack>

#include "list_node.h"

void PrintListReversingly(ListNode* head) {
  std::stack<ListNode*> s;
  while (head) {
    s.push(head);
    head = head->next;
  }
  while (!s.empty()) {
    std::cout << s.top()->val << std::endl;
    s.pop();
  }
}

int main(int argc, char* argv[]) {
  ListNode* head = new ListNode(1);
  AddToTail(head, 2);
  AddToTail(head, 3);
  AddToTail(head, 4);
  PrintListReversingly(head);
}
