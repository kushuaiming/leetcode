#include <iostream>
#include <string>
#include <vector>

// 暴力法: 时间复杂度O(mn)
int StrStr(const std::string& haystack, const std::string& needle) {
  const int m = haystack.size();
  const int n = needle.size();
  for (int i = 0; i < m - n + 1; ++i) {
    if (haystack.substr(i, n) == needle) {
      return i;
    }
  }
  return -1;
}

// KMP
int StrStr2(std::string& s, std::string& p) {
  int n = s.size(), m = p.size();
  if (m == 0) return 0;
  // 设置哨兵
  s.insert(s.begin(), ' ');
  p.insert(p.begin(), ' ');
  std::vector<int> next(m + 1);
  // 预处理next数组, 数组中每个位置的值就是该下标应该跳转的目标位置
  for (int i = 2, j = 0; i <= m; i++) {
    while (j && p[i] != p[j + 1]) {
      j = next[j];
    }
    if (p[i] == p[j + 1]) {
      j++;
    }
    next[i] = j;
  }
  // 匹配过程
  for (int i = 1, j = 0; i <= n; i++) {
    while (j && s[i] != p[j + 1]) {
      j = next[j];
    }
    if (s[i] == p[j + 1]) {
      j++;
    }
    if (j == m) {
      return i - m;
    }
  }
  return -1;
}

// TODO(2024/01/01): 了解 KMP 细节问题.
// KMP 官方解答, 算法的核心为前缀函数, pi(i).
int StrStr3(std::string& haystack, std::string& needle) {
  int n = haystack.size(), m = needle.size();
  if (m == 0) {
    return 0;
  }
  std::vector<int> pi(m);
  for (int i = 1, j = 0; i < m; ++i) {
    while (j > 0 && needle[i] != needle[j]) {
      j = pi[j - 1];
    }
    if (needle[i] == needle[j]) {
      ++j;
    }
    pi[i] = j;
  }
  for (int i = 0, j = 0; i < n; ++i) {
    while (j > 0 && haystack[i] != needle[j]) {
      j = pi[j - 1];
    }
    if (haystack[i] == needle[j]) {
      ++j;
    }
    if (j == m) {
      return i - m + 1;
    }
  }
  return -1;
}

int main(int argc, char* argv[]) {
  std::string haystack = "sadbutsad";
  std::string needle = "sad";
  std::cout << StrStr2(haystack, needle) << std::endl;
  return 0;
}
