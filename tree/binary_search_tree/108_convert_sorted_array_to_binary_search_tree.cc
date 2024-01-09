#include <vector>

#include "tree_node.h"

// 2024/01/09: 完全不看答案自己实现

TreeNode* SortedArrayToBST(const std::vector<int>& nums) {
  return SortedArrayToBST(nums, 0, nums.size() - 1);
}

// [left, right]
TreeNode* SortedArrayToBST(const std::vector<int>& nums, int left, int right) {
  if (left > right) {
    return nullptr;
  }
  int mid = left + (right - left) / 2;
  TreeNode* root = new TreeNode(nums[mid]);
  root->left = SortedArrayToBST(nums, left, mid - 1);
  root->right = SortedArrayToBST(nums, mid + 1, right);
  return root;
}