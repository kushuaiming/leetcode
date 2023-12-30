#include <iostream>
#include <queue>
#include <utility>
#include <vector>

// 注释: 如果priority_queue中直接使用index会产生超时不让通过, 但是原理上没有问题.
std::vector<int> MaxSlidingWindow(std::vector<int>& nums, int k) {
  std::priority_queue<std::pair<int, int>, std::vector<std::pair<int, int>>> pq;
  std::vector<int> ans;
  for (int i = 0; i < static_cast<int>(nums.size()); ++i) {
    pq.push({nums[i], i});
    while (!pq.empty() && pq.top().second < i - k + 1) {
      pq.pop();
    }
    if (i >= k - 1) {
      ans.push_back(pq.top().first);
    }
  }
  return ans;
}

int main(int argc, char* argv[]) {
  std::vector<int> nums = {1, 3, -1, -3, 5, 3, 6, 7};
  const int k = 3;
  std::vector<int> results = MaxSlidingWindow(nums, k);
  for (int result : results) {
    std::cout << result << std::endl;
  }
  return 0;
}
