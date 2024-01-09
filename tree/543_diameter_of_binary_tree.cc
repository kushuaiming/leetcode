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

// 2024/01/07: 自己做出来了从上到下的版本, 没有做出来从下到上的版本.
// 2024/01/02: 在做了110的前提下可以自己写出来.
int res = 0;

int Depth(TreeNode* root) {
  if (root == nullptr) {
    return 0;
  }
  const int left_depth = Depth(root->left);
  const int right_depth = Depth(root->right);
  res = std::max(res, left_depth + right_depth);
  return std::max(left_depth, right_depth) + 1;
}

int DiameterOfBinaryTree(TreeNode* root) {
  Depth(root);
  return res;
}
