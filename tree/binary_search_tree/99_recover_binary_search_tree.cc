#include <vector>

#include "tree_node.h"

// 2024/01/03: 完全没有思路, 想不到用中序遍历.

// 关键在于理解在一个递增序列中交换两个值, 会造成一个或者两个位置不满足升序条件.
void RecoverTree(TreeNode* root) {
  TreeNode* mistake1 = nullptr;
  TreeNode* mistake2 = nullptr;
  TreeNode* prev = nullptr;
  Inorder(root, mistake1, mistake2, prev);
  if (mistake1 && mistake2) {
    const int temp = mistake1->val;
    mistake1->val = mistake2->val;
    mistake2->val = temp;
  }
}

// 隐式中序遍历, 注意要改变指针本身, 需要用到引用
void Inorder(TreeNode* root, TreeNode*& mistake1, TreeNode*& mistake2,
             TreeNode*& prev) {
  if (root == nullptr) {
    return;
  }
  if (root->left) {
    Inorder(root->left, mistake1, mistake2, prev);
  }
  if (prev && root->val < prev->val) {
    if (mistake1 == nullptr) {
      mistake1 = prev;
      mistake2 = root;
    } else {
      mistake2 = root;
    }
  }
  prev = root; // 关键步骤: 记录中序遍历的上一个节点.
  if (root->right) {
    Inorder(root->right, mistake1, mistake2, prev);
  }
}

void RecoverTree2(TreeNode* root) {
  std::vector<TreeNode*> inorder_results;
  Inorder2(root, inorder_results);
  std::vector<TreeNode*> mistakes;
  for (int i = 0; i < inorder_results.size() - 1; ++i) {
    if (inorder_results[i]->val > inorder_results[i + 1]->val) {
      if (mistakes.empty()) {
        mistakes.push_back(inorder_results[i]);
        mistakes.push_back(inorder_results[i + 1]);
      } else {
        mistakes.push_back(inorder_results[i + 1]);
      }
    }
  }
  TreeNode* mistake1 = mistakes.front();
  TreeNode* mistake2 = mistakes.back();
  if (mistake1 && mistake2) {
    const int temp = mistake1->val;
    mistake1->val = mistake2->val;
    mistake2->val = temp;
  }
}

// 显式中序遍历
void Inorder2(TreeNode* root, std::vector<TreeNode*>& inorder_results) {
  if (root == nullptr) {
    return;
  }
  Inorder2(root->left, inorder_results);
  inorder_results.push_back(root);
  Inorder2(root->right, inorder_results);
}