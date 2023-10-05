#include <iostream>
#include <string>

// 关键是对'0'的处理
int NumDecodings(std::string s) {
  if (s[0] == '0') {
    return 0;
  }

  if (s.size() == 1) {
    return 1;
  }

  if (s.size() == 2) {
    if (s[1] == '0') {
      return (s[0] == '1' || s[0] == '2') ? 1 : 0;
    }
    return (std::stoi(s) <= 26 && s[0] != '0') ? 2 : 1;
  }

  int pre_num_decoding = 1;
  int num_decoding = 0;
  if (s[1] == '0') {
    if (s[0] == '1' || s[0] == '2') {
      num_decoding = 1;
    } else {
      return 0;
    }
  } else {
    num_decoding = std::stoi(s.substr(0, 2)) <= 26 && s[0] != '0' ? 2 : 1;
  }
  for (int i = 2; i < s.size(); ++i) {
    if (s[i] == '0') {
      if (s[i - 1] == '1' || s[i - 1] == '2') {
        num_decoding = pre_num_decoding;
      } else {
        return 0;
      }
    } else {
      int num = std::stoi(s.substr(i - 1, 2));
      if (num <= 26 && s[i - 1] != '0') {
        const int cur_num_decoding = num_decoding + pre_num_decoding;
        pre_num_decoding = num_decoding;
        num_decoding = cur_num_decoding;
      } else {
        pre_num_decoding = num_decoding;
      }
    }
  }
  return num_decoding;
}

int main(int argc, char* argv[]) {
  // "12" "226" "06" "2101"
  std::string s = "207";
  std::cout << NumDecodings(s) << std::endl;
  return 0;
}
