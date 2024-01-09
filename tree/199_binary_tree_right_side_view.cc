#include <queue>
#include <vector>

#include "tree_node.h"

// 2024/01/09: 不看答案自己实现.
std::vector<int> rightSideView(TreeNode* root) {
  if (root == nullptr) {
    return {};
  }
  std::queue<TreeNode*> q;
  q.push(root);
  std::vector<int> res;
  while (!q.empty()) {
    int size = q.size();
    for (int i = 0; i < size; ++i) {
      TreeNode* front = q.front();
      if (i == size - 1) {
        res.push_back(front->val);
      }
      q.pop();
      if (front->left) {
        q.push(front->left);
      }
      if (front->right) {
        q.push(front->right);
      }
    }
  }
  return res;
}
