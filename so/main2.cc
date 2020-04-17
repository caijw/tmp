#include <dlfcn.h>
#include <unistd.h>
#include <iostream>
#include <thread>


typedef int (*GetNum)();
typedef void (*SetNum)(int);


void t1() {
    void *dlHandle;
    GetNum getNum;
    SetNum setNum;
    dlHandle = dlopen("./libhelper.so", RTLD_LAZY);
    getNum =  (GetNum)dlsym(dlHandle, "getNum");
    setNum =  (SetNum)dlsym(dlHandle, "setNum");
    int num = 1;
    setNum(num);
    while(true) {
        std::cout << "t1: " << getNum() << std::endl;
        sleep(3);
    }
}

void t2() {
    void *dlHandle;
    GetNum getNum;
    SetNum setNum;
    dlHandle = dlopen("./libhelper.so", RTLD_LAZY);
    getNum =  (GetNum)dlsym(dlHandle, "getNum");
    setNum =  (SetNum)dlsym(dlHandle, "setNum");
    int num = 2;
    setNum(num);
    while(true) {
        std::cout << "t2: " << getNum() << std::endl;
        sleep(3);
    }
}


int main() {


    std::thread thread1(t1);
    std::thread thread2(t2);

    thread1.join();
    thread2.join();

    std::cout << "end" << std::endl;

    return 0;
}