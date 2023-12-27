bool IsPowerOfThree(int n) {
  if (n == 1) {
    return true;
  }
  if (n % 3 != 0 || n == 0) {
    return false;
  }
  return IsPowerOfThree(n / 3);
}

bool IsPowerOfThree2(int n) {
  while (n && n % 3 == 0) {
    n /= 3;
  }
  return n == 1;
}

int main(int argc, char* argv[]) {
  IsPowerOfThree(27);
  IsPowerOfThree(0);
  IsPowerOfThree(-1);
}
