#include <iostream>

class Base {

public:
    void print() {
        std::cout << "base print" << std::endl;
    }
};


class Inherite: public Base {

public:
    void print() {
        std::cout << "inherite print" << std::endl;
    }
};

int main() {
    Inherite inherite;
    Base &base = inherite;
    base.print();
    return 0;
}



