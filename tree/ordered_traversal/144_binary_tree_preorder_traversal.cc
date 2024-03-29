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

void Preorder(TreeNode* root, std::vector<int>& result) {
  if (root == nullptr) {
    return;
  }
  result.push_back(root->value);
  Preorder(root->left, result);
  Preorder(root->right, result);
}

std::vector<int> PreorderTraversal(TreeNode* root) {
  std::vector<int> result;
  Preorder(root, result);
  return result;
}

std::vector<int> PreorderTraversalIteration(TreeNode* root) {
  std::vector<int> result;
  std::stack<TreeNode*> stk;
  while (root || !stk.empty()) {
    while (root) {
      result.push_back(root->value);
      stk.push(root);
      root = root->left;
    }
    root = stk.top();
    stk.pop();
    root = root->right;
  }
  return result;
}

std::vector<int> PreorderTraversalIteration2(TreeNode* root) {
  std::vector<int> result;
  if (!root) {
    return result;
  }
  std::stack<TreeNode*> stack;
  stack.push(root);
  while (!stack.empty()) {
    TreeNode* node = stack.top();
    stack.pop();
    result.push_back(node->value);
    if (node->right) {
      stack.push(node->right);
    }
    if (node->left) {
      stack.push(node->left);
    }
  }
  return result;
}

int main(int argc, char* argv[]) {
  TreeNode* node_1 = new TreeNode(1);
  TreeNode* node_2 = new TreeNode(2);
  TreeNode* node_3 = new TreeNode(3);
  node_1->right = node_2;
  node_2->left = node_3;
  std::vector<int> result = PreorderTraversal(node_1);
  for (int value : result) {
    std::cout << value << '\t';
  }
  std::cout << std::endl;
  delete node_1;
  delete node_2;
  delete node_3;
  return 0;
}
