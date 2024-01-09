#include "tree_node.h"

// 2024/01/09: 自己写出来的版本.
TreeNode* invertTree(TreeNode* root) {
  if (root == nullptr) {
    return root;
  }
  TreeNode* temp = root->left;
  root->left = root->right;
  root->right = temp;
  invertTree(root->left);
  invertTree(root->right);
  return root;
}

// 官方答案
TreeNode* invertTree(TreeNode* root) {
  if (root == nullptr) {
    return root;
  }
  TreeNode* left = invertTree(root->left);
  TreeNode* right = invertTree(root->right);
  root->left = right;
  root->right = left;
  return root;
}
