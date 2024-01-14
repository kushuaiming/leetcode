#include <climits>
#include <iostream>

#include "tree_node.h"

// 2024/01/14: 不看答案自己实现.

int res = INT_MIN;
int MaxPathSumUseRoot(TreeNode* root) {
  if (root == nullptr) {
    return 0;
  }
  int left = MaxPathSumUseRoot(root->left);
  int right = MaxPathSumUseRoot(root->right);
  res = std::max(res,
                 root->val + (left > 0 ? left : 0) + (right > 0 ? right : 0));
  if (left < 0 && right < 0) {
    return root->val;
  }
  return root->val + (left > right ? left : right);
}

int MaxPathSum(TreeNode* root) {
  MaxPathSumUseRoot(root);
  return res;
}

int main(int argc, char* argv[]) {
  TreeNode* node1 = new TreeNode(1);
  TreeNode* node2 = new TreeNode(2);
  TreeNode* node3 = new TreeNode(3);
  node1->left = node2;
  node1->right = node3;
  std::cout << MaxPathSum(node1) << std::endl;
  return 0;
}
