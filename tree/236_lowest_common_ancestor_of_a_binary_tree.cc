#include "tree_node.h"

// 2024/01/10: 直接抄答案

TreeNode* res;

// root的整颗树是否含有p或者q.
bool Dfs(TreeNode* root, TreeNode* p, TreeNode* q) {
  if (root == nullptr) {
    return false;
  }
  bool left_son = Dfs(root->left, p, q);
  bool right_son = Dfs(root->right, p, q);
  if ((left_son && right_son) ||
      ((root->val == p->val || root->val == q->val) &&
       (left_son || right_son))) {
    res = root;
  }
  return left_son || right_son || root->val == p->val || root->val == q->val;
}

TreeNode* LowestCommonAncestor(TreeNode* root, TreeNode* p, TreeNode* q) {
  Dfs(root, p, q);
  return res;
}
