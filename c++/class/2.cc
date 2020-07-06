#include <iostream>
#include <vector>
#include <memory>
#include <unistd.h>
#include <stdio.h>

class A{
public:
    A(int data_) {
        data = std::make_unique<int>(data_);
        i = data_;
    }
    ~A() {
        std::cout << "~A " << i << std::endl;
    }
    int i;
    std::unique_ptr<int> data;
};

int main() {
    std::vector<A *> v;
    v.push_back(new A(1));
    v.push_back(new A(2));
    v.push_back(new A(3));
    for (auto &comp : v) {
        delete comp;
    }
    v.clear();

    A *a1 = new A(1);
    A *a2 = new A(2);

    printf("a1[%p], a2[%p]", a1, a2);

    while(true) {
        sleep(1);
        std::cout << "main loop" << std::endl;
    }

    return 0;
}