#include <iostream>
#include <stack>
#include <vector>

// 2024/01/12: 看了答案提示的情况下做出来了.

// 维护一个存储下标的单调栈, 从栈底到栈顶的下标对应的温度列表中的温度依次递减.
std::vector<int> DailyTemperatures(const std::vector<int>& temperatures) {
  int n = temperatures.size();
  std::vector<int> ans(n, 0);
  std::stack<int> stack;
  for (int i = 0; i < n; ++i) {
    while (!stack.empty() && temperatures[i] > temperatures[stack.top()]) {
      ans[stack.top()] = i - stack.top();
      stack.pop();
    }
    stack.push(i);
  }
  return ans;
}

int main(int argc, char* argv[]) {
  std::vector<int> temperatures = {73, 74, 75, 71, 69, 72, 76, 73};
  std::vector<int> ans = DailyTemperatures(temperatures);
  for (int answer : ans) {
    std::cout << answer << std::endl;
  }
  return 0;
}
