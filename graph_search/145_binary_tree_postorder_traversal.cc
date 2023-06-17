#include <iostream>
#include <stack>
#include <vector>

struct TreeNode {
  int value;
  TreeNode* left;
  TreeNode* right;
  TreeNode() : value(0), left(nullptr), right(nullptr) {}
  TreeNode(int x) : value(x), left(nullptr), right(nullptr) {}
  TreeNode(int x, TreeNode* left, TreeNode* right)
      : value(x), left(left), right(right) {}
};

void Postorder(TreeNode* root, std::vector<int>& result) {
  if (root == nullptr) {
    return;
  }
  Postorder(root->left, result);
  Postorder(root->right, result);
  result.push_back(root->value);
}

std::vector<int> PostorderTraversal(TreeNode* root) {
  std::vector<int> result;
  Postorder(root, result);
  return result;
}

int main(int argc, char* argv[]) {
  TreeNode* node_1 = new TreeNode(1);
  TreeNode* node_2 = new TreeNode(2);
  TreeNode* node_3 = new TreeNode(3);
  node_1->right = node_2;
  node_2->left = node_3;
  std::vector<int> result = PostorderTraversal(node_1);
  for (int value : result) {
    std::cout << value << '\t';
  }
  std::cout << std::endl;
  delete node_1;
  delete node_2;
  delete node_3;
  return 0;
}
