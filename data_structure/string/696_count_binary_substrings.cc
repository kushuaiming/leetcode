#include <iostream>
#include <string>
#include <vector>

// 官方题解: 将0和1分组, 计算每个组的0或1的个数.
// 对于相邻的两个组(u, v), 满足条件的子串数目为 min(u, v).
int CountBinarySubstrings(const std::string& s) {
  std::vector<int> counts;
  int ptr = 0, n = s.size();
  while (ptr < n) {
    int count = 0;
    const char c = s[ptr];
    while (ptr < n && s[ptr] == c) {
      ++ptr;
      ++count;
    }
    counts.push_back(count);
  }
  int ans = 0;
  for (int i = 0; i < static_cast<int>(counts.size()) - 1; ++i) {
    ans += std::min(counts[i], counts[i + 1]);
  }
  return ans;
}

// 从左往右遍历数组, 记录和当前位置数字相同且连续的长度,
// 以及其之前连续不同数字的长度.
// 若不同数字的连续长度大于等于当前数字的连续长度,
// 则有且只有一个已当前数字结尾满足条件的子字符串.
int CountBinarySubstrings(const std::string& s) {
  int pre = 0;
  int cur = 1;
  int count = 0;
  for (int i = 1; i < static_cast<int>(s.size()); ++i) {
    if (s[i] == s[i - 1]) {
      ++cur;
    } else {
      pre = cur;
      cur = 1;
    }
    if (pre >= cur) {
      ++count;
    }
  }
  return count;
}

int main(int argc, char* argv[]) {
  const std::string s = "10101";
  std::cout << CountBinarySubstrings(s) << std::endl;
  return 0;
}
