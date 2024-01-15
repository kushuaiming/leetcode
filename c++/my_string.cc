// 本题目来自《剑指 Offer》面试题 1

// 为MyString添加复制运算符函数.
/* class MyString {
 public:
  MyString(char* data = nullptr);
  MyString(const MyString& str);
  ~MyString(void);

 private:
  char* data_;
}; */

#include <cstring>

class MyString {
 public:
  MyString(char* data = nullptr);
  MyString(const MyString& str);
  MyString& operator=(const MyString& str);
  ~MyString(void);

 private:
  char* data_;
};

// 1. 是否把返回值的类型申明为该类型的引用, 并在函数结束前返回实例自身的引用.
// 2. 是否把传入的参数的类型声明为常量引用.
// 3. 是否释放实例自身已有的内存.
// 4. 判断传入的参数和当前的实例(*this)是不是同一个实例, 如果是同一个,
// 则不进行赋值操作, 直接返回.
MyString& MyString::operator=(const MyString& str) {
  if (this == &str) {
    return *this;
  }

  delete[] data_;
  data_ = nullptr;

  data_ = new char[strlen(str.data_) + 1];
  strcpy(data_, str.data_);

  return *this;
}

// 考虑异常安全.
// 先创建一个临时实例, 再交换临时实例和原来的实例.
MyString& MyString::operator=(const MyString& str) {
  if (this != &str) {
    MyString str_temp(str); // 在构造函数里调用new分配内存.
    char* temp = str_temp.data_;
    str_temp.data_ = data_;
    data_ = temp;
  }

  return *this;
}
