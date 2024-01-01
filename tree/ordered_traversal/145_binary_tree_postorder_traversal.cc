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

// 主要思想:
// 由于在某颗子树访问完成以后, 接着就要回溯到其父节点去
// 因此可以用prev来记录访问历史, 在回溯到父节点时, 可以由此来判断, 上一个访问的节点是否为右子树.
std::vector<int> PostTraversalIteration(TreeNode* root) {
  std::vector<int> result;
  std::stack<TreeNode*> stack;
  TreeNode* prev = nullptr;
  while (root != nullptr || !stack.empty()) {
    while (root != nullptr) {
      stack.push(root);
      root = root->left;
    }
    //从栈中弹出的元素, 左子树一定是访问完了的
    root = stack.top();
    stack.pop();
    // 现在需要确定的是是否有右子树, 或者右子树是否访问过.
    // 如果没有右子树, 或者右子树访问完了, 也就是上一个访问的节点是右子节点时,
    // 说明可以访问当前节点.
    if (root->right == nullptr || root->right == prev) {
      result.push_back(root->value);
      // 更新历史访问记录, 这样回溯的时候父节点可以由此判断右子树是否访问完成
      prev = root;
      root = nullptr;
    } else {
      // 如果右子树没有被访问, 那么将当前节点压栈, 访问右子树
      stack.push(root);
      root = root->right;
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
