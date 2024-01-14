#include <iostream>
#include <stack>
#include <string>
#include <vector>

// 2024/10/14: 动态规划, 看完视频题解之后自己实现.
int LongestValidParentheses(const std::string& s) {
  int n = s.size();
  // dp[i]表示以i位置结尾的最长有效括号子串的长度.
  std::vector<int> dp(n, 0);
  int res = 0;
  for (int i = 1; i < n; ++i) {
    if (s[i] == '(') {
      continue;
    }
    int j = i - dp[i - 1] - 1;
    if (j < 0 || s[j] != '(') {
      continue;
    }
    dp[i] += 2;
    dp[i] += dp[i - 1];
    if (j - 1 >= 0) {
      dp[i] += dp[j - 1];
    }
    res = std::max(res, dp[i]);
  }
  return res;
}

// 2024/01/14: 直接看答案, 官方题解栈的方法
int LongestValidParentheses2(const std::string& s) {
  std::stack<int> stk;
  stk.push(-1);
  int max_length = 0;
  for (int i = 0; i < s.size(); ++i) {
    if (s[i] == '(') {
      stk.push(i);
    } else {
      stk.pop();
      if (stk.empty()) {
        stk.push(i);
      } else {
        max_length = std::max(max_length, i - stk.top());
      }
    }
  }
  return max_length;
}

// 2024/01/14: 直接看答案, 思路比较难想到, 实现比较简单.
int LongestValidParentheses3(const std::string& s) {
  int left = 0, right = 0;
  int max_length = 0;
  for (int i = 0; i < s.size(); ++i) {
    if (s[i] == '(') {
      ++left;
    } else {
      ++right;
    }
    if (left == right) {
      max_length = std::max(max_length, left + right);
    } else if (right > left) {
      left = 0;
      right = 0;
    }
  }
  left = 0, right = 0;
  for (int i = s.size() - 1; i >= 0; --i) {
    if (s[i] == '(') {
      ++left;
    } else {
      ++right;
    }
    if (left == right) {
      max_length = std::max(max_length, left + right);
    } else if (right < left) {
      left = 0;
      right = 0;
    }
  }
  return max_length;
}

int main(int argc, char* argv[]) {
  std::string s = "()()(())";
  std::cout << LongestValidParentheses(s) << std::endl;
  return 0;
}
