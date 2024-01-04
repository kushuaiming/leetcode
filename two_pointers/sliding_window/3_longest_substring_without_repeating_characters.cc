#include <algorithm>
#include <string>
#include <unordered_map>

// 2024/01/04: 可以不看答案自己写出来

int LengthOfLongestSubstring(std::string s) {
  int n = s.size();
  std::unordered_map<char, int> hash_table;
  int left = 0, right = 0;
  int res = 0;
  while (right < n) {
    ++hash_table[s[right]];
    while (hash_table[s[right]] > 1 && left <= right) {
      --hash_table[s[left]];
      ++left;
    }
    res = std::max(res, right - left + 1);
    ++right;
  }
  return res;
}
