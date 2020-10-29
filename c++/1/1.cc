#include <cassert>
#include <iostream>
struct S {
    char c;  // 1 字节值
             // 3 字节填充（假设 alignof(float) == 4 ）
    float f; // 4 字节值（假设 sizeof(float) == 4 ）
    bool operator==(const S& arg) const { // 基于值的相等
        return c == arg.c && f == arg.f;
    }
};

class A {
    int a;
    void test() {

    }
};
 
void f() {
    static_assert(sizeof(S) == 8);
    static_assert(sizeof(char) == 1);
    static_assert(sizeof(float) == 4);
    std::cout << "sizeof(A): " << sizeof(A) << std::endl;
    std::cout << "sizeof(int): " << sizeof(int) << std::endl;
    S s1 = {'a', 3.14};
    S s2 = s1;
    reinterpret_cast<unsigned char*>(&s1)[2] = 'b'; // 更改填充的第 2 字节
    assert(s1 == s2); // 值并未更改
}

int main() {
    f();
    return 0;
}
