#include <string>
#include <vector>

// 2024/01/17: 直接看答案. 答案没有完全理解.
// dp[i][j]表示s的前i个字符与p的前j个字符是否能够匹配.
bool IsMatch(const std::string& s, const std::string& p) {
  int m = s.size();
  int n = p.size();

  auto matches = [&](int i, int j) {
    if (i == 0) {
      return false;
    }
    if (p[j - 1] == '.') {
      return true;
    }
    return s[i - 1] == p[j - 1];
  };

  std::vector<std::vector<int>> dp(m + 1, std::vector<int>(n + 1));
  dp[0][0] = true;
  for (int i = 0; i <= m; ++i) {
    for (int j = 1; j <= n; ++j) {
      if (p[j - 1] == '*') {
        dp[i][j] |= dp[i][j - 2];
        if (matches(i, j - 1)) {
          dp[i][j] |= dp[i - 1][j];
        }
      } else {
        if (matches(i, j)) {
          dp[i][j] |= dp[i - 1][j - 1];
        }
      }
    }
  }
  return dp[m][n];
}

// 2024/01/17: 直接看答案 《剑指 Offer》 面试题 19: 正则表达式匹配.
// 递归 + 有限状态机.
bool MatchCore(const std::string& s, const std::string& p, int s_ptr,
               int p_ptr) {
  if (s_ptr == s.size() && p_ptr == p.size()) {
    return true;
  }
  if (s_ptr != s.size() && p_ptr == p.size()) {
    return false;
  }
  if (p[p_ptr + 1] == '*') {
    if (p[p_ptr] == s[s_ptr] || (p[p_ptr] == '.' && s_ptr != s.size())) {
      return MatchCore(s, p, s_ptr + 1, p_ptr + 2) ||  // move on the next state
             MatchCore(s, p, s_ptr + 1, p_ptr) ||  // stay on the current state
             MatchCore(s, p, s_ptr, p_ptr + 2);    // ignore a '*'
    } else {
      return MatchCore(s, p, s_ptr, p_ptr + 2);  // ignore a '*'
    }
  }
  if (p[p_ptr] == s[s_ptr] || (p[p_ptr] == '.' && s_ptr != s.size())) {
    return MatchCore(s, p, s_ptr + 1, p_ptr + 1);
  }
  return false;
}

bool IsMatch2(const std::string& s, const std::string& p) {
  return MatchCore(s, p, 0, 0);
}
