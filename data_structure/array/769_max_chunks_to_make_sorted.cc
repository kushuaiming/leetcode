#include <vector>

// 从左往右遍历, 同时记录当前的最大值, 每当当前最大值等于数组位置时,
// 我们可以多一次分割
int MaxChunksToSorted(const std::vector<int>& arr) {
  int max_num = -1;
  int res = 0;
  for (int i = 0; i < arr.size(); ++i) {
    max_num = std::max(max_num, arr[i]);
    if (max_num == i) {
      ++res;
    }
  }
  return res;
}
