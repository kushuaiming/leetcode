#include <queue>

struct TreeNode {
  int val;
  TreeNode* left;
  TreeNode* right;
  TreeNode() : val(0), left(nullptr), right(nullptr) {}
  TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
  TreeNode(int x, TreeNode* left, TreeNode* right)
      : val(x), left(left), right(right) {}
};

// Recursion:
bool IsSymmetric(TreeNode* root) {
  if (root == nullptr) {
    return true;
  }
  return IsSymmetric(root->left, root->right);
}

bool IsSymmetric(TreeNode* left, TreeNode* right) {
  if (left == nullptr && right == nullptr) {
    return true;
  }
  if (left == nullptr || right == nullptr) {
    return false;
  }
  if (left->val != right->val) {
    return false;
  }
  return IsSymmetric(left->left, right->right) &&
         IsSymmetric(left->right, right->left);
}

// Iteration:
bool Check(TreeNode* left, TreeNode* right) {
  std::queue<TreeNode*> q;
  q.push(left);
  q.push(right);
  while (!q.empty()) {
    left = q.front();
    q.pop();
    right = q.front();
    q.pop();
    if (!left && !right) {
      continue;
    }
    if (!left || !right || left->val != right->val) {
      return false;
    }
    q.push(left->left);
    q.push(right->right);
    q.push(left->right);
    q.push(right->left);
  }
  return true;
}
