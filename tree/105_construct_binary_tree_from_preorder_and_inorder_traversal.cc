#include <unordered_map>
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

std::unordered_map<int, int> index;
// 注意函数参数的选择. [preorder_left, preorder_right], [inorder_left,
// inorder_right], 都是闭区间.
// TODO: 学习官方的迭代方法, 这里暂时只记忆递归方法.
TreeNode* BuildTree(const std::vector<int>& preorder,
                    const std::vector<int>& inorder, int preorder_left,
                    int preorder_right, int inorder_left, int inorder_right) {
  if (preorder_right < preorder_left || inorder_right < inorder_left) {
    return nullptr;
  }
  const int root_val = preorder[preorder_left];
  TreeNode* root = new TreeNode(root_val);
  const int root_index = index[root_val];
  const int left_node_count = root_index - inorder_left;
  root->left =
      BuildTree(preorder, inorder, preorder_left + 1,
                preorder_left + left_node_count, inorder_left, root_index - 1);
  root->right =
      BuildTree(preorder, inorder, preorder_left + left_node_count + 1,
                preorder_right, root_index + 1, inorder_right);
  return root;
}

TreeNode* BuildTree(const std::vector<int>& preorder,
                    const std::vector<int>& inorder) {
  for (int i = 0; i < inorder.size(); ++i) {
    index[inorder[i]] = i;
  }
  return BuildTree(preorder, inorder, 0, preorder.size() - 1, 0,
                   inorder.size() - 1);
}
