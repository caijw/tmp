#include <iostream>

class A {
public:
    A () {}
    A(A &a) {}
    // A(const A &a) {}

};


int main() {
    A a;
    A b = std::move(a); // 如果定义了拷贝构造函数，就没有自动生成的移动构造函数
}
