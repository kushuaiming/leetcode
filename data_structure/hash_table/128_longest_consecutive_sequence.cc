#include <iostream>
#include <unordered_set>
#include <vector>

// 熟悉unordered_set的count和insert的调用.
int LongestConsecutiveSequence(std::vector<int>& nums) {
  std::unordered_set<int> hash_table;
  for (int num : nums) {
    hash_table.insert(num);
  }
  int result = 0;
  for (int num : hash_table) {
    if (hash_table.count(num - 1)) {
      continue;
    }
    int index = 0;
    while (hash_table.count(num + index)) {
      ++index;
    }
    result = std::max(result, index);
  }
  return result;
}

int main(int argc, char* argv[]) {
  std::vector<int> nums = {100, 4, 200, 1, 3, 2};
  std::cout << LongestConsecutiveSequence(nums) << std::endl;
}
