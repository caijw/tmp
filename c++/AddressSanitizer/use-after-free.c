#include <stdlib.h>
#include <unistd.h>
#include <stdio.h>

int main() {
  char *x = (char*)malloc(10 * sizeof(char*));
  free(x);
  int a = x[5];
  int time = 5;
  while(time--) {
    printf("1\n");
    sleep(1);
  }
  return a;
}