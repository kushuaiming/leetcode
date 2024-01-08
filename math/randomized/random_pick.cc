#include <ctime>
#include <iostream>
#include <random>
#include <vector>

// 随机生成 1 - N 的数
int PickIndex(int n) {
  std::srand(std::time(nullptr));
  return std::rand() % n + 1;
}

int PickIndex2(int n) {
  std::mt19937 gen{std::random_device{}()};
  std::uniform_int_distribution<int> dis(1, n);
  return dis(gen);
}

// 随机生成半径为r的球上的一个点.
std::vector<double> GetPointFromSphere(double r) {
  std::mt19937 gen{std::random_device{}()};
  std::uniform_real_distribution<double> dis(0, 2 * M_PI);
  double theta = dis(gen);
  double gamma = dis(gen);
  double z = r * std::sin(gamma);
  double x = r * std::cos(gamma) * sin(theta);
  double y = r * std::cos(gamma) * cos(theta);
  return {x, y, z};
}

int main(int argc, char* argv[]) {
  std::cout << PickIndex2(10) << std::endl;
  return 0;
}
