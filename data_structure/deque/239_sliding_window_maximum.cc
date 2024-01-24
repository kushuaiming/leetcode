#include <deque>
#include <vector>

// 2024/01/04: 直接抄答案

// 利用双端队列(单调递减队列)进行操作, 双端队列里存放的是index.
// 每当向右移动时, 把窗口左端的值从队列左端剔除,把队列右边小于窗口右端的值全部剔除. 
// 双端队列的最左端永远是当前窗口内的最大值.
// 可以参考官方题解, 解释了为什么这样做是对的.
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
