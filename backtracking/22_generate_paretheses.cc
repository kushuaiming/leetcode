#include <string>
#include <vector>

// 2024/01/11: 直接抄答案
void Backtrack(std::vector<std::string>& ans, std::string& cur, int open,
               int close, int n) {
  if (cur.size() == n * 2) {
    ans.push_back(cur);
    return;
  }
  if (open < n) {
    cur.push_back('(');
    Backtrack(ans, cur, open + 1, close, n);
    cur.pop_back();
  }
  if (close < open) {
    cur.push_back(')');
    Backtrack(ans, cur, open, close + 1, n);
    cur.pop_back();
  }
}

std::vector<std::string> GenerateParenthesis(int n) {
  std::vector<std::string> result;
  std::string current;
  Backtrack(result, current, 0, 0, n);
  return result;
}
