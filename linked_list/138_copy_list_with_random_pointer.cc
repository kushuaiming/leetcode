#include <unordered_map>

class Node {
 public:
  int val;
  Node* next;
  Node* random;

  Node(int _val) {
    val = _val;
    next = nullptr;
    random = nullptr;
  }
};

// 2024/01/07: 自己写出迭代+哈希表版本.
Node* copyRandomList(Node* head) {
  std::unordered_map<Node*, Node*> hash_map;
  Node* curr_node = head;
  while (curr_node) {
    Node* temp_node = new Node(curr_node->val);
    hash_map[curr_node] = temp_node;
    curr_node = curr_node->next;
  }
  curr_node = head;
  while (curr_node) {
    hash_map[curr_node]->next = hash_map[curr_node->next];
    hash_map[curr_node]->random = hash_map[curr_node->random];
    curr_node = curr_node->next;
  }
  return hash_map[head];
}

// 2024/01/07: 直接抄答案, 回溯 + 哈希表
std::unordered_map<Node*, Node*> cached_node_;
Node* CopyRandomList2(Node* head) {
  if (head == nullptr) {
    return nullptr;
  }
  if (!cached_node_.count(head)) {
    Node* head_new = new Node(head->val);
    cached_node_[head] = head_new;
    head_new->next = CopyRandomList2(head->next);
    head_new->random = CopyRandomList2(head->random);
  }
  return cached_node_[head];
}

// 2024/01/07: 直接抄答案, 迭代 + 节点拆分
Node* CopyRandomList(Node* head) {
  if (head == nullptr) {
    return nullptr;
  }
  for (Node* node = head; node != nullptr; node = node->next->next) {
    Node* node_new = new Node(node->val);
    node_new->next = node->next;
    node->next = node_new;
  }
  for (Node* node = head; node != nullptr; node = node->next->next) {
    Node* node_new = node->next;
    node_new->random = node->random ? node->random->next : nullptr;
  }
  Node* head_new = head->next;
  for (Node* node = head; node != nullptr; node = node->next) {
    Node* node_new = node->next;
    node->next = node->next->next;
    node_new->next = node_new->next ? node_new->next->next : nullptr;
  }
  return head_new;
}
