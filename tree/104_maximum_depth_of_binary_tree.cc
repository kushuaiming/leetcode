#include <algorithm>
#include <queue>
#include <vector>

struct TreeNode {
  int val;
  TreeNode* left;
  TreeNode* right;
  TreeNode() : val(0), left(nullptr), right(nullptr) {}
  TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
  TreeNode(int x, TreeNode* left, TreeNode* right)
      : val(x), left(left), right(right) {}
};

// 2023/12/21: 可以不看答案自己写出来递归.
int MaxDepth(TreeNode* root) {
  if (root == nullptr) {
    return 0;
  }
  return std::max(MaxDepth(root->left), MaxDepth(root->right)) + 1;
}

int MaxDepth(TreeNode* root) {
  if (root == nullptr) {
    return 0;
  }
  std::queue<TreeNode*> q;
  q.push(root);
  int ans = 0;
  while (!q.empty()) {
    ++ans;
    int count = q.size(); // 维护一个size
    while (count > 0) {
      TreeNode* tree_node = q.front();
      q.pop();
      if (tree_node->left) {
        q.push(tree_node->left);
      }
      if (tree_node->right) {
        q.push(tree_node->right);
      }
      --count;
    }
  }

  return ans;
}
