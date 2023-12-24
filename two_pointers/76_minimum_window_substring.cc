// 滑动窗口
// 两个指针, 一个用于延伸窗口的r指针, 一个用于收缩窗口的l指针
// 在任意时刻, 只有一个指针运动, 而另一个保持静止

#include <iostream>
#include <limits>
#include <string>
#include <unordered_map>

bool Check(const std::unordered_map<char, int>& window_counts,
           const std::unordered_map<char, int>& t_counts) {
  for (const auto& t_count : t_counts) {
    // 注意unordered_map中的count / at / []的使用的区别
    if (window_counts.find(t_count.first) == window_counts.end()) {
      return false;
    }
    if (window_counts.at(t_count.first) < t_count.second) {
      return false;
    }
  }
  return true;
}

std::string MinWindow(const std::string& s, const std::string& t) {
  std::unordered_map<char, int> t_counts;
  for (const char& c : t) {
    ++t_counts[c];
  }
  std::unordered_map<char, int> window_counts;
  int left = 0;
  int right = 0;
  // !!! infinity只适用于浮点类型
  // int min_substr_length = std::numeric_limits<int>::infinity();
  int min_substr_length = std::numeric_limits<int>::max();
  int result_left = -1;
  while (right < s.size()) {
    if (t_counts.find(s[right]) != t_counts.end()) {
      ++window_counts[s[right]];
    }
    while (Check(window_counts, t_counts) && left <= right) {
      if (right - left + 1 < min_substr_length) {
        result_left = left;
        min_substr_length = right - left + 1;
      }
      if (t_counts.find(s[left]) != t_counts.end()) {
        --window_counts[s[left]];
      }
      ++left;
    }
    ++right;
  }
  return result_left == -1 ? "" : s.substr(result_left, min_substr_length);
}

int main(int argc, char* argv[]) {
  std::string s = "ADOBECODEBANC";
  std::string t = "ABC";
  std::cout << MinWindow(s, t) << std::endl;
  return 0;
}
