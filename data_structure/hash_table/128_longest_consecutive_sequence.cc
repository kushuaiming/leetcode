#include <iostream>
#include <unordered_set>
#include <vector>

// 2023/12/31: 自己完全没有思路

// 熟悉 unordered_set 的 count 和 insert 的调用.
// 关键是想到用一个哈希表去先把所有的数存储起来.

// 考虑数组中的数 x, 以其为起点, 不断匹配 x + 1, x + 2,...
// 如果 x - 1 在哈希表中, 那么 x 不会是起点, 无需匹配.
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

// 把所有数字放到一个哈希表, 然后不断地从哈系表中任意取一个值,
// 并删除掉其之前之后的所有连续数字, 然后更新目前的最长连续序列长度.
int LongestConsecutiveSequence2(std::vector<int>& nums) {
  std::unordered_set<int> hash_table;
  for (int num : nums) {
    hash_table.insert(num);
  }
  int result = 0;
  while (!hash_table.empty()) {
    int cur = *(hash_table.begin());
    hash_table.erase(cur);
    int next = cur + 1;
    int prev = cur - 1;
    while (hash_table.count(next)) {
      hash_table.erase(next++);
    }
    while (hash_table.count(prev)) {
      hash_table.erase(prev--);
    }
    result = std::max(result, next - prev - 1);
  }
  return result;
}

int main(int argc, char* argv[]) {
  std::vector<int> nums = {100, 4, 200, 1, 3, 2};
  std::cout << LongestConsecutiveSequence(nums) << std::endl;
}
