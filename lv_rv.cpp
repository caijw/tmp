#include <iostream>

class A {
public:
    A() = default;
    A &setA(int _a) {
        a = _a;
        return *this;
    }
    A setA1(int _a) {
        a = _a;
        return *this;
    }
    A(int _a): a(_a) {
    }
private:
    int a = 10;
};

int main() {
    A a;
    A a1;
    a.setA(11) = A(12);
    a1.setA1(11) = A(12);
    return 0;
}
