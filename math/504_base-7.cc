#include <string>

// 将10进制转化成7进制, 以字符串类型返回
// 利用除法与取模来进行计算
// 需要注意一些细节, 比如负数和零
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
    ans = std::to_string(num % 7) + ans;
    num = num / 7;
  }
  return is_negative ? "-" + ans : ans;
}
