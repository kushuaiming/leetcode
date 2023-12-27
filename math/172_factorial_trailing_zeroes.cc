int TrailingZeroes(int n) {
  int ans = 0;
  for (int i = 5; i <= n; i += 5) {
    for (int x = i; x % 5 == 0; x /= 5) {
      ++ans;
    }
  }
  return ans;
}

int TrailingZeroes2(int n) {
  return n == 0 ? 0 : n / 5 + TrailingZeroes2(n / 5);
}
