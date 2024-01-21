#include <algorithm>
#include <string>
#include <vector>

// 2024/01/21: 思路不难, 但是实现细节较多, 看了答案.
// 2024/01/12: 直接看答案.
// 2024/01/11: 直接看答案.

// 把字母、数字和括号看成是独立的 Token, 并用栈来维护这些 Token.
// 注意: 这里的ptr一定要用引用
std::string GetDigits(const std::string &s, size_t &ptr) {
  std::string ret;
  while (isdigit(s[ptr])) {
    ret += s[ptr++];
  }
  return ret;
}

std::string GetString(const std::vector<std::string> &v) {
  std::string ret;
  for (const auto &s : v) {
    ret += s;
  }
  return ret;
}

std::string DecodeString(const std::string &s) {
  // 注意: 用不定长数组来模拟栈操作, 方便从栈底向栈顶遍历
  std::vector<std::string> stk;
  size_t ptr = 0;

  while (ptr < s.size()) {
    char cur = s[ptr];
    if (isdigit(cur)) {
      // 获取一个数字并进栈
      std::string digits = GetDigits(s, ptr);
      stk.push_back(digits);
    } else if (isalpha(cur) || cur == '[') {
      // 获取一个字母并进栈
      stk.push_back(std::string(1, s[ptr++]));
    } else {
      std::vector<std::string> sub;
      while (stk.back() != "[") {
        sub.push_back(stk.back());
        stk.pop_back();
      }
      std::reverse(sub.begin(), sub.end());
      // 左括号出栈
      stk.pop_back();
      // 此时栈顶为当前 sub 对应的字符串应该出现的次数, 注意 stoi 的使用.
      int rep_time = stoi(stk.back());
      stk.pop_back();
      std::string t, o = GetString(sub);
      // 构造字符串
      while (rep_time--) t += o;
      // 将构造好的字符串入栈
      stk.push_back(t);
      ++ptr;
    }
  }

  return GetString(stk);
}
