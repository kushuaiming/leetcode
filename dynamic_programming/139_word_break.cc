#include <string>
#include <unordered_set>
#include <vector>

// 2024/01/12: 直接看答案.
bool WordBreak(std::string s, std::vector<std::string>& word_dict) {
  // 用哈希表加快查找的速度.
  std::unordered_set<std::string> word_dict_set;
  for (const std::string& word : word_dict) {
    word_dict_set.insert(word);
  }

  // dp[i] 表示字符串 s 前 i 个字符组成的字符串 s[0..i−1]
  // 是否能被空格拆分成若干个字典中出现的单词.
  std::vector<int> dp(s.size() + 1);
  dp[0] = 1;
  for (int i = 1; i <= s.size(); ++i) {
    for (int j = 0; j < i; ++j) {
      if (dp[j] &&
          word_dict_set.find(s.substr(j, i - j)) != word_dict_set.end()) {
        dp[i] = true;
        break;
      }
    }
  }
  return dp[s.size()];
}
