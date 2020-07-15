#include <iostream> // std::cout, std::endl
#include <thread>   // std::thread
#include <string>   // std::string
#include <future>   // std::promise, std::future
#include <chrono>   // seconds
using namespace std::chrono;

void read(std::future<std::string> *future) {
    // future会一直阻塞，直到有值到来
    std::cout << future->get() << std::endl;
}

int main() {
    // promise 相当于生产者
    std::promise<std::string> promise;
    promise.set_value("hello future");
    std::future<std::string> future = promise.get_future();
    std::cout << future.get() << std::endl;
    // future 相当于消费者, 右值构造
    // std::future<std::string> future = promise.get_future();
    // 另一线程中通过future来读取promise的值
    // std::thread thread(read, &future);
    // 让read等一会儿:)
    // std::this_thread::sleep_for(seconds(1));
    // 

    // 等待线程执行完成
    // thread.join();

    return 0;
}