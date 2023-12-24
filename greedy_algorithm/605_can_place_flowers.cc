/*
- 贪心算法: 尽可能的在两朵花之间种更多的花
- 假设有m个位置, 所有位置都为空位, 可以种(m + 1) / 2朵花
- 假设i和j上有花, i和j之间没有花. 那么可以种的区间为[i + 2, j - 2],
可种植的空位有(j-2) - (i + 2) + 1个, 可以种(j - i - 2) / 2朵花
- 假设l上有花, l左边没有花, 可种植区间为[0, l - 2], 可种l / 2朵花
- 假设r上有花, r右边没有花, 可种植区间为[r + 2, m - 1], 可种(m -r - 1) / 2
*/

#include <iostream>
#include <vector>

// 维护prev表示上一朵已经种植花的位置, 初始时prev = -1, 表示尚未遇到已经种植的花
// 难点在于公式的推导.
bool CanPlaceFlowers(const std::vector<int>& flowerbed, int n) {
  int prev = -1;
  int num_place_flowers = 0;
  for (int i = 0; i < flowerbed.size(); ++i) {
    if (flowerbed[i] == 1) {
      if (prev == -1) {
        num_place_flowers += i / 2;
      } else {
        num_place_flowers += (i - prev - 2) / 2;
      }
      prev = i;
    }
  }
  num_place_flowers += (flowerbed.size() - prev - 1) / 2;
  if (prev == -1) {
    num_place_flowers = (flowerbed.size() + 1) / 2;
  }
  std::cout << num_place_flowers << std::endl;
  return n <= num_place_flowers;
}

int main(int argc, char* argv[]) {
  std::vector<int> flowerbed = {1, 0, 0, 0, 1};
  std::cout << CanPlaceFlowers(flowerbed, 1) << std::endl;
  return 0;
}
