#include <iostream>

class C {
public:
    C() {
        std::cout << "C" << std::endl;
    }
    ~C() {
        std::cout << "~C" << std::endl;
    }
};

class D {
public:
    D() {
        std::cout << "D" << std::endl;
    }
    ~D() {
        std::cout << "~D" << std::endl;
    }
};

class A {
public:
    C c;
    A() {
        std::cout << "A" << std::endl;
    }
    ~A() {
        std::cout << "~A" << std::endl;
    }
};


class B : public A {
public:
    D d;
    B() {
        std::cout << "B" << std::endl;
    }
    ~B() {
        std::cout << "~B" << std::endl;
    }
};



int main() {
    std::cout << "hello" << std::endl;
    {
        B b;
    }
    std::cout << "bye" << std::endl;
}