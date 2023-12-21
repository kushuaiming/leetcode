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
bool Check(TreeNode* u, TreeNode* v) {
  std::queue<TreeNode*> q;
  q.push(u);
  q.push(v);
  while(!q.empty()) {
    u = q.front();
    q.pop();
    v = q.front();
    q.pop();

    if (!u && !v) {
      continue;
    }
    if (!u || !v || u->val != v->val) {
      return false;
    }

    q.push(u->left);
    q.push(v->right);

    q.push(u->right);
    q.push(v->left);
  }
  return true;
}
