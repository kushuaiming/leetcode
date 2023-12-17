#include <deque>
#include <vector>

std::vector<int> MaxSlidingWindow(std::vector<int>& nums, int k) {
  std::deque<int> dq;
  std::vector<int> ans;
  for (int i = 0; i < static_cast<int>(nums.size()); ++i) {
    if (!dq.empty() && dq.front() == i - k) {
      dq.pop_front();
    }
    while (!dq.empty() && nums[dq.back()] < nums[i]) {
      dq.pop_back();
    }
    dq.push_back(i);
    if (i >= k - 1) {
      ans.push_back(nums[dq.front()]);
    }
  }
  return ans;
}

int main(int argc, char* argv[]) {
  std::vector<int> nums = {1, 3, -1, -3, 5, 3, 6, 7};
  const int k = 3;
  std::vector<int> ans = MaxSlidingWindow(nums, k);
  return 0;
}
