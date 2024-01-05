#include <algorithm>
#include <string>
#include <vector>

// 2024/01/05: 对着答案自己实现了一遍.

std::vector<int> PartitionLabels(const std::string& s) {
  std::vector<int> end_position(26, -1);
  for (int i = 0; i < s.size(); ++i) {
    end_position[s[i] - 'a'] = std::max(end_position[s[i] - 'a'], i);
  }

  int start = 0, end = 0;
  std::vector<int> res;
  for (int i = 0; i < s.size(); ++i) {
    end = std::max(end, end_position[s[i] - 'a']);
    if (i == end) {
      res.push_back(end - start + 1);
      start = end + 1;
    }
  }
  return res;
}
