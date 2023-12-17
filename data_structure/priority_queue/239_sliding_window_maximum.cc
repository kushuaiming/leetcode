#include <iostream>
#include <queue>
#include <vector>

// 注释: 会超时, 但是个人感觉没有问题.
std::vector<int> MaxSlidingWindow(std::vector<int>& nums, int k) {
  auto cmp = [=](int left, int right) { return nums[left] < nums[right]; };
  std::priority_queue<int, std::vector<int>, decltype(cmp)> pq(cmp);
  std::vector<int> ans;
  for (int i = 0; i < static_cast<int>(nums.size()); ++i) {
    pq.push(i);
    while (!pq.empty() && pq.top() < i - k + 1) {
      pq.pop();
    }
    if (i >= k - 1) {
      ans.push_back(nums[pq.top()]);
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
