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

// 2023/12/21: 可以不看答案自己写出来.
std::vector<double> AverageOfLevels(TreeNode* root) {
  std::vector<double> ans;
  if (root == nullptr) {
    return ans;
  }
  std::queue<TreeNode*> q;
  q.push(root);
  while (!q.empty()) {
    const int count = q.size();
    double sum = 0;
    for (int i = 0; i < count; ++i) {
      sum += q.front()->val;
      if (q.front()->left) {
        q.push(q.front()->left);
      }
      if (q.front()->right) {
        q.push(q.front()->right);
      }
      q.pop();
    }
    ans.push_back(sum / count);
  }
  return ans;
}
