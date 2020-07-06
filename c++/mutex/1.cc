#include <mutex>
#include <thread>
std::mutex m;

void f1() {
    m.lock();
}

void f2() {
    // m.unlock();
    m.lock();
    // m.unlock();
}

int main() {

    std::thread t1(f1);

    std::thread t2(f2);
    t1.join();
    t2.join();
    return 0;
}