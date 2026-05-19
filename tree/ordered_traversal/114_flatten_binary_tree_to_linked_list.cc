#include <stack>
#include <vector>

#include "tree_node.h"

// 2024/01/09: 看答案写出了前序遍历, 注意left和right都要重新赋值.
// TODO: 学习一下前序遍历和展开同时进行.
void Flatten(TreeNode* root) {
  std::vector<TreeNode*> preordered_traversal;
  PreorderedTraversal(preordered_traversal, root);
  for (int i = 1; i < preordered_traversal.size(); ++i) {
    TreeNode* prev = preordered_traversal[i - 1];
    TreeNode* curr = preordered_traversal[i];
    prev->left = nullptr;
    prev->right = curr;
  }
}

void PreorderedTraversal(std::vector<TreeNode*>& preordered_traversal,
                         TreeNode* root) {
  std::stack<TreeNode*> s;
  while (!s.empty() || root) {
    while (root) {
      preordered_traversal.push_back(root);
      s.push(root);
      root = root->left;
    }
    root = s.top();
    s.pop();
    root = root->right;
  }
}
