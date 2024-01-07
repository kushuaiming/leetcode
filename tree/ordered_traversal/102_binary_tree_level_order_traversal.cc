#include <queue>
#include <vector>

#include "tree_node.h"

std::vector<std::vector<int>> levelOrder(TreeNode* root) {
  if (root == nullptr) {
    return {};
  }
  std::queue<TreeNode*> q;
  q.push(root);
  std::vector<std::vector<int>> res;
  while (!q.empty()) {
    std::vector<int> temp;
    int size = q.size();
    for (int i = 0; i < size; ++i) {
      TreeNode* front = q.front();
      q.pop();
      temp.push_back(front->val);
      if (front->left) {
        q.push(front->left);
      }
      if (front->right) {
        q.push(front->right);
      }
    }
    res.push_back(temp);
  }
  return res;
}
