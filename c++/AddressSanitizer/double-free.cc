#include <stdlib.h>
#include <unistd.h>
#include <stdio.h>

int main() {
  int i = 0;
  void *p = malloc(10);
  free(p);
  free(p);

  int time = 5;
  time = 5;
  while(time--) {
    printf("1\n");
    sleep(1);
  }

  int *a = new int;
  a[0] = 100;
  // delete a;
  printf("a: %d\n", *a);
  time = 5;
  while(time--) {
    printf("1\n");
    sleep(1);
  }
  return 0;
}