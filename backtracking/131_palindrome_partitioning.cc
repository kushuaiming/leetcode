#include <string>
#include <vector>

// 2024/01/11: 直接抄答案
// 回溯 + 动态规划预处理.
std::vector<std::vector<int>> dp;
std::vector<std::vector<std::string>> ret;
std::vector<std::string> ans;
int n;

void Dfs(const std::string& s, int i) {
  if (i == n) {
    ret.push_back(ans);
    return;
  }
  for (int j = i; j < n; ++j) {
    if (dp[i][j]) {
      ans.push_back(s.substr(i, j - i + 1));
      Dfs(s, j + 1);
      ans.pop_back();
    }
  }
}

std::vector<std::vector<std::string>> Partition(std::string s) {
  n = s.size();
  dp.assign(n, std::vector<int>(n, true));

  for (int i = n - 1; i >= 0; --i) {
    for (int j = i + 1; j < n; ++j) {
      dp[i][j] = (s[i] == s[j]) && dp[i + 1][j - 1];
    }
  }

  Dfs(s, 0);
  return ret;
}
