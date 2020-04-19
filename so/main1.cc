#include <dlfcn.h>
#include <iostream>
#include <unistd.h>

typedef int (*GetNum)();
typedef void (*SetNum)(int);


int main() {

    void *dlHandle;
    GetNum getNum;
    SetNum setNum;
    dlHandle = dlopen("./libhelper.so", RTLD_LAZY);
    getNum =  (GetNum)dlsym(dlHandle, "getNum");
    setNum =  (SetNum)dlsym(dlHandle, "setNum");
    int num = 2;
    setNum(num);
    while(true) {
        std::cout << getNum() << std::endl;
        sleep(3);
    }


    return 0;
}