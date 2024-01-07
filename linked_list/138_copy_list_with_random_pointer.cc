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