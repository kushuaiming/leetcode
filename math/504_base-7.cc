#include <string>

std::string ConvertToBase7(int num) {
  if (num == 0) {
    return "0";
  }
  const bool is_negative = num < 0;
  if (is_negative) {
    num = -num;
  }
  std::string ans;
  while (num > 0) {
    const int a = num / 7;
    const int b = num % 7;
    ans = std::to_string(b) + ans;
    num = a;
  }
  return is_negative ? "-" + ans : ans;
}
