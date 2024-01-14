#include <stack>
#include <vector>

// 2024/01/14: 动态规划, 直接看答案, 思路较难想到, 实现较为简单.
// 对于下标 i, 下雨后水能到达的最大高度等于下标 i 两边的最大高度的最小值.
int Trap1(std::vector<int>& height) {
  int n = height.size();
  std::vector<int> left_max(n, 0);
  std::vector<int> right_max(n, 0);
  left_max[0] = height[0];
  for (int i = 1; i < n; ++i) {
    left_max[i] = std::max(left_max[i - 1], height[i]);
  }
  right_max[n - 1] = height[n - 1];
  for (int i = n - 2; i >= 0; --i) {
    right_max[i] = std::max(right_max[i + 1], height[i]);
  }

  int res = 0;
  for (int i = 0; i < n; ++i) {
    res += std::min(left_max[i], right_max[i]) - height[i];
  }
  return res;
}

// 2024/01/14: 单调(递减)栈, 直接抄答案.
int Trap2(std::vector<int>& height) {
  int res = 0;
  std::stack<int> stk;
  int n = height.size();
  for (int i = 0; i < n; ++i) {
    while (!stk.empty() && height[i] > height[stk.top()]) {
      int top = stk.top();
      stk.pop();
      if (stk.empty()) {
        break;
      }
      int left = stk.top();
      int curr_width = i - left - 1;
      int curr_height = std::min(height[left], height[i]) - height[top];
      res += curr_width * curr_height;
    }
    stk.push(i);
  }
  return res;
}

// 2024/01/14: 双指针, 直接抄答案.
int Trap3(std::vector<int>& height) {
  int res = 0;
  int left = 0, right = height.size() - 1;
  int left_max = 0, right_max = 0;
  while (left < right) {
    left_max = std::max(left_max, height[left]);
    right_max = std::max(right_max, height[right]);
    if (height[left] < height[right]) {
      res += left_max - height[left];
      ++left;
    } else {
      res += right_max - height[right];
      --right;
    }
  }
  return res;
}
