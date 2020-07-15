/*
ASAN_OPTIONS=detect_leaks=1 

ASAN_OPTIONS=suppressions=MyASan.supp

LSAN_OPTIONS=suppressions=MyLSan.supp

clang-9 -g -fsanitize=address -fno-omit-frame-pointer -fsanitize-blacklist=blacklist.txt foo.c 

*/

#include <stdlib.h>
void bad_foo() {
  int *a = (int*)malloc(40);
  a[10] = 1;
}
int main() { bad_foo(); }