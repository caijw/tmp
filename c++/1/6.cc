#include <iostream>

class A
{
public:
    A() : m_ptr(new int(0))
    {
        std::cout << "construct" << std::endl;
    }
    A(const A& rhs) : m_ptr(new int(*rhs.m_ptr)) // 拷贝构造函数
    {
        std::cout << "copy construct" << std::endl;
    }
    A(A&& rhs) : m_ptr(rhs.m_ptr) //移动构造函数
    {
    rhs.m_ptr = nullptr;
    std::cout << "move construct" << std::endl;
    }
    ~A()
    {
        std::cout << "destruct" << std::endl;
        delete m_ptr;
    }
private:
    int* m_ptr;
};

A Get(bool flag)
{
    A a, b;
    if (flag)
    {
        return a;
    }
    return b;
}

int main()
{
    A a = Get(false);//调用拷贝构造函数
    return 0;
}