#include <algorithm>
#include <vector>

// 2024/01/04: 分治方法直接抄答案, 自己实现了DP的方法.
int MaxSubArray(std::vector<int>& nums) {
  int n = nums.size();
  // dp[i]: 以i结尾的连续数组的最大值.
  std::vector<int> dp(n, 0);
  dp[0] = nums[0];
  int res = nums[0];
  for (int i = 1; i < n; ++i) {
    dp[i] = nums[i] + std::max(dp[i - 1], 0);
    res = std::max(res, dp[i]);
  }
  return res;
}

// 分治方法类似于"线段树求解最长公共上升子序列问题"的pushUp操作.
struct Status {
  Status(int l_sum, int r_sum, int m_sum, int i_sum)
      : l_sum(l_sum), r_sum(r_sum), m_sum(m_sum), i_sum(i_sum) {}
  int l_sum;  // 表示 [l,r] 内以 l 为左端点的最大子段和
  int r_sum;  // 表示 [l,r] 内以 r 为右端点的最大子段和
  int m_sum;  // 表示 [l,r] 内的最大子段和
  int i_sum;  // 表示 [l,r] 的区间和
};

Status PushUp(Status l, Status r) {
  int i_sum = l.i_sum + r.i_sum;
  int l_sum = std::max(l.l_sum, l.i_sum + r.l_sum);
  int r_sum = std::max(r.r_sum, l.r_sum + r.i_sum);
  int m_sum = std::max({l.m_sum, r.m_sum, l.r_sum + r.l_sum});
  return (Status){l_sum, r_sum, m_sum, i_sum};
};

Status Get(const std::vector<int>& a, int l, int r) {
  if (l == r) {
    return (Status){a[l], a[l], a[l], a[l]};
  }
  int m = (l + r) >> 1;
  Status l_sub = Get(a, l, m);
  Status r_sub = Get(a, m + 1, r);
  return PushUp(l_sub, r_sub);
}

int MaxSubArray(std::vector<int>& nums) {
  return Get(nums, 0, nums.size() - 1).m_sum;
}
