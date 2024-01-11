#include <iostream>
#include <limits>
#include <stack>

// 2024/01/11: 不看答案自己做出来了.
class MinStack {
 public:
  MinStack() { min_stack_.push(std::numeric_limits<int>::max()); }

  void push(int val) {
    x_stack_.push(val);
    min_stack_.push(std::min(val, min_stack_.top()));
  }

  void pop() {
    x_stack_.pop();
    min_stack_.pop();
  }

  int top() { return x_stack_.top(); }

  int getMin() { return min_stack_.top(); }

 private:
  std::stack<int> x_stack_;
  std::stack<int> min_stack_;
};

/**
 * Your MinStack object will be instantiated and called as such:
 * MinStack* obj = new MinStack();
 * obj->push(val);
 * obj->pop();
 * int param_3 = obj->top();
 * int param_4 = obj->getMin();
 */

int main(int argc, char* argv[]) {
  MinStack* obj = new MinStack();
  obj->push(-2);
  obj->push(-1);
  obj->push(-1);
  obj->pop();
  int param_3 = obj->top();
  int param_4 = obj->getMin();
  std::cout << "param_3: " << param_3 << ", param_4: " << param_4 << std::endl;
  return 0;
}
