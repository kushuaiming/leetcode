#include <iostream>
#include <stack>

// 关键: 输入栈 & 输出栈
// 要通过一个额外栈翻转一次数组
class MyQueue {
 public:
  MyQueue() {}

  void push(int x) { in_stack_.push(x); }

  int pop() {
    if (out_stack_.empty()) {
      while (!in_stack_.empty()) {
        out_stack_.push(in_stack_.top());
        in_stack_.pop();
      }
    }
    int x = out_stack_.top();
    out_stack_.pop();
    return x;
  }

  int peek() {
    if (out_stack_.empty()) {
      while (!in_stack_.empty()) {
        out_stack_.push(in_stack_.top());
        in_stack_.pop();
      }
    }
    return out_stack_.top();
  }

  bool empty() { return in_stack_.empty() && out_stack_.empty(); }

 private:
  std::stack<int> in_stack_;
  std::stack<int> out_stack_;
};

int main(int argc, char* argv[]) {
  int x = 10;
  MyQueue* obj = new MyQueue();
  obj->push(x);
  int param_3 = obj->peek();
  int param_2 = obj->pop();
  bool param_4 = obj->empty();
  std::cout << "param_2: " << param_2 << ", param_3: " << param_3
            << ", param_4: " << param_4 << std::endl;
  return 0;
}
