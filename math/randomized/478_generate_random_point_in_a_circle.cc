#include <random>
#include <vector>

// 拒绝采样
class Solution {
 public:
  Solution(double radius, double x_center, double y_center)
      : distribution_(-radius, radius),
        x_center_(x_center),
        y_center_(y_center),
        radius_(radius) {}

  std::vector<double> randPoint() {
    while (true) {
      double x = distribution_(gen), y = distribution_(gen);
      if (x * x + y * y <= radius_ * radius_) {
        return {x_center_ + x, y_center_ + y};
      }
    }
  }

 private:
  std::mt19937 gen{std::random_device{}()};
  std::uniform_real_distribution<double> distribution_;
  double x_center_, y_center_, radius_;
};

// 计算分布函数.
class Solution {
 public:
  Solution(double radius, double x_center, double y_center)
      : dis(0, 1), x_center_(x_center), y_center_(y_center), radius(radius) {}

  std::vector<double> randPoint() {
    double u = dis(gen), theta = dis(gen) * 2 * acos(-1.0);
    double r = sqrt(u);
    return {x_center_ + r * cos(theta) * this->radius,
            y_center_ + r * sin(theta) * this->radius};
  }

 private:
  std::mt19937 gen{std::random_device{}()};
  std::uniform_real_distribution<double> dis;
  double x_center_, y_center_, radius;
};
