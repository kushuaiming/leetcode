#include "tree_node.h"

TreeNode* TrimBST(TreeNode* root, int low, int high) {
  if (root == nullptr) {
    return root;
  }
  if (root->val < low) {
    return TrimBST(root->right, low, high);
  }
  if (root->val > high) {
    return TrimBST(root->left, low, high);
  }
  root->left = TrimBST(root->left, low, high);
  root->right = TrimBST(root->right, low, high);
  return root;
}
