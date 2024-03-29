struct TreeNode {
  int val;
  TreeNode* left;
  TreeNode* right;
  TreeNode() : val(0), left(nullptr), right(nullptr) {}
  TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
  TreeNode(int x, TreeNode* left, TreeNode* right)
      : val(x), left(left), right(right) {}
};

// 2024/01/09: 不看答案自己实现, 但是代码没有这么简洁.

// Recursion: 递归每个节点时, 需要分情况考虑
// 1) 如果选取该节点加入路径, 则之后必须加入*连续*节点, 或停止加入节点.
// 2) 如果不选取该节点加入路径, 则对其左右节点重新进行考虑.
// 这里target_sum使用long, 因为节点里面的数可能很大
int PathSumStartWithRoot(TreeNode* root, long target_sum) {
  if (root == nullptr) {
    return 0;
  }
  int count = target_sum == root->val ? 1 : 0;
  count += PathSumStartWithRoot(root->left, target_sum - root->val);
  count += PathSumStartWithRoot(root->right, target_sum - root->val);
  return count;
}

int PathSum(TreeNode* root, int target_sum) {
  if (root == nullptr) {
    return 0;
  }
  return PathSumStartWithRoot(root, target_sum) +
         PathSum(root->left, target_sum) + PathSum(root->right, target_sum);
}
