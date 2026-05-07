#include <deque>
#include <vector>

// 2024/01/04: 直接抄答案

// 利用双端队列(单调递减队列, Monotonic Deque)进行操作, 双端队列里存放的是 Index.
// 始终维护队列中索引对应的元素值(即当前窗口内的值)从左到右单调递减, 这样队列的最左端永远是当前窗口内的最大值.
// 具体操作: 移除窗口外的过期元素 -> 维护窗口内的单调性 -> 当前元素入队 -> 记录结果.
std::vector<int> MaxSlidingWindow(std::vector<int>& nums, int k) {
  std::deque<int> dq;
  std::vector<int> res;
  for (int i = 0; i < static_cast<int>(nums.size()); ++i) {
    if (!dq.empty() && dq.front() == i - k) {
      dq.pop_front();
    }
    while (!dq.empty() && nums[dq.back()] < nums[i]) {
      dq.pop_back();
    }
    dq.push_back(i);
    if (i >= k - 1) {
      res.push_back(nums[dq.front()]);
    }
  }
  return res;
}

int main(int argc, char* argv[]) {
  std::vector<int> nums = {1, 3, -1, -3, 5, 3, 6, 7};
  const int k = 3;
  std::vector<int> res = MaxSlidingWindow(nums, k);
  return 0;
}
