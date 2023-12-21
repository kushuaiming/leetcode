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

int ans = 0;

int Depth(TreeNode* root) {
  if (root == nullptr) {
    return 0;
  }
  const int left_depth = Depth(root->left);
  const int right_depth = Depth(root->right);
  ans = std::max(ans, left_depth + right_depth + 1);
  return std::max(left_depth, right_depth) + 1;
}

int DiameterOfBinaryTree(TreeNode* root) {
  Depth(root);
  return ans - 1;
}
