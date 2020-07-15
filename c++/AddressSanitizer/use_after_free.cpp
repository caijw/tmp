#include <iostream>
int main(int argc, char **argv) {
  int *array = new int[100];
  delete [] array;
  std::cout << array[0] << std::endl;
  return 1;
}
