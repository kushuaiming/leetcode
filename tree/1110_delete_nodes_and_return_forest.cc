#include <unordered_set>
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

// 2023/12/21: 直接抄答案
std::vector<TreeNode*> DelNodes(TreeNode* root, std::vector<int>& to_delete) {
  std::vector<TreeNode*> forest;
  std::unordered_set<int> dict(to_delete.begin(), to_delete.end());
  root = Helper(root, dict, forest);
  if (root) {
    forest.push_back(root);
  }
  return forest;
}

TreeNode* Helper(TreeNode* root, const std::unordered_set<int>& dict,
                 std::vector<TreeNode*>& forest) {
  if (!root) {
    return root;
  }
  root->left = Helper(root->left, dict, forest);
  root->right = Helper(root->right, dict, forest);
  if (dict.count(root->val)) {
    if (root->left) {
      forest.push_back(root->left);
    }
    if (root->right) {
      forest.push_back(root->right);
    }
    root = nullptr;
  }
  return root;
}
