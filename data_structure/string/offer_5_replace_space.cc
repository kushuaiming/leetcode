#include <iostream>
#include <string>

// 2024/01/16: 自己实现用一个新的字符串存储替换后的值.
std::string ReplaceSpace1(const std::string& s) {
  std::string res = "";
  for (int i = 0; i < s.size(); ++i) {
    if (s[i] == ' ') {
      res += "%20";
    } else {
      res += s[i];
    }
  }
  return res;
}

// 2024/01/16: 看答案思路自己实现.
// 假设面试官要求在原来的字符串上进行替换,
// 并且保证输入的字符串后面有足够多的空余内存.
void ReplaceSpace2(std::string& s) {
  // 计算空格数量.
  int count_space = 0;
  for (char c : s) {
    if (c == ' ') {
      ++count_space;
    }
  }
  // 从后往前替换. 时间复杂度为O(n).
  int old_size = s.size();
  int new_size = s.size() + 2 * count_space;
  s.resize(new_size);
  int point = new_size;
  for (int i = old_size - 1; i >= 0; --i) {
    if (s[i] == ' ') {
      s[--point] = '0';
      s[--point] = '2';
      s[--point] = '%';
    } else {
      s[--point] = s[i];
    }
  }
}

int main(int argc, char* argv[]) {
  std::string s = "We are happy.     ";
  ReplaceSpace2(s);
  std::cout << s << std::endl;
  return 0;
}
