#include <iostream>

struct TreeNode {
  char val;
  TreeNode* left;
  TreeNode* right;
  TreeNode* parent;
  TreeNode() : val(0), left(nullptr), right(nullptr), parent(nullptr) {}
  TreeNode(char x) : val(x), left(nullptr), right(nullptr), parent(nullptr) {}
  TreeNode(char x, TreeNode* left, TreeNode* right, TreeNode* parent)
      : val(x), left(left), right(right), parent(parent) {}
};

TreeNode* GetNext(TreeNode* node) {
  if (node == nullptr) {
    return nullptr;
  }

  TreeNode* next = nullptr;
  if (node->right) {
    // 如果一个节点有右子树, 那么它的下一个节点就是它的右子树中的最左子节点.
    TreeNode* right_node = node->right;
    while (right_node->left) {
      right_node = right_node->left;
    }
    next = right_node;
  } else if (node->parent) {
    // 如果节点是它父节点的左子节点, 那么它的下一个节点就是它的父节点.
    // 如果节点是它父节点的右子节点, 沿着指向父节点的指针一直向上遍历,
    // 直到找到一个是它父节点的左子节点的节点. 如果这样的节点存在,
    // 那么这个节点的父节点就是我们要找的下一个节点.
    TreeNode* curr = node;
    TreeNode* parent_node = node->parent;
    while (parent_node && curr == parent_node->right) {
      curr = parent_node;
      parent_node = parent_node->parent;
    }
    next = parent_node;
  }
  return next;
}

int main(int argc, char* argv[]) {
  TreeNode* node_a = new TreeNode('a');
  TreeNode* node_b = new TreeNode('b');
  TreeNode* node_c = new TreeNode('c');
  TreeNode* node_d = new TreeNode('d');
  TreeNode* node_e = new TreeNode('e');
  TreeNode* node_f = new TreeNode('f');
  TreeNode* node_g = new TreeNode('g');
  TreeNode* node_h = new TreeNode('h');
  TreeNode* node_i = new TreeNode('i');

  node_a->left = node_b;
  node_a->right = node_c;

  node_b->left = node_d;
  node_b->right = node_e;
  node_b->parent = node_a;

  node_c->left = node_f;
  node_c->right = node_g;
  node_c->parent = node_a;

  node_d->parent = node_b;

  node_e->left = node_h;
  node_e->right = node_i;
  node_e->parent = node_b;

  node_f->parent = node_c;
  node_g->parent = node_c;
  node_h->parent = node_e;
  node_i->parent = node_e;

  std::cout << GetNext(node_g)->val << std::endl;
  return 0;
}
