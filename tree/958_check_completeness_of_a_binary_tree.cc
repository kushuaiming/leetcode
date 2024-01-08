#include <queue>

#include "tree_node.h"

// 将二叉树层序遍历放在队列中, 遇到null之后的所有节点都是null, 则是完全二叉树;
// 遇到null之后, 还有不是null的则是不完全二叉树.
bool isCompleteTree(TreeNode* root) {
  if (root == nullptr) {
    return true;
  }
  std::queue<TreeNode*> q;
  q.push(root);
  bool flag = false;
  while (!q.empty()) {
    int size = q.size();
    for (int i = 0; i < size; ++i) {
      TreeNode* front = q.front();
      q.pop();
      if (front == nullptr) {
        flag = true;
        continue;
      }
      if (flag) {
        return false;
      }
      q.push(front->left);
      q.push(front->right);
    }
  }
  return true;
}
