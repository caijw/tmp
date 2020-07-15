#include <thread>
#include <unordered_map>
#include <iostream>
#include <string>
std::unordered_map<std::string, std::string> *api_map_1;
void run() {
    std::cout << api_map_1->size() << std::endl;
}

int main() {
    api_map_1 = new std::unordered_map<std::string, std::string>;
    std::thread t1(run);
    t1.join();
    return 0;
}