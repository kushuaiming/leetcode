#include <algorithm>

struct TreeNode {
  int val;
  TreeNode* left;
  TreeNode* right;
  TreeNode() : val(0), left(nullptr), right(nullptr) {}
  TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
  TreeNode(int x, TreeNode* left, TreeNode* right)
      : val(x), left(left), right(right) {}
};

// 自顶向下的方法, 类似于前序遍历.
int Height(TreeNode* root) {
  if (root == nullptr) {
    return 0;
  }
  return std::max(Height(root->left), Height(root->right)) + 1;
}

bool IsBalanced(TreeNode* root) {
  if (root == nullptr) {
    return true;
  }
  return std::abs(Height(root->left) - Height(root->right)) <= 1 &&
         IsBalanced(root->left) && IsBalanced(root->right);
}

// 自底向上的方法, 类似于后序遍历
int Height2(TreeNode* root) {
  if (root == nullptr) {
    return 0;
  }
  const int left_height = Height2(root->left);
  const int right_height = Height2(root->right);
  if (left_height == -1 || right_height == -1 ||
      std::abs(left_height - right_height) > 1) {
    return -1;  // 使用-1表示该节点不平衡
  }
  return std::max(left_height, right_height) + 1;
}

bool IsBalanced2(TreeNode* root) { return Height2(root) >= 0; }
