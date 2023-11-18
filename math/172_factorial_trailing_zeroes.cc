int TrailingZeroes(int n) {
  int ans = 0;
  for (int i = 5; i <= n; i += 5) {
    for (int x = i; x % 5 == 0; x /= 5) {
      ++ans;
    }
  }
  return ans;
}
