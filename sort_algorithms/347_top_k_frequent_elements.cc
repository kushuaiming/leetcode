#include <iostream>
#include <unordered_map>
#include <vector>

std::vector<int> TopKFrequent(std::vector<int>& nums, int k) {
  std::unordered_map<int, int> counts;
  int max_count = 0;
  for (int num : nums) {
    max_count = std::max(max_count, ++counts[num]);
  }

  // 桶排序
  std::vector<std::vector<int>> buckets(max_count + 1);
  for (const auto& p : counts) {
    buckets[p.second].push_back(p.first);
  }

  std::vector<int> ans;
  for (int i = max_count; i >= 0 && ans.size() < k; --i) {
    for (int num : buckets[i]) {
      ans.push_back(num);
      if (ans.size() == k) {
        break;
      }
    }
  }
  return ans;
}

int main(int argc, char* argv[]) {
  std::vector<int> nums = {1, 1, 1, 2, 2, 3};
  std::cout << "Begin bubble sort: " << std::endl;
  std::vector<int> results = TopKFrequent(nums, 2);
  for (int result : results) {
    std::cout << result << std::endl;
  }
  return 0;
}
