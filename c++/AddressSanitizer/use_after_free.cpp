#include <iostream>
#include <unistd.h>

int main(int argc, char **argv) {
  int *array = new int[100];
  delete [] array;
  std::cout << array[0] << std::endl;
  while(1) {
    sleep(2);
    std::cout << 1 << std::endl;
  }
  return 1;
}
