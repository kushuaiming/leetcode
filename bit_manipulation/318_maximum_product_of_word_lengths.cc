#include <string>
#include <vector>

// 利用位运算可以在O(1)的时间复杂度下判断两个单词是否含有公共字母
int MaxProduct(const std::vector<std::string>& words) {
  std::vector<int> masks(words.size(), 0);
  for (int i = 0; i < words.size(); ++i) {
    const std::string& word = words[i];
    for (char c : word) {
      masks[i] |= (1 << (c - 'a'));
    }
  }
  int result;
  for (int i = 0; i < words.size(); ++i) {
    for (int j = i + 1; j < words.size(); ++j) {
      if ((masks[i] & masks[j]) == 0) {
        result = std::max(result,
                          static_cast<int>(words[i].size() * words[j].size()));
      }
    }
  }
  return result;
}
