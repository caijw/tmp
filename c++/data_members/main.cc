#include <iostream>
#include <stdio.h>

class Point3d {
public:
    virtual ~Point3d(){};
    static Point3d origin;
    float x, y, z;
};

struct Base1 { int val1; };
struct Base2 { int val2; };
struct Drived : Base1, Base2 {};

void func1 (int Drived::*dmp, Drived *pd) {
    pd->*dmp;
}

void func2 (Drived *pd) {
    int Base2::* bmp = &Base2::val2;

    func1(bmp, pd);
    // func1(bmp ? bmp + sizeof(Base1) : 0, pd);

}

class Point {
public:
    virtual ~Point(){};
    float x() {return 0;}
    float y() {return 0;}
    virtual float z() {return 0;}
};

int main() {
    printf("&Point3d::x = %p\n", &Point3d::x);
    printf("&Point3d::y = %p\n", &Point3d::y);
    printf("&Point3d::z = %p\n", &Point3d::z);
    float Point3d::* p1 = 0;
    float Point3d::* p2 = &Point3d::x;
    Point3d p3d;
    p3d.x = 1;
    p3d.y = 2;
    p3d.z = 3;
    std::cout << (&p3d)->*p2 << std::endl;
    // std::cout << &Point::~Point << std::endl;
    std::cout << &Point::x << std::endl;
    std::cout << &Point::y << std::endl;
    std::cout << &Point::z << std::endl;
}