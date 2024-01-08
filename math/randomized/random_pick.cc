#include <ctime>
#include <iostream>
#include <vector>

int PickIndex(int n) {
  std::srand(std::time(nullptr));
  return std::rand() % n + 1;
}

int main(int argc, char* argv[]) {
  std::cout << PickIndex(10) << std::endl;
  return 0;
}
