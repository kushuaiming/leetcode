#include <vector>

#include "../tree_node.h"

// 2024/01/09: 自己实现了中序遍历版本
int KthSmallest(TreeNode* root, int k) {
  std::vector<int> inordered_traversal;
  InorderedTraversal(inordered_traversal, root);
  return inordered_traversal[k - 1];
}

void InorderedTraversal(std::vector<int>& inordered_traversal, TreeNode* root) {
  if (root == nullptr) {
    return;
  }
  InorderedTraversal(inordered_traversal, root->left);
  inordered_traversal.push_back(root->val);
  InorderedTraversal(inordered_traversal, root->right);
}
