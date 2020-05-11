#include <iostream>
#include <functional>
#include <memory>


typedef std::function<void()> JsApiHandler;

JsApiHandler jsApiHandler;
class A {
public:
    A() {
        jsApiHandler = [this]() {
            std::cout << data << std::endl;
        };
    }
    int data = 10;
};

int main() {
    // 出现悬挂引用， a已经销毁了
    {
        A a;
    }
    
    jsApiHandler();

    return 0;
}
