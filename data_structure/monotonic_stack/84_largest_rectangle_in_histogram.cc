#include <climits>
#include <stack>
#include <vector>

// 2024/01/14: 直接抄答案.

// 暴力枚举"宽"的方法, 会超出时间限制.
int LargestRectangleArea1(std::vector<int>& heights) {
  int n = heights.size();
  int ans = 0;
  // 枚举左边界
  for (int left = 0; left < n; ++left) {
    int min_height = INT_MAX;
    // 枚举右边界
    for (int right = left; right < n; ++right) {
      // 确定高度
      min_height = std::min(min_height, heights[right]);
      // 计算面积
      ans = std::max(ans, (right - left + 1) * min_height);
    }
  }
  return ans;
}

// 暴力枚举"高"的方法, 是优化的基础.
int LargestRectangleArea2(std::vector<int>& heights) {
  int n = heights.size();
  int res = 0;
  for (int mid = 0; mid < n; ++mid) {
    int height = heights[mid];
    int left = mid, right = mid;
    while (left - 1 >= 0 && heights[left - 1] >= height) {
      --left;
    }
    while (right + 1 < n && heights[right + 1] >= height) {
      ++right;
    }
    res = std::max(res, height * (right - left + 1));
  }
  return res;
}

// 在一维数组中对每一个数找到第一个比自己小的元素.
// 这类“在一维数组中找第一个满足某种条件的数”的场景就是典型的单调栈应用场景.

// 视频题解: 单调(递增)栈(不加哨兵版本)
int LargestRectangleArea3(std::vector<int>& heights) {
  // 矩形的宽度等于当前遍历的下标与新栈顶元素的下标的差减1
  // 1. 都遍历完成之后, 栈内元素出栈的时候, 栈顶元素一定可以扩散到数组末尾
  // 2. 出栈后, 栈为空, 当前元素一定可以扩散到数组的最左边.
  // 3. 栈中存在高度相等的元素.

  int n = heights.size();
  if (n == 0) {
    return 0;
  }
  if (n == 1) {
    return heights[0];
  }

  int area = 0;
  std::stack<int> stk;
  for (int i = 0; i < n; ++i) {
    while (!stk.empty() && heights[i] < heights[stk.top()]) {
      int height = heights[stk.top()];
      stk.pop();
      while (!stk.empty() && heights[stk.top()] == height) {
        stk.pop();
      }
      int width;
      if (stk.empty()) {
        width = i;
      } else {
        width = i - stk.top() - 1;
      }
      area = std::max(area, width * height);
    }
    stk.push(i);
  }

  while (!stk.empty()) {
    int height = heights[stk.top()];
    stk.pop();
    while (!stk.empty() && heights[stk.top()] == height) {
      stk.pop();
    }
    int width;
    if (stk.empty()) {
      width = n;
    } else {
      width = n - stk.top() - 1;
    }
    area = std::max(area, width * height);
  }
  return area;
}

// 2024/01/21: 自己实现.
// 视频题解: 单调(递增)栈(加哨兵版本)
int LargestRectangleArea4(std::vector<int>& heights) {
  // 在原始数组的两边加上两个值为0的数作为哨兵(sentinel)
  std::vector<int> sentry_heights;
  sentry_heights.push_back(0);
  sentry_heights.insert(sentry_heights.begin() + 1, heights.begin(),
                        heights.end());
  sentry_heights.push_back(0);

  // 维护一个单调递增的栈.
  std::stack<int> stk;
  stk.push(sentry_heights[0]);
  int res = 0;
  for (int i = 1; i < sentry_heights.size(); ++i) {
    while (sentry_heights[i] < sentry_heights[stk.top()]) {
      int height = sentry_heights[stk.top()];
      stk.pop();
      int width = i - stk.top() - 1;
      res = std::max(res, height * width);
    }
    stk.push(i);
  }
  return res;
}
