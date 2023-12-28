#include <queue>

// 实现简单, 主要是思路
// 第一个队列存储栈内元素, 第二个队列作为入栈操作的辅助队列
class MyStack {
 public:
  MyStack() {}

  void push(int x) {
    queue2_.push(x);
    while (!queue1_.empty()) {
      int front = queue1_.front();
      queue1_.pop();
      queue2_.push(front);
    }
    std::swap(queue1_, queue2_);
  }

  int pop() {
    int front = queue1_.front();
    queue1_.pop();
    return front;
  }

  int top() { return queue1_.front(); }

  bool empty() { return queue1_.empty(); }

 private:
  std::queue<int> queue1_;
  std::queue<int> queue2_;
};

/**
 * Your MyStack object will be instantiated and called as such:
 * MyStack* obj = new MyStack();
 * obj->push(x);
 * int param_2 = obj->pop();
 * int param_3 = obj->top();
 * bool param_4 = obj->empty();
 */

int main(int argc, char* argv[]) { return 0; }