#include <iostream>
#include <typeinfo>
struct Base1 {
    // 多态类型：声明了虚成员
    virtual ~Base1() {}
};
struct Derived1 : Base1 {
     // 多态类型：继承了虚成员
};
 
struct Base2 {
     // 非多态类型
};
struct Derived2 : Base2 {
     // 非多态类型
};
 
int main()
{
    Derived1 obj1; // object1 创建为类型 Derived1
    Derived2 obj2; // object2 创建为类型 Derived2
 
    Base1& b1 = obj1; // b1 指代对象 obj1
    Base2& b2 = obj2; // b2 指代对象 obj2
 
    std::cout << "b1的表达式类型: " << typeid(decltype(b1)).name() << '\n'
              << "b2的表达式类型: " << typeid(decltype(b2)).name() << '\n'
              << "b1 的对象类型: " << typeid(b1).name() << '\n'
              << "b2 的对象类型: " << typeid(b2).name() << '\n'
              << "b1 的大小: " << sizeof b1 << '\n'
              << "b2 的大小: " << sizeof b2 << '\n';
/*
    decltype(i) a; //a推导为int
    decltype((i))b=i;//b推导为int&，必须为其初始化，否则编译错误
 */
    int i=10;
    std::cout << "decltype(i): " << typeid(decltype(i)).name() << '\n'
              << "decltype((i)): " << typeid(decltype((i))).name() << '\n';
    std::cout << "!" "2" "\n";

}