#include <deque>
#include <iostream>
#include <queue>
#include <utility>
#include <vector>

// 对于两个相邻(只差了一个位置)的滑动窗口, 它们共用着k-1个元素,
// 而只有一个元素是变化的, 我们可以根据这个特点进行优化.

// 优先队列: 如果priority_queue中直接使用index会产生超时不让通过, 但是原理上没有问题.
// 时间复杂度为O(nlogn)
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
