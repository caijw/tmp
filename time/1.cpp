#include <iostream>
#include <chrono>


int main() {
    // 这个timestamp可能是从1970开始，也可能是从系统开机时间开始
    unsigned long long timestamp =
      std::chrono::duration_cast<std::chrono::microseconds>(
          std::chrono::high_resolution_clock::now().time_since_epoch())
          .count();
    std::cout << "timestamp: " << timestamp << std::endl;

    return 0;
}