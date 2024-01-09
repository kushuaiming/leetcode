#include <vector>
#include <climits>

#include "../tree_node.h"

// 2024/01/09: 自己实现了中序遍历版本.

bool IsValidBST(TreeNode* root) {
  std::vector<int> inordered_traversal;
  inorderedTraversal(inordered_traversal, root);
  for (int i = 0; i < inordered_traversal.size() - 1; ++i) {
    if (inordered_traversal[i] >= inordered_traversal[i + 1]) {
      return false;
    }
  }
  return true;
}

void inorderedTraversal(std::vector<int>& inordered_traversal, TreeNode* root) {
  if (root == nullptr) {
    return;
  }
  inorderedTraversal(inordered_traversal, root->left);
  inordered_traversal.push_back(root->val);
  inorderedTraversal(inordered_traversal, root->right);
}

// 2024/01/09: 递归版本, 直接看的答案
bool Helper(TreeNode* root, long long lower, long long upper) {
  if (root == nullptr) {
    return true;
  }
  if (root->val <= lower || root->val >= upper) {
    return false;
  }
  return Helper(root->left, lower, root->val) &&
         Helper(root->right, root->val, upper);
}

bool IsValidBST(TreeNode* root) { return Helper(root, LONG_MIN, LONG_MAX); }
