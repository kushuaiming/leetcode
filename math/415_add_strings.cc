#include <algorithm>
#include <string>

// 2023/12/27 自己做出来
std::string AddStrings(const std::string& num1, const std::string& num2) {
  int p1 = num1.size() - 1;
  int p2 = num2.size() - 1;
  int carry = 0;
  std::string result;
  while (p1 >= 0 || p2 >= 0) {
    int sum = (p1 < 0 ? 0 : (num1[p1] - '0')) +
              (p2 < 0 ? 0 : (num2[p2] - '0')) + carry;
    result += '0' + sum % 10;
    carry = sum / 10;
    --p1;
    --p2;
  }
  if (carry) {
    result.push_back('1');
  }
  std::reverse(result.begin(), result.end());
  return result;
}

int main(int argc, char* argv[]) {
  std::string num1 = "11";
  std::string num2 = "123";
  AddStrings(num1, num2);
}
