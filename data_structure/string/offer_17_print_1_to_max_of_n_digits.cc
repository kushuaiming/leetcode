#include <iostream>
#include <string>

// 2024/01/17: 直接抄答案.
bool Increment(std::string& number) {
  bool is_overflow = false;
  int carry = 0;
  int length = number.size();
  for (int i = length - 1; i >= 0; --i) {
    int sum = (number[i] - '0') + carry;
    if (i == length - 1) {
      ++sum;
    }
    if (sum >= 10) {
      if (i == 0) {
        is_overflow = true;
      } else {
        sum -= 10;
        carry = 1;
        number[i] = '0' + sum;
      }
    } else {
      number[i] = '0' + sum;
      break;
    }
  }
  return is_overflow;
}

void PrintNumber(std::string& number) {
  bool is_beginning = true;
  int length = number.size();
  for (int i = 0; i < length; ++i) {
    if (is_beginning && number[i] != '0') {
      is_beginning = false;
    }
    if (!is_beginning) {
      std::cout << number[i];
    }
  }
  std::cout << std::endl;
}

void Print1ToMaxOfNDigits(int n) {
  if (n <= 0) {
    return;
  }
  std::string number;
  number.resize(n, '0');

  while (!Increment(number)) {
    PrintNumber(number);
  }
}

// 使用回溯实现全排列.
void BackTrack(std::string& str, int k, int n) {
  if (k == n) {
    PrintNumber(str);
    return;
  }

  for (int i = 0; i < 10; ++i) {
    str.push_back('0' + i);
    BackTrack(str, k + 1, n);
    str.pop_back();
  }
}

void Print1ToMaxOfNDigits2(int n) {
  if (n <= 0) {
    return;
  }
  std::string str = "";
  BackTrack(str, 0, n);
}

int main (int argc, char* argv[]) {
  Print1ToMaxOfNDigits2(3);
  return 0;
}
