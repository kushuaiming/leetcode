// 2023/12/20: 可以不看答案自己写出来.
// 2023/12/31: 可以不看答案自己写出来.
#include <iostream>
#include <string>
#include <vector>

// 动态规划
int CountSubstrings(const std::string& s) {
  const int n = s.size();
  std::vector<std::vector<int>> is_palindromic(n, std::vector<int>(n, 0));
  for (int i = 0; i < n; ++i) {
    is_palindromic[i][i] = 1;
  }
  for (int i = n - 1; i >= 0; --i) {
    for (int j = i + 1; j < n; ++j) {
      if (s[i] == s[j]) {
        if (j == i + 1) {
          is_palindromic[i][j] = 1;
        } else {
          is_palindromic[i][j] = is_palindromic[i + 1][j - 1];
        }
      } else {
        is_palindromic[i][j] = 0;
      }
    }
  }
  int count = 0;
  for (int i = n - 1; i >= 0; --i) {
    for (int j = i; j < n; ++j) {
      if (is_palindromic[i][j]) {
        ++count;
      }
    }
  }
  return count;
}

int ExtendSubstrings(const std::string& s, int left, int right) {
  int count = 0;
  while (left >= 0 && right < static_cast<int>(s.size()) &&
         s[left] == s[right]) {
    --left;
    ++right;
    ++count;
  }
  return count;
}

// 中心拓展法: 从字符串每个位置开始, 向左向右延长,
// 判断存在多少以当前位置为中轴的回文子字符串
int CountSubstrings2(const std::string& s) {
  int count = 0;
  for (int i = 0; i < static_cast<int>(s.size()); ++i) {
    count += ExtendSubstrings(s, i, i);      // 奇数长度
    count += ExtendSubstrings(s, i, i + 1);  // 偶数长度
  }
  return count;
}

int main(int argc, char* argv[]) {
  const std::string s = "aaa";
  std::cout << CountSubstrings2(s) << std::endl;
  return 0;
}
