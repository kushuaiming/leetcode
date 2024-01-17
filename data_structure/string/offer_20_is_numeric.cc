#include <iostream>
#include <string>

// 2024/01/17: 直接看答案.
// 用来扫描字符串中0~9的数位(类似于一个无符号整数),
// 可以用来匹配前面数值模式中的B部分.
bool ScanUnsignedInteger(const std::string& s, int& p) {
  int before = p;
  while (p != s.size() && s[p] >= '0' && s[p] <= '9') {
    ++p;
  }
  return p > before;
}

// 扫描可能以表示正负的'+'或者'-'为起始的0~9的数位(类似于一个可能带正负号的整数),
// 用来匹配前面数值模式中的A和C部分.
bool ScanInteger(const std::string& s, int& p) {
  if (s[p] == '+' || s[p] == '-') {
    ++p;
  }
  return ScanUnsignedInteger(s, p);
}

// 整数的格式可以用 A[.[B]][e|EC] 或者 .B[e|EC] 表示
// 其中 A 和 C 都是整数(可以有正负号, 也可以没有), 而 B 是一个无符号整数
bool IsNumeric(const std::string& s) {
  if (s.empty()) {
    return false;
  }

  int p = 0;
  bool numeric = ScanInteger(s, p);

  if (s[p] == '.') {
    // 接下来是数字的小数部分.
    ++p;
    // 下面一行使用||的原因.
    // 1. 小数可以没有整数部分, 如.123等于0.123;
    // 2. 小数点后面可以没有数字, 如233.等于233.0;
    // 3. 小数点前面和后面可以都有数字, 如233.666
    numeric = ScanUnsignedInteger(s, p) || numeric;
  }

  if (s[p] == 'e' || s[p] == 'E') {
    // 接下来是数字的指数部分
    ++p;
    // 下面一行使用&&的原因:
    // 1. 当e或者E前面没有数字时, 整个字符串不能表示数字, 如.e1 e1;
    // 2. 当e或者E后面没有整数时, 整个字符串不能表示数字, 如 12e 12e+5.4;
    numeric = numeric && ScanInteger(s, p);
  }

  return numeric && p == s.size();
}

int main(int argc, char* argv[]) {
  std::string s1 = "+100";
  std::string s2 = "5e2";
  std::string s3 = "-123";
  std::string s4 = "3.1416";
  std::string s5 = "-1E-16";

  std::string s6 = "12e";
  std::string s7 = "1a3.14";
  std::string s8 = "1.2.3";
  std::string s9 = "+-5";
  std::string s10 = "12e+5.4";

  std::cout << IsNumeric(s8) << std::endl;
  return 0;
}
